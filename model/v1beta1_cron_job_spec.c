#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_cron_job_spec.h"



v1beta1_cron_job_spec_t *v1beta1_cron_job_spec_create(
    char *concurrencyPolicy,
    int failedJobsHistoryLimit,
    v1beta1_job_template_spec_t *jobTemplate,
    char *schedule,
    long startingDeadlineSeconds,
    int successfulJobsHistoryLimit,
    int suspend
    ) {
	v1beta1_cron_job_spec_t *v1beta1_cron_job_spec_local_var = malloc(sizeof(v1beta1_cron_job_spec_t));
    if (!v1beta1_cron_job_spec_local_var) {
        return NULL;
    }
	v1beta1_cron_job_spec_local_var->concurrencyPolicy = concurrencyPolicy;
	v1beta1_cron_job_spec_local_var->failedJobsHistoryLimit = failedJobsHistoryLimit;
	v1beta1_cron_job_spec_local_var->jobTemplate = jobTemplate;
	v1beta1_cron_job_spec_local_var->schedule = schedule;
	v1beta1_cron_job_spec_local_var->startingDeadlineSeconds = startingDeadlineSeconds;
	v1beta1_cron_job_spec_local_var->successfulJobsHistoryLimit = successfulJobsHistoryLimit;
	v1beta1_cron_job_spec_local_var->suspend = suspend;

	return v1beta1_cron_job_spec_local_var;
}


void v1beta1_cron_job_spec_free(v1beta1_cron_job_spec_t *v1beta1_cron_job_spec) {
    listEntry_t *listEntry;
    free(v1beta1_cron_job_spec->concurrencyPolicy);
    v1beta1_job_template_spec_free(v1beta1_cron_job_spec->jobTemplate);
    free(v1beta1_cron_job_spec->schedule);
	free(v1beta1_cron_job_spec);
}

