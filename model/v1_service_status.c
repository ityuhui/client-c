#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_service_status.h"



v1_service_status_t *v1_service_status_create(
    v1_load_balancer_status_t *loadBalancer
    ) {
	v1_service_status_t *v1_service_status_local_var = malloc(sizeof(v1_service_status_t));
    if (!v1_service_status_local_var) {
        return NULL;
    }
	v1_service_status_local_var->loadBalancer = loadBalancer;

	return v1_service_status_local_var;
}


void v1_service_status_free(v1_service_status_t *v1_service_status) {
    listEntry_t *listEntry;
    v1_load_balancer_status_free(v1_service_status->loadBalancer);
	free(v1_service_status);
}

cJSON *v1_service_status_convertToJSON(v1_service_status_t *v1_service_status) {
	cJSON *item = cJSON_CreateObject();

	// v1_service_status->loadBalancer
    if(v1_service_status->loadBalancer) { 
    cJSON *loadBalancer_local_JSON = v1_load_balancer_status_convertToJSON(v1_service_status->loadBalancer);
    if(loadBalancer_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "loadBalancer", loadBalancer_local_JSON);
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

v1_service_status_t *v1_service_status_parseFromJSON(cJSON *v1_service_statusJSON){

    v1_service_status_t *v1_service_status_local_var = NULL;

    // v1_service_status->loadBalancer
    cJSON *loadBalancer = cJSON_GetObjectItemCaseSensitive(v1_service_statusJSON, "loadBalancer");
    v1_load_balancer_status_t *loadBalancer_local_nonprim = NULL;
    if (loadBalancer) { 
    loadBalancer_local_nonprim = v1_load_balancer_status_parseFromJSON(loadBalancer); //nonprimitive
    }


    v1_service_status_local_var = v1_service_status_create (
        loadBalancer ? loadBalancer_local_nonprim : NULL
        );

    return v1_service_status_local_var;
end:
    return NULL;

}
