#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_env_from_source.h"



v1_env_from_source_t *v1_env_from_source_create(
    v1_config_map_env_source_t *configMapRef,
    char *prefix,
    v1_secret_env_source_t *secretRef
    ) {
	v1_env_from_source_t *v1_env_from_source_local_var = malloc(sizeof(v1_env_from_source_t));
    if (!v1_env_from_source_local_var) {
        return NULL;
    }
	v1_env_from_source_local_var->configMapRef = configMapRef;
	v1_env_from_source_local_var->prefix = prefix;
	v1_env_from_source_local_var->secretRef = secretRef;

	return v1_env_from_source_local_var;
}


void v1_env_from_source_free(v1_env_from_source_t *v1_env_from_source) {
    listEntry_t *listEntry;
    v1_config_map_env_source_free(v1_env_from_source->configMapRef);
    free(v1_env_from_source->prefix);
    v1_secret_env_source_free(v1_env_from_source->secretRef);
	free(v1_env_from_source);
}

cJSON *v1_env_from_source_convertToJSON(v1_env_from_source_t *v1_env_from_source) {
	cJSON *item = cJSON_CreateObject();

	// v1_env_from_source->configMapRef
    if(v1_env_from_source->configMapRef) { 
    cJSON *configMapRef_local_JSON = v1_config_map_env_source_convertToJSON(v1_env_from_source->configMapRef);
    if(configMapRef_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "configMapRef", configMapRef_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_env_from_source->prefix
    if(v1_env_from_source->prefix) { 
    if(cJSON_AddStringToObject(item, "prefix", v1_env_from_source->prefix) == NULL) {
    goto fail; //String
    }
     } 


	// v1_env_from_source->secretRef
    if(v1_env_from_source->secretRef) { 
    cJSON *secretRef_local_JSON = v1_secret_env_source_convertToJSON(v1_env_from_source->secretRef);
    if(secretRef_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "secretRef", secretRef_local_JSON);
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

v1_env_from_source_t *v1_env_from_source_parseFromJSON(cJSON *v1_env_from_sourceJSON){

    v1_env_from_source_t *v1_env_from_source_local_var = NULL;

    // v1_env_from_source->configMapRef
    cJSON *configMapRef = cJSON_GetObjectItemCaseSensitive(v1_env_from_sourceJSON, "configMapRef");
    v1_config_map_env_source_t *configMapRef_local_nonprim = NULL;
    if (configMapRef) { 
    configMapRef_local_nonprim = v1_config_map_env_source_parseFromJSON(configMapRef); //nonprimitive
    }

    // v1_env_from_source->prefix
    cJSON *prefix = cJSON_GetObjectItemCaseSensitive(v1_env_from_sourceJSON, "prefix");
    if (prefix) { 
    if(!cJSON_IsString(prefix))
    {
    goto end; //String
    }
    }

    // v1_env_from_source->secretRef
    cJSON *secretRef = cJSON_GetObjectItemCaseSensitive(v1_env_from_sourceJSON, "secretRef");
    v1_secret_env_source_t *secretRef_local_nonprim = NULL;
    if (secretRef) { 
    secretRef_local_nonprim = v1_secret_env_source_parseFromJSON(secretRef); //nonprimitive
    }


    v1_env_from_source_local_var = v1_env_from_source_create (
        configMapRef ? configMapRef_local_nonprim : NULL,
        prefix ? strdup(prefix->valuestring) : NULL,
        secretRef ? secretRef_local_nonprim : NULL
        );

    return v1_env_from_source_local_var;
end:
    return NULL;

}
