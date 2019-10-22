#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_volume_device.h"



v1_volume_device_t *v1_volume_device_create(
    char *devicePath,
    char *name
    ) {
	v1_volume_device_t *v1_volume_device_local_var = malloc(sizeof(v1_volume_device_t));
    if (!v1_volume_device_local_var) {
        return NULL;
    }
	v1_volume_device_local_var->devicePath = devicePath;
	v1_volume_device_local_var->name = name;

	return v1_volume_device_local_var;
}


void v1_volume_device_free(v1_volume_device_t *v1_volume_device) {
    listEntry_t *listEntry;
    free(v1_volume_device->devicePath);
    free(v1_volume_device->name);
	free(v1_volume_device);
}

cJSON *v1_volume_device_convertToJSON(v1_volume_device_t *v1_volume_device) {
	cJSON *item = cJSON_CreateObject();

	// v1_volume_device->devicePath
    if (!v1_volume_device->devicePath) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "devicePath", v1_volume_device->devicePath) == NULL) {
    goto fail; //String
    }


	// v1_volume_device->name
    if (!v1_volume_device->name) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "name", v1_volume_device->name) == NULL) {
    goto fail; //String
    }

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1_volume_device_t *v1_volume_device_parseFromJSON(cJSON *v1_volume_deviceJSON){

    v1_volume_device_t *v1_volume_device_local_var = NULL;

    // v1_volume_device->devicePath
    cJSON *devicePath = cJSON_GetObjectItemCaseSensitive(v1_volume_deviceJSON, "devicePath");
    if (!devicePath) {
        goto end;
    }

    
    if(!cJSON_IsString(devicePath))
    {
    goto end; //String
    }

    // v1_volume_device->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_volume_deviceJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }


    v1_volume_device_local_var = v1_volume_device_create (
        strdup(devicePath->valuestring),
        strdup(name->valuestring)
        );

    return v1_volume_device_local_var;
end:
    return NULL;

}
