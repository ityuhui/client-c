#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_client_ip_config.h"



v1_client_ip_config_t *v1_client_ip_config_create(
    int timeoutSeconds
    ) {
	v1_client_ip_config_t *v1_client_ip_config_local_var = malloc(sizeof(v1_client_ip_config_t));
    if (!v1_client_ip_config_local_var) {
        return NULL;
    }
	v1_client_ip_config_local_var->timeoutSeconds = timeoutSeconds;

	return v1_client_ip_config_local_var;
}


void v1_client_ip_config_free(v1_client_ip_config_t *v1_client_ip_config) {
    listEntry_t *listEntry;
	free(v1_client_ip_config);
}

cJSON *v1_client_ip_config_convertToJSON(v1_client_ip_config_t *v1_client_ip_config) {
	cJSON *item = cJSON_CreateObject();

	// v1_client_ip_config->timeoutSeconds
    if(v1_client_ip_config->timeoutSeconds) { 
    if(cJSON_AddNumberToObject(item, "timeoutSeconds", v1_client_ip_config->timeoutSeconds) == NULL) {
    goto fail; //Numeric
    }
     } 

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1_client_ip_config_t *v1_client_ip_config_parseFromJSON(cJSON *v1_client_ip_configJSON){

    v1_client_ip_config_t *v1_client_ip_config_local_var = NULL;

    // v1_client_ip_config->timeoutSeconds
    cJSON *timeoutSeconds = cJSON_GetObjectItemCaseSensitive(v1_client_ip_configJSON, "timeoutSeconds");
    if (timeoutSeconds) { 
    if(!cJSON_IsNumber(timeoutSeconds))
    {
    goto end; //Numeric
    }
    }


    v1_client_ip_config_local_var = v1_client_ip_config_create (
        timeoutSeconds ? timeoutSeconds->valuedouble : 0
        );

    return v1_client_ip_config_local_var;
end:
    return NULL;

}
