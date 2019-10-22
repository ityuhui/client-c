#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_custom_resource_definition_names.h"



v1_custom_resource_definition_names_t *v1_custom_resource_definition_names_create(
    list_t *categories,
    char *kind,
    char *listKind,
    char *plural,
    list_t *shortNames,
    char *singular
    ) {
	v1_custom_resource_definition_names_t *v1_custom_resource_definition_names_local_var = malloc(sizeof(v1_custom_resource_definition_names_t));
    if (!v1_custom_resource_definition_names_local_var) {
        return NULL;
    }
	v1_custom_resource_definition_names_local_var->categories = categories;
	v1_custom_resource_definition_names_local_var->kind = kind;
	v1_custom_resource_definition_names_local_var->listKind = listKind;
	v1_custom_resource_definition_names_local_var->plural = plural;
	v1_custom_resource_definition_names_local_var->shortNames = shortNames;
	v1_custom_resource_definition_names_local_var->singular = singular;

	return v1_custom_resource_definition_names_local_var;
}


void v1_custom_resource_definition_names_free(v1_custom_resource_definition_names_t *v1_custom_resource_definition_names) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, v1_custom_resource_definition_names->categories) {
		free(listEntry->data);
	}
	list_free(v1_custom_resource_definition_names->categories);
    free(v1_custom_resource_definition_names->kind);
    free(v1_custom_resource_definition_names->listKind);
    free(v1_custom_resource_definition_names->plural);
	list_ForEach(listEntry, v1_custom_resource_definition_names->shortNames) {
		free(listEntry->data);
	}
	list_free(v1_custom_resource_definition_names->shortNames);
    free(v1_custom_resource_definition_names->singular);
	free(v1_custom_resource_definition_names);
}

cJSON *v1_custom_resource_definition_names_convertToJSON(v1_custom_resource_definition_names_t *v1_custom_resource_definition_names) {
	cJSON *item = cJSON_CreateObject();

	// v1_custom_resource_definition_names->categories
    if(v1_custom_resource_definition_names->categories) { 
	cJSON *categories = cJSON_AddArrayToObject(item, "categories");
	if(categories == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *categoriesListEntry;
    list_ForEach(categoriesListEntry, v1_custom_resource_definition_names->categories) {
    if(cJSON_AddStringToObject(categories, "", (char*)categoriesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


	// v1_custom_resource_definition_names->kind
    if (!v1_custom_resource_definition_names->kind) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "kind", v1_custom_resource_definition_names->kind) == NULL) {
    goto fail; //String
    }


	// v1_custom_resource_definition_names->listKind
    if(v1_custom_resource_definition_names->listKind) { 
    if(cJSON_AddStringToObject(item, "listKind", v1_custom_resource_definition_names->listKind) == NULL) {
    goto fail; //String
    }
     } 


	// v1_custom_resource_definition_names->plural
    if (!v1_custom_resource_definition_names->plural) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "plural", v1_custom_resource_definition_names->plural) == NULL) {
    goto fail; //String
    }


	// v1_custom_resource_definition_names->shortNames
    if(v1_custom_resource_definition_names->shortNames) { 
	cJSON *short_names = cJSON_AddArrayToObject(item, "shortNames");
	if(short_names == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *short_namesListEntry;
    list_ForEach(short_namesListEntry, v1_custom_resource_definition_names->shortNames) {
    if(cJSON_AddStringToObject(short_names, "", (char*)short_namesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


	// v1_custom_resource_definition_names->singular
    if(v1_custom_resource_definition_names->singular) { 
    if(cJSON_AddStringToObject(item, "singular", v1_custom_resource_definition_names->singular) == NULL) {
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

v1_custom_resource_definition_names_t *v1_custom_resource_definition_names_parseFromJSON(cJSON *v1_custom_resource_definition_namesJSON){

    v1_custom_resource_definition_names_t *v1_custom_resource_definition_names_local_var = NULL;

    // v1_custom_resource_definition_names->categories
    cJSON *categories = cJSON_GetObjectItemCaseSensitive(v1_custom_resource_definition_namesJSON, "categories");
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

    // v1_custom_resource_definition_names->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_custom_resource_definition_namesJSON, "kind");
    if (!kind) {
        goto end;
    }

    
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }

    // v1_custom_resource_definition_names->listKind
    cJSON *listKind = cJSON_GetObjectItemCaseSensitive(v1_custom_resource_definition_namesJSON, "listKind");
    if (listKind) { 
    if(!cJSON_IsString(listKind))
    {
    goto end; //String
    }
    }

    // v1_custom_resource_definition_names->plural
    cJSON *plural = cJSON_GetObjectItemCaseSensitive(v1_custom_resource_definition_namesJSON, "plural");
    if (!plural) {
        goto end;
    }

    
    if(!cJSON_IsString(plural))
    {
    goto end; //String
    }

    // v1_custom_resource_definition_names->shortNames
    cJSON *shortNames = cJSON_GetObjectItemCaseSensitive(v1_custom_resource_definition_namesJSON, "shortNames");
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

    // v1_custom_resource_definition_names->singular
    cJSON *singular = cJSON_GetObjectItemCaseSensitive(v1_custom_resource_definition_namesJSON, "singular");
    if (singular) { 
    if(!cJSON_IsString(singular))
    {
    goto end; //String
    }
    }


    v1_custom_resource_definition_names_local_var = v1_custom_resource_definition_names_create (
        categories ? categoriesList : NULL,
        strdup(kind->valuestring),
        listKind ? strdup(listKind->valuestring) : NULL,
        strdup(plural->valuestring),
        shortNames ? short_namesList : NULL,
        singular ? strdup(singular->valuestring) : NULL
        );

    return v1_custom_resource_definition_names_local_var;
end:
    return NULL;

}
