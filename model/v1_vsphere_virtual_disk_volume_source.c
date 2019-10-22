#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_vsphere_virtual_disk_volume_source.h"



v1_vsphere_virtual_disk_volume_source_t *v1_vsphere_virtual_disk_volume_source_create(
    char *fsType,
    char *storagePolicyID,
    char *storagePolicyName,
    char *volumePath
    ) {
	v1_vsphere_virtual_disk_volume_source_t *v1_vsphere_virtual_disk_volume_source_local_var = malloc(sizeof(v1_vsphere_virtual_disk_volume_source_t));
    if (!v1_vsphere_virtual_disk_volume_source_local_var) {
        return NULL;
    }
	v1_vsphere_virtual_disk_volume_source_local_var->fsType = fsType;
	v1_vsphere_virtual_disk_volume_source_local_var->storagePolicyID = storagePolicyID;
	v1_vsphere_virtual_disk_volume_source_local_var->storagePolicyName = storagePolicyName;
	v1_vsphere_virtual_disk_volume_source_local_var->volumePath = volumePath;

	return v1_vsphere_virtual_disk_volume_source_local_var;
}


void v1_vsphere_virtual_disk_volume_source_free(v1_vsphere_virtual_disk_volume_source_t *v1_vsphere_virtual_disk_volume_source) {
    listEntry_t *listEntry;
    free(v1_vsphere_virtual_disk_volume_source->fsType);
    free(v1_vsphere_virtual_disk_volume_source->storagePolicyID);
    free(v1_vsphere_virtual_disk_volume_source->storagePolicyName);
    free(v1_vsphere_virtual_disk_volume_source->volumePath);
	free(v1_vsphere_virtual_disk_volume_source);
}

cJSON *v1_vsphere_virtual_disk_volume_source_convertToJSON(v1_vsphere_virtual_disk_volume_source_t *v1_vsphere_virtual_disk_volume_source) {
	cJSON *item = cJSON_CreateObject();

	// v1_vsphere_virtual_disk_volume_source->fsType
    if(v1_vsphere_virtual_disk_volume_source->fsType) { 
    if(cJSON_AddStringToObject(item, "fsType", v1_vsphere_virtual_disk_volume_source->fsType) == NULL) {
    goto fail; //String
    }
     } 


	// v1_vsphere_virtual_disk_volume_source->storagePolicyID
    if(v1_vsphere_virtual_disk_volume_source->storagePolicyID) { 
    if(cJSON_AddStringToObject(item, "storagePolicyID", v1_vsphere_virtual_disk_volume_source->storagePolicyID) == NULL) {
    goto fail; //String
    }
     } 


	// v1_vsphere_virtual_disk_volume_source->storagePolicyName
    if(v1_vsphere_virtual_disk_volume_source->storagePolicyName) { 
    if(cJSON_AddStringToObject(item, "storagePolicyName", v1_vsphere_virtual_disk_volume_source->storagePolicyName) == NULL) {
    goto fail; //String
    }
     } 


	// v1_vsphere_virtual_disk_volume_source->volumePath
    if (!v1_vsphere_virtual_disk_volume_source->volumePath) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "volumePath", v1_vsphere_virtual_disk_volume_source->volumePath) == NULL) {
    goto fail; //String
    }

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1_vsphere_virtual_disk_volume_source_t *v1_vsphere_virtual_disk_volume_source_parseFromJSON(cJSON *v1_vsphere_virtual_disk_volume_sourceJSON){

    v1_vsphere_virtual_disk_volume_source_t *v1_vsphere_virtual_disk_volume_source_local_var = NULL;

    // v1_vsphere_virtual_disk_volume_source->fsType
    cJSON *fsType = cJSON_GetObjectItemCaseSensitive(v1_vsphere_virtual_disk_volume_sourceJSON, "fsType");
    if (fsType) { 
    if(!cJSON_IsString(fsType))
    {
    goto end; //String
    }
    }

    // v1_vsphere_virtual_disk_volume_source->storagePolicyID
    cJSON *storagePolicyID = cJSON_GetObjectItemCaseSensitive(v1_vsphere_virtual_disk_volume_sourceJSON, "storagePolicyID");
    if (storagePolicyID) { 
    if(!cJSON_IsString(storagePolicyID))
    {
    goto end; //String
    }
    }

    // v1_vsphere_virtual_disk_volume_source->storagePolicyName
    cJSON *storagePolicyName = cJSON_GetObjectItemCaseSensitive(v1_vsphere_virtual_disk_volume_sourceJSON, "storagePolicyName");
    if (storagePolicyName) { 
    if(!cJSON_IsString(storagePolicyName))
    {
    goto end; //String
    }
    }

    // v1_vsphere_virtual_disk_volume_source->volumePath
    cJSON *volumePath = cJSON_GetObjectItemCaseSensitive(v1_vsphere_virtual_disk_volume_sourceJSON, "volumePath");
    if (!volumePath) {
        goto end;
    }

    
    if(!cJSON_IsString(volumePath))
    {
    goto end; //String
    }


    v1_vsphere_virtual_disk_volume_source_local_var = v1_vsphere_virtual_disk_volume_source_create (
        fsType ? strdup(fsType->valuestring) : NULL,
        storagePolicyID ? strdup(storagePolicyID->valuestring) : NULL,
        storagePolicyName ? strdup(storagePolicyName->valuestring) : NULL,
        strdup(volumePath->valuestring)
        );

    return v1_vsphere_virtual_disk_volume_source_local_var;
end:
    return NULL;

}
