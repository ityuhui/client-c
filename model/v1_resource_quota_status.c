#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_resource_quota_status.h"



v1_resource_quota_status_t *v1_resource_quota_status_create(
    list_t* hard,
    list_t* used
    ) {
	v1_resource_quota_status_t *v1_resource_quota_status_local_var = malloc(sizeof(v1_resource_quota_status_t));
    if (!v1_resource_quota_status_local_var) {
        return NULL;
    }
	v1_resource_quota_status_local_var->hard = hard;
	v1_resource_quota_status_local_var->used = used;

	return v1_resource_quota_status_local_var;
}


void v1_resource_quota_status_free(v1_resource_quota_status_t *v1_resource_quota_status) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, v1_resource_quota_status->hard) {
		keyValuePair_t *localMapKeyPair = (keyValuePair_t*) listEntry->data;
        free (localMapKeyPair->key);
        free (localMapKeyPair->value);
	}
	list_free(v1_resource_quota_status->hard);
	list_ForEach(listEntry, v1_resource_quota_status->used) {
		keyValuePair_t *localMapKeyPair = (keyValuePair_t*) listEntry->data;
        free (localMapKeyPair->key);
        free (localMapKeyPair->value);
	}
	list_free(v1_resource_quota_status->used);
	free(v1_resource_quota_status);
}

cJSON *v1_resource_quota_status_convertToJSON(v1_resource_quota_status_t *v1_resource_quota_status) {
	cJSON *item = cJSON_CreateObject();

	// v1_resource_quota_status->hard
    if(v1_resource_quota_status->hard) { 
	cJSON *hard = cJSON_AddObjectToObject(item, "hard");
	if(hard == NULL) {
		goto fail; //primitive map container
	}
    cJSON *localMapObject = cJSON_CreateObject(); //Memory free to be implemented in user code
	listEntry_t *hardListEntry;
    if (v1_resource_quota_status->hard) {
    list_ForEach(hardListEntry, v1_resource_quota_status->hard) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)hardListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
        cJSON_AddItemToObject(hard,"", localMapObject);
    }
    }
     } 


	// v1_resource_quota_status->used
    if(v1_resource_quota_status->used) { 
	cJSON *used = cJSON_AddObjectToObject(item, "used");
	if(used == NULL) {
		goto fail; //primitive map container
	}
    cJSON *localMapObject = cJSON_CreateObject(); //Memory free to be implemented in user code
	listEntry_t *usedListEntry;
    if (v1_resource_quota_status->used) {
    list_ForEach(usedListEntry, v1_resource_quota_status->used) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)usedListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
        cJSON_AddItemToObject(used,"", localMapObject);
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

v1_resource_quota_status_t *v1_resource_quota_status_parseFromJSON(cJSON *v1_resource_quota_statusJSON){

    v1_resource_quota_status_t *v1_resource_quota_status_local_var = NULL;

    // v1_resource_quota_status->hard
    cJSON *hard = cJSON_GetObjectItemCaseSensitive(v1_resource_quota_statusJSON, "hard");
    list_t *List;
    if (hard) { 
    cJSON *_local_map;
    if(!cJSON_IsObject(hard)) {
        goto end;//primitive map container
    }
    List = list_create();
    keyValuePair_t *localMapKeyPair;
    cJSON_ArrayForEach(_local_map, hard)
    {
        if(!cJSON_IsNumber(_local_map))
        {
            goto end;
        }
        localMapKeyPair = keyValuePair_create(strdup(_local_map->string),&_local_map->valuedouble );
        list_addElement(List , localMapKeyPair);
    }
    }

    // v1_resource_quota_status->used
    cJSON *used = cJSON_GetObjectItemCaseSensitive(v1_resource_quota_statusJSON, "used");
    list_t *Listused;
    if (used) { 
    cJSON *_local_map;
    if(!cJSON_IsObject(used)) {
        goto end;//primitive map container
    }
    Listused = list_create();
    keyValuePair_t *localMapKeyPair;
    cJSON_ArrayForEach(_local_map, used)
    {
        if(!cJSON_IsNumber(_local_map))
        {
            goto end;
        }
        localMapKeyPair = keyValuePair_create(strdup(_local_map->string),&_local_map->valuedouble );
        list_addElement(Listused, localMapKeyPair);
    }
    }


    v1_resource_quota_status_local_var = v1_resource_quota_status_create (
        hard ? List : NULL,
        used ? Listused : NULL
        );

    return v1_resource_quota_status_local_var;
end:
    return NULL;

}
