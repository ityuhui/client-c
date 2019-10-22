#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_photon_persistent_disk_volume_source.h"



v1_photon_persistent_disk_volume_source_t *v1_photon_persistent_disk_volume_source_create(
    char *fsType,
    char *pdID
    ) {
	v1_photon_persistent_disk_volume_source_t *v1_photon_persistent_disk_volume_source_local_var = malloc(sizeof(v1_photon_persistent_disk_volume_source_t));
    if (!v1_photon_persistent_disk_volume_source_local_var) {
        return NULL;
    }
	v1_photon_persistent_disk_volume_source_local_var->fsType = fsType;
	v1_photon_persistent_disk_volume_source_local_var->pdID = pdID;

	return v1_photon_persistent_disk_volume_source_local_var;
}


void v1_photon_persistent_disk_volume_source_free(v1_photon_persistent_disk_volume_source_t *v1_photon_persistent_disk_volume_source) {
    listEntry_t *listEntry;
    free(v1_photon_persistent_disk_volume_source->fsType);
    free(v1_photon_persistent_disk_volume_source->pdID);
	free(v1_photon_persistent_disk_volume_source);
}

cJSON *v1_photon_persistent_disk_volume_source_convertToJSON(v1_photon_persistent_disk_volume_source_t *v1_photon_persistent_disk_volume_source) {
	cJSON *item = cJSON_CreateObject();

	// v1_photon_persistent_disk_volume_source->fsType
    if(v1_photon_persistent_disk_volume_source->fsType) { 
    if(cJSON_AddStringToObject(item, "fsType", v1_photon_persistent_disk_volume_source->fsType) == NULL) {
    goto fail; //String
    }
     } 


	// v1_photon_persistent_disk_volume_source->pdID
    if (!v1_photon_persistent_disk_volume_source->pdID) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "pdID", v1_photon_persistent_disk_volume_source->pdID) == NULL) {
    goto fail; //String
    }

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1_photon_persistent_disk_volume_source_t *v1_photon_persistent_disk_volume_source_parseFromJSON(cJSON *v1_photon_persistent_disk_volume_sourceJSON){

    v1_photon_persistent_disk_volume_source_t *v1_photon_persistent_disk_volume_source_local_var = NULL;

    // v1_photon_persistent_disk_volume_source->fsType
    cJSON *fsType = cJSON_GetObjectItemCaseSensitive(v1_photon_persistent_disk_volume_sourceJSON, "fsType");
    if (fsType) { 
    if(!cJSON_IsString(fsType))
    {
    goto end; //String
    }
    }

    // v1_photon_persistent_disk_volume_source->pdID
    cJSON *pdID = cJSON_GetObjectItemCaseSensitive(v1_photon_persistent_disk_volume_sourceJSON, "pdID");
    if (!pdID) {
        goto end;
    }

    
    if(!cJSON_IsString(pdID))
    {
    goto end; //String
    }


    v1_photon_persistent_disk_volume_source_local_var = v1_photon_persistent_disk_volume_source_create (
        fsType ? strdup(fsType->valuestring) : NULL,
        strdup(pdID->valuestring)
        );

    return v1_photon_persistent_disk_volume_source_local_var;
end:
    return NULL;

}
