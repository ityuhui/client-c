#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v2alpha1_cron_job.h"



v2alpha1_cron_job_t *v2alpha1_cron_job_create(
    char *apiVersion,
    char *kind,
    v1_object_meta_t *metadata,
    v2alpha1_cron_job_spec_t *spec,
    v2alpha1_cron_job_status_t *status
    ) {
	v2alpha1_cron_job_t *v2alpha1_cron_job_local_var = malloc(sizeof(v2alpha1_cron_job_t));
    if (!v2alpha1_cron_job_local_var) {
        return NULL;
    }
	v2alpha1_cron_job_local_var->apiVersion = apiVersion;
	v2alpha1_cron_job_local_var->kind = kind;
	v2alpha1_cron_job_local_var->metadata = metadata;
	v2alpha1_cron_job_local_var->spec = spec;
	v2alpha1_cron_job_local_var->status = status;

	return v2alpha1_cron_job_local_var;
}


void v2alpha1_cron_job_free(v2alpha1_cron_job_t *v2alpha1_cron_job) {
    listEntry_t *listEntry;
    free(v2alpha1_cron_job->apiVersion);
    free(v2alpha1_cron_job->kind);
    v1_object_meta_free(v2alpha1_cron_job->metadata);
    v2alpha1_cron_job_spec_free(v2alpha1_cron_job->spec);
    v2alpha1_cron_job_status_free(v2alpha1_cron_job->status);
	free(v2alpha1_cron_job);
}

cJSON *v2alpha1_cron_job_convertToJSON(v2alpha1_cron_job_t *v2alpha1_cron_job) {
	cJSON *item = cJSON_CreateObject();

	// v2alpha1_cron_job->apiVersion
    if(v2alpha1_cron_job->apiVersion) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v2alpha1_cron_job->apiVersion) == NULL) {
    goto fail; //String
    }
     } 


	// v2alpha1_cron_job->kind
    if(v2alpha1_cron_job->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v2alpha1_cron_job->kind) == NULL) {
    goto fail; //String
    }
     } 


	// v2alpha1_cron_job->metadata
    if(v2alpha1_cron_job->metadata) { 
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v2alpha1_cron_job->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v2alpha1_cron_job->spec
    if(v2alpha1_cron_job->spec) { 
    cJSON *spec_local_JSON = v2alpha1_cron_job_spec_convertToJSON(v2alpha1_cron_job->spec);
    if(spec_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "spec", spec_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v2alpha1_cron_job->status
    if(v2alpha1_cron_job->status) { 
    cJSON *status_local_JSON = v2alpha1_cron_job_status_convertToJSON(v2alpha1_cron_job->status);
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

v2alpha1_cron_job_t *v2alpha1_cron_job_parseFromJSON(cJSON *v2alpha1_cron_jobJSON){

    v2alpha1_cron_job_t *v2alpha1_cron_job_local_var = NULL;

    // v2alpha1_cron_job->apiVersion
    cJSON *apiVersion = cJSON_GetObjectItemCaseSensitive(v2alpha1_cron_jobJSON, "apiVersion");
    if (apiVersion) { 
    if(!cJSON_IsString(apiVersion))
    {
    goto end; //String
    }
    }

    // v2alpha1_cron_job->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v2alpha1_cron_jobJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v2alpha1_cron_job->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v2alpha1_cron_jobJSON, "metadata");
    v1_object_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v2alpha1_cron_job->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(v2alpha1_cron_jobJSON, "spec");
    v2alpha1_cron_job_spec_t *spec_local_nonprim = NULL;
    if (spec) { 
    spec_local_nonprim = v2alpha1_cron_job_spec_parseFromJSON(spec); //nonprimitive
    }

    // v2alpha1_cron_job->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(v2alpha1_cron_jobJSON, "status");
    v2alpha1_cron_job_status_t *status_local_nonprim = NULL;
    if (status) { 
    status_local_nonprim = v2alpha1_cron_job_status_parseFromJSON(status); //nonprimitive
    }


    v2alpha1_cron_job_local_var = v2alpha1_cron_job_create (
        apiVersion ? strdup(apiVersion->valuestring) : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        spec ? spec_local_nonprim : NULL,
        status ? status_local_nonprim : NULL
        );

    return v2alpha1_cron_job_local_var;
end:
    return NULL;

}
