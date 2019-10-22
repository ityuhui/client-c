#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_subject.h"



v1beta1_subject_t *v1beta1_subject_create(
    char *apiGroup,
    char *kind,
    char *name,
    char *namespace
    ) {
	v1beta1_subject_t *v1beta1_subject_local_var = malloc(sizeof(v1beta1_subject_t));
    if (!v1beta1_subject_local_var) {
        return NULL;
    }
	v1beta1_subject_local_var->apiGroup = apiGroup;
	v1beta1_subject_local_var->kind = kind;
	v1beta1_subject_local_var->name = name;
	v1beta1_subject_local_var->namespace = namespace;

	return v1beta1_subject_local_var;
}


void v1beta1_subject_free(v1beta1_subject_t *v1beta1_subject) {
    listEntry_t *listEntry;
    free(v1beta1_subject->apiGroup);
    free(v1beta1_subject->kind);
    free(v1beta1_subject->name);
    free(v1beta1_subject->namespace);
	free(v1beta1_subject);
}

cJSON *v1beta1_subject_convertToJSON(v1beta1_subject_t *v1beta1_subject) {
	cJSON *item = cJSON_CreateObject();

	// v1beta1_subject->apiGroup
    if(v1beta1_subject->apiGroup) { 
    if(cJSON_AddStringToObject(item, "apiGroup", v1beta1_subject->apiGroup) == NULL) {
    goto fail; //String
    }
     } 


	// v1beta1_subject->kind
    if (!v1beta1_subject->kind) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "kind", v1beta1_subject->kind) == NULL) {
    goto fail; //String
    }


	// v1beta1_subject->name
    if (!v1beta1_subject->name) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "name", v1beta1_subject->name) == NULL) {
    goto fail; //String
    }


	// v1beta1_subject->namespace
    if(v1beta1_subject->namespace) { 
    if(cJSON_AddStringToObject(item, "namespace", v1beta1_subject->namespace) == NULL) {
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

v1beta1_subject_t *v1beta1_subject_parseFromJSON(cJSON *v1beta1_subjectJSON){

    v1beta1_subject_t *v1beta1_subject_local_var = NULL;

    // v1beta1_subject->apiGroup
    cJSON *apiGroup = cJSON_GetObjectItemCaseSensitive(v1beta1_subjectJSON, "apiGroup");
    if (apiGroup) { 
    if(!cJSON_IsString(apiGroup))
    {
    goto end; //String
    }
    }

    // v1beta1_subject->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1beta1_subjectJSON, "kind");
    if (!kind) {
        goto end;
    }

    
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }

    // v1beta1_subject->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1beta1_subjectJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // v1beta1_subject->namespace
    cJSON *namespace = cJSON_GetObjectItemCaseSensitive(v1beta1_subjectJSON, "namespace");
    if (namespace) { 
    if(!cJSON_IsString(namespace))
    {
    goto end; //String
    }
    }


    v1beta1_subject_local_var = v1beta1_subject_create (
        apiGroup ? strdup(apiGroup->valuestring) : NULL,
        strdup(kind->valuestring),
        strdup(name->valuestring),
        namespace ? strdup(namespace->valuestring) : NULL
        );

    return v1beta1_subject_local_var;
end:
    return NULL;

}
