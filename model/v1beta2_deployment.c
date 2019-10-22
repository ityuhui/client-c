#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta2_deployment.h"



v1beta2_deployment_t *v1beta2_deployment_create(
    char *apiVersion,
    char *kind,
    v1_object_meta_t *metadata,
    v1beta2_deployment_spec_t *spec,
    v1beta2_deployment_status_t *status
    ) {
	v1beta2_deployment_t *v1beta2_deployment_local_var = malloc(sizeof(v1beta2_deployment_t));
    if (!v1beta2_deployment_local_var) {
        return NULL;
    }
	v1beta2_deployment_local_var->apiVersion = apiVersion;
	v1beta2_deployment_local_var->kind = kind;
	v1beta2_deployment_local_var->metadata = metadata;
	v1beta2_deployment_local_var->spec = spec;
	v1beta2_deployment_local_var->status = status;

	return v1beta2_deployment_local_var;
}


void v1beta2_deployment_free(v1beta2_deployment_t *v1beta2_deployment) {
    listEntry_t *listEntry;
    free(v1beta2_deployment->apiVersion);
    free(v1beta2_deployment->kind);
    v1_object_meta_free(v1beta2_deployment->metadata);
    v1beta2_deployment_spec_free(v1beta2_deployment->spec);
    v1beta2_deployment_status_free(v1beta2_deployment->status);
	free(v1beta2_deployment);
}

cJSON *v1beta2_deployment_convertToJSON(v1beta2_deployment_t *v1beta2_deployment) {
	cJSON *item = cJSON_CreateObject();

	// v1beta2_deployment->apiVersion
    if(v1beta2_deployment->apiVersion) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1beta2_deployment->apiVersion) == NULL) {
    goto fail; //String
    }
     } 


	// v1beta2_deployment->kind
    if(v1beta2_deployment->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1beta2_deployment->kind) == NULL) {
    goto fail; //String
    }
     } 


	// v1beta2_deployment->metadata
    if(v1beta2_deployment->metadata) { 
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1beta2_deployment->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1beta2_deployment->spec
    if(v1beta2_deployment->spec) { 
    cJSON *spec_local_JSON = v1beta2_deployment_spec_convertToJSON(v1beta2_deployment->spec);
    if(spec_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "spec", spec_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1beta2_deployment->status
    if(v1beta2_deployment->status) { 
    cJSON *status_local_JSON = v1beta2_deployment_status_convertToJSON(v1beta2_deployment->status);
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

v1beta2_deployment_t *v1beta2_deployment_parseFromJSON(cJSON *v1beta2_deploymentJSON){

    v1beta2_deployment_t *v1beta2_deployment_local_var = NULL;

    // v1beta2_deployment->apiVersion
    cJSON *apiVersion = cJSON_GetObjectItemCaseSensitive(v1beta2_deploymentJSON, "apiVersion");
    if (apiVersion) { 
    if(!cJSON_IsString(apiVersion))
    {
    goto end; //String
    }
    }

    // v1beta2_deployment->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1beta2_deploymentJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1beta2_deployment->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1beta2_deploymentJSON, "metadata");
    v1_object_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1beta2_deployment->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(v1beta2_deploymentJSON, "spec");
    v1beta2_deployment_spec_t *spec_local_nonprim = NULL;
    if (spec) { 
    spec_local_nonprim = v1beta2_deployment_spec_parseFromJSON(spec); //nonprimitive
    }

    // v1beta2_deployment->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(v1beta2_deploymentJSON, "status");
    v1beta2_deployment_status_t *status_local_nonprim = NULL;
    if (status) { 
    status_local_nonprim = v1beta2_deployment_status_parseFromJSON(status); //nonprimitive
    }


    v1beta2_deployment_local_var = v1beta2_deployment_create (
        apiVersion ? strdup(apiVersion->valuestring) : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        spec ? spec_local_nonprim : NULL,
        status ? status_local_nonprim : NULL
        );

    return v1beta2_deployment_local_var;
end:
    return NULL;

}
