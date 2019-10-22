#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_persistent_volume_claim_volume_source.h"



v1_persistent_volume_claim_volume_source_t *v1_persistent_volume_claim_volume_source_create(
    char *claimName,
    int readOnly
    ) {
	v1_persistent_volume_claim_volume_source_t *v1_persistent_volume_claim_volume_source_local_var = malloc(sizeof(v1_persistent_volume_claim_volume_source_t));
    if (!v1_persistent_volume_claim_volume_source_local_var) {
        return NULL;
    }
	v1_persistent_volume_claim_volume_source_local_var->claimName = claimName;
	v1_persistent_volume_claim_volume_source_local_var->readOnly = readOnly;

	return v1_persistent_volume_claim_volume_source_local_var;
}


void v1_persistent_volume_claim_volume_source_free(v1_persistent_volume_claim_volume_source_t *v1_persistent_volume_claim_volume_source) {
    listEntry_t *listEntry;
    free(v1_persistent_volume_claim_volume_source->claimName);
	free(v1_persistent_volume_claim_volume_source);
}

cJSON *v1_persistent_volume_claim_volume_source_convertToJSON(v1_persistent_volume_claim_volume_source_t *v1_persistent_volume_claim_volume_source) {
	cJSON *item = cJSON_CreateObject();

	// v1_persistent_volume_claim_volume_source->claimName
    if (!v1_persistent_volume_claim_volume_source->claimName) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "claimName", v1_persistent_volume_claim_volume_source->claimName) == NULL) {
    goto fail; //String
    }


	// v1_persistent_volume_claim_volume_source->readOnly
    if(v1_persistent_volume_claim_volume_source->readOnly) { 
    if(cJSON_AddBoolToObject(item, "readOnly", v1_persistent_volume_claim_volume_source->readOnly) == NULL) {
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

v1_persistent_volume_claim_volume_source_t *v1_persistent_volume_claim_volume_source_parseFromJSON(cJSON *v1_persistent_volume_claim_volume_sourceJSON){

    v1_persistent_volume_claim_volume_source_t *v1_persistent_volume_claim_volume_source_local_var = NULL;

    // v1_persistent_volume_claim_volume_source->claimName
    cJSON *claimName = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_claim_volume_sourceJSON, "claimName");
    if (!claimName) {
        goto end;
    }

    
    if(!cJSON_IsString(claimName))
    {
    goto end; //String
    }

    // v1_persistent_volume_claim_volume_source->readOnly
    cJSON *readOnly = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_claim_volume_sourceJSON, "readOnly");
    if (readOnly) { 
    if(!cJSON_IsBool(readOnly))
    {
    goto end; //Bool
    }
    }


    v1_persistent_volume_claim_volume_source_local_var = v1_persistent_volume_claim_volume_source_create (
        strdup(claimName->valuestring),
        readOnly ? readOnly->valueint : 0
        );

    return v1_persistent_volume_claim_volume_source_local_var;
end:
    return NULL;

}
