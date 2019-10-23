#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "extensions_v1beta1_scale_status.h"



extensions_v1beta1_scale_status_t *extensions_v1beta1_scale_status_create(
    int replicas,
    list_t* selector,
    char *targetSelector
    ) {
	extensions_v1beta1_scale_status_t *extensions_v1beta1_scale_status_local_var = malloc(sizeof(extensions_v1beta1_scale_status_t));
    if (!extensions_v1beta1_scale_status_local_var) {
        return NULL;
    }
	extensions_v1beta1_scale_status_local_var->replicas = replicas;
	extensions_v1beta1_scale_status_local_var->selector = selector;
	extensions_v1beta1_scale_status_local_var->targetSelector = targetSelector;

	return extensions_v1beta1_scale_status_local_var;
}


void extensions_v1beta1_scale_status_free(extensions_v1beta1_scale_status_t *extensions_v1beta1_scale_status) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, extensions_v1beta1_scale_status->selector) {
		keyValuePair_t *localMapKeyPair = (keyValuePair_t*) listEntry->data;
        free (localMapKeyPair->key);
        free (localMapKeyPair->value);
	}
	list_free(extensions_v1beta1_scale_status->selector);
    free(extensions_v1beta1_scale_status->targetSelector);
	free(extensions_v1beta1_scale_status);
}

cJSON *extensions_v1beta1_scale_status_convertToJSON(extensions_v1beta1_scale_status_t *extensions_v1beta1_scale_status) {
	cJSON *item = cJSON_CreateObject();

	// extensions_v1beta1_scale_status->replicas
    if (!extensions_v1beta1_scale_status->replicas) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "replicas", extensions_v1beta1_scale_status->replicas) == NULL) {
    goto fail; //Numeric
    }


	// extensions_v1beta1_scale_status->selector
    if(extensions_v1beta1_scale_status->selector) { 
	cJSON *selector = cJSON_AddObjectToObject(item, "selector");
	if(selector == NULL) {
		goto fail; //primitive map container
	}
    cJSON *localMapObject = cJSON_CreateObject(); //Memory free to be implemented in user code
	listEntry_t *selectorListEntry;
    if (extensions_v1beta1_scale_status->selector) {
    list_ForEach(selectorListEntry, extensions_v1beta1_scale_status->selector) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)selectorListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
        cJSON_AddItemToObject(selector,"", localMapObject);
    }
    }
     } 


	// extensions_v1beta1_scale_status->targetSelector
    if(extensions_v1beta1_scale_status->targetSelector) { 
    if(cJSON_AddStringToObject(item, "targetSelector", extensions_v1beta1_scale_status->targetSelector) == NULL) {
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

extensions_v1beta1_scale_status_t *extensions_v1beta1_scale_status_parseFromJSON(cJSON *extensions_v1beta1_scale_statusJSON){

    extensions_v1beta1_scale_status_t *extensions_v1beta1_scale_status_local_var = NULL;

    // extensions_v1beta1_scale_status->replicas
    cJSON *replicas = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_scale_statusJSON, "replicas");
    if (!replicas) {
        goto end;
    }

    
    if(!cJSON_IsNumber(replicas))
    {
    goto end; //Numeric
    }

    // extensions_v1beta1_scale_status->selector
    cJSON *selector = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_scale_statusJSON, "selector");
    list_t *List;
    if (selector) { 
    cJSON *_local_map;
    if(!cJSON_IsObject(selector)) {
        goto end;//primitive map container
    }
    List = list_create();
    keyValuePair_t *localMapKeyPair;
    cJSON_ArrayForEach(_local_map, selector)
    {
        if(!cJSON_IsNumber(_local_map))
        {
            goto end;
        }
        localMapKeyPair = keyValuePair_create(strdup(_local_map->string),&_local_map->valuedouble );
        list_addElement(List , localMapKeyPair);
    }
    }

    // extensions_v1beta1_scale_status->targetSelector
    cJSON *targetSelector = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_scale_statusJSON, "targetSelector");
    if (targetSelector) { 
    if(!cJSON_IsString(targetSelector))
    {
    goto end; //String
    }
    }


    extensions_v1beta1_scale_status_local_var = extensions_v1beta1_scale_status_create (
        replicas->valuedouble,
        selector ? List : NULL,
        targetSelector ? strdup(targetSelector->valuestring) : NULL
        );

    return extensions_v1beta1_scale_status_local_var;
end:
    return NULL;

}
