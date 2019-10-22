#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_horizontal_pod_autoscaler_status.h"



v1_horizontal_pod_autoscaler_status_t *v1_horizontal_pod_autoscaler_status_create(
    int currentCPUUtilizationPercentage,
    int currentReplicas,
    int desiredReplicas,
    char *lastScaleTime,
    long observedGeneration
    ) {
	v1_horizontal_pod_autoscaler_status_t *v1_horizontal_pod_autoscaler_status_local_var = malloc(sizeof(v1_horizontal_pod_autoscaler_status_t));
    if (!v1_horizontal_pod_autoscaler_status_local_var) {
        return NULL;
    }
	v1_horizontal_pod_autoscaler_status_local_var->currentCPUUtilizationPercentage = currentCPUUtilizationPercentage;
	v1_horizontal_pod_autoscaler_status_local_var->currentReplicas = currentReplicas;
	v1_horizontal_pod_autoscaler_status_local_var->desiredReplicas = desiredReplicas;
	v1_horizontal_pod_autoscaler_status_local_var->lastScaleTime = lastScaleTime;
	v1_horizontal_pod_autoscaler_status_local_var->observedGeneration = observedGeneration;

	return v1_horizontal_pod_autoscaler_status_local_var;
}


void v1_horizontal_pod_autoscaler_status_free(v1_horizontal_pod_autoscaler_status_t *v1_horizontal_pod_autoscaler_status) {
    listEntry_t *listEntry;
    free(v1_horizontal_pod_autoscaler_status->lastScaleTime);
	free(v1_horizontal_pod_autoscaler_status);
}

cJSON *v1_horizontal_pod_autoscaler_status_convertToJSON(v1_horizontal_pod_autoscaler_status_t *v1_horizontal_pod_autoscaler_status) {
	cJSON *item = cJSON_CreateObject();

	// v1_horizontal_pod_autoscaler_status->currentCPUUtilizationPercentage
    if(v1_horizontal_pod_autoscaler_status->currentCPUUtilizationPercentage) { 
    if(cJSON_AddNumberToObject(item, "currentCPUUtilizationPercentage", v1_horizontal_pod_autoscaler_status->currentCPUUtilizationPercentage) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1_horizontal_pod_autoscaler_status->currentReplicas
    if (!v1_horizontal_pod_autoscaler_status->currentReplicas) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "currentReplicas", v1_horizontal_pod_autoscaler_status->currentReplicas) == NULL) {
    goto fail; //Numeric
    }


	// v1_horizontal_pod_autoscaler_status->desiredReplicas
    if (!v1_horizontal_pod_autoscaler_status->desiredReplicas) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "desiredReplicas", v1_horizontal_pod_autoscaler_status->desiredReplicas) == NULL) {
    goto fail; //Numeric
    }


	// v1_horizontal_pod_autoscaler_status->lastScaleTime
    if(v1_horizontal_pod_autoscaler_status->lastScaleTime) { 
    if(cJSON_AddStringToObject(item, "lastScaleTime", v1_horizontal_pod_autoscaler_status->lastScaleTime) == NULL) {
    goto fail; //Date-Time
    }
     } 


	// v1_horizontal_pod_autoscaler_status->observedGeneration
    if(v1_horizontal_pod_autoscaler_status->observedGeneration) { 
    if(cJSON_AddNumberToObject(item, "observedGeneration", v1_horizontal_pod_autoscaler_status->observedGeneration) == NULL) {
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

v1_horizontal_pod_autoscaler_status_t *v1_horizontal_pod_autoscaler_status_parseFromJSON(cJSON *v1_horizontal_pod_autoscaler_statusJSON){

    v1_horizontal_pod_autoscaler_status_t *v1_horizontal_pod_autoscaler_status_local_var = NULL;

    // v1_horizontal_pod_autoscaler_status->currentCPUUtilizationPercentage
    cJSON *currentCPUUtilizationPercentage = cJSON_GetObjectItemCaseSensitive(v1_horizontal_pod_autoscaler_statusJSON, "currentCPUUtilizationPercentage");
    if (currentCPUUtilizationPercentage) { 
    if(!cJSON_IsNumber(currentCPUUtilizationPercentage))
    {
    goto end; //Numeric
    }
    }

    // v1_horizontal_pod_autoscaler_status->currentReplicas
    cJSON *currentReplicas = cJSON_GetObjectItemCaseSensitive(v1_horizontal_pod_autoscaler_statusJSON, "currentReplicas");
    if (!currentReplicas) {
        goto end;
    }

    
    if(!cJSON_IsNumber(currentReplicas))
    {
    goto end; //Numeric
    }

    // v1_horizontal_pod_autoscaler_status->desiredReplicas
    cJSON *desiredReplicas = cJSON_GetObjectItemCaseSensitive(v1_horizontal_pod_autoscaler_statusJSON, "desiredReplicas");
    if (!desiredReplicas) {
        goto end;
    }

    
    if(!cJSON_IsNumber(desiredReplicas))
    {
    goto end; //Numeric
    }

    // v1_horizontal_pod_autoscaler_status->lastScaleTime
    cJSON *lastScaleTime = cJSON_GetObjectItemCaseSensitive(v1_horizontal_pod_autoscaler_statusJSON, "lastScaleTime");
    if (lastScaleTime) { 
    if(!cJSON_IsString(lastScaleTime))
    {
    goto end; //DateTime
    }
    }

    // v1_horizontal_pod_autoscaler_status->observedGeneration
    cJSON *observedGeneration = cJSON_GetObjectItemCaseSensitive(v1_horizontal_pod_autoscaler_statusJSON, "observedGeneration");
    if (observedGeneration) { 
    if(!cJSON_IsNumber(observedGeneration))
    {
    goto end; //Numeric
    }
    }


    v1_horizontal_pod_autoscaler_status_local_var = v1_horizontal_pod_autoscaler_status_create (
        currentCPUUtilizationPercentage ? currentCPUUtilizationPercentage->valuedouble : 0,
        currentReplicas->valuedouble,
        desiredReplicas->valuedouble,
        lastScaleTime ? strdup(lastScaleTime->valuestring) : NULL,
        observedGeneration ? observedGeneration->valuedouble : 0
        );

    return v1_horizontal_pod_autoscaler_status_local_var;
end:
    return NULL;

}
