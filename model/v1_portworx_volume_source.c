#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_portworx_volume_source.h"



v1_portworx_volume_source_t *v1_portworx_volume_source_create(
    char *fsType,
    int readOnly,
    char *volumeID
    ) {
	v1_portworx_volume_source_t *v1_portworx_volume_source_local_var = malloc(sizeof(v1_portworx_volume_source_t));
    if (!v1_portworx_volume_source_local_var) {
        return NULL;
    }
	v1_portworx_volume_source_local_var->fsType = fsType;
	v1_portworx_volume_source_local_var->readOnly = readOnly;
	v1_portworx_volume_source_local_var->volumeID = volumeID;

	return v1_portworx_volume_source_local_var;
}


void v1_portworx_volume_source_free(v1_portworx_volume_source_t *v1_portworx_volume_source) {
    listEntry_t *listEntry;
    free(v1_portworx_volume_source->fsType);
    free(v1_portworx_volume_source->volumeID);
	free(v1_portworx_volume_source);
}

cJSON *v1_portworx_volume_source_convertToJSON(v1_portworx_volume_source_t *v1_portworx_volume_source) {
	cJSON *item = cJSON_CreateObject();

	// v1_portworx_volume_source->fsType
    if(v1_portworx_volume_source->fsType) { 
    if(cJSON_AddStringToObject(item, "fsType", v1_portworx_volume_source->fsType) == NULL) {
    goto fail; //String
    }
     } 


	// v1_portworx_volume_source->readOnly
    if(v1_portworx_volume_source->readOnly) { 
    if(cJSON_AddBoolToObject(item, "readOnly", v1_portworx_volume_source->readOnly) == NULL) {
    goto fail; //Bool
    }
     } 


	// v1_portworx_volume_source->volumeID
    if (!v1_portworx_volume_source->volumeID) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "volumeID", v1_portworx_volume_source->volumeID) == NULL) {
    goto fail; //String
    }

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1_portworx_volume_source_t *v1_portworx_volume_source_parseFromJSON(cJSON *v1_portworx_volume_sourceJSON){

    v1_portworx_volume_source_t *v1_portworx_volume_source_local_var = NULL;

    // v1_portworx_volume_source->fsType
    cJSON *fsType = cJSON_GetObjectItemCaseSensitive(v1_portworx_volume_sourceJSON, "fsType");
    if (fsType) { 
    if(!cJSON_IsString(fsType))
    {
    goto end; //String
    }
    }

    // v1_portworx_volume_source->readOnly
    cJSON *readOnly = cJSON_GetObjectItemCaseSensitive(v1_portworx_volume_sourceJSON, "readOnly");
    if (readOnly) { 
    if(!cJSON_IsBool(readOnly))
    {
    goto end; //Bool
    }
    }

    // v1_portworx_volume_source->volumeID
    cJSON *volumeID = cJSON_GetObjectItemCaseSensitive(v1_portworx_volume_sourceJSON, "volumeID");
    if (!volumeID) {
        goto end;
    }

    
    if(!cJSON_IsString(volumeID))
    {
    goto end; //String
    }


    v1_portworx_volume_source_local_var = v1_portworx_volume_source_create (
        fsType ? strdup(fsType->valuestring) : NULL,
        readOnly ? readOnly->valueint : 0,
        strdup(volumeID->valuestring)
        );

    return v1_portworx_volume_source_local_var;
end:
    return NULL;

}
