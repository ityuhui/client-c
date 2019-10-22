#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_rule_with_operations.h"



v1_rule_with_operations_t *v1_rule_with_operations_create(
    list_t *apiGroups,
    list_t *apiVersions,
    list_t *operations,
    list_t *resources,
    char *scope
    ) {
	v1_rule_with_operations_t *v1_rule_with_operations_local_var = malloc(sizeof(v1_rule_with_operations_t));
    if (!v1_rule_with_operations_local_var) {
        return NULL;
    }
	v1_rule_with_operations_local_var->apiGroups = apiGroups;
	v1_rule_with_operations_local_var->apiVersions = apiVersions;
	v1_rule_with_operations_local_var->operations = operations;
	v1_rule_with_operations_local_var->resources = resources;
	v1_rule_with_operations_local_var->scope = scope;

	return v1_rule_with_operations_local_var;
}


void v1_rule_with_operations_free(v1_rule_with_operations_t *v1_rule_with_operations) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, v1_rule_with_operations->apiGroups) {
		free(listEntry->data);
	}
	list_free(v1_rule_with_operations->apiGroups);
	list_ForEach(listEntry, v1_rule_with_operations->apiVersions) {
		free(listEntry->data);
	}
	list_free(v1_rule_with_operations->apiVersions);
	list_ForEach(listEntry, v1_rule_with_operations->operations) {
		free(listEntry->data);
	}
	list_free(v1_rule_with_operations->operations);
	list_ForEach(listEntry, v1_rule_with_operations->resources) {
		free(listEntry->data);
	}
	list_free(v1_rule_with_operations->resources);
    free(v1_rule_with_operations->scope);
	free(v1_rule_with_operations);
}

cJSON *v1_rule_with_operations_convertToJSON(v1_rule_with_operations_t *v1_rule_with_operations) {
	cJSON *item = cJSON_CreateObject();

	// v1_rule_with_operations->apiGroups
    if(v1_rule_with_operations->apiGroups) { 
	cJSON *api_groups = cJSON_AddArrayToObject(item, "apiGroups");
	if(api_groups == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *api_groupsListEntry;
    list_ForEach(api_groupsListEntry, v1_rule_with_operations->apiGroups) {
    if(cJSON_AddStringToObject(api_groups, "", (char*)api_groupsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


	// v1_rule_with_operations->apiVersions
    if(v1_rule_with_operations->apiVersions) { 
	cJSON *api_versions = cJSON_AddArrayToObject(item, "apiVersions");
	if(api_versions == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *api_versionsListEntry;
    list_ForEach(api_versionsListEntry, v1_rule_with_operations->apiVersions) {
    if(cJSON_AddStringToObject(api_versions, "", (char*)api_versionsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


	// v1_rule_with_operations->operations
    if(v1_rule_with_operations->operations) { 
	cJSON *operations = cJSON_AddArrayToObject(item, "operations");
	if(operations == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *operationsListEntry;
    list_ForEach(operationsListEntry, v1_rule_with_operations->operations) {
    if(cJSON_AddStringToObject(operations, "", (char*)operationsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


	// v1_rule_with_operations->resources
    if(v1_rule_with_operations->resources) { 
	cJSON *resources = cJSON_AddArrayToObject(item, "resources");
	if(resources == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *resourcesListEntry;
    list_ForEach(resourcesListEntry, v1_rule_with_operations->resources) {
    if(cJSON_AddStringToObject(resources, "", (char*)resourcesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


	// v1_rule_with_operations->scope
    if(v1_rule_with_operations->scope) { 
    if(cJSON_AddStringToObject(item, "scope", v1_rule_with_operations->scope) == NULL) {
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

v1_rule_with_operations_t *v1_rule_with_operations_parseFromJSON(cJSON *v1_rule_with_operationsJSON){

    v1_rule_with_operations_t *v1_rule_with_operations_local_var = NULL;

    // v1_rule_with_operations->apiGroups
    cJSON *apiGroups = cJSON_GetObjectItemCaseSensitive(v1_rule_with_operationsJSON, "apiGroups");
    list_t *api_groupsList;
    if (apiGroups) { 
    cJSON *api_groups_local;
    if(!cJSON_IsArray(apiGroups)) {
        goto end;//primitive container
    }
    api_groupsList = list_create();

    cJSON_ArrayForEach(api_groups_local, apiGroups)
    {
        if(!cJSON_IsString(api_groups_local))
        {
            goto end;
        }
        list_addElement(api_groupsList , strdup(api_groups_local->valuestring));
    }
    }

    // v1_rule_with_operations->apiVersions
    cJSON *apiVersions = cJSON_GetObjectItemCaseSensitive(v1_rule_with_operationsJSON, "apiVersions");
    list_t *api_versionsList;
    if (apiVersions) { 
    cJSON *api_versions_local;
    if(!cJSON_IsArray(apiVersions)) {
        goto end;//primitive container
    }
    api_versionsList = list_create();

    cJSON_ArrayForEach(api_versions_local, apiVersions)
    {
        if(!cJSON_IsString(api_versions_local))
        {
            goto end;
        }
        list_addElement(api_versionsList , strdup(api_versions_local->valuestring));
    }
    }

    // v1_rule_with_operations->operations
    cJSON *operations = cJSON_GetObjectItemCaseSensitive(v1_rule_with_operationsJSON, "operations");
    list_t *operationsList;
    if (operations) { 
    cJSON *operations_local;
    if(!cJSON_IsArray(operations)) {
        goto end;//primitive container
    }
    operationsList = list_create();

    cJSON_ArrayForEach(operations_local, operations)
    {
        if(!cJSON_IsString(operations_local))
        {
            goto end;
        }
        list_addElement(operationsList , strdup(operations_local->valuestring));
    }
    }

    // v1_rule_with_operations->resources
    cJSON *resources = cJSON_GetObjectItemCaseSensitive(v1_rule_with_operationsJSON, "resources");
    list_t *resourcesList;
    if (resources) { 
    cJSON *resources_local;
    if(!cJSON_IsArray(resources)) {
        goto end;//primitive container
    }
    resourcesList = list_create();

    cJSON_ArrayForEach(resources_local, resources)
    {
        if(!cJSON_IsString(resources_local))
        {
            goto end;
        }
        list_addElement(resourcesList , strdup(resources_local->valuestring));
    }
    }

    // v1_rule_with_operations->scope
    cJSON *scope = cJSON_GetObjectItemCaseSensitive(v1_rule_with_operationsJSON, "scope");
    if (scope) { 
    if(!cJSON_IsString(scope))
    {
    goto end; //String
    }
    }


    v1_rule_with_operations_local_var = v1_rule_with_operations_create (
        apiGroups ? api_groupsList : NULL,
        apiVersions ? api_versionsList : NULL,
        operations ? operationsList : NULL,
        resources ? resourcesList : NULL,
        scope ? strdup(scope->valuestring) : NULL
        );

    return v1_rule_with_operations_local_var;
end:
    return NULL;

}
