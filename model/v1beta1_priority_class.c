#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_priority_class.h"



v1beta1_priority_class_t *v1beta1_priority_class_create(
    char *apiVersion,
    char *description,
    int globalDefault,
    char *kind,
    v1_object_meta_t *metadata,
    char *preemptionPolicy,
    int value
    ) {
	v1beta1_priority_class_t *v1beta1_priority_class_local_var = malloc(sizeof(v1beta1_priority_class_t));
    if (!v1beta1_priority_class_local_var) {
        return NULL;
    }
	v1beta1_priority_class_local_var->apiVersion = apiVersion;
	v1beta1_priority_class_local_var->description = description;
	v1beta1_priority_class_local_var->globalDefault = globalDefault;
	v1beta1_priority_class_local_var->kind = kind;
	v1beta1_priority_class_local_var->metadata = metadata;
	v1beta1_priority_class_local_var->preemptionPolicy = preemptionPolicy;
	v1beta1_priority_class_local_var->value = value;

	return v1beta1_priority_class_local_var;
}


void v1beta1_priority_class_free(v1beta1_priority_class_t *v1beta1_priority_class) {
    listEntry_t *listEntry;
    free(v1beta1_priority_class->apiVersion);
    free(v1beta1_priority_class->description);
    free(v1beta1_priority_class->kind);
    v1_object_meta_free(v1beta1_priority_class->metadata);
    free(v1beta1_priority_class->preemptionPolicy);
	free(v1beta1_priority_class);
}

cJSON *v1beta1_priority_class_convertToJSON(v1beta1_priority_class_t *v1beta1_priority_class) {
	cJSON *item = cJSON_CreateObject();

	// v1beta1_priority_class->apiVersion
    if(v1beta1_priority_class->apiVersion) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1beta1_priority_class->apiVersion) == NULL) {
    goto fail; //String
    }
     } 


	// v1beta1_priority_class->description
    if(v1beta1_priority_class->description) { 
    if(cJSON_AddStringToObject(item, "description", v1beta1_priority_class->description) == NULL) {
    goto fail; //String
    }
     } 


	// v1beta1_priority_class->globalDefault
    if(v1beta1_priority_class->globalDefault) { 
    if(cJSON_AddBoolToObject(item, "globalDefault", v1beta1_priority_class->globalDefault) == NULL) {
    goto fail; //Bool
    }
     } 


	// v1beta1_priority_class->kind
    if(v1beta1_priority_class->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1beta1_priority_class->kind) == NULL) {
    goto fail; //String
    }
     } 


	// v1beta1_priority_class->metadata
    if(v1beta1_priority_class->metadata) { 
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1beta1_priority_class->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1beta1_priority_class->preemptionPolicy
    if(v1beta1_priority_class->preemptionPolicy) { 
    if(cJSON_AddStringToObject(item, "preemptionPolicy", v1beta1_priority_class->preemptionPolicy) == NULL) {
    goto fail; //String
    }
     } 


	// v1beta1_priority_class->value
    if (!v1beta1_priority_class->value) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "value", v1beta1_priority_class->value) == NULL) {
    goto fail; //Numeric
    }

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1beta1_priority_class_t *v1beta1_priority_class_parseFromJSON(cJSON *v1beta1_priority_classJSON){

    v1beta1_priority_class_t *v1beta1_priority_class_local_var = NULL;

    // v1beta1_priority_class->apiVersion
    cJSON *apiVersion = cJSON_GetObjectItemCaseSensitive(v1beta1_priority_classJSON, "apiVersion");
    if (apiVersion) { 
    if(!cJSON_IsString(apiVersion))
    {
    goto end; //String
    }
    }

    // v1beta1_priority_class->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(v1beta1_priority_classJSON, "description");
    if (description) { 
    if(!cJSON_IsString(description))
    {
    goto end; //String
    }
    }

    // v1beta1_priority_class->globalDefault
    cJSON *globalDefault = cJSON_GetObjectItemCaseSensitive(v1beta1_priority_classJSON, "globalDefault");
    if (globalDefault) { 
    if(!cJSON_IsBool(globalDefault))
    {
    goto end; //Bool
    }
    }

    // v1beta1_priority_class->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1beta1_priority_classJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1beta1_priority_class->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1beta1_priority_classJSON, "metadata");
    v1_object_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1beta1_priority_class->preemptionPolicy
    cJSON *preemptionPolicy = cJSON_GetObjectItemCaseSensitive(v1beta1_priority_classJSON, "preemptionPolicy");
    if (preemptionPolicy) { 
    if(!cJSON_IsString(preemptionPolicy))
    {
    goto end; //String
    }
    }

    // v1beta1_priority_class->value
    cJSON *value = cJSON_GetObjectItemCaseSensitive(v1beta1_priority_classJSON, "value");
    if (!value) {
        goto end;
    }

    
    if(!cJSON_IsNumber(value))
    {
    goto end; //Numeric
    }


    v1beta1_priority_class_local_var = v1beta1_priority_class_create (
        apiVersion ? strdup(apiVersion->valuestring) : NULL,
        description ? strdup(description->valuestring) : NULL,
        globalDefault ? globalDefault->valueint : 0,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        preemptionPolicy ? strdup(preemptionPolicy->valuestring) : NULL,
        value->valuedouble
        );

    return v1beta1_priority_class_local_var;
end:
    return NULL;

}
