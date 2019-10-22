#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_object_field_selector.h"



v1_object_field_selector_t *v1_object_field_selector_create(
    char *apiVersion,
    char *fieldPath
    ) {
	v1_object_field_selector_t *v1_object_field_selector_local_var = malloc(sizeof(v1_object_field_selector_t));
    if (!v1_object_field_selector_local_var) {
        return NULL;
    }
	v1_object_field_selector_local_var->apiVersion = apiVersion;
	v1_object_field_selector_local_var->fieldPath = fieldPath;

	return v1_object_field_selector_local_var;
}


void v1_object_field_selector_free(v1_object_field_selector_t *v1_object_field_selector) {
    listEntry_t *listEntry;
    free(v1_object_field_selector->apiVersion);
    free(v1_object_field_selector->fieldPath);
	free(v1_object_field_selector);
}

cJSON *v1_object_field_selector_convertToJSON(v1_object_field_selector_t *v1_object_field_selector) {
	cJSON *item = cJSON_CreateObject();

	// v1_object_field_selector->apiVersion
    if(v1_object_field_selector->apiVersion) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1_object_field_selector->apiVersion) == NULL) {
    goto fail; //String
    }
     } 


	// v1_object_field_selector->fieldPath
    if (!v1_object_field_selector->fieldPath) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "fieldPath", v1_object_field_selector->fieldPath) == NULL) {
    goto fail; //String
    }

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1_object_field_selector_t *v1_object_field_selector_parseFromJSON(cJSON *v1_object_field_selectorJSON){

    v1_object_field_selector_t *v1_object_field_selector_local_var = NULL;

    // v1_object_field_selector->apiVersion
    cJSON *apiVersion = cJSON_GetObjectItemCaseSensitive(v1_object_field_selectorJSON, "apiVersion");
    if (apiVersion) { 
    if(!cJSON_IsString(apiVersion))
    {
    goto end; //String
    }
    }

    // v1_object_field_selector->fieldPath
    cJSON *fieldPath = cJSON_GetObjectItemCaseSensitive(v1_object_field_selectorJSON, "fieldPath");
    if (!fieldPath) {
        goto end;
    }

    
    if(!cJSON_IsString(fieldPath))
    {
    goto end; //String
    }


    v1_object_field_selector_local_var = v1_object_field_selector_create (
        apiVersion ? strdup(apiVersion->valuestring) : NULL,
        strdup(fieldPath->valuestring)
        );

    return v1_object_field_selector_local_var;
end:
    return NULL;

}
