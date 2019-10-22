#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v2beta2_horizontal_pod_autoscaler_spec.h"



v2beta2_horizontal_pod_autoscaler_spec_t *v2beta2_horizontal_pod_autoscaler_spec_create(
    int maxReplicas,
    list_t *metrics,
    int minReplicas,
    v2beta2_cross_version_object_reference_t *scaleTargetRef
    ) {
	v2beta2_horizontal_pod_autoscaler_spec_t *v2beta2_horizontal_pod_autoscaler_spec_local_var = malloc(sizeof(v2beta2_horizontal_pod_autoscaler_spec_t));
    if (!v2beta2_horizontal_pod_autoscaler_spec_local_var) {
        return NULL;
    }
	v2beta2_horizontal_pod_autoscaler_spec_local_var->maxReplicas = maxReplicas;
	v2beta2_horizontal_pod_autoscaler_spec_local_var->metrics = metrics;
	v2beta2_horizontal_pod_autoscaler_spec_local_var->minReplicas = minReplicas;
	v2beta2_horizontal_pod_autoscaler_spec_local_var->scaleTargetRef = scaleTargetRef;

	return v2beta2_horizontal_pod_autoscaler_spec_local_var;
}


void v2beta2_horizontal_pod_autoscaler_spec_free(v2beta2_horizontal_pod_autoscaler_spec_t *v2beta2_horizontal_pod_autoscaler_spec) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, v2beta2_horizontal_pod_autoscaler_spec->metrics) {
		v2beta2_metric_spec_free(listEntry->data);
	}
	list_free(v2beta2_horizontal_pod_autoscaler_spec->metrics);
    v2beta2_cross_version_object_reference_free(v2beta2_horizontal_pod_autoscaler_spec->scaleTargetRef);
	free(v2beta2_horizontal_pod_autoscaler_spec);
}

cJSON *v2beta2_horizontal_pod_autoscaler_spec_convertToJSON(v2beta2_horizontal_pod_autoscaler_spec_t *v2beta2_horizontal_pod_autoscaler_spec) {
	cJSON *item = cJSON_CreateObject();

	// v2beta2_horizontal_pod_autoscaler_spec->maxReplicas
    if (!v2beta2_horizontal_pod_autoscaler_spec->maxReplicas) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "maxReplicas", v2beta2_horizontal_pod_autoscaler_spec->maxReplicas) == NULL) {
    goto fail; //Numeric
    }


	// v2beta2_horizontal_pod_autoscaler_spec->metrics
    if(v2beta2_horizontal_pod_autoscaler_spec->metrics) { 
    cJSON *metrics = cJSON_AddArrayToObject(item, "metrics");
    if(metrics == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *metricsListEntry;
    if (v2beta2_horizontal_pod_autoscaler_spec->metrics) {
    list_ForEach(metricsListEntry, v2beta2_horizontal_pod_autoscaler_spec->metrics) {
    cJSON *itemLocal = v2beta2_metric_spec_convertToJSON(metricsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(metrics, itemLocal);
    }
    }
     } 


	// v2beta2_horizontal_pod_autoscaler_spec->minReplicas
    if(v2beta2_horizontal_pod_autoscaler_spec->minReplicas) { 
    if(cJSON_AddNumberToObject(item, "minReplicas", v2beta2_horizontal_pod_autoscaler_spec->minReplicas) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v2beta2_horizontal_pod_autoscaler_spec->scaleTargetRef
    if (!v2beta2_horizontal_pod_autoscaler_spec->scaleTargetRef) {
        goto fail;
    }
    
    cJSON *scaleTargetRef_local_JSON = v2beta2_cross_version_object_reference_convertToJSON(v2beta2_horizontal_pod_autoscaler_spec->scaleTargetRef);
    if(scaleTargetRef_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "scaleTargetRef", scaleTargetRef_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v2beta2_horizontal_pod_autoscaler_spec_t *v2beta2_horizontal_pod_autoscaler_spec_parseFromJSON(cJSON *v2beta2_horizontal_pod_autoscaler_specJSON){

    v2beta2_horizontal_pod_autoscaler_spec_t *v2beta2_horizontal_pod_autoscaler_spec_local_var = NULL;

    // v2beta2_horizontal_pod_autoscaler_spec->maxReplicas
    cJSON *maxReplicas = cJSON_GetObjectItemCaseSensitive(v2beta2_horizontal_pod_autoscaler_specJSON, "maxReplicas");
    if (!maxReplicas) {
        goto end;
    }

    
    if(!cJSON_IsNumber(maxReplicas))
    {
    goto end; //Numeric
    }

    // v2beta2_horizontal_pod_autoscaler_spec->metrics
    cJSON *metrics = cJSON_GetObjectItemCaseSensitive(v2beta2_horizontal_pod_autoscaler_specJSON, "metrics");
    list_t *metricsList;
    if (metrics) { 
    cJSON *metrics_local_nonprimitive;
    if(!cJSON_IsArray(metrics)){
        goto end; //nonprimitive container
    }

    metricsList = list_create();

    cJSON_ArrayForEach(metrics_local_nonprimitive,metrics )
    {
        if(!cJSON_IsObject(metrics_local_nonprimitive)){
            goto end;
        }
        v2beta2_metric_spec_t *metricsItem = v2beta2_metric_spec_parseFromJSON(metrics_local_nonprimitive);

        list_addElement(metricsList, metricsItem);
    }
    }

    // v2beta2_horizontal_pod_autoscaler_spec->minReplicas
    cJSON *minReplicas = cJSON_GetObjectItemCaseSensitive(v2beta2_horizontal_pod_autoscaler_specJSON, "minReplicas");
    if (minReplicas) { 
    if(!cJSON_IsNumber(minReplicas))
    {
    goto end; //Numeric
    }
    }

    // v2beta2_horizontal_pod_autoscaler_spec->scaleTargetRef
    cJSON *scaleTargetRef = cJSON_GetObjectItemCaseSensitive(v2beta2_horizontal_pod_autoscaler_specJSON, "scaleTargetRef");
    if (!scaleTargetRef) {
        goto end;
    }

    v2beta2_cross_version_object_reference_t *scaleTargetRef_local_nonprim = NULL;
    
    scaleTargetRef_local_nonprim = v2beta2_cross_version_object_reference_parseFromJSON(scaleTargetRef); //nonprimitive


    v2beta2_horizontal_pod_autoscaler_spec_local_var = v2beta2_horizontal_pod_autoscaler_spec_create (
        maxReplicas->valuedouble,
        metrics ? metricsList : NULL,
        minReplicas ? minReplicas->valuedouble : 0,
        scaleTargetRef_local_nonprim
        );

    return v2beta2_horizontal_pod_autoscaler_spec_local_var;
end:
    return NULL;

}
