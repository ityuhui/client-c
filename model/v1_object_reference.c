#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_object_reference.h"



v1_object_reference_t *v1_object_reference_create(
    char *apiVersion,
    char *fieldPath,
    char *kind,
    char *name,
    char *namespace,
    char *resourceVersion,
    char *uid
    ) {
	v1_object_reference_t *v1_object_reference_local_var = malloc(sizeof(v1_object_reference_t));
    if (!v1_object_reference_local_var) {
        return NULL;
    }
	v1_object_reference_local_var->apiVersion = apiVersion;
	v1_object_reference_local_var->fieldPath = fieldPath;
	v1_object_reference_local_var->kind = kind;
	v1_object_reference_local_var->name = name;
	v1_object_reference_local_var->namespace = namespace;
	v1_object_reference_local_var->resourceVersion = resourceVersion;
	v1_object_reference_local_var->uid = uid;

	return v1_object_reference_local_var;
}


void v1_object_reference_free(v1_object_reference_t *v1_object_reference) {
    listEntry_t *listEntry;
    free(v1_object_reference->apiVersion);
    free(v1_object_reference->fieldPath);
    free(v1_object_reference->kind);
    free(v1_object_reference->name);
    free(v1_object_reference->namespace);
    free(v1_object_reference->resourceVersion);
    free(v1_object_reference->uid);
	free(v1_object_reference);
}

cJSON *v1_object_reference_convertToJSON(v1_object_reference_t *v1_object_reference) {
	cJSON *item = cJSON_CreateObject();

	// v1_object_reference->apiVersion
    if(v1_object_reference->apiVersion) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1_object_reference->apiVersion) == NULL) {
    goto fail; //String
    }
     } 


	// v1_object_reference->fieldPath
    if(v1_object_reference->fieldPath) { 
    if(cJSON_AddStringToObject(item, "fieldPath", v1_object_reference->fieldPath) == NULL) {
    goto fail; //String
    }
     } 


	// v1_object_reference->kind
    if(v1_object_reference->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1_object_reference->kind) == NULL) {
    goto fail; //String
    }
     } 


	// v1_object_reference->name
    if(v1_object_reference->name) { 
    if(cJSON_AddStringToObject(item, "name", v1_object_reference->name) == NULL) {
    goto fail; //String
    }
     } 


	// v1_object_reference->namespace
    if(v1_object_reference->namespace) { 
    if(cJSON_AddStringToObject(item, "namespace", v1_object_reference->namespace) == NULL) {
    goto fail; //String
    }
     } 


	// v1_object_reference->resourceVersion
    if(v1_object_reference->resourceVersion) { 
    if(cJSON_AddStringToObject(item, "resourceVersion", v1_object_reference->resourceVersion) == NULL) {
    goto fail; //String
    }
     } 


	// v1_object_reference->uid
    if(v1_object_reference->uid) { 
    if(cJSON_AddStringToObject(item, "uid", v1_object_reference->uid) == NULL) {
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

v1_object_reference_t *v1_object_reference_parseFromJSON(cJSON *v1_object_referenceJSON){

    v1_object_reference_t *v1_object_reference_local_var = NULL;

    // v1_object_reference->apiVersion
    cJSON *apiVersion = cJSON_GetObjectItemCaseSensitive(v1_object_referenceJSON, "apiVersion");
    if (apiVersion) { 
    if(!cJSON_IsString(apiVersion))
    {
    goto end; //String
    }
    }

    // v1_object_reference->fieldPath
    cJSON *fieldPath = cJSON_GetObjectItemCaseSensitive(v1_object_referenceJSON, "fieldPath");
    if (fieldPath) { 
    if(!cJSON_IsString(fieldPath))
    {
    goto end; //String
    }
    }

    // v1_object_reference->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_object_referenceJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1_object_reference->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_object_referenceJSON, "name");
    if (name) { 
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }
    }

    // v1_object_reference->namespace
    cJSON *namespace = cJSON_GetObjectItemCaseSensitive(v1_object_referenceJSON, "namespace");
    if (namespace) { 
    if(!cJSON_IsString(namespace))
    {
    goto end; //String
    }
    }

    // v1_object_reference->resourceVersion
    cJSON *resourceVersion = cJSON_GetObjectItemCaseSensitive(v1_object_referenceJSON, "resourceVersion");
    if (resourceVersion) { 
    if(!cJSON_IsString(resourceVersion))
    {
    goto end; //String
    }
    }

    // v1_object_reference->uid
    cJSON *uid = cJSON_GetObjectItemCaseSensitive(v1_object_referenceJSON, "uid");
    if (uid) { 
    if(!cJSON_IsString(uid))
    {
    goto end; //String
    }
    }


    v1_object_reference_local_var = v1_object_reference_create (
        apiVersion ? strdup(apiVersion->valuestring) : NULL,
        fieldPath ? strdup(fieldPath->valuestring) : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        name ? strdup(name->valuestring) : NULL,
        namespace ? strdup(namespace->valuestring) : NULL,
        resourceVersion ? strdup(resourceVersion->valuestring) : NULL,
        uid ? strdup(uid->valuestring) : NULL
        );

    return v1_object_reference_local_var;
end:
    return NULL;

}
