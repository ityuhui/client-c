#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_job.h"



v1_job_t *v1_job_create(
    char *apiVersion,
    char *kind,
    v1_object_meta_t *metadata,
    v1_job_spec_t *spec,
    v1_job_status_t *status
    ) {
	v1_job_t *v1_job_local_var = malloc(sizeof(v1_job_t));
    if (!v1_job_local_var) {
        return NULL;
    }
	v1_job_local_var->apiVersion = apiVersion;
	v1_job_local_var->kind = kind;
	v1_job_local_var->metadata = metadata;
	v1_job_local_var->spec = spec;
	v1_job_local_var->status = status;

	return v1_job_local_var;
}


void v1_job_free(v1_job_t *v1_job) {
    listEntry_t *listEntry;
    free(v1_job->apiVersion);
    free(v1_job->kind);
    v1_object_meta_free(v1_job->metadata);
    v1_job_spec_free(v1_job->spec);
    v1_job_status_free(v1_job->status);
	free(v1_job);
}

cJSON *v1_job_convertToJSON(v1_job_t *v1_job) {
	cJSON *item = cJSON_CreateObject();

	// v1_job->apiVersion
    if(v1_job->apiVersion) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1_job->apiVersion) == NULL) {
    goto fail; //String
    }
     } 


	// v1_job->kind
    if(v1_job->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1_job->kind) == NULL) {
    goto fail; //String
    }
     } 


	// v1_job->metadata
    if(v1_job->metadata) { 
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_job->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_job->spec
    if(v1_job->spec) { 
    cJSON *spec_local_JSON = v1_job_spec_convertToJSON(v1_job->spec);
    if(spec_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "spec", spec_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_job->status
    if(v1_job->status) { 
    cJSON *status_local_JSON = v1_job_status_convertToJSON(v1_job->status);
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

v1_job_t *v1_job_parseFromJSON(cJSON *v1_jobJSON){

    v1_job_t *v1_job_local_var = NULL;

    // v1_job->apiVersion
    cJSON *apiVersion = cJSON_GetObjectItemCaseSensitive(v1_jobJSON, "apiVersion");
    if (apiVersion) { 
    if(!cJSON_IsString(apiVersion))
    {
    goto end; //String
    }
    }

    // v1_job->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_jobJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1_job->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1_jobJSON, "metadata");
    v1_object_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1_job->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(v1_jobJSON, "spec");
    v1_job_spec_t *spec_local_nonprim = NULL;
    if (spec) { 
    spec_local_nonprim = v1_job_spec_parseFromJSON(spec); //nonprimitive
    }

    // v1_job->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(v1_jobJSON, "status");
    v1_job_status_t *status_local_nonprim = NULL;
    if (status) { 
    status_local_nonprim = v1_job_status_parseFromJSON(status); //nonprimitive
    }


    v1_job_local_var = v1_job_create (
        apiVersion ? strdup(apiVersion->valuestring) : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        spec ? spec_local_nonprim : NULL,
        status ? status_local_nonprim : NULL
        );

    return v1_job_local_var;
end:
    return NULL;

}
