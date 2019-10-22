#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_network_policy_spec.h"



v1beta1_network_policy_spec_t *v1beta1_network_policy_spec_create(
    list_t *egress,
    list_t *ingress,
    v1_label_selector_t *podSelector,
    list_t *policyTypes
    ) {
	v1beta1_network_policy_spec_t *v1beta1_network_policy_spec_local_var = malloc(sizeof(v1beta1_network_policy_spec_t));
    if (!v1beta1_network_policy_spec_local_var) {
        return NULL;
    }
	v1beta1_network_policy_spec_local_var->egress = egress;
	v1beta1_network_policy_spec_local_var->ingress = ingress;
	v1beta1_network_policy_spec_local_var->podSelector = podSelector;
	v1beta1_network_policy_spec_local_var->policyTypes = policyTypes;

	return v1beta1_network_policy_spec_local_var;
}


void v1beta1_network_policy_spec_free(v1beta1_network_policy_spec_t *v1beta1_network_policy_spec) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, v1beta1_network_policy_spec->egress) {
		v1beta1_network_policy_egress_rule_free(listEntry->data);
	}
	list_free(v1beta1_network_policy_spec->egress);
	list_ForEach(listEntry, v1beta1_network_policy_spec->ingress) {
		v1beta1_network_policy_ingress_rule_free(listEntry->data);
	}
	list_free(v1beta1_network_policy_spec->ingress);
    v1_label_selector_free(v1beta1_network_policy_spec->podSelector);
	list_ForEach(listEntry, v1beta1_network_policy_spec->policyTypes) {
		free(listEntry->data);
	}
	list_free(v1beta1_network_policy_spec->policyTypes);
	free(v1beta1_network_policy_spec);
}

cJSON *v1beta1_network_policy_spec_convertToJSON(v1beta1_network_policy_spec_t *v1beta1_network_policy_spec) {
	cJSON *item = cJSON_CreateObject();

	// v1beta1_network_policy_spec->egress
    if(v1beta1_network_policy_spec->egress) { 
    cJSON *egress = cJSON_AddArrayToObject(item, "egress");
    if(egress == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *egressListEntry;
    if (v1beta1_network_policy_spec->egress) {
    list_ForEach(egressListEntry, v1beta1_network_policy_spec->egress) {
    cJSON *itemLocal = v1beta1_network_policy_egress_rule_convertToJSON(egressListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(egress, itemLocal);
    }
    }
     } 


	// v1beta1_network_policy_spec->ingress
    if(v1beta1_network_policy_spec->ingress) { 
    cJSON *ingress = cJSON_AddArrayToObject(item, "ingress");
    if(ingress == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *ingressListEntry;
    if (v1beta1_network_policy_spec->ingress) {
    list_ForEach(ingressListEntry, v1beta1_network_policy_spec->ingress) {
    cJSON *itemLocal = v1beta1_network_policy_ingress_rule_convertToJSON(ingressListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(ingress, itemLocal);
    }
    }
     } 


	// v1beta1_network_policy_spec->podSelector
    if (!v1beta1_network_policy_spec->podSelector) {
        goto fail;
    }
    
    cJSON *podSelector_local_JSON = v1_label_selector_convertToJSON(v1beta1_network_policy_spec->podSelector);
    if(podSelector_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "podSelector", podSelector_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


	// v1beta1_network_policy_spec->policyTypes
    if(v1beta1_network_policy_spec->policyTypes) { 
	cJSON *policy_types = cJSON_AddArrayToObject(item, "policyTypes");
	if(policy_types == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *policy_typesListEntry;
    list_ForEach(policy_typesListEntry, v1beta1_network_policy_spec->policyTypes) {
    if(cJSON_AddStringToObject(policy_types, "", (char*)policy_typesListEntry->data) == NULL)
    {
        goto fail;
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

v1beta1_network_policy_spec_t *v1beta1_network_policy_spec_parseFromJSON(cJSON *v1beta1_network_policy_specJSON){

    v1beta1_network_policy_spec_t *v1beta1_network_policy_spec_local_var = NULL;

    // v1beta1_network_policy_spec->egress
    cJSON *egress = cJSON_GetObjectItemCaseSensitive(v1beta1_network_policy_specJSON, "egress");
    list_t *egressList;
    if (egress) { 
    cJSON *egress_local_nonprimitive;
    if(!cJSON_IsArray(egress)){
        goto end; //nonprimitive container
    }

    egressList = list_create();

    cJSON_ArrayForEach(egress_local_nonprimitive,egress )
    {
        if(!cJSON_IsObject(egress_local_nonprimitive)){
            goto end;
        }
        v1beta1_network_policy_egress_rule_t *egressItem = v1beta1_network_policy_egress_rule_parseFromJSON(egress_local_nonprimitive);

        list_addElement(egressList, egressItem);
    }
    }

    // v1beta1_network_policy_spec->ingress
    cJSON *ingress = cJSON_GetObjectItemCaseSensitive(v1beta1_network_policy_specJSON, "ingress");
    list_t *ingressList;
    if (ingress) { 
    cJSON *ingress_local_nonprimitive;
    if(!cJSON_IsArray(ingress)){
        goto end; //nonprimitive container
    }

    ingressList = list_create();

    cJSON_ArrayForEach(ingress_local_nonprimitive,ingress )
    {
        if(!cJSON_IsObject(ingress_local_nonprimitive)){
            goto end;
        }
        v1beta1_network_policy_ingress_rule_t *ingressItem = v1beta1_network_policy_ingress_rule_parseFromJSON(ingress_local_nonprimitive);

        list_addElement(ingressList, ingressItem);
    }
    }

    // v1beta1_network_policy_spec->podSelector
    cJSON *podSelector = cJSON_GetObjectItemCaseSensitive(v1beta1_network_policy_specJSON, "podSelector");
    if (!podSelector) {
        goto end;
    }

    v1_label_selector_t *podSelector_local_nonprim = NULL;
    
    podSelector_local_nonprim = v1_label_selector_parseFromJSON(podSelector); //nonprimitive

    // v1beta1_network_policy_spec->policyTypes
    cJSON *policyTypes = cJSON_GetObjectItemCaseSensitive(v1beta1_network_policy_specJSON, "policyTypes");
    list_t *policy_typesList;
    if (policyTypes) { 
    cJSON *policy_types_local;
    if(!cJSON_IsArray(policyTypes)) {
        goto end;//primitive container
    }
    policy_typesList = list_create();

    cJSON_ArrayForEach(policy_types_local, policyTypes)
    {
        if(!cJSON_IsString(policy_types_local))
        {
            goto end;
        }
        list_addElement(policy_typesList , strdup(policy_types_local->valuestring));
    }
    }


    v1beta1_network_policy_spec_local_var = v1beta1_network_policy_spec_create (
        egress ? egressList : NULL,
        ingress ? ingressList : NULL,
        podSelector_local_nonprim,
        policyTypes ? policy_typesList : NULL
        );

    return v1beta1_network_policy_spec_local_var;
end:
    return NULL;

}
