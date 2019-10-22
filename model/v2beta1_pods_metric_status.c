#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v2beta1_pods_metric_status.h"



v2beta1_pods_metric_status_t *v2beta1_pods_metric_status_create(
    char *currentAverageValue,
    char *metricName,
    v1_label_selector_t *selector
    ) {
	v2beta1_pods_metric_status_t *v2beta1_pods_metric_status_local_var = malloc(sizeof(v2beta1_pods_metric_status_t));
    if (!v2beta1_pods_metric_status_local_var) {
        return NULL;
    }
	v2beta1_pods_metric_status_local_var->currentAverageValue = currentAverageValue;
	v2beta1_pods_metric_status_local_var->metricName = metricName;
	v2beta1_pods_metric_status_local_var->selector = selector;

	return v2beta1_pods_metric_status_local_var;
}


void v2beta1_pods_metric_status_free(v2beta1_pods_metric_status_t *v2beta1_pods_metric_status) {
    listEntry_t *listEntry;
    free(v2beta1_pods_metric_status->currentAverageValue);
    free(v2beta1_pods_metric_status->metricName);
    v1_label_selector_free(v2beta1_pods_metric_status->selector);
	free(v2beta1_pods_metric_status);
}

cJSON *v2beta1_pods_metric_status_convertToJSON(v2beta1_pods_metric_status_t *v2beta1_pods_metric_status) {
	cJSON *item = cJSON_CreateObject();

	// v2beta1_pods_metric_status->currentAverageValue
    if (!v2beta1_pods_metric_status->currentAverageValue) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "currentAverageValue", v2beta1_pods_metric_status->currentAverageValue) == NULL) {
    goto fail; //String
    }


	// v2beta1_pods_metric_status->metricName
    if (!v2beta1_pods_metric_status->metricName) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "metricName", v2beta1_pods_metric_status->metricName) == NULL) {
    goto fail; //String
    }


	// v2beta1_pods_metric_status->selector
    if(v2beta1_pods_metric_status->selector) { 
    cJSON *selector_local_JSON = v1_label_selector_convertToJSON(v2beta1_pods_metric_status->selector);
    if(selector_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "selector", selector_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v2beta1_pods_metric_status_t *v2beta1_pods_metric_status_parseFromJSON(cJSON *v2beta1_pods_metric_statusJSON){

    v2beta1_pods_metric_status_t *v2beta1_pods_metric_status_local_var = NULL;

    // v2beta1_pods_metric_status->currentAverageValue
    cJSON *currentAverageValue = cJSON_GetObjectItemCaseSensitive(v2beta1_pods_metric_statusJSON, "currentAverageValue");
    if (!currentAverageValue) {
        goto end;
    }

    
    if(!cJSON_IsString(currentAverageValue))
    {
    goto end; //String
    }

    // v2beta1_pods_metric_status->metricName
    cJSON *metricName = cJSON_GetObjectItemCaseSensitive(v2beta1_pods_metric_statusJSON, "metricName");
    if (!metricName) {
        goto end;
    }

    
    if(!cJSON_IsString(metricName))
    {
    goto end; //String
    }

    // v2beta1_pods_metric_status->selector
    cJSON *selector = cJSON_GetObjectItemCaseSensitive(v2beta1_pods_metric_statusJSON, "selector");
    v1_label_selector_t *selector_local_nonprim = NULL;
    if (selector) { 
    selector_local_nonprim = v1_label_selector_parseFromJSON(selector); //nonprimitive
    }


    v2beta1_pods_metric_status_local_var = v2beta1_pods_metric_status_create (
        strdup(currentAverageValue->valuestring),
        strdup(metricName->valuestring),
        selector ? selector_local_nonprim : NULL
        );

    return v2beta1_pods_metric_status_local_var;
end:
    return NULL;

}
