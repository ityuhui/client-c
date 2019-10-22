#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_pod_preset.h"



v1alpha1_pod_preset_t *v1alpha1_pod_preset_create(
    char *apiVersion,
    char *kind,
    v1_object_meta_t *metadata,
    v1alpha1_pod_preset_spec_t *spec
    ) {
	v1alpha1_pod_preset_t *v1alpha1_pod_preset_local_var = malloc(sizeof(v1alpha1_pod_preset_t));
    if (!v1alpha1_pod_preset_local_var) {
        return NULL;
    }
	v1alpha1_pod_preset_local_var->apiVersion = apiVersion;
	v1alpha1_pod_preset_local_var->kind = kind;
	v1alpha1_pod_preset_local_var->metadata = metadata;
	v1alpha1_pod_preset_local_var->spec = spec;

	return v1alpha1_pod_preset_local_var;
}


void v1alpha1_pod_preset_free(v1alpha1_pod_preset_t *v1alpha1_pod_preset) {
    listEntry_t *listEntry;
    free(v1alpha1_pod_preset->apiVersion);
    free(v1alpha1_pod_preset->kind);
    v1_object_meta_free(v1alpha1_pod_preset->metadata);
    v1alpha1_pod_preset_spec_free(v1alpha1_pod_preset->spec);
	free(v1alpha1_pod_preset);
}

cJSON *v1alpha1_pod_preset_convertToJSON(v1alpha1_pod_preset_t *v1alpha1_pod_preset) {
	cJSON *item = cJSON_CreateObject();

	// v1alpha1_pod_preset->apiVersion
    if(v1alpha1_pod_preset->apiVersion) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1alpha1_pod_preset->apiVersion) == NULL) {
    goto fail; //String
    }
     } 


	// v1alpha1_pod_preset->kind
    if(v1alpha1_pod_preset->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1alpha1_pod_preset->kind) == NULL) {
    goto fail; //String
    }
     } 


	// v1alpha1_pod_preset->metadata
    if(v1alpha1_pod_preset->metadata) { 
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1alpha1_pod_preset->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1alpha1_pod_preset->spec
    if(v1alpha1_pod_preset->spec) { 
    cJSON *spec_local_JSON = v1alpha1_pod_preset_spec_convertToJSON(v1alpha1_pod_preset->spec);
    if(spec_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "spec", spec_local_JSON);
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

v1alpha1_pod_preset_t *v1alpha1_pod_preset_parseFromJSON(cJSON *v1alpha1_pod_presetJSON){

    v1alpha1_pod_preset_t *v1alpha1_pod_preset_local_var = NULL;

    // v1alpha1_pod_preset->apiVersion
    cJSON *apiVersion = cJSON_GetObjectItemCaseSensitive(v1alpha1_pod_presetJSON, "apiVersion");
    if (apiVersion) { 
    if(!cJSON_IsString(apiVersion))
    {
    goto end; //String
    }
    }

    // v1alpha1_pod_preset->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1alpha1_pod_presetJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1alpha1_pod_preset->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1alpha1_pod_presetJSON, "metadata");
    v1_object_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1alpha1_pod_preset->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(v1alpha1_pod_presetJSON, "spec");
    v1alpha1_pod_preset_spec_t *spec_local_nonprim = NULL;
    if (spec) { 
    spec_local_nonprim = v1alpha1_pod_preset_spec_parseFromJSON(spec); //nonprimitive
    }


    v1alpha1_pod_preset_local_var = v1alpha1_pod_preset_create (
        apiVersion ? strdup(apiVersion->valuestring) : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        spec ? spec_local_nonprim : NULL
        );

    return v1alpha1_pod_preset_local_var;
end:
    return NULL;

}
