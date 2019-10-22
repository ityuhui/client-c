#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_volume_attachment.h"



v1alpha1_volume_attachment_t *v1alpha1_volume_attachment_create(
    char *apiVersion,
    char *kind,
    v1_object_meta_t *metadata,
    v1alpha1_volume_attachment_spec_t *spec,
    v1alpha1_volume_attachment_status_t *status
    ) {
	v1alpha1_volume_attachment_t *v1alpha1_volume_attachment_local_var = malloc(sizeof(v1alpha1_volume_attachment_t));
    if (!v1alpha1_volume_attachment_local_var) {
        return NULL;
    }
	v1alpha1_volume_attachment_local_var->apiVersion = apiVersion;
	v1alpha1_volume_attachment_local_var->kind = kind;
	v1alpha1_volume_attachment_local_var->metadata = metadata;
	v1alpha1_volume_attachment_local_var->spec = spec;
	v1alpha1_volume_attachment_local_var->status = status;

	return v1alpha1_volume_attachment_local_var;
}


void v1alpha1_volume_attachment_free(v1alpha1_volume_attachment_t *v1alpha1_volume_attachment) {
    listEntry_t *listEntry;
    free(v1alpha1_volume_attachment->apiVersion);
    free(v1alpha1_volume_attachment->kind);
    v1_object_meta_free(v1alpha1_volume_attachment->metadata);
    v1alpha1_volume_attachment_spec_free(v1alpha1_volume_attachment->spec);
    v1alpha1_volume_attachment_status_free(v1alpha1_volume_attachment->status);
	free(v1alpha1_volume_attachment);
}

cJSON *v1alpha1_volume_attachment_convertToJSON(v1alpha1_volume_attachment_t *v1alpha1_volume_attachment) {
	cJSON *item = cJSON_CreateObject();

	// v1alpha1_volume_attachment->apiVersion
    if(v1alpha1_volume_attachment->apiVersion) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1alpha1_volume_attachment->apiVersion) == NULL) {
    goto fail; //String
    }
     } 


	// v1alpha1_volume_attachment->kind
    if(v1alpha1_volume_attachment->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1alpha1_volume_attachment->kind) == NULL) {
    goto fail; //String
    }
     } 


	// v1alpha1_volume_attachment->metadata
    if(v1alpha1_volume_attachment->metadata) { 
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1alpha1_volume_attachment->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1alpha1_volume_attachment->spec
    if (!v1alpha1_volume_attachment->spec) {
        goto fail;
    }
    
    cJSON *spec_local_JSON = v1alpha1_volume_attachment_spec_convertToJSON(v1alpha1_volume_attachment->spec);
    if(spec_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "spec", spec_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


	// v1alpha1_volume_attachment->status
    if(v1alpha1_volume_attachment->status) { 
    cJSON *status_local_JSON = v1alpha1_volume_attachment_status_convertToJSON(v1alpha1_volume_attachment->status);
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

v1alpha1_volume_attachment_t *v1alpha1_volume_attachment_parseFromJSON(cJSON *v1alpha1_volume_attachmentJSON){

    v1alpha1_volume_attachment_t *v1alpha1_volume_attachment_local_var = NULL;

    // v1alpha1_volume_attachment->apiVersion
    cJSON *apiVersion = cJSON_GetObjectItemCaseSensitive(v1alpha1_volume_attachmentJSON, "apiVersion");
    if (apiVersion) { 
    if(!cJSON_IsString(apiVersion))
    {
    goto end; //String
    }
    }

    // v1alpha1_volume_attachment->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1alpha1_volume_attachmentJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1alpha1_volume_attachment->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1alpha1_volume_attachmentJSON, "metadata");
    v1_object_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1alpha1_volume_attachment->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(v1alpha1_volume_attachmentJSON, "spec");
    if (!spec) {
        goto end;
    }

    v1alpha1_volume_attachment_spec_t *spec_local_nonprim = NULL;
    
    spec_local_nonprim = v1alpha1_volume_attachment_spec_parseFromJSON(spec); //nonprimitive

    // v1alpha1_volume_attachment->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(v1alpha1_volume_attachmentJSON, "status");
    v1alpha1_volume_attachment_status_t *status_local_nonprim = NULL;
    if (status) { 
    status_local_nonprim = v1alpha1_volume_attachment_status_parseFromJSON(status); //nonprimitive
    }


    v1alpha1_volume_attachment_local_var = v1alpha1_volume_attachment_create (
        apiVersion ? strdup(apiVersion->valuestring) : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        spec_local_nonprim,
        status ? status_local_nonprim : NULL
        );

    return v1alpha1_volume_attachment_local_var;
end:
    return NULL;

}
