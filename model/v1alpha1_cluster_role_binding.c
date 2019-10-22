#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_cluster_role_binding.h"



v1alpha1_cluster_role_binding_t *v1alpha1_cluster_role_binding_create(
    char *apiVersion,
    char *kind,
    v1_object_meta_t *metadata,
    v1alpha1_role_ref_t *roleRef,
    list_t *subjects
    ) {
	v1alpha1_cluster_role_binding_t *v1alpha1_cluster_role_binding_local_var = malloc(sizeof(v1alpha1_cluster_role_binding_t));
    if (!v1alpha1_cluster_role_binding_local_var) {
        return NULL;
    }
	v1alpha1_cluster_role_binding_local_var->apiVersion = apiVersion;
	v1alpha1_cluster_role_binding_local_var->kind = kind;
	v1alpha1_cluster_role_binding_local_var->metadata = metadata;
	v1alpha1_cluster_role_binding_local_var->roleRef = roleRef;
	v1alpha1_cluster_role_binding_local_var->subjects = subjects;

	return v1alpha1_cluster_role_binding_local_var;
}


void v1alpha1_cluster_role_binding_free(v1alpha1_cluster_role_binding_t *v1alpha1_cluster_role_binding) {
    listEntry_t *listEntry;
    free(v1alpha1_cluster_role_binding->apiVersion);
    free(v1alpha1_cluster_role_binding->kind);
    v1_object_meta_free(v1alpha1_cluster_role_binding->metadata);
    v1alpha1_role_ref_free(v1alpha1_cluster_role_binding->roleRef);
	list_ForEach(listEntry, v1alpha1_cluster_role_binding->subjects) {
		v1alpha1_subject_free(listEntry->data);
	}
	list_free(v1alpha1_cluster_role_binding->subjects);
	free(v1alpha1_cluster_role_binding);
}

cJSON *v1alpha1_cluster_role_binding_convertToJSON(v1alpha1_cluster_role_binding_t *v1alpha1_cluster_role_binding) {
	cJSON *item = cJSON_CreateObject();

	// v1alpha1_cluster_role_binding->apiVersion
    if(v1alpha1_cluster_role_binding->apiVersion) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1alpha1_cluster_role_binding->apiVersion) == NULL) {
    goto fail; //String
    }
     } 


	// v1alpha1_cluster_role_binding->kind
    if(v1alpha1_cluster_role_binding->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1alpha1_cluster_role_binding->kind) == NULL) {
    goto fail; //String
    }
     } 


	// v1alpha1_cluster_role_binding->metadata
    if(v1alpha1_cluster_role_binding->metadata) { 
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1alpha1_cluster_role_binding->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1alpha1_cluster_role_binding->roleRef
    if (!v1alpha1_cluster_role_binding->roleRef) {
        goto fail;
    }
    
    cJSON *roleRef_local_JSON = v1alpha1_role_ref_convertToJSON(v1alpha1_cluster_role_binding->roleRef);
    if(roleRef_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "roleRef", roleRef_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


	// v1alpha1_cluster_role_binding->subjects
    if(v1alpha1_cluster_role_binding->subjects) { 
    cJSON *subjects = cJSON_AddArrayToObject(item, "subjects");
    if(subjects == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *subjectsListEntry;
    if (v1alpha1_cluster_role_binding->subjects) {
    list_ForEach(subjectsListEntry, v1alpha1_cluster_role_binding->subjects) {
    cJSON *itemLocal = v1alpha1_subject_convertToJSON(subjectsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(subjects, itemLocal);
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

v1alpha1_cluster_role_binding_t *v1alpha1_cluster_role_binding_parseFromJSON(cJSON *v1alpha1_cluster_role_bindingJSON){

    v1alpha1_cluster_role_binding_t *v1alpha1_cluster_role_binding_local_var = NULL;

    // v1alpha1_cluster_role_binding->apiVersion
    cJSON *apiVersion = cJSON_GetObjectItemCaseSensitive(v1alpha1_cluster_role_bindingJSON, "apiVersion");
    if (apiVersion) { 
    if(!cJSON_IsString(apiVersion))
    {
    goto end; //String
    }
    }

    // v1alpha1_cluster_role_binding->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1alpha1_cluster_role_bindingJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1alpha1_cluster_role_binding->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1alpha1_cluster_role_bindingJSON, "metadata");
    v1_object_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1alpha1_cluster_role_binding->roleRef
    cJSON *roleRef = cJSON_GetObjectItemCaseSensitive(v1alpha1_cluster_role_bindingJSON, "roleRef");
    if (!roleRef) {
        goto end;
    }

    v1alpha1_role_ref_t *roleRef_local_nonprim = NULL;
    
    roleRef_local_nonprim = v1alpha1_role_ref_parseFromJSON(roleRef); //nonprimitive

    // v1alpha1_cluster_role_binding->subjects
    cJSON *subjects = cJSON_GetObjectItemCaseSensitive(v1alpha1_cluster_role_bindingJSON, "subjects");
    list_t *subjectsList;
    if (subjects) { 
    cJSON *subjects_local_nonprimitive;
    if(!cJSON_IsArray(subjects)){
        goto end; //nonprimitive container
    }

    subjectsList = list_create();

    cJSON_ArrayForEach(subjects_local_nonprimitive,subjects )
    {
        if(!cJSON_IsObject(subjects_local_nonprimitive)){
            goto end;
        }
        v1alpha1_subject_t *subjectsItem = v1alpha1_subject_parseFromJSON(subjects_local_nonprimitive);

        list_addElement(subjectsList, subjectsItem);
    }
    }


    v1alpha1_cluster_role_binding_local_var = v1alpha1_cluster_role_binding_create (
        apiVersion ? strdup(apiVersion->valuestring) : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        roleRef_local_nonprim,
        subjects ? subjectsList : NULL
        );

    return v1alpha1_cluster_role_binding_local_var;
end:
    return NULL;

}
