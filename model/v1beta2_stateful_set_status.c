#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta2_stateful_set_status.h"



v1beta2_stateful_set_status_t *v1beta2_stateful_set_status_create(
    int collisionCount,
    list_t *conditions,
    int currentReplicas,
    char *currentRevision,
    long observedGeneration,
    int readyReplicas,
    int replicas,
    char *updateRevision,
    int updatedReplicas
    ) {
	v1beta2_stateful_set_status_t *v1beta2_stateful_set_status_local_var = malloc(sizeof(v1beta2_stateful_set_status_t));
    if (!v1beta2_stateful_set_status_local_var) {
        return NULL;
    }
	v1beta2_stateful_set_status_local_var->collisionCount = collisionCount;
	v1beta2_stateful_set_status_local_var->conditions = conditions;
	v1beta2_stateful_set_status_local_var->currentReplicas = currentReplicas;
	v1beta2_stateful_set_status_local_var->currentRevision = currentRevision;
	v1beta2_stateful_set_status_local_var->observedGeneration = observedGeneration;
	v1beta2_stateful_set_status_local_var->readyReplicas = readyReplicas;
	v1beta2_stateful_set_status_local_var->replicas = replicas;
	v1beta2_stateful_set_status_local_var->updateRevision = updateRevision;
	v1beta2_stateful_set_status_local_var->updatedReplicas = updatedReplicas;

	return v1beta2_stateful_set_status_local_var;
}


void v1beta2_stateful_set_status_free(v1beta2_stateful_set_status_t *v1beta2_stateful_set_status) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, v1beta2_stateful_set_status->conditions) {
		v1beta2_stateful_set_condition_free(listEntry->data);
	}
	list_free(v1beta2_stateful_set_status->conditions);
    free(v1beta2_stateful_set_status->currentRevision);
    free(v1beta2_stateful_set_status->updateRevision);
	free(v1beta2_stateful_set_status);
}

