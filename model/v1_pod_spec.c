#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_pod_spec.h"



v1_pod_spec_t *v1_pod_spec_create(
    long activeDeadlineSeconds,
    v1_affinity_t *affinity,
    int automountServiceAccountToken,
    list_t *containers,
    v1_pod_dns_config_t *dnsConfig,
    char *dnsPolicy,
    int enableServiceLinks,
    list_t *ephemeralContainers,
    list_t *hostAliases,
    int hostIPC,
    int hostNetwork,
    int hostPID,
    char *hostname,
    list_t *imagePullSecrets,
    list_t *initContainers,
    char *nodeName,
    list_t* nodeSelector,
    list_t* overhead,
    char *preemptionPolicy,
    int priority,
    char *priorityClassName,
    list_t *readinessGates,
    char *restartPolicy,
    char *runtimeClassName,
    char *schedulerName,
    v1_pod_security_context_t *securityContext,
    char *serviceAccount,
    char *serviceAccountName,
    int shareProcessNamespace,
    char *subdomain,
    long terminationGracePeriodSeconds,
    list_t *tolerations,
    list_t *topologySpreadConstraints,
    list_t *volumes
    ) {
	v1_pod_spec_t *v1_pod_spec_local_var = malloc(sizeof(v1_pod_spec_t));
    if (!v1_pod_spec_local_var) {
        return NULL;
    }
	v1_pod_spec_local_var->activeDeadlineSeconds = activeDeadlineSeconds;
	v1_pod_spec_local_var->affinity = affinity;
	v1_pod_spec_local_var->automountServiceAccountToken = automountServiceAccountToken;
	v1_pod_spec_local_var->containers = containers;
	v1_pod_spec_local_var->dnsConfig = dnsConfig;
	v1_pod_spec_local_var->dnsPolicy = dnsPolicy;
	v1_pod_spec_local_var->enableServiceLinks = enableServiceLinks;
	v1_pod_spec_local_var->ephemeralContainers = ephemeralContainers;
	v1_pod_spec_local_var->hostAliases = hostAliases;
	v1_pod_spec_local_var->hostIPC = hostIPC;
	v1_pod_spec_local_var->hostNetwork = hostNetwork;
	v1_pod_spec_local_var->hostPID = hostPID;
	v1_pod_spec_local_var->hostname = hostname;
	v1_pod_spec_local_var->imagePullSecrets = imagePullSecrets;
	v1_pod_spec_local_var->initContainers = initContainers;
	v1_pod_spec_local_var->nodeName = nodeName;
	v1_pod_spec_local_var->nodeSelector = nodeSelector;
	v1_pod_spec_local_var->overhead = overhead;
	v1_pod_spec_local_var->preemptionPolicy = preemptionPolicy;
	v1_pod_spec_local_var->priority = priority;
	v1_pod_spec_local_var->priorityClassName = priorityClassName;
	v1_pod_spec_local_var->readinessGates = readinessGates;
	v1_pod_spec_local_var->restartPolicy = restartPolicy;
	v1_pod_spec_local_var->runtimeClassName = runtimeClassName;
	v1_pod_spec_local_var->schedulerName = schedulerName;
	v1_pod_spec_local_var->securityContext = securityContext;
	v1_pod_spec_local_var->serviceAccount = serviceAccount;
	v1_pod_spec_local_var->serviceAccountName = serviceAccountName;
	v1_pod_spec_local_var->shareProcessNamespace = shareProcessNamespace;
	v1_pod_spec_local_var->subdomain = subdomain;
	v1_pod_spec_local_var->terminationGracePeriodSeconds = terminationGracePeriodSeconds;
	v1_pod_spec_local_var->tolerations = tolerations;
	v1_pod_spec_local_var->topologySpreadConstraints = topologySpreadConstraints;
	v1_pod_spec_local_var->volumes = volumes;

	return v1_pod_spec_local_var;
}


