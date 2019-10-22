#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_custom_resource_definition_spec.h"



v1beta1_custom_resource_definition_spec_t *v1beta1_custom_resource_definition_spec_create(
    list_t *additionalPrinterColumns,
    v1beta1_custom_resource_conversion_t *conversion,
    char *group,
    v1beta1_custom_resource_definition_names_t *names,
    int preserveUnknownFields,
    char *scope,
    v1beta1_custom_resource_subresources_t *subresources,
    v1beta1_custom_resource_validation_t *validation,
    char *version,
    list_t *versions
    ) {
	v1beta1_custom_resource_definition_spec_t *v1beta1_custom_resource_definition_spec_local_var = malloc(sizeof(v1beta1_custom_resource_definition_spec_t));
    if (!v1beta1_custom_resource_definition_spec_local_var) {
        return NULL;
    }
	v1beta1_custom_resource_definition_spec_local_var->additionalPrinterColumns = additionalPrinterColumns;
	v1beta1_custom_resource_definition_spec_local_var->conversion = conversion;
	v1beta1_custom_resource_definition_spec_local_var->group = group;
	v1beta1_custom_resource_definition_spec_local_var->names = names;
	v1beta1_custom_resource_definition_spec_local_var->preserveUnknownFields = preserveUnknownFields;
	v1beta1_custom_resource_definition_spec_local_var->scope = scope;
	v1beta1_custom_resource_definition_spec_local_var->subresources = subresources;
	v1beta1_custom_resource_definition_spec_local_var->validation = validation;
	v1beta1_custom_resource_definition_spec_local_var->version = version;
	v1beta1_custom_resource_definition_spec_local_var->versions = versions;

	return v1beta1_custom_resource_definition_spec_local_var;
}


void v1beta1_custom_resource_definition_spec_free(v1beta1_custom_resource_definition_spec_t *v1beta1_custom_resource_definition_spec) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, v1beta1_custom_resource_definition_spec->additionalPrinterColumns) {
		v1beta1_custom_resource_column_definition_free(listEntry->data);
	}
	list_free(v1beta1_custom_resource_definition_spec->additionalPrinterColumns);
    v1beta1_custom_resource_conversion_free(v1beta1_custom_resource_definition_spec->conversion);
    free(v1beta1_custom_resource_definition_spec->group);
    v1beta1_custom_resource_definition_names_free(v1beta1_custom_resource_definition_spec->names);
    free(v1beta1_custom_resource_definition_spec->scope);
    v1beta1_custom_resource_subresources_free(v1beta1_custom_resource_definition_spec->subresources);
    v1beta1_custom_resource_validation_free(v1beta1_custom_resource_definition_spec->validation);
    free(v1beta1_custom_resource_definition_spec->version);
	list_ForEach(listEntry, v1beta1_custom_resource_definition_spec->versions) {
		v1beta1_custom_resource_definition_version_free(listEntry->data);
	}
	list_free(v1beta1_custom_resource_definition_spec->versions);
	free(v1beta1_custom_resource_definition_spec);
}

