#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_cinder_persistent_volume_source.h"



v1_cinder_persistent_volume_source_t *v1_cinder_persistent_volume_source_create(
    char *fsType,
    int readOnly,
    v1_secret_reference_t *secretRef,
    char *volumeID
    ) {
	v1_cinder_persistent_volume_source_t *v1_cinder_persistent_volume_source_local_var = malloc(sizeof(v1_cinder_persistent_volume_source_t));
    if (!v1_cinder_persistent_volume_source_local_var) {
        return NULL;
    }
	v1_cinder_persistent_volume_source_local_var->fsType = fsType;
	v1_cinder_persistent_volume_source_local_var->readOnly = readOnly;
	v1_cinder_persistent_volume_source_local_var->secretRef = secretRef;
	v1_cinder_persistent_volume_source_local_var->volumeID = volumeID;

	return v1_cinder_persistent_volume_source_local_var;
}


void v1_cinder_persistent_volume_source_free(v1_cinder_persistent_volume_source_t *v1_cinder_persistent_volume_source) {
    listEntry_t *listEntry;
    free(v1_cinder_persistent_volume_source->fsType);
    v1_secret_reference_free(v1_cinder_persistent_volume_source->secretRef);
    free(v1_cinder_persistent_volume_source->volumeID);
	free(v1_cinder_persistent_volume_source);
}

cJSON *v1_cinder_persistent_volume_source_convertToJSON(v1_cinder_persistent_volume_source_t *v1_cinder_persistent_volume_source) {
	cJSON *item = cJSON_CreateObject();

	// v1_cinder_persistent_volume_source->fsType
    if(v1_cinder_persistent_volume_source->fsType) { 
    if(cJSON_AddStringToObject(item, "fsType", v1_cinder_persistent_volume_source->fsType) == NULL) {
    goto fail; //String
    }
     } 


	// v1_cinder_persistent_volume_source->readOnly
    if(v1_cinder_persistent_volume_source->readOnly) { 
    if(cJSON_AddBoolToObject(item, "readOnly", v1_cinder_persistent_volume_source->readOnly) == NULL) {
    goto fail; //Bool
    }
     } 


	// v1_cinder_persistent_volume_source->secretRef
    if(v1_cinder_persistent_volume_source->secretRef) { 
    cJSON *secretRef_local_JSON = v1_secret_reference_convertToJSON(v1_cinder_persistent_volume_source->secretRef);
    if(secretRef_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "secretRef", secretRef_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_cinder_persistent_volume_source->volumeID
    if (!v1_cinder_persistent_volume_source->volumeID) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "volumeID", v1_cinder_persistent_volume_source->volumeID) == NULL) {
    goto fail; //String
    }

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1_cinder_persistent_volume_source_t *v1_cinder_persistent_volume_source_parseFromJSON(cJSON *v1_cinder_persistent_volume_sourceJSON){

    v1_cinder_persistent_volume_source_t *v1_cinder_persistent_volume_source_local_var = NULL;

    // v1_cinder_persistent_volume_source->fsType
    cJSON *fsType = cJSON_GetObjectItemCaseSensitive(v1_cinder_persistent_volume_sourceJSON, "fsType");
    if (fsType) { 
    if(!cJSON_IsString(fsType))
    {
    goto end; //String
    }
    }

    // v1_cinder_persistent_volume_source->readOnly
    cJSON *readOnly = cJSON_GetObjectItemCaseSensitive(v1_cinder_persistent_volume_sourceJSON, "readOnly");
    if (readOnly) { 
    if(!cJSON_IsBool(readOnly))
    {
    goto end; //Bool
    }
    }

    // v1_cinder_persistent_volume_source->secretRef
    cJSON *secretRef = cJSON_GetObjectItemCaseSensitive(v1_cinder_persistent_volume_sourceJSON, "secretRef");
    v1_secret_reference_t *secretRef_local_nonprim = NULL;
    if (secretRef) { 
    secretRef_local_nonprim = v1_secret_reference_parseFromJSON(secretRef); //nonprimitive
    }

    // v1_cinder_persistent_volume_source->volumeID
    cJSON *volumeID = cJSON_GetObjectItemCaseSensitive(v1_cinder_persistent_volume_sourceJSON, "volumeID");
    if (!volumeID) {
        goto end;
    }

    
    if(!cJSON_IsString(volumeID))
    {
    goto end; //String
    }


    v1_cinder_persistent_volume_source_local_var = v1_cinder_persistent_volume_source_create (
        fsType ? strdup(fsType->valuestring) : NULL,
        readOnly ? readOnly->valueint : 0,
        secretRef ? secretRef_local_nonprim : NULL,
        strdup(volumeID->valuestring)
        );

    return v1_cinder_persistent_volume_source_local_var;
end:
    return NULL;

}
