#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_webhook.h"



v1alpha1_webhook_t *v1alpha1_webhook_create(
    v1alpha1_webhook_client_config_t *clientConfig,
    v1alpha1_webhook_throttle_config_t *throttle
    ) {
	v1alpha1_webhook_t *v1alpha1_webhook_local_var = malloc(sizeof(v1alpha1_webhook_t));
    if (!v1alpha1_webhook_local_var) {
        return NULL;
    }
	v1alpha1_webhook_local_var->clientConfig = clientConfig;
	v1alpha1_webhook_local_var->throttle = throttle;

	return v1alpha1_webhook_local_var;
}


void v1alpha1_webhook_free(v1alpha1_webhook_t *v1alpha1_webhook) {
    listEntry_t *listEntry;
    v1alpha1_webhook_client_config_free(v1alpha1_webhook->clientConfig);
    v1alpha1_webhook_throttle_config_free(v1alpha1_webhook->throttle);
	free(v1alpha1_webhook);
}

cJSON *v1alpha1_webhook_convertToJSON(v1alpha1_webhook_t *v1alpha1_webhook) {
	cJSON *item = cJSON_CreateObject();

	// v1alpha1_webhook->clientConfig
    if (!v1alpha1_webhook->clientConfig) {
        goto fail;
    }
    
    cJSON *clientConfig_local_JSON = v1alpha1_webhook_client_config_convertToJSON(v1alpha1_webhook->clientConfig);
    if(clientConfig_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "clientConfig", clientConfig_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


	// v1alpha1_webhook->throttle
    if(v1alpha1_webhook->throttle) { 
    cJSON *throttle_local_JSON = v1alpha1_webhook_throttle_config_convertToJSON(v1alpha1_webhook->throttle);
    if(throttle_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "throttle", throttle_local_JSON);
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

v1alpha1_webhook_t *v1alpha1_webhook_parseFromJSON(cJSON *v1alpha1_webhookJSON){

    v1alpha1_webhook_t *v1alpha1_webhook_local_var = NULL;

    // v1alpha1_webhook->clientConfig
    cJSON *clientConfig = cJSON_GetObjectItemCaseSensitive(v1alpha1_webhookJSON, "clientConfig");
    if (!clientConfig) {
        goto end;
    }

    v1alpha1_webhook_client_config_t *clientConfig_local_nonprim = NULL;
    
    clientConfig_local_nonprim = v1alpha1_webhook_client_config_parseFromJSON(clientConfig); //nonprimitive

    // v1alpha1_webhook->throttle
    cJSON *throttle = cJSON_GetObjectItemCaseSensitive(v1alpha1_webhookJSON, "throttle");
    v1alpha1_webhook_throttle_config_t *throttle_local_nonprim = NULL;
    if (throttle) { 
    throttle_local_nonprim = v1alpha1_webhook_throttle_config_parseFromJSON(throttle); //nonprimitive
    }


    v1alpha1_webhook_local_var = v1alpha1_webhook_create (
        clientConfig_local_nonprim,
        throttle ? throttle_local_nonprim : NULL
        );

    return v1alpha1_webhook_local_var;
end:
    return NULL;

}
