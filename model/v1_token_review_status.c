#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_token_review_status.h"



v1_token_review_status_t *v1_token_review_status_create(
    list_t *audiences,
    int authenticated,
    char *error,
    v1_user_info_t *user
    ) {
	v1_token_review_status_t *v1_token_review_status_local_var = malloc(sizeof(v1_token_review_status_t));
    if (!v1_token_review_status_local_var) {
        return NULL;
    }
	v1_token_review_status_local_var->audiences = audiences;
	v1_token_review_status_local_var->authenticated = authenticated;
	v1_token_review_status_local_var->error = error;
	v1_token_review_status_local_var->user = user;

	return v1_token_review_status_local_var;
}


void v1_token_review_status_free(v1_token_review_status_t *v1_token_review_status) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, v1_token_review_status->audiences) {
		free(listEntry->data);
	}
	list_free(v1_token_review_status->audiences);
    free(v1_token_review_status->error);
    v1_user_info_free(v1_token_review_status->user);
	free(v1_token_review_status);
}

cJSON *v1_token_review_status_convertToJSON(v1_token_review_status_t *v1_token_review_status) {
	cJSON *item = cJSON_CreateObject();

	// v1_token_review_status->audiences
    if(v1_token_review_status->audiences) { 
	cJSON *audiences = cJSON_AddArrayToObject(item, "audiences");
	if(audiences == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *audiencesListEntry;
    list_ForEach(audiencesListEntry, v1_token_review_status->audiences) {
    if(cJSON_AddStringToObject(audiences, "", (char*)audiencesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


	// v1_token_review_status->authenticated
    if(v1_token_review_status->authenticated) { 
    if(cJSON_AddBoolToObject(item, "authenticated", v1_token_review_status->authenticated) == NULL) {
    goto fail; //Bool
    }
     } 


	// v1_token_review_status->error
    if(v1_token_review_status->error) { 
    if(cJSON_AddStringToObject(item, "error", v1_token_review_status->error) == NULL) {
    goto fail; //String
    }
     } 


	// v1_token_review_status->user
    if(v1_token_review_status->user) { 
    cJSON *user_local_JSON = v1_user_info_convertToJSON(v1_token_review_status->user);
    if(user_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "user", user_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1_token_review_status_t *v1_token_review_status_parseFromJSON(cJSON *v1_token_review_statusJSON){

    v1_token_review_status_t *v1_token_review_status_local_var = NULL;

    // v1_token_review_status->audiences
    cJSON *audiences = cJSON_GetObjectItemCaseSensitive(v1_token_review_statusJSON, "audiences");
    list_t *audiencesList;
    if (audiences) { 
    cJSON *audiences_local;
    if(!cJSON_IsArray(audiences)) {
        goto end;//primitive container
    }
    audiencesList = list_create();

    cJSON_ArrayForEach(audiences_local, audiences)
    {
        if(!cJSON_IsString(audiences_local))
        {
            goto end;
        }
        list_addElement(audiencesList , strdup(audiences_local->valuestring));
    }
    }

    // v1_token_review_status->authenticated
    cJSON *authenticated = cJSON_GetObjectItemCaseSensitive(v1_token_review_statusJSON, "authenticated");
    if (authenticated) { 
    if(!cJSON_IsBool(authenticated))
    {
    goto end; //Bool
    }
    }

    // v1_token_review_status->error
    cJSON *error = cJSON_GetObjectItemCaseSensitive(v1_token_review_statusJSON, "error");
    if (error) { 
    if(!cJSON_IsString(error))
    {
    goto end; //String
    }
    }

    // v1_token_review_status->user
    cJSON *user = cJSON_GetObjectItemCaseSensitive(v1_token_review_statusJSON, "user");
    v1_user_info_t *user_local_nonprim = NULL;
    if (user) { 
    user_local_nonprim = v1_user_info_parseFromJSON(user); //nonprimitive
    }


    v1_token_review_status_local_var = v1_token_review_status_create (
        audiences ? audiencesList : NULL,
        authenticated ? authenticated->valueint : 0,
        error ? strdup(error->valuestring) : NULL,
        user ? user_local_nonprim : NULL
        );

    return v1_token_review_status_local_var;
end:
    return NULL;

}
