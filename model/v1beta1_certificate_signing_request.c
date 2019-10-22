#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_certificate_signing_request.h"



v1beta1_certificate_signing_request_t *v1beta1_certificate_signing_request_create(
    char *apiVersion,
    char *kind,
    v1_object_meta_t *metadata,
    v1beta1_certificate_signing_request_spec_t *spec,
    v1beta1_certificate_signing_request_status_t *status
    ) {
	v1beta1_certificate_signing_request_t *v1beta1_certificate_signing_request_local_var = malloc(sizeof(v1beta1_certificate_signing_request_t));
    if (!v1beta1_certificate_signing_request_local_var) {
        return NULL;
    }
	v1beta1_certificate_signing_request_local_var->apiVersion = apiVersion;
	v1beta1_certificate_signing_request_local_var->kind = kind;
	v1beta1_certificate_signing_request_local_var->metadata = metadata;
	v1beta1_certificate_signing_request_local_var->spec = spec;
	v1beta1_certificate_signing_request_local_var->status = status;

	return v1beta1_certificate_signing_request_local_var;
}


void v1beta1_certificate_signing_request_free(v1beta1_certificate_signing_request_t *v1beta1_certificate_signing_request) {
    listEntry_t *listEntry;
    free(v1beta1_certificate_signing_request->apiVersion);
    free(v1beta1_certificate_signing_request->kind);
    v1_object_meta_free(v1beta1_certificate_signing_request->metadata);
    v1beta1_certificate_signing_request_spec_free(v1beta1_certificate_signing_request->spec);
    v1beta1_certificate_signing_request_status_free(v1beta1_certificate_signing_request->status);
	free(v1beta1_certificate_signing_request);
}

cJSON *v1beta1_certificate_signing_request_convertToJSON(v1beta1_certificate_signing_request_t *v1beta1_certificate_signing_request) {
	cJSON *item = cJSON_CreateObject();

	// v1beta1_certificate_signing_request->apiVersion
    if(v1beta1_certificate_signing_request->apiVersion) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1beta1_certificate_signing_request->apiVersion) == NULL) {
    goto fail; //String
    }
     } 


	// v1beta1_certificate_signing_request->kind
    if(v1beta1_certificate_signing_request->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1beta1_certificate_signing_request->kind) == NULL) {
    goto fail; //String
    }
     } 


	// v1beta1_certificate_signing_request->metadata
    if(v1beta1_certificate_signing_request->metadata) { 
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1beta1_certificate_signing_request->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1beta1_certificate_signing_request->spec
    if(v1beta1_certificate_signing_request->spec) { 
    cJSON *spec_local_JSON = v1beta1_certificate_signing_request_spec_convertToJSON(v1beta1_certificate_signing_request->spec);
    if(spec_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "spec", spec_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1beta1_certificate_signing_request->status
    if(v1beta1_certificate_signing_request->status) { 
    cJSON *status_local_JSON = v1beta1_certificate_signing_request_status_convertToJSON(v1beta1_certificate_signing_request->status);
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

v1beta1_certificate_signing_request_t *v1beta1_certificate_signing_request_parseFromJSON(cJSON *v1beta1_certificate_signing_requestJSON){

    v1beta1_certificate_signing_request_t *v1beta1_certificate_signing_request_local_var = NULL;

    // v1beta1_certificate_signing_request->apiVersion
    cJSON *apiVersion = cJSON_GetObjectItemCaseSensitive(v1beta1_certificate_signing_requestJSON, "apiVersion");
    if (apiVersion) { 
    if(!cJSON_IsString(apiVersion))
    {
    goto end; //String
    }
    }

    // v1beta1_certificate_signing_request->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1beta1_certificate_signing_requestJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1beta1_certificate_signing_request->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1beta1_certificate_signing_requestJSON, "metadata");
    v1_object_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1beta1_certificate_signing_request->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(v1beta1_certificate_signing_requestJSON, "spec");
    v1beta1_certificate_signing_request_spec_t *spec_local_nonprim = NULL;
    if (spec) { 
    spec_local_nonprim = v1beta1_certificate_signing_request_spec_parseFromJSON(spec); //nonprimitive
    }

    // v1beta1_certificate_signing_request->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(v1beta1_certificate_signing_requestJSON, "status");
    v1beta1_certificate_signing_request_status_t *status_local_nonprim = NULL;
    if (status) { 
    status_local_nonprim = v1beta1_certificate_signing_request_status_parseFromJSON(status); //nonprimitive
    }


    v1beta1_certificate_signing_request_local_var = v1beta1_certificate_signing_request_create (
        apiVersion ? strdup(apiVersion->valuestring) : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        spec ? spec_local_nonprim : NULL,
        status ? status_local_nonprim : NULL
        );

    return v1beta1_certificate_signing_request_local_var;
end:
    return NULL;

}
