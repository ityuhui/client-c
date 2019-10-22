#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "extensions_v1beta1_deployment_strategy.h"



extensions_v1beta1_deployment_strategy_t *extensions_v1beta1_deployment_strategy_create(
    extensions_v1beta1_rolling_update_deployment_t *rollingUpdate,
    char *type
    ) {
	extensions_v1beta1_deployment_strategy_t *extensions_v1beta1_deployment_strategy_local_var = malloc(sizeof(extensions_v1beta1_deployment_strategy_t));
    if (!extensions_v1beta1_deployment_strategy_local_var) {
        return NULL;
    }
	extensions_v1beta1_deployment_strategy_local_var->rollingUpdate = rollingUpdate;
	extensions_v1beta1_deployment_strategy_local_var->type = type;

	return extensions_v1beta1_deployment_strategy_local_var;
}


void extensions_v1beta1_deployment_strategy_free(extensions_v1beta1_deployment_strategy_t *extensions_v1beta1_deployment_strategy) {
    listEntry_t *listEntry;
    extensions_v1beta1_rolling_update_deployment_free(extensions_v1beta1_deployment_strategy->rollingUpdate);
    free(extensions_v1beta1_deployment_strategy->type);
	free(extensions_v1beta1_deployment_strategy);
}

cJSON *extensions_v1beta1_deployment_strategy_convertToJSON(extensions_v1beta1_deployment_strategy_t *extensions_v1beta1_deployment_strategy) {
	cJSON *item = cJSON_CreateObject();

	// extensions_v1beta1_deployment_strategy->rollingUpdate
    if(extensions_v1beta1_deployment_strategy->rollingUpdate) { 
    cJSON *rollingUpdate_local_JSON = extensions_v1beta1_rolling_update_deployment_convertToJSON(extensions_v1beta1_deployment_strategy->rollingUpdate);
    if(rollingUpdate_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "rollingUpdate", rollingUpdate_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// extensions_v1beta1_deployment_strategy->type
    if(extensions_v1beta1_deployment_strategy->type) { 
    if(cJSON_AddStringToObject(item, "type", extensions_v1beta1_deployment_strategy->type) == NULL) {
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

extensions_v1beta1_deployment_strategy_t *extensions_v1beta1_deployment_strategy_parseFromJSON(cJSON *extensions_v1beta1_deployment_strategyJSON){

    extensions_v1beta1_deployment_strategy_t *extensions_v1beta1_deployment_strategy_local_var = NULL;

    // extensions_v1beta1_deployment_strategy->rollingUpdate
    cJSON *rollingUpdate = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_deployment_strategyJSON, "rollingUpdate");
    extensions_v1beta1_rolling_update_deployment_t *rollingUpdate_local_nonprim = NULL;
    if (rollingUpdate) { 
    rollingUpdate_local_nonprim = extensions_v1beta1_rolling_update_deployment_parseFromJSON(rollingUpdate); //nonprimitive
    }

    // extensions_v1beta1_deployment_strategy->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_deployment_strategyJSON, "type");
    if (type) { 
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }
    }


    extensions_v1beta1_deployment_strategy_local_var = extensions_v1beta1_deployment_strategy_create (
        rollingUpdate ? rollingUpdate_local_nonprim : NULL,
        type ? strdup(type->valuestring) : NULL
        );

    return extensions_v1beta1_deployment_strategy_local_var;
end:
    return NULL;

}
