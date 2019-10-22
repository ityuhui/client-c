#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "networking_v1beta1_ingress.h"



networking_v1beta1_ingress_t *networking_v1beta1_ingress_create(
    char *apiVersion,
    char *kind,
    v1_object_meta_t *metadata,
    networking_v1beta1_ingress_spec_t *spec,
    networking_v1beta1_ingress_status_t *status
    ) {
	networking_v1beta1_ingress_t *networking_v1beta1_ingress_local_var = malloc(sizeof(networking_v1beta1_ingress_t));
    if (!networking_v1beta1_ingress_local_var) {
        return NULL;
    }
	networking_v1beta1_ingress_local_var->apiVersion = apiVersion;
	networking_v1beta1_ingress_local_var->kind = kind;
	networking_v1beta1_ingress_local_var->metadata = metadata;
	networking_v1beta1_ingress_local_var->spec = spec;
	networking_v1beta1_ingress_local_var->status = status;

	return networking_v1beta1_ingress_local_var;
}


void networking_v1beta1_ingress_free(networking_v1beta1_ingress_t *networking_v1beta1_ingress) {
    listEntry_t *listEntry;
    free(networking_v1beta1_ingress->apiVersion);
    free(networking_v1beta1_ingress->kind);
    v1_object_meta_free(networking_v1beta1_ingress->metadata);
    networking_v1beta1_ingress_spec_free(networking_v1beta1_ingress->spec);
    networking_v1beta1_ingress_status_free(networking_v1beta1_ingress->status);
	free(networking_v1beta1_ingress);
}

cJSON *networking_v1beta1_ingress_convertToJSON(networking_v1beta1_ingress_t *networking_v1beta1_ingress) {
	cJSON *item = cJSON_CreateObject();

	// networking_v1beta1_ingress->apiVersion
    if(networking_v1beta1_ingress->apiVersion) { 
    if(cJSON_AddStringToObject(item, "apiVersion", networking_v1beta1_ingress->apiVersion) == NULL) {
    goto fail; //String
    }
     } 


	// networking_v1beta1_ingress->kind
    if(networking_v1beta1_ingress->kind) { 
    if(cJSON_AddStringToObject(item, "kind", networking_v1beta1_ingress->kind) == NULL) {
    goto fail; //String
    }
     } 


	// networking_v1beta1_ingress->metadata
    if(networking_v1beta1_ingress->metadata) { 
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(networking_v1beta1_ingress->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// networking_v1beta1_ingress->spec
    if(networking_v1beta1_ingress->spec) { 
    cJSON *spec_local_JSON = networking_v1beta1_ingress_spec_convertToJSON(networking_v1beta1_ingress->spec);
    if(spec_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "spec", spec_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// networking_v1beta1_ingress->status
    if(networking_v1beta1_ingress->status) { 
    cJSON *status_local_JSON = networking_v1beta1_ingress_status_convertToJSON(networking_v1beta1_ingress->status);
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

networking_v1beta1_ingress_t *networking_v1beta1_ingress_parseFromJSON(cJSON *networking_v1beta1_ingressJSON){

    networking_v1beta1_ingress_t *networking_v1beta1_ingress_local_var = NULL;

    // networking_v1beta1_ingress->apiVersion
    cJSON *apiVersion = cJSON_GetObjectItemCaseSensitive(networking_v1beta1_ingressJSON, "apiVersion");
    if (apiVersion) { 
    if(!cJSON_IsString(apiVersion))
    {
    goto end; //String
    }
    }

    // networking_v1beta1_ingress->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(networking_v1beta1_ingressJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // networking_v1beta1_ingress->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(networking_v1beta1_ingressJSON, "metadata");
    v1_object_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // networking_v1beta1_ingress->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(networking_v1beta1_ingressJSON, "spec");
    networking_v1beta1_ingress_spec_t *spec_local_nonprim = NULL;
    if (spec) { 
    spec_local_nonprim = networking_v1beta1_ingress_spec_parseFromJSON(spec); //nonprimitive
    }

    // networking_v1beta1_ingress->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(networking_v1beta1_ingressJSON, "status");
    networking_v1beta1_ingress_status_t *status_local_nonprim = NULL;
    if (status) { 
    status_local_nonprim = networking_v1beta1_ingress_status_parseFromJSON(status); //nonprimitive
    }


    networking_v1beta1_ingress_local_var = networking_v1beta1_ingress_create (
        apiVersion ? strdup(apiVersion->valuestring) : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        spec ? spec_local_nonprim : NULL,
        status ? status_local_nonprim : NULL
        );

    return networking_v1beta1_ingress_local_var;
end:
    return NULL;

}