cJSON *v1beta2_stateful_set_status_convertToJSON(v1beta2_stateful_set_status_t *v1beta2_stateful_set_status) {
	cJSON *item = cJSON_CreateObject();

	// v1beta2_stateful_set_status->collisionCount
    if(v1beta2_stateful_set_status->collisionCount) { 
    if(cJSON_AddNumberToObject(item, "collisionCount", v1beta2_stateful_set_status->collisionCount) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1beta2_stateful_set_status->conditions
    if(v1beta2_stateful_set_status->conditions) { 
    cJSON *conditions = cJSON_AddArrayToObject(item, "conditions");
    if(conditions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *conditionsListEntry;
    if (v1beta2_stateful_set_status->conditions) {
    list_ForEach(conditionsListEntry, v1beta2_stateful_set_status->conditions) {
    cJSON *itemLocal = v1beta2_stateful_set_condition_convertToJSON(conditionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(conditions, itemLocal);
    }
    }
     } 


	// v1beta2_stateful_set_status->currentReplicas
    if(v1beta2_stateful_set_status->currentReplicas) { 
    if(cJSON_AddNumberToObject(item, "currentReplicas", v1beta2_stateful_set_status->currentReplicas) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1beta2_stateful_set_status->currentRevision
    if(v1beta2_stateful_set_status->currentRevision) { 
    if(cJSON_AddStringToObject(item, "currentRevision", v1beta2_stateful_set_status->currentRevision) == NULL) {
    goto fail; //String
    }
     } 


	// v1beta2_stateful_set_status->observedGeneration
    if(v1beta2_stateful_set_status->observedGeneration) { 
    if(cJSON_AddNumberToObject(item, "observedGeneration", v1beta2_stateful_set_status->observedGeneration) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1beta2_stateful_set_status->readyReplicas
    if(v1beta2_stateful_set_status->readyReplicas) { 
    if(cJSON_AddNumberToObject(item, "readyReplicas", v1beta2_stateful_set_status->readyReplicas) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1beta2_stateful_set_status->replicas
    if (!v1beta2_stateful_set_status->replicas) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "replicas", v1beta2_stateful_set_status->replicas) == NULL) {
    goto fail; //Numeric
    }


	// v1beta2_stateful_set_status->updateRevision
    if(v1beta2_stateful_set_status->updateRevision) { 
    if(cJSON_AddStringToObject(item, "updateRevision", v1beta2_stateful_set_status->updateRevision) == NULL) {
    goto fail; //String
    }
     } 


	// v1beta2_stateful_set_status->updatedReplicas
    if(v1beta2_stateful_set_status->updatedReplicas) { 
    if(cJSON_AddNumberToObject(item, "updatedReplicas", v1beta2_stateful_set_status->updatedReplicas) == NULL) {
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

v1beta2_stateful_set_status_t *v1beta2_stateful_set_status_parseFromJSON(cJSON *v1beta2_stateful_set_statusJSON){

    v1beta2_stateful_set_status_t *v1beta2_stateful_set_status_local_var = NULL;

    // v1beta2_stateful_set_status->collisionCount
    cJSON *collisionCount = cJSON_GetObjectItemCaseSensitive(v1beta2_stateful_set_statusJSON, "collisionCount");
    if (collisionCount) { 
    if(!cJSON_IsNumber(collisionCount))
    {
    goto end; //Numeric
    }
    }

    // v1beta2_stateful_set_status->conditions
    cJSON *conditions = cJSON_GetObjectItemCaseSensitive(v1beta2_stateful_set_statusJSON, "conditions");
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
        v1beta2_stateful_set_condition_t *conditionsItem = v1beta2_stateful_set_condition_parseFromJSON(conditions_local_nonprimitive);

        list_addElement(conditionsList, conditionsItem);
    }
    }

    // v1beta2_stateful_set_status->currentReplicas
    cJSON *currentReplicas = cJSON_GetObjectItemCaseSensitive(v1beta2_stateful_set_statusJSON, "currentReplicas");
    if (currentReplicas) { 
    if(!cJSON_IsNumber(currentReplicas))
    {
    goto end; //Numeric
    }
    }

    // v1beta2_stateful_set_status->currentRevision
    cJSON *currentRevision = cJSON_GetObjectItemCaseSensitive(v1beta2_stateful_set_statusJSON, "currentRevision");
    if (currentRevision) { 
    if(!cJSON_IsString(currentRevision))
    {
    goto end; //String
    }
    }

    // v1beta2_stateful_set_status->observedGeneration
    cJSON *observedGeneration = cJSON_GetObjectItemCaseSensitive(v1beta2_stateful_set_statusJSON, "observedGeneration");
    if (observedGeneration) { 
    if(!cJSON_IsNumber(observedGeneration))
    {
    goto end; //Numeric
    }
    }

    // v1beta2_stateful_set_status->readyReplicas
    cJSON *readyReplicas = cJSON_GetObjectItemCaseSensitive(v1beta2_stateful_set_statusJSON, "readyReplicas");
    if (readyReplicas) { 
    if(!cJSON_IsNumber(readyReplicas))
    {
    goto end; //Numeric
    }
    }

    // v1beta2_stateful_set_status->replicas
    cJSON *replicas = cJSON_GetObjectItemCaseSensitive(v1beta2_stateful_set_statusJSON, "replicas");
    if (!replicas) {
        goto end;
    }

    
    if(!cJSON_IsNumber(replicas))
    {
    goto end; //Numeric
    }

    // v1beta2_stateful_set_status->updateRevision
    cJSON *updateRevision = cJSON_GetObjectItemCaseSensitive(v1beta2_stateful_set_statusJSON, "updateRevision");
    if (updateRevision) { 
    if(!cJSON_IsString(updateRevision))
    {
    goto end; //String
    }
    }

    // v1beta2_stateful_set_status->updatedReplicas
    cJSON *updatedReplicas = cJSON_GetObjectItemCaseSensitive(v1beta2_stateful_set_statusJSON, "updatedReplicas");
    if (updatedReplicas) { 
    if(!cJSON_IsNumber(updatedReplicas))
    {
    goto end; //Numeric
    }
    }


    v1beta2_stateful_set_status_local_var = v1beta2_stateful_set_status_create (
        collisionCount ? collisionCount->valuedouble : 0,
        conditions ? conditionsList : NULL,
        currentReplicas ? currentReplicas->valuedouble : 0,
        currentRevision ? strdup(currentRevision->valuestring) : NULL,
        observedGeneration ? observedGeneration->valuedouble : 0,
        readyReplicas ? readyReplicas->valuedouble : 0,
        replicas->valuedouble,
        updateRevision ? strdup(updateRevision->valuestring) : NULL,
        updatedReplicas ? updatedReplicas->valuedouble : 0
        );

    return v1beta2_stateful_set_status_local_var;
end:
    return NULL;

}
