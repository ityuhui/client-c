#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v2beta1_resource_metric_status.h"



v2beta1_resource_metric_status_t *v2beta1_resource_metric_status_create(
    int currentAverageUtilization,
    char *currentAverageValue,
    char *name
    ) {
	v2beta1_resource_metric_status_t *v2beta1_resource_metric_status_local_var = malloc(sizeof(v2beta1_resource_metric_status_t));
    if (!v2beta1_resource_metric_status_local_var) {
        return NULL;
    }
	v2beta1_resource_metric_status_local_var->currentAverageUtilization = currentAverageUtilization;
	v2beta1_resource_metric_status_local_var->currentAverageValue = currentAverageValue;
	v2beta1_resource_metric_status_local_var->name = name;

	return v2beta1_resource_metric_status_local_var;
}


void v2beta1_resource_metric_status_free(v2beta1_resource_metric_status_t *v2beta1_resource_metric_status) {
    listEntry_t *listEntry;
    free(v2beta1_resource_metric_status->currentAverageValue);
    free(v2beta1_resource_metric_status->name);
	free(v2beta1_resource_metric_status);
}

cJSON *v2beta1_resource_metric_status_convertToJSON(v2beta1_resource_metric_status_t *v2beta1_resource_metric_status) {
	cJSON *item = cJSON_CreateObject();

	// v2beta1_resource_metric_status->currentAverageUtilization
    if(v2beta1_resource_metric_status->currentAverageUtilization) { 
    if(cJSON_AddNumberToObject(item, "currentAverageUtilization", v2beta1_resource_metric_status->currentAverageUtilization) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v2beta1_resource_metric_status->currentAverageValue
    if (!v2beta1_resource_metric_status->currentAverageValue) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "currentAverageValue", v2beta1_resource_metric_status->currentAverageValue) == NULL) {
    goto fail; //String
    }


	// v2beta1_resource_metric_status->name
    if (!v2beta1_resource_metric_status->name) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "name", v2beta1_resource_metric_status->name) == NULL) {
    goto fail; //String
    }

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v2beta1_resource_metric_status_t *v2beta1_resource_metric_status_parseFromJSON(cJSON *v2beta1_resource_metric_statusJSON){

    v2beta1_resource_metric_status_t *v2beta1_resource_metric_status_local_var = NULL;

    // v2beta1_resource_metric_status->currentAverageUtilization
    cJSON *currentAverageUtilization = cJSON_GetObjectItemCaseSensitive(v2beta1_resource_metric_statusJSON, "currentAverageUtilization");
    if (currentAverageUtilization) { 
    if(!cJSON_IsNumber(currentAverageUtilization))
    {
    goto end; //Numeric
    }
    }

    // v2beta1_resource_metric_status->currentAverageValue
    cJSON *currentAverageValue = cJSON_GetObjectItemCaseSensitive(v2beta1_resource_metric_statusJSON, "currentAverageValue");
    if (!currentAverageValue) {
        goto end;
    }

    
    if(!cJSON_IsString(currentAverageValue))
    {
    goto end; //String
    }

    // v2beta1_resource_metric_status->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v2beta1_resource_metric_statusJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }


    v2beta1_resource_metric_status_local_var = v2beta1_resource_metric_status_create (
        currentAverageUtilization ? currentAverageUtilization->valuedouble : 0,
        strdup(currentAverageValue->valuestring),
        strdup(name->valuestring)
        );

    return v2beta1_resource_metric_status_local_var;
end:
    return NULL;

}
