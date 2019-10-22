#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v2alpha1_job_template_spec.h"



v2alpha1_job_template_spec_t *v2alpha1_job_template_spec_create(
    v1_object_meta_t *metadata,
    v1_job_spec_t *spec
    ) {
	v2alpha1_job_template_spec_t *v2alpha1_job_template_spec_local_var = malloc(sizeof(v2alpha1_job_template_spec_t));
    if (!v2alpha1_job_template_spec_local_var) {
        return NULL;
    }
	v2alpha1_job_template_spec_local_var->metadata = metadata;
	v2alpha1_job_template_spec_local_var->spec = spec;

	return v2alpha1_job_template_spec_local_var;
}


void v2alpha1_job_template_spec_free(v2alpha1_job_template_spec_t *v2alpha1_job_template_spec) {
    listEntry_t *listEntry;
    v1_object_meta_free(v2alpha1_job_template_spec->metadata);
    v1_job_spec_free(v2alpha1_job_template_spec->spec);
	free(v2alpha1_job_template_spec);
}

cJSON *v2alpha1_job_template_spec_convertToJSON(v2alpha1_job_template_spec_t *v2alpha1_job_template_spec) {
	cJSON *item = cJSON_CreateObject();

	// v2alpha1_job_template_spec->metadata
    if(v2alpha1_job_template_spec->metadata) { 
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v2alpha1_job_template_spec->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v2alpha1_job_template_spec->spec
    if(v2alpha1_job_template_spec->spec) { 
    cJSON *spec_local_JSON = v1_job_spec_convertToJSON(v2alpha1_job_template_spec->spec);
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

v2alpha1_job_template_spec_t *v2alpha1_job_template_spec_parseFromJSON(cJSON *v2alpha1_job_template_specJSON){

    v2alpha1_job_template_spec_t *v2alpha1_job_template_spec_local_var = NULL;

    // v2alpha1_job_template_spec->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v2alpha1_job_template_specJSON, "metadata");
    v1_object_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v2alpha1_job_template_spec->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(v2alpha1_job_template_specJSON, "spec");
    v1_job_spec_t *spec_local_nonprim = NULL;
    if (spec) { 
    spec_local_nonprim = v1_job_spec_parseFromJSON(spec); //nonprimitive
    }


    v2alpha1_job_template_spec_local_var = v2alpha1_job_template_spec_create (
        metadata ? metadata_local_nonprim : NULL,
        spec ? spec_local_nonprim : NULL
        );

    return v2alpha1_job_template_spec_local_var;
end:
    return NULL;

}
