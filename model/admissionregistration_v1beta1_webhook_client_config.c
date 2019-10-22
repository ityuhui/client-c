#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "admissionregistration_v1beta1_webhook_client_config.h"



admissionregistration_v1beta1_webhook_client_config_t *admissionregistration_v1beta1_webhook_client_config_create(
    char caBundle,
    admissionregistration_v1beta1_service_reference_t *service,
    char *url
    ) {
	admissionregistration_v1beta1_webhook_client_config_t *admissionregistration_v1beta1_webhook_client_config_local_var = malloc(sizeof(admissionregistration_v1beta1_webhook_client_config_t));
    if (!admissionregistration_v1beta1_webhook_client_config_local_var) {
        return NULL;
    }
	admissionregistration_v1beta1_webhook_client_config_local_var->caBundle = caBundle;
	admissionregistration_v1beta1_webhook_client_config_local_var->service = service;
	admissionregistration_v1beta1_webhook_client_config_local_var->url = url;

	return admissionregistration_v1beta1_webhook_client_config_local_var;
}


void admissionregistration_v1beta1_webhook_client_config_free(admissionregistration_v1beta1_webhook_client_config_t *admissionregistration_v1beta1_webhook_client_config) {
    listEntry_t *listEntry;
    admissionregistration_v1beta1_service_reference_free(admissionregistration_v1beta1_webhook_client_config->service);
    free(admissionregistration_v1beta1_webhook_client_config->url);
	free(admissionregistration_v1beta1_webhook_client_config);
}

cJSON *admissionregistration_v1beta1_webhook_client_config_convertToJSON(admissionregistration_v1beta1_webhook_client_config_t *admissionregistration_v1beta1_webhook_client_config) {
	cJSON *item = cJSON_CreateObject();

	// admissionregistration_v1beta1_webhook_client_config->caBundle
    if(admissionregistration_v1beta1_webhook_client_config->caBundle) { 
    if(cJSON_AddNumberToObject(item, "caBundle", admissionregistration_v1beta1_webhook_client_config->caBundle) == NULL) {
    goto fail; //Byte
    }
     } 


	// admissionregistration_v1beta1_webhook_client_config->service
    if(admissionregistration_v1beta1_webhook_client_config->service) { 
    cJSON *service_local_JSON = admissionregistration_v1beta1_service_reference_convertToJSON(admissionregistration_v1beta1_webhook_client_config->service);
    if(service_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "service", service_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// admissionregistration_v1beta1_webhook_client_config->url
    if(admissionregistration_v1beta1_webhook_client_config->url) { 
    if(cJSON_AddStringToObject(item, "url", admissionregistration_v1beta1_webhook_client_config->url) == NULL) {
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

admissionregistration_v1beta1_webhook_client_config_t *admissionregistration_v1beta1_webhook_client_config_parseFromJSON(cJSON *admissionregistration_v1beta1_webhook_client_configJSON){

    admissionregistration_v1beta1_webhook_client_config_t *admissionregistration_v1beta1_webhook_client_config_local_var = NULL;

    // admissionregistration_v1beta1_webhook_client_config->caBundle
    cJSON *caBundle = cJSON_GetObjectItemCaseSensitive(admissionregistration_v1beta1_webhook_client_configJSON, "caBundle");
    if (caBundle) { 
    if(!cJSON_IsNumber(caBundle))
    {
    goto end; //Byte
    }
    }

    // admissionregistration_v1beta1_webhook_client_config->service
    cJSON *service = cJSON_GetObjectItemCaseSensitive(admissionregistration_v1beta1_webhook_client_configJSON, "service");
    admissionregistration_v1beta1_service_reference_t *service_local_nonprim = NULL;
    if (service) { 
    service_local_nonprim = admissionregistration_v1beta1_service_reference_parseFromJSON(service); //nonprimitive
    }

    // admissionregistration_v1beta1_webhook_client_config->url
    cJSON *url = cJSON_GetObjectItemCaseSensitive(admissionregistration_v1beta1_webhook_client_configJSON, "url");
    if (url) { 
    if(!cJSON_IsString(url))
    {
    goto end; //String
    }
    }


    admissionregistration_v1beta1_webhook_client_config_local_var = admissionregistration_v1beta1_webhook_client_config_create (
        caBundle ? caBundle->valueint : 0,
        service ? service_local_nonprim : NULL,
        url ? strdup(url->valuestring) : NULL
        );

    return admissionregistration_v1beta1_webhook_client_config_local_var;
end:
    return NULL;

}
