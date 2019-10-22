#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_downward_api_volume_file.h"



v1_downward_api_volume_file_t *v1_downward_api_volume_file_create(
    v1_object_field_selector_t *fieldRef,
    int mode,
    char *path,
    v1_resource_field_selector_t *resourceFieldRef
    ) {
	v1_downward_api_volume_file_t *v1_downward_api_volume_file_local_var = malloc(sizeof(v1_downward_api_volume_file_t));
    if (!v1_downward_api_volume_file_local_var) {
        return NULL;
    }
	v1_downward_api_volume_file_local_var->fieldRef = fieldRef;
	v1_downward_api_volume_file_local_var->mode = mode;
	v1_downward_api_volume_file_local_var->path = path;
	v1_downward_api_volume_file_local_var->resourceFieldRef = resourceFieldRef;

	return v1_downward_api_volume_file_local_var;
}


void v1_downward_api_volume_file_free(v1_downward_api_volume_file_t *v1_downward_api_volume_file) {
    listEntry_t *listEntry;
    v1_object_field_selector_free(v1_downward_api_volume_file->fieldRef);
    free(v1_downward_api_volume_file->path);
    v1_resource_field_selector_free(v1_downward_api_volume_file->resourceFieldRef);
	free(v1_downward_api_volume_file);
}

cJSON *v1_downward_api_volume_file_convertToJSON(v1_downward_api_volume_file_t *v1_downward_api_volume_file) {
	cJSON *item = cJSON_CreateObject();

	// v1_downward_api_volume_file->fieldRef
    if(v1_downward_api_volume_file->fieldRef) { 
    cJSON *fieldRef_local_JSON = v1_object_field_selector_convertToJSON(v1_downward_api_volume_file->fieldRef);
    if(fieldRef_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "fieldRef", fieldRef_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_downward_api_volume_file->mode
    if(v1_downward_api_volume_file->mode) { 
    if(cJSON_AddNumberToObject(item, "mode", v1_downward_api_volume_file->mode) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1_downward_api_volume_file->path
    if (!v1_downward_api_volume_file->path) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "path", v1_downward_api_volume_file->path) == NULL) {
    goto fail; //String
    }


	// v1_downward_api_volume_file->resourceFieldRef
    if(v1_downward_api_volume_file->resourceFieldRef) { 
    cJSON *resourceFieldRef_local_JSON = v1_resource_field_selector_convertToJSON(v1_downward_api_volume_file->resourceFieldRef);
    if(resourceFieldRef_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "resourceFieldRef", resourceFieldRef_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1_downward_api_volume_file_t *v1_downward_api_volume_file_parseFromJSON(cJSON *v1_downward_api_volume_fileJSON){

    v1_downward_api_volume_file_t *v1_downward_api_volume_file_local_var = NULL;

    // v1_downward_api_volume_file->fieldRef
    cJSON *fieldRef = cJSON_GetObjectItemCaseSensitive(v1_downward_api_volume_fileJSON, "fieldRef");
    v1_object_field_selector_t *fieldRef_local_nonprim = NULL;
    if (fieldRef) { 
    fieldRef_local_nonprim = v1_object_field_selector_parseFromJSON(fieldRef); //nonprimitive
    }

    // v1_downward_api_volume_file->mode
    cJSON *mode = cJSON_GetObjectItemCaseSensitive(v1_downward_api_volume_fileJSON, "mode");
    if (mode) { 
    if(!cJSON_IsNumber(mode))
    {
    goto end; //Numeric
    }
    }

    // v1_downward_api_volume_file->path
    cJSON *path = cJSON_GetObjectItemCaseSensitive(v1_downward_api_volume_fileJSON, "path");
    if (!path) {
        goto end;
    }

    
    if(!cJSON_IsString(path))
    {
    goto end; //String
    }

    // v1_downward_api_volume_file->resourceFieldRef
    cJSON *resourceFieldRef = cJSON_GetObjectItemCaseSensitive(v1_downward_api_volume_fileJSON, "resourceFieldRef");
    v1_resource_field_selector_t *resourceFieldRef_local_nonprim = NULL;
    if (resourceFieldRef) { 
    resourceFieldRef_local_nonprim = v1_resource_field_selector_parseFromJSON(resourceFieldRef); //nonprimitive
    }


    v1_downward_api_volume_file_local_var = v1_downward_api_volume_file_create (
        fieldRef ? fieldRef_local_nonprim : NULL,
        mode ? mode->valuedouble : 0,
        strdup(path->valuestring),
        resourceFieldRef ? resourceFieldRef_local_nonprim : NULL
        );

    return v1_downward_api_volume_file_local_var;
end:
    return NULL;

}
