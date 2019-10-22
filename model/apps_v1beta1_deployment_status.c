#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "apps_v1beta1_deployment_status.h"



apps_v1beta1_deployment_status_t *apps_v1beta1_deployment_status_create(
    int availableReplicas,
    int collisionCount,
    list_t *conditions,
    long observedGeneration,
    int readyReplicas,
    int replicas,
    int unavailableReplicas,
    int updatedReplicas
    ) {
	apps_v1beta1_deployment_status_t *apps_v1beta1_deployment_status_local_var = malloc(sizeof(apps_v1beta1_deployment_status_t));
    if (!apps_v1beta1_deployment_status_local_var) {
        return NULL;
    }
	apps_v1beta1_deployment_status_local_var->availableReplicas = availableReplicas;
	apps_v1beta1_deployment_status_local_var->collisionCount = collisionCount;
	apps_v1beta1_deployment_status_local_var->conditions = conditions;
	apps_v1beta1_deployment_status_local_var->observedGeneration = observedGeneration;
	apps_v1beta1_deployment_status_local_var->readyReplicas = readyReplicas;
	apps_v1beta1_deployment_status_local_var->replicas = replicas;
	apps_v1beta1_deployment_status_local_var->unavailableReplicas = unavailableReplicas;
	apps_v1beta1_deployment_status_local_var->updatedReplicas = updatedReplicas;

	return apps_v1beta1_deployment_status_local_var;
}


void apps_v1beta1_deployment_status_free(apps_v1beta1_deployment_status_t *apps_v1beta1_deployment_status) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, apps_v1beta1_deployment_status->conditions) {
		apps_v1beta1_deployment_condition_free(listEntry->data);
	}
	list_free(apps_v1beta1_deployment_status->conditions);
	free(apps_v1beta1_deployment_status);
}

