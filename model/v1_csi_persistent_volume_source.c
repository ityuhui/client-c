#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_csi_persistent_volume_source.h"



v1_csi_persistent_volume_source_t *v1_csi_persistent_volume_source_create(
    v1_secret_reference_t *controllerExpandSecretRef,
    v1_secret_reference_t *controllerPublishSecretRef,
    char *driver,
    char *fsType,
    v1_secret_reference_t *nodePublishSecretRef,
    v1_secret_reference_t *nodeStageSecretRef,
    int readOnly,
    list_t* volumeAttributes,
    char *volumeHandle
    ) {
	v1_csi_persistent_volume_source_t *v1_csi_persistent_volume_source_local_var = malloc(sizeof(v1_csi_persistent_volume_source_t));
    if (!v1_csi_persistent_volume_source_local_var) {
        return NULL;
    }
	v1_csi_persistent_volume_source_local_var->controllerExpandSecretRef = controllerExpandSecretRef;
	v1_csi_persistent_volume_source_local_var->controllerPublishSecretRef = controllerPublishSecretRef;
	v1_csi_persistent_volume_source_local_var->driver = driver;
	v1_csi_persistent_volume_source_local_var->fsType = fsType;
	v1_csi_persistent_volume_source_local_var->nodePublishSecretRef = nodePublishSecretRef;
	v1_csi_persistent_volume_source_local_var->nodeStageSecretRef = nodeStageSecretRef;
	v1_csi_persistent_volume_source_local_var->readOnly = readOnly;
	v1_csi_persistent_volume_source_local_var->volumeAttributes = volumeAttributes;
	v1_csi_persistent_volume_source_local_var->volumeHandle = volumeHandle;

	return v1_csi_persistent_volume_source_local_var;
}


void v1_csi_persistent_volume_source_free(v1_csi_persistent_volume_source_t *v1_csi_persistent_volume_source) {
    listEntry_t *listEntry;
    v1_secret_reference_free(v1_csi_persistent_volume_source->controllerExpandSecretRef);
    v1_secret_reference_free(v1_csi_persistent_volume_source->controllerPublishSecretRef);
    free(v1_csi_persistent_volume_source->driver);
    free(v1_csi_persistent_volume_source->fsType);
    v1_secret_reference_free(v1_csi_persistent_volume_source->nodePublishSecretRef);
    v1_secret_reference_free(v1_csi_persistent_volume_source->nodeStageSecretRef);
	list_ForEach(listEntry, v1_csi_persistent_volume_source->volumeAttributes) {
		keyValuePair_t *localMapKeyPair = (keyValuePair_t*) listEntry->data;
        //yhwa free (localKeyValue->key);
        //yhwa free (localKeyValue->value);
	}
	list_free(v1_csi_persistent_volume_source->volumeAttributes);
    free(v1_csi_persistent_volume_source->volumeHandle);
	free(v1_csi_persistent_volume_source);
}

