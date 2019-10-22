#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_scope_selector.h"



v1_scope_selector_t *v1_scope_selector_create(
    list_t *matchExpressions
    ) {
	v1_scope_selector_t *v1_scope_selector_local_var = malloc(sizeof(v1_scope_selector_t));
    if (!v1_scope_selector_local_var) {
        return NULL;
    }
	v1_scope_selector_local_var->matchExpressions = matchExpressions;

	return v1_scope_selector_local_var;
}


void v1_scope_selector_free(v1_scope_selector_t *v1_scope_selector) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, v1_scope_selector->matchExpressions) {
		v1_scoped_resource_selector_requirement_free(listEntry->data);
	}
	list_free(v1_scope_selector->matchExpressions);
	free(v1_scope_selector);
}

cJSON *v1_scope_selector_convertToJSON(v1_scope_selector_t *v1_scope_selector) {
	cJSON *item = cJSON_CreateObject();

	// v1_scope_selector->matchExpressions
    if(v1_scope_selector->matchExpressions) { 
    cJSON *matchExpressions = cJSON_AddArrayToObject(item, "matchExpressions");
    if(matchExpressions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *matchExpressionsListEntry;
    if (v1_scope_selector->matchExpressions) {
    list_ForEach(matchExpressionsListEntry, v1_scope_selector->matchExpressions) {
    cJSON *itemLocal = v1_scoped_resource_selector_requirement_convertToJSON(matchExpressionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(matchExpressions, itemLocal);
    }
    }
     } 

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1_scope_selector_t *v1_scope_selector_parseFromJSON(cJSON *v1_scope_selectorJSON){

    v1_scope_selector_t *v1_scope_selector_local_var = NULL;

    // v1_scope_selector->matchExpressions
    cJSON *matchExpressions = cJSON_GetObjectItemCaseSensitive(v1_scope_selectorJSON, "matchExpressions");
    list_t *matchExpressionsList;
    if (matchExpressions) { 
    cJSON *matchExpressions_local_nonprimitive;
    if(!cJSON_IsArray(matchExpressions)){
        goto end; //nonprimitive container
    }

    matchExpressionsList = list_create();

    cJSON_ArrayForEach(matchExpressions_local_nonprimitive,matchExpressions )
    {
        if(!cJSON_IsObject(matchExpressions_local_nonprimitive)){
            goto end;
        }
        v1_scoped_resource_selector_requirement_t *matchExpressionsItem = v1_scoped_resource_selector_requirement_parseFromJSON(matchExpressions_local_nonprimitive);

        list_addElement(matchExpressionsList, matchExpressionsItem);
    }
    }


    v1_scope_selector_local_var = v1_scope_selector_create (
        matchExpressions ? matchExpressionsList : NULL
        );

    return v1_scope_selector_local_var;
end:
    return NULL;

}
