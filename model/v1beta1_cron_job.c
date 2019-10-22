#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_cron_job.h"



v1beta1_cron_job_t *v1beta1_cron_job_create(
    char *apiVersion,
    char *kind,
    v1_object_meta_t *metadata,
    v1beta1_cron_job_spec_t *spec,
    v1beta1_cron_job_status_t *status
    ) {
	v1beta1_cron_job_t *v1beta1_cron_job_local_var = malloc(sizeof(v1beta1_cron_job_t));
    if (!v1beta1_cron_job_local_var) {
        return NULL;
    }
	v1beta1_cron_job_local_var->apiVersion = apiVersion;
	v1beta1_cron_job_local_var->kind = kind;
	v1beta1_cron_job_local_var->metadata = metadata;
	v1beta1_cron_job_local_var->spec = spec;
	v1beta1_cron_job_local_var->status = status;

	return v1beta1_cron_job_local_var;
}


void v1beta1_cron_job_free(v1beta1_cron_job_t *v1beta1_cron_job) {
    listEntry_t *listEntry;
    free(v1beta1_cron_job->apiVersion);
    free(v1beta1_cron_job->kind);
    v1_object_meta_free(v1beta1_cron_job->metadata);
    v1beta1_cron_job_spec_free(v1beta1_cron_job->spec);
    v1beta1_cron_job_status_free(v1beta1_cron_job->status);
	free(v1beta1_cron_job);
}

cJSON *v1beta1_cron_job_convertToJSON(v1beta1_cron_job_t *v1beta1_cron_job) {
	cJSON *item = cJSON_CreateObject();

	// v1beta1_cron_job->apiVersion
    if(v1beta1_cron_job->apiVersion) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1beta1_cron_job->apiVersion) == NULL) {
    goto fail; //String
    }
     } 


	// v1beta1_cron_job->kind
    if(v1beta1_cron_job->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1beta1_cron_job->kind) == NULL) {
    goto fail; //String
    }
     } 


	// v1beta1_cron_job->metadata
    if(v1beta1_cron_job->metadata) { 
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1beta1_cron_job->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1beta1_cron_job->spec
    if(v1beta1_cron_job->spec) { 
    cJSON *spec_local_JSON = v1beta1_cron_job_spec_convertToJSON(v1beta1_cron_job->spec);
    if(spec_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "spec", spec_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1beta1_cron_job->status
    if(v1beta1_cron_job->status) { 
    cJSON *status_local_JSON = v1beta1_cron_job_status_convertToJSON(v1beta1_cron_job->status);
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

v1beta1_cron_job_t *v1beta1_cron_job_parseFromJSON(cJSON *v1beta1_cron_jobJSON){

    v1beta1_cron_job_t *v1beta1_cron_job_local_var = NULL;

    // v1beta1_cron_job->apiVersion
    cJSON *apiVersion = cJSON_GetObjectItemCaseSensitive(v1beta1_cron_jobJSON, "apiVersion");
    if (apiVersion) { 
    if(!cJSON_IsString(apiVersion))
    {
    goto end; //String
    }
    }

    // v1beta1_cron_job->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1beta1_cron_jobJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1beta1_cron_job->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1beta1_cron_jobJSON, "metadata");
    v1_object_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1beta1_cron_job->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(v1beta1_cron_jobJSON, "spec");
    v1beta1_cron_job_spec_t *spec_local_nonprim = NULL;
    if (spec) { 
    spec_local_nonprim = v1beta1_cron_job_spec_parseFromJSON(spec); //nonprimitive
    }

    // v1beta1_cron_job->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(v1beta1_cron_jobJSON, "status");
    v1beta1_cron_job_status_t *status_local_nonprim = NULL;
    if (status) { 
    status_local_nonprim = v1beta1_cron_job_status_parseFromJSON(status); //nonprimitive
    }


    v1beta1_cron_job_local_var = v1beta1_cron_job_create (
        apiVersion ? strdup(apiVersion->valuestring) : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        spec ? spec_local_nonprim : NULL,
        status ? status_local_nonprim : NULL
        );

    return v1beta1_cron_job_local_var;
end:
    return NULL;

}