cJSON *v1beta1_cron_job_spec_convertToJSON(v1beta1_cron_job_spec_t *v1beta1_cron_job_spec) {
	cJSON *item = cJSON_CreateObject();

	// v1beta1_cron_job_spec->concurrencyPolicy
    if(v1beta1_cron_job_spec->concurrencyPolicy) { 
    if(cJSON_AddStringToObject(item, "concurrencyPolicy", v1beta1_cron_job_spec->concurrencyPolicy) == NULL) {
    goto fail; //String
    }
     } 


	// v1beta1_cron_job_spec->failedJobsHistoryLimit
    if(v1beta1_cron_job_spec->failedJobsHistoryLimit) { 
    if(cJSON_AddNumberToObject(item, "failedJobsHistoryLimit", v1beta1_cron_job_spec->failedJobsHistoryLimit) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1beta1_cron_job_spec->jobTemplate
    if (!v1beta1_cron_job_spec->jobTemplate) {
        goto fail;
    }
    
    cJSON *jobTemplate_local_JSON = v1beta1_job_template_spec_convertToJSON(v1beta1_cron_job_spec->jobTemplate);
    if(jobTemplate_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "jobTemplate", jobTemplate_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


	// v1beta1_cron_job_spec->schedule
    if (!v1beta1_cron_job_spec->schedule) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "schedule", v1beta1_cron_job_spec->schedule) == NULL) {
    goto fail; //String
    }


	// v1beta1_cron_job_spec->startingDeadlineSeconds
    if(v1beta1_cron_job_spec->startingDeadlineSeconds) { 
    if(cJSON_AddNumberToObject(item, "startingDeadlineSeconds", v1beta1_cron_job_spec->startingDeadlineSeconds) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1beta1_cron_job_spec->successfulJobsHistoryLimit
    if(v1beta1_cron_job_spec->successfulJobsHistoryLimit) { 
    if(cJSON_AddNumberToObject(item, "successfulJobsHistoryLimit", v1beta1_cron_job_spec->successfulJobsHistoryLimit) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1beta1_cron_job_spec->suspend
    if(v1beta1_cron_job_spec->suspend) { 
    if(cJSON_AddBoolToObject(item, "suspend", v1beta1_cron_job_spec->suspend) == NULL) {
    goto fail; //Bool
    }
     } 

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1beta1_cron_job_spec_t *v1beta1_cron_job_spec_parseFromJSON(cJSON *v1beta1_cron_job_specJSON){

    v1beta1_cron_job_spec_t *v1beta1_cron_job_spec_local_var = NULL;

    // v1beta1_cron_job_spec->concurrencyPolicy
    cJSON *concurrencyPolicy = cJSON_GetObjectItemCaseSensitive(v1beta1_cron_job_specJSON, "concurrencyPolicy");
    if (concurrencyPolicy) { 
    if(!cJSON_IsString(concurrencyPolicy))
    {
    goto end; //String
    }
    }

    // v1beta1_cron_job_spec->failedJobsHistoryLimit
    cJSON *failedJobsHistoryLimit = cJSON_GetObjectItemCaseSensitive(v1beta1_cron_job_specJSON, "failedJobsHistoryLimit");
    if (failedJobsHistoryLimit) { 
    if(!cJSON_IsNumber(failedJobsHistoryLimit))
    {
    goto end; //Numeric
    }
    }

    // v1beta1_cron_job_spec->jobTemplate
    cJSON *jobTemplate = cJSON_GetObjectItemCaseSensitive(v1beta1_cron_job_specJSON, "jobTemplate");
    if (!jobTemplate) {
        goto end;
    }

    v1beta1_job_template_spec_t *jobTemplate_local_nonprim = NULL;
    
    jobTemplate_local_nonprim = v1beta1_job_template_spec_parseFromJSON(jobTemplate); //nonprimitive

    // v1beta1_cron_job_spec->schedule
    cJSON *schedule = cJSON_GetObjectItemCaseSensitive(v1beta1_cron_job_specJSON, "schedule");
    if (!schedule) {
        goto end;
    }

    
    if(!cJSON_IsString(schedule))
    {
    goto end; //String
    }

    // v1beta1_cron_job_spec->startingDeadlineSeconds
    cJSON *startingDeadlineSeconds = cJSON_GetObjectItemCaseSensitive(v1beta1_cron_job_specJSON, "startingDeadlineSeconds");
    if (startingDeadlineSeconds) { 
    if(!cJSON_IsNumber(startingDeadlineSeconds))
    {
    goto end; //Numeric
    }
    }

    // v1beta1_cron_job_spec->successfulJobsHistoryLimit
    cJSON *successfulJobsHistoryLimit = cJSON_GetObjectItemCaseSensitive(v1beta1_cron_job_specJSON, "successfulJobsHistoryLimit");
    if (successfulJobsHistoryLimit) { 
    if(!cJSON_IsNumber(successfulJobsHistoryLimit))
    {
    goto end; //Numeric
    }
    }

    // v1beta1_cron_job_spec->suspend
    cJSON *suspend = cJSON_GetObjectItemCaseSensitive(v1beta1_cron_job_specJSON, "suspend");
    if (suspend) { 
    if(!cJSON_IsBool(suspend))
    {
    goto end; //Bool
    }
    }


    v1beta1_cron_job_spec_local_var = v1beta1_cron_job_spec_create (
        concurrencyPolicy ? strdup(concurrencyPolicy->valuestring) : NULL,
        failedJobsHistoryLimit ? failedJobsHistoryLimit->valuedouble : 0,
        jobTemplate_local_nonprim,
        strdup(schedule->valuestring),
        startingDeadlineSeconds ? startingDeadlineSeconds->valuedouble : 0,
        successfulJobsHistoryLimit ? successfulJobsHistoryLimit->valuedouble : 0,
        suspend ? suspend->valueint : 0
        );

    return v1beta1_cron_job_spec_local_var;
end:
    return NULL;

}
