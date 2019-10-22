#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_audit_sink.h"



v1alpha1_audit_sink_t *v1alpha1_audit_sink_create(
    char *apiVersion,
    char *kind,
    v1_object_meta_t *metadata,
    v1alpha1_audit_sink_spec_t *spec
    ) {
	v1alpha1_audit_sink_t *v1alpha1_audit_sink_local_var = malloc(sizeof(v1alpha1_audit_sink_t));
    if (!v1alpha1_audit_sink_local_var) {
        return NULL;
    }
	v1alpha1_audit_sink_local_var->apiVersion = apiVersion;
	v1alpha1_audit_sink_local_var->kind = kind;
	v1alpha1_audit_sink_local_var->metadata = metadata;
	v1alpha1_audit_sink_local_var->spec = spec;

	return v1alpha1_audit_sink_local_var;
}


void v1alpha1_audit_sink_free(v1alpha1_audit_sink_t *v1alpha1_audit_sink) {
    listEntry_t *listEntry;
    free(v1alpha1_audit_sink->apiVersion);
    free(v1alpha1_audit_sink->kind);
    v1_object_meta_free(v1alpha1_audit_sink->metadata);
    v1alpha1_audit_sink_spec_free(v1alpha1_audit_sink->spec);
	free(v1alpha1_audit_sink);
}

cJSON *v1alpha1_audit_sink_convertToJSON(v1alpha1_audit_sink_t *v1alpha1_audit_sink) {
	cJSON *item = cJSON_CreateObject();

	// v1alpha1_audit_sink->apiVersion
    if(v1alpha1_audit_sink->apiVersion) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1alpha1_audit_sink->apiVersion) == NULL) {
    goto fail; //String
    }
     } 


	// v1alpha1_audit_sink->kind
    if(v1alpha1_audit_sink->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1alpha1_audit_sink->kind) == NULL) {
    goto fail; //String
    }
     } 


	// v1alpha1_audit_sink->metadata
    if(v1alpha1_audit_sink->metadata) { 
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1alpha1_audit_sink->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1alpha1_audit_sink->spec
    if(v1alpha1_audit_sink->spec) { 
    cJSON *spec_local_JSON = v1alpha1_audit_sink_spec_convertToJSON(v1alpha1_audit_sink->spec);
    if(spec_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "spec", spec_local_JSON);
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

v1alpha1_audit_sink_t *v1alpha1_audit_sink_parseFromJSON(cJSON *v1alpha1_audit_sinkJSON){

    v1alpha1_audit_sink_t *v1alpha1_audit_sink_local_var = NULL;

    // v1alpha1_audit_sink->apiVersion
    cJSON *apiVersion = cJSON_GetObjectItemCaseSensitive(v1alpha1_audit_sinkJSON, "apiVersion");
    if (apiVersion) { 
    if(!cJSON_IsString(apiVersion))
    {
    goto end; //String
    }
    }

    // v1alpha1_audit_sink->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1alpha1_audit_sinkJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1alpha1_audit_sink->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1alpha1_audit_sinkJSON, "metadata");
    v1_object_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1alpha1_audit_sink->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(v1alpha1_audit_sinkJSON, "spec");
    v1alpha1_audit_sink_spec_t *spec_local_nonprim = NULL;
    if (spec) { 
    spec_local_nonprim = v1alpha1_audit_sink_spec_parseFromJSON(spec); //nonprimitive
    }


    v1alpha1_audit_sink_local_var = v1alpha1_audit_sink_create (
        apiVersion ? strdup(apiVersion->valuestring) : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        spec ? spec_local_nonprim : NULL
        );

    return v1alpha1_audit_sink_local_var;
end:
    return NULL;

}
