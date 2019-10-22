#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "extensions_v1beta1_ingress_status.h"



extensions_v1beta1_ingress_status_t *extensions_v1beta1_ingress_status_create(
    v1_load_balancer_status_t *loadBalancer
    ) {
	extensions_v1beta1_ingress_status_t *extensions_v1beta1_ingress_status_local_var = malloc(sizeof(extensions_v1beta1_ingress_status_t));
    if (!extensions_v1beta1_ingress_status_local_var) {
        return NULL;
    }
	extensions_v1beta1_ingress_status_local_var->loadBalancer = loadBalancer;

	return extensions_v1beta1_ingress_status_local_var;
}


void extensions_v1beta1_ingress_status_free(extensions_v1beta1_ingress_status_t *extensions_v1beta1_ingress_status) {
    listEntry_t *listEntry;
    v1_load_balancer_status_free(extensions_v1beta1_ingress_status->loadBalancer);
	free(extensions_v1beta1_ingress_status);
}

cJSON *extensions_v1beta1_ingress_status_convertToJSON(extensions_v1beta1_ingress_status_t *extensions_v1beta1_ingress_status) {
	cJSON *item = cJSON_CreateObject();

	// extensions_v1beta1_ingress_status->loadBalancer
    if(extensions_v1beta1_ingress_status->loadBalancer) { 
    cJSON *loadBalancer_local_JSON = v1_load_balancer_status_convertToJSON(extensions_v1beta1_ingress_status->loadBalancer);
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

extensions_v1beta1_ingress_status_t *extensions_v1beta1_ingress_status_parseFromJSON(cJSON *extensions_v1beta1_ingress_statusJSON){

    extensions_v1beta1_ingress_status_t *extensions_v1beta1_ingress_status_local_var = NULL;

    // extensions_v1beta1_ingress_status->loadBalancer
    cJSON *loadBalancer = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_ingress_statusJSON, "loadBalancer");
    v1_load_balancer_status_t *loadBalancer_local_nonprim = NULL;
    if (loadBalancer) { 
    loadBalancer_local_nonprim = v1_load_balancer_status_parseFromJSON(loadBalancer); //nonprimitive
    }


    extensions_v1beta1_ingress_status_local_var = extensions_v1beta1_ingress_status_create (
        loadBalancer ? loadBalancer_local_nonprim : NULL
        );

    return extensions_v1beta1_ingress_status_local_var;
end:
    return NULL;

}
