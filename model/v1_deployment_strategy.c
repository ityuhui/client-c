#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_deployment_strategy.h"



v1_deployment_strategy_t *v1_deployment_strategy_create(
    v1_rolling_update_deployment_t *rollingUpdate,
    char *type
    ) {
	v1_deployment_strategy_t *v1_deployment_strategy_local_var = malloc(sizeof(v1_deployment_strategy_t));
    if (!v1_deployment_strategy_local_var) {
        return NULL;
    }
	v1_deployment_strategy_local_var->rollingUpdate = rollingUpdate;
	v1_deployment_strategy_local_var->type = type;

	return v1_deployment_strategy_local_var;
}


void v1_deployment_strategy_free(v1_deployment_strategy_t *v1_deployment_strategy) {
    listEntry_t *listEntry;
    v1_rolling_update_deployment_free(v1_deployment_strategy->rollingUpdate);
    free(v1_deployment_strategy->type);
	free(v1_deployment_strategy);
}

cJSON *v1_deployment_strategy_convertToJSON(v1_deployment_strategy_t *v1_deployment_strategy) {
	cJSON *item = cJSON_CreateObject();

	// v1_deployment_strategy->rollingUpdate
    if(v1_deployment_strategy->rollingUpdate) { 
    cJSON *rollingUpdate_local_JSON = v1_rolling_update_deployment_convertToJSON(v1_deployment_strategy->rollingUpdate);
    if(rollingUpdate_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "rollingUpdate", rollingUpdate_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_deployment_strategy->type
    if(v1_deployment_strategy->type) { 
    if(cJSON_AddStringToObject(item, "type", v1_deployment_strategy->type) == NULL) {
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

v1_deployment_strategy_t *v1_deployment_strategy_parseFromJSON(cJSON *v1_deployment_strategyJSON){

    v1_deployment_strategy_t *v1_deployment_strategy_local_var = NULL;

    // v1_deployment_strategy->rollingUpdate
    cJSON *rollingUpdate = cJSON_GetObjectItemCaseSensitive(v1_deployment_strategyJSON, "rollingUpdate");
    v1_rolling_update_deployment_t *rollingUpdate_local_nonprim = NULL;
    if (rollingUpdate) { 
    rollingUpdate_local_nonprim = v1_rolling_update_deployment_parseFromJSON(rollingUpdate); //nonprimitive
    }

    // v1_deployment_strategy->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(v1_deployment_strategyJSON, "type");
    if (type) { 
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }
    }


    v1_deployment_strategy_local_var = v1_deployment_strategy_create (
        rollingUpdate ? rollingUpdate_local_nonprim : NULL,
        type ? strdup(type->valuestring) : NULL
        );

    return v1_deployment_strategy_local_var;
end:
    return NULL;

}
