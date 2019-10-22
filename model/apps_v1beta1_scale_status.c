#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "apps_v1beta1_scale_status.h"



apps_v1beta1_scale_status_t *apps_v1beta1_scale_status_create(
    int replicas,
    list_t* selector,
    char *targetSelector
    ) {
	apps_v1beta1_scale_status_t *apps_v1beta1_scale_status_local_var = malloc(sizeof(apps_v1beta1_scale_status_t));
    if (!apps_v1beta1_scale_status_local_var) {
        return NULL;
    }
	apps_v1beta1_scale_status_local_var->replicas = replicas;
	apps_v1beta1_scale_status_local_var->selector = selector;
	apps_v1beta1_scale_status_local_var->targetSelector = targetSelector;

	return apps_v1beta1_scale_status_local_var;
}


void apps_v1beta1_scale_status_free(apps_v1beta1_scale_status_t *apps_v1beta1_scale_status) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, apps_v1beta1_scale_status->selector) {
		keyValuePair_t *localMapKeyPair = (keyValuePair_t*) listEntry->data;
        //yhwa free (localKeyValue->key);
        //yhwa free (localKeyValue->value);
	}
	list_free(apps_v1beta1_scale_status->selector);
    free(apps_v1beta1_scale_status->targetSelector);
	free(apps_v1beta1_scale_status);
}

cJSON *apps_v1beta1_scale_status_convertToJSON(apps_v1beta1_scale_status_t *apps_v1beta1_scale_status) {
	cJSON *item = cJSON_CreateObject();

	// apps_v1beta1_scale_status->replicas
    if (!apps_v1beta1_scale_status->replicas) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "replicas", apps_v1beta1_scale_status->replicas) == NULL) {
    goto fail; //Numeric
    }


	// apps_v1beta1_scale_status->selector
    if(apps_v1beta1_scale_status->selector) { 
	cJSON *selector = cJSON_AddObjectToObject(item, "selector");
	if(selector == NULL) {
		goto fail; //primitive map container
	}
    cJSON *localMapObject = cJSON_CreateObject(); //Memory free to be implemented in user code
	listEntry_t *selectorListEntry;
    if (apps_v1beta1_scale_status->selector) {
    list_ForEach(selectorListEntry, apps_v1beta1_scale_status->selector) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)selectorListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
        cJSON_AddItemToObject(selector,"", localMapObject);
    }
    }
     } 


	// apps_v1beta1_scale_status->targetSelector
    if(apps_v1beta1_scale_status->targetSelector) { 
    if(cJSON_AddStringToObject(item, "targetSelector", apps_v1beta1_scale_status->targetSelector) == NULL) {
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

apps_v1beta1_scale_status_t *apps_v1beta1_scale_status_parseFromJSON(cJSON *apps_v1beta1_scale_statusJSON){

    apps_v1beta1_scale_status_t *apps_v1beta1_scale_status_local_var = NULL;

    // apps_v1beta1_scale_status->replicas
    cJSON *replicas = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_scale_statusJSON, "replicas");
    if (!replicas) {
        goto end;
    }

    
    if(!cJSON_IsNumber(replicas))
    {
    goto end; //Numeric
    }

    // apps_v1beta1_scale_status->selector
    cJSON *selector = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_scale_statusJSON, "selector");
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

    // apps_v1beta1_scale_status->targetSelector
    cJSON *targetSelector = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_scale_statusJSON, "targetSelector");
    if (targetSelector) { 
    if(!cJSON_IsString(targetSelector))
    {
    goto end; //String
    }
    }


    apps_v1beta1_scale_status_local_var = apps_v1beta1_scale_status_create (
        replicas->valuedouble,
        selector ? List : NULL,
        targetSelector ? strdup(targetSelector->valuestring) : NULL
        );

    return apps_v1beta1_scale_status_local_var;
end:
    return NULL;

}
