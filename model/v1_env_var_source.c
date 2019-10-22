#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_env_var_source.h"



v1_env_var_source_t *v1_env_var_source_create(
    v1_config_map_key_selector_t *configMapKeyRef,
    v1_object_field_selector_t *fieldRef,
    v1_resource_field_selector_t *resourceFieldRef,
    v1_secret_key_selector_t *secretKeyRef
    ) {
	v1_env_var_source_t *v1_env_var_source_local_var = malloc(sizeof(v1_env_var_source_t));
    if (!v1_env_var_source_local_var) {
        return NULL;
    }
	v1_env_var_source_local_var->configMapKeyRef = configMapKeyRef;
	v1_env_var_source_local_var->fieldRef = fieldRef;
	v1_env_var_source_local_var->resourceFieldRef = resourceFieldRef;
	v1_env_var_source_local_var->secretKeyRef = secretKeyRef;

	return v1_env_var_source_local_var;
}


void v1_env_var_source_free(v1_env_var_source_t *v1_env_var_source) {
    listEntry_t *listEntry;
    v1_config_map_key_selector_free(v1_env_var_source->configMapKeyRef);
    v1_object_field_selector_free(v1_env_var_source->fieldRef);
    v1_resource_field_selector_free(v1_env_var_source->resourceFieldRef);
    v1_secret_key_selector_free(v1_env_var_source->secretKeyRef);
	free(v1_env_var_source);
}

cJSON *v1_env_var_source_convertToJSON(v1_env_var_source_t *v1_env_var_source) {
	cJSON *item = cJSON_CreateObject();

	// v1_env_var_source->configMapKeyRef
    if(v1_env_var_source->configMapKeyRef) { 
    cJSON *configMapKeyRef_local_JSON = v1_config_map_key_selector_convertToJSON(v1_env_var_source->configMapKeyRef);
    if(configMapKeyRef_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "configMapKeyRef", configMapKeyRef_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_env_var_source->fieldRef
    if(v1_env_var_source->fieldRef) { 
    cJSON *fieldRef_local_JSON = v1_object_field_selector_convertToJSON(v1_env_var_source->fieldRef);
    if(fieldRef_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "fieldRef", fieldRef_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_env_var_source->resourceFieldRef
    if(v1_env_var_source->resourceFieldRef) { 
    cJSON *resourceFieldRef_local_JSON = v1_resource_field_selector_convertToJSON(v1_env_var_source->resourceFieldRef);
    if(resourceFieldRef_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "resourceFieldRef", resourceFieldRef_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_env_var_source->secretKeyRef
    if(v1_env_var_source->secretKeyRef) { 
    cJSON *secretKeyRef_local_JSON = v1_secret_key_selector_convertToJSON(v1_env_var_source->secretKeyRef);
    if(secretKeyRef_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "secretKeyRef", secretKeyRef_local_JSON);
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

v1_env_var_source_t *v1_env_var_source_parseFromJSON(cJSON *v1_env_var_sourceJSON){

    v1_env_var_source_t *v1_env_var_source_local_var = NULL;

    // v1_env_var_source->configMapKeyRef
    cJSON *configMapKeyRef = cJSON_GetObjectItemCaseSensitive(v1_env_var_sourceJSON, "configMapKeyRef");
    v1_config_map_key_selector_t *configMapKeyRef_local_nonprim = NULL;
    if (configMapKeyRef) { 
    configMapKeyRef_local_nonprim = v1_config_map_key_selector_parseFromJSON(configMapKeyRef); //nonprimitive
    }

    // v1_env_var_source->fieldRef
    cJSON *fieldRef = cJSON_GetObjectItemCaseSensitive(v1_env_var_sourceJSON, "fieldRef");
    v1_object_field_selector_t *fieldRef_local_nonprim = NULL;
    if (fieldRef) { 
    fieldRef_local_nonprim = v1_object_field_selector_parseFromJSON(fieldRef); //nonprimitive
    }

    // v1_env_var_source->resourceFieldRef
    cJSON *resourceFieldRef = cJSON_GetObjectItemCaseSensitive(v1_env_var_sourceJSON, "resourceFieldRef");
    v1_resource_field_selector_t *resourceFieldRef_local_nonprim = NULL;
    if (resourceFieldRef) { 
    resourceFieldRef_local_nonprim = v1_resource_field_selector_parseFromJSON(resourceFieldRef); //nonprimitive
    }

    // v1_env_var_source->secretKeyRef
    cJSON *secretKeyRef = cJSON_GetObjectItemCaseSensitive(v1_env_var_sourceJSON, "secretKeyRef");
    v1_secret_key_selector_t *secretKeyRef_local_nonprim = NULL;
    if (secretKeyRef) { 
    secretKeyRef_local_nonprim = v1_secret_key_selector_parseFromJSON(secretKeyRef); //nonprimitive
    }


    v1_env_var_source_local_var = v1_env_var_source_create (
        configMapKeyRef ? configMapKeyRef_local_nonprim : NULL,
        fieldRef ? fieldRef_local_nonprim : NULL,
        resourceFieldRef ? resourceFieldRef_local_nonprim : NULL,
        secretKeyRef ? secretKeyRef_local_nonprim : NULL
        );

    return v1_env_var_source_local_var;
end:
    return NULL;

}
