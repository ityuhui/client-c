#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v2beta2_horizontal_pod_autoscaler_status.h"



v2beta2_horizontal_pod_autoscaler_status_t *v2beta2_horizontal_pod_autoscaler_status_create(
    list_t *conditions,
    list_t *currentMetrics,
    int currentReplicas,
    int desiredReplicas,
    char *lastScaleTime,
    long observedGeneration
    ) {
	v2beta2_horizontal_pod_autoscaler_status_t *v2beta2_horizontal_pod_autoscaler_status_local_var = malloc(sizeof(v2beta2_horizontal_pod_autoscaler_status_t));
    if (!v2beta2_horizontal_pod_autoscaler_status_local_var) {
        return NULL;
    }
	v2beta2_horizontal_pod_autoscaler_status_local_var->conditions = conditions;
	v2beta2_horizontal_pod_autoscaler_status_local_var->currentMetrics = currentMetrics;
	v2beta2_horizontal_pod_autoscaler_status_local_var->currentReplicas = currentReplicas;
	v2beta2_horizontal_pod_autoscaler_status_local_var->desiredReplicas = desiredReplicas;
	v2beta2_horizontal_pod_autoscaler_status_local_var->lastScaleTime = lastScaleTime;
	v2beta2_horizontal_pod_autoscaler_status_local_var->observedGeneration = observedGeneration;

	return v2beta2_horizontal_pod_autoscaler_status_local_var;
}


void v2beta2_horizontal_pod_autoscaler_status_free(v2beta2_horizontal_pod_autoscaler_status_t *v2beta2_horizontal_pod_autoscaler_status) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, v2beta2_horizontal_pod_autoscaler_status->conditions) {
		v2beta2_horizontal_pod_autoscaler_condition_free(listEntry->data);
	}
	list_free(v2beta2_horizontal_pod_autoscaler_status->conditions);
	list_ForEach(listEntry, v2beta2_horizontal_pod_autoscaler_status->currentMetrics) {
		v2beta2_metric_status_free(listEntry->data);
	}
	list_free(v2beta2_horizontal_pod_autoscaler_status->currentMetrics);
    free(v2beta2_horizontal_pod_autoscaler_status->lastScaleTime);
	free(v2beta2_horizontal_pod_autoscaler_status);
}

