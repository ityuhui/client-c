#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_pod_status.h"



v1_pod_status_t *v1_pod_status_create(
    list_t *conditions,
    list_t *containerStatuses,
    list_t *ephemeralContainerStatuses,
    char *hostIP,
    list_t *initContainerStatuses,
    char *message,
    char *nominatedNodeName,
    char *phase,
    char *podIP,
    list_t *podIPs,
    char *qosClass,
    char *reason,
    char *startTime
    ) {
	v1_pod_status_t *v1_pod_status_local_var = malloc(sizeof(v1_pod_status_t));
    if (!v1_pod_status_local_var) {
        return NULL;
    }
	v1_pod_status_local_var->conditions = conditions;
	v1_pod_status_local_var->containerStatuses = containerStatuses;
	v1_pod_status_local_var->ephemeralContainerStatuses = ephemeralContainerStatuses;
	v1_pod_status_local_var->hostIP = hostIP;
	v1_pod_status_local_var->initContainerStatuses = initContainerStatuses;
	v1_pod_status_local_var->message = message;
	v1_pod_status_local_var->nominatedNodeName = nominatedNodeName;
	v1_pod_status_local_var->phase = phase;
	v1_pod_status_local_var->podIP = podIP;
	v1_pod_status_local_var->podIPs = podIPs;
	v1_pod_status_local_var->qosClass = qosClass;
	v1_pod_status_local_var->reason = reason;
	v1_pod_status_local_var->startTime = startTime;

	return v1_pod_status_local_var;
}


void v1_pod_status_free(v1_pod_status_t *v1_pod_status) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, v1_pod_status->conditions) {
		v1_pod_condition_free(listEntry->data);
	}
	list_free(v1_pod_status->conditions);
	list_ForEach(listEntry, v1_pod_status->containerStatuses) {
		v1_container_status_free(listEntry->data);
	}
	list_free(v1_pod_status->containerStatuses);
	list_ForEach(listEntry, v1_pod_status->ephemeralContainerStatuses) {
		v1_container_status_free(listEntry->data);
	}
	list_free(v1_pod_status->ephemeralContainerStatuses);
    free(v1_pod_status->hostIP);
	list_ForEach(listEntry, v1_pod_status->initContainerStatuses) {
		v1_container_status_free(listEntry->data);
	}
	list_free(v1_pod_status->initContainerStatuses);
    free(v1_pod_status->message);
    free(v1_pod_status->nominatedNodeName);
    free(v1_pod_status->phase);
    free(v1_pod_status->podIP);
	list_ForEach(listEntry, v1_pod_status->podIPs) {
		v1_pod_ip_free(listEntry->data);
	}
	list_free(v1_pod_status->podIPs);
    free(v1_pod_status->qosClass);
    free(v1_pod_status->reason);
    free(v1_pod_status->startTime);
	free(v1_pod_status);
}

