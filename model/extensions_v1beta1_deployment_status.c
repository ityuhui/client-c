#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "extensions_v1beta1_deployment_status.h"



extensions_v1beta1_deployment_status_t *extensions_v1beta1_deployment_status_create(
    int availableReplicas,
    int collisionCount,
    list_t *conditions,
    long observedGeneration,
    int readyReplicas,
    int replicas,
    int unavailableReplicas,
    int updatedReplicas
    ) {
	extensions_v1beta1_deployment_status_t *extensions_v1beta1_deployment_status_local_var = malloc(sizeof(extensions_v1beta1_deployment_status_t));
    if (!extensions_v1beta1_deployment_status_local_var) {
        return NULL;
    }
	extensions_v1beta1_deployment_status_local_var->availableReplicas = availableReplicas;
	extensions_v1beta1_deployment_status_local_var->collisionCount = collisionCount;
	extensions_v1beta1_deployment_status_local_var->conditions = conditions;
	extensions_v1beta1_deployment_status_local_var->observedGeneration = observedGeneration;
	extensions_v1beta1_deployment_status_local_var->readyReplicas = readyReplicas;
	extensions_v1beta1_deployment_status_local_var->replicas = replicas;
	extensions_v1beta1_deployment_status_local_var->unavailableReplicas = unavailableReplicas;
	extensions_v1beta1_deployment_status_local_var->updatedReplicas = updatedReplicas;

	return extensions_v1beta1_deployment_status_local_var;
}


void extensions_v1beta1_deployment_status_free(extensions_v1beta1_deployment_status_t *extensions_v1beta1_deployment_status) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, extensions_v1beta1_deployment_status->conditions) {
		extensions_v1beta1_deployment_condition_free(listEntry->data);
	}
	list_free(extensions_v1beta1_deployment_status->conditions);
	free(extensions_v1beta1_deployment_status);
}

