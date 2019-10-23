#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_certificate_signing_request_spec.h"



v1beta1_certificate_signing_request_spec_t *v1beta1_certificate_signing_request_spec_create(
    list_t* extra,
    list_t *groups,
    char request,
    char *uid,
    list_t *usages,
    char *username
    ) {
	v1beta1_certificate_signing_request_spec_t *v1beta1_certificate_signing_request_spec_local_var = malloc(sizeof(v1beta1_certificate_signing_request_spec_t));
    if (!v1beta1_certificate_signing_request_spec_local_var) {
        return NULL;
    }
	v1beta1_certificate_signing_request_spec_local_var->extra = extra;
	v1beta1_certificate_signing_request_spec_local_var->groups = groups;
	v1beta1_certificate_signing_request_spec_local_var->request = request;
	v1beta1_certificate_signing_request_spec_local_var->uid = uid;
	v1beta1_certificate_signing_request_spec_local_var->usages = usages;
	v1beta1_certificate_signing_request_spec_local_var->username = username;

	return v1beta1_certificate_signing_request_spec_local_var;
}


void v1beta1_certificate_signing_request_spec_free(v1beta1_certificate_signing_request_spec_t *v1beta1_certificate_signing_request_spec) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, v1beta1_certificate_signing_request_spec->extra) {
		keyValuePair_t *localMapKeyPair = (keyValuePair_t*) listEntry->data;
        free (localMapKeyPair->key);
        free (localMapKeyPair->value);
	}
	list_free(v1beta1_certificate_signing_request_spec->extra);
	list_ForEach(listEntry, v1beta1_certificate_signing_request_spec->groups) {
		free(listEntry->data);
	}
	list_free(v1beta1_certificate_signing_request_spec->groups);
    free(v1beta1_certificate_signing_request_spec->uid);
	list_ForEach(listEntry, v1beta1_certificate_signing_request_spec->usages) {
		free(listEntry->data);
	}
	list_free(v1beta1_certificate_signing_request_spec->usages);
    free(v1beta1_certificate_signing_request_spec->username);
	free(v1beta1_certificate_signing_request_spec);
}