cJSON *v1_pod_status_convertToJSON(v1_pod_status_t *v1_pod_status) {
	cJSON *item = cJSON_CreateObject();

	// v1_pod_status->conditions
    if(v1_pod_status->conditions) { 
    cJSON *conditions = cJSON_AddArrayToObject(item, "conditions");
    if(conditions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *conditionsListEntry;
    if (v1_pod_status->conditions) {
    list_ForEach(conditionsListEntry, v1_pod_status->conditions) {
    cJSON *itemLocal = v1_pod_condition_convertToJSON(conditionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(conditions, itemLocal);
    }
    }
     } 


	// v1_pod_status->containerStatuses
    if(v1_pod_status->containerStatuses) { 
    cJSON *containerStatuses = cJSON_AddArrayToObject(item, "containerStatuses");
    if(containerStatuses == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *containerStatusesListEntry;
    if (v1_pod_status->containerStatuses) {
    list_ForEach(containerStatusesListEntry, v1_pod_status->containerStatuses) {
    cJSON *itemLocal = v1_container_status_convertToJSON(containerStatusesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(containerStatuses, itemLocal);
    }
    }
     } 


	// v1_pod_status->ephemeralContainerStatuses
    if(v1_pod_status->ephemeralContainerStatuses) { 
    cJSON *ephemeralContainerStatuses = cJSON_AddArrayToObject(item, "ephemeralContainerStatuses");
    if(ephemeralContainerStatuses == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *ephemeralContainerStatusesListEntry;
    if (v1_pod_status->ephemeralContainerStatuses) {
    list_ForEach(ephemeralContainerStatusesListEntry, v1_pod_status->ephemeralContainerStatuses) {
    cJSON *itemLocal = v1_container_status_convertToJSON(ephemeralContainerStatusesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(ephemeralContainerStatuses, itemLocal);
    }
    }
     } 


	// v1_pod_status->hostIP
    if(v1_pod_status->hostIP) { 
    if(cJSON_AddStringToObject(item, "hostIP", v1_pod_status->hostIP) == NULL) {
    goto fail; //String
    }
     } 


	// v1_pod_status->initContainerStatuses
    if(v1_pod_status->initContainerStatuses) { 
    cJSON *initContainerStatuses = cJSON_AddArrayToObject(item, "initContainerStatuses");
    if(initContainerStatuses == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *initContainerStatusesListEntry;
    if (v1_pod_status->initContainerStatuses) {
    list_ForEach(initContainerStatusesListEntry, v1_pod_status->initContainerStatuses) {
    cJSON *itemLocal = v1_container_status_convertToJSON(initContainerStatusesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(initContainerStatuses, itemLocal);
    }
    }
     } 


	// v1_pod_status->message
    if(v1_pod_status->message) { 
    if(cJSON_AddStringToObject(item, "message", v1_pod_status->message) == NULL) {
    goto fail; //String
    }
     } 


	// v1_pod_status->nominatedNodeName
    if(v1_pod_status->nominatedNodeName) { 
    if(cJSON_AddStringToObject(item, "nominatedNodeName", v1_pod_status->nominatedNodeName) == NULL) {
    goto fail; //String
    }
     } 


	// v1_pod_status->phase
    if(v1_pod_status->phase) { 
    if(cJSON_AddStringToObject(item, "phase", v1_pod_status->phase) == NULL) {
    goto fail; //String
    }
     } 


	// v1_pod_status->podIP
    if(v1_pod_status->podIP) { 
    if(cJSON_AddStringToObject(item, "podIP", v1_pod_status->podIP) == NULL) {
    goto fail; //String
    }
     } 


	// v1_pod_status->podIPs
    if(v1_pod_status->podIPs) { 
    cJSON *podIPs = cJSON_AddArrayToObject(item, "podIPs");
    if(podIPs == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *podIPsListEntry;
    if (v1_pod_status->podIPs) {
    list_ForEach(podIPsListEntry, v1_pod_status->podIPs) {
    cJSON *itemLocal = v1_pod_ip_convertToJSON(podIPsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(podIPs, itemLocal);
    }
    }
     } 


	// v1_pod_status->qosClass
    if(v1_pod_status->qosClass) { 
    if(cJSON_AddStringToObject(item, "qosClass", v1_pod_status->qosClass) == NULL) {
    goto fail; //String
    }
     } 


	// v1_pod_status->reason
    if(v1_pod_status->reason) { 
    if(cJSON_AddStringToObject(item, "reason", v1_pod_status->reason) == NULL) {
    goto fail; //String
    }
     } 


	// v1_pod_status->startTime
    if(v1_pod_status->startTime) { 
    if(cJSON_AddStringToObject(item, "startTime", v1_pod_status->startTime) == NULL) {
    goto fail; //Date-Time
    }
     } 

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1_pod_status_t *v1_pod_status_parseFromJSON(cJSON *v1_pod_statusJSON){

    v1_pod_status_t *v1_pod_status_local_var = NULL;

    // v1_pod_status->conditions
    cJSON *conditions = cJSON_GetObjectItemCaseSensitive(v1_pod_statusJSON, "conditions");
    list_t *conditionsList;
    if (conditions) { 
    cJSON *conditions_local_nonprimitive;
    if(!cJSON_IsArray(conditions)){
        goto end; //nonprimitive container
    }

    conditionsList = list_create();

    cJSON_ArrayForEach(conditions_local_nonprimitive,conditions )
    {
        if(!cJSON_IsObject(conditions_local_nonprimitive)){
            goto end;
        }
        v1_pod_condition_t *conditionsItem = v1_pod_condition_parseFromJSON(conditions_local_nonprimitive);

        list_addElement(conditionsList, conditionsItem);
    }
    }

    // v1_pod_status->containerStatuses
    cJSON *containerStatuses = cJSON_GetObjectItemCaseSensitive(v1_pod_statusJSON, "containerStatuses");
    list_t *containerStatusesList;
    if (containerStatuses) { 
    cJSON *containerStatuses_local_nonprimitive;
    if(!cJSON_IsArray(containerStatuses)){
        goto end; //nonprimitive container
    }

    containerStatusesList = list_create();

    cJSON_ArrayForEach(containerStatuses_local_nonprimitive,containerStatuses )
    {
        if(!cJSON_IsObject(containerStatuses_local_nonprimitive)){
            goto end;
        }
        v1_container_status_t *containerStatusesItem = v1_container_status_parseFromJSON(containerStatuses_local_nonprimitive);

        list_addElement(containerStatusesList, containerStatusesItem);
    }
    }

    // v1_pod_status->ephemeralContainerStatuses
    cJSON *ephemeralContainerStatuses = cJSON_GetObjectItemCaseSensitive(v1_pod_statusJSON, "ephemeralContainerStatuses");
    list_t *ephemeralContainerStatusesList;
    if (ephemeralContainerStatuses) { 
    cJSON *ephemeralContainerStatuses_local_nonprimitive;
    if(!cJSON_IsArray(ephemeralContainerStatuses)){
        goto end; //nonprimitive container
    }

    ephemeralContainerStatusesList = list_create();

    cJSON_ArrayForEach(ephemeralContainerStatuses_local_nonprimitive,ephemeralContainerStatuses )
    {
        if(!cJSON_IsObject(ephemeralContainerStatuses_local_nonprimitive)){
            goto end;
        }
        v1_container_status_t *ephemeralContainerStatusesItem = v1_container_status_parseFromJSON(ephemeralContainerStatuses_local_nonprimitive);

        list_addElement(ephemeralContainerStatusesList, ephemeralContainerStatusesItem);
    }
    }

    // v1_pod_status->hostIP
    cJSON *hostIP = cJSON_GetObjectItemCaseSensitive(v1_pod_statusJSON, "hostIP");
    if (hostIP) { 
    if(!cJSON_IsString(hostIP))
    {
    goto end; //String
    }
    }

    // v1_pod_status->initContainerStatuses
    cJSON *initContainerStatuses = cJSON_GetObjectItemCaseSensitive(v1_pod_statusJSON, "initContainerStatuses");
    list_t *initContainerStatusesList;
    if (initContainerStatuses) { 
    cJSON *initContainerStatuses_local_nonprimitive;
    if(!cJSON_IsArray(initContainerStatuses)){
        goto end; //nonprimitive container
    }

    initContainerStatusesList = list_create();

    cJSON_ArrayForEach(initContainerStatuses_local_nonprimitive,initContainerStatuses )
    {
        if(!cJSON_IsObject(initContainerStatuses_local_nonprimitive)){
            goto end;
        }
        v1_container_status_t *initContainerStatusesItem = v1_container_status_parseFromJSON(initContainerStatuses_local_nonprimitive);

        list_addElement(initContainerStatusesList, initContainerStatusesItem);
    }
    }

    // v1_pod_status->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(v1_pod_statusJSON, "message");
    if (message) { 
    if(!cJSON_IsString(message))
    {
    goto end; //String
    }
    }

    // v1_pod_status->nominatedNodeName
    cJSON *nominatedNodeName = cJSON_GetObjectItemCaseSensitive(v1_pod_statusJSON, "nominatedNodeName");
    if (nominatedNodeName) { 
    if(!cJSON_IsString(nominatedNodeName))
    {
    goto end; //String
    }
    }

    // v1_pod_status->phase
    cJSON *phase = cJSON_GetObjectItemCaseSensitive(v1_pod_statusJSON, "phase");
    if (phase) { 
    if(!cJSON_IsString(phase))
    {
    goto end; //String
    }
    }

    // v1_pod_status->podIP
    cJSON *podIP = cJSON_GetObjectItemCaseSensitive(v1_pod_statusJSON, "podIP");
    if (podIP) { 
    if(!cJSON_IsString(podIP))
    {
    goto end; //String
    }
    }

    // v1_pod_status->podIPs
    cJSON *podIPs = cJSON_GetObjectItemCaseSensitive(v1_pod_statusJSON, "podIPs");
    list_t *podIPsList;
    if (podIPs) { 
    cJSON *podIPs_local_nonprimitive;
    if(!cJSON_IsArray(podIPs)){
        goto end; //nonprimitive container
    }

    podIPsList = list_create();

    cJSON_ArrayForEach(podIPs_local_nonprimitive,podIPs )
    {
        if(!cJSON_IsObject(podIPs_local_nonprimitive)){
            goto end;
        }
        v1_pod_ip_t *podIPsItem = v1_pod_ip_parseFromJSON(podIPs_local_nonprimitive);

        list_addElement(podIPsList, podIPsItem);
    }
    }

    // v1_pod_status->qosClass
    cJSON *qosClass = cJSON_GetObjectItemCaseSensitive(v1_pod_statusJSON, "qosClass");
    if (qosClass) { 
    if(!cJSON_IsString(qosClass))
    {
    goto end; //String
    }
    }

    // v1_pod_status->reason
    cJSON *reason = cJSON_GetObjectItemCaseSensitive(v1_pod_statusJSON, "reason");
    if (reason) { 
    if(!cJSON_IsString(reason))
    {
    goto end; //String
    }
    }

    // v1_pod_status->startTime
    cJSON *startTime = cJSON_GetObjectItemCaseSensitive(v1_pod_statusJSON, "startTime");
    if (startTime) { 
    if(!cJSON_IsString(startTime))
    {
    goto end; //DateTime
    }
    }


    v1_pod_status_local_var = v1_pod_status_create (
        conditions ? conditionsList : NULL,
        containerStatuses ? containerStatusesList : NULL,
        ephemeralContainerStatuses ? ephemeralContainerStatusesList : NULL,
        hostIP ? strdup(hostIP->valuestring) : NULL,
        initContainerStatuses ? initContainerStatusesList : NULL,
        message ? strdup(message->valuestring) : NULL,
        nominatedNodeName ? strdup(nominatedNodeName->valuestring) : NULL,
        phase ? strdup(phase->valuestring) : NULL,
        podIP ? strdup(podIP->valuestring) : NULL,
        podIPs ? podIPsList : NULL,
        qosClass ? strdup(qosClass->valuestring) : NULL,
        reason ? strdup(reason->valuestring) : NULL,
        startTime ? strdup(startTime->valuestring) : NULL
        );

    return v1_pod_status_local_var;
end:
    return NULL;

}
