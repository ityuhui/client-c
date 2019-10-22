#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_session_affinity_config.h"



v1_session_affinity_config_t *v1_session_affinity_config_create(
    v1_client_ip_config_t *clientIP
    ) {
	v1_session_affinity_config_t *v1_session_affinity_config_local_var = malloc(sizeof(v1_session_affinity_config_t));
    if (!v1_session_affinity_config_local_var) {
        return NULL;
    }
	v1_session_affinity_config_local_var->clientIP = clientIP;

	return v1_session_affinity_config_local_var;
}


void v1_session_affinity_config_free(v1_session_affinity_config_t *v1_session_affinity_config) {
    listEntry_t *listEntry;
    v1_client_ip_config_free(v1_session_affinity_config->clientIP);
	free(v1_session_affinity_config);
}

cJSON *v1_session_affinity_config_convertToJSON(v1_session_affinity_config_t *v1_session_affinity_config) {
	cJSON *item = cJSON_CreateObject();

	// v1_session_affinity_config->clientIP
    if(v1_session_affinity_config->clientIP) { 
    cJSON *clientIP_local_JSON = v1_client_ip_config_convertToJSON(v1_session_affinity_config->clientIP);
    if(clientIP_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "clientIP", clientIP_local_JSON);
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

v1_session_affinity_config_t *v1_session_affinity_config_parseFromJSON(cJSON *v1_session_affinity_configJSON){

    v1_session_affinity_config_t *v1_session_affinity_config_local_var = NULL;

    // v1_session_affinity_config->clientIP
    cJSON *clientIP = cJSON_GetObjectItemCaseSensitive(v1_session_affinity_configJSON, "clientIP");
    v1_client_ip_config_t *clientIP_local_nonprim = NULL;
    if (clientIP) { 
    clientIP_local_nonprim = v1_client_ip_config_parseFromJSON(clientIP); //nonprimitive
    }


    v1_session_affinity_config_local_var = v1_session_affinity_config_create (
        clientIP ? clientIP_local_nonprim : NULL
        );

    return v1_session_affinity_config_local_var;
end:
    return NULL;

}
