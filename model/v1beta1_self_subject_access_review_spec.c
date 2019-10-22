#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_self_subject_access_review_spec.h"



v1beta1_self_subject_access_review_spec_t *v1beta1_self_subject_access_review_spec_create(
    v1beta1_non_resource_attributes_t *nonResourceAttributes,
    v1beta1_resource_attributes_t *resourceAttributes
    ) {
	v1beta1_self_subject_access_review_spec_t *v1beta1_self_subject_access_review_spec_local_var = malloc(sizeof(v1beta1_self_subject_access_review_spec_t));
    if (!v1beta1_self_subject_access_review_spec_local_var) {
        return NULL;
    }
	v1beta1_self_subject_access_review_spec_local_var->nonResourceAttributes = nonResourceAttributes;
	v1beta1_self_subject_access_review_spec_local_var->resourceAttributes = resourceAttributes;

	return v1beta1_self_subject_access_review_spec_local_var;
}


void v1beta1_self_subject_access_review_spec_free(v1beta1_self_subject_access_review_spec_t *v1beta1_self_subject_access_review_spec) {
    listEntry_t *listEntry;
    v1beta1_non_resource_attributes_free(v1beta1_self_subject_access_review_spec->nonResourceAttributes);
    v1beta1_resource_attributes_free(v1beta1_self_subject_access_review_spec->resourceAttributes);
	free(v1beta1_self_subject_access_review_spec);
}

cJSON *v1beta1_self_subject_access_review_spec_convertToJSON(v1beta1_self_subject_access_review_spec_t *v1beta1_self_subject_access_review_spec) {
	cJSON *item = cJSON_CreateObject();

	// v1beta1_self_subject_access_review_spec->nonResourceAttributes
    if(v1beta1_self_subject_access_review_spec->nonResourceAttributes) { 
    cJSON *nonResourceAttributes_local_JSON = v1beta1_non_resource_attributes_convertToJSON(v1beta1_self_subject_access_review_spec->nonResourceAttributes);
    if(nonResourceAttributes_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "nonResourceAttributes", nonResourceAttributes_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1beta1_self_subject_access_review_spec->resourceAttributes
    if(v1beta1_self_subject_access_review_spec->resourceAttributes) { 
    cJSON *resourceAttributes_local_JSON = v1beta1_resource_attributes_convertToJSON(v1beta1_self_subject_access_review_spec->resourceAttributes);
    if(resourceAttributes_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "resourceAttributes", resourceAttributes_local_JSON);
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

v1beta1_self_subject_access_review_spec_t *v1beta1_self_subject_access_review_spec_parseFromJSON(cJSON *v1beta1_self_subject_access_review_specJSON){

    v1beta1_self_subject_access_review_spec_t *v1beta1_self_subject_access_review_spec_local_var = NULL;

    // v1beta1_self_subject_access_review_spec->nonResourceAttributes
    cJSON *nonResourceAttributes = cJSON_GetObjectItemCaseSensitive(v1beta1_self_subject_access_review_specJSON, "nonResourceAttributes");
    v1beta1_non_resource_attributes_t *nonResourceAttributes_local_nonprim = NULL;
    if (nonResourceAttributes) { 
    nonResourceAttributes_local_nonprim = v1beta1_non_resource_attributes_parseFromJSON(nonResourceAttributes); //nonprimitive
    }

    // v1beta1_self_subject_access_review_spec->resourceAttributes
    cJSON *resourceAttributes = cJSON_GetObjectItemCaseSensitive(v1beta1_self_subject_access_review_specJSON, "resourceAttributes");
    v1beta1_resource_attributes_t *resourceAttributes_local_nonprim = NULL;
    if (resourceAttributes) { 
    resourceAttributes_local_nonprim = v1beta1_resource_attributes_parseFromJSON(resourceAttributes); //nonprimitive
    }


    v1beta1_self_subject_access_review_spec_local_var = v1beta1_self_subject_access_review_spec_create (
        nonResourceAttributes ? nonResourceAttributes_local_nonprim : NULL,
        resourceAttributes ? resourceAttributes_local_nonprim : NULL
        );

    return v1beta1_self_subject_access_review_spec_local_var;
end:
    return NULL;

}
