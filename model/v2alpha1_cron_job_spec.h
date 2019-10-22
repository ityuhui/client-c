/*
 * v2alpha1_cron_job_spec.h
 *
 * CronJobSpec describes how the job execution will look like and when it will actually run.
 */

#ifndef _v2alpha1_cron_job_spec_H_
#define _v2alpha1_cron_job_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v2alpha1_job_template_spec.h"



typedef struct v2alpha1_cron_job_spec_t {
    char *concurrencyPolicy; // string
    int failedJobsHistoryLimit; //numeric
    v2alpha1_job_template_spec_t *jobTemplate; //model
    char *schedule; // string
    long startingDeadlineSeconds; //numeric
    int successfulJobsHistoryLimit; //numeric
    int suspend; //boolean

} v2alpha1_cron_job_spec_t;

v2alpha1_cron_job_spec_t *v2alpha1_cron_job_spec_create(
    char *concurrencyPolicy,
    int failedJobsHistoryLimit,
    v2alpha1_job_template_spec_t *jobTemplate,
    char *schedule,
    long startingDeadlineSeconds,
    int successfulJobsHistoryLimit,
    int suspend
);

void v2alpha1_cron_job_spec_free(v2alpha1_cron_job_spec_t *v2alpha1_cron_job_spec);

v2alpha1_cron_job_spec_t *v2alpha1_cron_job_spec_parseFromJSON(cJSON *v2alpha1_cron_job_specJSON);

cJSON *v2alpha1_cron_job_spec_convertToJSON(v2alpha1_cron_job_spec_t *v2alpha1_cron_job_spec);

#endif /* _v2alpha1_cron_job_spec_H_ */

