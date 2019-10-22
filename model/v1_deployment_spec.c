#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_deployment_spec.h"



v1_deployment_spec_t *v1_deployment_spec_create(
    int minReadySeconds,
    int paused,
    int progressDeadlineSeconds,
    int replicas,
    int revisionHistoryLimit,
    v1_label_selector_t *selector,
    v1_deployment_strategy_t *strategy,
    v1_pod_template_spec_t *template
    ) {
	v1_deployment_spec_t *v1_deployment_spec_local_var = malloc(sizeof(v1_deployment_spec_t));
    if (!v1_deployment_spec_local_var) {
        return NULL;
    }
	v1_deployment_spec_local_var->minReadySeconds = minReadySeconds;
	v1_deployment_spec_local_var->paused = paused;
	v1_deployment_spec_local_var->progressDeadlineSeconds = progressDeadlineSeconds;
	v1_deployment_spec_local_var->replicas = replicas;
	v1_deployment_spec_local_var->revisionHistoryLimit = revisionHistoryLimit;
	v1_deployment_spec_local_var->selector = selector;
	v1_deployment_spec_local_var->strategy = strategy;
	v1_deployment_spec_local_var->template = template;

	return v1_deployment_spec_local_var;
}


void v1_deployment_spec_free(v1_deployment_spec_t *v1_deployment_spec) {
    listEntry_t *listEntry;
    v1_label_selector_free(v1_deployment_spec->selector);
    v1_deployment_strategy_free(v1_deployment_spec->strategy);
    v1_pod_template_spec_free(v1_deployment_spec->template);
	free(v1_deployment_spec);
}

cJSON *v1_deployment_spec_convertToJSON(v1_deployment_spec_t *v1_deployment_spec) {
	cJSON *item = cJSON_CreateObject();

	// v1_deployment_spec->minReadySeconds
    if(v1_deployment_spec->minReadySeconds) { 
    if(cJSON_AddNumberToObject(item, "minReadySeconds", v1_deployment_spec->minReadySeconds) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1_deployment_spec->paused
    if(v1_deployment_spec->paused) { 
    if(cJSON_AddBoolToObject(item, "paused", v1_deployment_spec->paused) == NULL) {
    goto fail; //Bool
    }
     } 


	// v1_deployment_spec->progressDeadlineSeconds
    if(v1_deployment_spec->progressDeadlineSeconds) { 
    if(cJSON_AddNumberToObject(item, "progressDeadlineSeconds", v1_deployment_spec->progressDeadlineSeconds) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1_deployment_spec->replicas
    if(v1_deployment_spec->replicas) { 
    if(cJSON_AddNumberToObject(item, "replicas", v1_deployment_spec->replicas) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1_deployment_spec->revisionHistoryLimit
    if(v1_deployment_spec->revisionHistoryLimit) { 
    if(cJSON_AddNumberToObject(item, "revisionHistoryLimit", v1_deployment_spec->revisionHistoryLimit) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1_deployment_spec->selector
    if (!v1_deployment_spec->selector) {
        goto fail;
    }
    
    cJSON *selector_local_JSON = v1_label_selector_convertToJSON(v1_deployment_spec->selector);
    if(selector_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "selector", selector_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


	// v1_deployment_spec->strategy
    if(v1_deployment_spec->strategy) { 
    cJSON *strategy_local_JSON = v1_deployment_strategy_convertToJSON(v1_deployment_spec->strategy);
    if(strategy_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "strategy", strategy_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_deployment_spec->template
    if (!v1_deployment_spec->template) {
        goto fail;
    }
    
    cJSON *template_local_JSON = v1_pod_template_spec_convertToJSON(v1_deployment_spec->template);
    if(template_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "template", template_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1_deployment_spec_t *v1_deployment_spec_parseFromJSON(cJSON *v1_deployment_specJSON){

    v1_deployment_spec_t *v1_deployment_spec_local_var = NULL;

    // v1_deployment_spec->minReadySeconds
    cJSON *minReadySeconds = cJSON_GetObjectItemCaseSensitive(v1_deployment_specJSON, "minReadySeconds");
    if (minReadySeconds) { 
    if(!cJSON_IsNumber(minReadySeconds))
    {
    goto end; //Numeric
    }
    }

    // v1_deployment_spec->paused
    cJSON *paused = cJSON_GetObjectItemCaseSensitive(v1_deployment_specJSON, "paused");
    if (paused) { 
    if(!cJSON_IsBool(paused))
    {
    goto end; //Bool
    }
    }

    // v1_deployment_spec->progressDeadlineSeconds
    cJSON *progressDeadlineSeconds = cJSON_GetObjectItemCaseSensitive(v1_deployment_specJSON, "progressDeadlineSeconds");
    if (progressDeadlineSeconds) { 
    if(!cJSON_IsNumber(progressDeadlineSeconds))
    {
    goto end; //Numeric
    }
    }

    // v1_deployment_spec->replicas
    cJSON *replicas = cJSON_GetObjectItemCaseSensitive(v1_deployment_specJSON, "replicas");
    if (replicas) { 
    if(!cJSON_IsNumber(replicas))
    {
    goto end; //Numeric
    }
    }

    // v1_deployment_spec->revisionHistoryLimit
    cJSON *revisionHistoryLimit = cJSON_GetObjectItemCaseSensitive(v1_deployment_specJSON, "revisionHistoryLimit");
    if (revisionHistoryLimit) { 
    if(!cJSON_IsNumber(revisionHistoryLimit))
    {
    goto end; //Numeric
    }
    }

    // v1_deployment_spec->selector
    cJSON *selector = cJSON_GetObjectItemCaseSensitive(v1_deployment_specJSON, "selector");
    if (!selector) {
        goto end;
    }

    v1_label_selector_t *selector_local_nonprim = NULL;
    
    selector_local_nonprim = v1_label_selector_parseFromJSON(selector); //nonprimitive

    // v1_deployment_spec->strategy
    cJSON *strategy = cJSON_GetObjectItemCaseSensitive(v1_deployment_specJSON, "strategy");
    v1_deployment_strategy_t *strategy_local_nonprim = NULL;
    if (strategy) { 
    strategy_local_nonprim = v1_deployment_strategy_parseFromJSON(strategy); //nonprimitive
    }

    // v1_deployment_spec->template
    cJSON *template = cJSON_GetObjectItemCaseSensitive(v1_deployment_specJSON, "template");
    if (!template) {
        goto end;
    }

    v1_pod_template_spec_t *template_local_nonprim = NULL;
    
    template_local_nonprim = v1_pod_template_spec_parseFromJSON(template); //nonprimitive


    v1_deployment_spec_local_var = v1_deployment_spec_create (
        minReadySeconds ? minReadySeconds->valuedouble : 0,
        paused ? paused->valueint : 0,
        progressDeadlineSeconds ? progressDeadlineSeconds->valuedouble : 0,
        replicas ? replicas->valuedouble : 0,
        revisionHistoryLimit ? revisionHistoryLimit->valuedouble : 0,
        selector_local_nonprim,
        strategy ? strategy_local_nonprim : NULL,
        template_local_nonprim
        );

    return v1_deployment_spec_local_var;
end:
    return NULL;

}
