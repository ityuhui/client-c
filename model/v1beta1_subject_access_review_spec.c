#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_subject_access_review_spec.h"



v1beta1_subject_access_review_spec_t *v1beta1_subject_access_review_spec_create(
    list_t* extra,
    list_t *group,
    v1beta1_non_resource_attributes_t *nonResourceAttributes,
    v1beta1_resource_attributes_t *resourceAttributes,
    char *uid,
    char *user
    ) {
	v1beta1_subject_access_review_spec_t *v1beta1_subject_access_review_spec_local_var = malloc(sizeof(v1beta1_subject_access_review_spec_t));
    if (!v1beta1_subject_access_review_spec_local_var) {
        return NULL;
    }
	v1beta1_subject_access_review_spec_local_var->extra = extra;
	v1beta1_subject_access_review_spec_local_var->group = group;
	v1beta1_subject_access_review_spec_local_var->nonResourceAttributes = nonResourceAttributes;
	v1beta1_subject_access_review_spec_local_var->resourceAttributes = resourceAttributes;
	v1beta1_subject_access_review_spec_local_var->uid = uid;
	v1beta1_subject_access_review_spec_local_var->user = user;

	return v1beta1_subject_access_review_spec_local_var;
}


void v1beta1_subject_access_review_spec_free(v1beta1_subject_access_review_spec_t *v1beta1_subject_access_review_spec) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, v1beta1_subject_access_review_spec->extra) {
		keyValuePair_t *localMapKeyPair = (keyValuePair_t*) listEntry->data;
        free (localMapKeyPair->key);
        free (localMapKeyPair->value);
	}
	list_free(v1beta1_subject_access_review_spec->extra);
	list_ForEach(listEntry, v1beta1_subject_access_review_spec->group) {
		free(listEntry->data);
	}
	list_free(v1beta1_subject_access_review_spec->group);
    v1beta1_non_resource_attributes_free(v1beta1_subject_access_review_spec->nonResourceAttributes);
    v1beta1_resource_attributes_free(v1beta1_subject_access_review_spec->resourceAttributes);
    free(v1beta1_subject_access_review_spec->uid);
    free(v1beta1_subject_access_review_spec->user);
	free(v1beta1_subject_access_review_spec);
}

