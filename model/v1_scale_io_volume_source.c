#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_scale_io_volume_source.h"



v1_scale_io_volume_source_t *v1_scale_io_volume_source_create(
    char *fsType,
    char *gateway,
    char *protectionDomain,
    int readOnly,
    v1_local_object_reference_t *secretRef,
    int sslEnabled,
    char *storageMode,
    char *storagePool,
    char *system,
    char *volumeName
    ) {
	v1_scale_io_volume_source_t *v1_scale_io_volume_source_local_var = malloc(sizeof(v1_scale_io_volume_source_t));
    if (!v1_scale_io_volume_source_local_var) {
        return NULL;
    }
	v1_scale_io_volume_source_local_var->fsType = fsType;
	v1_scale_io_volume_source_local_var->gateway = gateway;
	v1_scale_io_volume_source_local_var->protectionDomain = protectionDomain;
	v1_scale_io_volume_source_local_var->readOnly = readOnly;
	v1_scale_io_volume_source_local_var->secretRef = secretRef;
	v1_scale_io_volume_source_local_var->sslEnabled = sslEnabled;
	v1_scale_io_volume_source_local_var->storageMode = storageMode;
	v1_scale_io_volume_source_local_var->storagePool = storagePool;
	v1_scale_io_volume_source_local_var->system = system;
	v1_scale_io_volume_source_local_var->volumeName = volumeName;

	return v1_scale_io_volume_source_local_var;
}


void v1_scale_io_volume_source_free(v1_scale_io_volume_source_t *v1_scale_io_volume_source) {
    listEntry_t *listEntry;
    free(v1_scale_io_volume_source->fsType);
    free(v1_scale_io_volume_source->gateway);
    free(v1_scale_io_volume_source->protectionDomain);
    v1_local_object_reference_free(v1_scale_io_volume_source->secretRef);
    free(v1_scale_io_volume_source->storageMode);
    free(v1_scale_io_volume_source->storagePool);
    free(v1_scale_io_volume_source->system);
    free(v1_scale_io_volume_source->volumeName);
	free(v1_scale_io_volume_source);
}

