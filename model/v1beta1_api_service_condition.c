#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_api_service_condition.h"



v1beta1_api_service_condition_t *v1beta1_api_service_condition_create(
    char *lastTransitionTime,
    char *message,
    char *reason,
    char *status,
    char *type
    ) {
	v1beta1_api_service_condition_t *v1beta1_api_service_condition_local_var = malloc(sizeof(v1beta1_api_service_condition_t));
    if (!v1beta1_api_service_condition_local_var) {
        return NULL;
    }
	v1beta1_api_service_condition_local_var->lastTransitionTime = lastTransitionTime;
	v1beta1_api_service_condition_local_var->message = message;
	v1beta1_api_service_condition_local_var->reason = reason;
	v1beta1_api_service_condition_local_var->status = status;
	v1beta1_api_service_condition_local_var->type = type;

	return v1beta1_api_service_condition_local_var;
}


void v1beta1_api_service_condition_free(v1beta1_api_service_condition_t *v1beta1_api_service_condition) {
    listEntry_t *listEntry;
    free(v1beta1_api_service_condition->lastTransitionTime);
    free(v1beta1_api_service_condition->message);
    free(v1beta1_api_service_condition->reason);
    free(v1beta1_api_service_condition->status);
    free(v1beta1_api_service_condition->type);
	free(v1beta1_api_service_condition);
}

cJSON *v1beta1_api_service_condition_convertToJSON(v1beta1_api_service_condition_t *v1beta1_api_service_condition) {
	cJSON *item = cJSON_CreateObject();

	// v1beta1_api_service_condition->lastTransitionTime
    if(v1beta1_api_service_condition->lastTransitionTime) { 
    if(cJSON_AddStringToObject(item, "lastTransitionTime", v1beta1_api_service_condition->lastTransitionTime) == NULL) {
    goto fail; //Date-Time
    }
     } 


	// v1beta1_api_service_condition->message
    if(v1beta1_api_service_condition->message) { 
    if(cJSON_AddStringToObject(item, "message", v1beta1_api_service_condition->message) == NULL) {
    goto fail; //String
    }
     } 


	// v1beta1_api_service_condition->reason
    if(v1beta1_api_service_condition->reason) { 
    if(cJSON_AddStringToObject(item, "reason", v1beta1_api_service_condition->reason) == NULL) {
    goto fail; //String
    }
     } 


	// v1beta1_api_service_condition->status
    if (!v1beta1_api_service_condition->status) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "status", v1beta1_api_service_condition->status) == NULL) {
    goto fail; //String
    }


	// v1beta1_api_service_condition->type
    if (!v1beta1_api_service_condition->type) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "type", v1beta1_api_service_condition->type) == NULL) {
    goto fail; //String
    }

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1beta1_api_service_condition_t *v1beta1_api_service_condition_parseFromJSON(cJSON *v1beta1_api_service_conditionJSON){

    v1beta1_api_service_condition_t *v1beta1_api_service_condition_local_var = NULL;

    // v1beta1_api_service_condition->lastTransitionTime
    cJSON *lastTransitionTime = cJSON_GetObjectItemCaseSensitive(v1beta1_api_service_conditionJSON, "lastTransitionTime");
    if (lastTransitionTime) { 
    if(!cJSON_IsString(lastTransitionTime))
    {
    goto end; //DateTime
    }
    }

    // v1beta1_api_service_condition->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(v1beta1_api_service_conditionJSON, "message");
    if (message) { 
    if(!cJSON_IsString(message))
    {
    goto end; //String
    }
    }

    // v1beta1_api_service_condition->reason
    cJSON *reason = cJSON_GetObjectItemCaseSensitive(v1beta1_api_service_conditionJSON, "reason");
    if (reason) { 
    if(!cJSON_IsString(reason))
    {
    goto end; //String
    }
    }

    // v1beta1_api_service_condition->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(v1beta1_api_service_conditionJSON, "status");
    if (!status) {
        goto end;
    }

    
    if(!cJSON_IsString(status))
    {
    goto end; //String
    }

    // v1beta1_api_service_condition->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(v1beta1_api_service_conditionJSON, "type");
    if (!type) {
        goto end;
    }

    
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }


    v1beta1_api_service_condition_local_var = v1beta1_api_service_condition_create (
        lastTransitionTime ? strdup(lastTransitionTime->valuestring) : NULL,
        message ? strdup(message->valuestring) : NULL,
        reason ? strdup(reason->valuestring) : NULL,
        strdup(status->valuestring),
        strdup(type->valuestring)
        );

    return v1beta1_api_service_condition_local_var;
end:
    return NULL;

}
