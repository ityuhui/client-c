#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "networking_v1beta1_ingress_backend.h"



networking_v1beta1_ingress_backend_t *networking_v1beta1_ingress_backend_create(
    char *serviceName,
    object_t *servicePort
    ) {
	networking_v1beta1_ingress_backend_t *networking_v1beta1_ingress_backend_local_var = malloc(sizeof(networking_v1beta1_ingress_backend_t));
    if (!networking_v1beta1_ingress_backend_local_var) {
        return NULL;
    }
	networking_v1beta1_ingress_backend_local_var->serviceName = serviceName;
	networking_v1beta1_ingress_backend_local_var->servicePort = servicePort;

	return networking_v1beta1_ingress_backend_local_var;
}


void networking_v1beta1_ingress_backend_free(networking_v1beta1_ingress_backend_t *networking_v1beta1_ingress_backend) {
    listEntry_t *listEntry;
    free(networking_v1beta1_ingress_backend->serviceName);
    object_free(networking_v1beta1_ingress_backend->servicePort);
	free(networking_v1beta1_ingress_backend);
}

cJSON *networking_v1beta1_ingress_backend_convertToJSON(networking_v1beta1_ingress_backend_t *networking_v1beta1_ingress_backend) {
	cJSON *item = cJSON_CreateObject();

	// networking_v1beta1_ingress_backend->serviceName
    if (!networking_v1beta1_ingress_backend->serviceName) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "serviceName", networking_v1beta1_ingress_backend->serviceName) == NULL) {
    goto fail; //String
    }


	// networking_v1beta1_ingress_backend->servicePort
    if (!networking_v1beta1_ingress_backend->servicePort) {
        goto fail;
    }
    
    cJSON *servicePort_object = object_convertToJSON(networking_v1beta1_ingress_backend->servicePort);
    if(servicePort_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "servicePort", servicePort_object);
    if(item->child == NULL) {
    goto fail;
    }

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

networking_v1beta1_ingress_backend_t *networking_v1beta1_ingress_backend_parseFromJSON(cJSON *networking_v1beta1_ingress_backendJSON){

    networking_v1beta1_ingress_backend_t *networking_v1beta1_ingress_backend_local_var = NULL;

    // networking_v1beta1_ingress_backend->serviceName
    cJSON *serviceName = cJSON_GetObjectItemCaseSensitive(networking_v1beta1_ingress_backendJSON, "serviceName");
    if (!serviceName) {
        goto end;
    }

    
    if(!cJSON_IsString(serviceName))
    {
    goto end; //String
    }

    // networking_v1beta1_ingress_backend->servicePort
    cJSON *servicePort = cJSON_GetObjectItemCaseSensitive(networking_v1beta1_ingress_backendJSON, "servicePort");
    if (!servicePort) {
        goto end;
    }

    object_t *servicePort_local_object = NULL;
    
    servicePort_local_object = object_parseFromJSON(servicePort); //object


    networking_v1beta1_ingress_backend_local_var = networking_v1beta1_ingress_backend_create (
        strdup(serviceName->valuestring),
        servicePort_local_object
        );

    return networking_v1beta1_ingress_backend_local_var;
end:
    return NULL;

}
