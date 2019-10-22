#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "apps_v1beta1_rolling_update_deployment.h"



apps_v1beta1_rolling_update_deployment_t *apps_v1beta1_rolling_update_deployment_create(
    object_t *maxSurge,
    object_t *maxUnavailable
    ) {
	apps_v1beta1_rolling_update_deployment_t *apps_v1beta1_rolling_update_deployment_local_var = malloc(sizeof(apps_v1beta1_rolling_update_deployment_t));
    if (!apps_v1beta1_rolling_update_deployment_local_var) {
        return NULL;
    }
	apps_v1beta1_rolling_update_deployment_local_var->maxSurge = maxSurge;
	apps_v1beta1_rolling_update_deployment_local_var->maxUnavailable = maxUnavailable;

	return apps_v1beta1_rolling_update_deployment_local_var;
}


void apps_v1beta1_rolling_update_deployment_free(apps_v1beta1_rolling_update_deployment_t *apps_v1beta1_rolling_update_deployment) {
    listEntry_t *listEntry;
    object_free(apps_v1beta1_rolling_update_deployment->maxSurge);
    object_free(apps_v1beta1_rolling_update_deployment->maxUnavailable);
	free(apps_v1beta1_rolling_update_deployment);
}

cJSON *apps_v1beta1_rolling_update_deployment_convertToJSON(apps_v1beta1_rolling_update_deployment_t *apps_v1beta1_rolling_update_deployment) {
	cJSON *item = cJSON_CreateObject();

	// apps_v1beta1_rolling_update_deployment->maxSurge
    if(apps_v1beta1_rolling_update_deployment->maxSurge) { 
    cJSON *maxSurge_object = object_convertToJSON(apps_v1beta1_rolling_update_deployment->maxSurge);
    if(maxSurge_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "maxSurge", maxSurge_object);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// apps_v1beta1_rolling_update_deployment->maxUnavailable
    if(apps_v1beta1_rolling_update_deployment->maxUnavailable) { 
    cJSON *maxUnavailable_object = object_convertToJSON(apps_v1beta1_rolling_update_deployment->maxUnavailable);
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

apps_v1beta1_rolling_update_deployment_t *apps_v1beta1_rolling_update_deployment_parseFromJSON(cJSON *apps_v1beta1_rolling_update_deploymentJSON){

    apps_v1beta1_rolling_update_deployment_t *apps_v1beta1_rolling_update_deployment_local_var = NULL;

    // apps_v1beta1_rolling_update_deployment->maxSurge
    cJSON *maxSurge = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_rolling_update_deploymentJSON, "maxSurge");
    object_t *maxSurge_local_object = NULL;
    if (maxSurge) { 
    maxSurge_local_object = object_parseFromJSON(maxSurge); //object
    }

    // apps_v1beta1_rolling_update_deployment->maxUnavailable
    cJSON *maxUnavailable = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_rolling_update_deploymentJSON, "maxUnavailable");
    object_t *maxUnavailable_local_object = NULL;
    if (maxUnavailable) { 
    maxUnavailable_local_object = object_parseFromJSON(maxUnavailable); //object
    }


    apps_v1beta1_rolling_update_deployment_local_var = apps_v1beta1_rolling_update_deployment_create (
        maxSurge ? maxSurge_local_object : NULL,
        maxUnavailable ? maxUnavailable_local_object : NULL
        );

    return apps_v1beta1_rolling_update_deployment_local_var;
end:
    return NULL;

}
