#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_topology_spread_constraint.h"



v1_topology_spread_constraint_t *v1_topology_spread_constraint_create(
    v1_label_selector_t *labelSelector,
    int maxSkew,
    char *topologyKey,
    char *whenUnsatisfiable
    ) {
	v1_topology_spread_constraint_t *v1_topology_spread_constraint_local_var = malloc(sizeof(v1_topology_spread_constraint_t));
    if (!v1_topology_spread_constraint_local_var) {
        return NULL;
    }
	v1_topology_spread_constraint_local_var->labelSelector = labelSelector;
	v1_topology_spread_constraint_local_var->maxSkew = maxSkew;
	v1_topology_spread_constraint_local_var->topologyKey = topologyKey;
	v1_topology_spread_constraint_local_var->whenUnsatisfiable = whenUnsatisfiable;

	return v1_topology_spread_constraint_local_var;
}


void v1_topology_spread_constraint_free(v1_topology_spread_constraint_t *v1_topology_spread_constraint) {
    listEntry_t *listEntry;
    v1_label_selector_free(v1_topology_spread_constraint->labelSelector);
    free(v1_topology_spread_constraint->topologyKey);
    free(v1_topology_spread_constraint->whenUnsatisfiable);
	free(v1_topology_spread_constraint);
}

cJSON *v1_topology_spread_constraint_convertToJSON(v1_topology_spread_constraint_t *v1_topology_spread_constraint) {
	cJSON *item = cJSON_CreateObject();

	// v1_topology_spread_constraint->labelSelector
    if(v1_topology_spread_constraint->labelSelector) { 
    cJSON *labelSelector_local_JSON = v1_label_selector_convertToJSON(v1_topology_spread_constraint->labelSelector);
    if(labelSelector_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "labelSelector", labelSelector_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_topology_spread_constraint->maxSkew
    if (!v1_topology_spread_constraint->maxSkew) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "maxSkew", v1_topology_spread_constraint->maxSkew) == NULL) {
    goto fail; //Numeric
    }


	// v1_topology_spread_constraint->topologyKey
    if (!v1_topology_spread_constraint->topologyKey) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "topologyKey", v1_topology_spread_constraint->topologyKey) == NULL) {
    goto fail; //String
    }


	// v1_topology_spread_constraint->whenUnsatisfiable
    if (!v1_topology_spread_constraint->whenUnsatisfiable) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "whenUnsatisfiable", v1_topology_spread_constraint->whenUnsatisfiable) == NULL) {
    goto fail; //String
    }

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1_topology_spread_constraint_t *v1_topology_spread_constraint_parseFromJSON(cJSON *v1_topology_spread_constraintJSON){

    v1_topology_spread_constraint_t *v1_topology_spread_constraint_local_var = NULL;

    // v1_topology_spread_constraint->labelSelector
    cJSON *labelSelector = cJSON_GetObjectItemCaseSensitive(v1_topology_spread_constraintJSON, "labelSelector");
    v1_label_selector_t *labelSelector_local_nonprim = NULL;
    if (labelSelector) { 
    labelSelector_local_nonprim = v1_label_selector_parseFromJSON(labelSelector); //nonprimitive
    }

    // v1_topology_spread_constraint->maxSkew
    cJSON *maxSkew = cJSON_GetObjectItemCaseSensitive(v1_topology_spread_constraintJSON, "maxSkew");
    if (!maxSkew) {
        goto end;
    }

    
    if(!cJSON_IsNumber(maxSkew))
    {
    goto end; //Numeric
    }

    // v1_topology_spread_constraint->topologyKey
    cJSON *topologyKey = cJSON_GetObjectItemCaseSensitive(v1_topology_spread_constraintJSON, "topologyKey");
    if (!topologyKey) {
        goto end;
    }

    
    if(!cJSON_IsString(topologyKey))
    {
    goto end; //String
    }

    // v1_topology_spread_constraint->whenUnsatisfiable
    cJSON *whenUnsatisfiable = cJSON_GetObjectItemCaseSensitive(v1_topology_spread_constraintJSON, "whenUnsatisfiable");
    if (!whenUnsatisfiable) {
        goto end;
    }

    
    if(!cJSON_IsString(whenUnsatisfiable))
    {
    goto end; //String
    }


    v1_topology_spread_constraint_local_var = v1_topology_spread_constraint_create (
        labelSelector ? labelSelector_local_nonprim : NULL,
        maxSkew->valuedouble,
        strdup(topologyKey->valuestring),
        strdup(whenUnsatisfiable->valuestring)
        );

    return v1_topology_spread_constraint_local_var;
end:
    return NULL;

}
