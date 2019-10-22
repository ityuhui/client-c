#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta2_stateful_set_spec.h"



v1beta2_stateful_set_spec_t *v1beta2_stateful_set_spec_create(
    char *podManagementPolicy,
    int replicas,
    int revisionHistoryLimit,
    v1_label_selector_t *selector,
    char *serviceName,
    v1_pod_template_spec_t *template,
    v1beta2_stateful_set_update_strategy_t *updateStrategy,
    list_t *volumeClaimTemplates
    ) {
	v1beta2_stateful_set_spec_t *v1beta2_stateful_set_spec_local_var = malloc(sizeof(v1beta2_stateful_set_spec_t));
    if (!v1beta2_stateful_set_spec_local_var) {
        return NULL;
    }
	v1beta2_stateful_set_spec_local_var->podManagementPolicy = podManagementPolicy;
	v1beta2_stateful_set_spec_local_var->replicas = replicas;
	v1beta2_stateful_set_spec_local_var->revisionHistoryLimit = revisionHistoryLimit;
	v1beta2_stateful_set_spec_local_var->selector = selector;
	v1beta2_stateful_set_spec_local_var->serviceName = serviceName;
	v1beta2_stateful_set_spec_local_var->template = template;
	v1beta2_stateful_set_spec_local_var->updateStrategy = updateStrategy;
	v1beta2_stateful_set_spec_local_var->volumeClaimTemplates = volumeClaimTemplates;

	return v1beta2_stateful_set_spec_local_var;
}


void v1beta2_stateful_set_spec_free(v1beta2_stateful_set_spec_t *v1beta2_stateful_set_spec) {
    listEntry_t *listEntry;
    free(v1beta2_stateful_set_spec->podManagementPolicy);
    v1_label_selector_free(v1beta2_stateful_set_spec->selector);
    free(v1beta2_stateful_set_spec->serviceName);
    v1_pod_template_spec_free(v1beta2_stateful_set_spec->template);
    v1beta2_stateful_set_update_strategy_free(v1beta2_stateful_set_spec->updateStrategy);
	list_ForEach(listEntry, v1beta2_stateful_set_spec->volumeClaimTemplates) {
		v1_persistent_volume_claim_free(listEntry->data);
	}
	list_free(v1beta2_stateful_set_spec->volumeClaimTemplates);
	free(v1beta2_stateful_set_spec);
}

