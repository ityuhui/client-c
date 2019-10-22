#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_empty_dir_volume_source.h"



v1_empty_dir_volume_source_t *v1_empty_dir_volume_source_create(
    char *medium,
    char *sizeLimit
    ) {
	v1_empty_dir_volume_source_t *v1_empty_dir_volume_source_local_var = malloc(sizeof(v1_empty_dir_volume_source_t));
    if (!v1_empty_dir_volume_source_local_var) {
        return NULL;
    }
	v1_empty_dir_volume_source_local_var->medium = medium;
	v1_empty_dir_volume_source_local_var->sizeLimit = sizeLimit;

	return v1_empty_dir_volume_source_local_var;
}


void v1_empty_dir_volume_source_free(v1_empty_dir_volume_source_t *v1_empty_dir_volume_source) {
    listEntry_t *listEntry;
    free(v1_empty_dir_volume_source->medium);
    free(v1_empty_dir_volume_source->sizeLimit);
	free(v1_empty_dir_volume_source);
}

cJSON *v1_empty_dir_volume_source_convertToJSON(v1_empty_dir_volume_source_t *v1_empty_dir_volume_source) {
	cJSON *item = cJSON_CreateObject();

	// v1_empty_dir_volume_source->medium
    if(v1_empty_dir_volume_source->medium) { 
    if(cJSON_AddStringToObject(item, "medium", v1_empty_dir_volume_source->medium) == NULL) {
    goto fail; //String
    }
     } 


	// v1_empty_dir_volume_source->sizeLimit
    if(v1_empty_dir_volume_source->sizeLimit) { 
    if(cJSON_AddStringToObject(item, "sizeLimit", v1_empty_dir_volume_source->sizeLimit) == NULL) {
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

v1_empty_dir_volume_source_t *v1_empty_dir_volume_source_parseFromJSON(cJSON *v1_empty_dir_volume_sourceJSON){

    v1_empty_dir_volume_source_t *v1_empty_dir_volume_source_local_var = NULL;

    // v1_empty_dir_volume_source->medium
    cJSON *medium = cJSON_GetObjectItemCaseSensitive(v1_empty_dir_volume_sourceJSON, "medium");
    if (medium) { 
    if(!cJSON_IsString(medium))
    {
    goto end; //String
    }
    }

    // v1_empty_dir_volume_source->sizeLimit
    cJSON *sizeLimit = cJSON_GetObjectItemCaseSensitive(v1_empty_dir_volume_sourceJSON, "sizeLimit");
    if (sizeLimit) { 
    if(!cJSON_IsString(sizeLimit))
    {
    goto end; //String
    }
    }


    v1_empty_dir_volume_source_local_var = v1_empty_dir_volume_source_create (
        medium ? strdup(medium->valuestring) : NULL,
        sizeLimit ? strdup(sizeLimit->valuestring) : NULL
        );

    return v1_empty_dir_volume_source_local_var;
end:
    return NULL;

}
