#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_json_schema_props.h"



v1_json_schema_props_t *v1_json_schema_props_create(
    char *$ref,
    char *$schema,
    object_t *additionalItems,
    object_t *additionalProperties,
    list_t *allOf,
    list_t *anyOf,
    object_t *default,
    list_t* definitions,
    list_t* dependencies,
    char *description,
    list_t *enum,
    object_t *example,
    int exclusiveMaximum,
    int exclusiveMinimum,
    v1_external_documentation_t *externalDocs,
    char *format,
    char *id,
    object_t *items,
    long maxItems,
    long maxLength,
    long maxProperties,
    double maximum,
    long minItems,
    long minLength,
    long minProperties,
    double minimum,
    double multipleOf,
    v1_json_schema_props_t *not,
    int nullable,
    list_t *oneOf,
    char *pattern,
    list_t* patternProperties,
    list_t* properties,
    list_t *required,
    char *title,
    char *type,
    int uniqueItems,
    int x-kubernetes-embedded-resource,
    int x-kubernetes-int-or-string,
    list_t *x-kubernetes-list-map-keys,
    char *x-kubernetes-list-type,
    int x-kubernetes-preserve-unknown-fields
    ) {
	v1_json_schema_props_t *v1_json_schema_props_local_var = malloc(sizeof(v1_json_schema_props_t));
    if (!v1_json_schema_props_local_var) {
        return NULL;
    }
	v1_json_schema_props_local_var->$ref = $ref;
	v1_json_schema_props_local_var->$schema = $schema;
	v1_json_schema_props_local_var->additionalItems = additionalItems;
	v1_json_schema_props_local_var->additionalProperties = additionalProperties;
	v1_json_schema_props_local_var->allOf = allOf;
	v1_json_schema_props_local_var->anyOf = anyOf;
	v1_json_schema_props_local_var->default = default;
	v1_json_schema_props_local_var->definitions = definitions;
	v1_json_schema_props_local_var->dependencies = dependencies;
	v1_json_schema_props_local_var->description = description;
	v1_json_schema_props_local_var->enum = enum;
	v1_json_schema_props_local_var->example = example;
	v1_json_schema_props_local_var->exclusiveMaximum = exclusiveMaximum;
	v1_json_schema_props_local_var->exclusiveMinimum = exclusiveMinimum;
	v1_json_schema_props_local_var->externalDocs = externalDocs;
	v1_json_schema_props_local_var->format = format;
	v1_json_schema_props_local_var->id = id;
	v1_json_schema_props_local_var->items = items;
	v1_json_schema_props_local_var->maxItems = maxItems;
	v1_json_schema_props_local_var->maxLength = maxLength;
	v1_json_schema_props_local_var->maxProperties = maxProperties;
	v1_json_schema_props_local_var->maximum = maximum;
	v1_json_schema_props_local_var->minItems = minItems;
	v1_json_schema_props_local_var->minLength = minLength;
	v1_json_schema_props_local_var->minProperties = minProperties;
	v1_json_schema_props_local_var->minimum = minimum;
	v1_json_schema_props_local_var->multipleOf = multipleOf;
	v1_json_schema_props_local_var->not = not;
	v1_json_schema_props_local_var->nullable = nullable;
	v1_json_schema_props_local_var->oneOf = oneOf;
	v1_json_schema_props_local_var->pattern = pattern;
	v1_json_schema_props_local_var->patternProperties = patternProperties;
	v1_json_schema_props_local_var->properties = properties;
	v1_json_schema_props_local_var->required = required;
	v1_json_schema_props_local_var->title = title;
	v1_json_schema_props_local_var->type = type;
	v1_json_schema_props_local_var->uniqueItems = uniqueItems;
	v1_json_schema_props_local_var->x-kubernetes-embedded-resource = x-kubernetes-embedded-resource;
	v1_json_schema_props_local_var->x-kubernetes-int-or-string = x-kubernetes-int-or-string;
	v1_json_schema_props_local_var->x-kubernetes-list-map-keys = x-kubernetes-list-map-keys;
	v1_json_schema_props_local_var->x-kubernetes-list-type = x-kubernetes-list-type;
	v1_json_schema_props_local_var->x-kubernetes-preserve-unknown-fields = x-kubernetes-preserve-unknown-fields;

	return v1_json_schema_props_local_var;
}


