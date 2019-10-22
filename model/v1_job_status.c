#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_job_status.h"



v1_job_status_t *v1_job_status_create(
    int active,
    char *completionTime,
    list_t *conditions,
    int failed,
    char *startTime,
    int succeeded
    ) {
	v1_job_status_t *v1_job_status_local_var = malloc(sizeof(v1_job_status_t));
    if (!v1_job_status_local_var) {
        return NULL;
    }
	v1_job_status_local_var->active = active;
	v1_job_status_local_var->completionTime = completionTime;
	v1_job_status_local_var->conditions = conditions;
	v1_job_status_local_var->failed = failed;
	v1_job_status_local_var->startTime = startTime;
	v1_job_status_local_var->succeeded = succeeded;

	return v1_job_status_local_var;
}


void v1_job_status_free(v1_job_status_t *v1_job_status) {
    listEntry_t *listEntry;
    free(v1_job_status->completionTime);
	list_ForEach(listEntry, v1_job_status->conditions) {
		v1_job_condition_free(listEntry->data);
	}
	list_free(v1_job_status->conditions);
    free(v1_job_status->startTime);
	free(v1_job_status);
}

cJSON *v1_job_status_convertToJSON(v1_job_status_t *v1_job_status) {
	cJSON *item = cJSON_CreateObject();

	// v1_job_status->active
    if(v1_job_status->active) { 
    if(cJSON_AddNumberToObject(item, "active", v1_job_status->active) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1_job_status->completionTime
    if(v1_job_status->completionTime) { 
    if(cJSON_AddStringToObject(item, "completionTime", v1_job_status->completionTime) == NULL) {
    goto fail; //Date-Time
    }
     } 


	// v1_job_status->conditions
    if(v1_job_status->conditions) { 
    cJSON *conditions = cJSON_AddArrayToObject(item, "conditions");
    if(conditions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *conditionsListEntry;
    if (v1_job_status->conditions) {
    list_ForEach(conditionsListEntry, v1_job_status->conditions) {
    cJSON *itemLocal = v1_job_condition_convertToJSON(conditionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(conditions, itemLocal);
    }
    }
     } 


	// v1_job_status->failed
    if(v1_job_status->failed) { 
    if(cJSON_AddNumberToObject(item, "failed", v1_job_status->failed) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1_job_status->startTime
    if(v1_job_status->startTime) { 
    if(cJSON_AddStringToObject(item, "startTime", v1_job_status->startTime) == NULL) {
    goto fail; //Date-Time
    }
     } 


	// v1_job_status->succeeded
    if(v1_job_status->succeeded) { 
    if(cJSON_AddNumberToObject(item, "succeeded", v1_job_status->succeeded) == NULL) {
    goto fail; //Numeric
    }
     } 

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1_job_status_t *v1_job_status_parseFromJSON(cJSON *v1_job_statusJSON){

    v1_job_status_t *v1_job_status_local_var = NULL;

    // v1_job_status->active
    cJSON *active = cJSON_GetObjectItemCaseSensitive(v1_job_statusJSON, "active");
    if (active) { 
    if(!cJSON_IsNumber(active))
    {
    goto end; //Numeric
    }
    }

    // v1_job_status->completionTime
    cJSON *completionTime = cJSON_GetObjectItemCaseSensitive(v1_job_statusJSON, "completionTime");
    if (completionTime) { 
    if(!cJSON_IsString(completionTime))
    {
    goto end; //DateTime
    }
    }

    // v1_job_status->conditions
    cJSON *conditions = cJSON_GetObjectItemCaseSensitive(v1_job_statusJSON, "conditions");
    list_t *conditionsList;
    if (conditions) { 
    cJSON *conditions_local_nonprimitive;
    if(!cJSON_IsArray(conditions)){
        goto end; //nonprimitive container
    }

    conditionsList = list_create();

    cJSON_ArrayForEach(conditions_local_nonprimitive,conditions )
    {
        if(!cJSON_IsObject(conditions_local_nonprimitive)){
            goto end;
        }
        v1_job_condition_t *conditionsItem = v1_job_condition_parseFromJSON(conditions_local_nonprimitive);

        list_addElement(conditionsList, conditionsItem);
    }
    }

    // v1_job_status->failed
    cJSON *failed = cJSON_GetObjectItemCaseSensitive(v1_job_statusJSON, "failed");
    if (failed) { 
    if(!cJSON_IsNumber(failed))
    {
    goto end; //Numeric
    }
    }

    // v1_job_status->startTime
    cJSON *startTime = cJSON_GetObjectItemCaseSensitive(v1_job_statusJSON, "startTime");
    if (startTime) { 
    if(!cJSON_IsString(startTime))
    {
    goto end; //DateTime
    }
    }

    // v1_job_status->succeeded
    cJSON *succeeded = cJSON_GetObjectItemCaseSensitive(v1_job_statusJSON, "succeeded");
    if (succeeded) { 
    if(!cJSON_IsNumber(succeeded))
    {
    goto end; //Numeric
    }
    }


    v1_job_status_local_var = v1_job_status_create (
        active ? active->valuedouble : 0,
        completionTime ? strdup(completionTime->valuestring) : NULL,
        conditions ? conditionsList : NULL,
        failed ? failed->valuedouble : 0,
        startTime ? strdup(startTime->valuestring) : NULL,
        succeeded ? succeeded->valuedouble : 0
        );

    return v1_job_status_local_var;
end:
    return NULL;

}
