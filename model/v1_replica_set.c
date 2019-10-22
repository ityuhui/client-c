#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_replica_set.h"



v1_replica_set_t *v1_replica_set_create(
    char *apiVersion,
    char *kind,
    v1_object_meta_t *metadata,
    v1_replica_set_spec_t *spec,
    v1_replica_set_status_t *status
    ) {
	v1_replica_set_t *v1_replica_set_local_var = malloc(sizeof(v1_replica_set_t));
    if (!v1_replica_set_local_var) {
        return NULL;
    }
	v1_replica_set_local_var->apiVersion = apiVersion;
	v1_replica_set_local_var->kind = kind;
	v1_replica_set_local_var->metadata = metadata;
	v1_replica_set_local_var->spec = spec;
	v1_replica_set_local_var->status = status;

	return v1_replica_set_local_var;
}


void v1_replica_set_free(v1_replica_set_t *v1_replica_set) {
    listEntry_t *listEntry;
    free(v1_replica_set->apiVersion);
    free(v1_replica_set->kind);
    v1_object_meta_free(v1_replica_set->metadata);
    v1_replica_set_spec_free(v1_replica_set->spec);
    v1_replica_set_status_free(v1_replica_set->status);
	free(v1_replica_set);
}

cJSON *v1_replica_set_convertToJSON(v1_replica_set_t *v1_replica_set) {
	cJSON *item = cJSON_CreateObject();

	// v1_replica_set->apiVersion
    if(v1_replica_set->apiVersion) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1_replica_set->apiVersion) == NULL) {
    goto fail; //String
    }
     } 


	// v1_replica_set->kind
    if(v1_replica_set->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1_replica_set->kind) == NULL) {
    goto fail; //String
    }
     } 


	// v1_replica_set->metadata
    if(v1_replica_set->metadata) { 
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_replica_set->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_replica_set->spec
    if(v1_replica_set->spec) { 
    cJSON *spec_local_JSON = v1_replica_set_spec_convertToJSON(v1_replica_set->spec);
    if(spec_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "spec", spec_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_replica_set->status
    if(v1_replica_set->status) { 
    cJSON *status_local_JSON = v1_replica_set_status_convertToJSON(v1_replica_set->status);
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

v1_replica_set_t *v1_replica_set_parseFromJSON(cJSON *v1_replica_setJSON){

    v1_replica_set_t *v1_replica_set_local_var = NULL;

    // v1_replica_set->apiVersion
    cJSON *apiVersion = cJSON_GetObjectItemCaseSensitive(v1_replica_setJSON, "apiVersion");
    if (apiVersion) { 
    if(!cJSON_IsString(apiVersion))
    {
    goto end; //String
    }
    }

    // v1_replica_set->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_replica_setJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1_replica_set->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1_replica_setJSON, "metadata");
    v1_object_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1_replica_set->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(v1_replica_setJSON, "spec");
    v1_replica_set_spec_t *spec_local_nonprim = NULL;
    if (spec) { 
    spec_local_nonprim = v1_replica_set_spec_parseFromJSON(spec); //nonprimitive
    }

    // v1_replica_set->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(v1_replica_setJSON, "status");
    v1_replica_set_status_t *status_local_nonprim = NULL;
    if (status) { 
    status_local_nonprim = v1_replica_set_status_parseFromJSON(status); //nonprimitive
    }


    v1_replica_set_local_var = v1_replica_set_create (
        apiVersion ? strdup(apiVersion->valuestring) : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        spec ? spec_local_nonprim : NULL,
        status ? status_local_nonprim : NULL
        );

    return v1_replica_set_local_var;
end:
    return NULL;

}
