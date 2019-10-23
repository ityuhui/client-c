#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_pod_disruption_budget_status.h"



v1beta1_pod_disruption_budget_status_t *v1beta1_pod_disruption_budget_status_create(
    int currentHealthy,
    int desiredHealthy,
    list_t* disruptedPods,
    int disruptionsAllowed,
    int expectedPods,
    long observedGeneration
    ) {
	v1beta1_pod_disruption_budget_status_t *v1beta1_pod_disruption_budget_status_local_var = malloc(sizeof(v1beta1_pod_disruption_budget_status_t));
    if (!v1beta1_pod_disruption_budget_status_local_var) {
        return NULL;
    }
	v1beta1_pod_disruption_budget_status_local_var->currentHealthy = currentHealthy;
	v1beta1_pod_disruption_budget_status_local_var->desiredHealthy = desiredHealthy;
	v1beta1_pod_disruption_budget_status_local_var->disruptedPods = disruptedPods;
	v1beta1_pod_disruption_budget_status_local_var->disruptionsAllowed = disruptionsAllowed;
	v1beta1_pod_disruption_budget_status_local_var->expectedPods = expectedPods;
	v1beta1_pod_disruption_budget_status_local_var->observedGeneration = observedGeneration;

	return v1beta1_pod_disruption_budget_status_local_var;
}


void v1beta1_pod_disruption_budget_status_free(v1beta1_pod_disruption_budget_status_t *v1beta1_pod_disruption_budget_status) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, v1beta1_pod_disruption_budget_status->disruptedPods) {
		keyValuePair_t *localMapKeyPair = (keyValuePair_t*) listEntry->data;
        free (localMapKeyPair->key);
        free (localMapKeyPair->value);
	}
	list_free(v1beta1_pod_disruption_budget_status->disruptedPods);
	free(v1beta1_pod_disruption_budget_status);
}

