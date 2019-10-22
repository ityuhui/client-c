/*
 * v1beta1_cron_job_spec.h
 *
 * CronJobSpec describes how the job execution will look like and when it will actually run.
 */

#ifndef _v1beta1_cron_job_spec_H_
#define _v1beta1_cron_job_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1beta1_job_template_spec.h"



typedef struct v1beta1_cron_job_spec_t {
    char *concurrencyPolicy; // string
    int failedJobsHistoryLimit; //numeric
    v1beta1_job_template_spec_t *jobTemplate; //model
    char *schedule; // string
    long startingDeadlineSeconds; //numeric
    int successfulJobsHistoryLimit; //numeric
    int suspend; //boolean

} v1beta1_cron_job_spec_t;

v1beta1_cron_job_spec_t *v1beta1_cron_job_spec_create(
    char *concurrencyPolicy,
    int failedJobsHistoryLimit,
    v1beta1_job_template_spec_t *jobTemplate,
    char *schedule,
    long startingDeadlineSeconds,
    int successfulJobsHistoryLimit,
    int suspend
);

void v1beta1_cron_job_spec_free(v1beta1_cron_job_spec_t *v1beta1_cron_job_spec);

v1beta1_cron_job_spec_t *v1beta1_cron_job_spec_parseFromJSON(cJSON *v1beta1_cron_job_specJSON);

cJSON *v1beta1_cron_job_spec_convertToJSON(v1beta1_cron_job_spec_t *v1beta1_cron_job_spec);

#endif /* _v1beta1_cron_job_spec_H_ */

