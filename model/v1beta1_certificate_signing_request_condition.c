#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_certificate_signing_request_condition.h"



v1beta1_certificate_signing_request_condition_t *v1beta1_certificate_signing_request_condition_create(
    char *lastUpdateTime,
    char *message,
    char *reason,
    char *type
    ) {
	v1beta1_certificate_signing_request_condition_t *v1beta1_certificate_signing_request_condition_local_var = malloc(sizeof(v1beta1_certificate_signing_request_condition_t));
    if (!v1beta1_certificate_signing_request_condition_local_var) {
        return NULL;
    }
	v1beta1_certificate_signing_request_condition_local_var->lastUpdateTime = lastUpdateTime;
	v1beta1_certificate_signing_request_condition_local_var->message = message;
	v1beta1_certificate_signing_request_condition_local_var->reason = reason;
	v1beta1_certificate_signing_request_condition_local_var->type = type;

	return v1beta1_certificate_signing_request_condition_local_var;
}


void v1beta1_certificate_signing_request_condition_free(v1beta1_certificate_signing_request_condition_t *v1beta1_certificate_signing_request_condition) {
    listEntry_t *listEntry;
    free(v1beta1_certificate_signing_request_condition->lastUpdateTime);
    free(v1beta1_certificate_signing_request_condition->message);
    free(v1beta1_certificate_signing_request_condition->reason);
    free(v1beta1_certificate_signing_request_condition->type);
	free(v1beta1_certificate_signing_request_condition);
}

cJSON *v1beta1_certificate_signing_request_condition_convertToJSON(v1beta1_certificate_signing_request_condition_t *v1beta1_certificate_signing_request_condition) {
	cJSON *item = cJSON_CreateObject();

	// v1beta1_certificate_signing_request_condition->lastUpdateTime
    if(v1beta1_certificate_signing_request_condition->lastUpdateTime) { 
    if(cJSON_AddStringToObject(item, "lastUpdateTime", v1beta1_certificate_signing_request_condition->lastUpdateTime) == NULL) {
    goto fail; //Date-Time
    }
     } 


	// v1beta1_certificate_signing_request_condition->message
    if(v1beta1_certificate_signing_request_condition->message) { 
    if(cJSON_AddStringToObject(item, "message", v1beta1_certificate_signing_request_condition->message) == NULL) {
    goto fail; //String
    }
     } 


	// v1beta1_certificate_signing_request_condition->reason
    if(v1beta1_certificate_signing_request_condition->reason) { 
    if(cJSON_AddStringToObject(item, "reason", v1beta1_certificate_signing_request_condition->reason) == NULL) {
    goto fail; //String
    }
     } 


	// v1beta1_certificate_signing_request_condition->type
    if (!v1beta1_certificate_signing_request_condition->type) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "type", v1beta1_certificate_signing_request_condition->type) == NULL) {
    goto fail; //String
    }

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1beta1_certificate_signing_request_condition_t *v1beta1_certificate_signing_request_condition_parseFromJSON(cJSON *v1beta1_certificate_signing_request_conditionJSON){

    v1beta1_certificate_signing_request_condition_t *v1beta1_certificate_signing_request_condition_local_var = NULL;

    // v1beta1_certificate_signing_request_condition->lastUpdateTime
    cJSON *lastUpdateTime = cJSON_GetObjectItemCaseSensitive(v1beta1_certificate_signing_request_conditionJSON, "lastUpdateTime");
    if (lastUpdateTime) { 
    if(!cJSON_IsString(lastUpdateTime))
    {
    goto end; //DateTime
    }
    }

    // v1beta1_certificate_signing_request_condition->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(v1beta1_certificate_signing_request_conditionJSON, "message");
    if (message) { 
    if(!cJSON_IsString(message))
    {
    goto end; //String
    }
    }

    // v1beta1_certificate_signing_request_condition->reason
    cJSON *reason = cJSON_GetObjectItemCaseSensitive(v1beta1_certificate_signing_request_conditionJSON, "reason");
    if (reason) { 
    if(!cJSON_IsString(reason))
    {
    goto end; //String
    }
    }

    // v1beta1_certificate_signing_request_condition->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(v1beta1_certificate_signing_request_conditionJSON, "type");
    if (!type) {
        goto end;
    }

    
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }


    v1beta1_certificate_signing_request_condition_local_var = v1beta1_certificate_signing_request_condition_create (
        lastUpdateTime ? strdup(lastUpdateTime->valuestring) : NULL,
        message ? strdup(message->valuestring) : NULL,
        reason ? strdup(reason->valuestring) : NULL,
        strdup(type->valuestring)
        );

    return v1beta1_certificate_signing_request_condition_local_var;
end:
    return NULL;

}
