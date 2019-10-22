#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v2beta1_object_metric_status.h"



v2beta1_object_metric_status_t *v2beta1_object_metric_status_create(
    char *averageValue,
    char *currentValue,
    char *metricName,
    v1_label_selector_t *selector,
    v2beta1_cross_version_object_reference_t *target
    ) {
	v2beta1_object_metric_status_t *v2beta1_object_metric_status_local_var = malloc(sizeof(v2beta1_object_metric_status_t));
    if (!v2beta1_object_metric_status_local_var) {
        return NULL;
    }
	v2beta1_object_metric_status_local_var->averageValue = averageValue;
	v2beta1_object_metric_status_local_var->currentValue = currentValue;
	v2beta1_object_metric_status_local_var->metricName = metricName;
	v2beta1_object_metric_status_local_var->selector = selector;
	v2beta1_object_metric_status_local_var->target = target;

	return v2beta1_object_metric_status_local_var;
}


void v2beta1_object_metric_status_free(v2beta1_object_metric_status_t *v2beta1_object_metric_status) {
    listEntry_t *listEntry;
    free(v2beta1_object_metric_status->averageValue);
    free(v2beta1_object_metric_status->currentValue);
    free(v2beta1_object_metric_status->metricName);
    v1_label_selector_free(v2beta1_object_metric_status->selector);
    v2beta1_cross_version_object_reference_free(v2beta1_object_metric_status->target);
	free(v2beta1_object_metric_status);
}

cJSON *v2beta1_object_metric_status_convertToJSON(v2beta1_object_metric_status_t *v2beta1_object_metric_status) {
	cJSON *item = cJSON_CreateObject();

	// v2beta1_object_metric_status->averageValue
    if(v2beta1_object_metric_status->averageValue) { 
    if(cJSON_AddStringToObject(item, "averageValue", v2beta1_object_metric_status->averageValue) == NULL) {
    goto fail; //String
    }
     } 


	// v2beta1_object_metric_status->currentValue
    if (!v2beta1_object_metric_status->currentValue) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "currentValue", v2beta1_object_metric_status->currentValue) == NULL) {
    goto fail; //String
    }


	// v2beta1_object_metric_status->metricName
    if (!v2beta1_object_metric_status->metricName) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "metricName", v2beta1_object_metric_status->metricName) == NULL) {
    goto fail; //String
    }


	// v2beta1_object_metric_status->selector
    if(v2beta1_object_metric_status->selector) { 
    cJSON *selector_local_JSON = v1_label_selector_convertToJSON(v2beta1_object_metric_status->selector);
    if(selector_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "selector", selector_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v2beta1_object_metric_status->target
    if (!v2beta1_object_metric_status->target) {
        goto fail;
    }
    
    cJSON *target_local_JSON = v2beta1_cross_version_object_reference_convertToJSON(v2beta1_object_metric_status->target);
    if(target_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "target", target_local_JSON);
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

v2beta1_object_metric_status_t *v2beta1_object_metric_status_parseFromJSON(cJSON *v2beta1_object_metric_statusJSON){

    v2beta1_object_metric_status_t *v2beta1_object_metric_status_local_var = NULL;

    // v2beta1_object_metric_status->averageValue
    cJSON *averageValue = cJSON_GetObjectItemCaseSensitive(v2beta1_object_metric_statusJSON, "averageValue");
    if (averageValue) { 
    if(!cJSON_IsString(averageValue))
    {
    goto end; //String
    }
    }

    // v2beta1_object_metric_status->currentValue
    cJSON *currentValue = cJSON_GetObjectItemCaseSensitive(v2beta1_object_metric_statusJSON, "currentValue");
    if (!currentValue) {
        goto end;
    }

    
    if(!cJSON_IsString(currentValue))
    {
    goto end; //String
    }

    // v2beta1_object_metric_status->metricName
    cJSON *metricName = cJSON_GetObjectItemCaseSensitive(v2beta1_object_metric_statusJSON, "metricName");
    if (!metricName) {
        goto end;
    }

    
    if(!cJSON_IsString(metricName))
    {
    goto end; //String
    }

    // v2beta1_object_metric_status->selector
    cJSON *selector = cJSON_GetObjectItemCaseSensitive(v2beta1_object_metric_statusJSON, "selector");
    v1_label_selector_t *selector_local_nonprim = NULL;
    if (selector) { 
    selector_local_nonprim = v1_label_selector_parseFromJSON(selector); //nonprimitive
    }

    // v2beta1_object_metric_status->target
    cJSON *target = cJSON_GetObjectItemCaseSensitive(v2beta1_object_metric_statusJSON, "target");
    if (!target) {
        goto end;
    }

    v2beta1_cross_version_object_reference_t *target_local_nonprim = NULL;
    
    target_local_nonprim = v2beta1_cross_version_object_reference_parseFromJSON(target); //nonprimitive


    v2beta1_object_metric_status_local_var = v2beta1_object_metric_status_create (
        averageValue ? strdup(averageValue->valuestring) : NULL,
        strdup(currentValue->valuestring),
        strdup(metricName->valuestring),
        selector ? selector_local_nonprim : NULL,
        target_local_nonprim
        );

    return v2beta1_object_metric_status_local_var;
end:
    return NULL;

}
