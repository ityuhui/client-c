#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_resource_requirements.h"



v1_resource_requirements_t *v1_resource_requirements_create(
    list_t* limits,
    list_t* requests
    ) {
	v1_resource_requirements_t *v1_resource_requirements_local_var = malloc(sizeof(v1_resource_requirements_t));
    if (!v1_resource_requirements_local_var) {
        return NULL;
    }
	v1_resource_requirements_local_var->limits = limits;
	v1_resource_requirements_local_var->requests = requests;

	return v1_resource_requirements_local_var;
}


void v1_resource_requirements_free(v1_resource_requirements_t *v1_resource_requirements) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, v1_resource_requirements->limits) {
		keyValuePair_t *localMapKeyPair = (keyValuePair_t*) listEntry->data;
        free (localKeyValue->key);
        free (localKeyValue->value);
	}
	list_free(v1_resource_requirements->limits);
	list_ForEach(listEntry, v1_resource_requirements->requests) {
		keyValuePair_t *localMapKeyPair = (keyValuePair_t*) listEntry->data;
        free (localKeyValue->key);
        free (localKeyValue->value);
	}
	list_free(v1_resource_requirements->requests);
	free(v1_resource_requirements);
}

cJSON *v1_resource_requirements_convertToJSON(v1_resource_requirements_t *v1_resource_requirements) {
	cJSON *item = cJSON_CreateObject();

	// v1_resource_requirements->limits
    if(v1_resource_requirements->limits) { 
	cJSON *limits = cJSON_AddObjectToObject(item, "limits");
	if(limits == NULL) {
		goto fail; //primitive map container
	}
    cJSON *localMapObject = cJSON_CreateObject(); //Memory free to be implemented in user code
	listEntry_t *limitsListEntry;
    if (v1_resource_requirements->limits) {
    list_ForEach(limitsListEntry, v1_resource_requirements->limits) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)limitsListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
        cJSON_AddItemToObject(limits,"", localMapObject);
    }
    }
     } 


	// v1_resource_requirements->requests
    if(v1_resource_requirements->requests) { 
	cJSON *requests = cJSON_AddObjectToObject(item, "requests");
	if(requests == NULL) {
		goto fail; //primitive map container
	}
    cJSON *localMapObject = cJSON_CreateObject(); //Memory free to be implemented in user code
	listEntry_t *requestsListEntry;
    if (v1_resource_requirements->requests) {
    list_ForEach(requestsListEntry, v1_resource_requirements->requests) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)requestsListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
        cJSON_AddItemToObject(requests,"", localMapObject);
    }
    }
     } 

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1_resource_requirements_t *v1_resource_requirements_parseFromJSON(cJSON *v1_resource_requirementsJSON){

    v1_resource_requirements_t *v1_resource_requirements_local_var = NULL;

    // v1_resource_requirements->limits
    cJSON *limits = cJSON_GetObjectItemCaseSensitive(v1_resource_requirementsJSON, "limits");
    list_t *List;
    if (limits) { 
    cJSON *_local_map;
    if(!cJSON_IsObject(limits)) {
        goto end;//primitive map container
    }
    List = list_create();
    keyValuePair_t *localMapKeyPair;
    cJSON_ArrayForEach(_local_map, limits)
    {
        if(!cJSON_IsNumber(_local_map))
        {
            goto end;
        }
        localMapKeyPair = keyValuePair_create(strdup(_local_map->string),&_local_map->valuedouble );
        list_addElement(List , localMapKeyPair);
    }
    }

    // v1_resource_requirements->requests
    cJSON *requests = cJSON_GetObjectItemCaseSensitive(v1_resource_requirementsJSON, "requests");
    list_t *List;
    if (requests) { 
    cJSON *_local_map;
    if(!cJSON_IsObject(requests)) {
        goto end;//primitive map container
    }
    List = list_create();
    keyValuePair_t *localMapKeyPair;
    cJSON_ArrayForEach(_local_map, requests)
    {
        if(!cJSON_IsNumber(_local_map))
        {
            goto end;
        }
        localMapKeyPair = keyValuePair_create(strdup(_local_map->string),&_local_map->valuedouble );
        list_addElement(List , localMapKeyPair);
    }
    }


    v1_resource_requirements_local_var = v1_resource_requirements_create (
        limits ? List : NULL,
        requests ? List : NULL
        );

    return v1_resource_requirements_local_var;
end:
    return NULL;

}
