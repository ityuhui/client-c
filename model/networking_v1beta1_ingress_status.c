#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "networking_v1beta1_ingress_status.h"



networking_v1beta1_ingress_status_t *networking_v1beta1_ingress_status_create(
    v1_load_balancer_status_t *loadBalancer
    ) {
	networking_v1beta1_ingress_status_t *networking_v1beta1_ingress_status_local_var = malloc(sizeof(networking_v1beta1_ingress_status_t));
    if (!networking_v1beta1_ingress_status_local_var) {
        return NULL;
    }
	networking_v1beta1_ingress_status_local_var->loadBalancer = loadBalancer;

	return networking_v1beta1_ingress_status_local_var;
}


void networking_v1beta1_ingress_status_free(networking_v1beta1_ingress_status_t *networking_v1beta1_ingress_status) {
    listEntry_t *listEntry;
    v1_load_balancer_status_free(networking_v1beta1_ingress_status->loadBalancer);
	free(networking_v1beta1_ingress_status);
}

cJSON *networking_v1beta1_ingress_status_convertToJSON(networking_v1beta1_ingress_status_t *networking_v1beta1_ingress_status) {
	cJSON *item = cJSON_CreateObject();

	// networking_v1beta1_ingress_status->loadBalancer
    if(networking_v1beta1_ingress_status->loadBalancer) { 
    cJSON *loadBalancer_local_JSON = v1_load_balancer_status_convertToJSON(networking_v1beta1_ingress_status->loadBalancer);
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

networking_v1beta1_ingress_status_t *networking_v1beta1_ingress_status_parseFromJSON(cJSON *networking_v1beta1_ingress_statusJSON){

    networking_v1beta1_ingress_status_t *networking_v1beta1_ingress_status_local_var = NULL;

    // networking_v1beta1_ingress_status->loadBalancer
    cJSON *loadBalancer = cJSON_GetObjectItemCaseSensitive(networking_v1beta1_ingress_statusJSON, "loadBalancer");
    v1_load_balancer_status_t *loadBalancer_local_nonprim = NULL;
    if (loadBalancer) { 
    loadBalancer_local_nonprim = v1_load_balancer_status_parseFromJSON(loadBalancer); //nonprimitive
    }


    networking_v1beta1_ingress_status_local_var = networking_v1beta1_ingress_status_create (
        loadBalancer ? loadBalancer_local_nonprim : NULL
        );

    return networking_v1beta1_ingress_status_local_var;
end:
    return NULL;

}
