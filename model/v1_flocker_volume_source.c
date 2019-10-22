#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_flocker_volume_source.h"



v1_flocker_volume_source_t *v1_flocker_volume_source_create(
    char *datasetName,
    char *datasetUUID
    ) {
	v1_flocker_volume_source_t *v1_flocker_volume_source_local_var = malloc(sizeof(v1_flocker_volume_source_t));
    if (!v1_flocker_volume_source_local_var) {
        return NULL;
    }
	v1_flocker_volume_source_local_var->datasetName = datasetName;
	v1_flocker_volume_source_local_var->datasetUUID = datasetUUID;

	return v1_flocker_volume_source_local_var;
}


void v1_flocker_volume_source_free(v1_flocker_volume_source_t *v1_flocker_volume_source) {
    listEntry_t *listEntry;
    free(v1_flocker_volume_source->datasetName);
    free(v1_flocker_volume_source->datasetUUID);
	free(v1_flocker_volume_source);
}

cJSON *v1_flocker_volume_source_convertToJSON(v1_flocker_volume_source_t *v1_flocker_volume_source) {
	cJSON *item = cJSON_CreateObject();

	// v1_flocker_volume_source->datasetName
    if(v1_flocker_volume_source->datasetName) { 
    if(cJSON_AddStringToObject(item, "datasetName", v1_flocker_volume_source->datasetName) == NULL) {
    goto fail; //String
    }
     } 


	// v1_flocker_volume_source->datasetUUID
    if(v1_flocker_volume_source->datasetUUID) { 
    if(cJSON_AddStringToObject(item, "datasetUUID", v1_flocker_volume_source->datasetUUID) == NULL) {
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

v1_flocker_volume_source_t *v1_flocker_volume_source_parseFromJSON(cJSON *v1_flocker_volume_sourceJSON){

    v1_flocker_volume_source_t *v1_flocker_volume_source_local_var = NULL;

    // v1_flocker_volume_source->datasetName
    cJSON *datasetName = cJSON_GetObjectItemCaseSensitive(v1_flocker_volume_sourceJSON, "datasetName");
    if (datasetName) { 
    if(!cJSON_IsString(datasetName))
    {
    goto end; //String
    }
    }

    // v1_flocker_volume_source->datasetUUID
    cJSON *datasetUUID = cJSON_GetObjectItemCaseSensitive(v1_flocker_volume_sourceJSON, "datasetUUID");
    if (datasetUUID) { 
    if(!cJSON_IsString(datasetUUID))
    {
    goto end; //String
    }
    }


    v1_flocker_volume_source_local_var = v1_flocker_volume_source_create (
        datasetName ? strdup(datasetName->valuestring) : NULL,
        datasetUUID ? strdup(datasetUUID->valuestring) : NULL
        );

    return v1_flocker_volume_source_local_var;
end:
    return NULL;

}
