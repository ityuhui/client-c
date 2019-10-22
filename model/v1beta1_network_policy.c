#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_network_policy.h"



v1beta1_network_policy_t *v1beta1_network_policy_create(
    char *apiVersion,
    char *kind,
    v1_object_meta_t *metadata,
    v1beta1_network_policy_spec_t *spec
    ) {
	v1beta1_network_policy_t *v1beta1_network_policy_local_var = malloc(sizeof(v1beta1_network_policy_t));
    if (!v1beta1_network_policy_local_var) {
        return NULL;
    }
	v1beta1_network_policy_local_var->apiVersion = apiVersion;
	v1beta1_network_policy_local_var->kind = kind;
	v1beta1_network_policy_local_var->metadata = metadata;
	v1beta1_network_policy_local_var->spec = spec;

	return v1beta1_network_policy_local_var;
}


void v1beta1_network_policy_free(v1beta1_network_policy_t *v1beta1_network_policy) {
    listEntry_t *listEntry;
    free(v1beta1_network_policy->apiVersion);
    free(v1beta1_network_policy->kind);
    v1_object_meta_free(v1beta1_network_policy->metadata);
    v1beta1_network_policy_spec_free(v1beta1_network_policy->spec);
	free(v1beta1_network_policy);
}

cJSON *v1beta1_network_policy_convertToJSON(v1beta1_network_policy_t *v1beta1_network_policy) {
	cJSON *item = cJSON_CreateObject();

	// v1beta1_network_policy->apiVersion
    if(v1beta1_network_policy->apiVersion) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1beta1_network_policy->apiVersion) == NULL) {
    goto fail; //String
    }
     } 


	// v1beta1_network_policy->kind
    if(v1beta1_network_policy->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1beta1_network_policy->kind) == NULL) {
    goto fail; //String
    }
     } 


	// v1beta1_network_policy->metadata
    if(v1beta1_network_policy->metadata) { 
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1beta1_network_policy->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1beta1_network_policy->spec
    if(v1beta1_network_policy->spec) { 
    cJSON *spec_local_JSON = v1beta1_network_policy_spec_convertToJSON(v1beta1_network_policy->spec);
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

v1beta1_network_policy_t *v1beta1_network_policy_parseFromJSON(cJSON *v1beta1_network_policyJSON){

    v1beta1_network_policy_t *v1beta1_network_policy_local_var = NULL;

    // v1beta1_network_policy->apiVersion
    cJSON *apiVersion = cJSON_GetObjectItemCaseSensitive(v1beta1_network_policyJSON, "apiVersion");
    if (apiVersion) { 
    if(!cJSON_IsString(apiVersion))
    {
    goto end; //String
    }
    }

    // v1beta1_network_policy->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1beta1_network_policyJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1beta1_network_policy->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1beta1_network_policyJSON, "metadata");
    v1_object_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1beta1_network_policy->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(v1beta1_network_policyJSON, "spec");
    v1beta1_network_policy_spec_t *spec_local_nonprim = NULL;
    if (spec) { 
    spec_local_nonprim = v1beta1_network_policy_spec_parseFromJSON(spec); //nonprimitive
    }


    v1beta1_network_policy_local_var = v1beta1_network_policy_create (
        apiVersion ? strdup(apiVersion->valuestring) : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        spec ? spec_local_nonprim : NULL
        );

    return v1beta1_network_policy_local_var;
end:
    return NULL;

}
