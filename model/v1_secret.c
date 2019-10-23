#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_secret.h"



v1_secret_t *v1_secret_create(
    char *apiVersion,
    list_t* data,
    char *kind,
    v1_object_meta_t *metadata,
    list_t* stringData,
    char *type
    ) {
	v1_secret_t *v1_secret_local_var = malloc(sizeof(v1_secret_t));
    if (!v1_secret_local_var) {
        return NULL;
    }
	v1_secret_local_var->apiVersion = apiVersion;
	v1_secret_local_var->data = data;
	v1_secret_local_var->kind = kind;
	v1_secret_local_var->metadata = metadata;
	v1_secret_local_var->stringData = stringData;
	v1_secret_local_var->type = type;

	return v1_secret_local_var;
}


void v1_secret_free(v1_secret_t *v1_secret) {
    listEntry_t *listEntry;
    free(v1_secret->apiVersion);
	list_ForEach(listEntry, v1_secret->data) {
		keyValuePair_t *localMapKeyPair = (keyValuePair_t*) listEntry->data;
        free (localMapKeyPair->key);
        free (localMapKeyPair->value);
	}
	list_free(v1_secret->data);
    free(v1_secret->kind);
    v1_object_meta_free(v1_secret->metadata);
	list_ForEach(listEntry, v1_secret->stringData) {
		keyValuePair_t *localMapKeyPair = (keyValuePair_t*) listEntry->data;
        free (localMapKeyPair->key);
        free (localMapKeyPair->value);
	}
	list_free(v1_secret->stringData);
    free(v1_secret->type);
	free(v1_secret);
}

cJSON *v1_secret_convertToJSON(v1_secret_t *v1_secret) {
	cJSON *item = cJSON_CreateObject();

	// v1_secret->apiVersion
    if(v1_secret->apiVersion) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1_secret->apiVersion) == NULL) {
    goto fail; //String
    }
     } 


	// v1_secret->data
    if(v1_secret->data) { 
	cJSON *data = cJSON_AddObjectToObject(item, "data");
	if(data == NULL) {
		goto fail; //primitive map container
	}
    cJSON *localMapObject = cJSON_CreateObject(); //Memory free to be implemented in user code
	listEntry_t *dataListEntry;
    if (v1_secret->data) {
    list_ForEach(dataListEntry, v1_secret->data) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)dataListEntry->data;
        if(cJSON_AddNumberToObject(localMapObject, localKeyValue->key, *(double *)localKeyValue->value) == NULL)
        {
            goto fail;
        }
        cJSON_AddItemToObject(data,"", localMapObject);
    }
    }
     } 


	// v1_secret->kind
    if(v1_secret->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1_secret->kind) == NULL) {
    goto fail; //String
    }
     } 


	// v1_secret->metadata
    if(v1_secret->metadata) { 
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_secret->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_secret->stringData
    if(v1_secret->stringData) { 
	cJSON *stringData = cJSON_AddObjectToObject(item, "stringData");
	if(stringData == NULL) {
		goto fail; //primitive map container
	}
    cJSON *localMapObject = cJSON_CreateObject(); //Memory free to be implemented in user code
	listEntry_t *stringDataListEntry;
    if (v1_secret->stringData) {
    list_ForEach(stringDataListEntry, v1_secret->stringData) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)stringDataListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
        cJSON_AddItemToObject(stringData,"", localMapObject);
    }
    }
     } 


	// v1_secret->type
    if(v1_secret->type) { 
    if(cJSON_AddStringToObject(item, "type", v1_secret->type) == NULL) {
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

v1_secret_t *v1_secret_parseFromJSON(cJSON *v1_secretJSON){

    v1_secret_t *v1_secret_local_var = NULL;

    // v1_secret->apiVersion
    cJSON *apiVersion = cJSON_GetObjectItemCaseSensitive(v1_secretJSON, "apiVersion");
    if (apiVersion) { 
    if(!cJSON_IsString(apiVersion))
    {
    goto end; //String
    }
    }

    // v1_secret->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(v1_secretJSON, "data");
    list_t *Listdata;
    if (data) { 
    cJSON *_local_map;
    if(!cJSON_IsObject(data)) {
        goto end;//primitive map container
    }
    Listdata = list_create();
    keyValuePair_t *localMapKeyPair;
    cJSON_ArrayForEach(_local_map, data)
    {
        if(!cJSON_IsNumber(_local_map))
        {
            goto end;
        }
        localMapKeyPair = keyValuePair_create(strdup(_local_map->string),&_local_map->valuedouble );
        list_addElement(Listdata, localMapKeyPair);
    }
    }

    // v1_secret->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_secretJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1_secret->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1_secretJSON, "metadata");
    v1_object_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1_secret->stringData
    cJSON *stringData = cJSON_GetObjectItemCaseSensitive(v1_secretJSON, "stringData");
    list_t *List;
    if (stringData) { 
    cJSON *_local_map;
    if(!cJSON_IsObject(stringData)) {
        goto end;//primitive map container
    }
    List = list_create();
    keyValuePair_t *localMapKeyPair;
    cJSON_ArrayForEach(_local_map, stringData)
    {
        if(!cJSON_IsNumber(_local_map))
        {
            goto end;
        }
        localMapKeyPair = keyValuePair_create(strdup(_local_map->string),&_local_map->valuedouble );
        list_addElement(List , localMapKeyPair);
    }
    }

    // v1_secret->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(v1_secretJSON, "type");
    if (type) { 
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }
    }


    v1_secret_local_var = v1_secret_create (
        apiVersion ? strdup(apiVersion->valuestring) : NULL,
        data ? Listdata : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        stringData ? List : NULL,
        type ? strdup(type->valuestring) : NULL
        );

    return v1_secret_local_var;
end:
    return NULL;

}
