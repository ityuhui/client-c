#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_config_map.h"



v1_config_map_t *v1_config_map_create(
    char *apiVersion,
    list_t* binaryData,
    list_t* data,
    char *kind,
    v1_object_meta_t *metadata
    ) {
	v1_config_map_t *v1_config_map_local_var = malloc(sizeof(v1_config_map_t));
    if (!v1_config_map_local_var) {
        return NULL;
    }
	v1_config_map_local_var->apiVersion = apiVersion;
	v1_config_map_local_var->binaryData = binaryData;
	v1_config_map_local_var->data = data;
	v1_config_map_local_var->kind = kind;
	v1_config_map_local_var->metadata = metadata;

	return v1_config_map_local_var;
}


void v1_config_map_free(v1_config_map_t *v1_config_map) {
    listEntry_t *listEntry;
    free(v1_config_map->apiVersion);
	list_ForEach(listEntry, v1_config_map->binaryData) {
		keyValuePair_t *localMapKeyPair = (keyValuePair_t*) listEntry->data;
        free (localMapKeyPair->key);
        free (localMapKeyPair->value);
	}
	list_free(v1_config_map->binaryData);
	list_ForEach(listEntry, v1_config_map->data) {
		keyValuePair_t *localMapKeyPair = (keyValuePair_t*) listEntry->data;
        free (localMapKeyPair->key);
        free (localMapKeyPair->value);
	}
	list_free(v1_config_map->data);
    free(v1_config_map->kind);
    v1_object_meta_free(v1_config_map->metadata);
	free(v1_config_map);
}

cJSON *v1_config_map_convertToJSON(v1_config_map_t *v1_config_map) {
	cJSON *item = cJSON_CreateObject();

	// v1_config_map->apiVersion
    if(v1_config_map->apiVersion) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1_config_map->apiVersion) == NULL) {
    goto fail; //String
    }
     } 


	// v1_config_map->binaryData
    if(v1_config_map->binaryData) { 
	cJSON *binaryData = cJSON_AddObjectToObject(item, "binaryData");
	if(binaryData == NULL) {
		goto fail; //primitive map container
	}
    cJSON *localMapObject = cJSON_CreateObject(); //Memory free to be implemented in user code
	listEntry_t *binaryDataListEntry;
    if (v1_config_map->binaryData) {
    list_ForEach(binaryDataListEntry, v1_config_map->binaryData) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)binaryDataListEntry->data;
        if(cJSON_AddNumberToObject(localMapObject, localKeyValue->key, *(double *)localKeyValue->value) == NULL)
        {
            goto fail;
        }
        cJSON_AddItemToObject(binaryData,"", localMapObject);
    }
    }
     } 


	// v1_config_map->data
    if(v1_config_map->data) { 
	cJSON *data = cJSON_AddObjectToObject(item, "data");
	if(data == NULL) {
		goto fail; //primitive map container
	}
    cJSON *localMapObject = cJSON_CreateObject(); //Memory free to be implemented in user code
	listEntry_t *dataListEntry;
    if (v1_config_map->data) {
    list_ForEach(dataListEntry, v1_config_map->data) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)dataListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
        cJSON_AddItemToObject(data,"", localMapObject);
    }
    }
     } 


	// v1_config_map->kind
    if(v1_config_map->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1_config_map->kind) == NULL) {
    goto fail; //String
    }
     } 


	// v1_config_map->metadata
    if(v1_config_map->metadata) { 
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_config_map->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
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

v1_config_map_t *v1_config_map_parseFromJSON(cJSON *v1_config_mapJSON){

    v1_config_map_t *v1_config_map_local_var = NULL;

    // v1_config_map->apiVersion
    cJSON *apiVersion = cJSON_GetObjectItemCaseSensitive(v1_config_mapJSON, "apiVersion");
    if (apiVersion) { 
    if(!cJSON_IsString(apiVersion))
    {
    goto end; //String
    }
    }

    // v1_config_map->binaryData
    cJSON *binaryData = cJSON_GetObjectItemCaseSensitive(v1_config_mapJSON, "binaryData");
    list_t *ListBinaryData;
    if (binaryData) { 
    cJSON *_local_map;
    if(!cJSON_IsObject(binaryData)) {
        goto end;//primitive map container
    }
    ListBinaryData = list_create();
    keyValuePair_t *localMapKeyPair;
    cJSON_ArrayForEach(_local_map, binaryData)
    {
        if(!cJSON_IsNumber(_local_map))
        {
            goto end;
        }
        localMapKeyPair = keyValuePair_create(strdup(_local_map->string),&_local_map->valuedouble );
        list_addElement(ListBinaryData, localMapKeyPair);
    }
    }

    // v1_config_map->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(v1_config_mapJSON, "data");
    list_t *List;
    if (data) { 
    cJSON *_local_map;
    if(!cJSON_IsObject(data)) {
        goto end;//primitive map container
    }
    List = list_create();
    keyValuePair_t *localMapKeyPair;
    cJSON_ArrayForEach(_local_map, data)
    {
        if(!cJSON_IsNumber(_local_map))
        {
            goto end;
        }
        localMapKeyPair = keyValuePair_create(strdup(_local_map->string),&_local_map->valuedouble );
        list_addElement(List , localMapKeyPair);
    }
    }

    // v1_config_map->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_config_mapJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1_config_map->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1_config_mapJSON, "metadata");
    v1_object_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }


    v1_config_map_local_var = v1_config_map_create (
        apiVersion ? strdup(apiVersion->valuestring) : NULL,
        binaryData ? ListBinaryData : NULL,
        data ? List : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL
        );

    return v1_config_map_local_var;
end:
    return NULL;

}
