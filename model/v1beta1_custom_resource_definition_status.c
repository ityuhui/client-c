#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_custom_resource_definition_status.h"



v1beta1_custom_resource_definition_status_t *v1beta1_custom_resource_definition_status_create(
    v1beta1_custom_resource_definition_names_t *acceptedNames,
    list_t *conditions,
    list_t *storedVersions
    ) {
	v1beta1_custom_resource_definition_status_t *v1beta1_custom_resource_definition_status_local_var = malloc(sizeof(v1beta1_custom_resource_definition_status_t));
    if (!v1beta1_custom_resource_definition_status_local_var) {
        return NULL;
    }
	v1beta1_custom_resource_definition_status_local_var->acceptedNames = acceptedNames;
	v1beta1_custom_resource_definition_status_local_var->conditions = conditions;
	v1beta1_custom_resource_definition_status_local_var->storedVersions = storedVersions;

	return v1beta1_custom_resource_definition_status_local_var;
}


void v1beta1_custom_resource_definition_status_free(v1beta1_custom_resource_definition_status_t *v1beta1_custom_resource_definition_status) {
    listEntry_t *listEntry;
    v1beta1_custom_resource_definition_names_free(v1beta1_custom_resource_definition_status->acceptedNames);
	list_ForEach(listEntry, v1beta1_custom_resource_definition_status->conditions) {
		v1beta1_custom_resource_definition_condition_free(listEntry->data);
	}
	list_free(v1beta1_custom_resource_definition_status->conditions);
	list_ForEach(listEntry, v1beta1_custom_resource_definition_status->storedVersions) {
		free(listEntry->data);
	}
	list_free(v1beta1_custom_resource_definition_status->storedVersions);
	free(v1beta1_custom_resource_definition_status);
}

cJSON *v1beta1_custom_resource_definition_status_convertToJSON(v1beta1_custom_resource_definition_status_t *v1beta1_custom_resource_definition_status) {
	cJSON *item = cJSON_CreateObject();

	// v1beta1_custom_resource_definition_status->acceptedNames
    if (!v1beta1_custom_resource_definition_status->acceptedNames) {
        goto fail;
    }
    
    cJSON *acceptedNames_local_JSON = v1beta1_custom_resource_definition_names_convertToJSON(v1beta1_custom_resource_definition_status->acceptedNames);
    if(acceptedNames_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "acceptedNames", acceptedNames_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


	// v1beta1_custom_resource_definition_status->conditions
    if(v1beta1_custom_resource_definition_status->conditions) { 
    cJSON *conditions = cJSON_AddArrayToObject(item, "conditions");
    if(conditions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *conditionsListEntry;
    if (v1beta1_custom_resource_definition_status->conditions) {
    list_ForEach(conditionsListEntry, v1beta1_custom_resource_definition_status->conditions) {
    cJSON *itemLocal = v1beta1_custom_resource_definition_condition_convertToJSON(conditionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(conditions, itemLocal);
    }
    }
     } 


	// v1beta1_custom_resource_definition_status->storedVersions
    if (!v1beta1_custom_resource_definition_status->storedVersions) {
        goto fail;
    }
    
	cJSON *stored_versions = cJSON_AddArrayToObject(item, "storedVersions");
	if(stored_versions == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *stored_versionsListEntry;
    list_ForEach(stored_versionsListEntry, v1beta1_custom_resource_definition_status->storedVersions) {
    if(cJSON_AddStringToObject(stored_versions, "", (char*)stored_versionsListEntry->data) == NULL)
    {
        goto fail;
    }
    }

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1beta1_custom_resource_definition_status_t *v1beta1_custom_resource_definition_status_parseFromJSON(cJSON *v1beta1_custom_resource_definition_statusJSON){

    v1beta1_custom_resource_definition_status_t *v1beta1_custom_resource_definition_status_local_var = NULL;

    // v1beta1_custom_resource_definition_status->acceptedNames
    cJSON *acceptedNames = cJSON_GetObjectItemCaseSensitive(v1beta1_custom_resource_definition_statusJSON, "acceptedNames");
    if (!acceptedNames) {
        goto end;
    }

    v1beta1_custom_resource_definition_names_t *acceptedNames_local_nonprim = NULL;
    
    acceptedNames_local_nonprim = v1beta1_custom_resource_definition_names_parseFromJSON(acceptedNames); //nonprimitive

    // v1beta1_custom_resource_definition_status->conditions
    cJSON *conditions = cJSON_GetObjectItemCaseSensitive(v1beta1_custom_resource_definition_statusJSON, "conditions");
    list_t *conditionsList;
    if (conditions) { 
    cJSON *conditions_local_nonprimitive;
    if(!cJSON_IsArray(conditions)){
        goto end; //nonprimitive container
    }

    conditionsList = list_create();

    cJSON_ArrayForEach(conditions_local_nonprimitive,conditions )
    {
        if(!cJSON_IsObject(conditions_local_nonprimitive)){
            goto end;
        }
        v1beta1_custom_resource_definition_condition_t *conditionsItem = v1beta1_custom_resource_definition_condition_parseFromJSON(conditions_local_nonprimitive);

        list_addElement(conditionsList, conditionsItem);
    }
    }

    // v1beta1_custom_resource_definition_status->storedVersions
    cJSON *storedVersions = cJSON_GetObjectItemCaseSensitive(v1beta1_custom_resource_definition_statusJSON, "storedVersions");
    if (!storedVersions) {
        goto end;
    }

    list_t *stored_versionsList;
    
    cJSON *stored_versions_local;
    if(!cJSON_IsArray(storedVersions)) {
        goto end;//primitive container
    }
    stored_versionsList = list_create();

    cJSON_ArrayForEach(stored_versions_local, storedVersions)
    {
        if(!cJSON_IsString(stored_versions_local))
        {
            goto end;
        }
        list_addElement(stored_versionsList , strdup(stored_versions_local->valuestring));
    }


    v1beta1_custom_resource_definition_status_local_var = v1beta1_custom_resource_definition_status_create (
        acceptedNames_local_nonprim,
        conditions ? conditionsList : NULL,
        stored_versionsList
        );

    return v1beta1_custom_resource_definition_status_local_var;
end:
    return NULL;

}
