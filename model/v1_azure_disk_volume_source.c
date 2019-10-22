#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_azure_disk_volume_source.h"



v1_azure_disk_volume_source_t *v1_azure_disk_volume_source_create(
    char *cachingMode,
    char *diskName,
    char *diskURI,
    char *fsType,
    char *kind,
    int readOnly
    ) {
	v1_azure_disk_volume_source_t *v1_azure_disk_volume_source_local_var = malloc(sizeof(v1_azure_disk_volume_source_t));
    if (!v1_azure_disk_volume_source_local_var) {
        return NULL;
    }
	v1_azure_disk_volume_source_local_var->cachingMode = cachingMode;
	v1_azure_disk_volume_source_local_var->diskName = diskName;
	v1_azure_disk_volume_source_local_var->diskURI = diskURI;
	v1_azure_disk_volume_source_local_var->fsType = fsType;
	v1_azure_disk_volume_source_local_var->kind = kind;
	v1_azure_disk_volume_source_local_var->readOnly = readOnly;

	return v1_azure_disk_volume_source_local_var;
}


void v1_azure_disk_volume_source_free(v1_azure_disk_volume_source_t *v1_azure_disk_volume_source) {
    listEntry_t *listEntry;
    free(v1_azure_disk_volume_source->cachingMode);
    free(v1_azure_disk_volume_source->diskName);
    free(v1_azure_disk_volume_source->diskURI);
    free(v1_azure_disk_volume_source->fsType);
    free(v1_azure_disk_volume_source->kind);
	free(v1_azure_disk_volume_source);
}

cJSON *v1_azure_disk_volume_source_convertToJSON(v1_azure_disk_volume_source_t *v1_azure_disk_volume_source) {
	cJSON *item = cJSON_CreateObject();

	// v1_azure_disk_volume_source->cachingMode
    if(v1_azure_disk_volume_source->cachingMode) { 
    if(cJSON_AddStringToObject(item, "cachingMode", v1_azure_disk_volume_source->cachingMode) == NULL) {
    goto fail; //String
    }
     } 


	// v1_azure_disk_volume_source->diskName
    if (!v1_azure_disk_volume_source->diskName) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "diskName", v1_azure_disk_volume_source->diskName) == NULL) {
    goto fail; //String
    }


	// v1_azure_disk_volume_source->diskURI
    if (!v1_azure_disk_volume_source->diskURI) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "diskURI", v1_azure_disk_volume_source->diskURI) == NULL) {
    goto fail; //String
    }


	// v1_azure_disk_volume_source->fsType
    if(v1_azure_disk_volume_source->fsType) { 
    if(cJSON_AddStringToObject(item, "fsType", v1_azure_disk_volume_source->fsType) == NULL) {
    goto fail; //String
    }
     } 


	// v1_azure_disk_volume_source->kind
    if(v1_azure_disk_volume_source->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1_azure_disk_volume_source->kind) == NULL) {
    goto fail; //String
    }
     } 


	// v1_azure_disk_volume_source->readOnly
    if(v1_azure_disk_volume_source->readOnly) { 
    if(cJSON_AddBoolToObject(item, "readOnly", v1_azure_disk_volume_source->readOnly) == NULL) {
    goto fail; //Bool
    }
     } 

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1_azure_disk_volume_source_t *v1_azure_disk_volume_source_parseFromJSON(cJSON *v1_azure_disk_volume_sourceJSON){

    v1_azure_disk_volume_source_t *v1_azure_disk_volume_source_local_var = NULL;

    // v1_azure_disk_volume_source->cachingMode
    cJSON *cachingMode = cJSON_GetObjectItemCaseSensitive(v1_azure_disk_volume_sourceJSON, "cachingMode");
    if (cachingMode) { 
    if(!cJSON_IsString(cachingMode))
    {
    goto end; //String
    }
    }

    // v1_azure_disk_volume_source->diskName
    cJSON *diskName = cJSON_GetObjectItemCaseSensitive(v1_azure_disk_volume_sourceJSON, "diskName");
    if (!diskName) {
        goto end;
    }

    
    if(!cJSON_IsString(diskName))
    {
    goto end; //String
    }

    // v1_azure_disk_volume_source->diskURI
    cJSON *diskURI = cJSON_GetObjectItemCaseSensitive(v1_azure_disk_volume_sourceJSON, "diskURI");
    if (!diskURI) {
        goto end;
    }

    
    if(!cJSON_IsString(diskURI))
    {
    goto end; //String
    }

    // v1_azure_disk_volume_source->fsType
    cJSON *fsType = cJSON_GetObjectItemCaseSensitive(v1_azure_disk_volume_sourceJSON, "fsType");
    if (fsType) { 
    if(!cJSON_IsString(fsType))
    {
    goto end; //String
    }
    }

    // v1_azure_disk_volume_source->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_azure_disk_volume_sourceJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1_azure_disk_volume_source->readOnly
    cJSON *readOnly = cJSON_GetObjectItemCaseSensitive(v1_azure_disk_volume_sourceJSON, "readOnly");
    if (readOnly) { 
    if(!cJSON_IsBool(readOnly))
    {
    goto end; //Bool
    }
    }


    v1_azure_disk_volume_source_local_var = v1_azure_disk_volume_source_create (
        cachingMode ? strdup(cachingMode->valuestring) : NULL,
        strdup(diskName->valuestring),
        strdup(diskURI->valuestring),
        fsType ? strdup(fsType->valuestring) : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        readOnly ? readOnly->valueint : 0
        );

    return v1_azure_disk_volume_source_local_var;
end:
    return NULL;

}
