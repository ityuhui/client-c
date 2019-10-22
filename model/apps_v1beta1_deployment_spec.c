#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "apps_v1beta1_deployment_spec.h"



apps_v1beta1_deployment_spec_t *apps_v1beta1_deployment_spec_create(
    int minReadySeconds,
    int paused,
    int progressDeadlineSeconds,
    int replicas,
    int revisionHistoryLimit,
    apps_v1beta1_rollback_config_t *rollbackTo,
    v1_label_selector_t *selector,
    apps_v1beta1_deployment_strategy_t *strategy,
    v1_pod_template_spec_t *template
    ) {
	apps_v1beta1_deployment_spec_t *apps_v1beta1_deployment_spec_local_var = malloc(sizeof(apps_v1beta1_deployment_spec_t));
    if (!apps_v1beta1_deployment_spec_local_var) {
        return NULL;
    }
	apps_v1beta1_deployment_spec_local_var->minReadySeconds = minReadySeconds;
	apps_v1beta1_deployment_spec_local_var->paused = paused;
	apps_v1beta1_deployment_spec_local_var->progressDeadlineSeconds = progressDeadlineSeconds;
	apps_v1beta1_deployment_spec_local_var->replicas = replicas;
	apps_v1beta1_deployment_spec_local_var->revisionHistoryLimit = revisionHistoryLimit;
	apps_v1beta1_deployment_spec_local_var->rollbackTo = rollbackTo;
	apps_v1beta1_deployment_spec_local_var->selector = selector;
	apps_v1beta1_deployment_spec_local_var->strategy = strategy;
	apps_v1beta1_deployment_spec_local_var->template = template;

	return apps_v1beta1_deployment_spec_local_var;
}


void apps_v1beta1_deployment_spec_free(apps_v1beta1_deployment_spec_t *apps_v1beta1_deployment_spec) {
    listEntry_t *listEntry;
    apps_v1beta1_rollback_config_free(apps_v1beta1_deployment_spec->rollbackTo);
    v1_label_selector_free(apps_v1beta1_deployment_spec->selector);
    apps_v1beta1_deployment_strategy_free(apps_v1beta1_deployment_spec->strategy);
    v1_pod_template_spec_free(apps_v1beta1_deployment_spec->template);
	free(apps_v1beta1_deployment_spec);
}

