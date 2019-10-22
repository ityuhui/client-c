#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_api_resource.h"



v1_api_resource_t *v1_api_resource_create(
    list_t *categories,
    char *group,
    char *kind,
    char *name,
    int namespaced,
    list_t *shortNames,
    char *singularName,
    char *storageVersionHash,
    list_t *verbs,
    char *version
    ) {
	v1_api_resource_t *v1_api_resource_local_var = malloc(sizeof(v1_api_resource_t));
    if (!v1_api_resource_local_var) {
        return NULL;
    }
	v1_api_resource_local_var->categories = categories;
	v1_api_resource_local_var->group = group;
	v1_api_resource_local_var->kind = kind;
	v1_api_resource_local_var->name = name;
	v1_api_resource_local_var->namespaced = namespaced;
	v1_api_resource_local_var->shortNames = shortNames;
	v1_api_resource_local_var->singularName = singularName;
	v1_api_resource_local_var->storageVersionHash = storageVersionHash;
	v1_api_resource_local_var->verbs = verbs;
	v1_api_resource_local_var->version = version;

	return v1_api_resource_local_var;
}


void v1_api_resource_free(v1_api_resource_t *v1_api_resource) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, v1_api_resource->categories) {
		free(listEntry->data);
	}
	list_free(v1_api_resource->categories);
    free(v1_api_resource->group);
    free(v1_api_resource->kind);
    free(v1_api_resource->name);
	list_ForEach(listEntry, v1_api_resource->shortNames) {
		free(listEntry->data);
	}
	list_free(v1_api_resource->shortNames);
    free(v1_api_resource->singularName);
    free(v1_api_resource->storageVersionHash);
	list_ForEach(listEntry, v1_api_resource->verbs) {
		free(listEntry->data);
	}
	list_free(v1_api_resource->verbs);
    free(v1_api_resource->version);
	free(v1_api_resource);
}

