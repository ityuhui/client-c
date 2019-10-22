#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_resource_quota.h"



v1_resource_quota_t *v1_resource_quota_create(
    char *apiVersion,
    char *kind,
    v1_object_meta_t *metadata,
    v1_resource_quota_spec_t *spec,
    v1_resource_quota_status_t *status
    ) {
	v1_resource_quota_t *v1_resource_quota_local_var = malloc(sizeof(v1_resource_quota_t));
    if (!v1_resource_quota_local_var) {
        return NULL;
    }
	v1_resource_quota_local_var->apiVersion = apiVersion;
	v1_resource_quota_local_var->kind = kind;
	v1_resource_quota_local_var->metadata = metadata;
	v1_resource_quota_local_var->spec = spec;
	v1_resource_quota_local_var->status = status;

	return v1_resource_quota_local_var;
}


void v1_resource_quota_free(v1_resource_quota_t *v1_resource_quota) {
    listEntry_t *listEntry;
    free(v1_resource_quota->apiVersion);
    free(v1_resource_quota->kind);
    v1_object_meta_free(v1_resource_quota->metadata);
    v1_resource_quota_spec_free(v1_resource_quota->spec);
    v1_resource_quota_status_free(v1_resource_quota->status);
	free(v1_resource_quota);
}

cJSON *v1_resource_quota_convertToJSON(v1_resource_quota_t *v1_resource_quota) {
	cJSON *item = cJSON_CreateObject();

	// v1_resource_quota->apiVersion
    if(v1_resource_quota->apiVersion) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1_resource_quota->apiVersion) == NULL) {
    goto fail; //String
    }
     } 


	// v1_resource_quota->kind
    if(v1_resource_quota->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1_resource_quota->kind) == NULL) {
    goto fail; //String
    }
     } 


	// v1_resource_quota->metadata
    if(v1_resource_quota->metadata) { 
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_resource_quota->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_resource_quota->spec
    if(v1_resource_quota->spec) { 
    cJSON *spec_local_JSON = v1_resource_quota_spec_convertToJSON(v1_resource_quota->spec);
    if(spec_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "spec", spec_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_resource_quota->status
    if(v1_resource_quota->status) { 
    cJSON *status_local_JSON = v1_resource_quota_status_convertToJSON(v1_resource_quota->status);
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

v1_resource_quota_t *v1_resource_quota_parseFromJSON(cJSON *v1_resource_quotaJSON){

    v1_resource_quota_t *v1_resource_quota_local_var = NULL;

    // v1_resource_quota->apiVersion
    cJSON *apiVersion = cJSON_GetObjectItemCaseSensitive(v1_resource_quotaJSON, "apiVersion");
    if (apiVersion) { 
    if(!cJSON_IsString(apiVersion))
    {
    goto end; //String
    }
    }

    // v1_resource_quota->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_resource_quotaJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1_resource_quota->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1_resource_quotaJSON, "metadata");
    v1_object_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1_resource_quota->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(v1_resource_quotaJSON, "spec");
    v1_resource_quota_spec_t *spec_local_nonprim = NULL;
    if (spec) { 
    spec_local_nonprim = v1_resource_quota_spec_parseFromJSON(spec); //nonprimitive
    }

    // v1_resource_quota->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(v1_resource_quotaJSON, "status");
    v1_resource_quota_status_t *status_local_nonprim = NULL;
    if (status) { 
    status_local_nonprim = v1_resource_quota_status_parseFromJSON(status); //nonprimitive
    }


    v1_resource_quota_local_var = v1_resource_quota_create (
        apiVersion ? strdup(apiVersion->valuestring) : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        spec ? spec_local_nonprim : NULL,
        status ? status_local_nonprim : NULL
        );

    return v1_resource_quota_local_var;
end:
    return NULL;

}
