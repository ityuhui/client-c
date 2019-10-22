#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "networking_v1beta1_ingress_tls.h"



networking_v1beta1_ingress_tls_t *networking_v1beta1_ingress_tls_create(
    list_t *hosts,
    char *secretName
    ) {
	networking_v1beta1_ingress_tls_t *networking_v1beta1_ingress_tls_local_var = malloc(sizeof(networking_v1beta1_ingress_tls_t));
    if (!networking_v1beta1_ingress_tls_local_var) {
        return NULL;
    }
	networking_v1beta1_ingress_tls_local_var->hosts = hosts;
	networking_v1beta1_ingress_tls_local_var->secretName = secretName;

	return networking_v1beta1_ingress_tls_local_var;
}


void networking_v1beta1_ingress_tls_free(networking_v1beta1_ingress_tls_t *networking_v1beta1_ingress_tls) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, networking_v1beta1_ingress_tls->hosts) {
		free(listEntry->data);
	}
	list_free(networking_v1beta1_ingress_tls->hosts);
    free(networking_v1beta1_ingress_tls->secretName);
	free(networking_v1beta1_ingress_tls);
}

cJSON *networking_v1beta1_ingress_tls_convertToJSON(networking_v1beta1_ingress_tls_t *networking_v1beta1_ingress_tls) {
	cJSON *item = cJSON_CreateObject();

	// networking_v1beta1_ingress_tls->hosts
    if(networking_v1beta1_ingress_tls->hosts) { 
	cJSON *hosts = cJSON_AddArrayToObject(item, "hosts");
	if(hosts == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *hostsListEntry;
    list_ForEach(hostsListEntry, networking_v1beta1_ingress_tls->hosts) {
    if(cJSON_AddStringToObject(hosts, "", (char*)hostsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


	// networking_v1beta1_ingress_tls->secretName
    if(networking_v1beta1_ingress_tls->secretName) { 
    if(cJSON_AddStringToObject(item, "secretName", networking_v1beta1_ingress_tls->secretName) == NULL) {
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

networking_v1beta1_ingress_tls_t *networking_v1beta1_ingress_tls_parseFromJSON(cJSON *networking_v1beta1_ingress_tlsJSON){

    networking_v1beta1_ingress_tls_t *networking_v1beta1_ingress_tls_local_var = NULL;

    // networking_v1beta1_ingress_tls->hosts
    cJSON *hosts = cJSON_GetObjectItemCaseSensitive(networking_v1beta1_ingress_tlsJSON, "hosts");
    list_t *hostsList;
    if (hosts) { 
    cJSON *hosts_local;
    if(!cJSON_IsArray(hosts)) {
        goto end;//primitive container
    }
    hostsList = list_create();

    cJSON_ArrayForEach(hosts_local, hosts)
    {
        if(!cJSON_IsString(hosts_local))
        {
            goto end;
        }
        list_addElement(hostsList , strdup(hosts_local->valuestring));
    }
    }

    // networking_v1beta1_ingress_tls->secretName
    cJSON *secretName = cJSON_GetObjectItemCaseSensitive(networking_v1beta1_ingress_tlsJSON, "secretName");
    if (secretName) { 
    if(!cJSON_IsString(secretName))
    {
    goto end; //String
    }
    }


    networking_v1beta1_ingress_tls_local_var = networking_v1beta1_ingress_tls_create (
        hosts ? hostsList : NULL,
        secretName ? strdup(secretName->valuestring) : NULL
        );

    return networking_v1beta1_ingress_tls_local_var;
end:
    return NULL;

}
