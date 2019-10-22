#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "apiextensions_v1_webhook_client_config.h"



apiextensions_v1_webhook_client_config_t *apiextensions_v1_webhook_client_config_create(
    char caBundle,
    apiextensions_v1_service_reference_t *service,
    char *url
    ) {
	apiextensions_v1_webhook_client_config_t *apiextensions_v1_webhook_client_config_local_var = malloc(sizeof(apiextensions_v1_webhook_client_config_t));
    if (!apiextensions_v1_webhook_client_config_local_var) {
        return NULL;
    }
	apiextensions_v1_webhook_client_config_local_var->caBundle = caBundle;
	apiextensions_v1_webhook_client_config_local_var->service = service;
	apiextensions_v1_webhook_client_config_local_var->url = url;

	return apiextensions_v1_webhook_client_config_local_var;
}


void apiextensions_v1_webhook_client_config_free(apiextensions_v1_webhook_client_config_t *apiextensions_v1_webhook_client_config) {
    listEntry_t *listEntry;
    apiextensions_v1_service_reference_free(apiextensions_v1_webhook_client_config->service);
    free(apiextensions_v1_webhook_client_config->url);
	free(apiextensions_v1_webhook_client_config);
}

cJSON *apiextensions_v1_webhook_client_config_convertToJSON(apiextensions_v1_webhook_client_config_t *apiextensions_v1_webhook_client_config) {
	cJSON *item = cJSON_CreateObject();

	// apiextensions_v1_webhook_client_config->caBundle
    if(apiextensions_v1_webhook_client_config->caBundle) { 
    if(cJSON_AddNumberToObject(item, "caBundle", apiextensions_v1_webhook_client_config->caBundle) == NULL) {
    goto fail; //Byte
    }
     } 


	// apiextensions_v1_webhook_client_config->service
    if(apiextensions_v1_webhook_client_config->service) { 
    cJSON *service_local_JSON = apiextensions_v1_service_reference_convertToJSON(apiextensions_v1_webhook_client_config->service);
    if(service_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "service", service_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// apiextensions_v1_webhook_client_config->url
    if(apiextensions_v1_webhook_client_config->url) { 
    if(cJSON_AddStringToObject(item, "url", apiextensions_v1_webhook_client_config->url) == NULL) {
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

apiextensions_v1_webhook_client_config_t *apiextensions_v1_webhook_client_config_parseFromJSON(cJSON *apiextensions_v1_webhook_client_configJSON){

    apiextensions_v1_webhook_client_config_t *apiextensions_v1_webhook_client_config_local_var = NULL;

    // apiextensions_v1_webhook_client_config->caBundle
    cJSON *caBundle = cJSON_GetObjectItemCaseSensitive(apiextensions_v1_webhook_client_configJSON, "caBundle");
    if (caBundle) { 
    if(!cJSON_IsNumber(caBundle))
    {
    goto end; //Byte
    }
    }

    // apiextensions_v1_webhook_client_config->service
    cJSON *service = cJSON_GetObjectItemCaseSensitive(apiextensions_v1_webhook_client_configJSON, "service");
    apiextensions_v1_service_reference_t *service_local_nonprim = NULL;
    if (service) { 
    service_local_nonprim = apiextensions_v1_service_reference_parseFromJSON(service); //nonprimitive
    }

    // apiextensions_v1_webhook_client_config->url
    cJSON *url = cJSON_GetObjectItemCaseSensitive(apiextensions_v1_webhook_client_configJSON, "url");
    if (url) { 
    if(!cJSON_IsString(url))
    {
    goto end; //String
    }
    }


    apiextensions_v1_webhook_client_config_local_var = apiextensions_v1_webhook_client_config_create (
        caBundle ? caBundle->valueint : 0,
        service ? service_local_nonprim : NULL,
        url ? strdup(url->valuestring) : NULL
        );

    return apiextensions_v1_webhook_client_config_local_var;
end:
    return NULL;

}
