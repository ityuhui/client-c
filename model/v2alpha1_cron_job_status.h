/*
 * v2alpha1_cron_job_status.h
 *
 * CronJobStatus represents the current state of a cron job.
 */

#ifndef _v2alpha1_cron_job_status_H_
#define _v2alpha1_cron_job_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_object_reference.h"



typedef struct v2alpha1_cron_job_status_t {
    list_t *active; //nonprimitive container
    char *lastScheduleTime; //date time

} v2alpha1_cron_job_status_t;

v2alpha1_cron_job_status_t *v2alpha1_cron_job_status_create(
    list_t *active,
    char *lastScheduleTime
);

void v2alpha1_cron_job_status_free(v2alpha1_cron_job_status_t *v2alpha1_cron_job_status);

v2alpha1_cron_job_status_t *v2alpha1_cron_job_status_parseFromJSON(cJSON *v2alpha1_cron_job_statusJSON);

cJSON *v2alpha1_cron_job_status_convertToJSON(v2alpha1_cron_job_status_t *v2alpha1_cron_job_status);

#endif /* _v2alpha1_cron_job_status_H_ */

