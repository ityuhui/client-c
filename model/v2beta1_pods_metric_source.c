#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v2beta1_pods_metric_source.h"



v2beta1_pods_metric_source_t *v2beta1_pods_metric_source_create(
    char *metricName,
    v1_label_selector_t *selector,
    char *targetAverageValue
    ) {
	v2beta1_pods_metric_source_t *v2beta1_pods_metric_source_local_var = malloc(sizeof(v2beta1_pods_metric_source_t));
    if (!v2beta1_pods_metric_source_local_var) {
        return NULL;
    }
	v2beta1_pods_metric_source_local_var->metricName = metricName;
	v2beta1_pods_metric_source_local_var->selector = selector;
	v2beta1_pods_metric_source_local_var->targetAverageValue = targetAverageValue;

	return v2beta1_pods_metric_source_local_var;
}


void v2beta1_pods_metric_source_free(v2beta1_pods_metric_source_t *v2beta1_pods_metric_source) {
    listEntry_t *listEntry;
    free(v2beta1_pods_metric_source->metricName);
    v1_label_selector_free(v2beta1_pods_metric_source->selector);
    free(v2beta1_pods_metric_source->targetAverageValue);
	free(v2beta1_pods_metric_source);
}

cJSON *v2beta1_pods_metric_source_convertToJSON(v2beta1_pods_metric_source_t *v2beta1_pods_metric_source) {
	cJSON *item = cJSON_CreateObject();

	// v2beta1_pods_metric_source->metricName
    if (!v2beta1_pods_metric_source->metricName) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "metricName", v2beta1_pods_metric_source->metricName) == NULL) {
    goto fail; //String
    }


	// v2beta1_pods_metric_source->selector
    if(v2beta1_pods_metric_source->selector) { 
    cJSON *selector_local_JSON = v1_label_selector_convertToJSON(v2beta1_pods_metric_source->selector);
    if(selector_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "selector", selector_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v2beta1_pods_metric_source->targetAverageValue
    if (!v2beta1_pods_metric_source->targetAverageValue) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "targetAverageValue", v2beta1_pods_metric_source->targetAverageValue) == NULL) {
    goto fail; //String
    }

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v2beta1_pods_metric_source_t *v2beta1_pods_metric_source_parseFromJSON(cJSON *v2beta1_pods_metric_sourceJSON){

    v2beta1_pods_metric_source_t *v2beta1_pods_metric_source_local_var = NULL;

    // v2beta1_pods_metric_source->metricName
    cJSON *metricName = cJSON_GetObjectItemCaseSensitive(v2beta1_pods_metric_sourceJSON, "metricName");
    if (!metricName) {
        goto end;
    }

    
    if(!cJSON_IsString(metricName))
    {
    goto end; //String
    }

    // v2beta1_pods_metric_source->selector
    cJSON *selector = cJSON_GetObjectItemCaseSensitive(v2beta1_pods_metric_sourceJSON, "selector");
    v1_label_selector_t *selector_local_nonprim = NULL;
    if (selector) { 
    selector_local_nonprim = v1_label_selector_parseFromJSON(selector); //nonprimitive
    }

    // v2beta1_pods_metric_source->targetAverageValue
    cJSON *targetAverageValue = cJSON_GetObjectItemCaseSensitive(v2beta1_pods_metric_sourceJSON, "targetAverageValue");
    if (!targetAverageValue) {
        goto end;
    }

    
    if(!cJSON_IsString(targetAverageValue))
    {
    goto end; //String
    }


    v2beta1_pods_metric_source_local_var = v2beta1_pods_metric_source_create (
        strdup(metricName->valuestring),
        selector ? selector_local_nonprim : NULL,
        strdup(targetAverageValue->valuestring)
        );

    return v2beta1_pods_metric_source_local_var;
end:
    return NULL;

}
