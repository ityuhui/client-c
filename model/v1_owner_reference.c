#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_owner_reference.h"



v1_owner_reference_t *v1_owner_reference_create(
    char *apiVersion,
    int blockOwnerDeletion,
    int controller,
    char *kind,
    char *name,
    char *uid
    ) {
	v1_owner_reference_t *v1_owner_reference_local_var = malloc(sizeof(v1_owner_reference_t));
    if (!v1_owner_reference_local_var) {
        return NULL;
    }
	v1_owner_reference_local_var->apiVersion = apiVersion;
	v1_owner_reference_local_var->blockOwnerDeletion = blockOwnerDeletion;
	v1_owner_reference_local_var->controller = controller;
	v1_owner_reference_local_var->kind = kind;
	v1_owner_reference_local_var->name = name;
	v1_owner_reference_local_var->uid = uid;

	return v1_owner_reference_local_var;
}


void v1_owner_reference_free(v1_owner_reference_t *v1_owner_reference) {
    listEntry_t *listEntry;
    free(v1_owner_reference->apiVersion);
    free(v1_owner_reference->kind);
    free(v1_owner_reference->name);
    free(v1_owner_reference->uid);
	free(v1_owner_reference);
}

cJSON *v1_owner_reference_convertToJSON(v1_owner_reference_t *v1_owner_reference) {
	cJSON *item = cJSON_CreateObject();

	// v1_owner_reference->apiVersion
    if (!v1_owner_reference->apiVersion) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "apiVersion", v1_owner_reference->apiVersion) == NULL) {
    goto fail; //String
    }


	// v1_owner_reference->blockOwnerDeletion
    if(v1_owner_reference->blockOwnerDeletion) { 
    if(cJSON_AddBoolToObject(item, "blockOwnerDeletion", v1_owner_reference->blockOwnerDeletion) == NULL) {
    goto fail; //Bool
    }
     } 


	// v1_owner_reference->controller
    if(v1_owner_reference->controller) { 
    if(cJSON_AddBoolToObject(item, "controller", v1_owner_reference->controller) == NULL) {
    goto fail; //Bool
    }
     } 


	// v1_owner_reference->kind
    if (!v1_owner_reference->kind) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "kind", v1_owner_reference->kind) == NULL) {
    goto fail; //String
    }


	// v1_owner_reference->name
    if (!v1_owner_reference->name) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "name", v1_owner_reference->name) == NULL) {
    goto fail; //String
    }


	// v1_owner_reference->uid
    if (!v1_owner_reference->uid) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "uid", v1_owner_reference->uid) == NULL) {
    goto fail; //String
    }

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1_owner_reference_t *v1_owner_reference_parseFromJSON(cJSON *v1_owner_referenceJSON){

    v1_owner_reference_t *v1_owner_reference_local_var = NULL;

    // v1_owner_reference->apiVersion
    cJSON *apiVersion = cJSON_GetObjectItemCaseSensitive(v1_owner_referenceJSON, "apiVersion");
    if (!apiVersion) {
        goto end;
    }

    
    if(!cJSON_IsString(apiVersion))
    {
    goto end; //String
    }

    // v1_owner_reference->blockOwnerDeletion
    cJSON *blockOwnerDeletion = cJSON_GetObjectItemCaseSensitive(v1_owner_referenceJSON, "blockOwnerDeletion");
    if (blockOwnerDeletion) { 
    if(!cJSON_IsBool(blockOwnerDeletion))
    {
    goto end; //Bool
    }
    }

    // v1_owner_reference->controller
    cJSON *controller = cJSON_GetObjectItemCaseSensitive(v1_owner_referenceJSON, "controller");
    if (controller) { 
    if(!cJSON_IsBool(controller))
    {
    goto end; //Bool
    }
    }

    // v1_owner_reference->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_owner_referenceJSON, "kind");
    if (!kind) {
        goto end;
    }

    
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }

    // v1_owner_reference->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_owner_referenceJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // v1_owner_reference->uid
    cJSON *uid = cJSON_GetObjectItemCaseSensitive(v1_owner_referenceJSON, "uid");
    if (!uid) {
        goto end;
    }

    
    if(!cJSON_IsString(uid))
    {
    goto end; //String
    }


    v1_owner_reference_local_var = v1_owner_reference_create (
        strdup(apiVersion->valuestring),
        blockOwnerDeletion ? blockOwnerDeletion->valueint : 0,
        controller ? controller->valueint : 0,
        strdup(kind->valuestring),
        strdup(name->valuestring),
        strdup(uid->valuestring)
        );

    return v1_owner_reference_local_var;
end:
    return NULL;

}
