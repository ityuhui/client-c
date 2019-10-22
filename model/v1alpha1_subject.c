#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_subject.h"



v1alpha1_subject_t *v1alpha1_subject_create(
    char *apiVersion,
    char *kind,
    char *name,
    char *namespace
    ) {
	v1alpha1_subject_t *v1alpha1_subject_local_var = malloc(sizeof(v1alpha1_subject_t));
    if (!v1alpha1_subject_local_var) {
        return NULL;
    }
	v1alpha1_subject_local_var->apiVersion = apiVersion;
	v1alpha1_subject_local_var->kind = kind;
	v1alpha1_subject_local_var->name = name;
	v1alpha1_subject_local_var->namespace = namespace;

	return v1alpha1_subject_local_var;
}


void v1alpha1_subject_free(v1alpha1_subject_t *v1alpha1_subject) {
    listEntry_t *listEntry;
    free(v1alpha1_subject->apiVersion);
    free(v1alpha1_subject->kind);
    free(v1alpha1_subject->name);
    free(v1alpha1_subject->namespace);
	free(v1alpha1_subject);
}

cJSON *v1alpha1_subject_convertToJSON(v1alpha1_subject_t *v1alpha1_subject) {
	cJSON *item = cJSON_CreateObject();

	// v1alpha1_subject->apiVersion
    if(v1alpha1_subject->apiVersion) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1alpha1_subject->apiVersion) == NULL) {
    goto fail; //String
    }
     } 


	// v1alpha1_subject->kind
    if (!v1alpha1_subject->kind) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "kind", v1alpha1_subject->kind) == NULL) {
    goto fail; //String
    }


	// v1alpha1_subject->name
    if (!v1alpha1_subject->name) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "name", v1alpha1_subject->name) == NULL) {
    goto fail; //String
    }


	// v1alpha1_subject->namespace
    if(v1alpha1_subject->namespace) { 
    if(cJSON_AddStringToObject(item, "namespace", v1alpha1_subject->namespace) == NULL) {
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

v1alpha1_subject_t *v1alpha1_subject_parseFromJSON(cJSON *v1alpha1_subjectJSON){

    v1alpha1_subject_t *v1alpha1_subject_local_var = NULL;

    // v1alpha1_subject->apiVersion
    cJSON *apiVersion = cJSON_GetObjectItemCaseSensitive(v1alpha1_subjectJSON, "apiVersion");
    if (apiVersion) { 
    if(!cJSON_IsString(apiVersion))
    {
    goto end; //String
    }
    }

    // v1alpha1_subject->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1alpha1_subjectJSON, "kind");
    if (!kind) {
        goto end;
    }

    
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }

    // v1alpha1_subject->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1alpha1_subjectJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // v1alpha1_subject->namespace
    cJSON *namespace = cJSON_GetObjectItemCaseSensitive(v1alpha1_subjectJSON, "namespace");
    if (namespace) { 
    if(!cJSON_IsString(namespace))
    {
    goto end; //String
    }
    }


    v1alpha1_subject_local_var = v1alpha1_subject_create (
        apiVersion ? strdup(apiVersion->valuestring) : NULL,
        strdup(kind->valuestring),
        strdup(name->valuestring),
        namespace ? strdup(namespace->valuestring) : NULL
        );

    return v1alpha1_subject_local_var;
end:
    return NULL;

}