cJSON *v1beta1_pod_disruption_budget_status_convertToJSON(v1beta1_pod_disruption_budget_status_t *v1beta1_pod_disruption_budget_status) {
	cJSON *item = cJSON_CreateObject();

	// v1beta1_pod_disruption_budget_status->currentHealthy
    if (!v1beta1_pod_disruption_budget_status->currentHealthy) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "currentHealthy", v1beta1_pod_disruption_budget_status->currentHealthy) == NULL) {
    goto fail; //Numeric
    }


	// v1beta1_pod_disruption_budget_status->desiredHealthy
    if (!v1beta1_pod_disruption_budget_status->desiredHealthy) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "desiredHealthy", v1beta1_pod_disruption_budget_status->desiredHealthy) == NULL) {
    goto fail; //Numeric
    }


	// v1beta1_pod_disruption_budget_status->disruptedPods
    if(v1beta1_pod_disruption_budget_status->disruptedPods) { 
	cJSON *disruptedPods = cJSON_AddObjectToObject(item, "disruptedPods");
	if(disruptedPods == NULL) {
		goto fail; //primitive map container
	}
    cJSON *localMapObject = cJSON_CreateObject(); //Memory free to be implemented in user code
	listEntry_t *disruptedPodsListEntry;
    if (v1beta1_pod_disruption_budget_status->disruptedPods) {
    list_ForEach(disruptedPodsListEntry, v1beta1_pod_disruption_budget_status->disruptedPods) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)disruptedPodsListEntry->data;
        if(cJSON_AddNumberToObject(localMapObject, localKeyValue->key, *(double *)localKeyValue->value) == NULL)
        {
            goto fail;
        }
        cJSON_AddItemToObject(disruptedPods,"", localMapObject);
    }
    }
     } 


	// v1beta1_pod_disruption_budget_status->disruptionsAllowed
    if (!v1beta1_pod_disruption_budget_status->disruptionsAllowed) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "disruptionsAllowed", v1beta1_pod_disruption_budget_status->disruptionsAllowed) == NULL) {
    goto fail; //Numeric
    }


	// v1beta1_pod_disruption_budget_status->expectedPods
    if (!v1beta1_pod_disruption_budget_status->expectedPods) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "expectedPods", v1beta1_pod_disruption_budget_status->expectedPods) == NULL) {
    goto fail; //Numeric
    }


	// v1beta1_pod_disruption_budget_status->observedGeneration
    if(v1beta1_pod_disruption_budget_status->observedGeneration) { 
    if(cJSON_AddNumberToObject(item, "observedGeneration", v1beta1_pod_disruption_budget_status->observedGeneration) == NULL) {
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

v1beta1_pod_disruption_budget_status_t *v1beta1_pod_disruption_budget_status_parseFromJSON(cJSON *v1beta1_pod_disruption_budget_statusJSON){

    v1beta1_pod_disruption_budget_status_t *v1beta1_pod_disruption_budget_status_local_var = NULL;

    // v1beta1_pod_disruption_budget_status->currentHealthy
    cJSON *currentHealthy = cJSON_GetObjectItemCaseSensitive(v1beta1_pod_disruption_budget_statusJSON, "currentHealthy");
    if (!currentHealthy) {
        goto end;
    }

    
    if(!cJSON_IsNumber(currentHealthy))
    {
    goto end; //Numeric
    }

    // v1beta1_pod_disruption_budget_status->desiredHealthy
    cJSON *desiredHealthy = cJSON_GetObjectItemCaseSensitive(v1beta1_pod_disruption_budget_statusJSON, "desiredHealthy");
    if (!desiredHealthy) {
        goto end;
    }

    
    if(!cJSON_IsNumber(desiredHealthy))
    {
    goto end; //Numeric
    }

    // v1beta1_pod_disruption_budget_status->disruptedPods
    cJSON *disruptedPods = cJSON_GetObjectItemCaseSensitive(v1beta1_pod_disruption_budget_statusJSON, "disruptedPods");
    list_t *List;
    if (disruptedPods) { 
    cJSON *_local_map;
    if(!cJSON_IsObject(disruptedPods)) {
        goto end;//primitive map container
    }
    List = list_create();
    keyValuePair_t *localMapKeyPair;
    cJSON_ArrayForEach(_local_map, disruptedPods)
    {
        if(!cJSON_IsNumber(_local_map))
        {
            goto end;
        }
        localMapKeyPair = keyValuePair_create(strdup(_local_map->string),&_local_map->valuedouble );
        list_addElement(List , localMapKeyPair);
    }
    }

    // v1beta1_pod_disruption_budget_status->disruptionsAllowed
    cJSON *disruptionsAllowed = cJSON_GetObjectItemCaseSensitive(v1beta1_pod_disruption_budget_statusJSON, "disruptionsAllowed");
    if (!disruptionsAllowed) {
        goto end;
    }

    
    if(!cJSON_IsNumber(disruptionsAllowed))
    {
    goto end; //Numeric
    }

    // v1beta1_pod_disruption_budget_status->expectedPods
    cJSON *expectedPods = cJSON_GetObjectItemCaseSensitive(v1beta1_pod_disruption_budget_statusJSON, "expectedPods");
    if (!expectedPods) {
        goto end;
    }

    
    if(!cJSON_IsNumber(expectedPods))
    {
    goto end; //Numeric
    }

    // v1beta1_pod_disruption_budget_status->observedGeneration
    cJSON *observedGeneration = cJSON_GetObjectItemCaseSensitive(v1beta1_pod_disruption_budget_statusJSON, "observedGeneration");
    if (observedGeneration) { 
    if(!cJSON_IsNumber(observedGeneration))
    {
    goto end; //Numeric
    }
    }


    v1beta1_pod_disruption_budget_status_local_var = v1beta1_pod_disruption_budget_status_create (
        currentHealthy->valuedouble,
        desiredHealthy->valuedouble,
        disruptedPods ? List : NULL,
        disruptionsAllowed->valuedouble,
        expectedPods->valuedouble,
        observedGeneration ? observedGeneration->valuedouble : 0
        );

    return v1beta1_pod_disruption_budget_status_local_var;
end:
    return NULL;

}
