#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_limit_range_item.h"



v1_limit_range_item_t *v1_limit_range_item_create(
    list_t* default,
    list_t* defaultRequest,
    list_t* max,
    list_t* maxLimitRequestRatio,
    list_t* min,
    char *type
    ) {
	v1_limit_range_item_t *v1_limit_range_item_local_var = malloc(sizeof(v1_limit_range_item_t));
    if (!v1_limit_range_item_local_var) {
        return NULL;
    }
	v1_limit_range_item_local_var->default = default;
	v1_limit_range_item_local_var->defaultRequest = defaultRequest;
	v1_limit_range_item_local_var->max = max;
	v1_limit_range_item_local_var->maxLimitRequestRatio = maxLimitRequestRatio;
	v1_limit_range_item_local_var->min = min;
	v1_limit_range_item_local_var->type = type;

	return v1_limit_range_item_local_var;
}


void v1_limit_range_item_free(v1_limit_range_item_t *v1_limit_range_item) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, v1_limit_range_item->default) {
		keyValuePair_t *localMapKeyPair = (keyValuePair_t*) listEntry->data;
        free (localKeyValue->key);
        free (localKeyValue->value);
	}
	list_free(v1_limit_range_item->default);
	list_ForEach(listEntry, v1_limit_range_item->defaultRequest) {
		keyValuePair_t *localMapKeyPair = (keyValuePair_t*) listEntry->data;
        free (localKeyValue->key);
        free (localKeyValue->value);
	}
	list_free(v1_limit_range_item->defaultRequest);
	list_ForEach(listEntry, v1_limit_range_item->max) {
		keyValuePair_t *localMapKeyPair = (keyValuePair_t*) listEntry->data;
        free (localKeyValue->key);
        free (localKeyValue->value);
	}
	list_free(v1_limit_range_item->max);
	list_ForEach(listEntry, v1_limit_range_item->maxLimitRequestRatio) {
		keyValuePair_t *localMapKeyPair = (keyValuePair_t*) listEntry->data;
        free (localKeyValue->key);
        free (localKeyValue->value);
	}
	list_free(v1_limit_range_item->maxLimitRequestRatio);
	list_ForEach(listEntry, v1_limit_range_item->min) {
		keyValuePair_t *localMapKeyPair = (keyValuePair_t*) listEntry->data;
        free (localKeyValue->key);
        free (localKeyValue->value);
	}
	list_free(v1_limit_range_item->min);
    free(v1_limit_range_item->type);
	free(v1_limit_range_item);
}

