#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_role_ref.h"



v1alpha1_role_ref_t *v1alpha1_role_ref_create(
    char *apiGroup,
    char *kind,
    char *name
    ) {
	v1alpha1_role_ref_t *v1alpha1_role_ref_local_var = malloc(sizeof(v1alpha1_role_ref_t));
    if (!v1alpha1_role_ref_local_var) {
        return NULL;
    }
	v1alpha1_role_ref_local_var->apiGroup = apiGroup;
	v1alpha1_role_ref_local_var->kind = kind;
	v1alpha1_role_ref_local_var->name = name;

	return v1alpha1_role_ref_local_var;
}


void v1alpha1_role_ref_free(v1alpha1_role_ref_t *v1alpha1_role_ref) {
    listEntry_t *listEntry;
    free(v1alpha1_role_ref->apiGroup);
    free(v1alpha1_role_ref->kind);
    free(v1alpha1_role_ref->name);
	free(v1alpha1_role_ref);
}

cJSON *v1alpha1_role_ref_convertToJSON(v1alpha1_role_ref_t *v1alpha1_role_ref) {
	cJSON *item = cJSON_CreateObject();

	// v1alpha1_role_ref->apiGroup
    if (!v1alpha1_role_ref->apiGroup) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "apiGroup", v1alpha1_role_ref->apiGroup) == NULL) {
    goto fail; //String
    }


	// v1alpha1_role_ref->kind
    if (!v1alpha1_role_ref->kind) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "kind", v1alpha1_role_ref->kind) == NULL) {
    goto fail; //String
    }


	// v1alpha1_role_ref->name
    if (!v1alpha1_role_ref->name) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "name", v1alpha1_role_ref->name) == NULL) {
    goto fail; //String
    }

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1alpha1_role_ref_t *v1alpha1_role_ref_parseFromJSON(cJSON *v1alpha1_role_refJSON){

    v1alpha1_role_ref_t *v1alpha1_role_ref_local_var = NULL;

    // v1alpha1_role_ref->apiGroup
    cJSON *apiGroup = cJSON_GetObjectItemCaseSensitive(v1alpha1_role_refJSON, "apiGroup");
    if (!apiGroup) {
        goto end;
    }

    
    if(!cJSON_IsString(apiGroup))
    {
    goto end; //String
    }

    // v1alpha1_role_ref->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1alpha1_role_refJSON, "kind");
    if (!kind) {
        goto end;
    }

    
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }

    // v1alpha1_role_ref->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1alpha1_role_refJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }


    v1alpha1_role_ref_local_var = v1alpha1_role_ref_create (
        strdup(apiGroup->valuestring),
        strdup(kind->valuestring),
        strdup(name->valuestring)
        );

    return v1alpha1_role_ref_local_var;
end:
    return NULL;

}
