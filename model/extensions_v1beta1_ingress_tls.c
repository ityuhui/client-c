#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "extensions_v1beta1_ingress_tls.h"



extensions_v1beta1_ingress_tls_t *extensions_v1beta1_ingress_tls_create(
    list_t *hosts,
    char *secretName
    ) {
	extensions_v1beta1_ingress_tls_t *extensions_v1beta1_ingress_tls_local_var = malloc(sizeof(extensions_v1beta1_ingress_tls_t));
    if (!extensions_v1beta1_ingress_tls_local_var) {
        return NULL;
    }
	extensions_v1beta1_ingress_tls_local_var->hosts = hosts;
	extensions_v1beta1_ingress_tls_local_var->secretName = secretName;

	return extensions_v1beta1_ingress_tls_local_var;
}


void extensions_v1beta1_ingress_tls_free(extensions_v1beta1_ingress_tls_t *extensions_v1beta1_ingress_tls) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, extensions_v1beta1_ingress_tls->hosts) {
		free(listEntry->data);
	}
	list_free(extensions_v1beta1_ingress_tls->hosts);
    free(extensions_v1beta1_ingress_tls->secretName);
	free(extensions_v1beta1_ingress_tls);
}

cJSON *extensions_v1beta1_ingress_tls_convertToJSON(extensions_v1beta1_ingress_tls_t *extensions_v1beta1_ingress_tls) {
	cJSON *item = cJSON_CreateObject();

	// extensions_v1beta1_ingress_tls->hosts
    if(extensions_v1beta1_ingress_tls->hosts) { 
	cJSON *hosts = cJSON_AddArrayToObject(item, "hosts");
	if(hosts == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *hostsListEntry;
    list_ForEach(hostsListEntry, extensions_v1beta1_ingress_tls->hosts) {
    if(cJSON_AddStringToObject(hosts, "", (char*)hostsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


	// extensions_v1beta1_ingress_tls->secretName
    if(extensions_v1beta1_ingress_tls->secretName) { 
    if(cJSON_AddStringToObject(item, "secretName", extensions_v1beta1_ingress_tls->secretName) == NULL) {
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

extensions_v1beta1_ingress_tls_t *extensions_v1beta1_ingress_tls_parseFromJSON(cJSON *extensions_v1beta1_ingress_tlsJSON){

    extensions_v1beta1_ingress_tls_t *extensions_v1beta1_ingress_tls_local_var = NULL;

    // extensions_v1beta1_ingress_tls->hosts
    cJSON *hosts = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_ingress_tlsJSON, "hosts");
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

    // extensions_v1beta1_ingress_tls->secretName
    cJSON *secretName = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_ingress_tlsJSON, "secretName");
    if (secretName) { 
    if(!cJSON_IsString(secretName))
    {
    goto end; //String
    }
    }


    extensions_v1beta1_ingress_tls_local_var = extensions_v1beta1_ingress_tls_create (
        hosts ? hostsList : NULL,
        secretName ? strdup(secretName->valuestring) : NULL
        );

    return extensions_v1beta1_ingress_tls_local_var;
end:
    return NULL;

}
