#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta2_deployment_status.h"



v1beta2_deployment_status_t *v1beta2_deployment_status_create(
    int availableReplicas,
    int collisionCount,
    list_t *conditions,
    long observedGeneration,
    int readyReplicas,
    int replicas,
    int unavailableReplicas,
    int updatedReplicas
    ) {
	v1beta2_deployment_status_t *v1beta2_deployment_status_local_var = malloc(sizeof(v1beta2_deployment_status_t));
    if (!v1beta2_deployment_status_local_var) {
        return NULL;
    }
	v1beta2_deployment_status_local_var->availableReplicas = availableReplicas;
	v1beta2_deployment_status_local_var->collisionCount = collisionCount;
	v1beta2_deployment_status_local_var->conditions = conditions;
	v1beta2_deployment_status_local_var->observedGeneration = observedGeneration;
	v1beta2_deployment_status_local_var->readyReplicas = readyReplicas;
	v1beta2_deployment_status_local_var->replicas = replicas;
	v1beta2_deployment_status_local_var->unavailableReplicas = unavailableReplicas;
	v1beta2_deployment_status_local_var->updatedReplicas = updatedReplicas;

	return v1beta2_deployment_status_local_var;
}


void v1beta2_deployment_status_free(v1beta2_deployment_status_t *v1beta2_deployment_status) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, v1beta2_deployment_status->conditions) {
		v1beta2_deployment_condition_free(listEntry->data);
	}
	list_free(v1beta2_deployment_status->conditions);
	free(v1beta2_deployment_status);
}

cJSON *v1beta2_deployment_status_convertToJSON(v1beta2_deployment_status_t *v1beta2_deployment_status) {
	cJSON *item = cJSON_CreateObject();

	// v1beta2_deployment_status->availableReplicas
    if(v1beta2_deployment_status->availableReplicas) { 
    if(cJSON_AddNumberToObject(item, "availableReplicas", v1beta2_deployment_status->availableReplicas) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1beta2_deployment_status->collisionCount
    if(v1beta2_deployment_status->collisionCount) { 
    if(cJSON_AddNumberToObject(item, "collisionCount", v1beta2_deployment_status->collisionCount) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1beta2_deployment_status->conditions
    if(v1beta2_deployment_status->conditions) { 
    cJSON *conditions = cJSON_AddArrayToObject(item, "conditions");
    if(conditions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *conditionsListEntry;
    if (v1beta2_deployment_status->conditions) {
    list_ForEach(conditionsListEntry, v1beta2_deployment_status->conditions) {
    cJSON *itemLocal = v1beta2_deployment_condition_convertToJSON(conditionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(conditions, itemLocal);
    }
    }
     } 


	// v1beta2_deployment_status->observedGeneration
    if(v1beta2_deployment_status->observedGeneration) { 
    if(cJSON_AddNumberToObject(item, "observedGeneration", v1beta2_deployment_status->observedGeneration) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1beta2_deployment_status->readyReplicas
    if(v1beta2_deployment_status->readyReplicas) { 
    if(cJSON_AddNumberToObject(item, "readyReplicas", v1beta2_deployment_status->readyReplicas) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1beta2_deployment_status->replicas
    if(v1beta2_deployment_status->replicas) { 
    if(cJSON_AddNumberToObject(item, "replicas", v1beta2_deployment_status->replicas) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1beta2_deployment_status->unavailableReplicas
    if(v1beta2_deployment_status->unavailableReplicas) { 
    if(cJSON_AddNumberToObject(item, "unavailableReplicas", v1beta2_deployment_status->unavailableReplicas) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1beta2_deployment_status->updatedReplicas
    if(v1beta2_deployment_status->updatedReplicas) { 
    if(cJSON_AddNumberToObject(item, "updatedReplicas", v1beta2_deployment_status->updatedReplicas) == NULL) {
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

v1beta2_deployment_status_t *v1beta2_deployment_status_parseFromJSON(cJSON *v1beta2_deployment_statusJSON){

    v1beta2_deployment_status_t *v1beta2_deployment_status_local_var = NULL;

    // v1beta2_deployment_status->availableReplicas
    cJSON *availableReplicas = cJSON_GetObjectItemCaseSensitive(v1beta2_deployment_statusJSON, "availableReplicas");
    if (availableReplicas) { 
    if(!cJSON_IsNumber(availableReplicas))
    {
    goto end; //Numeric
    }
    }

    // v1beta2_deployment_status->collisionCount
    cJSON *collisionCount = cJSON_GetObjectItemCaseSensitive(v1beta2_deployment_statusJSON, "collisionCount");
    if (collisionCount) { 
    if(!cJSON_IsNumber(collisionCount))
    {
    goto end; //Numeric
    }
    }

    // v1beta2_deployment_status->conditions
    cJSON *conditions = cJSON_GetObjectItemCaseSensitive(v1beta2_deployment_statusJSON, "conditions");
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
        v1beta2_deployment_condition_t *conditionsItem = v1beta2_deployment_condition_parseFromJSON(conditions_local_nonprimitive);

        list_addElement(conditionsList, conditionsItem);
    }
    }

    // v1beta2_deployment_status->observedGeneration
    cJSON *observedGeneration = cJSON_GetObjectItemCaseSensitive(v1beta2_deployment_statusJSON, "observedGeneration");
    if (observedGeneration) { 
    if(!cJSON_IsNumber(observedGeneration))
    {
    goto end; //Numeric
    }
    }

    // v1beta2_deployment_status->readyReplicas
    cJSON *readyReplicas = cJSON_GetObjectItemCaseSensitive(v1beta2_deployment_statusJSON, "readyReplicas");
    if (readyReplicas) { 
    if(!cJSON_IsNumber(readyReplicas))
    {
    goto end; //Numeric
    }
    }

    // v1beta2_deployment_status->replicas
    cJSON *replicas = cJSON_GetObjectItemCaseSensitive(v1beta2_deployment_statusJSON, "replicas");
    if (replicas) { 
    if(!cJSON_IsNumber(replicas))
    {
    goto end; //Numeric
    }
    }

    // v1beta2_deployment_status->unavailableReplicas
    cJSON *unavailableReplicas = cJSON_GetObjectItemCaseSensitive(v1beta2_deployment_statusJSON, "unavailableReplicas");
    if (unavailableReplicas) { 
    if(!cJSON_IsNumber(unavailableReplicas))
    {
    goto end; //Numeric
    }
    }

    // v1beta2_deployment_status->updatedReplicas
    cJSON *updatedReplicas = cJSON_GetObjectItemCaseSensitive(v1beta2_deployment_statusJSON, "updatedReplicas");
    if (updatedReplicas) { 
    if(!cJSON_IsNumber(updatedReplicas))
    {
    goto end; //Numeric
    }
    }


    v1beta2_deployment_status_local_var = v1beta2_deployment_status_create (
        availableReplicas ? availableReplicas->valuedouble : 0,
        collisionCount ? collisionCount->valuedouble : 0,
        conditions ? conditionsList : NULL,
        observedGeneration ? observedGeneration->valuedouble : 0,
        readyReplicas ? readyReplicas->valuedouble : 0,
        replicas ? replicas->valuedouble : 0,
        unavailableReplicas ? unavailableReplicas->valuedouble : 0,
        updatedReplicas ? updatedReplicas->valuedouble : 0
        );

    return v1beta2_deployment_status_local_var;
end:
    return NULL;

}
