#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_subject.h"



v1_subject_t *v1_subject_create(
    char *apiGroup,
    char *kind,
    char *name,
    char *namespace
    ) {
	v1_subject_t *v1_subject_local_var = malloc(sizeof(v1_subject_t));
    if (!v1_subject_local_var) {
        return NULL;
    }
	v1_subject_local_var->apiGroup = apiGroup;
	v1_subject_local_var->kind = kind;
	v1_subject_local_var->name = name;
	v1_subject_local_var->namespace = namespace;

	return v1_subject_local_var;
}


void v1_subject_free(v1_subject_t *v1_subject) {
    listEntry_t *listEntry;
    free(v1_subject->apiGroup);
    free(v1_subject->kind);
    free(v1_subject->name);
    free(v1_subject->namespace);
	free(v1_subject);
}

cJSON *v1_subject_convertToJSON(v1_subject_t *v1_subject) {
	cJSON *item = cJSON_CreateObject();

	// v1_subject->apiGroup
    if(v1_subject->apiGroup) { 
    if(cJSON_AddStringToObject(item, "apiGroup", v1_subject->apiGroup) == NULL) {
    goto fail; //String
    }
     } 


	// v1_subject->kind
    if (!v1_subject->kind) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "kind", v1_subject->kind) == NULL) {
    goto fail; //String
    }


	// v1_subject->name
    if (!v1_subject->name) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "name", v1_subject->name) == NULL) {
    goto fail; //String
    }


	// v1_subject->namespace
    if(v1_subject->namespace) { 
    if(cJSON_AddStringToObject(item, "namespace", v1_subject->namespace) == NULL) {
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

v1_subject_t *v1_subject_parseFromJSON(cJSON *v1_subjectJSON){

    v1_subject_t *v1_subject_local_var = NULL;

    // v1_subject->apiGroup
    cJSON *apiGroup = cJSON_GetObjectItemCaseSensitive(v1_subjectJSON, "apiGroup");
    if (apiGroup) { 
    if(!cJSON_IsString(apiGroup))
    {
    goto end; //String
    }
    }

    // v1_subject->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_subjectJSON, "kind");
    if (!kind) {
        goto end;
    }

    
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }

    // v1_subject->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_subjectJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // v1_subject->namespace
    cJSON *namespace = cJSON_GetObjectItemCaseSensitive(v1_subjectJSON, "namespace");
    if (namespace) { 
    if(!cJSON_IsString(namespace))
    {
    goto end; //String
    }
    }


    v1_subject_local_var = v1_subject_create (
        apiGroup ? strdup(apiGroup->valuestring) : NULL,
        strdup(kind->valuestring),
        strdup(name->valuestring),
        namespace ? strdup(namespace->valuestring) : NULL
        );

    return v1_subject_local_var;
end:
    return NULL;

}