void v1_json_schema_props_free(v1_json_schema_props_t *v1_json_schema_props) {
    listEntry_t *listEntry;
    free(v1_json_schema_props->$ref);
    free(v1_json_schema_props->$schema);
    object_free(v1_json_schema_props->additionalItems);
    object_free(v1_json_schema_props->additionalProperties);
	list_ForEach(listEntry, v1_json_schema_props->allOf) {
		v1_json_schema_props_free(listEntry->data);
	}
	list_free(v1_json_schema_props->allOf);
	list_ForEach(listEntry, v1_json_schema_props->anyOf) {
		v1_json_schema_props_free(listEntry->data);
	}
	list_free(v1_json_schema_props->anyOf);
    object_free(v1_json_schema_props->default);
	list_ForEach(listEntry, v1_json_schema_props->definitions) {
		keyValuePair_t *localMapKeyPair = (keyValuePair_t*) listEntry->data;
        free (localKeyValue->key);
        free (localKeyValue->value);
	}
	list_free(v1_json_schema_props->definitions);
	list_ForEach(listEntry, v1_json_schema_props->dependencies) {
		keyValuePair_t *localMapKeyPair = (keyValuePair_t*) listEntry->data;
        free (localKeyValue->key);
        free (localKeyValue->value);
	}
	list_free(v1_json_schema_props->dependencies);
    free(v1_json_schema_props->description);
	list_ForEach(listEntry, v1_json_schema_props->enum) {
		object_free(listEntry->data);
	}
	list_free(v1_json_schema_props->enum);
    object_free(v1_json_schema_props->example);
    v1_external_documentation_free(v1_json_schema_props->externalDocs);
    free(v1_json_schema_props->format);
    free(v1_json_schema_props->id);
    object_free(v1_json_schema_props->items);
    v1_json_schema_props_free(v1_json_schema_props->not);
	list_ForEach(listEntry, v1_json_schema_props->oneOf) {
		v1_json_schema_props_free(listEntry->data);
	}
	list_free(v1_json_schema_props->oneOf);
    free(v1_json_schema_props->pattern);
	list_ForEach(listEntry, v1_json_schema_props->patternProperties) {
		keyValuePair_t *localMapKeyPair = (keyValuePair_t*) listEntry->data;
        free (localKeyValue->key);
        free (localKeyValue->value);
	}
	list_free(v1_json_schema_props->patternProperties);
	list_ForEach(listEntry, v1_json_schema_props->properties) {
		keyValuePair_t *localMapKeyPair = (keyValuePair_t*) listEntry->data;
        free (localKeyValue->key);
        free (localKeyValue->value);
	}
	list_free(v1_json_schema_props->properties);
	list_ForEach(listEntry, v1_json_schema_props->required) {
		free(listEntry->data);
	}
	list_free(v1_json_schema_props->required);
    free(v1_json_schema_props->title);
    free(v1_json_schema_props->type);
	list_ForEach(listEntry, v1_json_schema_props->x-kubernetes-list-map-keys) {
		free(listEntry->data);
	}
	list_free(v1_json_schema_props->x-kubernetes-list-map-keys);
    free(v1_json_schema_props->x-kubernetes-list-type);
	free(v1_json_schema_props);
}

