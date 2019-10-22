#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v2beta2_metric_value_status.h"



v2beta2_metric_value_status_t *v2beta2_metric_value_status_create(
    int averageUtilization,
    char *averageValue,
    char *value
    ) {
	v2beta2_metric_value_status_t *v2beta2_metric_value_status_local_var = malloc(sizeof(v2beta2_metric_value_status_t));
    if (!v2beta2_metric_value_status_local_var) {
        return NULL;
    }
	v2beta2_metric_value_status_local_var->averageUtilization = averageUtilization;
	v2beta2_metric_value_status_local_var->averageValue = averageValue;
	v2beta2_metric_value_status_local_var->value = value;

	return v2beta2_metric_value_status_local_var;
}


void v2beta2_metric_value_status_free(v2beta2_metric_value_status_t *v2beta2_metric_value_status) {
    listEntry_t *listEntry;
    free(v2beta2_metric_value_status->averageValue);
    free(v2beta2_metric_value_status->value);
	free(v2beta2_metric_value_status);
}

cJSON *v2beta2_metric_value_status_convertToJSON(v2beta2_metric_value_status_t *v2beta2_metric_value_status) {
	cJSON *item = cJSON_CreateObject();

	// v2beta2_metric_value_status->averageUtilization
    if(v2beta2_metric_value_status->averageUtilization) { 
    if(cJSON_AddNumberToObject(item, "averageUtilization", v2beta2_metric_value_status->averageUtilization) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v2beta2_metric_value_status->averageValue
    if(v2beta2_metric_value_status->averageValue) { 
    if(cJSON_AddStringToObject(item, "averageValue", v2beta2_metric_value_status->averageValue) == NULL) {
    goto fail; //String
    }
     } 


	// v2beta2_metric_value_status->value
    if(v2beta2_metric_value_status->value) { 
    if(cJSON_AddStringToObject(item, "value", v2beta2_metric_value_status->value) == NULL) {
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

v2beta2_metric_value_status_t *v2beta2_metric_value_status_parseFromJSON(cJSON *v2beta2_metric_value_statusJSON){

    v2beta2_metric_value_status_t *v2beta2_metric_value_status_local_var = NULL;

    // v2beta2_metric_value_status->averageUtilization
    cJSON *averageUtilization = cJSON_GetObjectItemCaseSensitive(v2beta2_metric_value_statusJSON, "averageUtilization");
    if (averageUtilization) { 
    if(!cJSON_IsNumber(averageUtilization))
    {
    goto end; //Numeric
    }
    }

    // v2beta2_metric_value_status->averageValue
    cJSON *averageValue = cJSON_GetObjectItemCaseSensitive(v2beta2_metric_value_statusJSON, "averageValue");
    if (averageValue) { 
    if(!cJSON_IsString(averageValue))
    {
    goto end; //String
    }
    }

    // v2beta2_metric_value_status->value
    cJSON *value = cJSON_GetObjectItemCaseSensitive(v2beta2_metric_value_statusJSON, "value");
    if (value) { 
    if(!cJSON_IsString(value))
    {
    goto end; //String
    }
    }


    v2beta2_metric_value_status_local_var = v2beta2_metric_value_status_create (
        averageUtilization ? averageUtilization->valuedouble : 0,
        averageValue ? strdup(averageValue->valuestring) : NULL,
        value ? strdup(value->valuestring) : NULL
        );

    return v2beta2_metric_value_status_local_var;
end:
    return NULL;

}
