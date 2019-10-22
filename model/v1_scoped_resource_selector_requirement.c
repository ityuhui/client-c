#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_scoped_resource_selector_requirement.h"



v1_scoped_resource_selector_requirement_t *v1_scoped_resource_selector_requirement_create(
    char *operator,
    char *scopeName,
    list_t *values
    ) {
	v1_scoped_resource_selector_requirement_t *v1_scoped_resource_selector_requirement_local_var = malloc(sizeof(v1_scoped_resource_selector_requirement_t));
    if (!v1_scoped_resource_selector_requirement_local_var) {
        return NULL;
    }
	v1_scoped_resource_selector_requirement_local_var->operator = operator;
	v1_scoped_resource_selector_requirement_local_var->scopeName = scopeName;
	v1_scoped_resource_selector_requirement_local_var->values = values;

	return v1_scoped_resource_selector_requirement_local_var;
}


void v1_scoped_resource_selector_requirement_free(v1_scoped_resource_selector_requirement_t *v1_scoped_resource_selector_requirement) {
    listEntry_t *listEntry;
    free(v1_scoped_resource_selector_requirement->operator);
    free(v1_scoped_resource_selector_requirement->scopeName);
	list_ForEach(listEntry, v1_scoped_resource_selector_requirement->values) {
		free(listEntry->data);
	}
	list_free(v1_scoped_resource_selector_requirement->values);
	free(v1_scoped_resource_selector_requirement);
}

cJSON *v1_scoped_resource_selector_requirement_convertToJSON(v1_scoped_resource_selector_requirement_t *v1_scoped_resource_selector_requirement) {
	cJSON *item = cJSON_CreateObject();

	// v1_scoped_resource_selector_requirement->operator
    if (!v1_scoped_resource_selector_requirement->operator) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "operator", v1_scoped_resource_selector_requirement->operator) == NULL) {
    goto fail; //String
    }


	// v1_scoped_resource_selector_requirement->scopeName
    if (!v1_scoped_resource_selector_requirement->scopeName) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "scopeName", v1_scoped_resource_selector_requirement->scopeName) == NULL) {
    goto fail; //String
    }


	// v1_scoped_resource_selector_requirement->values
    if(v1_scoped_resource_selector_requirement->values) { 
	cJSON *values = cJSON_AddArrayToObject(item, "values");
	if(values == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *valuesListEntry;
    list_ForEach(valuesListEntry, v1_scoped_resource_selector_requirement->values) {
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

v1_scoped_resource_selector_requirement_t *v1_scoped_resource_selector_requirement_parseFromJSON(cJSON *v1_scoped_resource_selector_requirementJSON){

    v1_scoped_resource_selector_requirement_t *v1_scoped_resource_selector_requirement_local_var = NULL;

    // v1_scoped_resource_selector_requirement->operator
    cJSON *operator = cJSON_GetObjectItemCaseSensitive(v1_scoped_resource_selector_requirementJSON, "operator");
    if (!operator) {
        goto end;
    }

    
    if(!cJSON_IsString(operator))
    {
    goto end; //String
    }

    // v1_scoped_resource_selector_requirement->scopeName
    cJSON *scopeName = cJSON_GetObjectItemCaseSensitive(v1_scoped_resource_selector_requirementJSON, "scopeName");
    if (!scopeName) {
        goto end;
    }

    
    if(!cJSON_IsString(scopeName))
    {
    goto end; //String
    }

    // v1_scoped_resource_selector_requirement->values
    cJSON *values = cJSON_GetObjectItemCaseSensitive(v1_scoped_resource_selector_requirementJSON, "values");
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


    v1_scoped_resource_selector_requirement_local_var = v1_scoped_resource_selector_requirement_create (
        strdup(operator->valuestring),
        strdup(scopeName->valuestring),
        values ? valuesList : NULL
        );

    return v1_scoped_resource_selector_requirement_local_var;
end:
    return NULL;

}
