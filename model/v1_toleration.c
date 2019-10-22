#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_toleration.h"



v1_toleration_t *v1_toleration_create(
    char *effect,
    char *key,
    char *operator,
    long tolerationSeconds,
    char *value
    ) {
	v1_toleration_t *v1_toleration_local_var = malloc(sizeof(v1_toleration_t));
    if (!v1_toleration_local_var) {
        return NULL;
    }
	v1_toleration_local_var->effect = effect;
	v1_toleration_local_var->key = key;
	v1_toleration_local_var->operator = operator;
	v1_toleration_local_var->tolerationSeconds = tolerationSeconds;
	v1_toleration_local_var->value = value;

	return v1_toleration_local_var;
}


void v1_toleration_free(v1_toleration_t *v1_toleration) {
    listEntry_t *listEntry;
    free(v1_toleration->effect);
    free(v1_toleration->key);
    free(v1_toleration->operator);
    free(v1_toleration->value);
	free(v1_toleration);
}

cJSON *v1_toleration_convertToJSON(v1_toleration_t *v1_toleration) {
	cJSON *item = cJSON_CreateObject();

	// v1_toleration->effect
    if(v1_toleration->effect) { 
    if(cJSON_AddStringToObject(item, "effect", v1_toleration->effect) == NULL) {
    goto fail; //String
    }
     } 


	// v1_toleration->key
    if(v1_toleration->key) { 
    if(cJSON_AddStringToObject(item, "key", v1_toleration->key) == NULL) {
    goto fail; //String
    }
     } 


	// v1_toleration->operator
    if(v1_toleration->operator) { 
    if(cJSON_AddStringToObject(item, "operator", v1_toleration->operator) == NULL) {
    goto fail; //String
    }
     } 


	// v1_toleration->tolerationSeconds
    if(v1_toleration->tolerationSeconds) { 
    if(cJSON_AddNumberToObject(item, "tolerationSeconds", v1_toleration->tolerationSeconds) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1_toleration->value
    if(v1_toleration->value) { 
    if(cJSON_AddStringToObject(item, "value", v1_toleration->value) == NULL) {
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

v1_toleration_t *v1_toleration_parseFromJSON(cJSON *v1_tolerationJSON){

    v1_toleration_t *v1_toleration_local_var = NULL;

    // v1_toleration->effect
    cJSON *effect = cJSON_GetObjectItemCaseSensitive(v1_tolerationJSON, "effect");
    if (effect) { 
    if(!cJSON_IsString(effect))
    {
    goto end; //String
    }
    }

    // v1_toleration->key
    cJSON *key = cJSON_GetObjectItemCaseSensitive(v1_tolerationJSON, "key");
    if (key) { 
    if(!cJSON_IsString(key))
    {
    goto end; //String
    }
    }

    // v1_toleration->operator
    cJSON *operator = cJSON_GetObjectItemCaseSensitive(v1_tolerationJSON, "operator");
    if (operator) { 
    if(!cJSON_IsString(operator))
    {
    goto end; //String
    }
    }

    // v1_toleration->tolerationSeconds
    cJSON *tolerationSeconds = cJSON_GetObjectItemCaseSensitive(v1_tolerationJSON, "tolerationSeconds");
    if (tolerationSeconds) { 
    if(!cJSON_IsNumber(tolerationSeconds))
    {
    goto end; //Numeric
    }
    }

    // v1_toleration->value
    cJSON *value = cJSON_GetObjectItemCaseSensitive(v1_tolerationJSON, "value");
    if (value) { 
    if(!cJSON_IsString(value))
    {
    goto end; //String
    }
    }


    v1_toleration_local_var = v1_toleration_create (
        effect ? strdup(effect->valuestring) : NULL,
        key ? strdup(key->valuestring) : NULL,
        operator ? strdup(operator->valuestring) : NULL,
        tolerationSeconds ? tolerationSeconds->valuedouble : 0,
        value ? strdup(value->valuestring) : NULL
        );

    return v1_toleration_local_var;
end:
    return NULL;

}
