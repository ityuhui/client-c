#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_resource_rule.h"



v1beta1_resource_rule_t *v1beta1_resource_rule_create(
    list_t *apiGroups,
    list_t *resourceNames,
    list_t *resources,
    list_t *verbs
    ) {
	v1beta1_resource_rule_t *v1beta1_resource_rule_local_var = malloc(sizeof(v1beta1_resource_rule_t));
    if (!v1beta1_resource_rule_local_var) {
        return NULL;
    }
	v1beta1_resource_rule_local_var->apiGroups = apiGroups;
	v1beta1_resource_rule_local_var->resourceNames = resourceNames;
	v1beta1_resource_rule_local_var->resources = resources;
	v1beta1_resource_rule_local_var->verbs = verbs;

	return v1beta1_resource_rule_local_var;
}


void v1beta1_resource_rule_free(v1beta1_resource_rule_t *v1beta1_resource_rule) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, v1beta1_resource_rule->apiGroups) {
		free(listEntry->data);
	}
	list_free(v1beta1_resource_rule->apiGroups);
	list_ForEach(listEntry, v1beta1_resource_rule->resourceNames) {
		free(listEntry->data);
	}
	list_free(v1beta1_resource_rule->resourceNames);
	list_ForEach(listEntry, v1beta1_resource_rule->resources) {
		free(listEntry->data);
	}
	list_free(v1beta1_resource_rule->resources);
	list_ForEach(listEntry, v1beta1_resource_rule->verbs) {
		free(listEntry->data);
	}
	list_free(v1beta1_resource_rule->verbs);
	free(v1beta1_resource_rule);
}

cJSON *v1beta1_resource_rule_convertToJSON(v1beta1_resource_rule_t *v1beta1_resource_rule) {
	cJSON *item = cJSON_CreateObject();

	// v1beta1_resource_rule->apiGroups
    if(v1beta1_resource_rule->apiGroups) { 
	cJSON *api_groups = cJSON_AddArrayToObject(item, "apiGroups");
	if(api_groups == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *api_groupsListEntry;
    list_ForEach(api_groupsListEntry, v1beta1_resource_rule->apiGroups) {
    if(cJSON_AddStringToObject(api_groups, "", (char*)api_groupsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


	// v1beta1_resource_rule->resourceNames
    if(v1beta1_resource_rule->resourceNames) { 
	cJSON *resource_names = cJSON_AddArrayToObject(item, "resourceNames");
	if(resource_names == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *resource_namesListEntry;
    list_ForEach(resource_namesListEntry, v1beta1_resource_rule->resourceNames) {
    if(cJSON_AddStringToObject(resource_names, "", (char*)resource_namesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


	// v1beta1_resource_rule->resources
    if(v1beta1_resource_rule->resources) { 
	cJSON *resources = cJSON_AddArrayToObject(item, "resources");
	if(resources == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *resourcesListEntry;
    list_ForEach(resourcesListEntry, v1beta1_resource_rule->resources) {
    if(cJSON_AddStringToObject(resources, "", (char*)resourcesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


	// v1beta1_resource_rule->verbs
    if (!v1beta1_resource_rule->verbs) {
        goto fail;
    }
    
	cJSON *verbs = cJSON_AddArrayToObject(item, "verbs");
	if(verbs == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *verbsListEntry;
    list_ForEach(verbsListEntry, v1beta1_resource_rule->verbs) {
    if(cJSON_AddStringToObject(verbs, "", (char*)verbsListEntry->data) == NULL)
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

v1beta1_resource_rule_t *v1beta1_resource_rule_parseFromJSON(cJSON *v1beta1_resource_ruleJSON){

    v1beta1_resource_rule_t *v1beta1_resource_rule_local_var = NULL;

    // v1beta1_resource_rule->apiGroups
    cJSON *apiGroups = cJSON_GetObjectItemCaseSensitive(v1beta1_resource_ruleJSON, "apiGroups");
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

    // v1beta1_resource_rule->resourceNames
    cJSON *resourceNames = cJSON_GetObjectItemCaseSensitive(v1beta1_resource_ruleJSON, "resourceNames");
    list_t *resource_namesList;
    if (resourceNames) { 
    cJSON *resource_names_local;
    if(!cJSON_IsArray(resourceNames)) {
        goto end;//primitive container
    }
    resource_namesList = list_create();

    cJSON_ArrayForEach(resource_names_local, resourceNames)
    {
        if(!cJSON_IsString(resource_names_local))
        {
            goto end;
        }
        list_addElement(resource_namesList , strdup(resource_names_local->valuestring));
    }
    }

    // v1beta1_resource_rule->resources
    cJSON *resources = cJSON_GetObjectItemCaseSensitive(v1beta1_resource_ruleJSON, "resources");
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

    // v1beta1_resource_rule->verbs
    cJSON *verbs = cJSON_GetObjectItemCaseSensitive(v1beta1_resource_ruleJSON, "verbs");
    if (!verbs) {
        goto end;
    }

    list_t *verbsList;
    
    cJSON *verbs_local;
    if(!cJSON_IsArray(verbs)) {
        goto end;//primitive container
    }
    verbsList = list_create();

    cJSON_ArrayForEach(verbs_local, verbs)
    {
        if(!cJSON_IsString(verbs_local))
        {
            goto end;
        }
        list_addElement(verbsList , strdup(verbs_local->valuestring));
    }


    v1beta1_resource_rule_local_var = v1beta1_resource_rule_create (
        apiGroups ? api_groupsList : NULL,
        resourceNames ? resource_namesList : NULL,
        resources ? resourcesList : NULL,
        verbsList
        );

    return v1beta1_resource_rule_local_var;
end:
    return NULL;

}
