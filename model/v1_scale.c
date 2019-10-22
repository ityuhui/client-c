#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_scale.h"



v1_scale_t *v1_scale_create(
    char *apiVersion,
    char *kind,
    v1_object_meta_t *metadata,
    v1_scale_spec_t *spec,
    v1_scale_status_t *status
    ) {
	v1_scale_t *v1_scale_local_var = malloc(sizeof(v1_scale_t));
    if (!v1_scale_local_var) {
        return NULL;
    }
	v1_scale_local_var->apiVersion = apiVersion;
	v1_scale_local_var->kind = kind;
	v1_scale_local_var->metadata = metadata;
	v1_scale_local_var->spec = spec;
	v1_scale_local_var->status = status;

	return v1_scale_local_var;
}


void v1_scale_free(v1_scale_t *v1_scale) {
    listEntry_t *listEntry;
    free(v1_scale->apiVersion);
    free(v1_scale->kind);
    v1_object_meta_free(v1_scale->metadata);
    v1_scale_spec_free(v1_scale->spec);
    v1_scale_status_free(v1_scale->status);
	free(v1_scale);
}

cJSON *v1_scale_convertToJSON(v1_scale_t *v1_scale) {
	cJSON *item = cJSON_CreateObject();

	// v1_scale->apiVersion
    if(v1_scale->apiVersion) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1_scale->apiVersion) == NULL) {
    goto fail; //String
    }
     } 


	// v1_scale->kind
    if(v1_scale->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1_scale->kind) == NULL) {
    goto fail; //String
    }
     } 


	// v1_scale->metadata
    if(v1_scale->metadata) { 
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_scale->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_scale->spec
    if(v1_scale->spec) { 
    cJSON *spec_local_JSON = v1_scale_spec_convertToJSON(v1_scale->spec);
    if(spec_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "spec", spec_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_scale->status
    if(v1_scale->status) { 
    cJSON *status_local_JSON = v1_scale_status_convertToJSON(v1_scale->status);
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

v1_scale_t *v1_scale_parseFromJSON(cJSON *v1_scaleJSON){

    v1_scale_t *v1_scale_local_var = NULL;

    // v1_scale->apiVersion
    cJSON *apiVersion = cJSON_GetObjectItemCaseSensitive(v1_scaleJSON, "apiVersion");
    if (apiVersion) { 
    if(!cJSON_IsString(apiVersion))
    {
    goto end; //String
    }
    }

    // v1_scale->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_scaleJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1_scale->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1_scaleJSON, "metadata");
    v1_object_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1_scale->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(v1_scaleJSON, "spec");
    v1_scale_spec_t *spec_local_nonprim = NULL;
    if (spec) { 
    spec_local_nonprim = v1_scale_spec_parseFromJSON(spec); //nonprimitive
    }

    // v1_scale->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(v1_scaleJSON, "status");
    v1_scale_status_t *status_local_nonprim = NULL;
    if (status) { 
    status_local_nonprim = v1_scale_status_parseFromJSON(status); //nonprimitive
    }


    v1_scale_local_var = v1_scale_create (
        apiVersion ? strdup(apiVersion->valuestring) : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        spec ? spec_local_nonprim : NULL,
        status ? status_local_nonprim : NULL
        );

    return v1_scale_local_var;
end:
    return NULL;

}
