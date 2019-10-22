#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_limit_range.h"



v1_limit_range_t *v1_limit_range_create(
    char *apiVersion,
    char *kind,
    v1_object_meta_t *metadata,
    v1_limit_range_spec_t *spec
    ) {
	v1_limit_range_t *v1_limit_range_local_var = malloc(sizeof(v1_limit_range_t));
    if (!v1_limit_range_local_var) {
        return NULL;
    }
	v1_limit_range_local_var->apiVersion = apiVersion;
	v1_limit_range_local_var->kind = kind;
	v1_limit_range_local_var->metadata = metadata;
	v1_limit_range_local_var->spec = spec;

	return v1_limit_range_local_var;
}


void v1_limit_range_free(v1_limit_range_t *v1_limit_range) {
    listEntry_t *listEntry;
    free(v1_limit_range->apiVersion);
    free(v1_limit_range->kind);
    v1_object_meta_free(v1_limit_range->metadata);
    v1_limit_range_spec_free(v1_limit_range->spec);
	free(v1_limit_range);
}

cJSON *v1_limit_range_convertToJSON(v1_limit_range_t *v1_limit_range) {
	cJSON *item = cJSON_CreateObject();

	// v1_limit_range->apiVersion
    if(v1_limit_range->apiVersion) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1_limit_range->apiVersion) == NULL) {
    goto fail; //String
    }
     } 


	// v1_limit_range->kind
    if(v1_limit_range->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1_limit_range->kind) == NULL) {
    goto fail; //String
    }
     } 


	// v1_limit_range->metadata
    if(v1_limit_range->metadata) { 
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_limit_range->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_limit_range->spec
    if(v1_limit_range->spec) { 
    cJSON *spec_local_JSON = v1_limit_range_spec_convertToJSON(v1_limit_range->spec);
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

v1_limit_range_t *v1_limit_range_parseFromJSON(cJSON *v1_limit_rangeJSON){

    v1_limit_range_t *v1_limit_range_local_var = NULL;

    // v1_limit_range->apiVersion
    cJSON *apiVersion = cJSON_GetObjectItemCaseSensitive(v1_limit_rangeJSON, "apiVersion");
    if (apiVersion) { 
    if(!cJSON_IsString(apiVersion))
    {
    goto end; //String
    }
    }

    // v1_limit_range->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_limit_rangeJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1_limit_range->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1_limit_rangeJSON, "metadata");
    v1_object_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1_limit_range->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(v1_limit_rangeJSON, "spec");
    v1_limit_range_spec_t *spec_local_nonprim = NULL;
    if (spec) { 
    spec_local_nonprim = v1_limit_range_spec_parseFromJSON(spec); //nonprimitive
    }


    v1_limit_range_local_var = v1_limit_range_create (
        apiVersion ? strdup(apiVersion->valuestring) : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        spec ? spec_local_nonprim : NULL
        );

    return v1_limit_range_local_var;
end:
    return NULL;

}
