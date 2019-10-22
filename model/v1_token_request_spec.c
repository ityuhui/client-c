#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_token_request_spec.h"



v1_token_request_spec_t *v1_token_request_spec_create(
    list_t *audiences,
    v1_bound_object_reference_t *boundObjectRef,
    long expirationSeconds
    ) {
	v1_token_request_spec_t *v1_token_request_spec_local_var = malloc(sizeof(v1_token_request_spec_t));
    if (!v1_token_request_spec_local_var) {
        return NULL;
    }
	v1_token_request_spec_local_var->audiences = audiences;
	v1_token_request_spec_local_var->boundObjectRef = boundObjectRef;
	v1_token_request_spec_local_var->expirationSeconds = expirationSeconds;

	return v1_token_request_spec_local_var;
}


void v1_token_request_spec_free(v1_token_request_spec_t *v1_token_request_spec) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, v1_token_request_spec->audiences) {
		free(listEntry->data);
	}
	list_free(v1_token_request_spec->audiences);
    v1_bound_object_reference_free(v1_token_request_spec->boundObjectRef);
	free(v1_token_request_spec);
}

cJSON *v1_token_request_spec_convertToJSON(v1_token_request_spec_t *v1_token_request_spec) {
	cJSON *item = cJSON_CreateObject();

	// v1_token_request_spec->audiences
    if (!v1_token_request_spec->audiences) {
        goto fail;
    }
    
	cJSON *audiences = cJSON_AddArrayToObject(item, "audiences");
	if(audiences == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *audiencesListEntry;
    list_ForEach(audiencesListEntry, v1_token_request_spec->audiences) {
    if(cJSON_AddStringToObject(audiences, "", (char*)audiencesListEntry->data) == NULL)
    {
        goto fail;
    }
    }


	// v1_token_request_spec->boundObjectRef
    if(v1_token_request_spec->boundObjectRef) { 
    cJSON *boundObjectRef_local_JSON = v1_bound_object_reference_convertToJSON(v1_token_request_spec->boundObjectRef);
    if(boundObjectRef_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "boundObjectRef", boundObjectRef_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_token_request_spec->expirationSeconds
    if(v1_token_request_spec->expirationSeconds) { 
    if(cJSON_AddNumberToObject(item, "expirationSeconds", v1_token_request_spec->expirationSeconds) == NULL) {
    goto fail; //Numeric
    }
     } 

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

v1_token_request_spec_t *v1_token_request_spec_parseFromJSON(cJSON *v1_token_request_specJSON){

    v1_token_request_spec_t *v1_token_request_spec_local_var = NULL;

    // v1_token_request_spec->audiences
    cJSON *audiences = cJSON_GetObjectItemCaseSensitive(v1_token_request_specJSON, "audiences");
    if (!audiences) {
        goto end;
    }

    list_t *audiencesList;
    
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

    // v1_token_request_spec->boundObjectRef
    cJSON *boundObjectRef = cJSON_GetObjectItemCaseSensitive(v1_token_request_specJSON, "boundObjectRef");
    v1_bound_object_reference_t *boundObjectRef_local_nonprim = NULL;
    if (boundObjectRef) { 
    boundObjectRef_local_nonprim = v1_bound_object_reference_parseFromJSON(boundObjectRef); //nonprimitive
    }

    // v1_token_request_spec->expirationSeconds
    cJSON *expirationSeconds = cJSON_GetObjectItemCaseSensitive(v1_token_request_specJSON, "expirationSeconds");
    if (expirationSeconds) { 
    if(!cJSON_IsNumber(expirationSeconds))
    {
    goto end; //Numeric
    }
    }


    v1_token_request_spec_local_var = v1_token_request_spec_create (
        audiencesList,
        boundObjectRef ? boundObjectRef_local_nonprim : NULL,
        expirationSeconds ? expirationSeconds->valuedouble : 0
        );

    return v1_token_request_spec_local_var;
end:
    return NULL;

}