cJSON *v1_json_schema_props_convertToJSON(v1_json_schema_props_t *v1_json_schema_props) {
	cJSON *item = cJSON_CreateObject();

	// v1_json_schema_props->$ref
    if(v1_json_schema_props->$ref) { 
    if(cJSON_AddStringToObject(item, "$ref", v1_json_schema_props->$ref) == NULL) {
    goto fail; //String
    }
     } 


	// v1_json_schema_props->$schema
    if(v1_json_schema_props->$schema) { 
    if(cJSON_AddStringToObject(item, "$schema", v1_json_schema_props->$schema) == NULL) {
    goto fail; //String
    }
     } 


	// v1_json_schema_props->additionalItems
    if(v1_json_schema_props->additionalItems) { 
    cJSON *additionalItems_object = object_convertToJSON(v1_json_schema_props->additionalItems);
    if(additionalItems_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "additionalItems", additionalItems_object);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_json_schema_props->additionalProperties
    if(v1_json_schema_props->additionalProperties) { 
    cJSON *additionalProperties_object = object_convertToJSON(v1_json_schema_props->additionalProperties);
    if(additionalProperties_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "additionalProperties", additionalProperties_object);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_json_schema_props->allOf
    if(v1_json_schema_props->allOf) { 
    cJSON *allOf = cJSON_AddArrayToObject(item, "allOf");
    if(allOf == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *allOfListEntry;
    if (v1_json_schema_props->allOf) {
    list_ForEach(allOfListEntry, v1_json_schema_props->allOf) {
    cJSON *itemLocal = v1_json_schema_props_convertToJSON(allOfListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(allOf, itemLocal);
    }
    }
     } 


	// v1_json_schema_props->anyOf
    if(v1_json_schema_props->anyOf) { 
    cJSON *anyOf = cJSON_AddArrayToObject(item, "anyOf");
    if(anyOf == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *anyOfListEntry;
    if (v1_json_schema_props->anyOf) {
    list_ForEach(anyOfListEntry, v1_json_schema_props->anyOf) {
    cJSON *itemLocal = v1_json_schema_props_convertToJSON(anyOfListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(anyOf, itemLocal);
    }
    }
     } 


	// v1_json_schema_props->default
    if(v1_json_schema_props->default) { 
    cJSON *default_object = object_convertToJSON(v1_json_schema_props->default);
    if(default_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "default", default_object);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_json_schema_props->definitions
    if(v1_json_schema_props->definitions) { 
	cJSON *definitions = cJSON_AddObjectToObject(item, "definitions");
	if(definitions == NULL) {
		goto fail; //primitive map container
	}
    cJSON *localMapObject = cJSON_CreateObject(); //Memory free to be implemented in user code
	listEntry_t *definitionsListEntry;
    if (v1_json_schema_props->definitions) {
    list_ForEach(definitionsListEntry, v1_json_schema_props->definitions) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)definitionsListEntry->data;
        if(cJSON_AddNumberToObject(localMapObject, localKeyValue->key, *(double *)localKeyValue->value) == NULL)
        {
            goto fail;
        }
        cJSON_AddItemToObject(definitions,"", localMapObject);
    }
    }
     } 


	// v1_json_schema_props->dependencies
    if(v1_json_schema_props->dependencies) { 
	cJSON *dependencies = cJSON_AddObjectToObject(item, "dependencies");
	if(dependencies == NULL) {
		goto fail; //primitive map container
	}
    cJSON *localMapObject = cJSON_CreateObject(); //Memory free to be implemented in user code
	listEntry_t *dependenciesListEntry;
    if (v1_json_schema_props->dependencies) {
    list_ForEach(dependenciesListEntry, v1_json_schema_props->dependencies) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)dependenciesListEntry->data;
        if(cJSON_AddNumberToObject(localMapObject, localKeyValue->key, *(double *)localKeyValue->value) == NULL)
        {
            goto fail;
        }
        cJSON_AddItemToObject(dependencies,"", localMapObject);
    }
    }
     } 


	// v1_json_schema_props->description
    if(v1_json_schema_props->description) { 
    if(cJSON_AddStringToObject(item, "description", v1_json_schema_props->description) == NULL) {
    goto fail; //String
    }
     } 


	// v1_json_schema_props->enum
    if(v1_json_schema_props->enum) { 
    cJSON *enum = cJSON_AddArrayToObject(item, "enum");
    if(enum == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *enumListEntry;
    if (v1_json_schema_props->enum) {
    list_ForEach(enumListEntry, v1_json_schema_props->enum) {
    cJSON *itemLocal = object_convertToJSON(enumListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(enum, itemLocal);
    }
    }
     } 


	// v1_json_schema_props->example
    if(v1_json_schema_props->example) { 
    cJSON *example_object = object_convertToJSON(v1_json_schema_props->example);
    if(example_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "example", example_object);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_json_schema_props->exclusiveMaximum
    if(v1_json_schema_props->exclusiveMaximum) { 
    if(cJSON_AddBoolToObject(item, "exclusiveMaximum", v1_json_schema_props->exclusiveMaximum) == NULL) {
    goto fail; //Bool
    }
     } 


	// v1_json_schema_props->exclusiveMinimum
    if(v1_json_schema_props->exclusiveMinimum) { 
    if(cJSON_AddBoolToObject(item, "exclusiveMinimum", v1_json_schema_props->exclusiveMinimum) == NULL) {
    goto fail; //Bool
    }
     } 


	// v1_json_schema_props->externalDocs
    if(v1_json_schema_props->externalDocs) { 
    cJSON *externalDocs_local_JSON = v1_external_documentation_convertToJSON(v1_json_schema_props->externalDocs);
    if(externalDocs_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "externalDocs", externalDocs_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_json_schema_props->format
    if(v1_json_schema_props->format) { 
    if(cJSON_AddStringToObject(item, "format", v1_json_schema_props->format) == NULL) {
    goto fail; //String
    }
     } 


	// v1_json_schema_props->id
    if(v1_json_schema_props->id) { 
    if(cJSON_AddStringToObject(item, "id", v1_json_schema_props->id) == NULL) {
    goto fail; //String
    }
     } 


	// v1_json_schema_props->items
    if(v1_json_schema_props->items) { 
    cJSON *items_object = object_convertToJSON(v1_json_schema_props->items);
    if(items_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "items", items_object);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_json_schema_props->maxItems
    if(v1_json_schema_props->maxItems) { 
    if(cJSON_AddNumberToObject(item, "maxItems", v1_json_schema_props->maxItems) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1_json_schema_props->maxLength
    if(v1_json_schema_props->maxLength) { 
    if(cJSON_AddNumberToObject(item, "maxLength", v1_json_schema_props->maxLength) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1_json_schema_props->maxProperties
    if(v1_json_schema_props->maxProperties) { 
    if(cJSON_AddNumberToObject(item, "maxProperties", v1_json_schema_props->maxProperties) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1_json_schema_props->maximum
    if(v1_json_schema_props->maximum) { 
    if(cJSON_AddNumberToObject(item, "maximum", v1_json_schema_props->maximum) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1_json_schema_props->minItems
    if(v1_json_schema_props->minItems) { 
    if(cJSON_AddNumberToObject(item, "minItems", v1_json_schema_props->minItems) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1_json_schema_props->minLength
    if(v1_json_schema_props->minLength) { 
    if(cJSON_AddNumberToObject(item, "minLength", v1_json_schema_props->minLength) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1_json_schema_props->minProperties
    if(v1_json_schema_props->minProperties) { 
    if(cJSON_AddNumberToObject(item, "minProperties", v1_json_schema_props->minProperties) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1_json_schema_props->minimum
    if(v1_json_schema_props->minimum) { 
    if(cJSON_AddNumberToObject(item, "minimum", v1_json_schema_props->minimum) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1_json_schema_props->multipleOf
    if(v1_json_schema_props->multipleOf) { 
    if(cJSON_AddNumberToObject(item, "multipleOf", v1_json_schema_props->multipleOf) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1_json_schema_props->not
    if(v1_json_schema_props->not) { 
    cJSON *not_local_JSON = v1_json_schema_props_convertToJSON(v1_json_schema_props->not);
    if(not_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "not", not_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_json_schema_props->nullable
    if(v1_json_schema_props->nullable) { 
    if(cJSON_AddBoolToObject(item, "nullable", v1_json_schema_props->nullable) == NULL) {
    goto fail; //Bool
    }
     } 


	// v1_json_schema_props->oneOf
    if(v1_json_schema_props->oneOf) { 
    cJSON *oneOf = cJSON_AddArrayToObject(item, "oneOf");
    if(oneOf == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *oneOfListEntry;
    if (v1_json_schema_props->oneOf) {
    list_ForEach(oneOfListEntry, v1_json_schema_props->oneOf) {
    cJSON *itemLocal = v1_json_schema_props_convertToJSON(oneOfListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(oneOf, itemLocal);
    }
    }
     } 


	// v1_json_schema_props->pattern
    if(v1_json_schema_props->pattern) { 
    if(cJSON_AddStringToObject(item, "pattern", v1_json_schema_props->pattern) == NULL) {
    goto fail; //String
    }
     } 


	// v1_json_schema_props->patternProperties
    if(v1_json_schema_props->patternProperties) { 
	cJSON *patternProperties = cJSON_AddObjectToObject(item, "patternProperties");
	if(patternProperties == NULL) {
		goto fail; //primitive map container
	}
    cJSON *localMapObject = cJSON_CreateObject(); //Memory free to be implemented in user code
	listEntry_t *patternPropertiesListEntry;
    if (v1_json_schema_props->patternProperties) {
    list_ForEach(patternPropertiesListEntry, v1_json_schema_props->patternProperties) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)patternPropertiesListEntry->data;
        if(cJSON_AddNumberToObject(localMapObject, localKeyValue->key, *(double *)localKeyValue->value) == NULL)
        {
            goto fail;
        }
        cJSON_AddItemToObject(patternProperties,"", localMapObject);
    }
    }
     } 


	// v1_json_schema_props->properties
    if(v1_json_schema_props->properties) { 
	cJSON *properties = cJSON_AddObjectToObject(item, "properties");
	if(properties == NULL) {
		goto fail; //primitive map container
	}
    cJSON *localMapObject = cJSON_CreateObject(); //Memory free to be implemented in user code
	listEntry_t *propertiesListEntry;
    if (v1_json_schema_props->properties) {
    list_ForEach(propertiesListEntry, v1_json_schema_props->properties) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)propertiesListEntry->data;
        if(cJSON_AddNumberToObject(localMapObject, localKeyValue->key, *(double *)localKeyValue->value) == NULL)
        {
            goto fail;
        }
        cJSON_AddItemToObject(properties,"", localMapObject);
    }
    }
     } 


	// v1_json_schema_props->required
    if(v1_json_schema_props->required) { 
	cJSON *required = cJSON_AddArrayToObject(item, "required");
	if(required == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *requiredListEntry;
    list_ForEach(requiredListEntry, v1_json_schema_props->required) {
    if(cJSON_AddStringToObject(required, "", (char*)requiredListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


	// v1_json_schema_props->title
    if(v1_json_schema_props->title) { 
    if(cJSON_AddStringToObject(item, "title", v1_json_schema_props->title) == NULL) {
    goto fail; //String
    }
     } 


	// v1_json_schema_props->type
    if(v1_json_schema_props->type) { 
    if(cJSON_AddStringToObject(item, "type", v1_json_schema_props->type) == NULL) {
    goto fail; //String
    }
     } 


	// v1_json_schema_props->uniqueItems
    if(v1_json_schema_props->uniqueItems) { 
    if(cJSON_AddBoolToObject(item, "uniqueItems", v1_json_schema_props->uniqueItems) == NULL) {
    goto fail; //Bool
    }
     } 


	// v1_json_schema_props->x-kubernetes-embedded-resource
    if(v1_json_schema_props->x-kubernetes-embedded-resource) { 
    if(cJSON_AddBoolToObject(item, "x-kubernetes-embedded-resource", v1_json_schema_props->x-kubernetes-embedded-resource) == NULL) {
    goto fail; //Bool
    }
     } 


	// v1_json_schema_props->x-kubernetes-int-or-string
    if(v1_json_schema_props->x-kubernetes-int-or-string) { 
    if(cJSON_AddBoolToObject(item, "x-kubernetes-int-or-string", v1_json_schema_props->x-kubernetes-int-or-string) == NULL) {
    goto fail; //Bool
    }
     } 


	// v1_json_schema_props->x-kubernetes-list-map-keys
    if(v1_json_schema_props->x-kubernetes-list-map-keys) { 
	cJSON *x_kubernetes_list_map_keys = cJSON_AddArrayToObject(item, "x-kubernetes-list-map-keys");
	if(x_kubernetes_list_map_keys == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *x_kubernetes_list_map_keysListEntry;
    list_ForEach(x_kubernetes_list_map_keysListEntry, v1_json_schema_props->x-kubernetes-list-map-keys) {
    if(cJSON_AddStringToObject(x_kubernetes_list_map_keys, "", (char*)x_kubernetes_list_map_keysListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


	// v1_json_schema_props->x-kubernetes-list-type
    if(v1_json_schema_props->x-kubernetes-list-type) { 
    if(cJSON_AddStringToObject(item, "x-kubernetes-list-type", v1_json_schema_props->x-kubernetes-list-type) == NULL) {
    goto fail; //String
    }
     } 


	// v1_json_schema_props->x-kubernetes-preserve-unknown-fields
    if(v1_json_schema_props->x-kubernetes-preserve-unknown-fields) { 
    if(cJSON_AddBoolToObject(item, "x-kubernetes-preserve-unknown-fields", v1_json_schema_props->x-kubernetes-preserve-unknown-fields) == NULL) {
    goto fail; //Bool
    }
     } 

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1_json_schema_props_t *v1_json_schema_props_parseFromJSON(cJSON *v1_json_schema_propsJSON){

    v1_json_schema_props_t *v1_json_schema_props_local_var = NULL;

    // v1_json_schema_props->$ref
    cJSON *$ref = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "$ref");
    if ($ref) { 
    if(!cJSON_IsString($ref))
    {
    goto end; //String
    }
    }

    // v1_json_schema_props->$schema
    cJSON *$schema = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "$schema");
    if ($schema) { 
    if(!cJSON_IsString($schema))
    {
    goto end; //String
    }
    }

    // v1_json_schema_props->additionalItems
    cJSON *additionalItems = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "additionalItems");
    object_t *additionalItems_local_object = NULL;
    if (additionalItems) { 
    additionalItems_local_object = object_parseFromJSON(additionalItems); //object
    }

    // v1_json_schema_props->additionalProperties
    cJSON *additionalProperties = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "additionalProperties");
    object_t *additionalProperties_local_object = NULL;
    if (additionalProperties) { 
    additionalProperties_local_object = object_parseFromJSON(additionalProperties); //object
    }

    // v1_json_schema_props->allOf
    cJSON *allOf = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "allOf");
    list_t *allOfList;
    if (allOf) { 
    cJSON *allOf_local_nonprimitive;
    if(!cJSON_IsArray(allOf)){
        goto end; //nonprimitive container
    }

    allOfList = list_create();

    cJSON_ArrayForEach(allOf_local_nonprimitive,allOf )
    {
        if(!cJSON_IsObject(allOf_local_nonprimitive)){
            goto end;
        }
        v1_json_schema_props_t *allOfItem = v1_json_schema_props_parseFromJSON(allOf_local_nonprimitive);

        list_addElement(allOfList, allOfItem);
    }
    }

    // v1_json_schema_props->anyOf
    cJSON *anyOf = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "anyOf");
    list_t *anyOfList;
    if (anyOf) { 
    cJSON *anyOf_local_nonprimitive;
    if(!cJSON_IsArray(anyOf)){
        goto end; //nonprimitive container
    }

    anyOfList = list_create();

    cJSON_ArrayForEach(anyOf_local_nonprimitive,anyOf )
    {
        if(!cJSON_IsObject(anyOf_local_nonprimitive)){
            goto end;
        }
        v1_json_schema_props_t *anyOfItem = v1_json_schema_props_parseFromJSON(anyOf_local_nonprimitive);

        list_addElement(anyOfList, anyOfItem);
    }
    }

    // v1_json_schema_props->default
    cJSON *default = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "default");
    object_t *default_local_object = NULL;
    if (default) { 
    default_local_object = object_parseFromJSON(default); //object
    }

    // v1_json_schema_props->definitions
    cJSON *definitions = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "definitions");
    list_t *v1_json_schema_propsList;
    if (definitions) { 
    cJSON *v1_json_schema_props_local_map;
    if(!cJSON_IsObject(definitions)) {
        goto end;//primitive map container
    }
    v1_json_schema_propsList = list_create();
    keyValuePair_t *localMapKeyPair;
    cJSON_ArrayForEach(v1_json_schema_props_local_map, definitions)
    {
        if(!cJSON_IsNumber(v1_json_schema_props_local_map))
        {
            goto end;
        }
        localMapKeyPair = keyValuePair_create(strdup(v1_json_schema_props_local_map->string),&v1_json_schema_props_local_map->valuedouble );
        list_addElement(v1_json_schema_propsList , localMapKeyPair);
    }
    }

    // v1_json_schema_props->dependencies
    cJSON *dependencies = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "dependencies");
    list_t *objectList;
    if (dependencies) { 
    cJSON *object_local_map;
    if(!cJSON_IsObject(dependencies)) {
        goto end;//primitive map container
    }
    objectList = list_create();
    keyValuePair_t *localMapKeyPair;
    cJSON_ArrayForEach(object_local_map, dependencies)
    {
        if(!cJSON_IsNumber(object_local_map))
        {
            goto end;
        }
        localMapKeyPair = keyValuePair_create(strdup(object_local_map->string),&object_local_map->valuedouble );
        list_addElement(objectList , localMapKeyPair);
    }
    }

    // v1_json_schema_props->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "description");
    if (description) { 
    if(!cJSON_IsString(description))
    {
    goto end; //String
    }
    }

    // v1_json_schema_props->enum
    cJSON *enum = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "enum");
    list_t *enumList;
    if (enum) { 
    cJSON *enum_local_nonprimitive;
    if(!cJSON_IsArray(enum)){
        goto end; //nonprimitive container
    }

    enumList = list_create();

    cJSON_ArrayForEach(enum_local_nonprimitive,enum )
    {
        if(!cJSON_IsObject(enum_local_nonprimitive)){
            goto end;
        }
        object_t *enumItem = object_parseFromJSON(enum_local_nonprimitive);

        list_addElement(enumList, enumItem);
    }
    }

    // v1_json_schema_props->example
    cJSON *example = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "example");
    object_t *example_local_object = NULL;
    if (example) { 
    example_local_object = object_parseFromJSON(example); //object
    }

    // v1_json_schema_props->exclusiveMaximum
    cJSON *exclusiveMaximum = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "exclusiveMaximum");
    if (exclusiveMaximum) { 
    if(!cJSON_IsBool(exclusiveMaximum))
    {
    goto end; //Bool
    }
    }

    // v1_json_schema_props->exclusiveMinimum
    cJSON *exclusiveMinimum = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "exclusiveMinimum");
    if (exclusiveMinimum) { 
    if(!cJSON_IsBool(exclusiveMinimum))
    {
    goto end; //Bool
    }
    }

    // v1_json_schema_props->externalDocs
    cJSON *externalDocs = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "externalDocs");
    v1_external_documentation_t *externalDocs_local_nonprim = NULL;
    if (externalDocs) { 
    externalDocs_local_nonprim = v1_external_documentation_parseFromJSON(externalDocs); //nonprimitive
    }

    // v1_json_schema_props->format
    cJSON *format = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "format");
    if (format) { 
    if(!cJSON_IsString(format))
    {
    goto end; //String
    }
    }

    // v1_json_schema_props->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "id");
    if (id) { 
    if(!cJSON_IsString(id))
    {
    goto end; //String
    }
    }

    // v1_json_schema_props->items
    cJSON *items = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "items");
    object_t *items_local_object = NULL;
    if (items) { 
    items_local_object = object_parseFromJSON(items); //object
    }

    // v1_json_schema_props->maxItems
    cJSON *maxItems = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "maxItems");
    if (maxItems) { 
    if(!cJSON_IsNumber(maxItems))
    {
    goto end; //Numeric
    }
    }

    // v1_json_schema_props->maxLength
    cJSON *maxLength = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "maxLength");
    if (maxLength) { 
    if(!cJSON_IsNumber(maxLength))
    {
    goto end; //Numeric
    }
    }

    // v1_json_schema_props->maxProperties
    cJSON *maxProperties = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "maxProperties");
    if (maxProperties) { 
    if(!cJSON_IsNumber(maxProperties))
    {
    goto end; //Numeric
    }
    }

    // v1_json_schema_props->maximum
    cJSON *maximum = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "maximum");
    if (maximum) { 
    if(!cJSON_IsNumber(maximum))
    {
    goto end; //Numeric
    }
    }

    // v1_json_schema_props->minItems
    cJSON *minItems = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "minItems");
    if (minItems) { 
    if(!cJSON_IsNumber(minItems))
    {
    goto end; //Numeric
    }
    }

    // v1_json_schema_props->minLength
    cJSON *minLength = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "minLength");
    if (minLength) { 
    if(!cJSON_IsNumber(minLength))
    {
    goto end; //Numeric
    }
    }

    // v1_json_schema_props->minProperties
    cJSON *minProperties = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "minProperties");
    if (minProperties) { 
    if(!cJSON_IsNumber(minProperties))
    {
    goto end; //Numeric
    }
    }

    // v1_json_schema_props->minimum
    cJSON *minimum = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "minimum");
    if (minimum) { 
    if(!cJSON_IsNumber(minimum))
    {
    goto end; //Numeric
    }
    }

    // v1_json_schema_props->multipleOf
    cJSON *multipleOf = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "multipleOf");
    if (multipleOf) { 
    if(!cJSON_IsNumber(multipleOf))
    {
    goto end; //Numeric
    }
    }

    // v1_json_schema_props->not
    cJSON *not = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "not");
    v1_json_schema_props_t *not_local_nonprim = NULL;
    if (not) { 
    not_local_nonprim = v1_json_schema_props_parseFromJSON(not); //nonprimitive
    }

    // v1_json_schema_props->nullable
    cJSON *nullable = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "nullable");
    if (nullable) { 
    if(!cJSON_IsBool(nullable))
    {
    goto end; //Bool
    }
    }

    // v1_json_schema_props->oneOf
    cJSON *oneOf = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "oneOf");
    list_t *oneOfList;
    if (oneOf) { 
    cJSON *oneOf_local_nonprimitive;
    if(!cJSON_IsArray(oneOf)){
        goto end; //nonprimitive container
    }

    oneOfList = list_create();

    cJSON_ArrayForEach(oneOf_local_nonprimitive,oneOf )
    {
        if(!cJSON_IsObject(oneOf_local_nonprimitive)){
            goto end;
        }
        v1_json_schema_props_t *oneOfItem = v1_json_schema_props_parseFromJSON(oneOf_local_nonprimitive);

        list_addElement(oneOfList, oneOfItem);
    }
    }

    // v1_json_schema_props->pattern
    cJSON *pattern = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "pattern");
    if (pattern) { 
    if(!cJSON_IsString(pattern))
    {
    goto end; //String
    }
    }

    // v1_json_schema_props->patternProperties
    cJSON *patternProperties = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "patternProperties");
    list_t *v1_json_schema_propsList;
    if (patternProperties) { 
    cJSON *v1_json_schema_props_local_map;
    if(!cJSON_IsObject(patternProperties)) {
        goto end;//primitive map container
    }
    v1_json_schema_propsList = list_create();
    keyValuePair_t *localMapKeyPair;
    cJSON_ArrayForEach(v1_json_schema_props_local_map, patternProperties)
    {
        if(!cJSON_IsNumber(v1_json_schema_props_local_map))
        {
            goto end;
        }
        localMapKeyPair = keyValuePair_create(strdup(v1_json_schema_props_local_map->string),&v1_json_schema_props_local_map->valuedouble );
        list_addElement(v1_json_schema_propsList , localMapKeyPair);
    }
    }

    // v1_json_schema_props->properties
    cJSON *properties = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "properties");
    list_t *v1_json_schema_propsList;
    if (properties) { 
    cJSON *v1_json_schema_props_local_map;
    if(!cJSON_IsObject(properties)) {
        goto end;//primitive map container
    }
    v1_json_schema_propsList = list_create();
    keyValuePair_t *localMapKeyPair;
    cJSON_ArrayForEach(v1_json_schema_props_local_map, properties)
    {
        if(!cJSON_IsNumber(v1_json_schema_props_local_map))
        {
            goto end;
        }
        localMapKeyPair = keyValuePair_create(strdup(v1_json_schema_props_local_map->string),&v1_json_schema_props_local_map->valuedouble );
        list_addElement(v1_json_schema_propsList , localMapKeyPair);
    }
    }

    // v1_json_schema_props->required
    cJSON *required = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "required");
    list_t *requiredList;
    if (required) { 
    cJSON *required_local;
    if(!cJSON_IsArray(required)) {
        goto end;//primitive container
    }
    requiredList = list_create();

    cJSON_ArrayForEach(required_local, required)
    {
        if(!cJSON_IsString(required_local))
        {
            goto end;
        }
        list_addElement(requiredList , strdup(required_local->valuestring));
    }
    }

    // v1_json_schema_props->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "title");
    if (title) { 
    if(!cJSON_IsString(title))
    {
    goto end; //String
    }
    }

    // v1_json_schema_props->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "type");
    if (type) { 
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }
    }

    // v1_json_schema_props->uniqueItems
    cJSON *uniqueItems = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "uniqueItems");
    if (uniqueItems) { 
    if(!cJSON_IsBool(uniqueItems))
    {
    goto end; //Bool
    }
    }

    // v1_json_schema_props->x-kubernetes-embedded-resource
    cJSON *x-kubernetes-embedded-resource = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "x-kubernetes-embedded-resource");
    if (x-kubernetes-embedded-resource) { 
    if(!cJSON_IsBool(x-kubernetes-embedded-resource))
    {
    goto end; //Bool
    }
    }

    // v1_json_schema_props->x-kubernetes-int-or-string
    cJSON *x-kubernetes-int-or-string = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "x-kubernetes-int-or-string");
    if (x-kubernetes-int-or-string) { 
    if(!cJSON_IsBool(x-kubernetes-int-or-string))
    {
    goto end; //Bool
    }
    }

    // v1_json_schema_props->x-kubernetes-list-map-keys
    cJSON *x-kubernetes-list-map-keys = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "x-kubernetes-list-map-keys");
    list_t *x_kubernetes_list_map_keysList;
    if (x-kubernetes-list-map-keys) { 
    cJSON *x_kubernetes_list_map_keys_local;
    if(!cJSON_IsArray(x-kubernetes-list-map-keys)) {
        goto end;//primitive container
    }
    x_kubernetes_list_map_keysList = list_create();

    cJSON_ArrayForEach(x_kubernetes_list_map_keys_local, x-kubernetes-list-map-keys)
    {
        if(!cJSON_IsString(x_kubernetes_list_map_keys_local))
        {
            goto end;
        }
        list_addElement(x_kubernetes_list_map_keysList , strdup(x_kubernetes_list_map_keys_local->valuestring));
    }
    }

    // v1_json_schema_props->x-kubernetes-list-type
    cJSON *x-kubernetes-list-type = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "x-kubernetes-list-type");
    if (x-kubernetes-list-type) { 
    if(!cJSON_IsString(x-kubernetes-list-type))
    {
    goto end; //String
    }
    }

    // v1_json_schema_props->x-kubernetes-preserve-unknown-fields
    cJSON *x-kubernetes-preserve-unknown-fields = cJSON_GetObjectItemCaseSensitive(v1_json_schema_propsJSON, "x-kubernetes-preserve-unknown-fields");
    if (x-kubernetes-preserve-unknown-fields) { 
    if(!cJSON_IsBool(x-kubernetes-preserve-unknown-fields))
    {
    goto end; //Bool
    }
    }


    v1_json_schema_props_local_var = v1_json_schema_props_create (
        $ref ? strdup($ref->valuestring) : NULL,
        $schema ? strdup($schema->valuestring) : NULL,
        additionalItems ? additionalItems_local_object : NULL,
        additionalProperties ? additionalProperties_local_object : NULL,
        allOf ? allOfList : NULL,
        anyOf ? anyOfList : NULL,
        default ? default_local_object : NULL,
        definitions ? v1_json_schema_propsList : NULL,
        dependencies ? objectList : NULL,
        description ? strdup(description->valuestring) : NULL,
        enum ? enumList : NULL,
        example ? example_local_object : NULL,
        exclusiveMaximum ? exclusiveMaximum->valueint : 0,
        exclusiveMinimum ? exclusiveMinimum->valueint : 0,
        externalDocs ? externalDocs_local_nonprim : NULL,
        format ? strdup(format->valuestring) : NULL,
        id ? strdup(id->valuestring) : NULL,
        items ? items_local_object : NULL,
        maxItems ? maxItems->valuedouble : 0,
        maxLength ? maxLength->valuedouble : 0,
        maxProperties ? maxProperties->valuedouble : 0,
        maximum ? maximum->valuedouble : 0,
        minItems ? minItems->valuedouble : 0,
        minLength ? minLength->valuedouble : 0,
        minProperties ? minProperties->valuedouble : 0,
        minimum ? minimum->valuedouble : 0,
        multipleOf ? multipleOf->valuedouble : 0,
        not ? not_local_nonprim : NULL,
        nullable ? nullable->valueint : 0,
        oneOf ? oneOfList : NULL,
        pattern ? strdup(pattern->valuestring) : NULL,
        patternProperties ? v1_json_schema_propsList : NULL,
        properties ? v1_json_schema_propsList : NULL,
        required ? requiredList : NULL,
        title ? strdup(title->valuestring) : NULL,
        type ? strdup(type->valuestring) : NULL,
        uniqueItems ? uniqueItems->valueint : 0,
        x-kubernetes-embedded-resource ? x-kubernetes-embedded-resource->valueint : 0,
        x-kubernetes-int-or-string ? x-kubernetes-int-or-string->valueint : 0,
        x-kubernetes-list-map-keys ? x_kubernetes_list_map_keysList : NULL,
        x-kubernetes-list-type ? strdup(x-kubernetes-list-type->valuestring) : NULL,
        x-kubernetes-preserve-unknown-fields ? x-kubernetes-preserve-unknown-fields->valueint : 0
        );

    return v1_json_schema_props_local_var;
end:
    return NULL;

}
