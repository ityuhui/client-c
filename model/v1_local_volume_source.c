#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_local_volume_source.h"



v1_local_volume_source_t *v1_local_volume_source_create(
    char *fsType,
    char *path
    ) {
	v1_local_volume_source_t *v1_local_volume_source_local_var = malloc(sizeof(v1_local_volume_source_t));
    if (!v1_local_volume_source_local_var) {
        return NULL;
    }
	v1_local_volume_source_local_var->fsType = fsType;
	v1_local_volume_source_local_var->path = path;

	return v1_local_volume_source_local_var;
}


void v1_local_volume_source_free(v1_local_volume_source_t *v1_local_volume_source) {
    listEntry_t *listEntry;
    free(v1_local_volume_source->fsType);
    free(v1_local_volume_source->path);
	free(v1_local_volume_source);
}

cJSON *v1_local_volume_source_convertToJSON(v1_local_volume_source_t *v1_local_volume_source) {
	cJSON *item = cJSON_CreateObject();

	// v1_local_volume_source->fsType
    if(v1_local_volume_source->fsType) { 
    if(cJSON_AddStringToObject(item, "fsType", v1_local_volume_source->fsType) == NULL) {
    goto fail; //String
    }
     } 


	// v1_local_volume_source->path
    if (!v1_local_volume_source->path) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "path", v1_local_volume_source->path) == NULL) {
    goto fail; //String
    }

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1_local_volume_source_t *v1_local_volume_source_parseFromJSON(cJSON *v1_local_volume_sourceJSON){

    v1_local_volume_source_t *v1_local_volume_source_local_var = NULL;

    // v1_local_volume_source->fsType
    cJSON *fsType = cJSON_GetObjectItemCaseSensitive(v1_local_volume_sourceJSON, "fsType");
    if (fsType) { 
    if(!cJSON_IsString(fsType))
    {
    goto end; //String
    }
    }

    // v1_local_volume_source->path
    cJSON *path = cJSON_GetObjectItemCaseSensitive(v1_local_volume_sourceJSON, "path");
    if (!path) {
        goto end;
    }

    
    if(!cJSON_IsString(path))
    {
    goto end; //String
    }


    v1_local_volume_source_local_var = v1_local_volume_source_create (
        fsType ? strdup(fsType->valuestring) : NULL,
        strdup(path->valuestring)
        );

    return v1_local_volume_source_local_var;
end:
    return NULL;

}
