#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_runtime_class.h"



v1beta1_runtime_class_t *v1beta1_runtime_class_create(
    char *apiVersion,
    char *handler,
    char *kind,
    v1_object_meta_t *metadata,
    v1beta1_overhead_t *overhead,
    v1beta1_scheduling_t *scheduling
    ) {
	v1beta1_runtime_class_t *v1beta1_runtime_class_local_var = malloc(sizeof(v1beta1_runtime_class_t));
    if (!v1beta1_runtime_class_local_var) {
        return NULL;
    }
	v1beta1_runtime_class_local_var->apiVersion = apiVersion;
	v1beta1_runtime_class_local_var->handler = handler;
	v1beta1_runtime_class_local_var->kind = kind;
	v1beta1_runtime_class_local_var->metadata = metadata;
	v1beta1_runtime_class_local_var->overhead = overhead;
	v1beta1_runtime_class_local_var->scheduling = scheduling;

	return v1beta1_runtime_class_local_var;
}


void v1beta1_runtime_class_free(v1beta1_runtime_class_t *v1beta1_runtime_class) {
    listEntry_t *listEntry;
    free(v1beta1_runtime_class->apiVersion);
    free(v1beta1_runtime_class->handler);
    free(v1beta1_runtime_class->kind);
    v1_object_meta_free(v1beta1_runtime_class->metadata);
    v1beta1_overhead_free(v1beta1_runtime_class->overhead);
    v1beta1_scheduling_free(v1beta1_runtime_class->scheduling);
	free(v1beta1_runtime_class);
}

cJSON *v1beta1_runtime_class_convertToJSON(v1beta1_runtime_class_t *v1beta1_runtime_class) {
	cJSON *item = cJSON_CreateObject();

	// v1beta1_runtime_class->apiVersion
    if(v1beta1_runtime_class->apiVersion) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1beta1_runtime_class->apiVersion) == NULL) {
    goto fail; //String
    }
     } 


	// v1beta1_runtime_class->handler
    if (!v1beta1_runtime_class->handler) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "handler", v1beta1_runtime_class->handler) == NULL) {
    goto fail; //String
    }


	// v1beta1_runtime_class->kind
    if(v1beta1_runtime_class->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1beta1_runtime_class->kind) == NULL) {
    goto fail; //String
    }
     } 


	// v1beta1_runtime_class->metadata
    if(v1beta1_runtime_class->metadata) { 
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1beta1_runtime_class->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1beta1_runtime_class->overhead
    if(v1beta1_runtime_class->overhead) { 
    cJSON *overhead_local_JSON = v1beta1_overhead_convertToJSON(v1beta1_runtime_class->overhead);
    if(overhead_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "overhead", overhead_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1beta1_runtime_class->scheduling
    if(v1beta1_runtime_class->scheduling) { 
    cJSON *scheduling_local_JSON = v1beta1_scheduling_convertToJSON(v1beta1_runtime_class->scheduling);
    if(scheduling_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "scheduling", scheduling_local_JSON);
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

v1beta1_runtime_class_t *v1beta1_runtime_class_parseFromJSON(cJSON *v1beta1_runtime_classJSON){

    v1beta1_runtime_class_t *v1beta1_runtime_class_local_var = NULL;

    // v1beta1_runtime_class->apiVersion
    cJSON *apiVersion = cJSON_GetObjectItemCaseSensitive(v1beta1_runtime_classJSON, "apiVersion");
    if (apiVersion) { 
    if(!cJSON_IsString(apiVersion))
    {
    goto end; //String
    }
    }

    // v1beta1_runtime_class->handler
    cJSON *handler = cJSON_GetObjectItemCaseSensitive(v1beta1_runtime_classJSON, "handler");
    if (!handler) {
        goto end;
    }

    
    if(!cJSON_IsString(handler))
    {
    goto end; //String
    }

    // v1beta1_runtime_class->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1beta1_runtime_classJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1beta1_runtime_class->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1beta1_runtime_classJSON, "metadata");
    v1_object_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1beta1_runtime_class->overhead
    cJSON *overhead = cJSON_GetObjectItemCaseSensitive(v1beta1_runtime_classJSON, "overhead");
    v1beta1_overhead_t *overhead_local_nonprim = NULL;
    if (overhead) { 
    overhead_local_nonprim = v1beta1_overhead_parseFromJSON(overhead); //nonprimitive
    }

    // v1beta1_runtime_class->scheduling
    cJSON *scheduling = cJSON_GetObjectItemCaseSensitive(v1beta1_runtime_classJSON, "scheduling");
    v1beta1_scheduling_t *scheduling_local_nonprim = NULL;
    if (scheduling) { 
    scheduling_local_nonprim = v1beta1_scheduling_parseFromJSON(scheduling); //nonprimitive
    }


    v1beta1_runtime_class_local_var = v1beta1_runtime_class_create (
        apiVersion ? strdup(apiVersion->valuestring) : NULL,
        strdup(handler->valuestring),
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        overhead ? overhead_local_nonprim : NULL,
        scheduling ? scheduling_local_nonprim : NULL
        );

    return v1beta1_runtime_class_local_var;
end:
    return NULL;

}
