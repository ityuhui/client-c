#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_horizontal_pod_autoscaler.h"



v1_horizontal_pod_autoscaler_t *v1_horizontal_pod_autoscaler_create(
    char *apiVersion,
    char *kind,
    v1_object_meta_t *metadata,
    v1_horizontal_pod_autoscaler_spec_t *spec,
    v1_horizontal_pod_autoscaler_status_t *status
    ) {
	v1_horizontal_pod_autoscaler_t *v1_horizontal_pod_autoscaler_local_var = malloc(sizeof(v1_horizontal_pod_autoscaler_t));
    if (!v1_horizontal_pod_autoscaler_local_var) {
        return NULL;
    }
	v1_horizontal_pod_autoscaler_local_var->apiVersion = apiVersion;
	v1_horizontal_pod_autoscaler_local_var->kind = kind;
	v1_horizontal_pod_autoscaler_local_var->metadata = metadata;
	v1_horizontal_pod_autoscaler_local_var->spec = spec;
	v1_horizontal_pod_autoscaler_local_var->status = status;

	return v1_horizontal_pod_autoscaler_local_var;
}


void v1_horizontal_pod_autoscaler_free(v1_horizontal_pod_autoscaler_t *v1_horizontal_pod_autoscaler) {
    listEntry_t *listEntry;
    free(v1_horizontal_pod_autoscaler->apiVersion);
    free(v1_horizontal_pod_autoscaler->kind);
    v1_object_meta_free(v1_horizontal_pod_autoscaler->metadata);
    v1_horizontal_pod_autoscaler_spec_free(v1_horizontal_pod_autoscaler->spec);
    v1_horizontal_pod_autoscaler_status_free(v1_horizontal_pod_autoscaler->status);
	free(v1_horizontal_pod_autoscaler);
}

cJSON *v1_horizontal_pod_autoscaler_convertToJSON(v1_horizontal_pod_autoscaler_t *v1_horizontal_pod_autoscaler) {
	cJSON *item = cJSON_CreateObject();

	// v1_horizontal_pod_autoscaler->apiVersion
    if(v1_horizontal_pod_autoscaler->apiVersion) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1_horizontal_pod_autoscaler->apiVersion) == NULL) {
    goto fail; //String
    }
     } 


	// v1_horizontal_pod_autoscaler->kind
    if(v1_horizontal_pod_autoscaler->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1_horizontal_pod_autoscaler->kind) == NULL) {
    goto fail; //String
    }
     } 


	// v1_horizontal_pod_autoscaler->metadata
    if(v1_horizontal_pod_autoscaler->metadata) { 
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_horizontal_pod_autoscaler->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_horizontal_pod_autoscaler->spec
    if(v1_horizontal_pod_autoscaler->spec) { 
    cJSON *spec_local_JSON = v1_horizontal_pod_autoscaler_spec_convertToJSON(v1_horizontal_pod_autoscaler->spec);
    if(spec_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "spec", spec_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_horizontal_pod_autoscaler->status
    if(v1_horizontal_pod_autoscaler->status) { 
    cJSON *status_local_JSON = v1_horizontal_pod_autoscaler_status_convertToJSON(v1_horizontal_pod_autoscaler->status);
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

v1_horizontal_pod_autoscaler_t *v1_horizontal_pod_autoscaler_parseFromJSON(cJSON *v1_horizontal_pod_autoscalerJSON){

    v1_horizontal_pod_autoscaler_t *v1_horizontal_pod_autoscaler_local_var = NULL;

    // v1_horizontal_pod_autoscaler->apiVersion
    cJSON *apiVersion = cJSON_GetObjectItemCaseSensitive(v1_horizontal_pod_autoscalerJSON, "apiVersion");
    if (apiVersion) { 
    if(!cJSON_IsString(apiVersion))
    {
    goto end; //String
    }
    }

    // v1_horizontal_pod_autoscaler->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_horizontal_pod_autoscalerJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1_horizontal_pod_autoscaler->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1_horizontal_pod_autoscalerJSON, "metadata");
    v1_object_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1_horizontal_pod_autoscaler->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(v1_horizontal_pod_autoscalerJSON, "spec");
    v1_horizontal_pod_autoscaler_spec_t *spec_local_nonprim = NULL;
    if (spec) { 
    spec_local_nonprim = v1_horizontal_pod_autoscaler_spec_parseFromJSON(spec); //nonprimitive
    }

    // v1_horizontal_pod_autoscaler->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(v1_horizontal_pod_autoscalerJSON, "status");
    v1_horizontal_pod_autoscaler_status_t *status_local_nonprim = NULL;
    if (status) { 
    status_local_nonprim = v1_horizontal_pod_autoscaler_status_parseFromJSON(status); //nonprimitive
    }


    v1_horizontal_pod_autoscaler_local_var = v1_horizontal_pod_autoscaler_create (
        apiVersion ? strdup(apiVersion->valuestring) : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        spec ? spec_local_nonprim : NULL,
        status ? status_local_nonprim : NULL
        );

    return v1_horizontal_pod_autoscaler_local_var;
end:
    return NULL;

}
