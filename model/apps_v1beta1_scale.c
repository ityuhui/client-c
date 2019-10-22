#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "apps_v1beta1_scale.h"



apps_v1beta1_scale_t *apps_v1beta1_scale_create(
    char *apiVersion,
    char *kind,
    v1_object_meta_t *metadata,
    apps_v1beta1_scale_spec_t *spec,
    apps_v1beta1_scale_status_t *status
    ) {
	apps_v1beta1_scale_t *apps_v1beta1_scale_local_var = malloc(sizeof(apps_v1beta1_scale_t));
    if (!apps_v1beta1_scale_local_var) {
        return NULL;
    }
	apps_v1beta1_scale_local_var->apiVersion = apiVersion;
	apps_v1beta1_scale_local_var->kind = kind;
	apps_v1beta1_scale_local_var->metadata = metadata;
	apps_v1beta1_scale_local_var->spec = spec;
	apps_v1beta1_scale_local_var->status = status;

	return apps_v1beta1_scale_local_var;
}


void apps_v1beta1_scale_free(apps_v1beta1_scale_t *apps_v1beta1_scale) {
    listEntry_t *listEntry;
    free(apps_v1beta1_scale->apiVersion);
    free(apps_v1beta1_scale->kind);
    v1_object_meta_free(apps_v1beta1_scale->metadata);
    apps_v1beta1_scale_spec_free(apps_v1beta1_scale->spec);
    apps_v1beta1_scale_status_free(apps_v1beta1_scale->status);
	free(apps_v1beta1_scale);
}

cJSON *apps_v1beta1_scale_convertToJSON(apps_v1beta1_scale_t *apps_v1beta1_scale) {
	cJSON *item = cJSON_CreateObject();

	// apps_v1beta1_scale->apiVersion
    if(apps_v1beta1_scale->apiVersion) { 
    if(cJSON_AddStringToObject(item, "apiVersion", apps_v1beta1_scale->apiVersion) == NULL) {
    goto fail; //String
    }
     } 


	// apps_v1beta1_scale->kind
    if(apps_v1beta1_scale->kind) { 
    if(cJSON_AddStringToObject(item, "kind", apps_v1beta1_scale->kind) == NULL) {
    goto fail; //String
    }
     } 


	// apps_v1beta1_scale->metadata
    if(apps_v1beta1_scale->metadata) { 
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(apps_v1beta1_scale->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// apps_v1beta1_scale->spec
    if(apps_v1beta1_scale->spec) { 
    cJSON *spec_local_JSON = apps_v1beta1_scale_spec_convertToJSON(apps_v1beta1_scale->spec);
    if(spec_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "spec", spec_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// apps_v1beta1_scale->status
    if(apps_v1beta1_scale->status) { 
    cJSON *status_local_JSON = apps_v1beta1_scale_status_convertToJSON(apps_v1beta1_scale->status);
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

apps_v1beta1_scale_t *apps_v1beta1_scale_parseFromJSON(cJSON *apps_v1beta1_scaleJSON){

    apps_v1beta1_scale_t *apps_v1beta1_scale_local_var = NULL;

    // apps_v1beta1_scale->apiVersion
    cJSON *apiVersion = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_scaleJSON, "apiVersion");
    if (apiVersion) { 
    if(!cJSON_IsString(apiVersion))
    {
    goto end; //String
    }
    }

    // apps_v1beta1_scale->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_scaleJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // apps_v1beta1_scale->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_scaleJSON, "metadata");
    v1_object_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // apps_v1beta1_scale->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_scaleJSON, "spec");
    apps_v1beta1_scale_spec_t *spec_local_nonprim = NULL;
    if (spec) { 
    spec_local_nonprim = apps_v1beta1_scale_spec_parseFromJSON(spec); //nonprimitive
    }

    // apps_v1beta1_scale->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_scaleJSON, "status");
    apps_v1beta1_scale_status_t *status_local_nonprim = NULL;
    if (status) { 
    status_local_nonprim = apps_v1beta1_scale_status_parseFromJSON(status); //nonprimitive
    }


    apps_v1beta1_scale_local_var = apps_v1beta1_scale_create (
        apiVersion ? strdup(apiVersion->valuestring) : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        spec ? spec_local_nonprim : NULL,
        status ? status_local_nonprim : NULL
        );

    return apps_v1beta1_scale_local_var;
end:
    return NULL;

}
