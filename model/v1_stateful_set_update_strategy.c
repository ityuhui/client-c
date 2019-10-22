#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_stateful_set_update_strategy.h"



v1_stateful_set_update_strategy_t *v1_stateful_set_update_strategy_create(
    v1_rolling_update_stateful_set_strategy_t *rollingUpdate,
    char *type
    ) {
	v1_stateful_set_update_strategy_t *v1_stateful_set_update_strategy_local_var = malloc(sizeof(v1_stateful_set_update_strategy_t));
    if (!v1_stateful_set_update_strategy_local_var) {
        return NULL;
    }
	v1_stateful_set_update_strategy_local_var->rollingUpdate = rollingUpdate;
	v1_stateful_set_update_strategy_local_var->type = type;

	return v1_stateful_set_update_strategy_local_var;
}


void v1_stateful_set_update_strategy_free(v1_stateful_set_update_strategy_t *v1_stateful_set_update_strategy) {
    listEntry_t *listEntry;
    v1_rolling_update_stateful_set_strategy_free(v1_stateful_set_update_strategy->rollingUpdate);
    free(v1_stateful_set_update_strategy->type);
	free(v1_stateful_set_update_strategy);
}

cJSON *v1_stateful_set_update_strategy_convertToJSON(v1_stateful_set_update_strategy_t *v1_stateful_set_update_strategy) {
	cJSON *item = cJSON_CreateObject();

	// v1_stateful_set_update_strategy->rollingUpdate
    if(v1_stateful_set_update_strategy->rollingUpdate) { 
    cJSON *rollingUpdate_local_JSON = v1_rolling_update_stateful_set_strategy_convertToJSON(v1_stateful_set_update_strategy->rollingUpdate);
    if(rollingUpdate_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "rollingUpdate", rollingUpdate_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_stateful_set_update_strategy->type
    if(v1_stateful_set_update_strategy->type) { 
    if(cJSON_AddStringToObject(item, "type", v1_stateful_set_update_strategy->type) == NULL) {
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

v1_stateful_set_update_strategy_t *v1_stateful_set_update_strategy_parseFromJSON(cJSON *v1_stateful_set_update_strategyJSON){

    v1_stateful_set_update_strategy_t *v1_stateful_set_update_strategy_local_var = NULL;

    // v1_stateful_set_update_strategy->rollingUpdate
    cJSON *rollingUpdate = cJSON_GetObjectItemCaseSensitive(v1_stateful_set_update_strategyJSON, "rollingUpdate");
    v1_rolling_update_stateful_set_strategy_t *rollingUpdate_local_nonprim = NULL;
    if (rollingUpdate) { 
    rollingUpdate_local_nonprim = v1_rolling_update_stateful_set_strategy_parseFromJSON(rollingUpdate); //nonprimitive
    }

    // v1_stateful_set_update_strategy->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(v1_stateful_set_update_strategyJSON, "type");
    if (type) { 
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }
    }


    v1_stateful_set_update_strategy_local_var = v1_stateful_set_update_strategy_create (
        rollingUpdate ? rollingUpdate_local_nonprim : NULL,
        type ? strdup(type->valuestring) : NULL
        );

    return v1_stateful_set_update_strategy_local_var;
end:
    return NULL;

}
