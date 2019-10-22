#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v2beta1_object_metric_source.h"



v2beta1_object_metric_source_t *v2beta1_object_metric_source_create(
    char *averageValue,
    char *metricName,
    v1_label_selector_t *selector,
    v2beta1_cross_version_object_reference_t *target,
    char *targetValue
    ) {
	v2beta1_object_metric_source_t *v2beta1_object_metric_source_local_var = malloc(sizeof(v2beta1_object_metric_source_t));
    if (!v2beta1_object_metric_source_local_var) {
        return NULL;
    }
	v2beta1_object_metric_source_local_var->averageValue = averageValue;
	v2beta1_object_metric_source_local_var->metricName = metricName;
	v2beta1_object_metric_source_local_var->selector = selector;
	v2beta1_object_metric_source_local_var->target = target;
	v2beta1_object_metric_source_local_var->targetValue = targetValue;

	return v2beta1_object_metric_source_local_var;
}


void v2beta1_object_metric_source_free(v2beta1_object_metric_source_t *v2beta1_object_metric_source) {
    listEntry_t *listEntry;
    free(v2beta1_object_metric_source->averageValue);
    free(v2beta1_object_metric_source->metricName);
    v1_label_selector_free(v2beta1_object_metric_source->selector);
    v2beta1_cross_version_object_reference_free(v2beta1_object_metric_source->target);
    free(v2beta1_object_metric_source->targetValue);
	free(v2beta1_object_metric_source);
}

cJSON *v2beta1_object_metric_source_convertToJSON(v2beta1_object_metric_source_t *v2beta1_object_metric_source) {
	cJSON *item = cJSON_CreateObject();

	// v2beta1_object_metric_source->averageValue
    if(v2beta1_object_metric_source->averageValue) { 
    if(cJSON_AddStringToObject(item, "averageValue", v2beta1_object_metric_source->averageValue) == NULL) {
    goto fail; //String
    }
     } 


	// v2beta1_object_metric_source->metricName
    if (!v2beta1_object_metric_source->metricName) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "metricName", v2beta1_object_metric_source->metricName) == NULL) {
    goto fail; //String
    }


	// v2beta1_object_metric_source->selector
    if(v2beta1_object_metric_source->selector) { 
    cJSON *selector_local_JSON = v1_label_selector_convertToJSON(v2beta1_object_metric_source->selector);
    if(selector_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "selector", selector_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v2beta1_object_metric_source->target
    if (!v2beta1_object_metric_source->target) {
        goto fail;
    }
    
    cJSON *target_local_JSON = v2beta1_cross_version_object_reference_convertToJSON(v2beta1_object_metric_source->target);
    if(target_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "target", target_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


	// v2beta1_object_metric_source->targetValue
    if (!v2beta1_object_metric_source->targetValue) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "targetValue", v2beta1_object_metric_source->targetValue) == NULL) {
    goto fail; //String
    }

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v2beta1_object_metric_source_t *v2beta1_object_metric_source_parseFromJSON(cJSON *v2beta1_object_metric_sourceJSON){

    v2beta1_object_metric_source_t *v2beta1_object_metric_source_local_var = NULL;

    // v2beta1_object_metric_source->averageValue
    cJSON *averageValue = cJSON_GetObjectItemCaseSensitive(v2beta1_object_metric_sourceJSON, "averageValue");
    if (averageValue) { 
    if(!cJSON_IsString(averageValue))
    {
    goto end; //String
    }
    }

    // v2beta1_object_metric_source->metricName
    cJSON *metricName = cJSON_GetObjectItemCaseSensitive(v2beta1_object_metric_sourceJSON, "metricName");
    if (!metricName) {
        goto end;
    }

    
    if(!cJSON_IsString(metricName))
    {
    goto end; //String
    }

    // v2beta1_object_metric_source->selector
    cJSON *selector = cJSON_GetObjectItemCaseSensitive(v2beta1_object_metric_sourceJSON, "selector");
    v1_label_selector_t *selector_local_nonprim = NULL;
    if (selector) { 
    selector_local_nonprim = v1_label_selector_parseFromJSON(selector); //nonprimitive
    }

    // v2beta1_object_metric_source->target
    cJSON *target = cJSON_GetObjectItemCaseSensitive(v2beta1_object_metric_sourceJSON, "target");
    if (!target) {
        goto end;
    }

    v2beta1_cross_version_object_reference_t *target_local_nonprim = NULL;
    
    target_local_nonprim = v2beta1_cross_version_object_reference_parseFromJSON(target); //nonprimitive

    // v2beta1_object_metric_source->targetValue
    cJSON *targetValue = cJSON_GetObjectItemCaseSensitive(v2beta1_object_metric_sourceJSON, "targetValue");
    if (!targetValue) {
        goto end;
    }

    
    if(!cJSON_IsString(targetValue))
    {
    goto end; //String
    }


    v2beta1_object_metric_source_local_var = v2beta1_object_metric_source_create (
        averageValue ? strdup(averageValue->valuestring) : NULL,
        strdup(metricName->valuestring),
        selector ? selector_local_nonprim : NULL,
        target_local_nonprim,
        strdup(targetValue->valuestring)
        );

    return v2beta1_object_metric_source_local_var;
end:
    return NULL;

}
