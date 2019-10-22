#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_token_request_status.h"



v1_token_request_status_t *v1_token_request_status_create(
    char *expirationTimestamp,
    char *token
    ) {
	v1_token_request_status_t *v1_token_request_status_local_var = malloc(sizeof(v1_token_request_status_t));
    if (!v1_token_request_status_local_var) {
        return NULL;
    }
	v1_token_request_status_local_var->expirationTimestamp = expirationTimestamp;
	v1_token_request_status_local_var->token = token;

	return v1_token_request_status_local_var;
}


void v1_token_request_status_free(v1_token_request_status_t *v1_token_request_status) {
    listEntry_t *listEntry;
    free(v1_token_request_status->expirationTimestamp);
    free(v1_token_request_status->token);
	free(v1_token_request_status);
}

cJSON *v1_token_request_status_convertToJSON(v1_token_request_status_t *v1_token_request_status) {
	cJSON *item = cJSON_CreateObject();

	// v1_token_request_status->expirationTimestamp
    if (!v1_token_request_status->expirationTimestamp) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "expirationTimestamp", v1_token_request_status->expirationTimestamp) == NULL) {
    goto fail; //Date-Time
    }


	// v1_token_request_status->token
    if (!v1_token_request_status->token) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "token", v1_token_request_status->token) == NULL) {
    goto fail; //String
    }

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1_token_request_status_t *v1_token_request_status_parseFromJSON(cJSON *v1_token_request_statusJSON){

    v1_token_request_status_t *v1_token_request_status_local_var = NULL;

    // v1_token_request_status->expirationTimestamp
    cJSON *expirationTimestamp = cJSON_GetObjectItemCaseSensitive(v1_token_request_statusJSON, "expirationTimestamp");
    if (!expirationTimestamp) {
        goto end;
    }

    
    if(!cJSON_IsString(expirationTimestamp))
    {
    goto end; //DateTime
    }

    // v1_token_request_status->token
    cJSON *token = cJSON_GetObjectItemCaseSensitive(v1_token_request_statusJSON, "token");
    if (!token) {
        goto end;
    }

    
    if(!cJSON_IsString(token))
    {
    goto end; //String
    }


    v1_token_request_status_local_var = v1_token_request_status_create (
        strdup(expirationTimestamp->valuestring),
        strdup(token->valuestring)
        );

    return v1_token_request_status_local_var;
end:
    return NULL;

}
