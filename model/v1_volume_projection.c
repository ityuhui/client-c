#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_volume_projection.h"



v1_volume_projection_t *v1_volume_projection_create(
    v1_config_map_projection_t *configMap,
    v1_downward_api_projection_t *downwardAPI,
    v1_secret_projection_t *secret,
    v1_service_account_token_projection_t *serviceAccountToken
    ) {
	v1_volume_projection_t *v1_volume_projection_local_var = malloc(sizeof(v1_volume_projection_t));
    if (!v1_volume_projection_local_var) {
        return NULL;
    }
	v1_volume_projection_local_var->configMap = configMap;
	v1_volume_projection_local_var->downwardAPI = downwardAPI;
	v1_volume_projection_local_var->secret = secret;
	v1_volume_projection_local_var->serviceAccountToken = serviceAccountToken;

	return v1_volume_projection_local_var;
}


void v1_volume_projection_free(v1_volume_projection_t *v1_volume_projection) {
    listEntry_t *listEntry;
    v1_config_map_projection_free(v1_volume_projection->configMap);
    v1_downward_api_projection_free(v1_volume_projection->downwardAPI);
    v1_secret_projection_free(v1_volume_projection->secret);
    v1_service_account_token_projection_free(v1_volume_projection->serviceAccountToken);
	free(v1_volume_projection);
}

cJSON *v1_volume_projection_convertToJSON(v1_volume_projection_t *v1_volume_projection) {
	cJSON *item = cJSON_CreateObject();

	// v1_volume_projection->configMap
    if(v1_volume_projection->configMap) { 
    cJSON *configMap_local_JSON = v1_config_map_projection_convertToJSON(v1_volume_projection->configMap);
    if(configMap_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "configMap", configMap_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_volume_projection->downwardAPI
    if(v1_volume_projection->downwardAPI) { 
    cJSON *downwardAPI_local_JSON = v1_downward_api_projection_convertToJSON(v1_volume_projection->downwardAPI);
    if(downwardAPI_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "downwardAPI", downwardAPI_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_volume_projection->secret
    if(v1_volume_projection->secret) { 
    cJSON *secret_local_JSON = v1_secret_projection_convertToJSON(v1_volume_projection->secret);
    if(secret_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "secret", secret_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_volume_projection->serviceAccountToken
    if(v1_volume_projection->serviceAccountToken) { 
    cJSON *serviceAccountToken_local_JSON = v1_service_account_token_projection_convertToJSON(v1_volume_projection->serviceAccountToken);
    if(serviceAccountToken_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "serviceAccountToken", serviceAccountToken_local_JSON);
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

v1_volume_projection_t *v1_volume_projection_parseFromJSON(cJSON *v1_volume_projectionJSON){

    v1_volume_projection_t *v1_volume_projection_local_var = NULL;

    // v1_volume_projection->configMap
    cJSON *configMap = cJSON_GetObjectItemCaseSensitive(v1_volume_projectionJSON, "configMap");
    v1_config_map_projection_t *configMap_local_nonprim = NULL;
    if (configMap) { 
    configMap_local_nonprim = v1_config_map_projection_parseFromJSON(configMap); //nonprimitive
    }

    // v1_volume_projection->downwardAPI
    cJSON *downwardAPI = cJSON_GetObjectItemCaseSensitive(v1_volume_projectionJSON, "downwardAPI");
    v1_downward_api_projection_t *downwardAPI_local_nonprim = NULL;
    if (downwardAPI) { 
    downwardAPI_local_nonprim = v1_downward_api_projection_parseFromJSON(downwardAPI); //nonprimitive
    }

    // v1_volume_projection->secret
    cJSON *secret = cJSON_GetObjectItemCaseSensitive(v1_volume_projectionJSON, "secret");
    v1_secret_projection_t *secret_local_nonprim = NULL;
    if (secret) { 
    secret_local_nonprim = v1_secret_projection_parseFromJSON(secret); //nonprimitive
    }

    // v1_volume_projection->serviceAccountToken
    cJSON *serviceAccountToken = cJSON_GetObjectItemCaseSensitive(v1_volume_projectionJSON, "serviceAccountToken");
    v1_service_account_token_projection_t *serviceAccountToken_local_nonprim = NULL;
    if (serviceAccountToken) { 
    serviceAccountToken_local_nonprim = v1_service_account_token_projection_parseFromJSON(serviceAccountToken); //nonprimitive
    }


    v1_volume_projection_local_var = v1_volume_projection_create (
        configMap ? configMap_local_nonprim : NULL,
        downwardAPI ? downwardAPI_local_nonprim : NULL,
        secret ? secret_local_nonprim : NULL,
        serviceAccountToken ? serviceAccountToken_local_nonprim : NULL
        );

    return v1_volume_projection_local_var;
end:
    return NULL;

}
