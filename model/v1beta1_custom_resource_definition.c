#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_custom_resource_definition.h"



v1beta1_custom_resource_definition_t *v1beta1_custom_resource_definition_create(
    char *apiVersion,
    char *kind,
    v1_object_meta_t *metadata,
    v1beta1_custom_resource_definition_spec_t *spec,
    v1beta1_custom_resource_definition_status_t *status
    ) {
	v1beta1_custom_resource_definition_t *v1beta1_custom_resource_definition_local_var = malloc(sizeof(v1beta1_custom_resource_definition_t));
    if (!v1beta1_custom_resource_definition_local_var) {
        return NULL;
    }
	v1beta1_custom_resource_definition_local_var->apiVersion = apiVersion;
	v1beta1_custom_resource_definition_local_var->kind = kind;
	v1beta1_custom_resource_definition_local_var->metadata = metadata;
	v1beta1_custom_resource_definition_local_var->spec = spec;
	v1beta1_custom_resource_definition_local_var->status = status;

	return v1beta1_custom_resource_definition_local_var;
}


void v1beta1_custom_resource_definition_free(v1beta1_custom_resource_definition_t *v1beta1_custom_resource_definition) {
    listEntry_t *listEntry;
    free(v1beta1_custom_resource_definition->apiVersion);
    free(v1beta1_custom_resource_definition->kind);
    v1_object_meta_free(v1beta1_custom_resource_definition->metadata);
    v1beta1_custom_resource_definition_spec_free(v1beta1_custom_resource_definition->spec);
    v1beta1_custom_resource_definition_status_free(v1beta1_custom_resource_definition->status);
	free(v1beta1_custom_resource_definition);
}

cJSON *v1beta1_custom_resource_definition_convertToJSON(v1beta1_custom_resource_definition_t *v1beta1_custom_resource_definition) {
	cJSON *item = cJSON_CreateObject();

	// v1beta1_custom_resource_definition->apiVersion
    if(v1beta1_custom_resource_definition->apiVersion) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1beta1_custom_resource_definition->apiVersion) == NULL) {
    goto fail; //String
    }
     } 


	// v1beta1_custom_resource_definition->kind
    if(v1beta1_custom_resource_definition->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1beta1_custom_resource_definition->kind) == NULL) {
    goto fail; //String
    }
     } 


	// v1beta1_custom_resource_definition->metadata
    if(v1beta1_custom_resource_definition->metadata) { 
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1beta1_custom_resource_definition->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1beta1_custom_resource_definition->spec
    if (!v1beta1_custom_resource_definition->spec) {
        goto fail;
    }
    
    cJSON *spec_local_JSON = v1beta1_custom_resource_definition_spec_convertToJSON(v1beta1_custom_resource_definition->spec);
    if(spec_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "spec", spec_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


	// v1beta1_custom_resource_definition->status
    if(v1beta1_custom_resource_definition->status) { 
    cJSON *status_local_JSON = v1beta1_custom_resource_definition_status_convertToJSON(v1beta1_custom_resource_definition->status);
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

v1beta1_custom_resource_definition_t *v1beta1_custom_resource_definition_parseFromJSON(cJSON *v1beta1_custom_resource_definitionJSON){

    v1beta1_custom_resource_definition_t *v1beta1_custom_resource_definition_local_var = NULL;

    // v1beta1_custom_resource_definition->apiVersion
    cJSON *apiVersion = cJSON_GetObjectItemCaseSensitive(v1beta1_custom_resource_definitionJSON, "apiVersion");
    if (apiVersion) { 
    if(!cJSON_IsString(apiVersion))
    {
    goto end; //String
    }
    }

    // v1beta1_custom_resource_definition->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1beta1_custom_resource_definitionJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1beta1_custom_resource_definition->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1beta1_custom_resource_definitionJSON, "metadata");
    v1_object_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1beta1_custom_resource_definition->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(v1beta1_custom_resource_definitionJSON, "spec");
    if (!spec) {
        goto end;
    }

    v1beta1_custom_resource_definition_spec_t *spec_local_nonprim = NULL;
    
    spec_local_nonprim = v1beta1_custom_resource_definition_spec_parseFromJSON(spec); //nonprimitive

    // v1beta1_custom_resource_definition->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(v1beta1_custom_resource_definitionJSON, "status");
    v1beta1_custom_resource_definition_status_t *status_local_nonprim = NULL;
    if (status) { 
    status_local_nonprim = v1beta1_custom_resource_definition_status_parseFromJSON(status); //nonprimitive
    }


    v1beta1_custom_resource_definition_local_var = v1beta1_custom_resource_definition_create (
        apiVersion ? strdup(apiVersion->valuestring) : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        spec_local_nonprim,
        status ? status_local_nonprim : NULL
        );

    return v1beta1_custom_resource_definition_local_var;
end:
    return NULL;

}
