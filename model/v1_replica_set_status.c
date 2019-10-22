#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_replica_set_status.h"



v1_replica_set_status_t *v1_replica_set_status_create(
    int availableReplicas,
    list_t *conditions,
    int fullyLabeledReplicas,
    long observedGeneration,
    int readyReplicas,
    int replicas
    ) {
	v1_replica_set_status_t *v1_replica_set_status_local_var = malloc(sizeof(v1_replica_set_status_t));
    if (!v1_replica_set_status_local_var) {
        return NULL;
    }
	v1_replica_set_status_local_var->availableReplicas = availableReplicas;
	v1_replica_set_status_local_var->conditions = conditions;
	v1_replica_set_status_local_var->fullyLabeledReplicas = fullyLabeledReplicas;
	v1_replica_set_status_local_var->observedGeneration = observedGeneration;
	v1_replica_set_status_local_var->readyReplicas = readyReplicas;
	v1_replica_set_status_local_var->replicas = replicas;

	return v1_replica_set_status_local_var;
}


void v1_replica_set_status_free(v1_replica_set_status_t *v1_replica_set_status) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, v1_replica_set_status->conditions) {
		v1_replica_set_condition_free(listEntry->data);
	}
	list_free(v1_replica_set_status->conditions);
	free(v1_replica_set_status);
}

cJSON *v1_replica_set_status_convertToJSON(v1_replica_set_status_t *v1_replica_set_status) {
	cJSON *item = cJSON_CreateObject();

	// v1_replica_set_status->availableReplicas
    if(v1_replica_set_status->availableReplicas) { 
    if(cJSON_AddNumberToObject(item, "availableReplicas", v1_replica_set_status->availableReplicas) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1_replica_set_status->conditions
    if(v1_replica_set_status->conditions) { 
    cJSON *conditions = cJSON_AddArrayToObject(item, "conditions");
    if(conditions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *conditionsListEntry;
    if (v1_replica_set_status->conditions) {
    list_ForEach(conditionsListEntry, v1_replica_set_status->conditions) {
    cJSON *itemLocal = v1_replica_set_condition_convertToJSON(conditionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(conditions, itemLocal);
    }
    }
     } 


	// v1_replica_set_status->fullyLabeledReplicas
    if(v1_replica_set_status->fullyLabeledReplicas) { 
    if(cJSON_AddNumberToObject(item, "fullyLabeledReplicas", v1_replica_set_status->fullyLabeledReplicas) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1_replica_set_status->observedGeneration
    if(v1_replica_set_status->observedGeneration) { 
    if(cJSON_AddNumberToObject(item, "observedGeneration", v1_replica_set_status->observedGeneration) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1_replica_set_status->readyReplicas
    if(v1_replica_set_status->readyReplicas) { 
    if(cJSON_AddNumberToObject(item, "readyReplicas", v1_replica_set_status->readyReplicas) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1_replica_set_status->replicas
    if (!v1_replica_set_status->replicas) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "replicas", v1_replica_set_status->replicas) == NULL) {
    goto fail; //Numeric
    }

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1_replica_set_status_t *v1_replica_set_status_parseFromJSON(cJSON *v1_replica_set_statusJSON){

    v1_replica_set_status_t *v1_replica_set_status_local_var = NULL;

    // v1_replica_set_status->availableReplicas
    cJSON *availableReplicas = cJSON_GetObjectItemCaseSensitive(v1_replica_set_statusJSON, "availableReplicas");
    if (availableReplicas) { 
    if(!cJSON_IsNumber(availableReplicas))
    {
    goto end; //Numeric
    }
    }

    // v1_replica_set_status->conditions
    cJSON *conditions = cJSON_GetObjectItemCaseSensitive(v1_replica_set_statusJSON, "conditions");
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
        v1_replica_set_condition_t *conditionsItem = v1_replica_set_condition_parseFromJSON(conditions_local_nonprimitive);

        list_addElement(conditionsList, conditionsItem);
    }
    }

    // v1_replica_set_status->fullyLabeledReplicas
    cJSON *fullyLabeledReplicas = cJSON_GetObjectItemCaseSensitive(v1_replica_set_statusJSON, "fullyLabeledReplicas");
    if (fullyLabeledReplicas) { 
    if(!cJSON_IsNumber(fullyLabeledReplicas))
    {
    goto end; //Numeric
    }
    }

    // v1_replica_set_status->observedGeneration
    cJSON *observedGeneration = cJSON_GetObjectItemCaseSensitive(v1_replica_set_statusJSON, "observedGeneration");
    if (observedGeneration) { 
    if(!cJSON_IsNumber(observedGeneration))
    {
    goto end; //Numeric
    }
    }

    // v1_replica_set_status->readyReplicas
    cJSON *readyReplicas = cJSON_GetObjectItemCaseSensitive(v1_replica_set_statusJSON, "readyReplicas");
    if (readyReplicas) { 
    if(!cJSON_IsNumber(readyReplicas))
    {
    goto end; //Numeric
    }
    }

    // v1_replica_set_status->replicas
    cJSON *replicas = cJSON_GetObjectItemCaseSensitive(v1_replica_set_statusJSON, "replicas");
    if (!replicas) {
        goto end;
    }

    
    if(!cJSON_IsNumber(replicas))
    {
    goto end; //Numeric
    }


    v1_replica_set_status_local_var = v1_replica_set_status_create (
        availableReplicas ? availableReplicas->valuedouble : 0,
        conditions ? conditionsList : NULL,
        fullyLabeledReplicas ? fullyLabeledReplicas->valuedouble : 0,
        observedGeneration ? observedGeneration->valuedouble : 0,
        readyReplicas ? readyReplicas->valuedouble : 0,
        replicas->valuedouble
        );

    return v1_replica_set_status_local_var;
end:
    return NULL;

}