void v1_pod_spec_free(v1_pod_spec_t *v1_pod_spec) {
    listEntry_t *listEntry;
    v1_affinity_free(v1_pod_spec->affinity);
	list_ForEach(listEntry, v1_pod_spec->containers) {
		v1_container_free(listEntry->data);
	}
	list_free(v1_pod_spec->containers);
    v1_pod_dns_config_free(v1_pod_spec->dnsConfig);
    free(v1_pod_spec->dnsPolicy);
	list_ForEach(listEntry, v1_pod_spec->ephemeralContainers) {
		v1_ephemeral_container_free(listEntry->data);
	}
	list_free(v1_pod_spec->ephemeralContainers);
	list_ForEach(listEntry, v1_pod_spec->hostAliases) {
		v1_host_alias_free(listEntry->data);
	}
	list_free(v1_pod_spec->hostAliases);
    free(v1_pod_spec->hostname);
	list_ForEach(listEntry, v1_pod_spec->imagePullSecrets) {
		v1_local_object_reference_free(listEntry->data);
	}
	list_free(v1_pod_spec->imagePullSecrets);
	list_ForEach(listEntry, v1_pod_spec->initContainers) {
		v1_container_free(listEntry->data);
	}
	list_free(v1_pod_spec->initContainers);
    free(v1_pod_spec->nodeName);
	list_ForEach(listEntry, v1_pod_spec->nodeSelector) {
		keyValuePair_t *localMapKeyPair = (keyValuePair_t*) listEntry->data;
        free (localKeyValue->key);
        free (localKeyValue->value);
	}
	list_free(v1_pod_spec->nodeSelector);
	list_ForEach(listEntry, v1_pod_spec->overhead) {
		keyValuePair_t *localMapKeyPair = (keyValuePair_t*) listEntry->data;
        free (localKeyValue->key);
        free (localKeyValue->value);
	}
	list_free(v1_pod_spec->overhead);
    free(v1_pod_spec->preemptionPolicy);
    free(v1_pod_spec->priorityClassName);
	list_ForEach(listEntry, v1_pod_spec->readinessGates) {
		v1_pod_readiness_gate_free(listEntry->data);
	}
	list_free(v1_pod_spec->readinessGates);
    free(v1_pod_spec->restartPolicy);
    free(v1_pod_spec->runtimeClassName);
    free(v1_pod_spec->schedulerName);
    v1_pod_security_context_free(v1_pod_spec->securityContext);
    free(v1_pod_spec->serviceAccount);
    free(v1_pod_spec->serviceAccountName);
    free(v1_pod_spec->subdomain);
	list_ForEach(listEntry, v1_pod_spec->tolerations) {
		v1_toleration_free(listEntry->data);
	}
	list_free(v1_pod_spec->tolerations);
	list_ForEach(listEntry, v1_pod_spec->topologySpreadConstraints) {
		v1_topology_spread_constraint_free(listEntry->data);
	}
	list_free(v1_pod_spec->topologySpreadConstraints);
	list_ForEach(listEntry, v1_pod_spec->volumes) {
		v1_volume_free(listEntry->data);
	}
	list_free(v1_pod_spec->volumes);
	free(v1_pod_spec);
}

