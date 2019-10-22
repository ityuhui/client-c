#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_replica_set_spec.h"



v1_replica_set_spec_t *v1_replica_set_spec_create(
    int minReadySeconds,
    int replicas,
    v1_label_selector_t *selector,
    v1_pod_template_spec_t *template
    ) {
	v1_replica_set_spec_t *v1_replica_set_spec_local_var = malloc(sizeof(v1_replica_set_spec_t));
    if (!v1_replica_set_spec_local_var) {
        return NULL;
    }
	v1_replica_set_spec_local_var->minReadySeconds = minReadySeconds;
	v1_replica_set_spec_local_var->replicas = replicas;
	v1_replica_set_spec_local_var->selector = selector;
	v1_replica_set_spec_local_var->template = template;

	return v1_replica_set_spec_local_var;
}


void v1_replica_set_spec_free(v1_replica_set_spec_t *v1_replica_set_spec) {
    listEntry_t *listEntry;
    v1_label_selector_free(v1_replica_set_spec->selector);
    v1_pod_template_spec_free(v1_replica_set_spec->template);
	free(v1_replica_set_spec);
}

cJSON *v1_replica_set_spec_convertToJSON(v1_replica_set_spec_t *v1_replica_set_spec) {
	cJSON *item = cJSON_CreateObject();

	// v1_replica_set_spec->minReadySeconds
    if(v1_replica_set_spec->minReadySeconds) { 
    if(cJSON_AddNumberToObject(item, "minReadySeconds", v1_replica_set_spec->minReadySeconds) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1_replica_set_spec->replicas
    if(v1_replica_set_spec->replicas) { 
    if(cJSON_AddNumberToObject(item, "replicas", v1_replica_set_spec->replicas) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1_replica_set_spec->selector
    if (!v1_replica_set_spec->selector) {
        goto fail;
    }
    
    cJSON *selector_local_JSON = v1_label_selector_convertToJSON(v1_replica_set_spec->selector);
    if(selector_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "selector", selector_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


	// v1_replica_set_spec->template
    if(v1_replica_set_spec->template) { 
    cJSON *template_local_JSON = v1_pod_template_spec_convertToJSON(v1_replica_set_spec->template);
    if(template_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "template", template_local_JSON);
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

v1_replica_set_spec_t *v1_replica_set_spec_parseFromJSON(cJSON *v1_replica_set_specJSON){

    v1_replica_set_spec_t *v1_replica_set_spec_local_var = NULL;

    // v1_replica_set_spec->minReadySeconds
    cJSON *minReadySeconds = cJSON_GetObjectItemCaseSensitive(v1_replica_set_specJSON, "minReadySeconds");
    if (minReadySeconds) { 
    if(!cJSON_IsNumber(minReadySeconds))
    {
    goto end; //Numeric
    }
    }

    // v1_replica_set_spec->replicas
    cJSON *replicas = cJSON_GetObjectItemCaseSensitive(v1_replica_set_specJSON, "replicas");
    if (replicas) { 
    if(!cJSON_IsNumber(replicas))
    {
    goto end; //Numeric
    }
    }

    // v1_replica_set_spec->selector
    cJSON *selector = cJSON_GetObjectItemCaseSensitive(v1_replica_set_specJSON, "selector");
    if (!selector) {
        goto end;
    }

    v1_label_selector_t *selector_local_nonprim = NULL;
    
    selector_local_nonprim = v1_label_selector_parseFromJSON(selector); //nonprimitive

    // v1_replica_set_spec->template
    cJSON *template = cJSON_GetObjectItemCaseSensitive(v1_replica_set_specJSON, "template");
    v1_pod_template_spec_t *template_local_nonprim = NULL;
    if (template) { 
    template_local_nonprim = v1_pod_template_spec_parseFromJSON(template); //nonprimitive
    }


    v1_replica_set_spec_local_var = v1_replica_set_spec_create (
        minReadySeconds ? minReadySeconds->valuedouble : 0,
        replicas ? replicas->valuedouble : 0,
        selector_local_nonprim,
        template ? template_local_nonprim : NULL
        );

    return v1_replica_set_spec_local_var;
end:
    return NULL;

}
