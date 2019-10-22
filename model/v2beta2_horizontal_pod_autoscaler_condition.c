#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v2beta2_horizontal_pod_autoscaler_condition.h"



v2beta2_horizontal_pod_autoscaler_condition_t *v2beta2_horizontal_pod_autoscaler_condition_create(
    char *lastTransitionTime,
    char *message,
    char *reason,
    char *status,
    char *type
    ) {
	v2beta2_horizontal_pod_autoscaler_condition_t *v2beta2_horizontal_pod_autoscaler_condition_local_var = malloc(sizeof(v2beta2_horizontal_pod_autoscaler_condition_t));
    if (!v2beta2_horizontal_pod_autoscaler_condition_local_var) {
        return NULL;
    }
	v2beta2_horizontal_pod_autoscaler_condition_local_var->lastTransitionTime = lastTransitionTime;
	v2beta2_horizontal_pod_autoscaler_condition_local_var->message = message;
	v2beta2_horizontal_pod_autoscaler_condition_local_var->reason = reason;
	v2beta2_horizontal_pod_autoscaler_condition_local_var->status = status;
	v2beta2_horizontal_pod_autoscaler_condition_local_var->type = type;

	return v2beta2_horizontal_pod_autoscaler_condition_local_var;
}


void v2beta2_horizontal_pod_autoscaler_condition_free(v2beta2_horizontal_pod_autoscaler_condition_t *v2beta2_horizontal_pod_autoscaler_condition) {
    listEntry_t *listEntry;
    free(v2beta2_horizontal_pod_autoscaler_condition->lastTransitionTime);
    free(v2beta2_horizontal_pod_autoscaler_condition->message);
    free(v2beta2_horizontal_pod_autoscaler_condition->reason);
    free(v2beta2_horizontal_pod_autoscaler_condition->status);
    free(v2beta2_horizontal_pod_autoscaler_condition->type);
	free(v2beta2_horizontal_pod_autoscaler_condition);
}

cJSON *v2beta2_horizontal_pod_autoscaler_condition_convertToJSON(v2beta2_horizontal_pod_autoscaler_condition_t *v2beta2_horizontal_pod_autoscaler_condition) {
	cJSON *item = cJSON_CreateObject();

	// v2beta2_horizontal_pod_autoscaler_condition->lastTransitionTime
    if(v2beta2_horizontal_pod_autoscaler_condition->lastTransitionTime) { 
    if(cJSON_AddStringToObject(item, "lastTransitionTime", v2beta2_horizontal_pod_autoscaler_condition->lastTransitionTime) == NULL) {
    goto fail; //Date-Time
    }
     } 


	// v2beta2_horizontal_pod_autoscaler_condition->message
    if(v2beta2_horizontal_pod_autoscaler_condition->message) { 
    if(cJSON_AddStringToObject(item, "message", v2beta2_horizontal_pod_autoscaler_condition->message) == NULL) {
    goto fail; //String
    }
     } 


	// v2beta2_horizontal_pod_autoscaler_condition->reason
    if(v2beta2_horizontal_pod_autoscaler_condition->reason) { 
    if(cJSON_AddStringToObject(item, "reason", v2beta2_horizontal_pod_autoscaler_condition->reason) == NULL) {
    goto fail; //String
    }
     } 


	// v2beta2_horizontal_pod_autoscaler_condition->status
    if (!v2beta2_horizontal_pod_autoscaler_condition->status) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "status", v2beta2_horizontal_pod_autoscaler_condition->status) == NULL) {
    goto fail; //String
    }


	// v2beta2_horizontal_pod_autoscaler_condition->type
    if (!v2beta2_horizontal_pod_autoscaler_condition->type) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "type", v2beta2_horizontal_pod_autoscaler_condition->type) == NULL) {
    goto fail; //String
    }

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v2beta2_horizontal_pod_autoscaler_condition_t *v2beta2_horizontal_pod_autoscaler_condition_parseFromJSON(cJSON *v2beta2_horizontal_pod_autoscaler_conditionJSON){

    v2beta2_horizontal_pod_autoscaler_condition_t *v2beta2_horizontal_pod_autoscaler_condition_local_var = NULL;

    // v2beta2_horizontal_pod_autoscaler_condition->lastTransitionTime
    cJSON *lastTransitionTime = cJSON_GetObjectItemCaseSensitive(v2beta2_horizontal_pod_autoscaler_conditionJSON, "lastTransitionTime");
    if (lastTransitionTime) { 
    if(!cJSON_IsString(lastTransitionTime))
    {
    goto end; //DateTime
    }
    }

    // v2beta2_horizontal_pod_autoscaler_condition->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(v2beta2_horizontal_pod_autoscaler_conditionJSON, "message");
    if (message) { 
    if(!cJSON_IsString(message))
    {
    goto end; //String
    }
    }

    // v2beta2_horizontal_pod_autoscaler_condition->reason
    cJSON *reason = cJSON_GetObjectItemCaseSensitive(v2beta2_horizontal_pod_autoscaler_conditionJSON, "reason");
    if (reason) { 
    if(!cJSON_IsString(reason))
    {
    goto end; //String
    }
    }

    // v2beta2_horizontal_pod_autoscaler_condition->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(v2beta2_horizontal_pod_autoscaler_conditionJSON, "status");
    if (!status) {
        goto end;
    }

    
    if(!cJSON_IsString(status))
    {
    goto end; //String
    }

    // v2beta2_horizontal_pod_autoscaler_condition->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(v2beta2_horizontal_pod_autoscaler_conditionJSON, "type");
    if (!type) {
        goto end;
    }

    
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }


    v2beta2_horizontal_pod_autoscaler_condition_local_var = v2beta2_horizontal_pod_autoscaler_condition_create (
        lastTransitionTime ? strdup(lastTransitionTime->valuestring) : NULL,
        message ? strdup(message->valuestring) : NULL,
        reason ? strdup(reason->valuestring) : NULL,
        strdup(status->valuestring),
        strdup(type->valuestring)
        );

    return v2beta2_horizontal_pod_autoscaler_condition_local_var;
end:
    return NULL;

}
