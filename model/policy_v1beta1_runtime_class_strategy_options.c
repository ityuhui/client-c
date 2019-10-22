#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "policy_v1beta1_runtime_class_strategy_options.h"



policy_v1beta1_runtime_class_strategy_options_t *policy_v1beta1_runtime_class_strategy_options_create(
    list_t *allowedRuntimeClassNames,
    char *defaultRuntimeClassName
    ) {
	policy_v1beta1_runtime_class_strategy_options_t *policy_v1beta1_runtime_class_strategy_options_local_var = malloc(sizeof(policy_v1beta1_runtime_class_strategy_options_t));
    if (!policy_v1beta1_runtime_class_strategy_options_local_var) {
        return NULL;
    }
	policy_v1beta1_runtime_class_strategy_options_local_var->allowedRuntimeClassNames = allowedRuntimeClassNames;
	policy_v1beta1_runtime_class_strategy_options_local_var->defaultRuntimeClassName = defaultRuntimeClassName;

	return policy_v1beta1_runtime_class_strategy_options_local_var;
}


void policy_v1beta1_runtime_class_strategy_options_free(policy_v1beta1_runtime_class_strategy_options_t *policy_v1beta1_runtime_class_strategy_options) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, policy_v1beta1_runtime_class_strategy_options->allowedRuntimeClassNames) {
		free(listEntry->data);
	}
	list_free(policy_v1beta1_runtime_class_strategy_options->allowedRuntimeClassNames);
    free(policy_v1beta1_runtime_class_strategy_options->defaultRuntimeClassName);
	free(policy_v1beta1_runtime_class_strategy_options);
}

cJSON *policy_v1beta1_runtime_class_strategy_options_convertToJSON(policy_v1beta1_runtime_class_strategy_options_t *policy_v1beta1_runtime_class_strategy_options) {
	cJSON *item = cJSON_CreateObject();

	// policy_v1beta1_runtime_class_strategy_options->allowedRuntimeClassNames
    if (!policy_v1beta1_runtime_class_strategy_options->allowedRuntimeClassNames) {
        goto fail;
    }
    
	cJSON *allowed_runtime_class_names = cJSON_AddArrayToObject(item, "allowedRuntimeClassNames");
	if(allowed_runtime_class_names == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *allowed_runtime_class_namesListEntry;
    list_ForEach(allowed_runtime_class_namesListEntry, policy_v1beta1_runtime_class_strategy_options->allowedRuntimeClassNames) {
    if(cJSON_AddStringToObject(allowed_runtime_class_names, "", (char*)allowed_runtime_class_namesListEntry->data) == NULL)
    {
        goto fail;
    }
    }


	// policy_v1beta1_runtime_class_strategy_options->defaultRuntimeClassName
    if(policy_v1beta1_runtime_class_strategy_options->defaultRuntimeClassName) { 
    if(cJSON_AddStringToObject(item, "defaultRuntimeClassName", policy_v1beta1_runtime_class_strategy_options->defaultRuntimeClassName) == NULL) {
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

policy_v1beta1_runtime_class_strategy_options_t *policy_v1beta1_runtime_class_strategy_options_parseFromJSON(cJSON *policy_v1beta1_runtime_class_strategy_optionsJSON){

    policy_v1beta1_runtime_class_strategy_options_t *policy_v1beta1_runtime_class_strategy_options_local_var = NULL;

    // policy_v1beta1_runtime_class_strategy_options->allowedRuntimeClassNames
    cJSON *allowedRuntimeClassNames = cJSON_GetObjectItemCaseSensitive(policy_v1beta1_runtime_class_strategy_optionsJSON, "allowedRuntimeClassNames");
    if (!allowedRuntimeClassNames) {
        goto end;
    }

    list_t *allowed_runtime_class_namesList;
    
    cJSON *allowed_runtime_class_names_local;
    if(!cJSON_IsArray(allowedRuntimeClassNames)) {
        goto end;//primitive container
    }
    allowed_runtime_class_namesList = list_create();

    cJSON_ArrayForEach(allowed_runtime_class_names_local, allowedRuntimeClassNames)
    {
        if(!cJSON_IsString(allowed_runtime_class_names_local))
        {
            goto end;
        }
        list_addElement(allowed_runtime_class_namesList , strdup(allowed_runtime_class_names_local->valuestring));
    }

    // policy_v1beta1_runtime_class_strategy_options->defaultRuntimeClassName
    cJSON *defaultRuntimeClassName = cJSON_GetObjectItemCaseSensitive(policy_v1beta1_runtime_class_strategy_optionsJSON, "defaultRuntimeClassName");
    if (defaultRuntimeClassName) { 
    if(!cJSON_IsString(defaultRuntimeClassName))
    {
    goto end; //String
    }
    }


    policy_v1beta1_runtime_class_strategy_options_local_var = policy_v1beta1_runtime_class_strategy_options_create (
        allowed_runtime_class_namesList,
        defaultRuntimeClassName ? strdup(defaultRuntimeClassName->valuestring) : NULL
        );

    return policy_v1beta1_runtime_class_strategy_options_local_var;
end:
    return NULL;

}
