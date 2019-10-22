#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_node_selector_term.h"



v1_node_selector_term_t *v1_node_selector_term_create(
    list_t *matchExpressions,
    list_t *matchFields
    ) {
	v1_node_selector_term_t *v1_node_selector_term_local_var = malloc(sizeof(v1_node_selector_term_t));
    if (!v1_node_selector_term_local_var) {
        return NULL;
    }
	v1_node_selector_term_local_var->matchExpressions = matchExpressions;
	v1_node_selector_term_local_var->matchFields = matchFields;

	return v1_node_selector_term_local_var;
}


void v1_node_selector_term_free(v1_node_selector_term_t *v1_node_selector_term) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, v1_node_selector_term->matchExpressions) {
		v1_node_selector_requirement_free(listEntry->data);
	}
	list_free(v1_node_selector_term->matchExpressions);
	list_ForEach(listEntry, v1_node_selector_term->matchFields) {
		v1_node_selector_requirement_free(listEntry->data);
	}
	list_free(v1_node_selector_term->matchFields);
	free(v1_node_selector_term);
}

cJSON *v1_node_selector_term_convertToJSON(v1_node_selector_term_t *v1_node_selector_term) {
	cJSON *item = cJSON_CreateObject();

	// v1_node_selector_term->matchExpressions
    if(v1_node_selector_term->matchExpressions) { 
    cJSON *matchExpressions = cJSON_AddArrayToObject(item, "matchExpressions");
    if(matchExpressions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *matchExpressionsListEntry;
    if (v1_node_selector_term->matchExpressions) {
    list_ForEach(matchExpressionsListEntry, v1_node_selector_term->matchExpressions) {
    cJSON *itemLocal = v1_node_selector_requirement_convertToJSON(matchExpressionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(matchExpressions, itemLocal);
    }
    }
     } 


	// v1_node_selector_term->matchFields
    if(v1_node_selector_term->matchFields) { 
    cJSON *matchFields = cJSON_AddArrayToObject(item, "matchFields");
    if(matchFields == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *matchFieldsListEntry;
    if (v1_node_selector_term->matchFields) {
    list_ForEach(matchFieldsListEntry, v1_node_selector_term->matchFields) {
    cJSON *itemLocal = v1_node_selector_requirement_convertToJSON(matchFieldsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(matchFields, itemLocal);
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

v1_node_selector_term_t *v1_node_selector_term_parseFromJSON(cJSON *v1_node_selector_termJSON){

    v1_node_selector_term_t *v1_node_selector_term_local_var = NULL;

    // v1_node_selector_term->matchExpressions
    cJSON *matchExpressions = cJSON_GetObjectItemCaseSensitive(v1_node_selector_termJSON, "matchExpressions");
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
        v1_node_selector_requirement_t *matchExpressionsItem = v1_node_selector_requirement_parseFromJSON(matchExpressions_local_nonprimitive);

        list_addElement(matchExpressionsList, matchExpressionsItem);
    }
    }

    // v1_node_selector_term->matchFields
    cJSON *matchFields = cJSON_GetObjectItemCaseSensitive(v1_node_selector_termJSON, "matchFields");
    list_t *matchFieldsList;
    if (matchFields) { 
    cJSON *matchFields_local_nonprimitive;
    if(!cJSON_IsArray(matchFields)){
        goto end; //nonprimitive container
    }

    matchFieldsList = list_create();

    cJSON_ArrayForEach(matchFields_local_nonprimitive,matchFields )
    {
        if(!cJSON_IsObject(matchFields_local_nonprimitive)){
            goto end;
        }
        v1_node_selector_requirement_t *matchFieldsItem = v1_node_selector_requirement_parseFromJSON(matchFields_local_nonprimitive);

        list_addElement(matchFieldsList, matchFieldsItem);
    }
    }


    v1_node_selector_term_local_var = v1_node_selector_term_create (
        matchExpressions ? matchExpressionsList : NULL,
        matchFields ? matchFieldsList : NULL
        );

    return v1_node_selector_term_local_var;
end:
    return NULL;

}
