#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "extensions_v1beta1_deployment_spec.h"



extensions_v1beta1_deployment_spec_t *extensions_v1beta1_deployment_spec_create(
    int minReadySeconds,
    int paused,
    int progressDeadlineSeconds,
    int replicas,
    int revisionHistoryLimit,
    extensions_v1beta1_rollback_config_t *rollbackTo,
    v1_label_selector_t *selector,
    extensions_v1beta1_deployment_strategy_t *strategy,
    v1_pod_template_spec_t *template
    ) {
	extensions_v1beta1_deployment_spec_t *extensions_v1beta1_deployment_spec_local_var = malloc(sizeof(extensions_v1beta1_deployment_spec_t));
    if (!extensions_v1beta1_deployment_spec_local_var) {
        return NULL;
    }
	extensions_v1beta1_deployment_spec_local_var->minReadySeconds = minReadySeconds;
	extensions_v1beta1_deployment_spec_local_var->paused = paused;
	extensions_v1beta1_deployment_spec_local_var->progressDeadlineSeconds = progressDeadlineSeconds;
	extensions_v1beta1_deployment_spec_local_var->replicas = replicas;
	extensions_v1beta1_deployment_spec_local_var->revisionHistoryLimit = revisionHistoryLimit;
	extensions_v1beta1_deployment_spec_local_var->rollbackTo = rollbackTo;
	extensions_v1beta1_deployment_spec_local_var->selector = selector;
	extensions_v1beta1_deployment_spec_local_var->strategy = strategy;
	extensions_v1beta1_deployment_spec_local_var->template = template;

	return extensions_v1beta1_deployment_spec_local_var;
}


void extensions_v1beta1_deployment_spec_free(extensions_v1beta1_deployment_spec_t *extensions_v1beta1_deployment_spec) {
    listEntry_t *listEntry;
    extensions_v1beta1_rollback_config_free(extensions_v1beta1_deployment_spec->rollbackTo);
    v1_label_selector_free(extensions_v1beta1_deployment_spec->selector);
    extensions_v1beta1_deployment_strategy_free(extensions_v1beta1_deployment_spec->strategy);
    v1_pod_template_spec_free(extensions_v1beta1_deployment_spec->template);
	free(extensions_v1beta1_deployment_spec);
}

