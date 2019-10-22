#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "extensions_v1beta1_runtime_class_strategy_options.h"



extensions_v1beta1_runtime_class_strategy_options_t *extensions_v1beta1_runtime_class_strategy_options_create(
    list_t *allowedRuntimeClassNames,
    char *defaultRuntimeClassName
    ) {
	extensions_v1beta1_runtime_class_strategy_options_t *extensions_v1beta1_runtime_class_strategy_options_local_var = malloc(sizeof(extensions_v1beta1_runtime_class_strategy_options_t));
    if (!extensions_v1beta1_runtime_class_strategy_options_local_var) {
        return NULL;
    }
	extensions_v1beta1_runtime_class_strategy_options_local_var->allowedRuntimeClassNames = allowedRuntimeClassNames;
	extensions_v1beta1_runtime_class_strategy_options_local_var->defaultRuntimeClassName = defaultRuntimeClassName;

	return extensions_v1beta1_runtime_class_strategy_options_local_var;
}


void extensions_v1beta1_runtime_class_strategy_options_free(extensions_v1beta1_runtime_class_strategy_options_t *extensions_v1beta1_runtime_class_strategy_options) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, extensions_v1beta1_runtime_class_strategy_options->allowedRuntimeClassNames) {
		free(listEntry->data);
	}
	list_free(extensions_v1beta1_runtime_class_strategy_options->allowedRuntimeClassNames);
    free(extensions_v1beta1_runtime_class_strategy_options->defaultRuntimeClassName);
	free(extensions_v1beta1_runtime_class_strategy_options);
}

cJSON *extensions_v1beta1_runtime_class_strategy_options_convertToJSON(extensions_v1beta1_runtime_class_strategy_options_t *extensions_v1beta1_runtime_class_strategy_options) {
	cJSON *item = cJSON_CreateObject();

	// extensions_v1beta1_runtime_class_strategy_options->allowedRuntimeClassNames
    if (!extensions_v1beta1_runtime_class_strategy_options->allowedRuntimeClassNames) {
        goto fail;
    }
    
	cJSON *allowed_runtime_class_names = cJSON_AddArrayToObject(item, "allowedRuntimeClassNames");
	if(allowed_runtime_class_names == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *allowed_runtime_class_namesListEntry;
    list_ForEach(allowed_runtime_class_namesListEntry, extensions_v1beta1_runtime_class_strategy_options->allowedRuntimeClassNames) {
    if(cJSON_AddStringToObject(allowed_runtime_class_names, "", (char*)allowed_runtime_class_namesListEntry->data) == NULL)
    {
        goto fail;
    }
    }


	// extensions_v1beta1_runtime_class_strategy_options->defaultRuntimeClassName
    if(extensions_v1beta1_runtime_class_strategy_options->defaultRuntimeClassName) { 
    if(cJSON_AddStringToObject(item, "defaultRuntimeClassName", extensions_v1beta1_runtime_class_strategy_options->defaultRuntimeClassName) == NULL) {
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

extensions_v1beta1_runtime_class_strategy_options_t *extensions_v1beta1_runtime_class_strategy_options_parseFromJSON(cJSON *extensions_v1beta1_runtime_class_strategy_optionsJSON){

    extensions_v1beta1_runtime_class_strategy_options_t *extensions_v1beta1_runtime_class_strategy_options_local_var = NULL;

    // extensions_v1beta1_runtime_class_strategy_options->allowedRuntimeClassNames
    cJSON *allowedRuntimeClassNames = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_runtime_class_strategy_optionsJSON, "allowedRuntimeClassNames");
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

    // extensions_v1beta1_runtime_class_strategy_options->defaultRuntimeClassName
    cJSON *defaultRuntimeClassName = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_runtime_class_strategy_optionsJSON, "defaultRuntimeClassName");
    if (defaultRuntimeClassName) { 
    if(!cJSON_IsString(defaultRuntimeClassName))
    {
    goto end; //String
    }
    }


    extensions_v1beta1_runtime_class_strategy_options_local_var = extensions_v1beta1_runtime_class_strategy_options_create (
        allowed_runtime_class_namesList,
        defaultRuntimeClassName ? strdup(defaultRuntimeClassName->valuestring) : NULL
        );

    return extensions_v1beta1_runtime_class_strategy_options_local_var;
end:
    return NULL;

}