cJSON *apps_v1beta1_deployment_spec_convertToJSON(apps_v1beta1_deployment_spec_t *apps_v1beta1_deployment_spec) {
	cJSON *item = cJSON_CreateObject();

	// apps_v1beta1_deployment_spec->minReadySeconds
    if(apps_v1beta1_deployment_spec->minReadySeconds) { 
    if(cJSON_AddNumberToObject(item, "minReadySeconds", apps_v1beta1_deployment_spec->minReadySeconds) == NULL) {
    goto fail; //Numeric
    }
     } 


	// apps_v1beta1_deployment_spec->paused
    if(apps_v1beta1_deployment_spec->paused) { 
    if(cJSON_AddBoolToObject(item, "paused", apps_v1beta1_deployment_spec->paused) == NULL) {
    goto fail; //Bool
    }
     } 


	// apps_v1beta1_deployment_spec->progressDeadlineSeconds
    if(apps_v1beta1_deployment_spec->progressDeadlineSeconds) { 
    if(cJSON_AddNumberToObject(item, "progressDeadlineSeconds", apps_v1beta1_deployment_spec->progressDeadlineSeconds) == NULL) {
    goto fail; //Numeric
    }
     } 


	// apps_v1beta1_deployment_spec->replicas
    if(apps_v1beta1_deployment_spec->replicas) { 
    if(cJSON_AddNumberToObject(item, "replicas", apps_v1beta1_deployment_spec->replicas) == NULL) {
    goto fail; //Numeric
    }
     } 


	// apps_v1beta1_deployment_spec->revisionHistoryLimit
    if(apps_v1beta1_deployment_spec->revisionHistoryLimit) { 
    if(cJSON_AddNumberToObject(item, "revisionHistoryLimit", apps_v1beta1_deployment_spec->revisionHistoryLimit) == NULL) {
    goto fail; //Numeric
    }
     } 


	// apps_v1beta1_deployment_spec->rollbackTo
    if(apps_v1beta1_deployment_spec->rollbackTo) { 
    cJSON *rollbackTo_local_JSON = apps_v1beta1_rollback_config_convertToJSON(apps_v1beta1_deployment_spec->rollbackTo);
    if(rollbackTo_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "rollbackTo", rollbackTo_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// apps_v1beta1_deployment_spec->selector
    if(apps_v1beta1_deployment_spec->selector) { 
    cJSON *selector_local_JSON = v1_label_selector_convertToJSON(apps_v1beta1_deployment_spec->selector);
    if(selector_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "selector", selector_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// apps_v1beta1_deployment_spec->strategy
    if(apps_v1beta1_deployment_spec->strategy) { 
    cJSON *strategy_local_JSON = apps_v1beta1_deployment_strategy_convertToJSON(apps_v1beta1_deployment_spec->strategy);
    if(strategy_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "strategy", strategy_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// apps_v1beta1_deployment_spec->template
    if (!apps_v1beta1_deployment_spec->template) {
        goto fail;
    }
    
    cJSON *template_local_JSON = v1_pod_template_spec_convertToJSON(apps_v1beta1_deployment_spec->template);
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

apps_v1beta1_deployment_spec_t *apps_v1beta1_deployment_spec_parseFromJSON(cJSON *apps_v1beta1_deployment_specJSON){

    apps_v1beta1_deployment_spec_t *apps_v1beta1_deployment_spec_local_var = NULL;

    // apps_v1beta1_deployment_spec->minReadySeconds
    cJSON *minReadySeconds = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_deployment_specJSON, "minReadySeconds");
    if (minReadySeconds) { 
    if(!cJSON_IsNumber(minReadySeconds))
    {
    goto end; //Numeric
    }
    }

    // apps_v1beta1_deployment_spec->paused
    cJSON *paused = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_deployment_specJSON, "paused");
    if (paused) { 
    if(!cJSON_IsBool(paused))
    {
    goto end; //Bool
    }
    }

    // apps_v1beta1_deployment_spec->progressDeadlineSeconds
    cJSON *progressDeadlineSeconds = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_deployment_specJSON, "progressDeadlineSeconds");
    if (progressDeadlineSeconds) { 
    if(!cJSON_IsNumber(progressDeadlineSeconds))
    {
    goto end; //Numeric
    }
    }

    // apps_v1beta1_deployment_spec->replicas
    cJSON *replicas = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_deployment_specJSON, "replicas");
    if (replicas) { 
    if(!cJSON_IsNumber(replicas))
    {
    goto end; //Numeric
    }
    }

    // apps_v1beta1_deployment_spec->revisionHistoryLimit
    cJSON *revisionHistoryLimit = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_deployment_specJSON, "revisionHistoryLimit");
    if (revisionHistoryLimit) { 
    if(!cJSON_IsNumber(revisionHistoryLimit))
    {
    goto end; //Numeric
    }
    }

    // apps_v1beta1_deployment_spec->rollbackTo
    cJSON *rollbackTo = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_deployment_specJSON, "rollbackTo");
    apps_v1beta1_rollback_config_t *rollbackTo_local_nonprim = NULL;
    if (rollbackTo) { 
    rollbackTo_local_nonprim = apps_v1beta1_rollback_config_parseFromJSON(rollbackTo); //nonprimitive
    }

    // apps_v1beta1_deployment_spec->selector
    cJSON *selector = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_deployment_specJSON, "selector");
    v1_label_selector_t *selector_local_nonprim = NULL;
    if (selector) { 
    selector_local_nonprim = v1_label_selector_parseFromJSON(selector); //nonprimitive
    }

    // apps_v1beta1_deployment_spec->strategy
    cJSON *strategy = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_deployment_specJSON, "strategy");
    apps_v1beta1_deployment_strategy_t *strategy_local_nonprim = NULL;
    if (strategy) { 
    strategy_local_nonprim = apps_v1beta1_deployment_strategy_parseFromJSON(strategy); //nonprimitive
    }

    // apps_v1beta1_deployment_spec->template
    cJSON *template = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_deployment_specJSON, "template");
    if (!template) {
        goto end;
    }

    v1_pod_template_spec_t *template_local_nonprim = NULL;
    
    template_local_nonprim = v1_pod_template_spec_parseFromJSON(template); //nonprimitive


    apps_v1beta1_deployment_spec_local_var = apps_v1beta1_deployment_spec_create (
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

    return apps_v1beta1_deployment_spec_local_var;
end:
    return NULL;

}
