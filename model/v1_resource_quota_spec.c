#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_resource_quota_spec.h"



v1_resource_quota_spec_t *v1_resource_quota_spec_create(
    list_t* hard,
    v1_scope_selector_t *scopeSelector,
    list_t *scopes
    ) {
	v1_resource_quota_spec_t *v1_resource_quota_spec_local_var = malloc(sizeof(v1_resource_quota_spec_t));
    if (!v1_resource_quota_spec_local_var) {
        return NULL;
    }
	v1_resource_quota_spec_local_var->hard = hard;
	v1_resource_quota_spec_local_var->scopeSelector = scopeSelector;
	v1_resource_quota_spec_local_var->scopes = scopes;

	return v1_resource_quota_spec_local_var;
}


void v1_resource_quota_spec_free(v1_resource_quota_spec_t *v1_resource_quota_spec) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, v1_resource_quota_spec->hard) {
		keyValuePair_t *localMapKeyPair = (keyValuePair_t*) listEntry->data;
        free (localKeyValue->key);
        free (localKeyValue->value);
	}
	list_free(v1_resource_quota_spec->hard);
    v1_scope_selector_free(v1_resource_quota_spec->scopeSelector);
	list_ForEach(listEntry, v1_resource_quota_spec->scopes) {
		free(listEntry->data);
	}
	list_free(v1_resource_quota_spec->scopes);
	free(v1_resource_quota_spec);
}

cJSON *v1_resource_quota_spec_convertToJSON(v1_resource_quota_spec_t *v1_resource_quota_spec) {
	cJSON *item = cJSON_CreateObject();

	// v1_resource_quota_spec->hard
    if(v1_resource_quota_spec->hard) { 
	cJSON *hard = cJSON_AddObjectToObject(item, "hard");
	if(hard == NULL) {
		goto fail; //primitive map container
	}
    cJSON *localMapObject = cJSON_CreateObject(); //Memory free to be implemented in user code
	listEntry_t *hardListEntry;
    if (v1_resource_quota_spec->hard) {
    list_ForEach(hardListEntry, v1_resource_quota_spec->hard) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)hardListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
        cJSON_AddItemToObject(hard,"", localMapObject);
    }
    }
     } 


	// v1_resource_quota_spec->scopeSelector
    if(v1_resource_quota_spec->scopeSelector) { 
    cJSON *scopeSelector_local_JSON = v1_scope_selector_convertToJSON(v1_resource_quota_spec->scopeSelector);
    if(scopeSelector_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "scopeSelector", scopeSelector_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_resource_quota_spec->scopes
    if(v1_resource_quota_spec->scopes) { 
	cJSON *scopes = cJSON_AddArrayToObject(item, "scopes");
	if(scopes == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *scopesListEntry;
    list_ForEach(scopesListEntry, v1_resource_quota_spec->scopes) {
    if(cJSON_AddStringToObject(scopes, "", (char*)scopesListEntry->data) == NULL)
    {
        goto fail;
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

v1_resource_quota_spec_t *v1_resource_quota_spec_parseFromJSON(cJSON *v1_resource_quota_specJSON){

    v1_resource_quota_spec_t *v1_resource_quota_spec_local_var = NULL;

    // v1_resource_quota_spec->hard
    cJSON *hard = cJSON_GetObjectItemCaseSensitive(v1_resource_quota_specJSON, "hard");
    list_t *List;
    if (hard) { 
    cJSON *_local_map;
    if(!cJSON_IsObject(hard)) {
        goto end;//primitive map container
    }
    List = list_create();
    keyValuePair_t *localMapKeyPair;
    cJSON_ArrayForEach(_local_map, hard)
    {
        if(!cJSON_IsNumber(_local_map))
        {
            goto end;
        }
        localMapKeyPair = keyValuePair_create(strdup(_local_map->string),&_local_map->valuedouble );
        list_addElement(List , localMapKeyPair);
    }
    }

    // v1_resource_quota_spec->scopeSelector
    cJSON *scopeSelector = cJSON_GetObjectItemCaseSensitive(v1_resource_quota_specJSON, "scopeSelector");
    v1_scope_selector_t *scopeSelector_local_nonprim = NULL;
    if (scopeSelector) { 
    scopeSelector_local_nonprim = v1_scope_selector_parseFromJSON(scopeSelector); //nonprimitive
    }

    // v1_resource_quota_spec->scopes
    cJSON *scopes = cJSON_GetObjectItemCaseSensitive(v1_resource_quota_specJSON, "scopes");
    list_t *scopesList;
    if (scopes) { 
    cJSON *scopes_local;
    if(!cJSON_IsArray(scopes)) {
        goto end;//primitive container
    }
    scopesList = list_create();

    cJSON_ArrayForEach(scopes_local, scopes)
    {
        if(!cJSON_IsString(scopes_local))
        {
            goto end;
        }
        list_addElement(scopesList , strdup(scopes_local->valuestring));
    }
    }


    v1_resource_quota_spec_local_var = v1_resource_quota_spec_create (
        hard ? List : NULL,
        scopeSelector ? scopeSelector_local_nonprim : NULL,
        scopes ? scopesList : NULL
        );

    return v1_resource_quota_spec_local_var;
end:
    return NULL;

}
