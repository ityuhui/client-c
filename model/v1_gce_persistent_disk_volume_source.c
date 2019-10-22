#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_gce_persistent_disk_volume_source.h"



v1_gce_persistent_disk_volume_source_t *v1_gce_persistent_disk_volume_source_create(
    char *fsType,
    int partition,
    char *pdName,
    int readOnly
    ) {
	v1_gce_persistent_disk_volume_source_t *v1_gce_persistent_disk_volume_source_local_var = malloc(sizeof(v1_gce_persistent_disk_volume_source_t));
    if (!v1_gce_persistent_disk_volume_source_local_var) {
        return NULL;
    }
	v1_gce_persistent_disk_volume_source_local_var->fsType = fsType;
	v1_gce_persistent_disk_volume_source_local_var->partition = partition;
	v1_gce_persistent_disk_volume_source_local_var->pdName = pdName;
	v1_gce_persistent_disk_volume_source_local_var->readOnly = readOnly;

	return v1_gce_persistent_disk_volume_source_local_var;
}


void v1_gce_persistent_disk_volume_source_free(v1_gce_persistent_disk_volume_source_t *v1_gce_persistent_disk_volume_source) {
    listEntry_t *listEntry;
    free(v1_gce_persistent_disk_volume_source->fsType);
    free(v1_gce_persistent_disk_volume_source->pdName);
	free(v1_gce_persistent_disk_volume_source);
}

cJSON *v1_gce_persistent_disk_volume_source_convertToJSON(v1_gce_persistent_disk_volume_source_t *v1_gce_persistent_disk_volume_source) {
	cJSON *item = cJSON_CreateObject();

	// v1_gce_persistent_disk_volume_source->fsType
    if(v1_gce_persistent_disk_volume_source->fsType) { 
    if(cJSON_AddStringToObject(item, "fsType", v1_gce_persistent_disk_volume_source->fsType) == NULL) {
    goto fail; //String
    }
     } 


	// v1_gce_persistent_disk_volume_source->partition
    if(v1_gce_persistent_disk_volume_source->partition) { 
    if(cJSON_AddNumberToObject(item, "partition", v1_gce_persistent_disk_volume_source->partition) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1_gce_persistent_disk_volume_source->pdName
    if (!v1_gce_persistent_disk_volume_source->pdName) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "pdName", v1_gce_persistent_disk_volume_source->pdName) == NULL) {
    goto fail; //String
    }


	// v1_gce_persistent_disk_volume_source->readOnly
    if(v1_gce_persistent_disk_volume_source->readOnly) { 
    if(cJSON_AddBoolToObject(item, "readOnly", v1_gce_persistent_disk_volume_source->readOnly) == NULL) {
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

v1_gce_persistent_disk_volume_source_t *v1_gce_persistent_disk_volume_source_parseFromJSON(cJSON *v1_gce_persistent_disk_volume_sourceJSON){

    v1_gce_persistent_disk_volume_source_t *v1_gce_persistent_disk_volume_source_local_var = NULL;

    // v1_gce_persistent_disk_volume_source->fsType
    cJSON *fsType = cJSON_GetObjectItemCaseSensitive(v1_gce_persistent_disk_volume_sourceJSON, "fsType");
    if (fsType) { 
    if(!cJSON_IsString(fsType))
    {
    goto end; //String
    }
    }

    // v1_gce_persistent_disk_volume_source->partition
    cJSON *partition = cJSON_GetObjectItemCaseSensitive(v1_gce_persistent_disk_volume_sourceJSON, "partition");
    if (partition) { 
    if(!cJSON_IsNumber(partition))
    {
    goto end; //Numeric
    }
    }

    // v1_gce_persistent_disk_volume_source->pdName
    cJSON *pdName = cJSON_GetObjectItemCaseSensitive(v1_gce_persistent_disk_volume_sourceJSON, "pdName");
    if (!pdName) {
        goto end;
    }

    
    if(!cJSON_IsString(pdName))
    {
    goto end; //String
    }

    // v1_gce_persistent_disk_volume_source->readOnly
    cJSON *readOnly = cJSON_GetObjectItemCaseSensitive(v1_gce_persistent_disk_volume_sourceJSON, "readOnly");
    if (readOnly) { 
    if(!cJSON_IsBool(readOnly))
    {
    goto end; //Bool
    }
    }


    v1_gce_persistent_disk_volume_source_local_var = v1_gce_persistent_disk_volume_source_create (
        fsType ? strdup(fsType->valuestring) : NULL,
        partition ? partition->valuedouble : 0,
        strdup(pdName->valuestring),
        readOnly ? readOnly->valueint : 0
        );

    return v1_gce_persistent_disk_volume_source_local_var;
end:
    return NULL;

}
