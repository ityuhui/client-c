#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_token_review.h"



v1_token_review_t *v1_token_review_create(
    char *apiVersion,
    char *kind,
    v1_object_meta_t *metadata,
    v1_token_review_spec_t *spec,
    v1_token_review_status_t *status
    ) {
	v1_token_review_t *v1_token_review_local_var = malloc(sizeof(v1_token_review_t));
    if (!v1_token_review_local_var) {
        return NULL;
    }
	v1_token_review_local_var->apiVersion = apiVersion;
	v1_token_review_local_var->kind = kind;
	v1_token_review_local_var->metadata = metadata;
	v1_token_review_local_var->spec = spec;
	v1_token_review_local_var->status = status;

	return v1_token_review_local_var;
}


void v1_token_review_free(v1_token_review_t *v1_token_review) {
    listEntry_t *listEntry;
    free(v1_token_review->apiVersion);
    free(v1_token_review->kind);
    v1_object_meta_free(v1_token_review->metadata);
    v1_token_review_spec_free(v1_token_review->spec);
    v1_token_review_status_free(v1_token_review->status);
	free(v1_token_review);
}

cJSON *v1_token_review_convertToJSON(v1_token_review_t *v1_token_review) {
	cJSON *item = cJSON_CreateObject();

	// v1_token_review->apiVersion
    if(v1_token_review->apiVersion) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1_token_review->apiVersion) == NULL) {
    goto fail; //String
    }
     } 


	// v1_token_review->kind
    if(v1_token_review->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1_token_review->kind) == NULL) {
    goto fail; //String
    }
     } 


	// v1_token_review->metadata
    if(v1_token_review->metadata) { 
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_token_review->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_token_review->spec
    if (!v1_token_review->spec) {
        goto fail;
    }
    
    cJSON *spec_local_JSON = v1_token_review_spec_convertToJSON(v1_token_review->spec);
    if(spec_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "spec", spec_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


	// v1_token_review->status
    if(v1_token_review->status) { 
    cJSON *status_local_JSON = v1_token_review_status_convertToJSON(v1_token_review->status);
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

v1_token_review_t *v1_token_review_parseFromJSON(cJSON *v1_token_reviewJSON){

    v1_token_review_t *v1_token_review_local_var = NULL;

    // v1_token_review->apiVersion
    cJSON *apiVersion = cJSON_GetObjectItemCaseSensitive(v1_token_reviewJSON, "apiVersion");
    if (apiVersion) { 
    if(!cJSON_IsString(apiVersion))
    {
    goto end; //String
    }
    }

    // v1_token_review->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_token_reviewJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1_token_review->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1_token_reviewJSON, "metadata");
    v1_object_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1_token_review->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(v1_token_reviewJSON, "spec");
    if (!spec) {
        goto end;
    }

    v1_token_review_spec_t *spec_local_nonprim = NULL;
    
    spec_local_nonprim = v1_token_review_spec_parseFromJSON(spec); //nonprimitive

    // v1_token_review->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(v1_token_reviewJSON, "status");
    v1_token_review_status_t *status_local_nonprim = NULL;
    if (status) { 
    status_local_nonprim = v1_token_review_status_parseFromJSON(status); //nonprimitive
    }


    v1_token_review_local_var = v1_token_review_create (
        apiVersion ? strdup(apiVersion->valuestring) : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        spec_local_nonprim,
        status ? status_local_nonprim : NULL
        );

    return v1_token_review_local_var;
end:
    return NULL;

}