cJSON *v1_csi_persistent_volume_source_convertToJSON(v1_csi_persistent_volume_source_t *v1_csi_persistent_volume_source) {
	cJSON *item = cJSON_CreateObject();

	// v1_csi_persistent_volume_source->controllerExpandSecretRef
    if(v1_csi_persistent_volume_source->controllerExpandSecretRef) { 
    cJSON *controllerExpandSecretRef_local_JSON = v1_secret_reference_convertToJSON(v1_csi_persistent_volume_source->controllerExpandSecretRef);
    if(controllerExpandSecretRef_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "controllerExpandSecretRef", controllerExpandSecretRef_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_csi_persistent_volume_source->controllerPublishSecretRef
    if(v1_csi_persistent_volume_source->controllerPublishSecretRef) { 
    cJSON *controllerPublishSecretRef_local_JSON = v1_secret_reference_convertToJSON(v1_csi_persistent_volume_source->controllerPublishSecretRef);
    if(controllerPublishSecretRef_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "controllerPublishSecretRef", controllerPublishSecretRef_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_csi_persistent_volume_source->driver
    if (!v1_csi_persistent_volume_source->driver) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "driver", v1_csi_persistent_volume_source->driver) == NULL) {
    goto fail; //String
    }


	// v1_csi_persistent_volume_source->fsType
    if(v1_csi_persistent_volume_source->fsType) { 
    if(cJSON_AddStringToObject(item, "fsType", v1_csi_persistent_volume_source->fsType) == NULL) {
    goto fail; //String
    }
     } 


	// v1_csi_persistent_volume_source->nodePublishSecretRef
    if(v1_csi_persistent_volume_source->nodePublishSecretRef) { 
    cJSON *nodePublishSecretRef_local_JSON = v1_secret_reference_convertToJSON(v1_csi_persistent_volume_source->nodePublishSecretRef);
    if(nodePublishSecretRef_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "nodePublishSecretRef", nodePublishSecretRef_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_csi_persistent_volume_source->nodeStageSecretRef
    if(v1_csi_persistent_volume_source->nodeStageSecretRef) { 
    cJSON *nodeStageSecretRef_local_JSON = v1_secret_reference_convertToJSON(v1_csi_persistent_volume_source->nodeStageSecretRef);
    if(nodeStageSecretRef_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "nodeStageSecretRef", nodeStageSecretRef_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_csi_persistent_volume_source->readOnly
    if(v1_csi_persistent_volume_source->readOnly) { 
    if(cJSON_AddBoolToObject(item, "readOnly", v1_csi_persistent_volume_source->readOnly) == NULL) {
    goto fail; //Bool
    }
     } 


	// v1_csi_persistent_volume_source->volumeAttributes
    if(v1_csi_persistent_volume_source->volumeAttributes) { 
	cJSON *volumeAttributes = cJSON_AddObjectToObject(item, "volumeAttributes");
	if(volumeAttributes == NULL) {
		goto fail; //primitive map container
	}
    cJSON *localMapObject = cJSON_CreateObject(); //Memory free to be implemented in user code
	listEntry_t *volumeAttributesListEntry;
    if (v1_csi_persistent_volume_source->volumeAttributes) {
    list_ForEach(volumeAttributesListEntry, v1_csi_persistent_volume_source->volumeAttributes) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)volumeAttributesListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
        cJSON_AddItemToObject(volumeAttributes,"", localMapObject);
    }
    }
     } 


	// v1_csi_persistent_volume_source->volumeHandle
    if (!v1_csi_persistent_volume_source->volumeHandle) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "volumeHandle", v1_csi_persistent_volume_source->volumeHandle) == NULL) {
    goto fail; //String
    }

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1_csi_persistent_volume_source_t *v1_csi_persistent_volume_source_parseFromJSON(cJSON *v1_csi_persistent_volume_sourceJSON){

    v1_csi_persistent_volume_source_t *v1_csi_persistent_volume_source_local_var = NULL;

    // v1_csi_persistent_volume_source->controllerExpandSecretRef
    cJSON *controllerExpandSecretRef = cJSON_GetObjectItemCaseSensitive(v1_csi_persistent_volume_sourceJSON, "controllerExpandSecretRef");
    v1_secret_reference_t *controllerExpandSecretRef_local_nonprim = NULL;
    if (controllerExpandSecretRef) { 
    controllerExpandSecretRef_local_nonprim = v1_secret_reference_parseFromJSON(controllerExpandSecretRef); //nonprimitive
    }

    // v1_csi_persistent_volume_source->controllerPublishSecretRef
    cJSON *controllerPublishSecretRef = cJSON_GetObjectItemCaseSensitive(v1_csi_persistent_volume_sourceJSON, "controllerPublishSecretRef");
    v1_secret_reference_t *controllerPublishSecretRef_local_nonprim = NULL;
    if (controllerPublishSecretRef) { 
    controllerPublishSecretRef_local_nonprim = v1_secret_reference_parseFromJSON(controllerPublishSecretRef); //nonprimitive
    }

    // v1_csi_persistent_volume_source->driver
    cJSON *driver = cJSON_GetObjectItemCaseSensitive(v1_csi_persistent_volume_sourceJSON, "driver");
    if (!driver) {
        goto end;
    }

    
    if(!cJSON_IsString(driver))
    {
    goto end; //String
    }

    // v1_csi_persistent_volume_source->fsType
    cJSON *fsType = cJSON_GetObjectItemCaseSensitive(v1_csi_persistent_volume_sourceJSON, "fsType");
    if (fsType) { 
    if(!cJSON_IsString(fsType))
    {
    goto end; //String
    }
    }

    // v1_csi_persistent_volume_source->nodePublishSecretRef
    cJSON *nodePublishSecretRef = cJSON_GetObjectItemCaseSensitive(v1_csi_persistent_volume_sourceJSON, "nodePublishSecretRef");
    v1_secret_reference_t *nodePublishSecretRef_local_nonprim = NULL;
    if (nodePublishSecretRef) { 
    nodePublishSecretRef_local_nonprim = v1_secret_reference_parseFromJSON(nodePublishSecretRef); //nonprimitive
    }

    // v1_csi_persistent_volume_source->nodeStageSecretRef
    cJSON *nodeStageSecretRef = cJSON_GetObjectItemCaseSensitive(v1_csi_persistent_volume_sourceJSON, "nodeStageSecretRef");
    v1_secret_reference_t *nodeStageSecretRef_local_nonprim = NULL;
    if (nodeStageSecretRef) { 
    nodeStageSecretRef_local_nonprim = v1_secret_reference_parseFromJSON(nodeStageSecretRef); //nonprimitive
    }

    // v1_csi_persistent_volume_source->readOnly
    cJSON *readOnly = cJSON_GetObjectItemCaseSensitive(v1_csi_persistent_volume_sourceJSON, "readOnly");
    if (readOnly) { 
    if(!cJSON_IsBool(readOnly))
    {
    goto end; //Bool
    }
    }

    // v1_csi_persistent_volume_source->volumeAttributes
    cJSON *volumeAttributes = cJSON_GetObjectItemCaseSensitive(v1_csi_persistent_volume_sourceJSON, "volumeAttributes");
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

    // v1_csi_persistent_volume_source->volumeHandle
    cJSON *volumeHandle = cJSON_GetObjectItemCaseSensitive(v1_csi_persistent_volume_sourceJSON, "volumeHandle");
    if (!volumeHandle) {
        goto end;
    }

    
    if(!cJSON_IsString(volumeHandle))
    {
    goto end; //String
    }


    v1_csi_persistent_volume_source_local_var = v1_csi_persistent_volume_source_create (
        controllerExpandSecretRef ? controllerExpandSecretRef_local_nonprim : NULL,
        controllerPublishSecretRef ? controllerPublishSecretRef_local_nonprim : NULL,
        strdup(driver->valuestring),
        fsType ? strdup(fsType->valuestring) : NULL,
        nodePublishSecretRef ? nodePublishSecretRef_local_nonprim : NULL,
        nodeStageSecretRef ? nodeStageSecretRef_local_nonprim : NULL,
        readOnly ? readOnly->valueint : 0,
        volumeAttributes ? List : NULL,
        strdup(volumeHandle->valuestring)
        );

    return v1_csi_persistent_volume_source_local_var;
end:
    return NULL;

}
