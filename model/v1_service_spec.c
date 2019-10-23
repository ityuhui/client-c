#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_service_spec.h"



v1_service_spec_t *v1_service_spec_create(
    char *clusterIP,
    list_t *externalIPs,
    char *externalName,
    char *externalTrafficPolicy,
    int healthCheckNodePort,
    char *ipFamily,
    char *loadBalancerIP,
    list_t *loadBalancerSourceRanges,
    list_t *ports,
    int publishNotReadyAddresses,
    list_t* selector,
    char *sessionAffinity,
    v1_session_affinity_config_t *sessionAffinityConfig,
    char *type
    ) {
	v1_service_spec_t *v1_service_spec_local_var = malloc(sizeof(v1_service_spec_t));
    if (!v1_service_spec_local_var) {
        return NULL;
    }
	v1_service_spec_local_var->clusterIP = clusterIP;
	v1_service_spec_local_var->externalIPs = externalIPs;
	v1_service_spec_local_var->externalName = externalName;
	v1_service_spec_local_var->externalTrafficPolicy = externalTrafficPolicy;
	v1_service_spec_local_var->healthCheckNodePort = healthCheckNodePort;
	v1_service_spec_local_var->ipFamily = ipFamily;
	v1_service_spec_local_var->loadBalancerIP = loadBalancerIP;
	v1_service_spec_local_var->loadBalancerSourceRanges = loadBalancerSourceRanges;
	v1_service_spec_local_var->ports = ports;
	v1_service_spec_local_var->publishNotReadyAddresses = publishNotReadyAddresses;
	v1_service_spec_local_var->selector = selector;
	v1_service_spec_local_var->sessionAffinity = sessionAffinity;
	v1_service_spec_local_var->sessionAffinityConfig = sessionAffinityConfig;
	v1_service_spec_local_var->type = type;

	return v1_service_spec_local_var;
}


void v1_service_spec_free(v1_service_spec_t *v1_service_spec) {
    listEntry_t *listEntry;
    free(v1_service_spec->clusterIP);
	list_ForEach(listEntry, v1_service_spec->externalIPs) {
		free(listEntry->data);
	}
	list_free(v1_service_spec->externalIPs);
    free(v1_service_spec->externalName);
    free(v1_service_spec->externalTrafficPolicy);
    free(v1_service_spec->ipFamily);
    free(v1_service_spec->loadBalancerIP);
	list_ForEach(listEntry, v1_service_spec->loadBalancerSourceRanges) {
		free(listEntry->data);
	}
	list_free(v1_service_spec->loadBalancerSourceRanges);
	list_ForEach(listEntry, v1_service_spec->ports) {
		v1_service_port_free(listEntry->data);
	}
	list_free(v1_service_spec->ports);
	list_ForEach(listEntry, v1_service_spec->selector) {
		keyValuePair_t *localMapKeyPair = (keyValuePair_t*) listEntry->data;
        free (localMapKeyPair->key);
        free (localMapKeyPair->value);
	}
	list_free(v1_service_spec->selector);
    free(v1_service_spec->sessionAffinity);
    v1_session_affinity_config_free(v1_service_spec->sessionAffinityConfig);
    free(v1_service_spec->type);
	free(v1_service_spec);
}

