#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "extensions_v1beta1_rolling_update_deployment.h"



extensions_v1beta1_rolling_update_deployment_t *extensions_v1beta1_rolling_update_deployment_create(
    object_t *maxSurge,
    object_t *maxUnavailable
    ) {
	extensions_v1beta1_rolling_update_deployment_t *extensions_v1beta1_rolling_update_deployment_local_var = malloc(sizeof(extensions_v1beta1_rolling_update_deployment_t));
    if (!extensions_v1beta1_rolling_update_deployment_local_var) {
        return NULL;
    }
	extensions_v1beta1_rolling_update_deployment_local_var->maxSurge = maxSurge;
	extensions_v1beta1_rolling_update_deployment_local_var->maxUnavailable = maxUnavailable;

	return extensions_v1beta1_rolling_update_deployment_local_var;
}


void extensions_v1beta1_rolling_update_deployment_free(extensions_v1beta1_rolling_update_deployment_t *extensions_v1beta1_rolling_update_deployment) {
    listEntry_t *listEntry;
    object_free(extensions_v1beta1_rolling_update_deployment->maxSurge);
    object_free(extensions_v1beta1_rolling_update_deployment->maxUnavailable);
	free(extensions_v1beta1_rolling_update_deployment);
}

cJSON *extensions_v1beta1_rolling_update_deployment_convertToJSON(extensions_v1beta1_rolling_update_deployment_t *extensions_v1beta1_rolling_update_deployment) {
	cJSON *item = cJSON_CreateObject();

	// extensions_v1beta1_rolling_update_deployment->maxSurge
    if(extensions_v1beta1_rolling_update_deployment->maxSurge) { 
    cJSON *maxSurge_object = object_convertToJSON(extensions_v1beta1_rolling_update_deployment->maxSurge);
    if(maxSurge_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "maxSurge", maxSurge_object);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// extensions_v1beta1_rolling_update_deployment->maxUnavailable
    if(extensions_v1beta1_rolling_update_deployment->maxUnavailable) { 
    cJSON *maxUnavailable_object = object_convertToJSON(extensions_v1beta1_rolling_update_deployment->maxUnavailable);
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

extensions_v1beta1_rolling_update_deployment_t *extensions_v1beta1_rolling_update_deployment_parseFromJSON(cJSON *extensions_v1beta1_rolling_update_deploymentJSON){

    extensions_v1beta1_rolling_update_deployment_t *extensions_v1beta1_rolling_update_deployment_local_var = NULL;

    // extensions_v1beta1_rolling_update_deployment->maxSurge
    cJSON *maxSurge = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_rolling_update_deploymentJSON, "maxSurge");
    object_t *maxSurge_local_object = NULL;
    if (maxSurge) { 
    maxSurge_local_object = object_parseFromJSON(maxSurge); //object
    }

    // extensions_v1beta1_rolling_update_deployment->maxUnavailable
    cJSON *maxUnavailable = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_rolling_update_deploymentJSON, "maxUnavailable");
    object_t *maxUnavailable_local_object = NULL;
    if (maxUnavailable) { 
    maxUnavailable_local_object = object_parseFromJSON(maxUnavailable); //object
    }


    extensions_v1beta1_rolling_update_deployment_local_var = extensions_v1beta1_rolling_update_deployment_create (
        maxSurge ? maxSurge_local_object : NULL,
        maxUnavailable ? maxUnavailable_local_object : NULL
        );

    return extensions_v1beta1_rolling_update_deployment_local_var;
end:
    return NULL;

}
