#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_namespace.h"



v1_namespace_t *v1_namespace_create(
    char *apiVersion,
    char *kind,
    v1_object_meta_t *metadata,
    v1_namespace_spec_t *spec,
    v1_namespace_status_t *status
    ) {
	v1_namespace_t *v1_namespace_local_var = malloc(sizeof(v1_namespace_t));
    if (!v1_namespace_local_var) {
        return NULL;
    }
	v1_namespace_local_var->apiVersion = apiVersion;
	v1_namespace_local_var->kind = kind;
	v1_namespace_local_var->metadata = metadata;
	v1_namespace_local_var->spec = spec;
	v1_namespace_local_var->status = status;

	return v1_namespace_local_var;
}


void v1_namespace_free(v1_namespace_t *v1_namespace) {
    listEntry_t *listEntry;
    free(v1_namespace->apiVersion);
    free(v1_namespace->kind);
    v1_object_meta_free(v1_namespace->metadata);
    v1_namespace_spec_free(v1_namespace->spec);
    v1_namespace_status_free(v1_namespace->status);
	free(v1_namespace);
}

cJSON *v1_namespace_convertToJSON(v1_namespace_t *v1_namespace) {
	cJSON *item = cJSON_CreateObject();

	// v1_namespace->apiVersion
    if(v1_namespace->apiVersion) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1_namespace->apiVersion) == NULL) {
    goto fail; //String
    }
     } 


	// v1_namespace->kind
    if(v1_namespace->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1_namespace->kind) == NULL) {
    goto fail; //String
    }
     } 


	// v1_namespace->metadata
    if(v1_namespace->metadata) { 
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_namespace->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_namespace->spec
    if(v1_namespace->spec) { 
    cJSON *spec_local_JSON = v1_namespace_spec_convertToJSON(v1_namespace->spec);
    if(spec_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "spec", spec_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_namespace->status
    if(v1_namespace->status) { 
    cJSON *status_local_JSON = v1_namespace_status_convertToJSON(v1_namespace->status);
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

v1_namespace_t *v1_namespace_parseFromJSON(cJSON *v1_namespaceJSON){

    v1_namespace_t *v1_namespace_local_var = NULL;

    // v1_namespace->apiVersion
    cJSON *apiVersion = cJSON_GetObjectItemCaseSensitive(v1_namespaceJSON, "apiVersion");
    if (apiVersion) { 
    if(!cJSON_IsString(apiVersion))
    {
    goto end; //String
    }
    }

    // v1_namespace->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_namespaceJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1_namespace->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1_namespaceJSON, "metadata");
    v1_object_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1_namespace->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(v1_namespaceJSON, "spec");
    v1_namespace_spec_t *spec_local_nonprim = NULL;
    if (spec) { 
    spec_local_nonprim = v1_namespace_spec_parseFromJSON(spec); //nonprimitive
    }

    // v1_namespace->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(v1_namespaceJSON, "status");
    v1_namespace_status_t *status_local_nonprim = NULL;
    if (status) { 
    status_local_nonprim = v1_namespace_status_parseFromJSON(status); //nonprimitive
    }


    v1_namespace_local_var = v1_namespace_create (
        apiVersion ? strdup(apiVersion->valuestring) : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        spec ? spec_local_nonprim : NULL,
        status ? status_local_nonprim : NULL
        );

    return v1_namespace_local_var;
end:
    return NULL;

}
