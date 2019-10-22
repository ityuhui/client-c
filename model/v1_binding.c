#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_binding.h"



v1_binding_t *v1_binding_create(
    char *apiVersion,
    char *kind,
    v1_object_meta_t *metadata,
    v1_object_reference_t *target
    ) {
	v1_binding_t *v1_binding_local_var = malloc(sizeof(v1_binding_t));
    if (!v1_binding_local_var) {
        return NULL;
    }
	v1_binding_local_var->apiVersion = apiVersion;
	v1_binding_local_var->kind = kind;
	v1_binding_local_var->metadata = metadata;
	v1_binding_local_var->target = target;

	return v1_binding_local_var;
}


void v1_binding_free(v1_binding_t *v1_binding) {
    listEntry_t *listEntry;
    free(v1_binding->apiVersion);
    free(v1_binding->kind);
    v1_object_meta_free(v1_binding->metadata);
    v1_object_reference_free(v1_binding->target);
	free(v1_binding);
}

cJSON *v1_binding_convertToJSON(v1_binding_t *v1_binding) {
	cJSON *item = cJSON_CreateObject();

	// v1_binding->apiVersion
    if(v1_binding->apiVersion) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1_binding->apiVersion) == NULL) {
    goto fail; //String
    }
     } 


	// v1_binding->kind
    if(v1_binding->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1_binding->kind) == NULL) {
    goto fail; //String
    }
     } 


	// v1_binding->metadata
    if(v1_binding->metadata) { 
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_binding->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_binding->target
    if (!v1_binding->target) {
        goto fail;
    }
    
    cJSON *target_local_JSON = v1_object_reference_convertToJSON(v1_binding->target);
    if(target_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "target", target_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1_binding_t *v1_binding_parseFromJSON(cJSON *v1_bindingJSON){

    v1_binding_t *v1_binding_local_var = NULL;

    // v1_binding->apiVersion
    cJSON *apiVersion = cJSON_GetObjectItemCaseSensitive(v1_bindingJSON, "apiVersion");
    if (apiVersion) { 
    if(!cJSON_IsString(apiVersion))
    {
    goto end; //String
    }
    }

    // v1_binding->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_bindingJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1_binding->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1_bindingJSON, "metadata");
    v1_object_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1_binding->target
    cJSON *target = cJSON_GetObjectItemCaseSensitive(v1_bindingJSON, "target");
    if (!target) {
        goto end;
    }

    v1_object_reference_t *target_local_nonprim = NULL;
    
    target_local_nonprim = v1_object_reference_parseFromJSON(target); //nonprimitive


    v1_binding_local_var = v1_binding_create (
        apiVersion ? strdup(apiVersion->valuestring) : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        target_local_nonprim
        );

    return v1_binding_local_var;
end:
    return NULL;

}
