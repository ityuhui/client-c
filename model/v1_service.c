#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_service.h"



v1_service_t *v1_service_create(
    char *apiVersion,
    char *kind,
    v1_object_meta_t *metadata,
    v1_service_spec_t *spec,
    v1_service_status_t *status
    ) {
	v1_service_t *v1_service_local_var = malloc(sizeof(v1_service_t));
    if (!v1_service_local_var) {
        return NULL;
    }
	v1_service_local_var->apiVersion = apiVersion;
	v1_service_local_var->kind = kind;
	v1_service_local_var->metadata = metadata;
	v1_service_local_var->spec = spec;
	v1_service_local_var->status = status;

	return v1_service_local_var;
}


void v1_service_free(v1_service_t *v1_service) {
    listEntry_t *listEntry;
    free(v1_service->apiVersion);
    free(v1_service->kind);
    v1_object_meta_free(v1_service->metadata);
    v1_service_spec_free(v1_service->spec);
    v1_service_status_free(v1_service->status);
	free(v1_service);
}

cJSON *v1_service_convertToJSON(v1_service_t *v1_service) {
	cJSON *item = cJSON_CreateObject();

	// v1_service->apiVersion
    if(v1_service->apiVersion) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1_service->apiVersion) == NULL) {
    goto fail; //String
    }
     } 


	// v1_service->kind
    if(v1_service->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1_service->kind) == NULL) {
    goto fail; //String
    }
     } 


	// v1_service->metadata
    if(v1_service->metadata) { 
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_service->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_service->spec
    if(v1_service->spec) { 
    cJSON *spec_local_JSON = v1_service_spec_convertToJSON(v1_service->spec);
    if(spec_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "spec", spec_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_service->status
    if(v1_service->status) { 
    cJSON *status_local_JSON = v1_service_status_convertToJSON(v1_service->status);
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

v1_service_t *v1_service_parseFromJSON(cJSON *v1_serviceJSON){

    v1_service_t *v1_service_local_var = NULL;

    // v1_service->apiVersion
    cJSON *apiVersion = cJSON_GetObjectItemCaseSensitive(v1_serviceJSON, "apiVersion");
    if (apiVersion) { 
    if(!cJSON_IsString(apiVersion))
    {
    goto end; //String
    }
    }

    // v1_service->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_serviceJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1_service->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1_serviceJSON, "metadata");
    v1_object_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1_service->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(v1_serviceJSON, "spec");
    v1_service_spec_t *spec_local_nonprim = NULL;
    if (spec) { 
    spec_local_nonprim = v1_service_spec_parseFromJSON(spec); //nonprimitive
    }

    // v1_service->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(v1_serviceJSON, "status");
    v1_service_status_t *status_local_nonprim = NULL;
    if (status) { 
    status_local_nonprim = v1_service_status_parseFromJSON(status); //nonprimitive
    }


    v1_service_local_var = v1_service_create (
        apiVersion ? strdup(apiVersion->valuestring) : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        spec ? spec_local_nonprim : NULL,
        status ? status_local_nonprim : NULL
        );

    return v1_service_local_var;
end:
    return NULL;

}