cJSON *extensions_v1beta1_deployment_spec_convertToJSON(extensions_v1beta1_deployment_spec_t *extensions_v1beta1_deployment_spec) {
	cJSON *item = cJSON_CreateObject();

	// extensions_v1beta1_deployment_spec->minReadySeconds
    if(extensions_v1beta1_deployment_spec->minReadySeconds) { 
    if(cJSON_AddNumberToObject(item, "minReadySeconds", extensions_v1beta1_deployment_spec->minReadySeconds) == NULL) {
    goto fail; //Numeric
    }
     } 


	// extensions_v1beta1_deployment_spec->paused
    if(extensions_v1beta1_deployment_spec->paused) { 
    if(cJSON_AddBoolToObject(item, "paused", extensions_v1beta1_deployment_spec->paused) == NULL) {
    goto fail; //Bool
    }
     } 


	// extensions_v1beta1_deployment_spec->progressDeadlineSeconds
    if(extensions_v1beta1_deployment_spec->progressDeadlineSeconds) { 
    if(cJSON_AddNumberToObject(item, "progressDeadlineSeconds", extensions_v1beta1_deployment_spec->progressDeadlineSeconds) == NULL) {
    goto fail; //Numeric
    }
     } 


	// extensions_v1beta1_deployment_spec->replicas
    if(extensions_v1beta1_deployment_spec->replicas) { 
    if(cJSON_AddNumberToObject(item, "replicas", extensions_v1beta1_deployment_spec->replicas) == NULL) {
    goto fail; //Numeric
    }
     } 


	// extensions_v1beta1_deployment_spec->revisionHistoryLimit
    if(extensions_v1beta1_deployment_spec->revisionHistoryLimit) { 
    if(cJSON_AddNumberToObject(item, "revisionHistoryLimit", extensions_v1beta1_deployment_spec->revisionHistoryLimit) == NULL) {
    goto fail; //Numeric
    }
     } 


	// extensions_v1beta1_deployment_spec->rollbackTo
    if(extensions_v1beta1_deployment_spec->rollbackTo) { 
    cJSON *rollbackTo_local_JSON = extensions_v1beta1_rollback_config_convertToJSON(extensions_v1beta1_deployment_spec->rollbackTo);
    if(rollbackTo_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "rollbackTo", rollbackTo_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// extensions_v1beta1_deployment_spec->selector
    if(extensions_v1beta1_deployment_spec->selector) { 
    cJSON *selector_local_JSON = v1_label_selector_convertToJSON(extensions_v1beta1_deployment_spec->selector);
    if(selector_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "selector", selector_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// extensions_v1beta1_deployment_spec->strategy
    if(extensions_v1beta1_deployment_spec->strategy) { 
    cJSON *strategy_local_JSON = extensions_v1beta1_deployment_strategy_convertToJSON(extensions_v1beta1_deployment_spec->strategy);
    if(strategy_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "strategy", strategy_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// extensions_v1beta1_deployment_spec->template
    if (!extensions_v1beta1_deployment_spec->template) {
        goto fail;
    }
    
    cJSON *template_local_JSON = v1_pod_template_spec_convertToJSON(extensions_v1beta1_deployment_spec->template);
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

extensions_v1beta1_deployment_spec_t *extensions_v1beta1_deployment_spec_parseFromJSON(cJSON *extensions_v1beta1_deployment_specJSON){

    extensions_v1beta1_deployment_spec_t *extensions_v1beta1_deployment_spec_local_var = NULL;

    // extensions_v1beta1_deployment_spec->minReadySeconds
    cJSON *minReadySeconds = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_deployment_specJSON, "minReadySeconds");
    if (minReadySeconds) { 
    if(!cJSON_IsNumber(minReadySeconds))
    {
    goto end; //Numeric
    }
    }

    // extensions_v1beta1_deployment_spec->paused
    cJSON *paused = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_deployment_specJSON, "paused");
    if (paused) { 
    if(!cJSON_IsBool(paused))
    {
    goto end; //Bool
    }
    }

    // extensions_v1beta1_deployment_spec->progressDeadlineSeconds
    cJSON *progressDeadlineSeconds = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_deployment_specJSON, "progressDeadlineSeconds");
    if (progressDeadlineSeconds) { 
    if(!cJSON_IsNumber(progressDeadlineSeconds))
    {
    goto end; //Numeric
    }
    }

    // extensions_v1beta1_deployment_spec->replicas
    cJSON *replicas = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_deployment_specJSON, "replicas");
    if (replicas) { 
    if(!cJSON_IsNumber(replicas))
    {
    goto end; //Numeric
    }
    }

    // extensions_v1beta1_deployment_spec->revisionHistoryLimit
    cJSON *revisionHistoryLimit = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_deployment_specJSON, "revisionHistoryLimit");
    if (revisionHistoryLimit) { 
    if(!cJSON_IsNumber(revisionHistoryLimit))
    {
    goto end; //Numeric
    }
    }

    // extensions_v1beta1_deployment_spec->rollbackTo
    cJSON *rollbackTo = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_deployment_specJSON, "rollbackTo");
    extensions_v1beta1_rollback_config_t *rollbackTo_local_nonprim = NULL;
    if (rollbackTo) { 
    rollbackTo_local_nonprim = extensions_v1beta1_rollback_config_parseFromJSON(rollbackTo); //nonprimitive
    }

    // extensions_v1beta1_deployment_spec->selector
    cJSON *selector = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_deployment_specJSON, "selector");
    v1_label_selector_t *selector_local_nonprim = NULL;
    if (selector) { 
    selector_local_nonprim = v1_label_selector_parseFromJSON(selector); //nonprimitive
    }

    // extensions_v1beta1_deployment_spec->strategy
    cJSON *strategy = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_deployment_specJSON, "strategy");
    extensions_v1beta1_deployment_strategy_t *strategy_local_nonprim = NULL;
    if (strategy) { 
    strategy_local_nonprim = extensions_v1beta1_deployment_strategy_parseFromJSON(strategy); //nonprimitive
    }

    // extensions_v1beta1_deployment_spec->template
    cJSON *template = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_deployment_specJSON, "template");
    if (!template) {
        goto end;
    }

    v1_pod_template_spec_t *template_local_nonprim = NULL;
    
    template_local_nonprim = v1_pod_template_spec_parseFromJSON(template); //nonprimitive


    extensions_v1beta1_deployment_spec_local_var = extensions_v1beta1_deployment_spec_create (
        minReadySeconds ? minReadySeconds->valuedouble : 0,
        paused ? paused->valueint : 0,
        progressDeadlineSeconds ? progressDeadlineSeconds->valuedouble : 0,
        replicas ? replicas->valuedouble : 0,
        revisionHistoryLimit ? revisionHistoryLimit->valuedouble : 0,
        rollbackTo ? rollbackTo_local_nonprim : NULL,
        selector ? selector_local_nonprim : NULL,
        strategy ? strategy_local_nonprim : NULL,
        template_local_nonprim
        );

    return extensions_v1beta1_deployment_spec_local_var;
end:
    return NULL;

}