cJSON *v1_scale_io_volume_source_convertToJSON(v1_scale_io_volume_source_t *v1_scale_io_volume_source) {
	cJSON *item = cJSON_CreateObject();

	// v1_scale_io_volume_source->fsType
    if(v1_scale_io_volume_source->fsType) { 
    if(cJSON_AddStringToObject(item, "fsType", v1_scale_io_volume_source->fsType) == NULL) {
    goto fail; //String
    }
     } 


	// v1_scale_io_volume_source->gateway
    if (!v1_scale_io_volume_source->gateway) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "gateway", v1_scale_io_volume_source->gateway) == NULL) {
    goto fail; //String
    }


	// v1_scale_io_volume_source->protectionDomain
    if(v1_scale_io_volume_source->protectionDomain) { 
    if(cJSON_AddStringToObject(item, "protectionDomain", v1_scale_io_volume_source->protectionDomain) == NULL) {
    goto fail; //String
    }
     } 


	// v1_scale_io_volume_source->readOnly
    if(v1_scale_io_volume_source->readOnly) { 
    if(cJSON_AddBoolToObject(item, "readOnly", v1_scale_io_volume_source->readOnly) == NULL) {
    goto fail; //Bool
    }
     } 


	// v1_scale_io_volume_source->secretRef
    if (!v1_scale_io_volume_source->secretRef) {
        goto fail;
    }
    
    cJSON *secretRef_local_JSON = v1_local_object_reference_convertToJSON(v1_scale_io_volume_source->secretRef);
    if(secretRef_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "secretRef", secretRef_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


	// v1_scale_io_volume_source->sslEnabled
    if(v1_scale_io_volume_source->sslEnabled) { 
    if(cJSON_AddBoolToObject(item, "sslEnabled", v1_scale_io_volume_source->sslEnabled) == NULL) {
    goto fail; //Bool
    }
     } 


	// v1_scale_io_volume_source->storageMode
    if(v1_scale_io_volume_source->storageMode) { 
    if(cJSON_AddStringToObject(item, "storageMode", v1_scale_io_volume_source->storageMode) == NULL) {
    goto fail; //String
    }
     } 


	// v1_scale_io_volume_source->storagePool
    if(v1_scale_io_volume_source->storagePool) { 
    if(cJSON_AddStringToObject(item, "storagePool", v1_scale_io_volume_source->storagePool) == NULL) {
    goto fail; //String
    }
     } 


	// v1_scale_io_volume_source->system
    if (!v1_scale_io_volume_source->system) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "system", v1_scale_io_volume_source->system) == NULL) {
    goto fail; //String
    }


	// v1_scale_io_volume_source->volumeName
    if(v1_scale_io_volume_source->volumeName) { 
    if(cJSON_AddStringToObject(item, "volumeName", v1_scale_io_volume_source->volumeName) == NULL) {
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

v1_scale_io_volume_source_t *v1_scale_io_volume_source_parseFromJSON(cJSON *v1_scale_io_volume_sourceJSON){

    v1_scale_io_volume_source_t *v1_scale_io_volume_source_local_var = NULL;

    // v1_scale_io_volume_source->fsType
    cJSON *fsType = cJSON_GetObjectItemCaseSensitive(v1_scale_io_volume_sourceJSON, "fsType");
    if (fsType) { 
    if(!cJSON_IsString(fsType))
    {
    goto end; //String
    }
    }

    // v1_scale_io_volume_source->gateway
    cJSON *gateway = cJSON_GetObjectItemCaseSensitive(v1_scale_io_volume_sourceJSON, "gateway");
    if (!gateway) {
        goto end;
    }

    
    if(!cJSON_IsString(gateway))
    {
    goto end; //String
    }

    // v1_scale_io_volume_source->protectionDomain
    cJSON *protectionDomain = cJSON_GetObjectItemCaseSensitive(v1_scale_io_volume_sourceJSON, "protectionDomain");
    if (protectionDomain) { 
    if(!cJSON_IsString(protectionDomain))
    {
    goto end; //String
    }
    }

    // v1_scale_io_volume_source->readOnly
    cJSON *readOnly = cJSON_GetObjectItemCaseSensitive(v1_scale_io_volume_sourceJSON, "readOnly");
    if (readOnly) { 
    if(!cJSON_IsBool(readOnly))
    {
    goto end; //Bool
    }
    }

    // v1_scale_io_volume_source->secretRef
    cJSON *secretRef = cJSON_GetObjectItemCaseSensitive(v1_scale_io_volume_sourceJSON, "secretRef");
    if (!secretRef) {
        goto end;
    }

    v1_local_object_reference_t *secretRef_local_nonprim = NULL;
    
    secretRef_local_nonprim = v1_local_object_reference_parseFromJSON(secretRef); //nonprimitive

    // v1_scale_io_volume_source->sslEnabled
    cJSON *sslEnabled = cJSON_GetObjectItemCaseSensitive(v1_scale_io_volume_sourceJSON, "sslEnabled");
    if (sslEnabled) { 
    if(!cJSON_IsBool(sslEnabled))
    {
    goto end; //Bool
    }
    }

    // v1_scale_io_volume_source->storageMode
    cJSON *storageMode = cJSON_GetObjectItemCaseSensitive(v1_scale_io_volume_sourceJSON, "storageMode");
    if (storageMode) { 
    if(!cJSON_IsString(storageMode))
    {
    goto end; //String
    }
    }

    // v1_scale_io_volume_source->storagePool
    cJSON *storagePool = cJSON_GetObjectItemCaseSensitive(v1_scale_io_volume_sourceJSON, "storagePool");
    if (storagePool) { 
    if(!cJSON_IsString(storagePool))
    {
    goto end; //String
    }
    }

    // v1_scale_io_volume_source->system
    cJSON *system = cJSON_GetObjectItemCaseSensitive(v1_scale_io_volume_sourceJSON, "system");
    if (!system) {
        goto end;
    }

    
    if(!cJSON_IsString(system))
    {
    goto end; //String
    }

    // v1_scale_io_volume_source->volumeName
    cJSON *volumeName = cJSON_GetObjectItemCaseSensitive(v1_scale_io_volume_sourceJSON, "volumeName");
    if (volumeName) { 
    if(!cJSON_IsString(volumeName))
    {
    goto end; //String
    }
    }


    v1_scale_io_volume_source_local_var = v1_scale_io_volume_source_create (
        fsType ? strdup(fsType->valuestring) : NULL,
        strdup(gateway->valuestring),
        protectionDomain ? strdup(protectionDomain->valuestring) : NULL,
        readOnly ? readOnly->valueint : 0,
        secretRef_local_nonprim,
        sslEnabled ? sslEnabled->valueint : 0,
        storageMode ? strdup(storageMode->valuestring) : NULL,
        storagePool ? strdup(storagePool->valuestring) : NULL,
        strdup(system->valuestring),
        volumeName ? strdup(volumeName->valuestring) : NULL
        );

    return v1_scale_io_volume_source_local_var;
end:
    return NULL;

}
