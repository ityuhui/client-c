#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_container_state_terminated.h"



v1_container_state_terminated_t *v1_container_state_terminated_create(
    char *containerID,
    int exitCode,
    char *finishedAt,
    char *message,
    char *reason,
    int signal,
    char *startedAt
    ) {
	v1_container_state_terminated_t *v1_container_state_terminated_local_var = malloc(sizeof(v1_container_state_terminated_t));
    if (!v1_container_state_terminated_local_var) {
        return NULL;
    }
	v1_container_state_terminated_local_var->containerID = containerID;
	v1_container_state_terminated_local_var->exitCode = exitCode;
	v1_container_state_terminated_local_var->finishedAt = finishedAt;
	v1_container_state_terminated_local_var->message = message;
	v1_container_state_terminated_local_var->reason = reason;
	v1_container_state_terminated_local_var->signal = signal;
	v1_container_state_terminated_local_var->startedAt = startedAt;

	return v1_container_state_terminated_local_var;
}


void v1_container_state_terminated_free(v1_container_state_terminated_t *v1_container_state_terminated) {
    listEntry_t *listEntry;
    free(v1_container_state_terminated->containerID);
    free(v1_container_state_terminated->finishedAt);
    free(v1_container_state_terminated->message);
    free(v1_container_state_terminated->reason);
    free(v1_container_state_terminated->startedAt);
	free(v1_container_state_terminated);
}

cJSON *v1_container_state_terminated_convertToJSON(v1_container_state_terminated_t *v1_container_state_terminated) {
	cJSON *item = cJSON_CreateObject();

	// v1_container_state_terminated->containerID
    if(v1_container_state_terminated->containerID) { 
    if(cJSON_AddStringToObject(item, "containerID", v1_container_state_terminated->containerID) == NULL) {
    goto fail; //String
    }
     } 


	// v1_container_state_terminated->exitCode
    if (!v1_container_state_terminated->exitCode) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "exitCode", v1_container_state_terminated->exitCode) == NULL) {
    goto fail; //Numeric
    }


	// v1_container_state_terminated->finishedAt
    if(v1_container_state_terminated->finishedAt) { 
    if(cJSON_AddStringToObject(item, "finishedAt", v1_container_state_terminated->finishedAt) == NULL) {
    goto fail; //Date-Time
    }
     } 


	// v1_container_state_terminated->message
    if(v1_container_state_terminated->message) { 
    if(cJSON_AddStringToObject(item, "message", v1_container_state_terminated->message) == NULL) {
    goto fail; //String
    }
     } 


	// v1_container_state_terminated->reason
    if(v1_container_state_terminated->reason) { 
    if(cJSON_AddStringToObject(item, "reason", v1_container_state_terminated->reason) == NULL) {
    goto fail; //String
    }
     } 


	// v1_container_state_terminated->signal
    if(v1_container_state_terminated->signal) { 
    if(cJSON_AddNumberToObject(item, "signal", v1_container_state_terminated->signal) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1_container_state_terminated->startedAt
    if(v1_container_state_terminated->startedAt) { 
    if(cJSON_AddStringToObject(item, "startedAt", v1_container_state_terminated->startedAt) == NULL) {
    goto fail; //Date-Time
    }
     } 

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1_container_state_terminated_t *v1_container_state_terminated_parseFromJSON(cJSON *v1_container_state_terminatedJSON){

    v1_container_state_terminated_t *v1_container_state_terminated_local_var = NULL;

    // v1_container_state_terminated->containerID
    cJSON *containerID = cJSON_GetObjectItemCaseSensitive(v1_container_state_terminatedJSON, "containerID");
    if (containerID) { 
    if(!cJSON_IsString(containerID))
    {
    goto end; //String
    }
    }

    // v1_container_state_terminated->exitCode
    cJSON *exitCode = cJSON_GetObjectItemCaseSensitive(v1_container_state_terminatedJSON, "exitCode");
    if (!exitCode) {
        goto end;
    }

    
    if(!cJSON_IsNumber(exitCode))
    {
    goto end; //Numeric
    }

    // v1_container_state_terminated->finishedAt
    cJSON *finishedAt = cJSON_GetObjectItemCaseSensitive(v1_container_state_terminatedJSON, "finishedAt");
    if (finishedAt) { 
    if(!cJSON_IsString(finishedAt))
    {
    goto end; //DateTime
    }
    }

    // v1_container_state_terminated->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(v1_container_state_terminatedJSON, "message");
    if (message) { 
    if(!cJSON_IsString(message))
    {
    goto end; //String
    }
    }

    // v1_container_state_terminated->reason
    cJSON *reason = cJSON_GetObjectItemCaseSensitive(v1_container_state_terminatedJSON, "reason");
    if (reason) { 
    if(!cJSON_IsString(reason))
    {
    goto end; //String
    }
    }

    // v1_container_state_terminated->signal
    cJSON *signal = cJSON_GetObjectItemCaseSensitive(v1_container_state_terminatedJSON, "signal");
    if (signal) { 
    if(!cJSON_IsNumber(signal))
    {
    goto end; //Numeric
    }
    }

    // v1_container_state_terminated->startedAt
    cJSON *startedAt = cJSON_GetObjectItemCaseSensitive(v1_container_state_terminatedJSON, "startedAt");
    if (startedAt) { 
    if(!cJSON_IsString(startedAt))
    {
    goto end; //DateTime
    }
    }


    v1_container_state_terminated_local_var = v1_container_state_terminated_create (
        containerID ? strdup(containerID->valuestring) : NULL,
        exitCode->valuedouble,
        finishedAt ? strdup(finishedAt->valuestring) : NULL,
        message ? strdup(message->valuestring) : NULL,
        reason ? strdup(reason->valuestring) : NULL,
        signal ? signal->valuedouble : 0,
        startedAt ? strdup(startedAt->valuestring) : NULL
        );

    return v1_container_state_terminated_local_var;
end:
    return NULL;

}
