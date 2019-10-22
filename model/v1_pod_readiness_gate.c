#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_pod_readiness_gate.h"



v1_pod_readiness_gate_t *v1_pod_readiness_gate_create(
    char *conditionType
    ) {
	v1_pod_readiness_gate_t *v1_pod_readiness_gate_local_var = malloc(sizeof(v1_pod_readiness_gate_t));
    if (!v1_pod_readiness_gate_local_var) {
        return NULL;
    }
	v1_pod_readiness_gate_local_var->conditionType = conditionType;

	return v1_pod_readiness_gate_local_var;
}


void v1_pod_readiness_gate_free(v1_pod_readiness_gate_t *v1_pod_readiness_gate) {
    listEntry_t *listEntry;
    free(v1_pod_readiness_gate->conditionType);
	free(v1_pod_readiness_gate);
}

cJSON *v1_pod_readiness_gate_convertToJSON(v1_pod_readiness_gate_t *v1_pod_readiness_gate) {
	cJSON *item = cJSON_CreateObject();

	// v1_pod_readiness_gate->conditionType
    if (!v1_pod_readiness_gate->conditionType) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "conditionType", v1_pod_readiness_gate->conditionType) == NULL) {
    goto fail; //String
    }

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1_pod_readiness_gate_t *v1_pod_readiness_gate_parseFromJSON(cJSON *v1_pod_readiness_gateJSON){

    v1_pod_readiness_gate_t *v1_pod_readiness_gate_local_var = NULL;

    // v1_pod_readiness_gate->conditionType
    cJSON *conditionType = cJSON_GetObjectItemCaseSensitive(v1_pod_readiness_gateJSON, "conditionType");
    if (!conditionType) {
        goto end;
    }

    
    if(!cJSON_IsString(conditionType))
    {
    goto end; //String
    }


    v1_pod_readiness_gate_local_var = v1_pod_readiness_gate_create (
        strdup(conditionType->valuestring)
        );

    return v1_pod_readiness_gate_local_var;
end:
    return NULL;

}
