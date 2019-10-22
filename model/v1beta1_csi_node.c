#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_csi_node.h"



v1beta1_csi_node_t *v1beta1_csi_node_create(
    char *apiVersion,
    char *kind,
    v1_object_meta_t *metadata,
    v1beta1_csi_node_spec_t *spec
    ) {
	v1beta1_csi_node_t *v1beta1_csi_node_local_var = malloc(sizeof(v1beta1_csi_node_t));
    if (!v1beta1_csi_node_local_var) {
        return NULL;
    }
	v1beta1_csi_node_local_var->apiVersion = apiVersion;
	v1beta1_csi_node_local_var->kind = kind;
	v1beta1_csi_node_local_var->metadata = metadata;
	v1beta1_csi_node_local_var->spec = spec;

	return v1beta1_csi_node_local_var;
}


void v1beta1_csi_node_free(v1beta1_csi_node_t *v1beta1_csi_node) {
    listEntry_t *listEntry;
    free(v1beta1_csi_node->apiVersion);
    free(v1beta1_csi_node->kind);
    v1_object_meta_free(v1beta1_csi_node->metadata);
    v1beta1_csi_node_spec_free(v1beta1_csi_node->spec);
	free(v1beta1_csi_node);
}

cJSON *v1beta1_csi_node_convertToJSON(v1beta1_csi_node_t *v1beta1_csi_node) {
	cJSON *item = cJSON_CreateObject();

	// v1beta1_csi_node->apiVersion
    if(v1beta1_csi_node->apiVersion) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1beta1_csi_node->apiVersion) == NULL) {
    goto fail; //String
    }
     } 


	// v1beta1_csi_node->kind
    if(v1beta1_csi_node->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1beta1_csi_node->kind) == NULL) {
    goto fail; //String
    }
     } 


	// v1beta1_csi_node->metadata
    if(v1beta1_csi_node->metadata) { 
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1beta1_csi_node->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1beta1_csi_node->spec
    if (!v1beta1_csi_node->spec) {
        goto fail;
    }
    
    cJSON *spec_local_JSON = v1beta1_csi_node_spec_convertToJSON(v1beta1_csi_node->spec);
    if(spec_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "spec", spec_local_JSON);
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

v1beta1_csi_node_t *v1beta1_csi_node_parseFromJSON(cJSON *v1beta1_csi_nodeJSON){

    v1beta1_csi_node_t *v1beta1_csi_node_local_var = NULL;

    // v1beta1_csi_node->apiVersion
    cJSON *apiVersion = cJSON_GetObjectItemCaseSensitive(v1beta1_csi_nodeJSON, "apiVersion");
    if (apiVersion) { 
    if(!cJSON_IsString(apiVersion))
    {
    goto end; //String
    }
    }

    // v1beta1_csi_node->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1beta1_csi_nodeJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1beta1_csi_node->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1beta1_csi_nodeJSON, "metadata");
    v1_object_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1beta1_csi_node->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(v1beta1_csi_nodeJSON, "spec");
    if (!spec) {
        goto end;
    }

    v1beta1_csi_node_spec_t *spec_local_nonprim = NULL;
    
    spec_local_nonprim = v1beta1_csi_node_spec_parseFromJSON(spec); //nonprimitive


    v1beta1_csi_node_local_var = v1beta1_csi_node_create (
        apiVersion ? strdup(apiVersion->valuestring) : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        spec_local_nonprim
        );

    return v1beta1_csi_node_local_var;
end:
    return NULL;

}