cJSON *v1beta1_custom_resource_definition_spec_convertToJSON(v1beta1_custom_resource_definition_spec_t *v1beta1_custom_resource_definition_spec) {
	cJSON *item = cJSON_CreateObject();

	// v1beta1_custom_resource_definition_spec->additionalPrinterColumns
    if(v1beta1_custom_resource_definition_spec->additionalPrinterColumns) { 
    cJSON *additionalPrinterColumns = cJSON_AddArrayToObject(item, "additionalPrinterColumns");
    if(additionalPrinterColumns == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *additionalPrinterColumnsListEntry;
    if (v1beta1_custom_resource_definition_spec->additionalPrinterColumns) {
    list_ForEach(additionalPrinterColumnsListEntry, v1beta1_custom_resource_definition_spec->additionalPrinterColumns) {
    cJSON *itemLocal = v1beta1_custom_resource_column_definition_convertToJSON(additionalPrinterColumnsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(additionalPrinterColumns, itemLocal);
    }
    }
     } 


	// v1beta1_custom_resource_definition_spec->conversion
    if(v1beta1_custom_resource_definition_spec->conversion) { 
    cJSON *conversion_local_JSON = v1beta1_custom_resource_conversion_convertToJSON(v1beta1_custom_resource_definition_spec->conversion);
    if(conversion_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "conversion", conversion_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1beta1_custom_resource_definition_spec->group
    if (!v1beta1_custom_resource_definition_spec->group) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "group", v1beta1_custom_resource_definition_spec->group) == NULL) {
    goto fail; //String
    }


	// v1beta1_custom_resource_definition_spec->names
    if (!v1beta1_custom_resource_definition_spec->names) {
        goto fail;
    }
    
    cJSON *names_local_JSON = v1beta1_custom_resource_definition_names_convertToJSON(v1beta1_custom_resource_definition_spec->names);
    if(names_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "names", names_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


	// v1beta1_custom_resource_definition_spec->preserveUnknownFields
    if(v1beta1_custom_resource_definition_spec->preserveUnknownFields) { 
    if(cJSON_AddBoolToObject(item, "preserveUnknownFields", v1beta1_custom_resource_definition_spec->preserveUnknownFields) == NULL) {
    goto fail; //Bool
    }
     } 


	// v1beta1_custom_resource_definition_spec->scope
    if (!v1beta1_custom_resource_definition_spec->scope) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "scope", v1beta1_custom_resource_definition_spec->scope) == NULL) {
    goto fail; //String
    }


	// v1beta1_custom_resource_definition_spec->subresources
    if(v1beta1_custom_resource_definition_spec->subresources) { 
    cJSON *subresources_local_JSON = v1beta1_custom_resource_subresources_convertToJSON(v1beta1_custom_resource_definition_spec->subresources);
    if(subresources_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "subresources", subresources_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1beta1_custom_resource_definition_spec->validation
    if(v1beta1_custom_resource_definition_spec->validation) { 
    cJSON *validation_local_JSON = v1beta1_custom_resource_validation_convertToJSON(v1beta1_custom_resource_definition_spec->validation);
    if(validation_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "validation", validation_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1beta1_custom_resource_definition_spec->version
    if(v1beta1_custom_resource_definition_spec->version) { 
    if(cJSON_AddStringToObject(item, "version", v1beta1_custom_resource_definition_spec->version) == NULL) {
    goto fail; //String
    }
     } 


	// v1beta1_custom_resource_definition_spec->versions
    if(v1beta1_custom_resource_definition_spec->versions) { 
    cJSON *versions = cJSON_AddArrayToObject(item, "versions");
    if(versions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *versionsListEntry;
    if (v1beta1_custom_resource_definition_spec->versions) {
    list_ForEach(versionsListEntry, v1beta1_custom_resource_definition_spec->versions) {
    cJSON *itemLocal = v1beta1_custom_resource_definition_version_convertToJSON(versionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(versions, itemLocal);
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

v1beta1_custom_resource_definition_spec_t *v1beta1_custom_resource_definition_spec_parseFromJSON(cJSON *v1beta1_custom_resource_definition_specJSON){

    v1beta1_custom_resource_definition_spec_t *v1beta1_custom_resource_definition_spec_local_var = NULL;

    // v1beta1_custom_resource_definition_spec->additionalPrinterColumns
    cJSON *additionalPrinterColumns = cJSON_GetObjectItemCaseSensitive(v1beta1_custom_resource_definition_specJSON, "additionalPrinterColumns");
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
        v1beta1_custom_resource_column_definition_t *additionalPrinterColumnsItem = v1beta1_custom_resource_column_definition_parseFromJSON(additionalPrinterColumns_local_nonprimitive);

        list_addElement(additionalPrinterColumnsList, additionalPrinterColumnsItem);
    }
    }

    // v1beta1_custom_resource_definition_spec->conversion
    cJSON *conversion = cJSON_GetObjectItemCaseSensitive(v1beta1_custom_resource_definition_specJSON, "conversion");
    v1beta1_custom_resource_conversion_t *conversion_local_nonprim = NULL;
    if (conversion) { 
    conversion_local_nonprim = v1beta1_custom_resource_conversion_parseFromJSON(conversion); //nonprimitive
    }

    // v1beta1_custom_resource_definition_spec->group
    cJSON *group = cJSON_GetObjectItemCaseSensitive(v1beta1_custom_resource_definition_specJSON, "group");
    if (!group) {
        goto end;
    }

    
    if(!cJSON_IsString(group))
    {
    goto end; //String
    }

    // v1beta1_custom_resource_definition_spec->names
    cJSON *names = cJSON_GetObjectItemCaseSensitive(v1beta1_custom_resource_definition_specJSON, "names");
    if (!names) {
        goto end;
    }

    v1beta1_custom_resource_definition_names_t *names_local_nonprim = NULL;
    
    names_local_nonprim = v1beta1_custom_resource_definition_names_parseFromJSON(names); //nonprimitive

    // v1beta1_custom_resource_definition_spec->preserveUnknownFields
    cJSON *preserveUnknownFields = cJSON_GetObjectItemCaseSensitive(v1beta1_custom_resource_definition_specJSON, "preserveUnknownFields");
    if (preserveUnknownFields) { 
    if(!cJSON_IsBool(preserveUnknownFields))
    {
    goto end; //Bool
    }
    }

    // v1beta1_custom_resource_definition_spec->scope
    cJSON *scope = cJSON_GetObjectItemCaseSensitive(v1beta1_custom_resource_definition_specJSON, "scope");
    if (!scope) {
        goto end;
    }

    
    if(!cJSON_IsString(scope))
    {
    goto end; //String
    }

    // v1beta1_custom_resource_definition_spec->subresources
    cJSON *subresources = cJSON_GetObjectItemCaseSensitive(v1beta1_custom_resource_definition_specJSON, "subresources");
    v1beta1_custom_resource_subresources_t *subresources_local_nonprim = NULL;
    if (subresources) { 
    subresources_local_nonprim = v1beta1_custom_resource_subresources_parseFromJSON(subresources); //nonprimitive
    }

    // v1beta1_custom_resource_definition_spec->validation
    cJSON *validation = cJSON_GetObjectItemCaseSensitive(v1beta1_custom_resource_definition_specJSON, "validation");
    v1beta1_custom_resource_validation_t *validation_local_nonprim = NULL;
    if (validation) { 
    validation_local_nonprim = v1beta1_custom_resource_validation_parseFromJSON(validation); //nonprimitive
    }

    // v1beta1_custom_resource_definition_spec->version
    cJSON *version = cJSON_GetObjectItemCaseSensitive(v1beta1_custom_resource_definition_specJSON, "version");
    if (version) { 
    if(!cJSON_IsString(version))
    {
    goto end; //String
    }
    }

    // v1beta1_custom_resource_definition_spec->versions
    cJSON *versions = cJSON_GetObjectItemCaseSensitive(v1beta1_custom_resource_definition_specJSON, "versions");
    list_t *versionsList;
    if (versions) { 
    cJSON *versions_local_nonprimitive;
    if(!cJSON_IsArray(versions)){
        goto end; //nonprimitive container
    }

    versionsList = list_create();

    cJSON_ArrayForEach(versions_local_nonprimitive,versions )
    {
        if(!cJSON_IsObject(versions_local_nonprimitive)){
            goto end;
        }
        v1beta1_custom_resource_definition_version_t *versionsItem = v1beta1_custom_resource_definition_version_parseFromJSON(versions_local_nonprimitive);

        list_addElement(versionsList, versionsItem);
    }
    }


    v1beta1_custom_resource_definition_spec_local_var = v1beta1_custom_resource_definition_spec_create (
        additionalPrinterColumns ? additionalPrinterColumnsList : NULL,
        conversion ? conversion_local_nonprim : NULL,
        strdup(group->valuestring),
        names_local_nonprim,
        preserveUnknownFields ? preserveUnknownFields->valueint : 0,
        strdup(scope->valuestring),
        subresources ? subresources_local_nonprim : NULL,
        validation ? validation_local_nonprim : NULL,
        version ? strdup(version->valuestring) : NULL,
        versions ? versionsList : NULL
        );

    return v1beta1_custom_resource_definition_spec_local_var;
end:
    return NULL;

}
