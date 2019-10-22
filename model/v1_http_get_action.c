#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_http_get_action.h"



v1_http_get_action_t *v1_http_get_action_create(
    char *host,
    list_t *httpHeaders,
    char *path,
    object_t *port,
    char *scheme
    ) {
	v1_http_get_action_t *v1_http_get_action_local_var = malloc(sizeof(v1_http_get_action_t));
    if (!v1_http_get_action_local_var) {
        return NULL;
    }
	v1_http_get_action_local_var->host = host;
	v1_http_get_action_local_var->httpHeaders = httpHeaders;
	v1_http_get_action_local_var->path = path;
	v1_http_get_action_local_var->port = port;
	v1_http_get_action_local_var->scheme = scheme;

	return v1_http_get_action_local_var;
}


void v1_http_get_action_free(v1_http_get_action_t *v1_http_get_action) {
    listEntry_t *listEntry;
    free(v1_http_get_action->host);
	list_ForEach(listEntry, v1_http_get_action->httpHeaders) {
		v1_http_header_free(listEntry->data);
	}
	list_free(v1_http_get_action->httpHeaders);
    free(v1_http_get_action->path);
    object_free(v1_http_get_action->port);
    free(v1_http_get_action->scheme);
	free(v1_http_get_action);
}

cJSON *v1_http_get_action_convertToJSON(v1_http_get_action_t *v1_http_get_action) {
	cJSON *item = cJSON_CreateObject();

	// v1_http_get_action->host
    if(v1_http_get_action->host) { 
    if(cJSON_AddStringToObject(item, "host", v1_http_get_action->host) == NULL) {
    goto fail; //String
    }
     } 


	// v1_http_get_action->httpHeaders
    if(v1_http_get_action->httpHeaders) { 
    cJSON *httpHeaders = cJSON_AddArrayToObject(item, "httpHeaders");
    if(httpHeaders == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *httpHeadersListEntry;
    if (v1_http_get_action->httpHeaders) {
    list_ForEach(httpHeadersListEntry, v1_http_get_action->httpHeaders) {
    cJSON *itemLocal = v1_http_header_convertToJSON(httpHeadersListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(httpHeaders, itemLocal);
    }
    }
     } 


	// v1_http_get_action->path
    if(v1_http_get_action->path) { 
    if(cJSON_AddStringToObject(item, "path", v1_http_get_action->path) == NULL) {
    goto fail; //String
    }
     } 


	// v1_http_get_action->port
    if (!v1_http_get_action->port) {
        goto fail;
    }
    
    cJSON *port_object = object_convertToJSON(v1_http_get_action->port);
    if(port_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "port", port_object);
    if(item->child == NULL) {
    goto fail;
    }


	// v1_http_get_action->scheme
    if(v1_http_get_action->scheme) { 
    if(cJSON_AddStringToObject(item, "scheme", v1_http_get_action->scheme) == NULL) {
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

v1_http_get_action_t *v1_http_get_action_parseFromJSON(cJSON *v1_http_get_actionJSON){

    v1_http_get_action_t *v1_http_get_action_local_var = NULL;

    // v1_http_get_action->host
    cJSON *host = cJSON_GetObjectItemCaseSensitive(v1_http_get_actionJSON, "host");
    if (host) { 
    if(!cJSON_IsString(host))
    {
    goto end; //String
    }
    }

    // v1_http_get_action->httpHeaders
    cJSON *httpHeaders = cJSON_GetObjectItemCaseSensitive(v1_http_get_actionJSON, "httpHeaders");
    list_t *httpHeadersList;
    if (httpHeaders) { 
    cJSON *httpHeaders_local_nonprimitive;
    if(!cJSON_IsArray(httpHeaders)){
        goto end; //nonprimitive container
    }

    httpHeadersList = list_create();

    cJSON_ArrayForEach(httpHeaders_local_nonprimitive,httpHeaders )
    {
        if(!cJSON_IsObject(httpHeaders_local_nonprimitive)){
            goto end;
        }
        v1_http_header_t *httpHeadersItem = v1_http_header_parseFromJSON(httpHeaders_local_nonprimitive);

        list_addElement(httpHeadersList, httpHeadersItem);
    }
    }

    // v1_http_get_action->path
    cJSON *path = cJSON_GetObjectItemCaseSensitive(v1_http_get_actionJSON, "path");
    if (path) { 
    if(!cJSON_IsString(path))
    {
    goto end; //String
    }
    }

    // v1_http_get_action->port
    cJSON *port = cJSON_GetObjectItemCaseSensitive(v1_http_get_actionJSON, "port");
    if (!port) {
        goto end;
    }

    object_t *port_local_object = NULL;
    
    port_local_object = object_parseFromJSON(port); //object

    // v1_http_get_action->scheme
    cJSON *scheme = cJSON_GetObjectItemCaseSensitive(v1_http_get_actionJSON, "scheme");
    if (scheme) { 
    if(!cJSON_IsString(scheme))
    {
    goto end; //String
    }
    }


    v1_http_get_action_local_var = v1_http_get_action_create (
        host ? strdup(host->valuestring) : NULL,
        httpHeaders ? httpHeadersList : NULL,
        path ? strdup(path->valuestring) : NULL,
        port_local_object,
        scheme ? strdup(scheme->valuestring) : NULL
        );

    return v1_http_get_action_local_var;
end:
    return NULL;

}
