#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta2_scale_status.h"



v1beta2_scale_status_t *v1beta2_scale_status_create(
    int replicas,
    list_t* selector,
    char *targetSelector
    ) {
	v1beta2_scale_status_t *v1beta2_scale_status_local_var = malloc(sizeof(v1beta2_scale_status_t));
    if (!v1beta2_scale_status_local_var) {
        return NULL;
    }
	v1beta2_scale_status_local_var->replicas = replicas;
	v1beta2_scale_status_local_var->selector = selector;
	v1beta2_scale_status_local_var->targetSelector = targetSelector;

	return v1beta2_scale_status_local_var;
}


void v1beta2_scale_status_free(v1beta2_scale_status_t *v1beta2_scale_status) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, v1beta2_scale_status->selector) {
		keyValuePair_t *localMapKeyPair = (keyValuePair_t*) listEntry->data;
        free (localMapKeyPair->key);
        free (localMapKeyPair->value);
	}
	list_free(v1beta2_scale_status->selector);
    free(v1beta2_scale_status->targetSelector);
	free(v1beta2_scale_status);
}

cJSON *v1beta2_scale_status_convertToJSON(v1beta2_scale_status_t *v1beta2_scale_status) {
	cJSON *item = cJSON_CreateObject();

	// v1beta2_scale_status->replicas
    if (!v1beta2_scale_status->replicas) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "replicas", v1beta2_scale_status->replicas) == NULL) {
    goto fail; //Numeric
    }


	// v1beta2_scale_status->selector
    if(v1beta2_scale_status->selector) { 
	cJSON *selector = cJSON_AddObjectToObject(item, "selector");
	if(selector == NULL) {
		goto fail; //primitive map container
	}
    cJSON *localMapObject = cJSON_CreateObject(); //Memory free to be implemented in user code
	listEntry_t *selectorListEntry;
    if (v1beta2_scale_status->selector) {
    list_ForEach(selectorListEntry, v1beta2_scale_status->selector) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)selectorListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
        cJSON_AddItemToObject(selector,"", localMapObject);
    }
    }
     } 


	// v1beta2_scale_status->targetSelector
    if(v1beta2_scale_status->targetSelector) { 
    if(cJSON_AddStringToObject(item, "targetSelector", v1beta2_scale_status->targetSelector) == NULL) {
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

v1beta2_scale_status_t *v1beta2_scale_status_parseFromJSON(cJSON *v1beta2_scale_statusJSON){

    v1beta2_scale_status_t *v1beta2_scale_status_local_var = NULL;

    // v1beta2_scale_status->replicas
    cJSON *replicas = cJSON_GetObjectItemCaseSensitive(v1beta2_scale_statusJSON, "replicas");
    if (!replicas) {
        goto end;
    }

    
    if(!cJSON_IsNumber(replicas))
    {
    goto end; //Numeric
    }

    // v1beta2_scale_status->selector
    cJSON *selector = cJSON_GetObjectItemCaseSensitive(v1beta2_scale_statusJSON, "selector");
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

    // v1beta2_scale_status->targetSelector
    cJSON *targetSelector = cJSON_GetObjectItemCaseSensitive(v1beta2_scale_statusJSON, "targetSelector");
    if (targetSelector) { 
    if(!cJSON_IsString(targetSelector))
    {
    goto end; //String
    }
    }


    v1beta2_scale_status_local_var = v1beta2_scale_status_create (
        replicas->valuedouble,
        selector ? List : NULL,
        targetSelector ? strdup(targetSelector->valuestring) : NULL
        );

    return v1beta2_scale_status_local_var;
end:
    return NULL;

}
