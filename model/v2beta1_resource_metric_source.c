#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v2beta1_resource_metric_source.h"



v2beta1_resource_metric_source_t *v2beta1_resource_metric_source_create(
    char *name,
    int targetAverageUtilization,
    char *targetAverageValue
    ) {
	v2beta1_resource_metric_source_t *v2beta1_resource_metric_source_local_var = malloc(sizeof(v2beta1_resource_metric_source_t));
    if (!v2beta1_resource_metric_source_local_var) {
        return NULL;
    }
	v2beta1_resource_metric_source_local_var->name = name;
	v2beta1_resource_metric_source_local_var->targetAverageUtilization = targetAverageUtilization;
	v2beta1_resource_metric_source_local_var->targetAverageValue = targetAverageValue;

	return v2beta1_resource_metric_source_local_var;
}


void v2beta1_resource_metric_source_free(v2beta1_resource_metric_source_t *v2beta1_resource_metric_source) {
    listEntry_t *listEntry;
    free(v2beta1_resource_metric_source->name);
    free(v2beta1_resource_metric_source->targetAverageValue);
	free(v2beta1_resource_metric_source);
}

cJSON *v2beta1_resource_metric_source_convertToJSON(v2beta1_resource_metric_source_t *v2beta1_resource_metric_source) {
	cJSON *item = cJSON_CreateObject();

	// v2beta1_resource_metric_source->name
    if (!v2beta1_resource_metric_source->name) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "name", v2beta1_resource_metric_source->name) == NULL) {
    goto fail; //String
    }


	// v2beta1_resource_metric_source->targetAverageUtilization
    if(v2beta1_resource_metric_source->targetAverageUtilization) { 
    if(cJSON_AddNumberToObject(item, "targetAverageUtilization", v2beta1_resource_metric_source->targetAverageUtilization) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v2beta1_resource_metric_source->targetAverageValue
    if(v2beta1_resource_metric_source->targetAverageValue) { 
    if(cJSON_AddStringToObject(item, "targetAverageValue", v2beta1_resource_metric_source->targetAverageValue) == NULL) {
    goto fail; //String
    }
     } 

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v2beta1_resource_metric_source_t *v2beta1_resource_metric_source_parseFromJSON(cJSON *v2beta1_resource_metric_sourceJSON){

    v2beta1_resource_metric_source_t *v2beta1_resource_metric_source_local_var = NULL;

    // v2beta1_resource_metric_source->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v2beta1_resource_metric_sourceJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // v2beta1_resource_metric_source->targetAverageUtilization
    cJSON *targetAverageUtilization = cJSON_GetObjectItemCaseSensitive(v2beta1_resource_metric_sourceJSON, "targetAverageUtilization");
    if (targetAverageUtilization) { 
    if(!cJSON_IsNumber(targetAverageUtilization))
    {
    goto end; //Numeric
    }
    }

    // v2beta1_resource_metric_source->targetAverageValue
    cJSON *targetAverageValue = cJSON_GetObjectItemCaseSensitive(v2beta1_resource_metric_sourceJSON, "targetAverageValue");
    if (targetAverageValue) { 
    if(!cJSON_IsString(targetAverageValue))
    {
    goto end; //String
    }
    }


    v2beta1_resource_metric_source_local_var = v2beta1_resource_metric_source_create (
        strdup(name->valuestring),
        targetAverageUtilization ? targetAverageUtilization->valuedouble : 0,
        targetAverageValue ? strdup(targetAverageValue->valuestring) : NULL
        );

    return v2beta1_resource_metric_source_local_var;
end:
    return NULL;

}