cJSON *v1beta1_subject_access_review_spec_convertToJSON(v1beta1_subject_access_review_spec_t *v1beta1_subject_access_review_spec) {
	cJSON *item = cJSON_CreateObject();

	// v1beta1_subject_access_review_spec->extra
    if(v1beta1_subject_access_review_spec->extra) { 
	cJSON *extra = cJSON_AddObjectToObject(item, "extra");
	if(extra == NULL) {
		goto fail; //primitive map container
	}
    cJSON *localMapObject = cJSON_CreateObject(); //Memory free to be implemented in user code
	listEntry_t *extraListEntry;
    if (v1beta1_subject_access_review_spec->extra) {
    list_ForEach(extraListEntry, v1beta1_subject_access_review_spec->extra) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)extraListEntry->data;
        if(cJSON_AddNumberToObject(localMapObject, localKeyValue->key, *(double *)localKeyValue->value) == NULL)
        {
            goto fail;
        }
        cJSON_AddItemToObject(extra,"", localMapObject);
    }
    }
     } 


	// v1beta1_subject_access_review_spec->group
    if(v1beta1_subject_access_review_spec->group) { 
	cJSON *group = cJSON_AddArrayToObject(item, "group");
	if(group == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *groupListEntry;
    list_ForEach(groupListEntry, v1beta1_subject_access_review_spec->group) {
    if(cJSON_AddStringToObject(group, "", (char*)groupListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


	// v1beta1_subject_access_review_spec->nonResourceAttributes
    if(v1beta1_subject_access_review_spec->nonResourceAttributes) { 
    cJSON *nonResourceAttributes_local_JSON = v1beta1_non_resource_attributes_convertToJSON(v1beta1_subject_access_review_spec->nonResourceAttributes);
    if(nonResourceAttributes_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "nonResourceAttributes", nonResourceAttributes_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1beta1_subject_access_review_spec->resourceAttributes
    if(v1beta1_subject_access_review_spec->resourceAttributes) { 
    cJSON *resourceAttributes_local_JSON = v1beta1_resource_attributes_convertToJSON(v1beta1_subject_access_review_spec->resourceAttributes);
    if(resourceAttributes_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "resourceAttributes", resourceAttributes_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1beta1_subject_access_review_spec->uid
    if(v1beta1_subject_access_review_spec->uid) { 
    if(cJSON_AddStringToObject(item, "uid", v1beta1_subject_access_review_spec->uid) == NULL) {
    goto fail; //String
    }
     } 


	// v1beta1_subject_access_review_spec->user
    if(v1beta1_subject_access_review_spec->user) { 
    if(cJSON_AddStringToObject(item, "user", v1beta1_subject_access_review_spec->user) == NULL) {
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

v1beta1_subject_access_review_spec_t *v1beta1_subject_access_review_spec_parseFromJSON(cJSON *v1beta1_subject_access_review_specJSON){

    v1beta1_subject_access_review_spec_t *v1beta1_subject_access_review_spec_local_var = NULL;

    // v1beta1_subject_access_review_spec->extra
    cJSON *extra = cJSON_GetObjectItemCaseSensitive(v1beta1_subject_access_review_specJSON, "extra");
    list_t *List;
    if (extra) { 
    cJSON *_local_map;
    if(!cJSON_IsObject(extra)) {
        goto end;//primitive map container
    }
    List = list_create();
    keyValuePair_t *localMapKeyPair;
    cJSON_ArrayForEach(_local_map, extra)
    {
        if(!cJSON_IsNumber(_local_map))
        {
            goto end;
        }
        localMapKeyPair = keyValuePair_create(strdup(_local_map->string),&_local_map->valuedouble );
        list_addElement(List , localMapKeyPair);
    }
    }

    // v1beta1_subject_access_review_spec->group
    cJSON *group = cJSON_GetObjectItemCaseSensitive(v1beta1_subject_access_review_specJSON, "group");
    list_t *groupList;
    if (group) { 
    cJSON *group_local;
    if(!cJSON_IsArray(group)) {
        goto end;//primitive container
    }
    groupList = list_create();

    cJSON_ArrayForEach(group_local, group)
    {
        if(!cJSON_IsString(group_local))
        {
            goto end;
        }
        list_addElement(groupList , strdup(group_local->valuestring));
    }
    }

    // v1beta1_subject_access_review_spec->nonResourceAttributes
    cJSON *nonResourceAttributes = cJSON_GetObjectItemCaseSensitive(v1beta1_subject_access_review_specJSON, "nonResourceAttributes");
    v1beta1_non_resource_attributes_t *nonResourceAttributes_local_nonprim = NULL;
    if (nonResourceAttributes) { 
    nonResourceAttributes_local_nonprim = v1beta1_non_resource_attributes_parseFromJSON(nonResourceAttributes); //nonprimitive
    }

    // v1beta1_subject_access_review_spec->resourceAttributes
    cJSON *resourceAttributes = cJSON_GetObjectItemCaseSensitive(v1beta1_subject_access_review_specJSON, "resourceAttributes");
    v1beta1_resource_attributes_t *resourceAttributes_local_nonprim = NULL;
    if (resourceAttributes) { 
    resourceAttributes_local_nonprim = v1beta1_resource_attributes_parseFromJSON(resourceAttributes); //nonprimitive
    }

    // v1beta1_subject_access_review_spec->uid
    cJSON *uid = cJSON_GetObjectItemCaseSensitive(v1beta1_subject_access_review_specJSON, "uid");
    if (uid) { 
    if(!cJSON_IsString(uid))
    {
    goto end; //String
    }
    }

    // v1beta1_subject_access_review_spec->user
    cJSON *user = cJSON_GetObjectItemCaseSensitive(v1beta1_subject_access_review_specJSON, "user");
    if (user) { 
    if(!cJSON_IsString(user))
    {
    goto end; //String
    }
    }


    v1beta1_subject_access_review_spec_local_var = v1beta1_subject_access_review_spec_create (
        extra ? List : NULL,
        group ? groupList : NULL,
        nonResourceAttributes ? nonResourceAttributes_local_nonprim : NULL,
        resourceAttributes ? resourceAttributes_local_nonprim : NULL,
        uid ? strdup(uid->valuestring) : NULL,
        user ? strdup(user->valuestring) : NULL
        );

    return v1beta1_subject_access_review_spec_local_var;
end:
    return NULL;

}
