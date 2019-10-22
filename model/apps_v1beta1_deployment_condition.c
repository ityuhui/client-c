#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "apps_v1beta1_deployment_condition.h"



apps_v1beta1_deployment_condition_t *apps_v1beta1_deployment_condition_create(
    char *lastTransitionTime,
    char *lastUpdateTime,
    char *message,
    char *reason,
    char *status,
    char *type
    ) {
	apps_v1beta1_deployment_condition_t *apps_v1beta1_deployment_condition_local_var = malloc(sizeof(apps_v1beta1_deployment_condition_t));
    if (!apps_v1beta1_deployment_condition_local_var) {
        return NULL;
    }
	apps_v1beta1_deployment_condition_local_var->lastTransitionTime = lastTransitionTime;
	apps_v1beta1_deployment_condition_local_var->lastUpdateTime = lastUpdateTime;
	apps_v1beta1_deployment_condition_local_var->message = message;
	apps_v1beta1_deployment_condition_local_var->reason = reason;
	apps_v1beta1_deployment_condition_local_var->status = status;
	apps_v1beta1_deployment_condition_local_var->type = type;

	return apps_v1beta1_deployment_condition_local_var;
}


void apps_v1beta1_deployment_condition_free(apps_v1beta1_deployment_condition_t *apps_v1beta1_deployment_condition) {
    listEntry_t *listEntry;
    free(apps_v1beta1_deployment_condition->lastTransitionTime);
    free(apps_v1beta1_deployment_condition->lastUpdateTime);
    free(apps_v1beta1_deployment_condition->message);
    free(apps_v1beta1_deployment_condition->reason);
    free(apps_v1beta1_deployment_condition->status);
    free(apps_v1beta1_deployment_condition->type);
	free(apps_v1beta1_deployment_condition);
}

cJSON *apps_v1beta1_deployment_condition_convertToJSON(apps_v1beta1_deployment_condition_t *apps_v1beta1_deployment_condition) {
	cJSON *item = cJSON_CreateObject();

	// apps_v1beta1_deployment_condition->lastTransitionTime
    if(apps_v1beta1_deployment_condition->lastTransitionTime) { 
    if(cJSON_AddStringToObject(item, "lastTransitionTime", apps_v1beta1_deployment_condition->lastTransitionTime) == NULL) {
    goto fail; //Date-Time
    }
     } 


	// apps_v1beta1_deployment_condition->lastUpdateTime
    if(apps_v1beta1_deployment_condition->lastUpdateTime) { 
    if(cJSON_AddStringToObject(item, "lastUpdateTime", apps_v1beta1_deployment_condition->lastUpdateTime) == NULL) {
    goto fail; //Date-Time
    }
     } 


	// apps_v1beta1_deployment_condition->message
    if(apps_v1beta1_deployment_condition->message) { 
    if(cJSON_AddStringToObject(item, "message", apps_v1beta1_deployment_condition->message) == NULL) {
    goto fail; //String
    }
     } 


	// apps_v1beta1_deployment_condition->reason
    if(apps_v1beta1_deployment_condition->reason) { 
    if(cJSON_AddStringToObject(item, "reason", apps_v1beta1_deployment_condition->reason) == NULL) {
    goto fail; //String
    }
     } 


	// apps_v1beta1_deployment_condition->status
    if (!apps_v1beta1_deployment_condition->status) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "status", apps_v1beta1_deployment_condition->status) == NULL) {
    goto fail; //String
    }


	// apps_v1beta1_deployment_condition->type
    if (!apps_v1beta1_deployment_condition->type) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "type", apps_v1beta1_deployment_condition->type) == NULL) {
    goto fail; //String
    }

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

apps_v1beta1_deployment_condition_t *apps_v1beta1_deployment_condition_parseFromJSON(cJSON *apps_v1beta1_deployment_conditionJSON){

    apps_v1beta1_deployment_condition_t *apps_v1beta1_deployment_condition_local_var = NULL;

    // apps_v1beta1_deployment_condition->lastTransitionTime
    cJSON *lastTransitionTime = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_deployment_conditionJSON, "lastTransitionTime");
    if (lastTransitionTime) { 
    if(!cJSON_IsString(lastTransitionTime))
    {
    goto end; //DateTime
    }
    }

    // apps_v1beta1_deployment_condition->lastUpdateTime
    cJSON *lastUpdateTime = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_deployment_conditionJSON, "lastUpdateTime");
    if (lastUpdateTime) { 
    if(!cJSON_IsString(lastUpdateTime))
    {
    goto end; //DateTime
    }
    }

    // apps_v1beta1_deployment_condition->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_deployment_conditionJSON, "message");
    if (message) { 
    if(!cJSON_IsString(message))
    {
    goto end; //String
    }
    }

    // apps_v1beta1_deployment_condition->reason
    cJSON *reason = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_deployment_conditionJSON, "reason");
    if (reason) { 
    if(!cJSON_IsString(reason))
    {
    goto end; //String
    }
    }

    // apps_v1beta1_deployment_condition->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_deployment_conditionJSON, "status");
    if (!status) {
        goto end;
    }

    
    if(!cJSON_IsString(status))
    {
    goto end; //String
    }

    // apps_v1beta1_deployment_condition->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_deployment_conditionJSON, "type");
    if (!type) {
        goto end;
    }

    
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }


    apps_v1beta1_deployment_condition_local_var = apps_v1beta1_deployment_condition_create (
        lastTransitionTime ? strdup(lastTransitionTime->valuestring) : NULL,
        lastUpdateTime ? strdup(lastUpdateTime->valuestring) : NULL,
        message ? strdup(message->valuestring) : NULL,
        reason ? strdup(reason->valuestring) : NULL,
        strdup(status->valuestring),
        strdup(type->valuestring)
        );

    return apps_v1beta1_deployment_condition_local_var;
end:
    return NULL;

}
