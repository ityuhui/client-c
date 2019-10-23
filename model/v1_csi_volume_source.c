#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_csi_volume_source.h"



v1_csi_volume_source_t *v1_csi_volume_source_create(
    char *driver,
    char *fsType,
    v1_local_object_reference_t *nodePublishSecretRef,
    int readOnly,
    list_t* volumeAttributes
    ) {
	v1_csi_volume_source_t *v1_csi_volume_source_local_var = malloc(sizeof(v1_csi_volume_source_t));
    if (!v1_csi_volume_source_local_var) {
        return NULL;
    }
	v1_csi_volume_source_local_var->driver = driver;
	v1_csi_volume_source_local_var->fsType = fsType;
	v1_csi_volume_source_local_var->nodePublishSecretRef = nodePublishSecretRef;
	v1_csi_volume_source_local_var->readOnly = readOnly;
	v1_csi_volume_source_local_var->volumeAttributes = volumeAttributes;

	return v1_csi_volume_source_local_var;
}


void v1_csi_volume_source_free(v1_csi_volume_source_t *v1_csi_volume_source) {
    listEntry_t *listEntry;
    free(v1_csi_volume_source->driver);
    free(v1_csi_volume_source->fsType);
    v1_local_object_reference_free(v1_csi_volume_source->nodePublishSecretRef);
	list_ForEach(listEntry, v1_csi_volume_source->volumeAttributes) {
		keyValuePair_t *localMapKeyPair = (keyValuePair_t*) listEntry->data;
        free (localMapKeyPair->key);
        free (localMapKeyPair->value);
	}
	list_free(v1_csi_volume_source->volumeAttributes);
	free(v1_csi_volume_source);
}

cJSON *v1_csi_volume_source_convertToJSON(v1_csi_volume_source_t *v1_csi_volume_source) {
	cJSON *item = cJSON_CreateObject();

	// v1_csi_volume_source->driver
    if (!v1_csi_volume_source->driver) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "driver", v1_csi_volume_source->driver) == NULL) {
    goto fail; //String
    }


	// v1_csi_volume_source->fsType
    if(v1_csi_volume_source->fsType) { 
    if(cJSON_AddStringToObject(item, "fsType", v1_csi_volume_source->fsType) == NULL) {
    goto fail; //String
    }
     } 


	// v1_csi_volume_source->nodePublishSecretRef
    if(v1_csi_volume_source->nodePublishSecretRef) { 
    cJSON *nodePublishSecretRef_local_JSON = v1_local_object_reference_convertToJSON(v1_csi_volume_source->nodePublishSecretRef);
    if(nodePublishSecretRef_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "nodePublishSecretRef", nodePublishSecretRef_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_csi_volume_source->readOnly
    if(v1_csi_volume_source->readOnly) { 
    if(cJSON_AddBoolToObject(item, "readOnly", v1_csi_volume_source->readOnly) == NULL) {
    goto fail; //Bool
    }
     } 


	// v1_csi_volume_source->volumeAttributes
    if(v1_csi_volume_source->volumeAttributes) { 
	cJSON *volumeAttributes = cJSON_AddObjectToObject(item, "volumeAttributes");
	if(volumeAttributes == NULL) {
		goto fail; //primitive map container
	}
    cJSON *localMapObject = cJSON_CreateObject(); //Memory free to be implemented in user code
	listEntry_t *volumeAttributesListEntry;
    if (v1_csi_volume_source->volumeAttributes) {
    list_ForEach(volumeAttributesListEntry, v1_csi_volume_source->volumeAttributes) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)volumeAttributesListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
        cJSON_AddItemToObject(volumeAttributes,"", localMapObject);
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

v1_csi_volume_source_t *v1_csi_volume_source_parseFromJSON(cJSON *v1_csi_volume_sourceJSON){

    v1_csi_volume_source_t *v1_csi_volume_source_local_var = NULL;

    // v1_csi_volume_source->driver
    cJSON *driver = cJSON_GetObjectItemCaseSensitive(v1_csi_volume_sourceJSON, "driver");
    if (!driver) {
        goto end;
    }

    
    if(!cJSON_IsString(driver))
    {
    goto end; //String
    }

    // v1_csi_volume_source->fsType
    cJSON *fsType = cJSON_GetObjectItemCaseSensitive(v1_csi_volume_sourceJSON, "fsType");
    if (fsType) { 
    if(!cJSON_IsString(fsType))
    {
    goto end; //String
    }
    }

    // v1_csi_volume_source->nodePublishSecretRef
    cJSON *nodePublishSecretRef = cJSON_GetObjectItemCaseSensitive(v1_csi_volume_sourceJSON, "nodePublishSecretRef");
    v1_local_object_reference_t *nodePublishSecretRef_local_nonprim = NULL;
    if (nodePublishSecretRef) { 
    nodePublishSecretRef_local_nonprim = v1_local_object_reference_parseFromJSON(nodePublishSecretRef); //nonprimitive
    }

    // v1_csi_volume_source->readOnly
    cJSON *readOnly = cJSON_GetObjectItemCaseSensitive(v1_csi_volume_sourceJSON, "readOnly");
    if (readOnly) { 
    if(!cJSON_IsBool(readOnly))
    {
    goto end; //Bool
    }
    }

    // v1_csi_volume_source->volumeAttributes
    cJSON *volumeAttributes = cJSON_GetObjectItemCaseSensitive(v1_csi_volume_sourceJSON, "volumeAttributes");
    list_t *List;
    if (volumeAttributes) { 
    cJSON *_local_map;
    if(!cJSON_IsObject(volumeAttributes)) {
        goto end;//primitive map container
    }
    List = list_create();
    keyValuePair_t *localMapKeyPair;
    cJSON_ArrayForEach(_local_map, volumeAttributes)
    {
        if(!cJSON_IsNumber(_local_map))
        {
            goto end;
        }
        localMapKeyPair = keyValuePair_create(strdup(_local_map->string),&_local_map->valuedouble );
        list_addElement(List , localMapKeyPair);
    }
    }


    v1_csi_volume_source_local_var = v1_csi_volume_source_create (
        strdup(driver->valuestring),
        fsType ? strdup(fsType->valuestring) : NULL,
        nodePublishSecretRef ? nodePublishSecretRef_local_nonprim : NULL,
        readOnly ? readOnly->valueint : 0,
        volumeAttributes ? List : NULL
        );

    return v1_csi_volume_source_local_var;
end:
    return NULL;

}
