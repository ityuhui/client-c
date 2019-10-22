#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_custom_resource_definition_version.h"



v1_custom_resource_definition_version_t *v1_custom_resource_definition_version_create(
    list_t *additionalPrinterColumns,
    char *name,
    v1_custom_resource_validation_t *schema,
    int served,
    int storage,
    v1_custom_resource_subresources_t *subresources
    ) {
	v1_custom_resource_definition_version_t *v1_custom_resource_definition_version_local_var = malloc(sizeof(v1_custom_resource_definition_version_t));
    if (!v1_custom_resource_definition_version_local_var) {
        return NULL;
    }
	v1_custom_resource_definition_version_local_var->additionalPrinterColumns = additionalPrinterColumns;
	v1_custom_resource_definition_version_local_var->name = name;
	v1_custom_resource_definition_version_local_var->schema = schema;
	v1_custom_resource_definition_version_local_var->served = served;
	v1_custom_resource_definition_version_local_var->storage = storage;
	v1_custom_resource_definition_version_local_var->subresources = subresources;

	return v1_custom_resource_definition_version_local_var;
}


void v1_custom_resource_definition_version_free(v1_custom_resource_definition_version_t *v1_custom_resource_definition_version) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, v1_custom_resource_definition_version->additionalPrinterColumns) {
		v1_custom_resource_column_definition_free(listEntry->data);
	}
	list_free(v1_custom_resource_definition_version->additionalPrinterColumns);
    free(v1_custom_resource_definition_version->name);
    v1_custom_resource_validation_free(v1_custom_resource_definition_version->schema);
    v1_custom_resource_subresources_free(v1_custom_resource_definition_version->subresources);
	free(v1_custom_resource_definition_version);
}

cJSON *v1_custom_resource_definition_version_convertToJSON(v1_custom_resource_definition_version_t *v1_custom_resource_definition_version) {
	cJSON *item = cJSON_CreateObject();

	// v1_custom_resource_definition_version->additionalPrinterColumns
    if(v1_custom_resource_definition_version->additionalPrinterColumns) { 
    cJSON *additionalPrinterColumns = cJSON_AddArrayToObject(item, "additionalPrinterColumns");
    if(additionalPrinterColumns == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *additionalPrinterColumnsListEntry;
    if (v1_custom_resource_definition_version->additionalPrinterColumns) {
    list_ForEach(additionalPrinterColumnsListEntry, v1_custom_resource_definition_version->additionalPrinterColumns) {
    cJSON *itemLocal = v1_custom_resource_column_definition_convertToJSON(additionalPrinterColumnsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(additionalPrinterColumns, itemLocal);
    }
    }
     } 


	// v1_custom_resource_definition_version->name
    if (!v1_custom_resource_definition_version->name) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "name", v1_custom_resource_definition_version->name) == NULL) {
    goto fail; //String
    }


	// v1_custom_resource_definition_version->schema
    if(v1_custom_resource_definition_version->schema) { 
    cJSON *schema_local_JSON = v1_custom_resource_validation_convertToJSON(v1_custom_resource_definition_version->schema);
    if(schema_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "schema", schema_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_custom_resource_definition_version->served
    if (!v1_custom_resource_definition_version->served) {
        goto fail;
    }
    
    if(cJSON_AddBoolToObject(item, "served", v1_custom_resource_definition_version->served) == NULL) {
    goto fail; //Bool
    }


	// v1_custom_resource_definition_version->storage
    if (!v1_custom_resource_definition_version->storage) {
        goto fail;
    }
    
    if(cJSON_AddBoolToObject(item, "storage", v1_custom_resource_definition_version->storage) == NULL) {
    goto fail; //Bool
    }


	// v1_custom_resource_definition_version->subresources
    if(v1_custom_resource_definition_version->subresources) { 
    cJSON *subresources_local_JSON = v1_custom_resource_subresources_convertToJSON(v1_custom_resource_definition_version->subresources);
    if(subresources_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "subresources", subresources_local_JSON);
    if(item->child == NULL) {
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

v1_custom_resource_definition_version_t *v1_custom_resource_definition_version_parseFromJSON(cJSON *v1_custom_resource_definition_versionJSON){

    v1_custom_resource_definition_version_t *v1_custom_resource_definition_version_local_var = NULL;

    // v1_custom_resource_definition_version->additionalPrinterColumns
    cJSON *additionalPrinterColumns = cJSON_GetObjectItemCaseSensitive(v1_custom_resource_definition_versionJSON, "additionalPrinterColumns");
    list_t *additionalPrinterColumnsList;
    if (additionalPrinterColumns) { 
    cJSON *additionalPrinterColumns_local_nonprimitive;
    if(!cJSON_IsArray(additionalPrinterColumns)){
        goto end; //nonprimitive container
    }

    additionalPrinterColumnsList = list_create();

    cJSON_ArrayForEach(additionalPrinterColumns_local_nonprimitive,additionalPrinterColumns )
    {
        if(!cJSON_IsObject(additionalPrinterColumns_local_nonprimitive)){
            goto end;
        }
        v1_custom_resource_column_definition_t *additionalPrinterColumnsItem = v1_custom_resource_column_definition_parseFromJSON(additionalPrinterColumns_local_nonprimitive);

        list_addElement(additionalPrinterColumnsList, additionalPrinterColumnsItem);
    }
    }

    // v1_custom_resource_definition_version->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_custom_resource_definition_versionJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // v1_custom_resource_definition_version->schema
    cJSON *schema = cJSON_GetObjectItemCaseSensitive(v1_custom_resource_definition_versionJSON, "schema");
    v1_custom_resource_validation_t *schema_local_nonprim = NULL;
    if (schema) { 
    schema_local_nonprim = v1_custom_resource_validation_parseFromJSON(schema); //nonprimitive
    }

    // v1_custom_resource_definition_version->served
    cJSON *served = cJSON_GetObjectItemCaseSensitive(v1_custom_resource_definition_versionJSON, "served");
    if (!served) {
        goto end;
    }

    
    if(!cJSON_IsBool(served))
    {
    goto end; //Bool
    }

    // v1_custom_resource_definition_version->storage
    cJSON *storage = cJSON_GetObjectItemCaseSensitive(v1_custom_resource_definition_versionJSON, "storage");
    if (!storage) {
        goto end;
    }

    
    if(!cJSON_IsBool(storage))
    {
    goto end; //Bool
    }

    // v1_custom_resource_definition_version->subresources
    cJSON *subresources = cJSON_GetObjectItemCaseSensitive(v1_custom_resource_definition_versionJSON, "subresources");
    v1_custom_resource_subresources_t *subresources_local_nonprim = NULL;
    if (subresources) { 
    subresources_local_nonprim = v1_custom_resource_subresources_parseFromJSON(subresources); //nonprimitive
    }


    v1_custom_resource_definition_version_local_var = v1_custom_resource_definition_version_create (
        additionalPrinterColumns ? additionalPrinterColumnsList : NULL,
        strdup(name->valuestring),
        schema ? schema_local_nonprim : NULL,
        served->valueint,
        storage->valueint,
        subresources ? subresources_local_nonprim : NULL
        );

    return v1_custom_resource_definition_version_local_var;
end:
    return NULL;

}