cJSON *v1beta1_certificate_signing_request_spec_convertToJSON(v1beta1_certificate_signing_request_spec_t *v1beta1_certificate_signing_request_spec) {
	cJSON *item = cJSON_CreateObject();

	// v1beta1_certificate_signing_request_spec->extra
    if(v1beta1_certificate_signing_request_spec->extra) { 
	cJSON *extra = cJSON_AddObjectToObject(item, "extra");
	if(extra == NULL) {
		goto fail; //primitive map container
	}
    cJSON *localMapObject = cJSON_CreateObject(); //Memory free to be implemented in user code
	listEntry_t *extraListEntry;
    if (v1beta1_certificate_signing_request_spec->extra) {
    list_ForEach(extraListEntry, v1beta1_certificate_signing_request_spec->extra) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)extraListEntry->data;
        if(cJSON_AddNumberToObject(localMapObject, localKeyValue->key, *(double *)localKeyValue->value) == NULL)
        {
            goto fail;
        }
        cJSON_AddItemToObject(extra,"", localMapObject);
    }
    }
     } 


	// v1beta1_certificate_signing_request_spec->groups
    if(v1beta1_certificate_signing_request_spec->groups) { 
	cJSON *groups = cJSON_AddArrayToObject(item, "groups");
	if(groups == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *groupsListEntry;
    list_ForEach(groupsListEntry, v1beta1_certificate_signing_request_spec->groups) {
    if(cJSON_AddStringToObject(groups, "", (char*)groupsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


	// v1beta1_certificate_signing_request_spec->request
    if (!v1beta1_certificate_signing_request_spec->request) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "request", v1beta1_certificate_signing_request_spec->request) == NULL) {
    goto fail; //Byte
    }


	// v1beta1_certificate_signing_request_spec->uid
    if(v1beta1_certificate_signing_request_spec->uid) { 
    if(cJSON_AddStringToObject(item, "uid", v1beta1_certificate_signing_request_spec->uid) == NULL) {
    goto fail; //String
    }
     } 


	// v1beta1_certificate_signing_request_spec->usages
    if(v1beta1_certificate_signing_request_spec->usages) { 
	cJSON *usages = cJSON_AddArrayToObject(item, "usages");
	if(usages == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *usagesListEntry;
    list_ForEach(usagesListEntry, v1beta1_certificate_signing_request_spec->usages) {
    if(cJSON_AddStringToObject(usages, "", (char*)usagesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


	// v1beta1_certificate_signing_request_spec->username
    if(v1beta1_certificate_signing_request_spec->username) { 
    if(cJSON_AddStringToObject(item, "username", v1beta1_certificate_signing_request_spec->username) == NULL) {
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

v1beta1_certificate_signing_request_spec_t *v1beta1_certificate_signing_request_spec_parseFromJSON(cJSON *v1beta1_certificate_signing_request_specJSON){

    v1beta1_certificate_signing_request_spec_t *v1beta1_certificate_signing_request_spec_local_var = NULL;

    // v1beta1_certificate_signing_request_spec->extra
    cJSON *extra = cJSON_GetObjectItemCaseSensitive(v1beta1_certificate_signing_request_specJSON, "extra");
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

    // v1beta1_certificate_signing_request_spec->groups
    cJSON *groups = cJSON_GetObjectItemCaseSensitive(v1beta1_certificate_signing_request_specJSON, "groups");
    list_t *groupsList;
    if (groups) { 
    cJSON *groups_local;
    if(!cJSON_IsArray(groups)) {
        goto end;//primitive container
    }
    groupsList = list_create();

    cJSON_ArrayForEach(groups_local, groups)
    {
        if(!cJSON_IsString(groups_local))
        {
            goto end;
        }
        list_addElement(groupsList , strdup(groups_local->valuestring));
    }
    }

    // v1beta1_certificate_signing_request_spec->request
    cJSON *request = cJSON_GetObjectItemCaseSensitive(v1beta1_certificate_signing_request_specJSON, "request");
    if (!request) {
        goto end;
    }

    
    if(!cJSON_IsNumber(request))
    {
    goto end; //Byte
    }

    // v1beta1_certificate_signing_request_spec->uid
    cJSON *uid = cJSON_GetObjectItemCaseSensitive(v1beta1_certificate_signing_request_specJSON, "uid");
    if (uid) { 
    if(!cJSON_IsString(uid))
    {
    goto end; //String
    }
    }

    // v1beta1_certificate_signing_request_spec->usages
    cJSON *usages = cJSON_GetObjectItemCaseSensitive(v1beta1_certificate_signing_request_specJSON, "usages");
    list_t *usagesList;
    if (usages) { 
    cJSON *usages_local;
    if(!cJSON_IsArray(usages)) {
        goto end;//primitive container
    }
    usagesList = list_create();

    cJSON_ArrayForEach(usages_local, usages)
    {
        if(!cJSON_IsString(usages_local))
        {
            goto end;
        }
        list_addElement(usagesList , strdup(usages_local->valuestring));
    }
    }

    // v1beta1_certificate_signing_request_spec->username
    cJSON *username = cJSON_GetObjectItemCaseSensitive(v1beta1_certificate_signing_request_specJSON, "username");
    if (username) { 
    if(!cJSON_IsString(username))
    {
    goto end; //String
    }
    }


    v1beta1_certificate_signing_request_spec_local_var = v1beta1_certificate_signing_request_spec_create (
        extra ? List : NULL,
        groups ? groupsList : NULL,
        request->valueint,
        uid ? strdup(uid->valuestring) : NULL,
        usages ? usagesList : NULL,
        username ? strdup(username->valuestring) : NULL
        );

    return v1beta1_certificate_signing_request_spec_local_var;
end:
    return NULL;

}
