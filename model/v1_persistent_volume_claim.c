#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_persistent_volume_claim.h"



v1_persistent_volume_claim_t *v1_persistent_volume_claim_create(
    char *apiVersion,
    char *kind,
    v1_object_meta_t *metadata,
    v1_persistent_volume_claim_spec_t *spec,
    v1_persistent_volume_claim_status_t *status
    ) {
	v1_persistent_volume_claim_t *v1_persistent_volume_claim_local_var = malloc(sizeof(v1_persistent_volume_claim_t));
    if (!v1_persistent_volume_claim_local_var) {
        return NULL;
    }
	v1_persistent_volume_claim_local_var->apiVersion = apiVersion;
	v1_persistent_volume_claim_local_var->kind = kind;
	v1_persistent_volume_claim_local_var->metadata = metadata;
	v1_persistent_volume_claim_local_var->spec = spec;
	v1_persistent_volume_claim_local_var->status = status;

	return v1_persistent_volume_claim_local_var;
}


void v1_persistent_volume_claim_free(v1_persistent_volume_claim_t *v1_persistent_volume_claim) {
    listEntry_t *listEntry;
    free(v1_persistent_volume_claim->apiVersion);
    free(v1_persistent_volume_claim->kind);
    v1_object_meta_free(v1_persistent_volume_claim->metadata);
    v1_persistent_volume_claim_spec_free(v1_persistent_volume_claim->spec);
    v1_persistent_volume_claim_status_free(v1_persistent_volume_claim->status);
	free(v1_persistent_volume_claim);
}

cJSON *v1_persistent_volume_claim_convertToJSON(v1_persistent_volume_claim_t *v1_persistent_volume_claim) {
	cJSON *item = cJSON_CreateObject();

	// v1_persistent_volume_claim->apiVersion
    if(v1_persistent_volume_claim->apiVersion) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1_persistent_volume_claim->apiVersion) == NULL) {
    goto fail; //String
    }
     } 


	// v1_persistent_volume_claim->kind
    if(v1_persistent_volume_claim->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1_persistent_volume_claim->kind) == NULL) {
    goto fail; //String
    }
     } 


	// v1_persistent_volume_claim->metadata
    if(v1_persistent_volume_claim->metadata) { 
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_persistent_volume_claim->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_persistent_volume_claim->spec
    if(v1_persistent_volume_claim->spec) { 
    cJSON *spec_local_JSON = v1_persistent_volume_claim_spec_convertToJSON(v1_persistent_volume_claim->spec);
    if(spec_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "spec", spec_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_persistent_volume_claim->status
    if(v1_persistent_volume_claim->status) { 
    cJSON *status_local_JSON = v1_persistent_volume_claim_status_convertToJSON(v1_persistent_volume_claim->status);
    if(status_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "status", status_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1_persistent_volume_claim_t *v1_persistent_volume_claim_parseFromJSON(cJSON *v1_persistent_volume_claimJSON){

    v1_persistent_volume_claim_t *v1_persistent_volume_claim_local_var = NULL;

    // v1_persistent_volume_claim->apiVersion
    cJSON *apiVersion = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_claimJSON, "apiVersion");
    if (apiVersion) { 
    if(!cJSON_IsString(apiVersion))
    {
    goto end; //String
    }
    }

    // v1_persistent_volume_claim->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_claimJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1_persistent_volume_claim->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_claimJSON, "metadata");
    v1_object_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1_persistent_volume_claim->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_claimJSON, "spec");
    v1_persistent_volume_claim_spec_t *spec_local_nonprim = NULL;
    if (spec) { 
    spec_local_nonprim = v1_persistent_volume_claim_spec_parseFromJSON(spec); //nonprimitive
    }

    // v1_persistent_volume_claim->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_claimJSON, "status");
    v1_persistent_volume_claim_status_t *status_local_nonprim = NULL;
    if (status) { 
    status_local_nonprim = v1_persistent_volume_claim_status_parseFromJSON(status); //nonprimitive
    }


    v1_persistent_volume_claim_local_var = v1_persistent_volume_claim_create (
        apiVersion ? strdup(apiVersion->valuestring) : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        spec ? spec_local_nonprim : NULL,
        status ? status_local_nonprim : NULL
        );

    return v1_persistent_volume_claim_local_var;
end:
    return NULL;

}
