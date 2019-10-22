#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_daemon_set_status.h"



v1_daemon_set_status_t *v1_daemon_set_status_create(
    int collisionCount,
    list_t *conditions,
    int currentNumberScheduled,
    int desiredNumberScheduled,
    int numberAvailable,
    int numberMisscheduled,
    int numberReady,
    int numberUnavailable,
    long observedGeneration,
    int updatedNumberScheduled
    ) {
	v1_daemon_set_status_t *v1_daemon_set_status_local_var = malloc(sizeof(v1_daemon_set_status_t));
    if (!v1_daemon_set_status_local_var) {
        return NULL;
    }
	v1_daemon_set_status_local_var->collisionCount = collisionCount;
	v1_daemon_set_status_local_var->conditions = conditions;
	v1_daemon_set_status_local_var->currentNumberScheduled = currentNumberScheduled;
	v1_daemon_set_status_local_var->desiredNumberScheduled = desiredNumberScheduled;
	v1_daemon_set_status_local_var->numberAvailable = numberAvailable;
	v1_daemon_set_status_local_var->numberMisscheduled = numberMisscheduled;
	v1_daemon_set_status_local_var->numberReady = numberReady;
	v1_daemon_set_status_local_var->numberUnavailable = numberUnavailable;
	v1_daemon_set_status_local_var->observedGeneration = observedGeneration;
	v1_daemon_set_status_local_var->updatedNumberScheduled = updatedNumberScheduled;

	return v1_daemon_set_status_local_var;
}


void v1_daemon_set_status_free(v1_daemon_set_status_t *v1_daemon_set_status) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, v1_daemon_set_status->conditions) {
		v1_daemon_set_condition_free(listEntry->data);
	}
	list_free(v1_daemon_set_status->conditions);
	free(v1_daemon_set_status);
}

