#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_storage_os_volume_source.h"



v1_storage_os_volume_source_t *v1_storage_os_volume_source_create(
    char *fsType,
    int readOnly,
    v1_local_object_reference_t *secretRef,
    char *volumeName,
    char *volumeNamespace
    ) {
	v1_storage_os_volume_source_t *v1_storage_os_volume_source_local_var = malloc(sizeof(v1_storage_os_volume_source_t));
    if (!v1_storage_os_volume_source_local_var) {
        return NULL;
    }
	v1_storage_os_volume_source_local_var->fsType = fsType;
	v1_storage_os_volume_source_local_var->readOnly = readOnly;
	v1_storage_os_volume_source_local_var->secretRef = secretRef;
	v1_storage_os_volume_source_local_var->volumeName = volumeName;
	v1_storage_os_volume_source_local_var->volumeNamespace = volumeNamespace;

	return v1_storage_os_volume_source_local_var;
}


void v1_storage_os_volume_source_free(v1_storage_os_volume_source_t *v1_storage_os_volume_source) {
    listEntry_t *listEntry;
    free(v1_storage_os_volume_source->fsType);
    v1_local_object_reference_free(v1_storage_os_volume_source->secretRef);
    free(v1_storage_os_volume_source->volumeName);
    free(v1_storage_os_volume_source->volumeNamespace);
	free(v1_storage_os_volume_source);
}

cJSON *v1_storage_os_volume_source_convertToJSON(v1_storage_os_volume_source_t *v1_storage_os_volume_source) {
	cJSON *item = cJSON_CreateObject();

	// v1_storage_os_volume_source->fsType
    if(v1_storage_os_volume_source->fsType) { 
    if(cJSON_AddStringToObject(item, "fsType", v1_storage_os_volume_source->fsType) == NULL) {
    goto fail; //String
    }
     } 


	// v1_storage_os_volume_source->readOnly
    if(v1_storage_os_volume_source->readOnly) { 
    if(cJSON_AddBoolToObject(item, "readOnly", v1_storage_os_volume_source->readOnly) == NULL) {
    goto fail; //Bool
    }
     } 


	// v1_storage_os_volume_source->secretRef
    if(v1_storage_os_volume_source->secretRef) { 
    cJSON *secretRef_local_JSON = v1_local_object_reference_convertToJSON(v1_storage_os_volume_source->secretRef);
    if(secretRef_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "secretRef", secretRef_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_storage_os_volume_source->volumeName
    if(v1_storage_os_volume_source->volumeName) { 
    if(cJSON_AddStringToObject(item, "volumeName", v1_storage_os_volume_source->volumeName) == NULL) {
    goto fail; //String
    }
     } 


	// v1_storage_os_volume_source->volumeNamespace
    if(v1_storage_os_volume_source->volumeNamespace) { 
    if(cJSON_AddStringToObject(item, "volumeNamespace", v1_storage_os_volume_source->volumeNamespace) == NULL) {
    goto fail; //String
    }
     } 

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1_storage_os_volume_source_t *v1_storage_os_volume_source_parseFromJSON(cJSON *v1_storage_os_volume_sourceJSON){

    v1_storage_os_volume_source_t *v1_storage_os_volume_source_local_var = NULL;

    // v1_storage_os_volume_source->fsType
    cJSON *fsType = cJSON_GetObjectItemCaseSensitive(v1_storage_os_volume_sourceJSON, "fsType");
    if (fsType) { 
    if(!cJSON_IsString(fsType))
    {
    goto end; //String
    }
    }

    // v1_storage_os_volume_source->readOnly
    cJSON *readOnly = cJSON_GetObjectItemCaseSensitive(v1_storage_os_volume_sourceJSON, "readOnly");
    if (readOnly) { 
    if(!cJSON_IsBool(readOnly))
    {
    goto end; //Bool
    }
    }

    // v1_storage_os_volume_source->secretRef
    cJSON *secretRef = cJSON_GetObjectItemCaseSensitive(v1_storage_os_volume_sourceJSON, "secretRef");
    v1_local_object_reference_t *secretRef_local_nonprim = NULL;
    if (secretRef) { 
    secretRef_local_nonprim = v1_local_object_reference_parseFromJSON(secretRef); //nonprimitive
    }

    // v1_storage_os_volume_source->volumeName
    cJSON *volumeName = cJSON_GetObjectItemCaseSensitive(v1_storage_os_volume_sourceJSON, "volumeName");
    if (volumeName) { 
    if(!cJSON_IsString(volumeName))
    {
    goto end; //String
    }
    }

    // v1_storage_os_volume_source->volumeNamespace
    cJSON *volumeNamespace = cJSON_GetObjectItemCaseSensitive(v1_storage_os_volume_sourceJSON, "volumeNamespace");
    if (volumeNamespace) { 
    if(!cJSON_IsString(volumeNamespace))
    {
    goto end; //String
    }
    }


    v1_storage_os_volume_source_local_var = v1_storage_os_volume_source_create (
        fsType ? strdup(fsType->valuestring) : NULL,
        readOnly ? readOnly->valueint : 0,
        secretRef ? secretRef_local_nonprim : NULL,
        volumeName ? strdup(volumeName->valuestring) : NULL,
        volumeNamespace ? strdup(volumeNamespace->valuestring) : NULL
        );

    return v1_storage_os_volume_source_local_var;
end:
    return NULL;

}
