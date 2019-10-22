#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_node_spec.h"



v1_node_spec_t *v1_node_spec_create(
    v1_node_config_source_t *configSource,
    char *externalID,
    char *podCIDR,
    list_t *podCIDRs,
    char *providerID,
    list_t *taints,
    int unschedulable
    ) {
	v1_node_spec_t *v1_node_spec_local_var = malloc(sizeof(v1_node_spec_t));
    if (!v1_node_spec_local_var) {
        return NULL;
    }
	v1_node_spec_local_var->configSource = configSource;
	v1_node_spec_local_var->externalID = externalID;
	v1_node_spec_local_var->podCIDR = podCIDR;
	v1_node_spec_local_var->podCIDRs = podCIDRs;
	v1_node_spec_local_var->providerID = providerID;
	v1_node_spec_local_var->taints = taints;
	v1_node_spec_local_var->unschedulable = unschedulable;

	return v1_node_spec_local_var;
}


void v1_node_spec_free(v1_node_spec_t *v1_node_spec) {
    listEntry_t *listEntry;
    v1_node_config_source_free(v1_node_spec->configSource);
    free(v1_node_spec->externalID);
    free(v1_node_spec->podCIDR);
	list_ForEach(listEntry, v1_node_spec->podCIDRs) {
		free(listEntry->data);
	}
	list_free(v1_node_spec->podCIDRs);
    free(v1_node_spec->providerID);
	list_ForEach(listEntry, v1_node_spec->taints) {
		v1_taint_free(listEntry->data);
	}
	list_free(v1_node_spec->taints);
	free(v1_node_spec);
}

cJSON *v1_node_spec_convertToJSON(v1_node_spec_t *v1_node_spec) {
	cJSON *item = cJSON_CreateObject();

	// v1_node_spec->configSource
    if(v1_node_spec->configSource) { 
    cJSON *configSource_local_JSON = v1_node_config_source_convertToJSON(v1_node_spec->configSource);
    if(configSource_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "configSource", configSource_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_node_spec->externalID
    if(v1_node_spec->externalID) { 
    if(cJSON_AddStringToObject(item, "externalID", v1_node_spec->externalID) == NULL) {
    goto fail; //String
    }
     } 


	// v1_node_spec->podCIDR
    if(v1_node_spec->podCIDR) { 
    if(cJSON_AddStringToObject(item, "podCIDR", v1_node_spec->podCIDR) == NULL) {
    goto fail; //String
    }
     } 


	// v1_node_spec->podCIDRs
    if(v1_node_spec->podCIDRs) { 
	cJSON *pod_cid_rs = cJSON_AddArrayToObject(item, "podCIDRs");
	if(pod_cid_rs == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *pod_cid_rsListEntry;
    list_ForEach(pod_cid_rsListEntry, v1_node_spec->podCIDRs) {
    if(cJSON_AddStringToObject(pod_cid_rs, "", (char*)pod_cid_rsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


	// v1_node_spec->providerID
    if(v1_node_spec->providerID) { 
    if(cJSON_AddStringToObject(item, "providerID", v1_node_spec->providerID) == NULL) {
    goto fail; //String
    }
     } 


	// v1_node_spec->taints
    if(v1_node_spec->taints) { 
    cJSON *taints = cJSON_AddArrayToObject(item, "taints");
    if(taints == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *taintsListEntry;
    if (v1_node_spec->taints) {
    list_ForEach(taintsListEntry, v1_node_spec->taints) {
    cJSON *itemLocal = v1_taint_convertToJSON(taintsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(taints, itemLocal);
    }
    }
     } 


	// v1_node_spec->unschedulable
    if(v1_node_spec->unschedulable) { 
    if(cJSON_AddBoolToObject(item, "unschedulable", v1_node_spec->unschedulable) == NULL) {
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

v1_node_spec_t *v1_node_spec_parseFromJSON(cJSON *v1_node_specJSON){

    v1_node_spec_t *v1_node_spec_local_var = NULL;

    // v1_node_spec->configSource
    cJSON *configSource = cJSON_GetObjectItemCaseSensitive(v1_node_specJSON, "configSource");
    v1_node_config_source_t *configSource_local_nonprim = NULL;
    if (configSource) { 
    configSource_local_nonprim = v1_node_config_source_parseFromJSON(configSource); //nonprimitive
    }

    // v1_node_spec->externalID
    cJSON *externalID = cJSON_GetObjectItemCaseSensitive(v1_node_specJSON, "externalID");
    if (externalID) { 
    if(!cJSON_IsString(externalID))
    {
    goto end; //String
    }
    }

    // v1_node_spec->podCIDR
    cJSON *podCIDR = cJSON_GetObjectItemCaseSensitive(v1_node_specJSON, "podCIDR");
    if (podCIDR) { 
    if(!cJSON_IsString(podCIDR))
    {
    goto end; //String
    }
    }

    // v1_node_spec->podCIDRs
    cJSON *podCIDRs = cJSON_GetObjectItemCaseSensitive(v1_node_specJSON, "podCIDRs");
    list_t *pod_cid_rsList;
    if (podCIDRs) { 
    cJSON *pod_cid_rs_local;
    if(!cJSON_IsArray(podCIDRs)) {
        goto end;//primitive container
    }
    pod_cid_rsList = list_create();

    cJSON_ArrayForEach(pod_cid_rs_local, podCIDRs)
    {
        if(!cJSON_IsString(pod_cid_rs_local))
        {
            goto end;
        }
        list_addElement(pod_cid_rsList , strdup(pod_cid_rs_local->valuestring));
    }
    }

    // v1_node_spec->providerID
    cJSON *providerID = cJSON_GetObjectItemCaseSensitive(v1_node_specJSON, "providerID");
    if (providerID) { 
    if(!cJSON_IsString(providerID))
    {
    goto end; //String
    }
    }

    // v1_node_spec->taints
    cJSON *taints = cJSON_GetObjectItemCaseSensitive(v1_node_specJSON, "taints");
    list_t *taintsList;
    if (taints) { 
    cJSON *taints_local_nonprimitive;
    if(!cJSON_IsArray(taints)){
        goto end; //nonprimitive container
    }

    taintsList = list_create();

    cJSON_ArrayForEach(taints_local_nonprimitive,taints )
    {
        if(!cJSON_IsObject(taints_local_nonprimitive)){
            goto end;
        }
        v1_taint_t *taintsItem = v1_taint_parseFromJSON(taints_local_nonprimitive);

        list_addElement(taintsList, taintsItem);
    }
    }

    // v1_node_spec->unschedulable
    cJSON *unschedulable = cJSON_GetObjectItemCaseSensitive(v1_node_specJSON, "unschedulable");
    if (unschedulable) { 
    if(!cJSON_IsBool(unschedulable))
    {
    goto end; //Bool
    }
    }


    v1_node_spec_local_var = v1_node_spec_create (
        configSource ? configSource_local_nonprim : NULL,
        externalID ? strdup(externalID->valuestring) : NULL,
        podCIDR ? strdup(podCIDR->valuestring) : NULL,
        podCIDRs ? pod_cid_rsList : NULL,
        providerID ? strdup(providerID->valuestring) : NULL,
        taints ? taintsList : NULL,
        unschedulable ? unschedulable->valueint : 0
        );

    return v1_node_spec_local_var;
end:
    return NULL;

}
