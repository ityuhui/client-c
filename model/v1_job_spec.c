#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_job_spec.h"



v1_job_spec_t *v1_job_spec_create(
    long activeDeadlineSeconds,
    int backoffLimit,
    int completions,
    int manualSelector,
    int parallelism,
    v1_label_selector_t *selector,
    v1_pod_template_spec_t *template,
    int ttlSecondsAfterFinished
    ) {
	v1_job_spec_t *v1_job_spec_local_var = malloc(sizeof(v1_job_spec_t));
    if (!v1_job_spec_local_var) {
        return NULL;
    }
	v1_job_spec_local_var->activeDeadlineSeconds = activeDeadlineSeconds;
	v1_job_spec_local_var->backoffLimit = backoffLimit;
	v1_job_spec_local_var->completions = completions;
	v1_job_spec_local_var->manualSelector = manualSelector;
	v1_job_spec_local_var->parallelism = parallelism;
	v1_job_spec_local_var->selector = selector;
	v1_job_spec_local_var->template = template;
	v1_job_spec_local_var->ttlSecondsAfterFinished = ttlSecondsAfterFinished;

	return v1_job_spec_local_var;
}


void v1_job_spec_free(v1_job_spec_t *v1_job_spec) {
    listEntry_t *listEntry;
    v1_label_selector_free(v1_job_spec->selector);
    v1_pod_template_spec_free(v1_job_spec->template);
	free(v1_job_spec);
}

cJSON *v1_job_spec_convertToJSON(v1_job_spec_t *v1_job_spec) {
	cJSON *item = cJSON_CreateObject();

	// v1_job_spec->activeDeadlineSeconds
    if(v1_job_spec->activeDeadlineSeconds) { 
    if(cJSON_AddNumberToObject(item, "activeDeadlineSeconds", v1_job_spec->activeDeadlineSeconds) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1_job_spec->backoffLimit
    if(v1_job_spec->backoffLimit) { 
    if(cJSON_AddNumberToObject(item, "backoffLimit", v1_job_spec->backoffLimit) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1_job_spec->completions
    if(v1_job_spec->completions) { 
    if(cJSON_AddNumberToObject(item, "completions", v1_job_spec->completions) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1_job_spec->manualSelector
    if(v1_job_spec->manualSelector) { 
    if(cJSON_AddBoolToObject(item, "manualSelector", v1_job_spec->manualSelector) == NULL) {
    goto fail; //Bool
    }
     } 


	// v1_job_spec->parallelism
    if(v1_job_spec->parallelism) { 
    if(cJSON_AddNumberToObject(item, "parallelism", v1_job_spec->parallelism) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1_job_spec->selector
    if(v1_job_spec->selector) { 
    cJSON *selector_local_JSON = v1_label_selector_convertToJSON(v1_job_spec->selector);
    if(selector_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "selector", selector_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_job_spec->template
    if (!v1_job_spec->template) {
        goto fail;
    }
    
    cJSON *template_local_JSON = v1_pod_template_spec_convertToJSON(v1_job_spec->template);
    if(template_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "template", template_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


	// v1_job_spec->ttlSecondsAfterFinished
    if(v1_job_spec->ttlSecondsAfterFinished) { 
    if(cJSON_AddNumberToObject(item, "ttlSecondsAfterFinished", v1_job_spec->ttlSecondsAfterFinished) == NULL) {
    goto fail; //Numeric
    }
     } 

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1_job_spec_t *v1_job_spec_parseFromJSON(cJSON *v1_job_specJSON){

    v1_job_spec_t *v1_job_spec_local_var = NULL;

    // v1_job_spec->activeDeadlineSeconds
    cJSON *activeDeadlineSeconds = cJSON_GetObjectItemCaseSensitive(v1_job_specJSON, "activeDeadlineSeconds");
    if (activeDeadlineSeconds) { 
    if(!cJSON_IsNumber(activeDeadlineSeconds))
    {
    goto end; //Numeric
    }
    }

    // v1_job_spec->backoffLimit
    cJSON *backoffLimit = cJSON_GetObjectItemCaseSensitive(v1_job_specJSON, "backoffLimit");
    if (backoffLimit) { 
    if(!cJSON_IsNumber(backoffLimit))
    {
    goto end; //Numeric
    }
    }

    // v1_job_spec->completions
    cJSON *completions = cJSON_GetObjectItemCaseSensitive(v1_job_specJSON, "completions");
    if (completions) { 
    if(!cJSON_IsNumber(completions))
    {
    goto end; //Numeric
    }
    }

    // v1_job_spec->manualSelector
    cJSON *manualSelector = cJSON_GetObjectItemCaseSensitive(v1_job_specJSON, "manualSelector");
    if (manualSelector) { 
    if(!cJSON_IsBool(manualSelector))
    {
    goto end; //Bool
    }
    }

    // v1_job_spec->parallelism
    cJSON *parallelism = cJSON_GetObjectItemCaseSensitive(v1_job_specJSON, "parallelism");
    if (parallelism) { 
    if(!cJSON_IsNumber(parallelism))
    {
    goto end; //Numeric
    }
    }

    // v1_job_spec->selector
    cJSON *selector = cJSON_GetObjectItemCaseSensitive(v1_job_specJSON, "selector");
    v1_label_selector_t *selector_local_nonprim = NULL;
    if (selector) { 
    selector_local_nonprim = v1_label_selector_parseFromJSON(selector); //nonprimitive
    }

    // v1_job_spec->template
    cJSON *template = cJSON_GetObjectItemCaseSensitive(v1_job_specJSON, "template");
    if (!template) {
        goto end;
    }

    v1_pod_template_spec_t *template_local_nonprim = NULL;
    
    template_local_nonprim = v1_pod_template_spec_parseFromJSON(template); //nonprimitive

    // v1_job_spec->ttlSecondsAfterFinished
    cJSON *ttlSecondsAfterFinished = cJSON_GetObjectItemCaseSensitive(v1_job_specJSON, "ttlSecondsAfterFinished");
    if (ttlSecondsAfterFinished) { 
    if(!cJSON_IsNumber(ttlSecondsAfterFinished))
    {
    goto end; //Numeric
    }
    }


    v1_job_spec_local_var = v1_job_spec_create (
        activeDeadlineSeconds ? activeDeadlineSeconds->valuedouble : 0,
        backoffLimit ? backoffLimit->valuedouble : 0,
        completions ? completions->valuedouble : 0,
        manualSelector ? manualSelector->valueint : 0,
        parallelism ? parallelism->valuedouble : 0,
        selector ? selector_local_nonprim : NULL,
        template_local_nonprim,
        ttlSecondsAfterFinished ? ttlSecondsAfterFinished->valuedouble : 0
        );

    return v1_job_spec_local_var;
end:
    return NULL;

}
