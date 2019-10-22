#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "extensions_v1beta1_deployment_condition.h"



extensions_v1beta1_deployment_condition_t *extensions_v1beta1_deployment_condition_create(
    char *lastTransitionTime,
    char *lastUpdateTime,
    char *message,
    char *reason,
    char *status,
    char *type
    ) {
	extensions_v1beta1_deployment_condition_t *extensions_v1beta1_deployment_condition_local_var = malloc(sizeof(extensions_v1beta1_deployment_condition_t));
    if (!extensions_v1beta1_deployment_condition_local_var) {
        return NULL;
    }
	extensions_v1beta1_deployment_condition_local_var->lastTransitionTime = lastTransitionTime;
	extensions_v1beta1_deployment_condition_local_var->lastUpdateTime = lastUpdateTime;
	extensions_v1beta1_deployment_condition_local_var->message = message;
	extensions_v1beta1_deployment_condition_local_var->reason = reason;
	extensions_v1beta1_deployment_condition_local_var->status = status;
	extensions_v1beta1_deployment_condition_local_var->type = type;

	return extensions_v1beta1_deployment_condition_local_var;
}


void extensions_v1beta1_deployment_condition_free(extensions_v1beta1_deployment_condition_t *extensions_v1beta1_deployment_condition) {
    listEntry_t *listEntry;
    free(extensions_v1beta1_deployment_condition->lastTransitionTime);
    free(extensions_v1beta1_deployment_condition->lastUpdateTime);
    free(extensions_v1beta1_deployment_condition->message);
    free(extensions_v1beta1_deployment_condition->reason);
    free(extensions_v1beta1_deployment_condition->status);
    free(extensions_v1beta1_deployment_condition->type);
	free(extensions_v1beta1_deployment_condition);
}

cJSON *extensions_v1beta1_deployment_condition_convertToJSON(extensions_v1beta1_deployment_condition_t *extensions_v1beta1_deployment_condition) {
	cJSON *item = cJSON_CreateObject();

	// extensions_v1beta1_deployment_condition->lastTransitionTime
    if(extensions_v1beta1_deployment_condition->lastTransitionTime) { 
    if(cJSON_AddStringToObject(item, "lastTransitionTime", extensions_v1beta1_deployment_condition->lastTransitionTime) == NULL) {
    goto fail; //Date-Time
    }
     } 


	// extensions_v1beta1_deployment_condition->lastUpdateTime
    if(extensions_v1beta1_deployment_condition->lastUpdateTime) { 
    if(cJSON_AddStringToObject(item, "lastUpdateTime", extensions_v1beta1_deployment_condition->lastUpdateTime) == NULL) {
    goto fail; //Date-Time
    }
     } 


	// extensions_v1beta1_deployment_condition->message
    if(extensions_v1beta1_deployment_condition->message) { 
    if(cJSON_AddStringToObject(item, "message", extensions_v1beta1_deployment_condition->message) == NULL) {
    goto fail; //String
    }
     } 


	// extensions_v1beta1_deployment_condition->reason
    if(extensions_v1beta1_deployment_condition->reason) { 
    if(cJSON_AddStringToObject(item, "reason", extensions_v1beta1_deployment_condition->reason) == NULL) {
    goto fail; //String
    }
     } 


	// extensions_v1beta1_deployment_condition->status
    if (!extensions_v1beta1_deployment_condition->status) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "status", extensions_v1beta1_deployment_condition->status) == NULL) {
    goto fail; //String
    }


	// extensions_v1beta1_deployment_condition->type
    if (!extensions_v1beta1_deployment_condition->type) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "type", extensions_v1beta1_deployment_condition->type) == NULL) {
    goto fail; //String
    }

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

extensions_v1beta1_deployment_condition_t *extensions_v1beta1_deployment_condition_parseFromJSON(cJSON *extensions_v1beta1_deployment_conditionJSON){

    extensions_v1beta1_deployment_condition_t *extensions_v1beta1_deployment_condition_local_var = NULL;

    // extensions_v1beta1_deployment_condition->lastTransitionTime
    cJSON *lastTransitionTime = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_deployment_conditionJSON, "lastTransitionTime");
    if (lastTransitionTime) { 
    if(!cJSON_IsString(lastTransitionTime))
    {
    goto end; //DateTime
    }
    }

    // extensions_v1beta1_deployment_condition->lastUpdateTime
    cJSON *lastUpdateTime = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_deployment_conditionJSON, "lastUpdateTime");
    if (lastUpdateTime) { 
    if(!cJSON_IsString(lastUpdateTime))
    {
    goto end; //DateTime
    }
    }

    // extensions_v1beta1_deployment_condition->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_deployment_conditionJSON, "message");
    if (message) { 
    if(!cJSON_IsString(message))
    {
    goto end; //String
    }
    }

    // extensions_v1beta1_deployment_condition->reason
    cJSON *reason = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_deployment_conditionJSON, "reason");
    if (reason) { 
    if(!cJSON_IsString(reason))
    {
    goto end; //String
    }
    }

    // extensions_v1beta1_deployment_condition->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_deployment_conditionJSON, "status");
    if (!status) {
        goto end;
    }

    
    if(!cJSON_IsString(status))
    {
    goto end; //String
    }

    // extensions_v1beta1_deployment_condition->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_deployment_conditionJSON, "type");
    if (!type) {
        goto end;
    }

    
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }


    extensions_v1beta1_deployment_condition_local_var = extensions_v1beta1_deployment_condition_create (
        lastTransitionTime ? strdup(lastTransitionTime->valuestring) : NULL,
        lastUpdateTime ? strdup(lastUpdateTime->valuestring) : NULL,
        message ? strdup(message->valuestring) : NULL,
        reason ? strdup(reason->valuestring) : NULL,
        strdup(status->valuestring),
        strdup(type->valuestring)
        );

    return extensions_v1beta1_deployment_condition_local_var;
end:
    return NULL;

}
