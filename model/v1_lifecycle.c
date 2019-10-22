#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_lifecycle.h"



v1_lifecycle_t *v1_lifecycle_create(
    v1_handler_t *postStart,
    v1_handler_t *preStop
    ) {
	v1_lifecycle_t *v1_lifecycle_local_var = malloc(sizeof(v1_lifecycle_t));
    if (!v1_lifecycle_local_var) {
        return NULL;
    }
	v1_lifecycle_local_var->postStart = postStart;
	v1_lifecycle_local_var->preStop = preStop;

	return v1_lifecycle_local_var;
}


void v1_lifecycle_free(v1_lifecycle_t *v1_lifecycle) {
    listEntry_t *listEntry;
    v1_handler_free(v1_lifecycle->postStart);
    v1_handler_free(v1_lifecycle->preStop);
	free(v1_lifecycle);
}

cJSON *v1_lifecycle_convertToJSON(v1_lifecycle_t *v1_lifecycle) {
	cJSON *item = cJSON_CreateObject();

	// v1_lifecycle->postStart
    if(v1_lifecycle->postStart) { 
    cJSON *postStart_local_JSON = v1_handler_convertToJSON(v1_lifecycle->postStart);
    if(postStart_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "postStart", postStart_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// v1_lifecycle->preStop
    if(v1_lifecycle->preStop) { 
    cJSON *preStop_local_JSON = v1_handler_convertToJSON(v1_lifecycle->preStop);
    if(preStop_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "preStop", preStop_local_JSON);
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

v1_lifecycle_t *v1_lifecycle_parseFromJSON(cJSON *v1_lifecycleJSON){

    v1_lifecycle_t *v1_lifecycle_local_var = NULL;

    // v1_lifecycle->postStart
    cJSON *postStart = cJSON_GetObjectItemCaseSensitive(v1_lifecycleJSON, "postStart");
    v1_handler_t *postStart_local_nonprim = NULL;
    if (postStart) { 
    postStart_local_nonprim = v1_handler_parseFromJSON(postStart); //nonprimitive
    }

    // v1_lifecycle->preStop
    cJSON *preStop = cJSON_GetObjectItemCaseSensitive(v1_lifecycleJSON, "preStop");
    v1_handler_t *preStop_local_nonprim = NULL;
    if (preStop) { 
    preStop_local_nonprim = v1_handler_parseFromJSON(preStop); //nonprimitive
    }


    v1_lifecycle_local_var = v1_lifecycle_create (
        postStart ? postStart_local_nonprim : NULL,
        preStop ? preStop_local_nonprim : NULL
        );

    return v1_lifecycle_local_var;
end:
    return NULL;

}
