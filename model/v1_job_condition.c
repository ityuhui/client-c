#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_job_condition.h"



v1_job_condition_t *v1_job_condition_create(
    char *lastProbeTime,
    char *lastTransitionTime,
    char *message,
    char *reason,
    char *status,
    char *type
    ) {
	v1_job_condition_t *v1_job_condition_local_var = malloc(sizeof(v1_job_condition_t));
    if (!v1_job_condition_local_var) {
        return NULL;
    }
	v1_job_condition_local_var->lastProbeTime = lastProbeTime;
	v1_job_condition_local_var->lastTransitionTime = lastTransitionTime;
	v1_job_condition_local_var->message = message;
	v1_job_condition_local_var->reason = reason;
	v1_job_condition_local_var->status = status;
	v1_job_condition_local_var->type = type;

	return v1_job_condition_local_var;
}


void v1_job_condition_free(v1_job_condition_t *v1_job_condition) {
    listEntry_t *listEntry;
    free(v1_job_condition->lastProbeTime);
    free(v1_job_condition->lastTransitionTime);
    free(v1_job_condition->message);
    free(v1_job_condition->reason);
    free(v1_job_condition->status);
    free(v1_job_condition->type);
	free(v1_job_condition);
}

cJSON *v1_job_condition_convertToJSON(v1_job_condition_t *v1_job_condition) {
	cJSON *item = cJSON_CreateObject();

	// v1_job_condition->lastProbeTime
    if(v1_job_condition->lastProbeTime) { 
    if(cJSON_AddStringToObject(item, "lastProbeTime", v1_job_condition->lastProbeTime) == NULL) {
    goto fail; //Date-Time
    }
     } 


	// v1_job_condition->lastTransitionTime
    if(v1_job_condition->lastTransitionTime) { 
    if(cJSON_AddStringToObject(item, "lastTransitionTime", v1_job_condition->lastTransitionTime) == NULL) {
    goto fail; //Date-Time
    }
     } 


	// v1_job_condition->message
    if(v1_job_condition->message) { 
    if(cJSON_AddStringToObject(item, "message", v1_job_condition->message) == NULL) {
    goto fail; //String
    }
     } 


	// v1_job_condition->reason
    if(v1_job_condition->reason) { 
    if(cJSON_AddStringToObject(item, "reason", v1_job_condition->reason) == NULL) {
    goto fail; //String
    }
     } 


	// v1_job_condition->status
    if (!v1_job_condition->status) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "status", v1_job_condition->status) == NULL) {
    goto fail; //String
    }


	// v1_job_condition->type
    if (!v1_job_condition->type) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "type", v1_job_condition->type) == NULL) {
    goto fail; //String
    }

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1_job_condition_t *v1_job_condition_parseFromJSON(cJSON *v1_job_conditionJSON){

    v1_job_condition_t *v1_job_condition_local_var = NULL;

    // v1_job_condition->lastProbeTime
    cJSON *lastProbeTime = cJSON_GetObjectItemCaseSensitive(v1_job_conditionJSON, "lastProbeTime");
    if (lastProbeTime) { 
    if(!cJSON_IsString(lastProbeTime))
    {
    goto end; //DateTime
    }
    }

    // v1_job_condition->lastTransitionTime
    cJSON *lastTransitionTime = cJSON_GetObjectItemCaseSensitive(v1_job_conditionJSON, "lastTransitionTime");
    if (lastTransitionTime) { 
    if(!cJSON_IsString(lastTransitionTime))
    {
    goto end; //DateTime
    }
    }

    // v1_job_condition->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(v1_job_conditionJSON, "message");
    if (message) { 
    if(!cJSON_IsString(message))
    {
    goto end; //String
    }
    }

    // v1_job_condition->reason
    cJSON *reason = cJSON_GetObjectItemCaseSensitive(v1_job_conditionJSON, "reason");
    if (reason) { 
    if(!cJSON_IsString(reason))
    {
    goto end; //String
    }
    }

    // v1_job_condition->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(v1_job_conditionJSON, "status");
    if (!status) {
        goto end;
    }

    
    if(!cJSON_IsString(status))
    {
    goto end; //String
    }

    // v1_job_condition->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(v1_job_conditionJSON, "type");
    if (!type) {
        goto end;
    }

    
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }


    v1_job_condition_local_var = v1_job_condition_create (
        lastProbeTime ? strdup(lastProbeTime->valuestring) : NULL,
        lastTransitionTime ? strdup(lastTransitionTime->valuestring) : NULL,
        message ? strdup(message->valuestring) : NULL,
        reason ? strdup(reason->valuestring) : NULL,
        strdup(status->valuestring),
        strdup(type->valuestring)
        );

    return v1_job_condition_local_var;
end:
    return NULL;

}