cJSON *v1_service_spec_convertToJSON(v1_service_spec_t *v1_service_spec) {
	cJSON *item = cJSON_CreateObject();

	// v1_service_spec->clusterIP
    if(v1_service_spec->clusterIP) { 
    if(cJSON_AddStringToObject(item, "clusterIP", v1_service_spec->clusterIP) == NULL) {
    goto fail; //String
    }
     } 


	// v1_service_spec->externalIPs
    if(v1_service_spec->externalIPs) { 
	cJSON *external_i_ps = cJSON_AddArrayToObject(item, "externalIPs");
	if(external_i_ps == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *external_i_psListEntry;
    list_ForEach(external_i_psListEntry, v1_service_spec->externalIPs) {
    if(cJSON_AddStringToObject(external_i_ps, "", (char*)external_i_psListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


	// v1_service_spec->externalName
    if(v1_service_spec->externalName) { 
    if(cJSON_AddStringToObject(item, "externalName", v1_service_spec->externalName) == NULL) {
    goto fail; //String
    }
     } 


	// v1_service_spec->externalTrafficPolicy
    if(v1_service_spec->externalTrafficPolicy) { 
    if(cJSON_AddStringToObject(item, "externalTrafficPolicy", v1_service_spec->externalTrafficPolicy) == NULL) {
    goto fail; //String
    }
     } 


	// v1_service_spec->healthCheckNodePort
    if(v1_service_spec->healthCheckNodePort) { 
    if(cJSON_AddNumberToObject(item, "healthCheckNodePort", v1_service_spec->healthCheckNodePort) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1_service_spec->ipFamily
    if(v1_service_spec->ipFamily) { 
    if(cJSON_AddStringToObject(item, "ipFamily", v1_service_spec->ipFamily) == NULL) {
    goto fail; //String
    }
     } 


	// v1_service_spec->loadBalancerIP
    if(v1_service_spec->loadBalancerIP) { 
    if(cJSON_AddStringToObject(item, "loadBalancerIP", v1_service_spec->loadBalancerIP) == NULL) {
    goto fail; //String
    }
     } 


	// v1_service_spec->loadBalancerSourceRanges
    if(v1_service_spec->loadBalancerSourceRanges) { 
	cJSON *load_balancer_source_ranges = cJSON_AddArrayToObject(item, "loadBalancerSourceRanges");
	if(load_balancer_source_ranges == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *load_balancer_source_rangesListEntry;
    list_ForEach(load_balancer_source_rangesListEntry, v1_service_spec->loadBalancerSourceRanges) {
    if(cJSON_AddStringToObject(load_balancer_source_ranges, "", (char*)load_balancer_source_rangesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


	// v1_service_spec->ports
    if(v1_service_spec->ports) { 
    cJSON *ports = cJSON_AddArrayToObject(item, "ports");
    if(ports == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *portsListEntry;
    if (v1_service_spec->ports) {
    list_ForEach(portsListEntry, v1_service_spec->ports) {
    cJSON *itemLocal = v1_service_port_convertToJSON(portsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(ports, itemLocal);
    }
    }
     } 


	// v1_service_spec->publishNotReadyAddresses
    if(v1_service_spec->publishNotReadyAddresses) { 
    if(cJSON_AddBoolToObject(item, "publishNotReadyAddresses", v1_service_spec->publishNotReadyAddresses) == NULL) {
    goto fail; //Bool
    }
     } 


	// v1_service_spec->selector
    if(v1_service_spec->selector) { 
	cJSON *selector = cJSON_AddObjectToObject(item, "selector");
	if(selector == NULL) {
		goto fail; //primitive map container
	}
    cJSON *localMapObject = cJSON_CreateObject(); //Memory free to be implemented in user code
	listEntry_t *selectorListEntry;
    if (v1_service_spec->selector) {
    list_ForEach(selectorListEntry, v1_service_spec->selector) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)selectorListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
        cJSON_AddItemToObject(selector,"", localMapObject);
    }
    }
     } 


	// v1_service_spec->sessionAffinity
    if(v1_service_spec->sessionAffinity) { 
    if(cJSON_AddStringToObject(item, "sessionAffinity", v1_service_spec->sessionAffinity) == NULL) {
    goto fail; //String
    }
     } 


	// v1_service_spec->sessionAffinityConfig
    if(v1_service_spec->sessionAffinityConfig) { 
    cJSON *sessionAffinityConfig_local_JSON = v1_session_affinity_config_convertToJSON(v1_service_spec->sessionAffinityConfig);
    if(sessionAffinityConfig_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "sessionAffinityConfig", sessionAffinityConfig_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_service_spec->type
    if(v1_service_spec->type) { 
    if(cJSON_AddStringToObject(item, "type", v1_service_spec->type) == NULL) {
    goto fail; //String
    }
     } 

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1_service_spec_t *v1_service_spec_parseFromJSON(cJSON *v1_service_specJSON){

    v1_service_spec_t *v1_service_spec_local_var = NULL;

    // v1_service_spec->clusterIP
    cJSON *clusterIP = cJSON_GetObjectItemCaseSensitive(v1_service_specJSON, "clusterIP");
    if (clusterIP) { 
    if(!cJSON_IsString(clusterIP))
    {
    goto end; //String
    }
    }

    // v1_service_spec->externalIPs
    cJSON *externalIPs = cJSON_GetObjectItemCaseSensitive(v1_service_specJSON, "externalIPs");
    list_t *external_i_psList;
    if (externalIPs) { 
    cJSON *external_i_ps_local;
    if(!cJSON_IsArray(externalIPs)) {
        goto end;//primitive container
    }
    external_i_psList = list_create();

    cJSON_ArrayForEach(external_i_ps_local, externalIPs)
    {
        if(!cJSON_IsString(external_i_ps_local))
        {
            goto end;
        }
        list_addElement(external_i_psList , strdup(external_i_ps_local->valuestring));
    }
    }

    // v1_service_spec->externalName
    cJSON *externalName = cJSON_GetObjectItemCaseSensitive(v1_service_specJSON, "externalName");
    if (externalName) { 
    if(!cJSON_IsString(externalName))
    {
    goto end; //String
    }
    }

    // v1_service_spec->externalTrafficPolicy
    cJSON *externalTrafficPolicy = cJSON_GetObjectItemCaseSensitive(v1_service_specJSON, "externalTrafficPolicy");
    if (externalTrafficPolicy) { 
    if(!cJSON_IsString(externalTrafficPolicy))
    {
    goto end; //String
    }
    }

    // v1_service_spec->healthCheckNodePort
    cJSON *healthCheckNodePort = cJSON_GetObjectItemCaseSensitive(v1_service_specJSON, "healthCheckNodePort");
    if (healthCheckNodePort) { 
    if(!cJSON_IsNumber(healthCheckNodePort))
    {
    goto end; //Numeric
    }
    }

    // v1_service_spec->ipFamily
    cJSON *ipFamily = cJSON_GetObjectItemCaseSensitive(v1_service_specJSON, "ipFamily");
    if (ipFamily) { 
    if(!cJSON_IsString(ipFamily))
    {
    goto end; //String
    }
    }

    // v1_service_spec->loadBalancerIP
    cJSON *loadBalancerIP = cJSON_GetObjectItemCaseSensitive(v1_service_specJSON, "loadBalancerIP");
    if (loadBalancerIP) { 
    if(!cJSON_IsString(loadBalancerIP))
    {
    goto end; //String
    }
    }

    // v1_service_spec->loadBalancerSourceRanges
    cJSON *loadBalancerSourceRanges = cJSON_GetObjectItemCaseSensitive(v1_service_specJSON, "loadBalancerSourceRanges");
    list_t *load_balancer_source_rangesList;
    if (loadBalancerSourceRanges) { 
    cJSON *load_balancer_source_ranges_local;
    if(!cJSON_IsArray(loadBalancerSourceRanges)) {
        goto end;//primitive container
    }
    load_balancer_source_rangesList = list_create();

    cJSON_ArrayForEach(load_balancer_source_ranges_local, loadBalancerSourceRanges)
    {
        if(!cJSON_IsString(load_balancer_source_ranges_local))
        {
            goto end;
        }
        list_addElement(load_balancer_source_rangesList , strdup(load_balancer_source_ranges_local->valuestring));
    }
    }

    // v1_service_spec->ports
    cJSON *ports = cJSON_GetObjectItemCaseSensitive(v1_service_specJSON, "ports");
    list_t *portsList;
    if (ports) { 
    cJSON *ports_local_nonprimitive;
    if(!cJSON_IsArray(ports)){
        goto end; //nonprimitive container
    }

    portsList = list_create();

    cJSON_ArrayForEach(ports_local_nonprimitive,ports )
    {
        if(!cJSON_IsObject(ports_local_nonprimitive)){
            goto end;
        }
        v1_service_port_t *portsItem = v1_service_port_parseFromJSON(ports_local_nonprimitive);

        list_addElement(portsList, portsItem);
    }
    }

    // v1_service_spec->publishNotReadyAddresses
    cJSON *publishNotReadyAddresses = cJSON_GetObjectItemCaseSensitive(v1_service_specJSON, "publishNotReadyAddresses");
    if (publishNotReadyAddresses) { 
    if(!cJSON_IsBool(publishNotReadyAddresses))
    {
    goto end; //Bool
    }
    }

    // v1_service_spec->selector
    cJSON *selector = cJSON_GetObjectItemCaseSensitive(v1_service_specJSON, "selector");
    list_t *List;
    if (selector) { 
    cJSON *_local_map;
    if(!cJSON_IsObject(selector)) {
        goto end;//primitive map container
    }
    List = list_create();
    keyValuePair_t *localMapKeyPair;
    cJSON_ArrayForEach(_local_map, selector)
    {
        if(!cJSON_IsNumber(_local_map))
        {
            goto end;
        }
        localMapKeyPair = keyValuePair_create(strdup(_local_map->string),&_local_map->valuedouble );
        list_addElement(List , localMapKeyPair);
    }
    }

    // v1_service_spec->sessionAffinity
    cJSON *sessionAffinity = cJSON_GetObjectItemCaseSensitive(v1_service_specJSON, "sessionAffinity");
    if (sessionAffinity) { 
    if(!cJSON_IsString(sessionAffinity))
    {
    goto end; //String
    }
    }

    // v1_service_spec->sessionAffinityConfig
    cJSON *sessionAffinityConfig = cJSON_GetObjectItemCaseSensitive(v1_service_specJSON, "sessionAffinityConfig");
    v1_session_affinity_config_t *sessionAffinityConfig_local_nonprim = NULL;
    if (sessionAffinityConfig) { 
    sessionAffinityConfig_local_nonprim = v1_session_affinity_config_parseFromJSON(sessionAffinityConfig); //nonprimitive
    }

    // v1_service_spec->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(v1_service_specJSON, "type");
    if (type) { 
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }
    }


    v1_service_spec_local_var = v1_service_spec_create (
        clusterIP ? strdup(clusterIP->valuestring) : NULL,
        externalIPs ? external_i_psList : NULL,
        externalName ? strdup(externalName->valuestring) : NULL,
        externalTrafficPolicy ? strdup(externalTrafficPolicy->valuestring) : NULL,
        healthCheckNodePort ? healthCheckNodePort->valuedouble : 0,
        ipFamily ? strdup(ipFamily->valuestring) : NULL,
        loadBalancerIP ? strdup(loadBalancerIP->valuestring) : NULL,
        loadBalancerSourceRanges ? load_balancer_source_rangesList : NULL,
        ports ? portsList : NULL,
        publishNotReadyAddresses ? publishNotReadyAddresses->valueint : 0,
        selector ? List : NULL,
        sessionAffinity ? strdup(sessionAffinity->valuestring) : NULL,
        sessionAffinityConfig ? sessionAffinityConfig_local_nonprim : NULL,
        type ? strdup(type->valuestring) : NULL
        );

    return v1_service_spec_local_var;
end:
    return NULL;

}