cJSON *v1_limit_range_item_convertToJSON(v1_limit_range_item_t *v1_limit_range_item) {
	cJSON *item = cJSON_CreateObject();

	// v1_limit_range_item->default
    if(v1_limit_range_item->default) { 
	cJSON *default = cJSON_AddObjectToObject(item, "default");
	if(default == NULL) {
		goto fail; //primitive map container
	}
    cJSON *localMapObject = cJSON_CreateObject(); //Memory free to be implemented in user code
	listEntry_t *defaultListEntry;
    if (v1_limit_range_item->default) {
    list_ForEach(defaultListEntry, v1_limit_range_item->default) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)defaultListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
        cJSON_AddItemToObject(default,"", localMapObject);
    }
    }
     } 


	// v1_limit_range_item->defaultRequest
    if(v1_limit_range_item->defaultRequest) { 
	cJSON *defaultRequest = cJSON_AddObjectToObject(item, "defaultRequest");
	if(defaultRequest == NULL) {
		goto fail; //primitive map container
	}
    cJSON *localMapObject = cJSON_CreateObject(); //Memory free to be implemented in user code
	listEntry_t *defaultRequestListEntry;
    if (v1_limit_range_item->defaultRequest) {
    list_ForEach(defaultRequestListEntry, v1_limit_range_item->defaultRequest) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)defaultRequestListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
        cJSON_AddItemToObject(defaultRequest,"", localMapObject);
    }
    }
     } 


	// v1_limit_range_item->max
    if(v1_limit_range_item->max) { 
	cJSON *max = cJSON_AddObjectToObject(item, "max");
	if(max == NULL) {
		goto fail; //primitive map container
	}
    cJSON *localMapObject = cJSON_CreateObject(); //Memory free to be implemented in user code
	listEntry_t *maxListEntry;
    if (v1_limit_range_item->max) {
    list_ForEach(maxListEntry, v1_limit_range_item->max) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)maxListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
        cJSON_AddItemToObject(max,"", localMapObject);
    }
    }
     } 


	// v1_limit_range_item->maxLimitRequestRatio
    if(v1_limit_range_item->maxLimitRequestRatio) { 
	cJSON *maxLimitRequestRatio = cJSON_AddObjectToObject(item, "maxLimitRequestRatio");
	if(maxLimitRequestRatio == NULL) {
		goto fail; //primitive map container
	}
    cJSON *localMapObject = cJSON_CreateObject(); //Memory free to be implemented in user code
	listEntry_t *maxLimitRequestRatioListEntry;
    if (v1_limit_range_item->maxLimitRequestRatio) {
    list_ForEach(maxLimitRequestRatioListEntry, v1_limit_range_item->maxLimitRequestRatio) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)maxLimitRequestRatioListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
        cJSON_AddItemToObject(maxLimitRequestRatio,"", localMapObject);
    }
    }
     } 


	// v1_limit_range_item->min
    if(v1_limit_range_item->min) { 
	cJSON *min = cJSON_AddObjectToObject(item, "min");
	if(min == NULL) {
		goto fail; //primitive map container
	}
    cJSON *localMapObject = cJSON_CreateObject(); //Memory free to be implemented in user code
	listEntry_t *minListEntry;
    if (v1_limit_range_item->min) {
    list_ForEach(minListEntry, v1_limit_range_item->min) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)minListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
        cJSON_AddItemToObject(min,"", localMapObject);
    }
    }
     } 


	// v1_limit_range_item->type
    if(v1_limit_range_item->type) { 
    if(cJSON_AddStringToObject(item, "type", v1_limit_range_item->type) == NULL) {
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

v1_limit_range_item_t *v1_limit_range_item_parseFromJSON(cJSON *v1_limit_range_itemJSON){

    v1_limit_range_item_t *v1_limit_range_item_local_var = NULL;

    // v1_limit_range_item->default
    cJSON *default = cJSON_GetObjectItemCaseSensitive(v1_limit_range_itemJSON, "default");
    list_t *List;
    if (default) { 
    cJSON *_local_map;
    if(!cJSON_IsObject(default)) {
        goto end;//primitive map container
    }
    List = list_create();
    keyValuePair_t *localMapKeyPair;
    cJSON_ArrayForEach(_local_map, default)
    {
        if(!cJSON_IsNumber(_local_map))
        {
            goto end;
        }
        localMapKeyPair = keyValuePair_create(strdup(_local_map->string),&_local_map->valuedouble );
        list_addElement(List , localMapKeyPair);
    }
    }

    // v1_limit_range_item->defaultRequest
    cJSON *defaultRequest = cJSON_GetObjectItemCaseSensitive(v1_limit_range_itemJSON, "defaultRequest");
    list_t *List;
    if (defaultRequest) { 
    cJSON *_local_map;
    if(!cJSON_IsObject(defaultRequest)) {
        goto end;//primitive map container
    }
    List = list_create();
    keyValuePair_t *localMapKeyPair;
    cJSON_ArrayForEach(_local_map, defaultRequest)
    {
        if(!cJSON_IsNumber(_local_map))
        {
            goto end;
        }
        localMapKeyPair = keyValuePair_create(strdup(_local_map->string),&_local_map->valuedouble );
        list_addElement(List , localMapKeyPair);
    }
    }

    // v1_limit_range_item->max
    cJSON *max = cJSON_GetObjectItemCaseSensitive(v1_limit_range_itemJSON, "max");
    list_t *List;
    if (max) { 
    cJSON *_local_map;
    if(!cJSON_IsObject(max)) {
        goto end;//primitive map container
    }
    List = list_create();
    keyValuePair_t *localMapKeyPair;
    cJSON_ArrayForEach(_local_map, max)
    {
        if(!cJSON_IsNumber(_local_map))
        {
            goto end;
        }
        localMapKeyPair = keyValuePair_create(strdup(_local_map->string),&_local_map->valuedouble );
        list_addElement(List , localMapKeyPair);
    }
    }

    // v1_limit_range_item->maxLimitRequestRatio
    cJSON *maxLimitRequestRatio = cJSON_GetObjectItemCaseSensitive(v1_limit_range_itemJSON, "maxLimitRequestRatio");
    list_t *List;
    if (maxLimitRequestRatio) { 
    cJSON *_local_map;
    if(!cJSON_IsObject(maxLimitRequestRatio)) {
        goto end;//primitive map container
    }
    List = list_create();
    keyValuePair_t *localMapKeyPair;
    cJSON_ArrayForEach(_local_map, maxLimitRequestRatio)
    {
        if(!cJSON_IsNumber(_local_map))
        {
            goto end;
        }
        localMapKeyPair = keyValuePair_create(strdup(_local_map->string),&_local_map->valuedouble );
        list_addElement(List , localMapKeyPair);
    }
    }

    // v1_limit_range_item->min
    cJSON *min = cJSON_GetObjectItemCaseSensitive(v1_limit_range_itemJSON, "min");
    list_t *List;
    if (min) { 
    cJSON *_local_map;
    if(!cJSON_IsObject(min)) {
        goto end;//primitive map container
    }
    List = list_create();
    keyValuePair_t *localMapKeyPair;
    cJSON_ArrayForEach(_local_map, min)
    {
        if(!cJSON_IsNumber(_local_map))
        {
            goto end;
        }
        localMapKeyPair = keyValuePair_create(strdup(_local_map->string),&_local_map->valuedouble );
        list_addElement(List , localMapKeyPair);
    }
    }

    // v1_limit_range_item->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(v1_limit_range_itemJSON, "type");
    if (type) { 
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }
    }


    v1_limit_range_item_local_var = v1_limit_range_item_create (
        default ? List : NULL,
        defaultRequest ? List : NULL,
        max ? List : NULL,
        maxLimitRequestRatio ? List : NULL,
        min ? List : NULL,
        type ? strdup(type->valuestring) : NULL
        );

    return v1_limit_range_item_local_var;
end:
    return NULL;

}
