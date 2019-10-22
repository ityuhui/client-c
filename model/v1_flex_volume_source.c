#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_flex_volume_source.h"



v1_flex_volume_source_t *v1_flex_volume_source_create(
    char *driver,
    char *fsType,
    list_t* options,
    int readOnly,
    v1_local_object_reference_t *secretRef
    ) {
	v1_flex_volume_source_t *v1_flex_volume_source_local_var = malloc(sizeof(v1_flex_volume_source_t));
    if (!v1_flex_volume_source_local_var) {
        return NULL;
    }
	v1_flex_volume_source_local_var->driver = driver;
	v1_flex_volume_source_local_var->fsType = fsType;
	v1_flex_volume_source_local_var->options = options;
	v1_flex_volume_source_local_var->readOnly = readOnly;
	v1_flex_volume_source_local_var->secretRef = secretRef;

	return v1_flex_volume_source_local_var;
}


void v1_flex_volume_source_free(v1_flex_volume_source_t *v1_flex_volume_source) {
    listEntry_t *listEntry;
    free(v1_flex_volume_source->driver);
    free(v1_flex_volume_source->fsType);
	list_ForEach(listEntry, v1_flex_volume_source->options) {
		keyValuePair_t *localMapKeyPair = (keyValuePair_t*) listEntry->data;
        free (localKeyValue->key);
        free (localKeyValue->value);
	}
	list_free(v1_flex_volume_source->options);
    v1_local_object_reference_free(v1_flex_volume_source->secretRef);
	free(v1_flex_volume_source);
}

cJSON *v1_flex_volume_source_convertToJSON(v1_flex_volume_source_t *v1_flex_volume_source) {
	cJSON *item = cJSON_CreateObject();

	// v1_flex_volume_source->driver
    if (!v1_flex_volume_source->driver) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "driver", v1_flex_volume_source->driver) == NULL) {
    goto fail; //String
    }


	// v1_flex_volume_source->fsType
    if(v1_flex_volume_source->fsType) { 
    if(cJSON_AddStringToObject(item, "fsType", v1_flex_volume_source->fsType) == NULL) {
    goto fail; //String
    }
     } 


	// v1_flex_volume_source->options
    if(v1_flex_volume_source->options) { 
	cJSON *options = cJSON_AddObjectToObject(item, "options");
	if(options == NULL) {
		goto fail; //primitive map container
	}
    cJSON *localMapObject = cJSON_CreateObject(); //Memory free to be implemented in user code
	listEntry_t *optionsListEntry;
    if (v1_flex_volume_source->options) {
    list_ForEach(optionsListEntry, v1_flex_volume_source->options) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)optionsListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
        cJSON_AddItemToObject(options,"", localMapObject);
    }
    }
     } 


	// v1_flex_volume_source->readOnly
    if(v1_flex_volume_source->readOnly) { 
    if(cJSON_AddBoolToObject(item, "readOnly", v1_flex_volume_source->readOnly) == NULL) {
    goto fail; //Bool
    }
     } 


	// v1_flex_volume_source->secretRef
    if(v1_flex_volume_source->secretRef) { 
    cJSON *secretRef_local_JSON = v1_local_object_reference_convertToJSON(v1_flex_volume_source->secretRef);
    if(secretRef_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "secretRef", secretRef_local_JSON);
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

v1_flex_volume_source_t *v1_flex_volume_source_parseFromJSON(cJSON *v1_flex_volume_sourceJSON){

    v1_flex_volume_source_t *v1_flex_volume_source_local_var = NULL;

    // v1_flex_volume_source->driver
    cJSON *driver = cJSON_GetObjectItemCaseSensitive(v1_flex_volume_sourceJSON, "driver");
    if (!driver) {
        goto end;
    }

    
    if(!cJSON_IsString(driver))
    {
    goto end; //String
    }

    // v1_flex_volume_source->fsType
    cJSON *fsType = cJSON_GetObjectItemCaseSensitive(v1_flex_volume_sourceJSON, "fsType");
    if (fsType) { 
    if(!cJSON_IsString(fsType))
    {
    goto end; //String
    }
    }

    // v1_flex_volume_source->options
    cJSON *options = cJSON_GetObjectItemCaseSensitive(v1_flex_volume_sourceJSON, "options");
    list_t *List;
    if (options) { 
    cJSON *_local_map;
    if(!cJSON_IsObject(options)) {
        goto end;//primitive map container
    }
    List = list_create();
    keyValuePair_t *localMapKeyPair;
    cJSON_ArrayForEach(_local_map, options)
    {
        if(!cJSON_IsNumber(_local_map))
        {
            goto end;
        }
        localMapKeyPair = keyValuePair_create(strdup(_local_map->string),&_local_map->valuedouble );
        list_addElement(List , localMapKeyPair);
    }
    }

    // v1_flex_volume_source->readOnly
    cJSON *readOnly = cJSON_GetObjectItemCaseSensitive(v1_flex_volume_sourceJSON, "readOnly");
    if (readOnly) { 
    if(!cJSON_IsBool(readOnly))
    {
    goto end; //Bool
    }
    }

    // v1_flex_volume_source->secretRef
    cJSON *secretRef = cJSON_GetObjectItemCaseSensitive(v1_flex_volume_sourceJSON, "secretRef");
    v1_local_object_reference_t *secretRef_local_nonprim = NULL;
    if (secretRef) { 
    secretRef_local_nonprim = v1_local_object_reference_parseFromJSON(secretRef); //nonprimitive
    }


    v1_flex_volume_source_local_var = v1_flex_volume_source_create (
        strdup(driver->valuestring),
        fsType ? strdup(fsType->valuestring) : NULL,
        options ? List : NULL,
        readOnly ? readOnly->valueint : 0,
        secretRef ? secretRef_local_nonprim : NULL
        );

    return v1_flex_volume_source_local_var;
end:
    return NULL;

}
