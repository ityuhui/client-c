#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ego_v1_activity_status.h"



ego_v1_activity_status_t *ego_v1_activity_status_create(
    ) {
    ego_v1_activity_status_t *ego_v1_activity_status_local_var = malloc(sizeof(ego_v1_activity_status_t));
    if (!ego_v1_activity_status_local_var) {
        return NULL;
    }


	return ego_v1_activity_status_local_var;
}


void ego_v1_activity_status_free(ego_v1_activity_status_t *ego_v1_activity_status) {
    FREEUP(ego_v1_activity_status);
}

cJSON *ego_v1_activity_status_convertToJSON(ego_v1_activity_status_t *ego_v1_activity_status) {
	cJSON *item = cJSON_CreateObject();

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

ego_v1_activity_status_t *ego_v1_activity_status_parseFromJSON(cJSON *ego_v1_activity_statusJSON){

    ego_v1_activity_status_t *ego_v1_activity_status_local_var = NULL;

    ego_v1_activity_status_local_var = v1_job_status_create (
        );

    return ego_v1_activity_status_local_var;
end:
    return NULL;

}
