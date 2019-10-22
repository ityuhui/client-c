#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_horizontal_pod_autoscaler_spec.h"



v1_horizontal_pod_autoscaler_spec_t *v1_horizontal_pod_autoscaler_spec_create(
    int maxReplicas,
    int minReplicas,
    v1_cross_version_object_reference_t *scaleTargetRef,
    int targetCPUUtilizationPercentage
    ) {
	v1_horizontal_pod_autoscaler_spec_t *v1_horizontal_pod_autoscaler_spec_local_var = malloc(sizeof(v1_horizontal_pod_autoscaler_spec_t));
    if (!v1_horizontal_pod_autoscaler_spec_local_var) {
        return NULL;
    }
	v1_horizontal_pod_autoscaler_spec_local_var->maxReplicas = maxReplicas;
	v1_horizontal_pod_autoscaler_spec_local_var->minReplicas = minReplicas;
	v1_horizontal_pod_autoscaler_spec_local_var->scaleTargetRef = scaleTargetRef;
	v1_horizontal_pod_autoscaler_spec_local_var->targetCPUUtilizationPercentage = targetCPUUtilizationPercentage;

	return v1_horizontal_pod_autoscaler_spec_local_var;
}


void v1_horizontal_pod_autoscaler_spec_free(v1_horizontal_pod_autoscaler_spec_t *v1_horizontal_pod_autoscaler_spec) {
    listEntry_t *listEntry;
    v1_cross_version_object_reference_free(v1_horizontal_pod_autoscaler_spec->scaleTargetRef);
	free(v1_horizontal_pod_autoscaler_spec);
}

cJSON *v1_horizontal_pod_autoscaler_spec_convertToJSON(v1_horizontal_pod_autoscaler_spec_t *v1_horizontal_pod_autoscaler_spec) {
	cJSON *item = cJSON_CreateObject();

	// v1_horizontal_pod_autoscaler_spec->maxReplicas
    if (!v1_horizontal_pod_autoscaler_spec->maxReplicas) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "maxReplicas", v1_horizontal_pod_autoscaler_spec->maxReplicas) == NULL) {
    goto fail; //Numeric
    }


	// v1_horizontal_pod_autoscaler_spec->minReplicas
    if(v1_horizontal_pod_autoscaler_spec->minReplicas) { 
    if(cJSON_AddNumberToObject(item, "minReplicas", v1_horizontal_pod_autoscaler_spec->minReplicas) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1_horizontal_pod_autoscaler_spec->scaleTargetRef
    if (!v1_horizontal_pod_autoscaler_spec->scaleTargetRef) {
        goto fail;
    }
    
    cJSON *scaleTargetRef_local_JSON = v1_cross_version_object_reference_convertToJSON(v1_horizontal_pod_autoscaler_spec->scaleTargetRef);
    if(scaleTargetRef_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "scaleTargetRef", scaleTargetRef_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


	// v1_horizontal_pod_autoscaler_spec->targetCPUUtilizationPercentage
    if(v1_horizontal_pod_autoscaler_spec->targetCPUUtilizationPercentage) { 
    if(cJSON_AddNumberToObject(item, "targetCPUUtilizationPercentage", v1_horizontal_pod_autoscaler_spec->targetCPUUtilizationPercentage) == NULL) {
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

v1_horizontal_pod_autoscaler_spec_t *v1_horizontal_pod_autoscaler_spec_parseFromJSON(cJSON *v1_horizontal_pod_autoscaler_specJSON){

    v1_horizontal_pod_autoscaler_spec_t *v1_horizontal_pod_autoscaler_spec_local_var = NULL;

    // v1_horizontal_pod_autoscaler_spec->maxReplicas
    cJSON *maxReplicas = cJSON_GetObjectItemCaseSensitive(v1_horizontal_pod_autoscaler_specJSON, "maxReplicas");
    if (!maxReplicas) {
        goto end;
    }

    
    if(!cJSON_IsNumber(maxReplicas))
    {
    goto end; //Numeric
    }

    // v1_horizontal_pod_autoscaler_spec->minReplicas
    cJSON *minReplicas = cJSON_GetObjectItemCaseSensitive(v1_horizontal_pod_autoscaler_specJSON, "minReplicas");
    if (minReplicas) { 
    if(!cJSON_IsNumber(minReplicas))
    {
    goto end; //Numeric
    }
    }

    // v1_horizontal_pod_autoscaler_spec->scaleTargetRef
    cJSON *scaleTargetRef = cJSON_GetObjectItemCaseSensitive(v1_horizontal_pod_autoscaler_specJSON, "scaleTargetRef");
    if (!scaleTargetRef) {
        goto end;
    }

    v1_cross_version_object_reference_t *scaleTargetRef_local_nonprim = NULL;
    
    scaleTargetRef_local_nonprim = v1_cross_version_object_reference_parseFromJSON(scaleTargetRef); //nonprimitive

    // v1_horizontal_pod_autoscaler_spec->targetCPUUtilizationPercentage
    cJSON *targetCPUUtilizationPercentage = cJSON_GetObjectItemCaseSensitive(v1_horizontal_pod_autoscaler_specJSON, "targetCPUUtilizationPercentage");
    if (targetCPUUtilizationPercentage) { 
    if(!cJSON_IsNumber(targetCPUUtilizationPercentage))
    {
    goto end; //Numeric
    }
    }


    v1_horizontal_pod_autoscaler_spec_local_var = v1_horizontal_pod_autoscaler_spec_create (
        maxReplicas->valuedouble,
        minReplicas ? minReplicas->valuedouble : 0,
        scaleTargetRef_local_nonprim,
        targetCPUUtilizationPercentage ? targetCPUUtilizationPercentage->valuedouble : 0
        );

    return v1_horizontal_pod_autoscaler_spec_local_var;
end:
    return NULL;

}