cJSON *v1_daemon_set_status_convertToJSON(v1_daemon_set_status_t *v1_daemon_set_status) {
	cJSON *item = cJSON_CreateObject();

	// v1_daemon_set_status->collisionCount
    if(v1_daemon_set_status->collisionCount) { 
    if(cJSON_AddNumberToObject(item, "collisionCount", v1_daemon_set_status->collisionCount) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1_daemon_set_status->conditions
    if(v1_daemon_set_status->conditions) { 
    cJSON *conditions = cJSON_AddArrayToObject(item, "conditions");
    if(conditions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *conditionsListEntry;
    if (v1_daemon_set_status->conditions) {
    list_ForEach(conditionsListEntry, v1_daemon_set_status->conditions) {
    cJSON *itemLocal = v1_daemon_set_condition_convertToJSON(conditionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(conditions, itemLocal);
    }
    }
     } 


	// v1_daemon_set_status->currentNumberScheduled
    if (!v1_daemon_set_status->currentNumberScheduled) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "currentNumberScheduled", v1_daemon_set_status->currentNumberScheduled) == NULL) {
    goto fail; //Numeric
    }


	// v1_daemon_set_status->desiredNumberScheduled
    if (!v1_daemon_set_status->desiredNumberScheduled) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "desiredNumberScheduled", v1_daemon_set_status->desiredNumberScheduled) == NULL) {
    goto fail; //Numeric
    }


	// v1_daemon_set_status->numberAvailable
    if(v1_daemon_set_status->numberAvailable) { 
    if(cJSON_AddNumberToObject(item, "numberAvailable", v1_daemon_set_status->numberAvailable) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1_daemon_set_status->numberMisscheduled
    if (!v1_daemon_set_status->numberMisscheduled) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "numberMisscheduled", v1_daemon_set_status->numberMisscheduled) == NULL) {
    goto fail; //Numeric
    }


	// v1_daemon_set_status->numberReady
    if (!v1_daemon_set_status->numberReady) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "numberReady", v1_daemon_set_status->numberReady) == NULL) {
    goto fail; //Numeric
    }


	// v1_daemon_set_status->numberUnavailable
    if(v1_daemon_set_status->numberUnavailable) { 
    if(cJSON_AddNumberToObject(item, "numberUnavailable", v1_daemon_set_status->numberUnavailable) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1_daemon_set_status->observedGeneration
    if(v1_daemon_set_status->observedGeneration) { 
    if(cJSON_AddNumberToObject(item, "observedGeneration", v1_daemon_set_status->observedGeneration) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1_daemon_set_status->updatedNumberScheduled
    if(v1_daemon_set_status->updatedNumberScheduled) { 
    if(cJSON_AddNumberToObject(item, "updatedNumberScheduled", v1_daemon_set_status->updatedNumberScheduled) == NULL) {
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

v1_daemon_set_status_t *v1_daemon_set_status_parseFromJSON(cJSON *v1_daemon_set_statusJSON){

    v1_daemon_set_status_t *v1_daemon_set_status_local_var = NULL;

    // v1_daemon_set_status->collisionCount
    cJSON *collisionCount = cJSON_GetObjectItemCaseSensitive(v1_daemon_set_statusJSON, "collisionCount");
    if (collisionCount) { 
    if(!cJSON_IsNumber(collisionCount))
    {
    goto end; //Numeric
    }
    }

    // v1_daemon_set_status->conditions
    cJSON *conditions = cJSON_GetObjectItemCaseSensitive(v1_daemon_set_statusJSON, "conditions");
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
        v1_daemon_set_condition_t *conditionsItem = v1_daemon_set_condition_parseFromJSON(conditions_local_nonprimitive);

        list_addElement(conditionsList, conditionsItem);
    }
    }

    // v1_daemon_set_status->currentNumberScheduled
    cJSON *currentNumberScheduled = cJSON_GetObjectItemCaseSensitive(v1_daemon_set_statusJSON, "currentNumberScheduled");
    if (!currentNumberScheduled) {
        goto end;
    }

    
    if(!cJSON_IsNumber(currentNumberScheduled))
    {
    goto end; //Numeric
    }

    // v1_daemon_set_status->desiredNumberScheduled
    cJSON *desiredNumberScheduled = cJSON_GetObjectItemCaseSensitive(v1_daemon_set_statusJSON, "desiredNumberScheduled");
    if (!desiredNumberScheduled) {
        goto end;
    }

    
    if(!cJSON_IsNumber(desiredNumberScheduled))
    {
    goto end; //Numeric
    }

    // v1_daemon_set_status->numberAvailable
    cJSON *numberAvailable = cJSON_GetObjectItemCaseSensitive(v1_daemon_set_statusJSON, "numberAvailable");
    if (numberAvailable) { 
    if(!cJSON_IsNumber(numberAvailable))
    {
    goto end; //Numeric
    }
    }

    // v1_daemon_set_status->numberMisscheduled
    cJSON *numberMisscheduled = cJSON_GetObjectItemCaseSensitive(v1_daemon_set_statusJSON, "numberMisscheduled");
    if (!numberMisscheduled) {
        goto end;
    }

    
    if(!cJSON_IsNumber(numberMisscheduled))
    {
    goto end; //Numeric
    }

    // v1_daemon_set_status->numberReady
    cJSON *numberReady = cJSON_GetObjectItemCaseSensitive(v1_daemon_set_statusJSON, "numberReady");
    if (!numberReady) {
        goto end;
    }

    
    if(!cJSON_IsNumber(numberReady))
    {
    goto end; //Numeric
    }

    // v1_daemon_set_status->numberUnavailable
    cJSON *numberUnavailable = cJSON_GetObjectItemCaseSensitive(v1_daemon_set_statusJSON, "numberUnavailable");
    if (numberUnavailable) { 
    if(!cJSON_IsNumber(numberUnavailable))
    {
    goto end; //Numeric
    }
    }

    // v1_daemon_set_status->observedGeneration
    cJSON *observedGeneration = cJSON_GetObjectItemCaseSensitive(v1_daemon_set_statusJSON, "observedGeneration");
    if (observedGeneration) { 
    if(!cJSON_IsNumber(observedGeneration))
    {
    goto end; //Numeric
    }
    }

    // v1_daemon_set_status->updatedNumberScheduled
    cJSON *updatedNumberScheduled = cJSON_GetObjectItemCaseSensitive(v1_daemon_set_statusJSON, "updatedNumberScheduled");
    if (updatedNumberScheduled) { 
    if(!cJSON_IsNumber(updatedNumberScheduled))
    {
    goto end; //Numeric
    }
    }


    v1_daemon_set_status_local_var = v1_daemon_set_status_create (
        collisionCount ? collisionCount->valuedouble : 0,
        conditions ? conditionsList : NULL,
        currentNumberScheduled->valuedouble,
        desiredNumberScheduled->valuedouble,
        numberAvailable ? numberAvailable->valuedouble : 0,
        numberMisscheduled->valuedouble,
        numberReady->valuedouble,
        numberUnavailable ? numberUnavailable->valuedouble : 0,
        observedGeneration ? observedGeneration->valuedouble : 0,
        updatedNumberScheduled ? updatedNumberScheduled->valuedouble : 0
        );

    return v1_daemon_set_status_local_var;
end:
    return NULL;

}
