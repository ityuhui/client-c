/*
 * v1_job_spec.h
 *
 * JobSpec describes how the job execution will look like.
 */

#ifndef _v1_job_spec_H_
#define _v1_job_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_label_selector.h"
#include "v1_pod_template_spec.h"



typedef struct v1_job_spec_t {
    long activeDeadlineSeconds; //numeric
    int backoffLimit; //numeric
    int completions; //numeric
    int manualSelector; //boolean
    int parallelism; //numeric
    v1_label_selector_t *selector; //model
    v1_pod_template_spec_t *template; //model
    int ttlSecondsAfterFinished; //numeric

} v1_job_spec_t;

v1_job_spec_t *v1_job_spec_create(
    long activeDeadlineSeconds,
    int backoffLimit,
    int completions,
    int manualSelector,
    int parallelism,
    v1_label_selector_t *selector,
    v1_pod_template_spec_t *template,
    int ttlSecondsAfterFinished
);

void v1_job_spec_free(v1_job_spec_t *v1_job_spec);

v1_job_spec_t *v1_job_spec_parseFromJSON(cJSON *v1_job_specJSON);

cJSON *v1_job_spec_convertToJSON(v1_job_spec_t *v1_job_spec);

#endif /* _v1_job_spec_H_ */