cJSON *v1_api_resource_convertToJSON(v1_api_resource_t *v1_api_resource) {
	cJSON *item = cJSON_CreateObject();

	// v1_api_resource->categories
    if(v1_api_resource->categories) { 
	cJSON *categories = cJSON_AddArrayToObject(item, "categories");
	if(categories == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *categoriesListEntry;
    list_ForEach(categoriesListEntry, v1_api_resource->categories) {
    if(cJSON_AddStringToObject(categories, "", (char*)categoriesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


	// v1_api_resource->group
    if(v1_api_resource->group) { 
    if(cJSON_AddStringToObject(item, "group", v1_api_resource->group) == NULL) {
    goto fail; //String
    }
     } 


	// v1_api_resource->kind
    if (!v1_api_resource->kind) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "kind", v1_api_resource->kind) == NULL) {
    goto fail; //String
    }


	// v1_api_resource->name
    if (!v1_api_resource->name) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "name", v1_api_resource->name) == NULL) {
    goto fail; //String
    }


	// v1_api_resource->namespaced
    if (!v1_api_resource->namespaced) {
        goto fail;
    }
    
    if(cJSON_AddBoolToObject(item, "namespaced", v1_api_resource->namespaced) == NULL) {
    goto fail; //Bool
    }


	// v1_api_resource->shortNames
    if(v1_api_resource->shortNames) { 
	cJSON *short_names = cJSON_AddArrayToObject(item, "shortNames");
	if(short_names == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *short_namesListEntry;
    list_ForEach(short_namesListEntry, v1_api_resource->shortNames) {
    if(cJSON_AddStringToObject(short_names, "", (char*)short_namesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


	// v1_api_resource->singularName
    if (!v1_api_resource->singularName) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "singularName", v1_api_resource->singularName) == NULL) {
    goto fail; //String
    }


	// v1_api_resource->storageVersionHash
    if(v1_api_resource->storageVersionHash) { 
    if(cJSON_AddStringToObject(item, "storageVersionHash", v1_api_resource->storageVersionHash) == NULL) {
    goto fail; //String
    }
     } 


	// v1_api_resource->verbs
    if (!v1_api_resource->verbs) {
        goto fail;
    }
    
	cJSON *verbs = cJSON_AddArrayToObject(item, "verbs");
	if(verbs == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *verbsListEntry;
    list_ForEach(verbsListEntry, v1_api_resource->verbs) {
    if(cJSON_AddStringToObject(verbs, "", (char*)verbsListEntry->data) == NULL)
    {
        goto fail;
    }
    }


	// v1_api_resource->version
    if(v1_api_resource->version) { 
    if(cJSON_AddStringToObject(item, "version", v1_api_resource->version) == NULL) {
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

v1_api_resource_t *v1_api_resource_parseFromJSON(cJSON *v1_api_resourceJSON){

    v1_api_resource_t *v1_api_resource_local_var = NULL;

    // v1_api_resource->categories
    cJSON *categories = cJSON_GetObjectItemCaseSensitive(v1_api_resourceJSON, "categories");
    list_t *categoriesList;
    if (categories) { 
    cJSON *categories_local;
    if(!cJSON_IsArray(categories)) {
        goto end;//primitive container
    }
    categoriesList = list_create();

    cJSON_ArrayForEach(categories_local, categories)
    {
        if(!cJSON_IsString(categories_local))
        {
            goto end;
        }
        list_addElement(categoriesList , strdup(categories_local->valuestring));
    }
    }

    // v1_api_resource->group
    cJSON *group = cJSON_GetObjectItemCaseSensitive(v1_api_resourceJSON, "group");
    if (group) { 
    if(!cJSON_IsString(group))
    {
    goto end; //String
    }
    }

    // v1_api_resource->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_api_resourceJSON, "kind");
    if (!kind) {
        goto end;
    }

    
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }

    // v1_api_resource->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_api_resourceJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // v1_api_resource->namespaced
    cJSON *namespaced = cJSON_GetObjectItemCaseSensitive(v1_api_resourceJSON, "namespaced");
    if (!namespaced) {
        goto end;
    }

    
    if(!cJSON_IsBool(namespaced))
    {
    goto end; //Bool
    }

    // v1_api_resource->shortNames
    cJSON *shortNames = cJSON_GetObjectItemCaseSensitive(v1_api_resourceJSON, "shortNames");
    list_t *short_namesList;
    if (shortNames) { 
    cJSON *short_names_local;
    if(!cJSON_IsArray(shortNames)) {
        goto end;//primitive container
    }
    short_namesList = list_create();

    cJSON_ArrayForEach(short_names_local, shortNames)
    {
        if(!cJSON_IsString(short_names_local))
        {
            goto end;
        }
        list_addElement(short_namesList , strdup(short_names_local->valuestring));
    }
    }

    // v1_api_resource->singularName
    cJSON *singularName = cJSON_GetObjectItemCaseSensitive(v1_api_resourceJSON, "singularName");
    if (!singularName) {
        goto end;
    }

    
    if(!cJSON_IsString(singularName))
    {
    goto end; //String
    }

    // v1_api_resource->storageVersionHash
    cJSON *storageVersionHash = cJSON_GetObjectItemCaseSensitive(v1_api_resourceJSON, "storageVersionHash");
    if (storageVersionHash) { 
    if(!cJSON_IsString(storageVersionHash))
    {
    goto end; //String
    }
    }

    // v1_api_resource->verbs
    cJSON *verbs = cJSON_GetObjectItemCaseSensitive(v1_api_resourceJSON, "verbs");
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

    // v1_api_resource->version
    cJSON *version = cJSON_GetObjectItemCaseSensitive(v1_api_resourceJSON, "version");
    if (version) { 
    if(!cJSON_IsString(version))
    {
    goto end; //String
    }
    }


    v1_api_resource_local_var = v1_api_resource_create (
        categories ? categoriesList : NULL,
        group ? strdup(group->valuestring) : NULL,
        strdup(kind->valuestring),
        strdup(name->valuestring),
        namespaced->valueint,
        shortNames ? short_namesList : NULL,
        strdup(singularName->valuestring),
        storageVersionHash ? strdup(storageVersionHash->valuestring) : NULL,
        verbsList,
        version ? strdup(version->valuestring) : NULL
        );

    return v1_api_resource_local_var;
end:
    return NULL;

}
