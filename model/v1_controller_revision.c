#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_controller_revision.h"



v1_controller_revision_t *v1_controller_revision_create(
    char *apiVersion,
    object_t *data,
    char *kind,
    v1_object_meta_t *metadata,
    long revision
    ) {
	v1_controller_revision_t *v1_controller_revision_local_var = malloc(sizeof(v1_controller_revision_t));
    if (!v1_controller_revision_local_var) {
        return NULL;
    }
	v1_controller_revision_local_var->apiVersion = apiVersion;
	v1_controller_revision_local_var->data = data;
	v1_controller_revision_local_var->kind = kind;
	v1_controller_revision_local_var->metadata = metadata;
	v1_controller_revision_local_var->revision = revision;

	return v1_controller_revision_local_var;
}


void v1_controller_revision_free(v1_controller_revision_t *v1_controller_revision) {
    listEntry_t *listEntry;
    free(v1_controller_revision->apiVersion);
    object_free(v1_controller_revision->data);
    free(v1_controller_revision->kind);
    v1_object_meta_free(v1_controller_revision->metadata);
	free(v1_controller_revision);
}

cJSON *v1_controller_revision_convertToJSON(v1_controller_revision_t *v1_controller_revision) {
	cJSON *item = cJSON_CreateObject();

	// v1_controller_revision->apiVersion
    if(v1_controller_revision->apiVersion) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1_controller_revision->apiVersion) == NULL) {
    goto fail; //String
    }
     } 


	// v1_controller_revision->data
    if(v1_controller_revision->data) { 
    cJSON *data_object = object_convertToJSON(v1_controller_revision->data);
    if(data_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "data", data_object);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_controller_revision->kind
    if(v1_controller_revision->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1_controller_revision->kind) == NULL) {
    goto fail; //String
    }
     } 


	// v1_controller_revision->metadata
    if(v1_controller_revision->metadata) { 
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_controller_revision->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_controller_revision->revision
    if (!v1_controller_revision->revision) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "revision", v1_controller_revision->revision) == NULL) {
    goto fail; //Numeric
    }

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1_controller_revision_t *v1_controller_revision_parseFromJSON(cJSON *v1_controller_revisionJSON){

    v1_controller_revision_t *v1_controller_revision_local_var = NULL;

    // v1_controller_revision->apiVersion
    cJSON *apiVersion = cJSON_GetObjectItemCaseSensitive(v1_controller_revisionJSON, "apiVersion");
    if (apiVersion) { 
    if(!cJSON_IsString(apiVersion))
    {
    goto end; //String
    }
    }

    // v1_controller_revision->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(v1_controller_revisionJSON, "data");
    object_t *data_local_object = NULL;
    if (data) { 
    data_local_object = object_parseFromJSON(data); //object
    }

    // v1_controller_revision->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_controller_revisionJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1_controller_revision->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1_controller_revisionJSON, "metadata");
    v1_object_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1_controller_revision->revision
    cJSON *revision = cJSON_GetObjectItemCaseSensitive(v1_controller_revisionJSON, "revision");
    if (!revision) {
        goto end;
    }

    
    if(!cJSON_IsNumber(revision))
    {
    goto end; //Numeric
    }


    v1_controller_revision_local_var = v1_controller_revision_create (
        apiVersion ? strdup(apiVersion->valuestring) : NULL,
        data ? data_local_object : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        revision->valuedouble
        );

    return v1_controller_revision_local_var;
end:
    return NULL;

}
