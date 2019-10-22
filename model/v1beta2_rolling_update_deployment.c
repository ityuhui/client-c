#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta2_rolling_update_deployment.h"



v1beta2_rolling_update_deployment_t *v1beta2_rolling_update_deployment_create(
    object_t *maxSurge,
    object_t *maxUnavailable
    ) {
	v1beta2_rolling_update_deployment_t *v1beta2_rolling_update_deployment_local_var = malloc(sizeof(v1beta2_rolling_update_deployment_t));
    if (!v1beta2_rolling_update_deployment_local_var) {
        return NULL;
    }
	v1beta2_rolling_update_deployment_local_var->maxSurge = maxSurge;
	v1beta2_rolling_update_deployment_local_var->maxUnavailable = maxUnavailable;

	return v1beta2_rolling_update_deployment_local_var;
}


void v1beta2_rolling_update_deployment_free(v1beta2_rolling_update_deployment_t *v1beta2_rolling_update_deployment) {
    listEntry_t *listEntry;
    object_free(v1beta2_rolling_update_deployment->maxSurge);
    object_free(v1beta2_rolling_update_deployment->maxUnavailable);
	free(v1beta2_rolling_update_deployment);
}

cJSON *v1beta2_rolling_update_deployment_convertToJSON(v1beta2_rolling_update_deployment_t *v1beta2_rolling_update_deployment) {
	cJSON *item = cJSON_CreateObject();

	// v1beta2_rolling_update_deployment->maxSurge
    if(v1beta2_rolling_update_deployment->maxSurge) { 
    cJSON *maxSurge_object = object_convertToJSON(v1beta2_rolling_update_deployment->maxSurge);
    if(maxSurge_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "maxSurge", maxSurge_object);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1beta2_rolling_update_deployment->maxUnavailable
    if(v1beta2_rolling_update_deployment->maxUnavailable) { 
    cJSON *maxUnavailable_object = object_convertToJSON(v1beta2_rolling_update_deployment->maxUnavailable);
    if(maxUnavailable_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "maxUnavailable", maxUnavailable_object);
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

v1beta2_rolling_update_deployment_t *v1beta2_rolling_update_deployment_parseFromJSON(cJSON *v1beta2_rolling_update_deploymentJSON){

    v1beta2_rolling_update_deployment_t *v1beta2_rolling_update_deployment_local_var = NULL;

    // v1beta2_rolling_update_deployment->maxSurge
    cJSON *maxSurge = cJSON_GetObjectItemCaseSensitive(v1beta2_rolling_update_deploymentJSON, "maxSurge");
    object_t *maxSurge_local_object = NULL;
    if (maxSurge) { 
    maxSurge_local_object = object_parseFromJSON(maxSurge); //object
    }

    // v1beta2_rolling_update_deployment->maxUnavailable
    cJSON *maxUnavailable = cJSON_GetObjectItemCaseSensitive(v1beta2_rolling_update_deploymentJSON, "maxUnavailable");
    object_t *maxUnavailable_local_object = NULL;
    if (maxUnavailable) { 
    maxUnavailable_local_object = object_parseFromJSON(maxUnavailable); //object
    }


    v1beta2_rolling_update_deployment_local_var = v1beta2_rolling_update_deployment_create (
        maxSurge ? maxSurge_local_object : NULL,
        maxUnavailable ? maxUnavailable_local_object : NULL
        );

    return v1beta2_rolling_update_deployment_local_var;
end:
    return NULL;

}
