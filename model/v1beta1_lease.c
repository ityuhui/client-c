#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_lease.h"



v1beta1_lease_t *v1beta1_lease_create(
    char *apiVersion,
    char *kind,
    v1_object_meta_t *metadata,
    v1beta1_lease_spec_t *spec
    ) {
	v1beta1_lease_t *v1beta1_lease_local_var = malloc(sizeof(v1beta1_lease_t));
    if (!v1beta1_lease_local_var) {
        return NULL;
    }
	v1beta1_lease_local_var->apiVersion = apiVersion;
	v1beta1_lease_local_var->kind = kind;
	v1beta1_lease_local_var->metadata = metadata;
	v1beta1_lease_local_var->spec = spec;

	return v1beta1_lease_local_var;
}


void v1beta1_lease_free(v1beta1_lease_t *v1beta1_lease) {
    listEntry_t *listEntry;
    free(v1beta1_lease->apiVersion);
    free(v1beta1_lease->kind);
    v1_object_meta_free(v1beta1_lease->metadata);
    v1beta1_lease_spec_free(v1beta1_lease->spec);
	free(v1beta1_lease);
}

cJSON *v1beta1_lease_convertToJSON(v1beta1_lease_t *v1beta1_lease) {
	cJSON *item = cJSON_CreateObject();

	// v1beta1_lease->apiVersion
    if(v1beta1_lease->apiVersion) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1beta1_lease->apiVersion) == NULL) {
    goto fail; //String
    }
     } 


	// v1beta1_lease->kind
    if(v1beta1_lease->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1beta1_lease->kind) == NULL) {
    goto fail; //String
    }
     } 


	// v1beta1_lease->metadata
    if(v1beta1_lease->metadata) { 
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1beta1_lease->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1beta1_lease->spec
    if(v1beta1_lease->spec) { 
    cJSON *spec_local_JSON = v1beta1_lease_spec_convertToJSON(v1beta1_lease->spec);
    if(spec_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "spec", spec_local_JSON);
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

v1beta1_lease_t *v1beta1_lease_parseFromJSON(cJSON *v1beta1_leaseJSON){

    v1beta1_lease_t *v1beta1_lease_local_var = NULL;

    // v1beta1_lease->apiVersion
    cJSON *apiVersion = cJSON_GetObjectItemCaseSensitive(v1beta1_leaseJSON, "apiVersion");
    if (apiVersion) { 
    if(!cJSON_IsString(apiVersion))
    {
    goto end; //String
    }
    }

    // v1beta1_lease->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1beta1_leaseJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1beta1_lease->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1beta1_leaseJSON, "metadata");
    v1_object_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1beta1_lease->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(v1beta1_leaseJSON, "spec");
    v1beta1_lease_spec_t *spec_local_nonprim = NULL;
    if (spec) { 
    spec_local_nonprim = v1beta1_lease_spec_parseFromJSON(spec); //nonprimitive
    }


    v1beta1_lease_local_var = v1beta1_lease_create (
        apiVersion ? strdup(apiVersion->valuestring) : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        spec ? spec_local_nonprim : NULL
        );

    return v1beta1_lease_local_var;
end:
    return NULL;

}
