#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_endpoint_conditions.h"



v1alpha1_endpoint_conditions_t *v1alpha1_endpoint_conditions_create(
    int ready
    ) {
	v1alpha1_endpoint_conditions_t *v1alpha1_endpoint_conditions_local_var = malloc(sizeof(v1alpha1_endpoint_conditions_t));
    if (!v1alpha1_endpoint_conditions_local_var) {
        return NULL;
    }
	v1alpha1_endpoint_conditions_local_var->ready = ready;

	return v1alpha1_endpoint_conditions_local_var;
}


void v1alpha1_endpoint_conditions_free(v1alpha1_endpoint_conditions_t *v1alpha1_endpoint_conditions) {
    listEntry_t *listEntry;
	free(v1alpha1_endpoint_conditions);
}

cJSON *v1alpha1_endpoint_conditions_convertToJSON(v1alpha1_endpoint_conditions_t *v1alpha1_endpoint_conditions) {
	cJSON *item = cJSON_CreateObject();

	// v1alpha1_endpoint_conditions->ready
    if(v1alpha1_endpoint_conditions->ready) { 
    if(cJSON_AddBoolToObject(item, "ready", v1alpha1_endpoint_conditions->ready) == NULL) {
    goto fail; //Bool
    }
     } 

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1alpha1_endpoint_conditions_t *v1alpha1_endpoint_conditions_parseFromJSON(cJSON *v1alpha1_endpoint_conditionsJSON){

    v1alpha1_endpoint_conditions_t *v1alpha1_endpoint_conditions_local_var = NULL;

    // v1alpha1_endpoint_conditions->ready
    cJSON *ready = cJSON_GetObjectItemCaseSensitive(v1alpha1_endpoint_conditionsJSON, "ready");
    if (ready) { 
    if(!cJSON_IsBool(ready))
    {
    goto end; //Bool
    }
    }


    v1alpha1_endpoint_conditions_local_var = v1alpha1_endpoint_conditions_create (
        ready ? ready->valueint : 0
        );

    return v1alpha1_endpoint_conditions_local_var;
end:
    return NULL;

}
