#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_pod_disruption_budget_spec.h"



v1beta1_pod_disruption_budget_spec_t *v1beta1_pod_disruption_budget_spec_create(
    object_t *maxUnavailable,
    object_t *minAvailable,
    v1_label_selector_t *selector
    ) {
	v1beta1_pod_disruption_budget_spec_t *v1beta1_pod_disruption_budget_spec_local_var = malloc(sizeof(v1beta1_pod_disruption_budget_spec_t));
    if (!v1beta1_pod_disruption_budget_spec_local_var) {
        return NULL;
    }
	v1beta1_pod_disruption_budget_spec_local_var->maxUnavailable = maxUnavailable;
	v1beta1_pod_disruption_budget_spec_local_var->minAvailable = minAvailable;
	v1beta1_pod_disruption_budget_spec_local_var->selector = selector;

	return v1beta1_pod_disruption_budget_spec_local_var;
}


void v1beta1_pod_disruption_budget_spec_free(v1beta1_pod_disruption_budget_spec_t *v1beta1_pod_disruption_budget_spec) {
    listEntry_t *listEntry;
    object_free(v1beta1_pod_disruption_budget_spec->maxUnavailable);
    object_free(v1beta1_pod_disruption_budget_spec->minAvailable);
    v1_label_selector_free(v1beta1_pod_disruption_budget_spec->selector);
	free(v1beta1_pod_disruption_budget_spec);
}

cJSON *v1beta1_pod_disruption_budget_spec_convertToJSON(v1beta1_pod_disruption_budget_spec_t *v1beta1_pod_disruption_budget_spec) {
	cJSON *item = cJSON_CreateObject();

	// v1beta1_pod_disruption_budget_spec->maxUnavailable
    if(v1beta1_pod_disruption_budget_spec->maxUnavailable) { 
    cJSON *maxUnavailable_object = object_convertToJSON(v1beta1_pod_disruption_budget_spec->maxUnavailable);
    if(maxUnavailable_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "maxUnavailable", maxUnavailable_object);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1beta1_pod_disruption_budget_spec->minAvailable
    if(v1beta1_pod_disruption_budget_spec->minAvailable) { 
    cJSON *minAvailable_object = object_convertToJSON(v1beta1_pod_disruption_budget_spec->minAvailable);
    if(minAvailable_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "minAvailable", minAvailable_object);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1beta1_pod_disruption_budget_spec->selector
    if(v1beta1_pod_disruption_budget_spec->selector) { 
    cJSON *selector_local_JSON = v1_label_selector_convertToJSON(v1beta1_pod_disruption_budget_spec->selector);
    if(selector_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "selector", selector_local_JSON);
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

v1beta1_pod_disruption_budget_spec_t *v1beta1_pod_disruption_budget_spec_parseFromJSON(cJSON *v1beta1_pod_disruption_budget_specJSON){

    v1beta1_pod_disruption_budget_spec_t *v1beta1_pod_disruption_budget_spec_local_var = NULL;

    // v1beta1_pod_disruption_budget_spec->maxUnavailable
    cJSON *maxUnavailable = cJSON_GetObjectItemCaseSensitive(v1beta1_pod_disruption_budget_specJSON, "maxUnavailable");
    object_t *maxUnavailable_local_object = NULL;
    if (maxUnavailable) { 
    maxUnavailable_local_object = object_parseFromJSON(maxUnavailable); //object
    }

    // v1beta1_pod_disruption_budget_spec->minAvailable
    cJSON *minAvailable = cJSON_GetObjectItemCaseSensitive(v1beta1_pod_disruption_budget_specJSON, "minAvailable");
    object_t *minAvailable_local_object = NULL;
    if (minAvailable) { 
    minAvailable_local_object = object_parseFromJSON(minAvailable); //object
    }

    // v1beta1_pod_disruption_budget_spec->selector
    cJSON *selector = cJSON_GetObjectItemCaseSensitive(v1beta1_pod_disruption_budget_specJSON, "selector");
    v1_label_selector_t *selector_local_nonprim = NULL;
    if (selector) { 
    selector_local_nonprim = v1_label_selector_parseFromJSON(selector); //nonprimitive
    }


    v1beta1_pod_disruption_budget_spec_local_var = v1beta1_pod_disruption_budget_spec_create (
        maxUnavailable ? maxUnavailable_local_object : NULL,
        minAvailable ? minAvailable_local_object : NULL,
        selector ? selector_local_nonprim : NULL
        );

    return v1beta1_pod_disruption_budget_spec_local_var;
end:
    return NULL;

}
