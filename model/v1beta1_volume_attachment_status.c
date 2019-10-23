#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_volume_attachment_status.h"



v1beta1_volume_attachment_status_t *v1beta1_volume_attachment_status_create(
    v1beta1_volume_error_t *attachError,
    int attached,
    list_t* attachmentMetadata,
    v1beta1_volume_error_t *detachError
    ) {
	v1beta1_volume_attachment_status_t *v1beta1_volume_attachment_status_local_var = malloc(sizeof(v1beta1_volume_attachment_status_t));
    if (!v1beta1_volume_attachment_status_local_var) {
        return NULL;
    }
	v1beta1_volume_attachment_status_local_var->attachError = attachError;
	v1beta1_volume_attachment_status_local_var->attached = attached;
	v1beta1_volume_attachment_status_local_var->attachmentMetadata = attachmentMetadata;
	v1beta1_volume_attachment_status_local_var->detachError = detachError;

	return v1beta1_volume_attachment_status_local_var;
}


void v1beta1_volume_attachment_status_free(v1beta1_volume_attachment_status_t *v1beta1_volume_attachment_status) {
    listEntry_t *listEntry;
    v1beta1_volume_error_free(v1beta1_volume_attachment_status->attachError);
	list_ForEach(listEntry, v1beta1_volume_attachment_status->attachmentMetadata) {
		keyValuePair_t *localMapKeyPair = (keyValuePair_t*) listEntry->data;
        free (localMapKeyPair->key);
        free (localMapKeyPair->value);
	}
	list_free(v1beta1_volume_attachment_status->attachmentMetadata);
    v1beta1_volume_error_free(v1beta1_volume_attachment_status->detachError);
	free(v1beta1_volume_attachment_status);
}

cJSON *v1beta1_volume_attachment_status_convertToJSON(v1beta1_volume_attachment_status_t *v1beta1_volume_attachment_status) {
	cJSON *item = cJSON_CreateObject();

	// v1beta1_volume_attachment_status->attachError
    if(v1beta1_volume_attachment_status->attachError) { 
    cJSON *attachError_local_JSON = v1beta1_volume_error_convertToJSON(v1beta1_volume_attachment_status->attachError);
    if(attachError_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "attachError", attachError_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1beta1_volume_attachment_status->attached
    if (!v1beta1_volume_attachment_status->attached) {
        goto fail;
    }
    
    if(cJSON_AddBoolToObject(item, "attached", v1beta1_volume_attachment_status->attached) == NULL) {
    goto fail; //Bool
    }


	// v1beta1_volume_attachment_status->attachmentMetadata
    if(v1beta1_volume_attachment_status->attachmentMetadata) { 
	cJSON *attachmentMetadata = cJSON_AddObjectToObject(item, "attachmentMetadata");
	if(attachmentMetadata == NULL) {
		goto fail; //primitive map container
	}
    cJSON *localMapObject = cJSON_CreateObject(); //Memory free to be implemented in user code
	listEntry_t *attachmentMetadataListEntry;
    if (v1beta1_volume_attachment_status->attachmentMetadata) {
    list_ForEach(attachmentMetadataListEntry, v1beta1_volume_attachment_status->attachmentMetadata) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)attachmentMetadataListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
        cJSON_AddItemToObject(attachmentMetadata,"", localMapObject);
    }
    }
     } 


	// v1beta1_volume_attachment_status->detachError
    if(v1beta1_volume_attachment_status->detachError) { 
    cJSON *detachError_local_JSON = v1beta1_volume_error_convertToJSON(v1beta1_volume_attachment_status->detachError);
    if(detachError_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "detachError", detachError_local_JSON);
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

v1beta1_volume_attachment_status_t *v1beta1_volume_attachment_status_parseFromJSON(cJSON *v1beta1_volume_attachment_statusJSON){

    v1beta1_volume_attachment_status_t *v1beta1_volume_attachment_status_local_var = NULL;

    // v1beta1_volume_attachment_status->attachError
    cJSON *attachError = cJSON_GetObjectItemCaseSensitive(v1beta1_volume_attachment_statusJSON, "attachError");
    v1beta1_volume_error_t *attachError_local_nonprim = NULL;
    if (attachError) { 
    attachError_local_nonprim = v1beta1_volume_error_parseFromJSON(attachError); //nonprimitive
    }

    // v1beta1_volume_attachment_status->attached
    cJSON *attached = cJSON_GetObjectItemCaseSensitive(v1beta1_volume_attachment_statusJSON, "attached");
    if (!attached) {
        goto end;
    }

    
    if(!cJSON_IsBool(attached))
    {
    goto end; //Bool
    }

    // v1beta1_volume_attachment_status->attachmentMetadata
    cJSON *attachmentMetadata = cJSON_GetObjectItemCaseSensitive(v1beta1_volume_attachment_statusJSON, "attachmentMetadata");
    list_t *List;
    if (attachmentMetadata) { 
    cJSON *_local_map;
    if(!cJSON_IsObject(attachmentMetadata)) {
        goto end;//primitive map container
    }
    List = list_create();
    keyValuePair_t *localMapKeyPair;
    cJSON_ArrayForEach(_local_map, attachmentMetadata)
    {
        if(!cJSON_IsNumber(_local_map))
        {
            goto end;
        }
        localMapKeyPair = keyValuePair_create(strdup(_local_map->string),&_local_map->valuedouble );
        list_addElement(List , localMapKeyPair);
    }
    }

    // v1beta1_volume_attachment_status->detachError
    cJSON *detachError = cJSON_GetObjectItemCaseSensitive(v1beta1_volume_attachment_statusJSON, "detachError");
    v1beta1_volume_error_t *detachError_local_nonprim = NULL;
    if (detachError) { 
    detachError_local_nonprim = v1beta1_volume_error_parseFromJSON(detachError); //nonprimitive
    }


    v1beta1_volume_attachment_status_local_var = v1beta1_volume_attachment_status_create (
        attachError ? attachError_local_nonprim : NULL,
        attached->valueint,
        attachmentMetadata ? List : NULL,
        detachError ? detachError_local_nonprim : NULL
        );

    return v1beta1_volume_attachment_status_local_var;
end:
    return NULL;

}