cJSON *apps_v1beta1_deployment_status_convertToJSON(apps_v1beta1_deployment_status_t *apps_v1beta1_deployment_status) {
	cJSON *item = cJSON_CreateObject();

	// apps_v1beta1_deployment_status->availableReplicas
    if(apps_v1beta1_deployment_status->availableReplicas) { 
    if(cJSON_AddNumberToObject(item, "availableReplicas", apps_v1beta1_deployment_status->availableReplicas) == NULL) {
    goto fail; //Numeric
    }
     } 


	// apps_v1beta1_deployment_status->collisionCount
    if(apps_v1beta1_deployment_status->collisionCount) { 
    if(cJSON_AddNumberToObject(item, "collisionCount", apps_v1beta1_deployment_status->collisionCount) == NULL) {
    goto fail; //Numeric
    }
     } 


	// apps_v1beta1_deployment_status->conditions
    if(apps_v1beta1_deployment_status->conditions) { 
    cJSON *conditions = cJSON_AddArrayToObject(item, "conditions");
    if(conditions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *conditionsListEntry;
    if (apps_v1beta1_deployment_status->conditions) {
    list_ForEach(conditionsListEntry, apps_v1beta1_deployment_status->conditions) {
    cJSON *itemLocal = apps_v1beta1_deployment_condition_convertToJSON(conditionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(conditions, itemLocal);
    }
    }
     } 


	// apps_v1beta1_deployment_status->observedGeneration
    if(apps_v1beta1_deployment_status->observedGeneration) { 
    if(cJSON_AddNumberToObject(item, "observedGeneration", apps_v1beta1_deployment_status->observedGeneration) == NULL) {
    goto fail; //Numeric
    }
     } 


	// apps_v1beta1_deployment_status->readyReplicas
    if(apps_v1beta1_deployment_status->readyReplicas) { 
    if(cJSON_AddNumberToObject(item, "readyReplicas", apps_v1beta1_deployment_status->readyReplicas) == NULL) {
    goto fail; //Numeric
    }
     } 


	// apps_v1beta1_deployment_status->replicas
    if(apps_v1beta1_deployment_status->replicas) { 
    if(cJSON_AddNumberToObject(item, "replicas", apps_v1beta1_deployment_status->replicas) == NULL) {
    goto fail; //Numeric
    }
     } 


	// apps_v1beta1_deployment_status->unavailableReplicas
    if(apps_v1beta1_deployment_status->unavailableReplicas) { 
    if(cJSON_AddNumberToObject(item, "unavailableReplicas", apps_v1beta1_deployment_status->unavailableReplicas) == NULL) {
    goto fail; //Numeric
    }
     } 


	// apps_v1beta1_deployment_status->updatedReplicas
    if(apps_v1beta1_deployment_status->updatedReplicas) { 
    if(cJSON_AddNumberToObject(item, "updatedReplicas", apps_v1beta1_deployment_status->updatedReplicas) == NULL) {
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

apps_v1beta1_deployment_status_t *apps_v1beta1_deployment_status_parseFromJSON(cJSON *apps_v1beta1_deployment_statusJSON){

    apps_v1beta1_deployment_status_t *apps_v1beta1_deployment_status_local_var = NULL;

    // apps_v1beta1_deployment_status->availableReplicas
    cJSON *availableReplicas = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_deployment_statusJSON, "availableReplicas");
    if (availableReplicas) { 
    if(!cJSON_IsNumber(availableReplicas))
    {
    goto end; //Numeric
    }
    }

    // apps_v1beta1_deployment_status->collisionCount
    cJSON *collisionCount = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_deployment_statusJSON, "collisionCount");
    if (collisionCount) { 
    if(!cJSON_IsNumber(collisionCount))
    {
    goto end; //Numeric
    }
    }

    // apps_v1beta1_deployment_status->conditions
    cJSON *conditions = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_deployment_statusJSON, "conditions");
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
        apps_v1beta1_deployment_condition_t *conditionsItem = apps_v1beta1_deployment_condition_parseFromJSON(conditions_local_nonprimitive);

        list_addElement(conditionsList, conditionsItem);
    }
    }

    // apps_v1beta1_deployment_status->observedGeneration
    cJSON *observedGeneration = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_deployment_statusJSON, "observedGeneration");
    if (observedGeneration) { 
    if(!cJSON_IsNumber(observedGeneration))
    {
    goto end; //Numeric
    }
    }

    // apps_v1beta1_deployment_status->readyReplicas
    cJSON *readyReplicas = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_deployment_statusJSON, "readyReplicas");
    if (readyReplicas) { 
    if(!cJSON_IsNumber(readyReplicas))
    {
    goto end; //Numeric
    }
    }

    // apps_v1beta1_deployment_status->replicas
    cJSON *replicas = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_deployment_statusJSON, "replicas");
    if (replicas) { 
    if(!cJSON_IsNumber(replicas))
    {
    goto end; //Numeric
    }
    }

    // apps_v1beta1_deployment_status->unavailableReplicas
    cJSON *unavailableReplicas = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_deployment_statusJSON, "unavailableReplicas");
    if (unavailableReplicas) { 
    if(!cJSON_IsNumber(unavailableReplicas))
    {
    goto end; //Numeric
    }
    }

    // apps_v1beta1_deployment_status->updatedReplicas
    cJSON *updatedReplicas = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_deployment_statusJSON, "updatedReplicas");
    if (updatedReplicas) { 
    if(!cJSON_IsNumber(updatedReplicas))
    {
    goto end; //Numeric
    }
    }


    apps_v1beta1_deployment_status_local_var = apps_v1beta1_deployment_status_create (
        availableReplicas ? availableReplicas->valuedouble : 0,
        collisionCount ? collisionCount->valuedouble : 0,
        conditions ? conditionsList : NULL,
        observedGeneration ? observedGeneration->valuedouble : 0,
        readyReplicas ? readyReplicas->valuedouble : 0,
        replicas ? replicas->valuedouble : 0,
        unavailableReplicas ? unavailableReplicas->valuedouble : 0,
        updatedReplicas ? updatedReplicas->valuedouble : 0
        );

    return apps_v1beta1_deployment_status_local_var;
end:
    return NULL;

}
