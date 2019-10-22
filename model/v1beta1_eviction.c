#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_eviction.h"



v1beta1_eviction_t *v1beta1_eviction_create(
    char *apiVersion,
    v1_delete_options_t *deleteOptions,
    char *kind,
    v1_object_meta_t *metadata
    ) {
	v1beta1_eviction_t *v1beta1_eviction_local_var = malloc(sizeof(v1beta1_eviction_t));
    if (!v1beta1_eviction_local_var) {
        return NULL;
    }
	v1beta1_eviction_local_var->apiVersion = apiVersion;
	v1beta1_eviction_local_var->deleteOptions = deleteOptions;
	v1beta1_eviction_local_var->kind = kind;
	v1beta1_eviction_local_var->metadata = metadata;

	return v1beta1_eviction_local_var;
}


void v1beta1_eviction_free(v1beta1_eviction_t *v1beta1_eviction) {
    listEntry_t *listEntry;
    free(v1beta1_eviction->apiVersion);
    v1_delete_options_free(v1beta1_eviction->deleteOptions);
    free(v1beta1_eviction->kind);
    v1_object_meta_free(v1beta1_eviction->metadata);
	free(v1beta1_eviction);
}

cJSON *v1beta1_eviction_convertToJSON(v1beta1_eviction_t *v1beta1_eviction) {
	cJSON *item = cJSON_CreateObject();

	// v1beta1_eviction->apiVersion
    if(v1beta1_eviction->apiVersion) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1beta1_eviction->apiVersion) == NULL) {
    goto fail; //String
    }
     } 


	// v1beta1_eviction->deleteOptions
    if(v1beta1_eviction->deleteOptions) { 
    cJSON *deleteOptions_local_JSON = v1_delete_options_convertToJSON(v1beta1_eviction->deleteOptions);
    if(deleteOptions_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "deleteOptions", deleteOptions_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1beta1_eviction->kind
    if(v1beta1_eviction->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1beta1_eviction->kind) == NULL) {
    goto fail; //String
    }
     } 


	// v1beta1_eviction->metadata
    if(v1beta1_eviction->metadata) { 
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1beta1_eviction->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
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

v1beta1_eviction_t *v1beta1_eviction_parseFromJSON(cJSON *v1beta1_evictionJSON){

    v1beta1_eviction_t *v1beta1_eviction_local_var = NULL;

    // v1beta1_eviction->apiVersion
    cJSON *apiVersion = cJSON_GetObjectItemCaseSensitive(v1beta1_evictionJSON, "apiVersion");
    if (apiVersion) { 
    if(!cJSON_IsString(apiVersion))
    {
    goto end; //String
    }
    }

    // v1beta1_eviction->deleteOptions
    cJSON *deleteOptions = cJSON_GetObjectItemCaseSensitive(v1beta1_evictionJSON, "deleteOptions");
    v1_delete_options_t *deleteOptions_local_nonprim = NULL;
    if (deleteOptions) { 
    deleteOptions_local_nonprim = v1_delete_options_parseFromJSON(deleteOptions); //nonprimitive
    }

    // v1beta1_eviction->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1beta1_evictionJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1beta1_eviction->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1beta1_evictionJSON, "metadata");
    v1_object_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }


    v1beta1_eviction_local_var = v1beta1_eviction_create (
        apiVersion ? strdup(apiVersion->valuestring) : NULL,
        deleteOptions ? deleteOptions_local_nonprim : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL
        );

    return v1beta1_eviction_local_var;
end:
    return NULL;

}