cJSON *v1beta2_stateful_set_spec_convertToJSON(v1beta2_stateful_set_spec_t *v1beta2_stateful_set_spec) {
	cJSON *item = cJSON_CreateObject();

	// v1beta2_stateful_set_spec->podManagementPolicy
    if(v1beta2_stateful_set_spec->podManagementPolicy) { 
    if(cJSON_AddStringToObject(item, "podManagementPolicy", v1beta2_stateful_set_spec->podManagementPolicy) == NULL) {
    goto fail; //String
    }
     } 


	// v1beta2_stateful_set_spec->replicas
    if(v1beta2_stateful_set_spec->replicas) { 
    if(cJSON_AddNumberToObject(item, "replicas", v1beta2_stateful_set_spec->replicas) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1beta2_stateful_set_spec->revisionHistoryLimit
    if(v1beta2_stateful_set_spec->revisionHistoryLimit) { 
    if(cJSON_AddNumberToObject(item, "revisionHistoryLimit", v1beta2_stateful_set_spec->revisionHistoryLimit) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1beta2_stateful_set_spec->selector
    if (!v1beta2_stateful_set_spec->selector) {
        goto fail;
    }
    
    cJSON *selector_local_JSON = v1_label_selector_convertToJSON(v1beta2_stateful_set_spec->selector);
    if(selector_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "selector", selector_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


	// v1beta2_stateful_set_spec->serviceName
    if (!v1beta2_stateful_set_spec->serviceName) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "serviceName", v1beta2_stateful_set_spec->serviceName) == NULL) {
    goto fail; //String
    }


	// v1beta2_stateful_set_spec->template
    if (!v1beta2_stateful_set_spec->template) {
        goto fail;
    }
    
    cJSON *template_local_JSON = v1_pod_template_spec_convertToJSON(v1beta2_stateful_set_spec->template);
    if(template_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "template", template_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


	// v1beta2_stateful_set_spec->updateStrategy
    if(v1beta2_stateful_set_spec->updateStrategy) { 
    cJSON *updateStrategy_local_JSON = v1beta2_stateful_set_update_strategy_convertToJSON(v1beta2_stateful_set_spec->updateStrategy);
    if(updateStrategy_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "updateStrategy", updateStrategy_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1beta2_stateful_set_spec->volumeClaimTemplates
    if(v1beta2_stateful_set_spec->volumeClaimTemplates) { 
    cJSON *volumeClaimTemplates = cJSON_AddArrayToObject(item, "volumeClaimTemplates");
    if(volumeClaimTemplates == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *volumeClaimTemplatesListEntry;
    if (v1beta2_stateful_set_spec->volumeClaimTemplates) {
    list_ForEach(volumeClaimTemplatesListEntry, v1beta2_stateful_set_spec->volumeClaimTemplates) {
    cJSON *itemLocal = v1_persistent_volume_claim_convertToJSON(volumeClaimTemplatesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(volumeClaimTemplates, itemLocal);
    }
    }
     } 

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1beta2_stateful_set_spec_t *v1beta2_stateful_set_spec_parseFromJSON(cJSON *v1beta2_stateful_set_specJSON){

    v1beta2_stateful_set_spec_t *v1beta2_stateful_set_spec_local_var = NULL;

    // v1beta2_stateful_set_spec->podManagementPolicy
    cJSON *podManagementPolicy = cJSON_GetObjectItemCaseSensitive(v1beta2_stateful_set_specJSON, "podManagementPolicy");
    if (podManagementPolicy) { 
    if(!cJSON_IsString(podManagementPolicy))
    {
    goto end; //String
    }
    }

    // v1beta2_stateful_set_spec->replicas
    cJSON *replicas = cJSON_GetObjectItemCaseSensitive(v1beta2_stateful_set_specJSON, "replicas");
    if (replicas) { 
    if(!cJSON_IsNumber(replicas))
    {
    goto end; //Numeric
    }
    }

    // v1beta2_stateful_set_spec->revisionHistoryLimit
    cJSON *revisionHistoryLimit = cJSON_GetObjectItemCaseSensitive(v1beta2_stateful_set_specJSON, "revisionHistoryLimit");
    if (revisionHistoryLimit) { 
    if(!cJSON_IsNumber(revisionHistoryLimit))
    {
    goto end; //Numeric
    }
    }

    // v1beta2_stateful_set_spec->selector
    cJSON *selector = cJSON_GetObjectItemCaseSensitive(v1beta2_stateful_set_specJSON, "selector");
    if (!selector) {
        goto end;
    }

    v1_label_selector_t *selector_local_nonprim = NULL;
    
    selector_local_nonprim = v1_label_selector_parseFromJSON(selector); //nonprimitive

    // v1beta2_stateful_set_spec->serviceName
    cJSON *serviceName = cJSON_GetObjectItemCaseSensitive(v1beta2_stateful_set_specJSON, "serviceName");
    if (!serviceName) {
        goto end;
    }

    
    if(!cJSON_IsString(serviceName))
    {
    goto end; //String
    }

    // v1beta2_stateful_set_spec->template
    cJSON *template = cJSON_GetObjectItemCaseSensitive(v1beta2_stateful_set_specJSON, "template");
    if (!template) {
        goto end;
    }

    v1_pod_template_spec_t *template_local_nonprim = NULL;
    
    template_local_nonprim = v1_pod_template_spec_parseFromJSON(template); //nonprimitive

    // v1beta2_stateful_set_spec->updateStrategy
    cJSON *updateStrategy = cJSON_GetObjectItemCaseSensitive(v1beta2_stateful_set_specJSON, "updateStrategy");
    v1beta2_stateful_set_update_strategy_t *updateStrategy_local_nonprim = NULL;
    if (updateStrategy) { 
    updateStrategy_local_nonprim = v1beta2_stateful_set_update_strategy_parseFromJSON(updateStrategy); //nonprimitive
    }

    // v1beta2_stateful_set_spec->volumeClaimTemplates
    cJSON *volumeClaimTemplates = cJSON_GetObjectItemCaseSensitive(v1beta2_stateful_set_specJSON, "volumeClaimTemplates");
    list_t *volumeClaimTemplatesList;
    if (volumeClaimTemplates) { 
    cJSON *volumeClaimTemplates_local_nonprimitive;
    if(!cJSON_IsArray(volumeClaimTemplates)){
        goto end; //nonprimitive container
    }

    volumeClaimTemplatesList = list_create();

    cJSON_ArrayForEach(volumeClaimTemplates_local_nonprimitive,volumeClaimTemplates )
    {
        if(!cJSON_IsObject(volumeClaimTemplates_local_nonprimitive)){
            goto end;
        }
        v1_persistent_volume_claim_t *volumeClaimTemplatesItem = v1_persistent_volume_claim_parseFromJSON(volumeClaimTemplates_local_nonprimitive);

        list_addElement(volumeClaimTemplatesList, volumeClaimTemplatesItem);
    }
    }


    v1beta2_stateful_set_spec_local_var = v1beta2_stateful_set_spec_create (
        podManagementPolicy ? strdup(podManagementPolicy->valuestring) : NULL,
        replicas ? replicas->valuedouble : 0,
        revisionHistoryLimit ? revisionHistoryLimit->valuedouble : 0,
        selector_local_nonprim,
        strdup(serviceName->valuestring),
        template_local_nonprim,
        updateStrategy ? updateStrategy_local_nonprim : NULL,
        volumeClaimTemplates ? volumeClaimTemplatesList : NULL
        );

    return v1beta2_stateful_set_spec_local_var;
end:
    return NULL;

}