cJSON *extensions_v1beta1_deployment_status_convertToJSON(extensions_v1beta1_deployment_status_t *extensions_v1beta1_deployment_status) {
	cJSON *item = cJSON_CreateObject();

	// extensions_v1beta1_deployment_status->availableReplicas
    if(extensions_v1beta1_deployment_status->availableReplicas) { 
    if(cJSON_AddNumberToObject(item, "availableReplicas", extensions_v1beta1_deployment_status->availableReplicas) == NULL) {
    goto fail; //Numeric
    }
     } 


	// extensions_v1beta1_deployment_status->collisionCount
    if(extensions_v1beta1_deployment_status->collisionCount) { 
    if(cJSON_AddNumberToObject(item, "collisionCount", extensions_v1beta1_deployment_status->collisionCount) == NULL) {
    goto fail; //Numeric
    }
     } 


	// extensions_v1beta1_deployment_status->conditions
    if(extensions_v1beta1_deployment_status->conditions) { 
    cJSON *conditions = cJSON_AddArrayToObject(item, "conditions");
    if(conditions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *conditionsListEntry;
    if (extensions_v1beta1_deployment_status->conditions) {
    list_ForEach(conditionsListEntry, extensions_v1beta1_deployment_status->conditions) {
    cJSON *itemLocal = extensions_v1beta1_deployment_condition_convertToJSON(conditionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(conditions, itemLocal);
    }
    }
     } 


	// extensions_v1beta1_deployment_status->observedGeneration
    if(extensions_v1beta1_deployment_status->observedGeneration) { 
    if(cJSON_AddNumberToObject(item, "observedGeneration", extensions_v1beta1_deployment_status->observedGeneration) == NULL) {
    goto fail; //Numeric
    }
     } 


	// extensions_v1beta1_deployment_status->readyReplicas
    if(extensions_v1beta1_deployment_status->readyReplicas) { 
    if(cJSON_AddNumberToObject(item, "readyReplicas", extensions_v1beta1_deployment_status->readyReplicas) == NULL) {
    goto fail; //Numeric
    }
     } 


	// extensions_v1beta1_deployment_status->replicas
    if(extensions_v1beta1_deployment_status->replicas) { 
    if(cJSON_AddNumberToObject(item, "replicas", extensions_v1beta1_deployment_status->replicas) == NULL) {
    goto fail; //Numeric
    }
     } 


	// extensions_v1beta1_deployment_status->unavailableReplicas
    if(extensions_v1beta1_deployment_status->unavailableReplicas) { 
    if(cJSON_AddNumberToObject(item, "unavailableReplicas", extensions_v1beta1_deployment_status->unavailableReplicas) == NULL) {
    goto fail; //Numeric
    }
     } 


	// extensions_v1beta1_deployment_status->updatedReplicas
    if(extensions_v1beta1_deployment_status->updatedReplicas) { 
    if(cJSON_AddNumberToObject(item, "updatedReplicas", extensions_v1beta1_deployment_status->updatedReplicas) == NULL) {
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

extensions_v1beta1_deployment_status_t *extensions_v1beta1_deployment_status_parseFromJSON(cJSON *extensions_v1beta1_deployment_statusJSON){

    extensions_v1beta1_deployment_status_t *extensions_v1beta1_deployment_status_local_var = NULL;

    // extensions_v1beta1_deployment_status->availableReplicas
    cJSON *availableReplicas = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_deployment_statusJSON, "availableReplicas");
    if (availableReplicas) { 
    if(!cJSON_IsNumber(availableReplicas))
    {
    goto end; //Numeric
    }
    }

    // extensions_v1beta1_deployment_status->collisionCount
    cJSON *collisionCount = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_deployment_statusJSON, "collisionCount");
    if (collisionCount) { 
    if(!cJSON_IsNumber(collisionCount))
    {
    goto end; //Numeric
    }
    }

    // extensions_v1beta1_deployment_status->conditions
    cJSON *conditions = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_deployment_statusJSON, "conditions");
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
        extensions_v1beta1_deployment_condition_t *conditionsItem = extensions_v1beta1_deployment_condition_parseFromJSON(conditions_local_nonprimitive);

        list_addElement(conditionsList, conditionsItem);
    }
    }

    // extensions_v1beta1_deployment_status->observedGeneration
    cJSON *observedGeneration = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_deployment_statusJSON, "observedGeneration");
    if (observedGeneration) { 
    if(!cJSON_IsNumber(observedGeneration))
    {
    goto end; //Numeric
    }
    }

    // extensions_v1beta1_deployment_status->readyReplicas
    cJSON *readyReplicas = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_deployment_statusJSON, "readyReplicas");
    if (readyReplicas) { 
    if(!cJSON_IsNumber(readyReplicas))
    {
    goto end; //Numeric
    }
    }

    // extensions_v1beta1_deployment_status->replicas
    cJSON *replicas = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_deployment_statusJSON, "replicas");
    if (replicas) { 
    if(!cJSON_IsNumber(replicas))
    {
    goto end; //Numeric
    }
    }

    // extensions_v1beta1_deployment_status->unavailableReplicas
    cJSON *unavailableReplicas = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_deployment_statusJSON, "unavailableReplicas");
    if (unavailableReplicas) { 
    if(!cJSON_IsNumber(unavailableReplicas))
    {
    goto end; //Numeric
    }
    }

    // extensions_v1beta1_deployment_status->updatedReplicas
    cJSON *updatedReplicas = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_deployment_statusJSON, "updatedReplicas");
    if (updatedReplicas) { 
    if(!cJSON_IsNumber(updatedReplicas))
    {
    goto end; //Numeric
    }
    }


    extensions_v1beta1_deployment_status_local_var = extensions_v1beta1_deployment_status_create (
        availableReplicas ? availableReplicas->valuedouble : 0,
        collisionCount ? collisionCount->valuedouble : 0,
        conditions ? conditionsList : NULL,
        observedGeneration ? observedGeneration->valuedouble : 0,
        readyReplicas ? readyReplicas->valuedouble : 0,
        replicas ? replicas->valuedouble : 0,
        unavailableReplicas ? unavailableReplicas->valuedouble : 0,
        updatedReplicas ? updatedReplicas->valuedouble : 0
        );

    return extensions_v1beta1_deployment_status_local_var;
end:
    return NULL;

}
