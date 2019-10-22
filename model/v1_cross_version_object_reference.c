#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_cross_version_object_reference.h"



v1_cross_version_object_reference_t *v1_cross_version_object_reference_create(
    char *apiVersion,
    char *kind,
    char *name
    ) {
	v1_cross_version_object_reference_t *v1_cross_version_object_reference_local_var = malloc(sizeof(v1_cross_version_object_reference_t));
    if (!v1_cross_version_object_reference_local_var) {
        return NULL;
    }
	v1_cross_version_object_reference_local_var->apiVersion = apiVersion;
	v1_cross_version_object_reference_local_var->kind = kind;
	v1_cross_version_object_reference_local_var->name = name;

	return v1_cross_version_object_reference_local_var;
}


void v1_cross_version_object_reference_free(v1_cross_version_object_reference_t *v1_cross_version_object_reference) {
    listEntry_t *listEntry;
    free(v1_cross_version_object_reference->apiVersion);
    free(v1_cross_version_object_reference->kind);
    free(v1_cross_version_object_reference->name);
	free(v1_cross_version_object_reference);
}

cJSON *v1_cross_version_object_reference_convertToJSON(v1_cross_version_object_reference_t *v1_cross_version_object_reference) {
	cJSON *item = cJSON_CreateObject();

	// v1_cross_version_object_reference->apiVersion
    if(v1_cross_version_object_reference->apiVersion) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1_cross_version_object_reference->apiVersion) == NULL) {
    goto fail; //String
    }
     } 


	// v1_cross_version_object_reference->kind
    if (!v1_cross_version_object_reference->kind) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "kind", v1_cross_version_object_reference->kind) == NULL) {
    goto fail; //String
    }


	// v1_cross_version_object_reference->name
    if (!v1_cross_version_object_reference->name) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "name", v1_cross_version_object_reference->name) == NULL) {
    goto fail; //String
    }

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1_cross_version_object_reference_t *v1_cross_version_object_reference_parseFromJSON(cJSON *v1_cross_version_object_referenceJSON){

    v1_cross_version_object_reference_t *v1_cross_version_object_reference_local_var = NULL;

    // v1_cross_version_object_reference->apiVersion
    cJSON *apiVersion = cJSON_GetObjectItemCaseSensitive(v1_cross_version_object_referenceJSON, "apiVersion");
    if (apiVersion) { 
    if(!cJSON_IsString(apiVersion))
    {
    goto end; //String
    }
    }

    // v1_cross_version_object_reference->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_cross_version_object_referenceJSON, "kind");
    if (!kind) {
        goto end;
    }

    
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }

    // v1_cross_version_object_reference->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_cross_version_object_referenceJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }


    v1_cross_version_object_reference_local_var = v1_cross_version_object_reference_create (
        apiVersion ? strdup(apiVersion->valuestring) : NULL,
        strdup(kind->valuestring),
        strdup(name->valuestring)
        );

    return v1_cross_version_object_reference_local_var;
end:
    return NULL;

}
