#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "policy_v1beta1_se_linux_strategy_options.h"



policy_v1beta1_se_linux_strategy_options_t *policy_v1beta1_se_linux_strategy_options_create(
    char *rule,
    v1_se_linux_options_t *seLinuxOptions
    ) {
	policy_v1beta1_se_linux_strategy_options_t *policy_v1beta1_se_linux_strategy_options_local_var = malloc(sizeof(policy_v1beta1_se_linux_strategy_options_t));
    if (!policy_v1beta1_se_linux_strategy_options_local_var) {
        return NULL;
    }
	policy_v1beta1_se_linux_strategy_options_local_var->rule = rule;
	policy_v1beta1_se_linux_strategy_options_local_var->seLinuxOptions = seLinuxOptions;

	return policy_v1beta1_se_linux_strategy_options_local_var;
}


void policy_v1beta1_se_linux_strategy_options_free(policy_v1beta1_se_linux_strategy_options_t *policy_v1beta1_se_linux_strategy_options) {
    listEntry_t *listEntry;
    free(policy_v1beta1_se_linux_strategy_options->rule);
    v1_se_linux_options_free(policy_v1beta1_se_linux_strategy_options->seLinuxOptions);
	free(policy_v1beta1_se_linux_strategy_options);
}

cJSON *policy_v1beta1_se_linux_strategy_options_convertToJSON(policy_v1beta1_se_linux_strategy_options_t *policy_v1beta1_se_linux_strategy_options) {
	cJSON *item = cJSON_CreateObject();

	// policy_v1beta1_se_linux_strategy_options->rule
    if (!policy_v1beta1_se_linux_strategy_options->rule) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "rule", policy_v1beta1_se_linux_strategy_options->rule) == NULL) {
    goto fail; //String
    }


	// policy_v1beta1_se_linux_strategy_options->seLinuxOptions
    if(policy_v1beta1_se_linux_strategy_options->seLinuxOptions) { 
    cJSON *seLinuxOptions_local_JSON = v1_se_linux_options_convertToJSON(policy_v1beta1_se_linux_strategy_options->seLinuxOptions);
    if(seLinuxOptions_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "seLinuxOptions", seLinuxOptions_local_JSON);
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

policy_v1beta1_se_linux_strategy_options_t *policy_v1beta1_se_linux_strategy_options_parseFromJSON(cJSON *policy_v1beta1_se_linux_strategy_optionsJSON){

    policy_v1beta1_se_linux_strategy_options_t *policy_v1beta1_se_linux_strategy_options_local_var = NULL;

    // policy_v1beta1_se_linux_strategy_options->rule
    cJSON *rule = cJSON_GetObjectItemCaseSensitive(policy_v1beta1_se_linux_strategy_optionsJSON, "rule");
    if (!rule) {
        goto end;
    }

    
    if(!cJSON_IsString(rule))
    {
    goto end; //String
    }

    // policy_v1beta1_se_linux_strategy_options->seLinuxOptions
    cJSON *seLinuxOptions = cJSON_GetObjectItemCaseSensitive(policy_v1beta1_se_linux_strategy_optionsJSON, "seLinuxOptions");
    v1_se_linux_options_t *seLinuxOptions_local_nonprim = NULL;
    if (seLinuxOptions) { 
    seLinuxOptions_local_nonprim = v1_se_linux_options_parseFromJSON(seLinuxOptions); //nonprimitive
    }


    policy_v1beta1_se_linux_strategy_options_local_var = policy_v1beta1_se_linux_strategy_options_create (
        strdup(rule->valuestring),
        seLinuxOptions ? seLinuxOptions_local_nonprim : NULL
        );

    return policy_v1beta1_se_linux_strategy_options_local_var;
end:
    return NULL;

}
