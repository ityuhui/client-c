#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_weighted_pod_affinity_term.h"



v1_weighted_pod_affinity_term_t *v1_weighted_pod_affinity_term_create(
    v1_pod_affinity_term_t *podAffinityTerm,
    int weight
    ) {
	v1_weighted_pod_affinity_term_t *v1_weighted_pod_affinity_term_local_var = malloc(sizeof(v1_weighted_pod_affinity_term_t));
    if (!v1_weighted_pod_affinity_term_local_var) {
        return NULL;
    }
	v1_weighted_pod_affinity_term_local_var->podAffinityTerm = podAffinityTerm;
	v1_weighted_pod_affinity_term_local_var->weight = weight;

	return v1_weighted_pod_affinity_term_local_var;
}


void v1_weighted_pod_affinity_term_free(v1_weighted_pod_affinity_term_t *v1_weighted_pod_affinity_term) {
    listEntry_t *listEntry;
    v1_pod_affinity_term_free(v1_weighted_pod_affinity_term->podAffinityTerm);
	free(v1_weighted_pod_affinity_term);
}

cJSON *v1_weighted_pod_affinity_term_convertToJSON(v1_weighted_pod_affinity_term_t *v1_weighted_pod_affinity_term) {
	cJSON *item = cJSON_CreateObject();

	// v1_weighted_pod_affinity_term->podAffinityTerm
    if (!v1_weighted_pod_affinity_term->podAffinityTerm) {
        goto fail;
    }
    
    cJSON *podAffinityTerm_local_JSON = v1_pod_affinity_term_convertToJSON(v1_weighted_pod_affinity_term->podAffinityTerm);
    if(podAffinityTerm_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "podAffinityTerm", podAffinityTerm_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


	// v1_weighted_pod_affinity_term->weight
    if (!v1_weighted_pod_affinity_term->weight) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "weight", v1_weighted_pod_affinity_term->weight) == NULL) {
    goto fail; //Numeric
    }

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1_weighted_pod_affinity_term_t *v1_weighted_pod_affinity_term_parseFromJSON(cJSON *v1_weighted_pod_affinity_termJSON){

    v1_weighted_pod_affinity_term_t *v1_weighted_pod_affinity_term_local_var = NULL;

    // v1_weighted_pod_affinity_term->podAffinityTerm
    cJSON *podAffinityTerm = cJSON_GetObjectItemCaseSensitive(v1_weighted_pod_affinity_termJSON, "podAffinityTerm");
    if (!podAffinityTerm) {
        goto end;
    }

    v1_pod_affinity_term_t *podAffinityTerm_local_nonprim = NULL;
    
    podAffinityTerm_local_nonprim = v1_pod_affinity_term_parseFromJSON(podAffinityTerm); //nonprimitive

    // v1_weighted_pod_affinity_term->weight
    cJSON *weight = cJSON_GetObjectItemCaseSensitive(v1_weighted_pod_affinity_termJSON, "weight");
    if (!weight) {
        goto end;
    }

    
    if(!cJSON_IsNumber(weight))
    {
    goto end; //Numeric
    }


    v1_weighted_pod_affinity_term_local_var = v1_weighted_pod_affinity_term_create (
        podAffinityTerm_local_nonprim,
        weight->valuedouble
        );

    return v1_weighted_pod_affinity_term_local_var;
end:
    return NULL;

}
