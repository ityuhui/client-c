#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_attached_volume.h"



v1_attached_volume_t *v1_attached_volume_create(
    char *devicePath,
    char *name
    ) {
	v1_attached_volume_t *v1_attached_volume_local_var = malloc(sizeof(v1_attached_volume_t));
    if (!v1_attached_volume_local_var) {
        return NULL;
    }
	v1_attached_volume_local_var->devicePath = devicePath;
	v1_attached_volume_local_var->name = name;

	return v1_attached_volume_local_var;
}


void v1_attached_volume_free(v1_attached_volume_t *v1_attached_volume) {
    listEntry_t *listEntry;
    free(v1_attached_volume->devicePath);
    free(v1_attached_volume->name);
	free(v1_attached_volume);
}

cJSON *v1_attached_volume_convertToJSON(v1_attached_volume_t *v1_attached_volume) {
	cJSON *item = cJSON_CreateObject();

	// v1_attached_volume->devicePath
    if (!v1_attached_volume->devicePath) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "devicePath", v1_attached_volume->devicePath) == NULL) {
    goto fail; //String
    }


	// v1_attached_volume->name
    if (!v1_attached_volume->name) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "name", v1_attached_volume->name) == NULL) {
    goto fail; //String
    }

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1_attached_volume_t *v1_attached_volume_parseFromJSON(cJSON *v1_attached_volumeJSON){

    v1_attached_volume_t *v1_attached_volume_local_var = NULL;

    // v1_attached_volume->devicePath
    cJSON *devicePath = cJSON_GetObjectItemCaseSensitive(v1_attached_volumeJSON, "devicePath");
    if (!devicePath) {
        goto end;
    }

    
    if(!cJSON_IsString(devicePath))
    {
    goto end; //String
    }

    // v1_attached_volume->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_attached_volumeJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }


    v1_attached_volume_local_var = v1_attached_volume_create (
        strdup(devicePath->valuestring),
        strdup(name->valuestring)
        );

    return v1_attached_volume_local_var;
end:
    return NULL;

}
