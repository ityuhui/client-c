/*
 * v1_job_status.h
 *
 * JobStatus represents the current state of a Job.
 */

#ifndef _ego_v1_activity_status_H_
#define _ego_v1_activity_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"


typedef struct ego_v1_activity_status {
    int temp;

} ego_v1_activity_status_t;

ego_v1_activity_status_t *ego_v1_activity_status_create(

);

void ego_v1_activity_status_free(ego_v1_activity_status_t *ego_v1_activity_status);

ego_v1_activity_status_t *v1_job_status_parseFromJSON(cJSON *ego_v1_activity_statusJSON);

cJSON *ego_v1_activity_status_convertToJSON(ego_v1_activity_status_t *ego_v1_activity_status);

#endif /* ego_v1_activity_status */

