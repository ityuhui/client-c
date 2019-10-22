#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_node_selector_requirement.h"



v1_node_selector_requirement_t *v1_node_selector_requirement_create(
    char *key,
    char *operator,
    list_t *values
    ) {
	v1_node_selector_requirement_t *v1_node_selector_requirement_local_var = malloc(sizeof(v1_node_selector_requirement_t));
    if (!v1_node_selector_requirement_local_var) {
        return NULL;
    }
	v1_node_selector_requirement_local_var->key = key;
	v1_node_selector_requirement_local_var->operator = operator;
	v1_node_selector_requirement_local_var->values = values;

	return v1_node_selector_requirement_local_var;
}


void v1_node_selector_requirement_free(v1_node_selector_requirement_t *v1_node_selector_requirement) {
    listEntry_t *listEntry;
    free(v1_node_selector_requirement->key);
    free(v1_node_selector_requirement->operator);
	list_ForEach(listEntry, v1_node_selector_requirement->values) {
		free(listEntry->data);
	}
	list_free(v1_node_selector_requirement->values);
	free(v1_node_selector_requirement);
}

cJSON *v1_node_selector_requirement_convertToJSON(v1_node_selector_requirement_t *v1_node_selector_requirement) {
	cJSON *item = cJSON_CreateObject();

	// v1_node_selector_requirement->key
    if (!v1_node_selector_requirement->key) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "key", v1_node_selector_requirement->key) == NULL) {
    goto fail; //String
    }


	// v1_node_selector_requirement->operator
    if (!v1_node_selector_requirement->operator) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "operator", v1_node_selector_requirement->operator) == NULL) {
    goto fail; //String
    }


	// v1_node_selector_requirement->values
    if(v1_node_selector_requirement->values) { 
	cJSON *values = cJSON_AddArrayToObject(item, "values");
	if(values == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *valuesListEntry;
    list_ForEach(valuesListEntry, v1_node_selector_requirement->values) {
    if(cJSON_AddStringToObject(values, "", (char*)valuesListEntry->data) == NULL)
    {
        goto fail;
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

v1_node_selector_requirement_t *v1_node_selector_requirement_parseFromJSON(cJSON *v1_node_selector_requirementJSON){

    v1_node_selector_requirement_t *v1_node_selector_requirement_local_var = NULL;

    // v1_node_selector_requirement->key
    cJSON *key = cJSON_GetObjectItemCaseSensitive(v1_node_selector_requirementJSON, "key");
    if (!key) {
        goto end;
    }

    
    if(!cJSON_IsString(key))
    {
    goto end; //String
    }

    // v1_node_selector_requirement->operator
    cJSON *operator = cJSON_GetObjectItemCaseSensitive(v1_node_selector_requirementJSON, "operator");
    if (!operator) {
        goto end;
    }

    
    if(!cJSON_IsString(operator))
    {
    goto end; //String
    }

    // v1_node_selector_requirement->values
    cJSON *values = cJSON_GetObjectItemCaseSensitive(v1_node_selector_requirementJSON, "values");
    list_t *valuesList;
    if (values) { 
    cJSON *values_local;
    if(!cJSON_IsArray(values)) {
        goto end;//primitive container
    }
    valuesList = list_create();

    cJSON_ArrayForEach(values_local, values)
    {
        if(!cJSON_IsString(values_local))
        {
            goto end;
        }
        list_addElement(valuesList , strdup(values_local->valuestring));
    }
    }


    v1_node_selector_requirement_local_var = v1_node_selector_requirement_create (
        strdup(key->valuestring),
        strdup(operator->valuestring),
        values ? valuesList : NULL
        );

    return v1_node_selector_requirement_local_var;
end:
    return NULL;

}
