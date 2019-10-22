#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta2_rolling_update_daemon_set.h"



v1beta2_rolling_update_daemon_set_t *v1beta2_rolling_update_daemon_set_create(
    object_t *maxUnavailable
    ) {
	v1beta2_rolling_update_daemon_set_t *v1beta2_rolling_update_daemon_set_local_var = malloc(sizeof(v1beta2_rolling_update_daemon_set_t));
    if (!v1beta2_rolling_update_daemon_set_local_var) {
        return NULL;
    }
	v1beta2_rolling_update_daemon_set_local_var->maxUnavailable = maxUnavailable;

	return v1beta2_rolling_update_daemon_set_local_var;
}


void v1beta2_rolling_update_daemon_set_free(v1beta2_rolling_update_daemon_set_t *v1beta2_rolling_update_daemon_set) {
    listEntry_t *listEntry;
    object_free(v1beta2_rolling_update_daemon_set->maxUnavailable);
	free(v1beta2_rolling_update_daemon_set);
}

cJSON *v1beta2_rolling_update_daemon_set_convertToJSON(v1beta2_rolling_update_daemon_set_t *v1beta2_rolling_update_daemon_set) {
	cJSON *item = cJSON_CreateObject();

	// v1beta2_rolling_update_daemon_set->maxUnavailable
    if(v1beta2_rolling_update_daemon_set->maxUnavailable) { 
    cJSON *maxUnavailable_object = object_convertToJSON(v1beta2_rolling_update_daemon_set->maxUnavailable);
    if(maxUnavailable_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "maxUnavailable", maxUnavailable_object);
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

v1beta2_rolling_update_daemon_set_t *v1beta2_rolling_update_daemon_set_parseFromJSON(cJSON *v1beta2_rolling_update_daemon_setJSON){

    v1beta2_rolling_update_daemon_set_t *v1beta2_rolling_update_daemon_set_local_var = NULL;

    // v1beta2_rolling_update_daemon_set->maxUnavailable
    cJSON *maxUnavailable = cJSON_GetObjectItemCaseSensitive(v1beta2_rolling_update_daemon_setJSON, "maxUnavailable");
    object_t *maxUnavailable_local_object = NULL;
    if (maxUnavailable) { 
    maxUnavailable_local_object = object_parseFromJSON(maxUnavailable); //object
    }


    v1beta2_rolling_update_daemon_set_local_var = v1beta2_rolling_update_daemon_set_create (
        maxUnavailable ? maxUnavailable_local_object : NULL
        );

    return v1beta2_rolling_update_daemon_set_local_var;
end:
    return NULL;

}