cJSON *v1_pod_spec_convertToJSON(v1_pod_spec_t *v1_pod_spec) {
	cJSON *item = cJSON_CreateObject();

	// v1_pod_spec->activeDeadlineSeconds
    if(v1_pod_spec->activeDeadlineSeconds) { 
    if(cJSON_AddNumberToObject(item, "activeDeadlineSeconds", v1_pod_spec->activeDeadlineSeconds) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1_pod_spec->affinity
    if(v1_pod_spec->affinity) { 
    cJSON *affinity_local_JSON = v1_affinity_convertToJSON(v1_pod_spec->affinity);
    if(affinity_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "affinity", affinity_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_pod_spec->automountServiceAccountToken
    if(v1_pod_spec->automountServiceAccountToken) { 
    if(cJSON_AddBoolToObject(item, "automountServiceAccountToken", v1_pod_spec->automountServiceAccountToken) == NULL) {
    goto fail; //Bool
    }
     } 


	// v1_pod_spec->containers
    if (!v1_pod_spec->containers) {
        goto fail;
    }
    
    cJSON *containers = cJSON_AddArrayToObject(item, "containers");
    if(containers == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *containersListEntry;
    if (v1_pod_spec->containers) {
    list_ForEach(containersListEntry, v1_pod_spec->containers) {
    cJSON *itemLocal = v1_container_convertToJSON(containersListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(containers, itemLocal);
    }
    }


	// v1_pod_spec->dnsConfig
    if(v1_pod_spec->dnsConfig) { 
    cJSON *dnsConfig_local_JSON = v1_pod_dns_config_convertToJSON(v1_pod_spec->dnsConfig);
    if(dnsConfig_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "dnsConfig", dnsConfig_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_pod_spec->dnsPolicy
    if(v1_pod_spec->dnsPolicy) { 
    if(cJSON_AddStringToObject(item, "dnsPolicy", v1_pod_spec->dnsPolicy) == NULL) {
    goto fail; //String
    }
     } 


	// v1_pod_spec->enableServiceLinks
    if(v1_pod_spec->enableServiceLinks) { 
    if(cJSON_AddBoolToObject(item, "enableServiceLinks", v1_pod_spec->enableServiceLinks) == NULL) {
    goto fail; //Bool
    }
     } 


	// v1_pod_spec->ephemeralContainers
    if(v1_pod_spec->ephemeralContainers) { 
    cJSON *ephemeralContainers = cJSON_AddArrayToObject(item, "ephemeralContainers");
    if(ephemeralContainers == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *ephemeralContainersListEntry;
    if (v1_pod_spec->ephemeralContainers) {
    list_ForEach(ephemeralContainersListEntry, v1_pod_spec->ephemeralContainers) {
    cJSON *itemLocal = v1_ephemeral_container_convertToJSON(ephemeralContainersListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(ephemeralContainers, itemLocal);
    }
    }
     } 


	// v1_pod_spec->hostAliases
    if(v1_pod_spec->hostAliases) { 
    cJSON *hostAliases = cJSON_AddArrayToObject(item, "hostAliases");
    if(hostAliases == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *hostAliasesListEntry;
    if (v1_pod_spec->hostAliases) {
    list_ForEach(hostAliasesListEntry, v1_pod_spec->hostAliases) {
    cJSON *itemLocal = v1_host_alias_convertToJSON(hostAliasesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(hostAliases, itemLocal);
    }
    }
     } 


	// v1_pod_spec->hostIPC
    if(v1_pod_spec->hostIPC) { 
    if(cJSON_AddBoolToObject(item, "hostIPC", v1_pod_spec->hostIPC) == NULL) {
    goto fail; //Bool
    }
     } 


	// v1_pod_spec->hostNetwork
    if(v1_pod_spec->hostNetwork) { 
    if(cJSON_AddBoolToObject(item, "hostNetwork", v1_pod_spec->hostNetwork) == NULL) {
    goto fail; //Bool
    }
     } 


	// v1_pod_spec->hostPID
    if(v1_pod_spec->hostPID) { 
    if(cJSON_AddBoolToObject(item, "hostPID", v1_pod_spec->hostPID) == NULL) {
    goto fail; //Bool
    }
     } 


	// v1_pod_spec->hostname
    if(v1_pod_spec->hostname) { 
    if(cJSON_AddStringToObject(item, "hostname", v1_pod_spec->hostname) == NULL) {
    goto fail; //String
    }
     } 


	// v1_pod_spec->imagePullSecrets
    if(v1_pod_spec->imagePullSecrets) { 
    cJSON *imagePullSecrets = cJSON_AddArrayToObject(item, "imagePullSecrets");
    if(imagePullSecrets == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *imagePullSecretsListEntry;
    if (v1_pod_spec->imagePullSecrets) {
    list_ForEach(imagePullSecretsListEntry, v1_pod_spec->imagePullSecrets) {
    cJSON *itemLocal = v1_local_object_reference_convertToJSON(imagePullSecretsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(imagePullSecrets, itemLocal);
    }
    }
     } 


	// v1_pod_spec->initContainers
    if(v1_pod_spec->initContainers) { 
    cJSON *initContainers = cJSON_AddArrayToObject(item, "initContainers");
    if(initContainers == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *initContainersListEntry;
    if (v1_pod_spec->initContainers) {
    list_ForEach(initContainersListEntry, v1_pod_spec->initContainers) {
    cJSON *itemLocal = v1_container_convertToJSON(initContainersListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(initContainers, itemLocal);
    }
    }
     } 


	// v1_pod_spec->nodeName
    if(v1_pod_spec->nodeName) { 
    if(cJSON_AddStringToObject(item, "nodeName", v1_pod_spec->nodeName) == NULL) {
    goto fail; //String
    }
     } 


	// v1_pod_spec->nodeSelector
    if(v1_pod_spec->nodeSelector) { 
	cJSON *nodeSelector = cJSON_AddObjectToObject(item, "nodeSelector");
	if(nodeSelector == NULL) {
		goto fail; //primitive map container
	}
    cJSON *localMapObject = cJSON_CreateObject(); //Memory free to be implemented in user code
	listEntry_t *nodeSelectorListEntry;
    if (v1_pod_spec->nodeSelector) {
    list_ForEach(nodeSelectorListEntry, v1_pod_spec->nodeSelector) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)nodeSelectorListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
        cJSON_AddItemToObject(nodeSelector,"", localMapObject);
    }
    }
     } 


	// v1_pod_spec->overhead
    if(v1_pod_spec->overhead) { 
	cJSON *overhead = cJSON_AddObjectToObject(item, "overhead");
	if(overhead == NULL) {
		goto fail; //primitive map container
	}
    cJSON *localMapObject = cJSON_CreateObject(); //Memory free to be implemented in user code
	listEntry_t *overheadListEntry;
    if (v1_pod_spec->overhead) {
    list_ForEach(overheadListEntry, v1_pod_spec->overhead) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)overheadListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
        cJSON_AddItemToObject(overhead,"", localMapObject);
    }
    }
     } 


	// v1_pod_spec->preemptionPolicy
    if(v1_pod_spec->preemptionPolicy) { 
    if(cJSON_AddStringToObject(item, "preemptionPolicy", v1_pod_spec->preemptionPolicy) == NULL) {
    goto fail; //String
    }
     } 


	// v1_pod_spec->priority
    if(v1_pod_spec->priority) { 
    if(cJSON_AddNumberToObject(item, "priority", v1_pod_spec->priority) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1_pod_spec->priorityClassName
    if(v1_pod_spec->priorityClassName) { 
    if(cJSON_AddStringToObject(item, "priorityClassName", v1_pod_spec->priorityClassName) == NULL) {
    goto fail; //String
    }
     } 


	// v1_pod_spec->readinessGates
    if(v1_pod_spec->readinessGates) { 
    cJSON *readinessGates = cJSON_AddArrayToObject(item, "readinessGates");
    if(readinessGates == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *readinessGatesListEntry;
    if (v1_pod_spec->readinessGates) {
    list_ForEach(readinessGatesListEntry, v1_pod_spec->readinessGates) {
    cJSON *itemLocal = v1_pod_readiness_gate_convertToJSON(readinessGatesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(readinessGates, itemLocal);
    }
    }
     } 


	// v1_pod_spec->restartPolicy
    if(v1_pod_spec->restartPolicy) { 
    if(cJSON_AddStringToObject(item, "restartPolicy", v1_pod_spec->restartPolicy) == NULL) {
    goto fail; //String
    }
     } 


	// v1_pod_spec->runtimeClassName
    if(v1_pod_spec->runtimeClassName) { 
    if(cJSON_AddStringToObject(item, "runtimeClassName", v1_pod_spec->runtimeClassName) == NULL) {
    goto fail; //String
    }
     } 


	// v1_pod_spec->schedulerName
    if(v1_pod_spec->schedulerName) { 
    if(cJSON_AddStringToObject(item, "schedulerName", v1_pod_spec->schedulerName) == NULL) {
    goto fail; //String
    }
     } 


	// v1_pod_spec->securityContext
    if(v1_pod_spec->securityContext) { 
    cJSON *securityContext_local_JSON = v1_pod_security_context_convertToJSON(v1_pod_spec->securityContext);
    if(securityContext_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "securityContext", securityContext_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_pod_spec->serviceAccount
    if(v1_pod_spec->serviceAccount) { 
    if(cJSON_AddStringToObject(item, "serviceAccount", v1_pod_spec->serviceAccount) == NULL) {
    goto fail; //String
    }
     } 


	// v1_pod_spec->serviceAccountName
    if(v1_pod_spec->serviceAccountName) { 
    if(cJSON_AddStringToObject(item, "serviceAccountName", v1_pod_spec->serviceAccountName) == NULL) {
    goto fail; //String
    }
     } 


	// v1_pod_spec->shareProcessNamespace
    if(v1_pod_spec->shareProcessNamespace) { 
    if(cJSON_AddBoolToObject(item, "shareProcessNamespace", v1_pod_spec->shareProcessNamespace) == NULL) {
    goto fail; //Bool
    }
     } 


	// v1_pod_spec->subdomain
    if(v1_pod_spec->subdomain) { 
    if(cJSON_AddStringToObject(item, "subdomain", v1_pod_spec->subdomain) == NULL) {
    goto fail; //String
    }
     } 


	// v1_pod_spec->terminationGracePeriodSeconds
    if(v1_pod_spec->terminationGracePeriodSeconds) { 
    if(cJSON_AddNumberToObject(item, "terminationGracePeriodSeconds", v1_pod_spec->terminationGracePeriodSeconds) == NULL) {
    goto fail; //Numeric
    }
     } 


	// v1_pod_spec->tolerations
    if(v1_pod_spec->tolerations) { 
    cJSON *tolerations = cJSON_AddArrayToObject(item, "tolerations");
    if(tolerations == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *tolerationsListEntry;
    if (v1_pod_spec->tolerations) {
    list_ForEach(tolerationsListEntry, v1_pod_spec->tolerations) {
    cJSON *itemLocal = v1_toleration_convertToJSON(tolerationsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(tolerations, itemLocal);
    }
    }
     } 


	// v1_pod_spec->topologySpreadConstraints
    if(v1_pod_spec->topologySpreadConstraints) { 
    cJSON *topologySpreadConstraints = cJSON_AddArrayToObject(item, "topologySpreadConstraints");
    if(topologySpreadConstraints == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *topologySpreadConstraintsListEntry;
    if (v1_pod_spec->topologySpreadConstraints) {
    list_ForEach(topologySpreadConstraintsListEntry, v1_pod_spec->topologySpreadConstraints) {
    cJSON *itemLocal = v1_topology_spread_constraint_convertToJSON(topologySpreadConstraintsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(topologySpreadConstraints, itemLocal);
    }
    }
     } 


	// v1_pod_spec->volumes
    if(v1_pod_spec->volumes) { 
    cJSON *volumes = cJSON_AddArrayToObject(item, "volumes");
    if(volumes == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *volumesListEntry;
    if (v1_pod_spec->volumes) {
    list_ForEach(volumesListEntry, v1_pod_spec->volumes) {
    cJSON *itemLocal = v1_volume_convertToJSON(volumesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(volumes, itemLocal);
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

v1_pod_spec_t *v1_pod_spec_parseFromJSON(cJSON *v1_pod_specJSON){

    v1_pod_spec_t *v1_pod_spec_local_var = NULL;

    // v1_pod_spec->activeDeadlineSeconds
    cJSON *activeDeadlineSeconds = cJSON_GetObjectItemCaseSensitive(v1_pod_specJSON, "activeDeadlineSeconds");
    if (activeDeadlineSeconds) { 
    if(!cJSON_IsNumber(activeDeadlineSeconds))
    {
    goto end; //Numeric
    }
    }

    // v1_pod_spec->affinity
    cJSON *affinity = cJSON_GetObjectItemCaseSensitive(v1_pod_specJSON, "affinity");
    v1_affinity_t *affinity_local_nonprim = NULL;
    if (affinity) { 
    affinity_local_nonprim = v1_affinity_parseFromJSON(affinity); //nonprimitive
    }

    // v1_pod_spec->automountServiceAccountToken
    cJSON *automountServiceAccountToken = cJSON_GetObjectItemCaseSensitive(v1_pod_specJSON, "automountServiceAccountToken");
    if (automountServiceAccountToken) { 
    if(!cJSON_IsBool(automountServiceAccountToken))
    {
    goto end; //Bool
    }
    }

    // v1_pod_spec->containers
    cJSON *containers = cJSON_GetObjectItemCaseSensitive(v1_pod_specJSON, "containers");
    if (!containers) {
        goto end;
    }

    list_t *containersList;
    
    cJSON *containers_local_nonprimitive;
    if(!cJSON_IsArray(containers)){
        goto end; //nonprimitive container
    }

    containersList = list_create();

    cJSON_ArrayForEach(containers_local_nonprimitive,containers )
    {
        if(!cJSON_IsObject(containers_local_nonprimitive)){
            goto end;
        }
        v1_container_t *containersItem = v1_container_parseFromJSON(containers_local_nonprimitive);

        list_addElement(containersList, containersItem);
    }

    // v1_pod_spec->dnsConfig
    cJSON *dnsConfig = cJSON_GetObjectItemCaseSensitive(v1_pod_specJSON, "dnsConfig");
    v1_pod_dns_config_t *dnsConfig_local_nonprim = NULL;
    if (dnsConfig) { 
    dnsConfig_local_nonprim = v1_pod_dns_config_parseFromJSON(dnsConfig); //nonprimitive
    }

    // v1_pod_spec->dnsPolicy
    cJSON *dnsPolicy = cJSON_GetObjectItemCaseSensitive(v1_pod_specJSON, "dnsPolicy");
    if (dnsPolicy) { 
    if(!cJSON_IsString(dnsPolicy))
    {
    goto end; //String
    }
    }

    // v1_pod_spec->enableServiceLinks
    cJSON *enableServiceLinks = cJSON_GetObjectItemCaseSensitive(v1_pod_specJSON, "enableServiceLinks");
    if (enableServiceLinks) { 
    if(!cJSON_IsBool(enableServiceLinks))
    {
    goto end; //Bool
    }
    }

    // v1_pod_spec->ephemeralContainers
    cJSON *ephemeralContainers = cJSON_GetObjectItemCaseSensitive(v1_pod_specJSON, "ephemeralContainers");
    list_t *ephemeralContainersList;
    if (ephemeralContainers) { 
    cJSON *ephemeralContainers_local_nonprimitive;
    if(!cJSON_IsArray(ephemeralContainers)){
        goto end; //nonprimitive container
    }

    ephemeralContainersList = list_create();

    cJSON_ArrayForEach(ephemeralContainers_local_nonprimitive,ephemeralContainers )
    {
        if(!cJSON_IsObject(ephemeralContainers_local_nonprimitive)){
            goto end;
        }
        v1_ephemeral_container_t *ephemeralContainersItem = v1_ephemeral_container_parseFromJSON(ephemeralContainers_local_nonprimitive);

        list_addElement(ephemeralContainersList, ephemeralContainersItem);
    }
    }

    // v1_pod_spec->hostAliases
    cJSON *hostAliases = cJSON_GetObjectItemCaseSensitive(v1_pod_specJSON, "hostAliases");
    list_t *hostAliasesList;
    if (hostAliases) { 
    cJSON *hostAliases_local_nonprimitive;
    if(!cJSON_IsArray(hostAliases)){
        goto end; //nonprimitive container
    }

    hostAliasesList = list_create();

    cJSON_ArrayForEach(hostAliases_local_nonprimitive,hostAliases )
    {
        if(!cJSON_IsObject(hostAliases_local_nonprimitive)){
            goto end;
        }
        v1_host_alias_t *hostAliasesItem = v1_host_alias_parseFromJSON(hostAliases_local_nonprimitive);

        list_addElement(hostAliasesList, hostAliasesItem);
    }
    }

    // v1_pod_spec->hostIPC
    cJSON *hostIPC = cJSON_GetObjectItemCaseSensitive(v1_pod_specJSON, "hostIPC");
    if (hostIPC) { 
    if(!cJSON_IsBool(hostIPC))
    {
    goto end; //Bool
    }
    }

    // v1_pod_spec->hostNetwork
    cJSON *hostNetwork = cJSON_GetObjectItemCaseSensitive(v1_pod_specJSON, "hostNetwork");
    if (hostNetwork) { 
    if(!cJSON_IsBool(hostNetwork))
    {
    goto end; //Bool
    }
    }

    // v1_pod_spec->hostPID
    cJSON *hostPID = cJSON_GetObjectItemCaseSensitive(v1_pod_specJSON, "hostPID");
    if (hostPID) { 
    if(!cJSON_IsBool(hostPID))
    {
    goto end; //Bool
    }
    }

    // v1_pod_spec->hostname
    cJSON *hostname = cJSON_GetObjectItemCaseSensitive(v1_pod_specJSON, "hostname");
    if (hostname) { 
    if(!cJSON_IsString(hostname))
    {
    goto end; //String
    }
    }

    // v1_pod_spec->imagePullSecrets
    cJSON *imagePullSecrets = cJSON_GetObjectItemCaseSensitive(v1_pod_specJSON, "imagePullSecrets");
    list_t *imagePullSecretsList;
    if (imagePullSecrets) { 
    cJSON *imagePullSecrets_local_nonprimitive;
    if(!cJSON_IsArray(imagePullSecrets)){
        goto end; //nonprimitive container
    }

    imagePullSecretsList = list_create();

    cJSON_ArrayForEach(imagePullSecrets_local_nonprimitive,imagePullSecrets )
    {
        if(!cJSON_IsObject(imagePullSecrets_local_nonprimitive)){
            goto end;
        }
        v1_local_object_reference_t *imagePullSecretsItem = v1_local_object_reference_parseFromJSON(imagePullSecrets_local_nonprimitive);

        list_addElement(imagePullSecretsList, imagePullSecretsItem);
    }
    }

    // v1_pod_spec->initContainers
    cJSON *initContainers = cJSON_GetObjectItemCaseSensitive(v1_pod_specJSON, "initContainers");
    list_t *initContainersList;
    if (initContainers) { 
    cJSON *initContainers_local_nonprimitive;
    if(!cJSON_IsArray(initContainers)){
        goto end; //nonprimitive container
    }

    initContainersList = list_create();

    cJSON_ArrayForEach(initContainers_local_nonprimitive,initContainers )
    {
        if(!cJSON_IsObject(initContainers_local_nonprimitive)){
            goto end;
        }
        v1_container_t *initContainersItem = v1_container_parseFromJSON(initContainers_local_nonprimitive);

        list_addElement(initContainersList, initContainersItem);
    }
    }

    // v1_pod_spec->nodeName
    cJSON *nodeName = cJSON_GetObjectItemCaseSensitive(v1_pod_specJSON, "nodeName");
    if (nodeName) { 
    if(!cJSON_IsString(nodeName))
    {
    goto end; //String
    }
    }

    // v1_pod_spec->nodeSelector
    cJSON *nodeSelector = cJSON_GetObjectItemCaseSensitive(v1_pod_specJSON, "nodeSelector");
    list_t *List;
    if (nodeSelector) { 
    cJSON *_local_map;
    if(!cJSON_IsObject(nodeSelector)) {
        goto end;//primitive map container
    }
    List = list_create();
    keyValuePair_t *localMapKeyPair;
    cJSON_ArrayForEach(_local_map, nodeSelector)
    {
        if(!cJSON_IsNumber(_local_map))
        {
            goto end;
        }
        localMapKeyPair = keyValuePair_create(strdup(_local_map->string),&_local_map->valuedouble );
        list_addElement(List , localMapKeyPair);
    }
    }

    // v1_pod_spec->overhead
    cJSON *overhead = cJSON_GetObjectItemCaseSensitive(v1_pod_specJSON, "overhead");
    list_t *List;
    if (overhead) { 
    cJSON *_local_map;
    if(!cJSON_IsObject(overhead)) {
        goto end;//primitive map container
    }
    List = list_create();
    keyValuePair_t *localMapKeyPair;
    cJSON_ArrayForEach(_local_map, overhead)
    {
        if(!cJSON_IsNumber(_local_map))
        {
            goto end;
        }
        localMapKeyPair = keyValuePair_create(strdup(_local_map->string),&_local_map->valuedouble );
        list_addElement(List , localMapKeyPair);
    }
    }

    // v1_pod_spec->preemptionPolicy
    cJSON *preemptionPolicy = cJSON_GetObjectItemCaseSensitive(v1_pod_specJSON, "preemptionPolicy");
    if (preemptionPolicy) { 
    if(!cJSON_IsString(preemptionPolicy))
    {
    goto end; //String
    }
    }

    // v1_pod_spec->priority
    cJSON *priority = cJSON_GetObjectItemCaseSensitive(v1_pod_specJSON, "priority");
    if (priority) { 
    if(!cJSON_IsNumber(priority))
    {
    goto end; //Numeric
    }
    }

    // v1_pod_spec->priorityClassName
    cJSON *priorityClassName = cJSON_GetObjectItemCaseSensitive(v1_pod_specJSON, "priorityClassName");
    if (priorityClassName) { 
    if(!cJSON_IsString(priorityClassName))
    {
    goto end; //String
    }
    }

    // v1_pod_spec->readinessGates
    cJSON *readinessGates = cJSON_GetObjectItemCaseSensitive(v1_pod_specJSON, "readinessGates");
    list_t *readinessGatesList;
    if (readinessGates) { 
    cJSON *readinessGates_local_nonprimitive;
    if(!cJSON_IsArray(readinessGates)){
        goto end; //nonprimitive container
    }

    readinessGatesList = list_create();

    cJSON_ArrayForEach(readinessGates_local_nonprimitive,readinessGates )
    {
        if(!cJSON_IsObject(readinessGates_local_nonprimitive)){
            goto end;
        }
        v1_pod_readiness_gate_t *readinessGatesItem = v1_pod_readiness_gate_parseFromJSON(readinessGates_local_nonprimitive);

        list_addElement(readinessGatesList, readinessGatesItem);
    }
    }

    // v1_pod_spec->restartPolicy
    cJSON *restartPolicy = cJSON_GetObjectItemCaseSensitive(v1_pod_specJSON, "restartPolicy");
    if (restartPolicy) { 
    if(!cJSON_IsString(restartPolicy))
    {
    goto end; //String
    }
    }

    // v1_pod_spec->runtimeClassName
    cJSON *runtimeClassName = cJSON_GetObjectItemCaseSensitive(v1_pod_specJSON, "runtimeClassName");
    if (runtimeClassName) { 
    if(!cJSON_IsString(runtimeClassName))
    {
    goto end; //String
    }
    }

    // v1_pod_spec->schedulerName
    cJSON *schedulerName = cJSON_GetObjectItemCaseSensitive(v1_pod_specJSON, "schedulerName");
    if (schedulerName) { 
    if(!cJSON_IsString(schedulerName))
    {
    goto end; //String
    }
    }

    // v1_pod_spec->securityContext
    cJSON *securityContext = cJSON_GetObjectItemCaseSensitive(v1_pod_specJSON, "securityContext");
    v1_pod_security_context_t *securityContext_local_nonprim = NULL;
    if (securityContext) { 
    securityContext_local_nonprim = v1_pod_security_context_parseFromJSON(securityContext); //nonprimitive
    }

    // v1_pod_spec->serviceAccount
    cJSON *serviceAccount = cJSON_GetObjectItemCaseSensitive(v1_pod_specJSON, "serviceAccount");
    if (serviceAccount) { 
    if(!cJSON_IsString(serviceAccount))
    {
    goto end; //String
    }
    }

    // v1_pod_spec->serviceAccountName
    cJSON *serviceAccountName = cJSON_GetObjectItemCaseSensitive(v1_pod_specJSON, "serviceAccountName");
    if (serviceAccountName) { 
    if(!cJSON_IsString(serviceAccountName))
    {
    goto end; //String
    }
    }

    // v1_pod_spec->shareProcessNamespace
    cJSON *shareProcessNamespace = cJSON_GetObjectItemCaseSensitive(v1_pod_specJSON, "shareProcessNamespace");
    if (shareProcessNamespace) { 
    if(!cJSON_IsBool(shareProcessNamespace))
    {
    goto end; //Bool
    }
    }

    // v1_pod_spec->subdomain
    cJSON *subdomain = cJSON_GetObjectItemCaseSensitive(v1_pod_specJSON, "subdomain");
    if (subdomain) { 
    if(!cJSON_IsString(subdomain))
    {
    goto end; //String
    }
    }

    // v1_pod_spec->terminationGracePeriodSeconds
    cJSON *terminationGracePeriodSeconds = cJSON_GetObjectItemCaseSensitive(v1_pod_specJSON, "terminationGracePeriodSeconds");
    if (terminationGracePeriodSeconds) { 
    if(!cJSON_IsNumber(terminationGracePeriodSeconds))
    {
    goto end; //Numeric
    }
    }

    // v1_pod_spec->tolerations
    cJSON *tolerations = cJSON_GetObjectItemCaseSensitive(v1_pod_specJSON, "tolerations");
    list_t *tolerationsList;
    if (tolerations) { 
    cJSON *tolerations_local_nonprimitive;
    if(!cJSON_IsArray(tolerations)){
        goto end; //nonprimitive container
    }

    tolerationsList = list_create();

    cJSON_ArrayForEach(tolerations_local_nonprimitive,tolerations )
    {
        if(!cJSON_IsObject(tolerations_local_nonprimitive)){
            goto end;
        }
        v1_toleration_t *tolerationsItem = v1_toleration_parseFromJSON(tolerations_local_nonprimitive);

        list_addElement(tolerationsList, tolerationsItem);
    }
    }

    // v1_pod_spec->topologySpreadConstraints
    cJSON *topologySpreadConstraints = cJSON_GetObjectItemCaseSensitive(v1_pod_specJSON, "topologySpreadConstraints");
    list_t *topologySpreadConstraintsList;
    if (topologySpreadConstraints) { 
    cJSON *topologySpreadConstraints_local_nonprimitive;
    if(!cJSON_IsArray(topologySpreadConstraints)){
        goto end; //nonprimitive container
    }

    topologySpreadConstraintsList = list_create();

    cJSON_ArrayForEach(topologySpreadConstraints_local_nonprimitive,topologySpreadConstraints )
    {
        if(!cJSON_IsObject(topologySpreadConstraints_local_nonprimitive)){
            goto end;
        }
        v1_topology_spread_constraint_t *topologySpreadConstraintsItem = v1_topology_spread_constraint_parseFromJSON(topologySpreadConstraints_local_nonprimitive);

        list_addElement(topologySpreadConstraintsList, topologySpreadConstraintsItem);
    }
    }

    // v1_pod_spec->volumes
    cJSON *volumes = cJSON_GetObjectItemCaseSensitive(v1_pod_specJSON, "volumes");
    list_t *volumesList;
    if (volumes) { 
    cJSON *volumes_local_nonprimitive;
    if(!cJSON_IsArray(volumes)){
        goto end; //nonprimitive container
    }

    volumesList = list_create();

    cJSON_ArrayForEach(volumes_local_nonprimitive,volumes )
    {
        if(!cJSON_IsObject(volumes_local_nonprimitive)){
            goto end;
        }
        v1_volume_t *volumesItem = v1_volume_parseFromJSON(volumes_local_nonprimitive);

        list_addElement(volumesList, volumesItem);
    }
    }


    v1_pod_spec_local_var = v1_pod_spec_create (
        activeDeadlineSeconds ? activeDeadlineSeconds->valuedouble : 0,
        affinity ? affinity_local_nonprim : NULL,
        automountServiceAccountToken ? automountServiceAccountToken->valueint : 0,
        containersList,
        dnsConfig ? dnsConfig_local_nonprim : NULL,
        dnsPolicy ? strdup(dnsPolicy->valuestring) : NULL,
        enableServiceLinks ? enableServiceLinks->valueint : 0,
        ephemeralContainers ? ephemeralContainersList : NULL,
        hostAliases ? hostAliasesList : NULL,
        hostIPC ? hostIPC->valueint : 0,
        hostNetwork ? hostNetwork->valueint : 0,
        hostPID ? hostPID->valueint : 0,
        hostname ? strdup(hostname->valuestring) : NULL,
        imagePullSecrets ? imagePullSecretsList : NULL,
        initContainers ? initContainersList : NULL,
        nodeName ? strdup(nodeName->valuestring) : NULL,
        nodeSelector ? List : NULL,
        overhead ? List : NULL,
        preemptionPolicy ? strdup(preemptionPolicy->valuestring) : NULL,
        priority ? priority->valuedouble : 0,
        priorityClassName ? strdup(priorityClassName->valuestring) : NULL,
        readinessGates ? readinessGatesList : NULL,
        restartPolicy ? strdup(restartPolicy->valuestring) : NULL,
        runtimeClassName ? strdup(runtimeClassName->valuestring) : NULL,
        schedulerName ? strdup(schedulerName->valuestring) : NULL,
        securityContext ? securityContext_local_nonprim : NULL,
        serviceAccount ? strdup(serviceAccount->valuestring) : NULL,
        serviceAccountName ? strdup(serviceAccountName->valuestring) : NULL,
        shareProcessNamespace ? shareProcessNamespace->valueint : 0,
        subdomain ? strdup(subdomain->valuestring) : NULL,
        terminationGracePeriodSeconds ? terminationGracePeriodSeconds->valuedouble : 0,
        tolerations ? tolerationsList : NULL,
        topologySpreadConstraints ? topologySpreadConstraintsList : NULL,
        volumes ? volumesList : NULL
        );

    return v1_pod_spec_local_var;
end:
    return NULL;

}
