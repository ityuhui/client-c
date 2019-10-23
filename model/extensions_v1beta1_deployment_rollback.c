#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "extensions_v1beta1_deployment_rollback.h"



extensions_v1beta1_deployment_rollback_t *extensions_v1beta1_deployment_rollback_create(
    char *apiVersion,
    char *kind,
    char *name,
    extensions_v1beta1_rollback_config_t *rollbackTo,
    list_t* updatedAnnotations
    ) {
	extensions_v1beta1_deployment_rollback_t *extensions_v1beta1_deployment_rollback_local_var = malloc(sizeof(extensions_v1beta1_deployment_rollback_t));
    if (!extensions_v1beta1_deployment_rollback_local_var) {
        return NULL;
    }
	extensions_v1beta1_deployment_rollback_local_var->apiVersion = apiVersion;
	extensions_v1beta1_deployment_rollback_local_var->kind = kind;
	extensions_v1beta1_deployment_rollback_local_var->name = name;
	extensions_v1beta1_deployment_rollback_local_var->rollbackTo = rollbackTo;
	extensions_v1beta1_deployment_rollback_local_var->updatedAnnotations = updatedAnnotations;

	return extensions_v1beta1_deployment_rollback_local_var;
}


void extensions_v1beta1_deployment_rollback_free(extensions_v1beta1_deployment_rollback_t *extensions_v1beta1_deployment_rollback) {
    listEntry_t *listEntry;
    free(extensions_v1beta1_deployment_rollback->apiVersion);
    free(extensions_v1beta1_deployment_rollback->kind);
    free(extensions_v1beta1_deployment_rollback->name);
    extensions_v1beta1_rollback_config_free(extensions_v1beta1_deployment_rollback->rollbackTo);
	list_ForEach(listEntry, extensions_v1beta1_deployment_rollback->updatedAnnotations) {
		keyValuePair_t *localMapKeyPair = (keyValuePair_t*) listEntry->data;
        free (localMapKeyPair->key);
        free (localMapKeyPair->value);
	}
	list_free(extensions_v1beta1_deployment_rollback->updatedAnnotations);
	free(extensions_v1beta1_deployment_rollback);
}

cJSON *extensions_v1beta1_deployment_rollback_convertToJSON(extensions_v1beta1_deployment_rollback_t *extensions_v1beta1_deployment_rollback) {
	cJSON *item = cJSON_CreateObject();

	// extensions_v1beta1_deployment_rollback->apiVersion
    if(extensions_v1beta1_deployment_rollback->apiVersion) { 
    if(cJSON_AddStringToObject(item, "apiVersion", extensions_v1beta1_deployment_rollback->apiVersion) == NULL) {
    goto fail; //String
    }
     } 


	// extensions_v1beta1_deployment_rollback->kind
    if(extensions_v1beta1_deployment_rollback->kind) { 
    if(cJSON_AddStringToObject(item, "kind", extensions_v1beta1_deployment_rollback->kind) == NULL) {
    goto fail; //String
    }
     } 


	// extensions_v1beta1_deployment_rollback->name
    if (!extensions_v1beta1_deployment_rollback->name) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "name", extensions_v1beta1_deployment_rollback->name) == NULL) {
    goto fail; //String
    }


	// extensions_v1beta1_deployment_rollback->rollbackTo
    if (!extensions_v1beta1_deployment_rollback->rollbackTo) {
        goto fail;
    }
    
    cJSON *rollbackTo_local_JSON = extensions_v1beta1_rollback_config_convertToJSON(extensions_v1beta1_deployment_rollback->rollbackTo);
    if(rollbackTo_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "rollbackTo", rollbackTo_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


	// extensions_v1beta1_deployment_rollback->updatedAnnotations
    if(extensions_v1beta1_deployment_rollback->updatedAnnotations) { 
	cJSON *updatedAnnotations = cJSON_AddObjectToObject(item, "updatedAnnotations");
	if(updatedAnnotations == NULL) {
		goto fail; //primitive map container
	}
    cJSON *localMapObject = cJSON_CreateObject(); //Memory free to be implemented in user code
	listEntry_t *updatedAnnotationsListEntry;
    if (extensions_v1beta1_deployment_rollback->updatedAnnotations) {
    list_ForEach(updatedAnnotationsListEntry, extensions_v1beta1_deployment_rollback->updatedAnnotations) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)updatedAnnotationsListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
        cJSON_AddItemToObject(updatedAnnotations,"", localMapObject);
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

extensions_v1beta1_deployment_rollback_t *extensions_v1beta1_deployment_rollback_parseFromJSON(cJSON *extensions_v1beta1_deployment_rollbackJSON){

    extensions_v1beta1_deployment_rollback_t *extensions_v1beta1_deployment_rollback_local_var = NULL;

    // extensions_v1beta1_deployment_rollback->apiVersion
    cJSON *apiVersion = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_deployment_rollbackJSON, "apiVersion");
    if (apiVersion) { 
    if(!cJSON_IsString(apiVersion))
    {
    goto end; //String
    }
    }

    // extensions_v1beta1_deployment_rollback->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_deployment_rollbackJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // extensions_v1beta1_deployment_rollback->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_deployment_rollbackJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // extensions_v1beta1_deployment_rollback->rollbackTo
    cJSON *rollbackTo = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_deployment_rollbackJSON, "rollbackTo");
    if (!rollbackTo) {
        goto end;
    }

    extensions_v1beta1_rollback_config_t *rollbackTo_local_nonprim = NULL;
    
    rollbackTo_local_nonprim = extensions_v1beta1_rollback_config_parseFromJSON(rollbackTo); //nonprimitive

    // extensions_v1beta1_deployment_rollback->updatedAnnotations
    cJSON *updatedAnnotations = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_deployment_rollbackJSON, "updatedAnnotations");
    list_t *List;
    if (updatedAnnotations) { 
    cJSON *_local_map;
    if(!cJSON_IsObject(updatedAnnotations)) {
        goto end;//primitive map container
    }
    List = list_create();
    keyValuePair_t *localMapKeyPair;
    cJSON_ArrayForEach(_local_map, updatedAnnotations)
    {
        if(!cJSON_IsNumber(_local_map))
        {
            goto end;
        }
        localMapKeyPair = keyValuePair_create(strdup(_local_map->string),&_local_map->valuedouble );
        list_addElement(List , localMapKeyPair);
    }
    }


    extensions_v1beta1_deployment_rollback_local_var = extensions_v1beta1_deployment_rollback_create (
        apiVersion ? strdup(apiVersion->valuestring) : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        strdup(name->valuestring),
        rollbackTo_local_nonprim,
        updatedAnnotations ? List : NULL
        );

    return extensions_v1beta1_deployment_rollback_local_var;
end:
    return NULL;

}
