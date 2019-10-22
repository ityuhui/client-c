#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_endpoints.h"



v1_endpoints_t *v1_endpoints_create(
    char *apiVersion,
    char *kind,
    v1_object_meta_t *metadata,
    list_t *subsets
    ) {
	v1_endpoints_t *v1_endpoints_local_var = malloc(sizeof(v1_endpoints_t));
    if (!v1_endpoints_local_var) {
        return NULL;
    }
	v1_endpoints_local_var->apiVersion = apiVersion;
	v1_endpoints_local_var->kind = kind;
	v1_endpoints_local_var->metadata = metadata;
	v1_endpoints_local_var->subsets = subsets;

	return v1_endpoints_local_var;
}


void v1_endpoints_free(v1_endpoints_t *v1_endpoints) {
    listEntry_t *listEntry;
    free(v1_endpoints->apiVersion);
    free(v1_endpoints->kind);
    v1_object_meta_free(v1_endpoints->metadata);
	list_ForEach(listEntry, v1_endpoints->subsets) {
		v1_endpoint_subset_free(listEntry->data);
	}
	list_free(v1_endpoints->subsets);
	free(v1_endpoints);
}

cJSON *v1_endpoints_convertToJSON(v1_endpoints_t *v1_endpoints) {
	cJSON *item = cJSON_CreateObject();

	// v1_endpoints->apiVersion
    if(v1_endpoints->apiVersion) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1_endpoints->apiVersion) == NULL) {
    goto fail; //String
    }
     } 


	// v1_endpoints->kind
    if(v1_endpoints->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1_endpoints->kind) == NULL) {
    goto fail; //String
    }
     } 


	// v1_endpoints->metadata
    if(v1_endpoints->metadata) { 
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_endpoints->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_endpoints->subsets
    if(v1_endpoints->subsets) { 
    cJSON *subsets = cJSON_AddArrayToObject(item, "subsets");
    if(subsets == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *subsetsListEntry;
    if (v1_endpoints->subsets) {
    list_ForEach(subsetsListEntry, v1_endpoints->subsets) {
    cJSON *itemLocal = v1_endpoint_subset_convertToJSON(subsetsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(subsets, itemLocal);
    }
    }
     } 

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1_endpoints_t *v1_endpoints_parseFromJSON(cJSON *v1_endpointsJSON){

    v1_endpoints_t *v1_endpoints_local_var = NULL;

    // v1_endpoints->apiVersion
    cJSON *apiVersion = cJSON_GetObjectItemCaseSensitive(v1_endpointsJSON, "apiVersion");
    if (apiVersion) { 
    if(!cJSON_IsString(apiVersion))
    {
    goto end; //String
    }
    }

    // v1_endpoints->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_endpointsJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1_endpoints->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1_endpointsJSON, "metadata");
    v1_object_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1_endpoints->subsets
    cJSON *subsets = cJSON_GetObjectItemCaseSensitive(v1_endpointsJSON, "subsets");
    list_t *subsetsList;
    if (subsets) { 
    cJSON *subsets_local_nonprimitive;
    if(!cJSON_IsArray(subsets)){
        goto end; //nonprimitive container
    }

    subsetsList = list_create();

    cJSON_ArrayForEach(subsets_local_nonprimitive,subsets )
    {
        if(!cJSON_IsObject(subsets_local_nonprimitive)){
            goto end;
        }
        v1_endpoint_subset_t *subsetsItem = v1_endpoint_subset_parseFromJSON(subsets_local_nonprimitive);

        list_addElement(subsetsList, subsetsItem);
    }
    }


    v1_endpoints_local_var = v1_endpoints_create (
        apiVersion ? strdup(apiVersion->valuestring) : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        subsets ? subsetsList : NULL
        );

    return v1_endpoints_local_var;
end:
    return NULL;

}
