#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_topology_selector_term.h"



v1_topology_selector_term_t *v1_topology_selector_term_create(
    list_t *matchLabelExpressions
    ) {
	v1_topology_selector_term_t *v1_topology_selector_term_local_var = malloc(sizeof(v1_topology_selector_term_t));
    if (!v1_topology_selector_term_local_var) {
        return NULL;
    }
	v1_topology_selector_term_local_var->matchLabelExpressions = matchLabelExpressions;

	return v1_topology_selector_term_local_var;
}


void v1_topology_selector_term_free(v1_topology_selector_term_t *v1_topology_selector_term) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, v1_topology_selector_term->matchLabelExpressions) {
		v1_topology_selector_label_requirement_free(listEntry->data);
	}
	list_free(v1_topology_selector_term->matchLabelExpressions);
	free(v1_topology_selector_term);
}

cJSON *v1_topology_selector_term_convertToJSON(v1_topology_selector_term_t *v1_topology_selector_term) {
	cJSON *item = cJSON_CreateObject();

	// v1_topology_selector_term->matchLabelExpressions
    if(v1_topology_selector_term->matchLabelExpressions) { 
    cJSON *matchLabelExpressions = cJSON_AddArrayToObject(item, "matchLabelExpressions");
    if(matchLabelExpressions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *matchLabelExpressionsListEntry;
    if (v1_topology_selector_term->matchLabelExpressions) {
    list_ForEach(matchLabelExpressionsListEntry, v1_topology_selector_term->matchLabelExpressions) {
    cJSON *itemLocal = v1_topology_selector_label_requirement_convertToJSON(matchLabelExpressionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(matchLabelExpressions, itemLocal);
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

v1_topology_selector_term_t *v1_topology_selector_term_parseFromJSON(cJSON *v1_topology_selector_termJSON){

    v1_topology_selector_term_t *v1_topology_selector_term_local_var = NULL;

    // v1_topology_selector_term->matchLabelExpressions
    cJSON *matchLabelExpressions = cJSON_GetObjectItemCaseSensitive(v1_topology_selector_termJSON, "matchLabelExpressions");
    list_t *matchLabelExpressionsList;
    if (matchLabelExpressions) { 
    cJSON *matchLabelExpressions_local_nonprimitive;
    if(!cJSON_IsArray(matchLabelExpressions)){
        goto end; //nonprimitive container
    }

    matchLabelExpressionsList = list_create();

    cJSON_ArrayForEach(matchLabelExpressions_local_nonprimitive,matchLabelExpressions )
    {
        if(!cJSON_IsObject(matchLabelExpressions_local_nonprimitive)){
            goto end;
        }
        v1_topology_selector_label_requirement_t *matchLabelExpressionsItem = v1_topology_selector_label_requirement_parseFromJSON(matchLabelExpressions_local_nonprimitive);

        list_addElement(matchLabelExpressionsList, matchLabelExpressionsItem);
    }
    }


    v1_topology_selector_term_local_var = v1_topology_selector_term_create (
        matchLabelExpressions ? matchLabelExpressionsList : NULL
        );

    return v1_topology_selector_term_local_var;
end:
    return NULL;

}
