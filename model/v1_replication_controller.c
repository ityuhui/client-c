#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_replication_controller.h"



v1_replication_controller_t *v1_replication_controller_create(
    char *apiVersion,
    char *kind,
    v1_object_meta_t *metadata,
    v1_replication_controller_spec_t *spec,
    v1_replication_controller_status_t *status
    ) {
	v1_replication_controller_t *v1_replication_controller_local_var = malloc(sizeof(v1_replication_controller_t));
    if (!v1_replication_controller_local_var) {
        return NULL;
    }
	v1_replication_controller_local_var->apiVersion = apiVersion;
	v1_replication_controller_local_var->kind = kind;
	v1_replication_controller_local_var->metadata = metadata;
	v1_replication_controller_local_var->spec = spec;
	v1_replication_controller_local_var->status = status;

	return v1_replication_controller_local_var;
}


void v1_replication_controller_free(v1_replication_controller_t *v1_replication_controller) {
    listEntry_t *listEntry;
    free(v1_replication_controller->apiVersion);
    free(v1_replication_controller->kind);
    v1_object_meta_free(v1_replication_controller->metadata);
    v1_replication_controller_spec_free(v1_replication_controller->spec);
    v1_replication_controller_status_free(v1_replication_controller->status);
	free(v1_replication_controller);
}

cJSON *v1_replication_controller_convertToJSON(v1_replication_controller_t *v1_replication_controller) {
	cJSON *item = cJSON_CreateObject();

	// v1_replication_controller->apiVersion
    if(v1_replication_controller->apiVersion) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1_replication_controller->apiVersion) == NULL) {
    goto fail; //String
    }
     } 


	// v1_replication_controller->kind
    if(v1_replication_controller->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1_replication_controller->kind) == NULL) {
    goto fail; //String
    }
     } 


	// v1_replication_controller->metadata
    if(v1_replication_controller->metadata) { 
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_replication_controller->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_replication_controller->spec
    if(v1_replication_controller->spec) { 
    cJSON *spec_local_JSON = v1_replication_controller_spec_convertToJSON(v1_replication_controller->spec);
    if(spec_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "spec", spec_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_replication_controller->status
    if(v1_replication_controller->status) { 
    cJSON *status_local_JSON = v1_replication_controller_status_convertToJSON(v1_replication_controller->status);
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

v1_replication_controller_t *v1_replication_controller_parseFromJSON(cJSON *v1_replication_controllerJSON){

    v1_replication_controller_t *v1_replication_controller_local_var = NULL;

    // v1_replication_controller->apiVersion
    cJSON *apiVersion = cJSON_GetObjectItemCaseSensitive(v1_replication_controllerJSON, "apiVersion");
    if (apiVersion) { 
    if(!cJSON_IsString(apiVersion))
    {
    goto end; //String
    }
    }

    // v1_replication_controller->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_replication_controllerJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1_replication_controller->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1_replication_controllerJSON, "metadata");
    v1_object_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1_replication_controller->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(v1_replication_controllerJSON, "spec");
    v1_replication_controller_spec_t *spec_local_nonprim = NULL;
    if (spec) { 
    spec_local_nonprim = v1_replication_controller_spec_parseFromJSON(spec); //nonprimitive
    }

    // v1_replication_controller->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(v1_replication_controllerJSON, "status");
    v1_replication_controller_status_t *status_local_nonprim = NULL;
    if (status) { 
    status_local_nonprim = v1_replication_controller_status_parseFromJSON(status); //nonprimitive
    }


    v1_replication_controller_local_var = v1_replication_controller_create (
        apiVersion ? strdup(apiVersion->valuestring) : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        spec ? spec_local_nonprim : NULL,
        status ? status_local_nonprim : NULL
        );

    return v1_replication_controller_local_var;
end:
    return NULL;

}