cJSON *v2beta2_horizontal_pod_autoscaler_status_convertToJSON(v2beta2_horizontal_pod_autoscaler_status_t *v2beta2_horizontal_pod_autoscaler_status) {
	cJSON *item = cJSON_CreateObject();

	// v2beta2_horizontal_pod_autoscaler_status->conditions
    if (!v2beta2_horizontal_pod_autoscaler_status->conditions) {
        goto fail;
    }
    
    cJSON *conditions = cJSON_AddArrayToObject(item, "conditions");
    if(conditions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *conditionsListEntry;
    if (v2beta2_horizontal_pod_autoscaler_status->conditions) {
    list_ForEach(conditionsListEntry, v2beta2_horizontal_pod_autoscaler_status->conditions) {
    cJSON *itemLocal = v2beta2_horizontal_pod_autoscaler_condition_convertToJSON(conditionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(conditions, itemLocal);
    }
    }


	// v2beta2_horizontal_pod_autoscaler_status->currentMetrics
    if(v2beta2_horizontal_pod_autoscaler_status->currentMetrics) { 
    cJSON *currentMetrics = cJSON_AddArrayToObject(item, "currentMetrics");
    if(currentMetrics == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *currentMetricsListEntry;
    if (v2beta2_horizontal_pod_autoscaler_status->currentMetrics) {
    list_ForEach(currentMetricsListEntry, v2beta2_horizontal_pod_autoscaler_status->currentMetrics) {
    cJSON *itemLocal = v2beta2_metric_status_convertToJSON(currentMetricsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(currentMetrics, itemLocal);
    }
    }
     } 


	// v2beta2_horizontal_pod_autoscaler_status->currentReplicas
    if (!v2beta2_horizontal_pod_autoscaler_status->currentReplicas) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "currentReplicas", v2beta2_horizontal_pod_autoscaler_status->currentReplicas) == NULL) {
    goto fail; //Numeric
    }


	// v2beta2_horizontal_pod_autoscaler_status->desiredReplicas
    if (!v2beta2_horizontal_pod_autoscaler_status->desiredReplicas) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "desiredReplicas", v2beta2_horizontal_pod_autoscaler_status->desiredReplicas) == NULL) {
    goto fail; //Numeric
    }


	// v2beta2_horizontal_pod_autoscaler_status->lastScaleTime
    if(v2beta2_horizontal_pod_autoscaler_status->lastScaleTime) { 
    if(cJSON_AddStringToObject(item, "lastScaleTime", v2beta2_horizontal_pod_autoscaler_status->lastScaleTime) == NULL) {
    goto fail; //Date-Time
    }
     } 


	// v2beta2_horizontal_pod_autoscaler_status->observedGeneration
    if(v2beta2_horizontal_pod_autoscaler_status->observedGeneration) { 
    if(cJSON_AddNumberToObject(item, "observedGeneration", v2beta2_horizontal_pod_autoscaler_status->observedGeneration) == NULL) {
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

v2beta2_horizontal_pod_autoscaler_status_t *v2beta2_horizontal_pod_autoscaler_status_parseFromJSON(cJSON *v2beta2_horizontal_pod_autoscaler_statusJSON){

    v2beta2_horizontal_pod_autoscaler_status_t *v2beta2_horizontal_pod_autoscaler_status_local_var = NULL;

    // v2beta2_horizontal_pod_autoscaler_status->conditions
    cJSON *conditions = cJSON_GetObjectItemCaseSensitive(v2beta2_horizontal_pod_autoscaler_statusJSON, "conditions");
    if (!conditions) {
        goto end;
    }

    list_t *conditionsList;
    
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
        v2beta2_horizontal_pod_autoscaler_condition_t *conditionsItem = v2beta2_horizontal_pod_autoscaler_condition_parseFromJSON(conditions_local_nonprimitive);

        list_addElement(conditionsList, conditionsItem);
    }

    // v2beta2_horizontal_pod_autoscaler_status->currentMetrics
    cJSON *currentMetrics = cJSON_GetObjectItemCaseSensitive(v2beta2_horizontal_pod_autoscaler_statusJSON, "currentMetrics");
    list_t *currentMetricsList;
    if (currentMetrics) { 
    cJSON *currentMetrics_local_nonprimitive;
    if(!cJSON_IsArray(currentMetrics)){
        goto end; //nonprimitive container
    }

    currentMetricsList = list_create();

    cJSON_ArrayForEach(currentMetrics_local_nonprimitive,currentMetrics )
    {
        if(!cJSON_IsObject(currentMetrics_local_nonprimitive)){
            goto end;
        }
        v2beta2_metric_status_t *currentMetricsItem = v2beta2_metric_status_parseFromJSON(currentMetrics_local_nonprimitive);

        list_addElement(currentMetricsList, currentMetricsItem);
    }
    }

    // v2beta2_horizontal_pod_autoscaler_status->currentReplicas
    cJSON *currentReplicas = cJSON_GetObjectItemCaseSensitive(v2beta2_horizontal_pod_autoscaler_statusJSON, "currentReplicas");
    if (!currentReplicas) {
        goto end;
    }

    
    if(!cJSON_IsNumber(currentReplicas))
    {
    goto end; //Numeric
    }

    // v2beta2_horizontal_pod_autoscaler_status->desiredReplicas
    cJSON *desiredReplicas = cJSON_GetObjectItemCaseSensitive(v2beta2_horizontal_pod_autoscaler_statusJSON, "desiredReplicas");
    if (!desiredReplicas) {
        goto end;
    }

    
    if(!cJSON_IsNumber(desiredReplicas))
    {
    goto end; //Numeric
    }

    // v2beta2_horizontal_pod_autoscaler_status->lastScaleTime
    cJSON *lastScaleTime = cJSON_GetObjectItemCaseSensitive(v2beta2_horizontal_pod_autoscaler_statusJSON, "lastScaleTime");
    if (lastScaleTime) { 
    if(!cJSON_IsString(lastScaleTime))
    {
    goto end; //DateTime
    }
    }

    // v2beta2_horizontal_pod_autoscaler_status->observedGeneration
    cJSON *observedGeneration = cJSON_GetObjectItemCaseSensitive(v2beta2_horizontal_pod_autoscaler_statusJSON, "observedGeneration");
    if (observedGeneration) { 
    if(!cJSON_IsNumber(observedGeneration))
    {
    goto end; //Numeric
    }
    }


    v2beta2_horizontal_pod_autoscaler_status_local_var = v2beta2_horizontal_pod_autoscaler_status_create (
        conditionsList,
        currentMetrics ? currentMetricsList : NULL,
        currentReplicas->valuedouble,
        desiredReplicas->valuedouble,
        lastScaleTime ? strdup(lastScaleTime->valuestring) : NULL,
        observedGeneration ? observedGeneration->valuedouble : 0
        );

    return v2beta2_horizontal_pod_autoscaler_status_local_var;
end:
    return NULL;

}
