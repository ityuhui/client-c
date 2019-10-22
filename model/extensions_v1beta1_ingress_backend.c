#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "extensions_v1beta1_ingress_backend.h"



extensions_v1beta1_ingress_backend_t *extensions_v1beta1_ingress_backend_create(
    char *serviceName,
    object_t *servicePort
    ) {
	extensions_v1beta1_ingress_backend_t *extensions_v1beta1_ingress_backend_local_var = malloc(sizeof(extensions_v1beta1_ingress_backend_t));
    if (!extensions_v1beta1_ingress_backend_local_var) {
        return NULL;
    }
	extensions_v1beta1_ingress_backend_local_var->serviceName = serviceName;
	extensions_v1beta1_ingress_backend_local_var->servicePort = servicePort;

	return extensions_v1beta1_ingress_backend_local_var;
}


void extensions_v1beta1_ingress_backend_free(extensions_v1beta1_ingress_backend_t *extensions_v1beta1_ingress_backend) {
    listEntry_t *listEntry;
    free(extensions_v1beta1_ingress_backend->serviceName);
    object_free(extensions_v1beta1_ingress_backend->servicePort);
	free(extensions_v1beta1_ingress_backend);
}

cJSON *extensions_v1beta1_ingress_backend_convertToJSON(extensions_v1beta1_ingress_backend_t *extensions_v1beta1_ingress_backend) {
	cJSON *item = cJSON_CreateObject();

	// extensions_v1beta1_ingress_backend->serviceName
    if (!extensions_v1beta1_ingress_backend->serviceName) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "serviceName", extensions_v1beta1_ingress_backend->serviceName) == NULL) {
    goto fail; //String
    }


	// extensions_v1beta1_ingress_backend->servicePort
    if (!extensions_v1beta1_ingress_backend->servicePort) {
        goto fail;
    }
    
    cJSON *servicePort_object = object_convertToJSON(extensions_v1beta1_ingress_backend->servicePort);
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

extensions_v1beta1_ingress_backend_t *extensions_v1beta1_ingress_backend_parseFromJSON(cJSON *extensions_v1beta1_ingress_backendJSON){

    extensions_v1beta1_ingress_backend_t *extensions_v1beta1_ingress_backend_local_var = NULL;

    // extensions_v1beta1_ingress_backend->serviceName
    cJSON *serviceName = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_ingress_backendJSON, "serviceName");
    if (!serviceName) {
        goto end;
    }

    
    if(!cJSON_IsString(serviceName))
    {
    goto end; //String
    }

    // extensions_v1beta1_ingress_backend->servicePort
    cJSON *servicePort = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_ingress_backendJSON, "servicePort");
    if (!servicePort) {
        goto end;
    }

    object_t *servicePort_local_object = NULL;
    
    servicePort_local_object = object_parseFromJSON(servicePort); //object


    extensions_v1beta1_ingress_backend_local_var = extensions_v1beta1_ingress_backend_create (
        strdup(serviceName->valuestring),
        servicePort_local_object
        );

    return extensions_v1beta1_ingress_backend_local_var;
end:
    return NULL;

}
