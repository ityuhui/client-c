#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_subject_access_review_status.h"



v1_subject_access_review_status_t *v1_subject_access_review_status_create(
    int allowed,
    int denied,
    char *evaluationError,
    char *reason
    ) {
	v1_subject_access_review_status_t *v1_subject_access_review_status_local_var = malloc(sizeof(v1_subject_access_review_status_t));
    if (!v1_subject_access_review_status_local_var) {
        return NULL;
    }
	v1_subject_access_review_status_local_var->allowed = allowed;
	v1_subject_access_review_status_local_var->denied = denied;
	v1_subject_access_review_status_local_var->evaluationError = evaluationError;
	v1_subject_access_review_status_local_var->reason = reason;

	return v1_subject_access_review_status_local_var;
}


void v1_subject_access_review_status_free(v1_subject_access_review_status_t *v1_subject_access_review_status) {
    listEntry_t *listEntry;
    free(v1_subject_access_review_status->evaluationError);
    free(v1_subject_access_review_status->reason);
	free(v1_subject_access_review_status);
}

cJSON *v1_subject_access_review_status_convertToJSON(v1_subject_access_review_status_t *v1_subject_access_review_status) {
	cJSON *item = cJSON_CreateObject();

	// v1_subject_access_review_status->allowed
    if (!v1_subject_access_review_status->allowed) {
        goto fail;
    }
    
    if(cJSON_AddBoolToObject(item, "allowed", v1_subject_access_review_status->allowed) == NULL) {
    goto fail; //Bool
    }


	// v1_subject_access_review_status->denied
    if(v1_subject_access_review_status->denied) { 
    if(cJSON_AddBoolToObject(item, "denied", v1_subject_access_review_status->denied) == NULL) {
    goto fail; //Bool
    }
     } 


	// v1_subject_access_review_status->evaluationError
    if(v1_subject_access_review_status->evaluationError) { 
    if(cJSON_AddStringToObject(item, "evaluationError", v1_subject_access_review_status->evaluationError) == NULL) {
    goto fail; //String
    }
     } 


	// v1_subject_access_review_status->reason
    if(v1_subject_access_review_status->reason) { 
    if(cJSON_AddStringToObject(item, "reason", v1_subject_access_review_status->reason) == NULL) {
    goto fail; //String
    }
     } 

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1_subject_access_review_status_t *v1_subject_access_review_status_parseFromJSON(cJSON *v1_subject_access_review_statusJSON){

    v1_subject_access_review_status_t *v1_subject_access_review_status_local_var = NULL;

    // v1_subject_access_review_status->allowed
    cJSON *allowed = cJSON_GetObjectItemCaseSensitive(v1_subject_access_review_statusJSON, "allowed");
    if (!allowed) {
        goto end;
    }

    
    if(!cJSON_IsBool(allowed))
    {
    goto end; //Bool
    }

    // v1_subject_access_review_status->denied
    cJSON *denied = cJSON_GetObjectItemCaseSensitive(v1_subject_access_review_statusJSON, "denied");
    if (denied) { 
    if(!cJSON_IsBool(denied))
    {
    goto end; //Bool
    }
    }

    // v1_subject_access_review_status->evaluationError
    cJSON *evaluationError = cJSON_GetObjectItemCaseSensitive(v1_subject_access_review_statusJSON, "evaluationError");
    if (evaluationError) { 
    if(!cJSON_IsString(evaluationError))
    {
    goto end; //String
    }
    }

    // v1_subject_access_review_status->reason
    cJSON *reason = cJSON_GetObjectItemCaseSensitive(v1_subject_access_review_statusJSON, "reason");
    if (reason) { 
    if(!cJSON_IsString(reason))
    {
    goto end; //String
    }
    }


    v1_subject_access_review_status_local_var = v1_subject_access_review_status_create (
        allowed->valueint,
        denied ? denied->valueint : 0,
        evaluationError ? strdup(evaluationError->valuestring) : NULL,
        reason ? strdup(reason->valuestring) : NULL
        );

    return v1_subject_access_review_status_local_var;
end:
    return NULL;

}
