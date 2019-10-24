/*
 * v1_job_spec.h
 *
 * JobSpec describes how the job execution will look like.
 */

#ifndef _ego_v1_activity_spec_H_
#define _ego_v1_activity_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_label_selector.h"
#include "v1_pod_template_spec.h"


typedef struct ego_v1_activity_spec {
    char *host; // string
    char *command; // string
} ego_v1_activity_spec_t;

ego_v1_activity_spec_t *v1_job_spec_create(
    char *host, // string
    char *command// string
);

void ego_v1_activity_spec_free(ego_v1_activity_spec_t *ego_v1_activity_spec);

ego_v1_activity_spec_t *ego_v1_activity_spec_parseFromJSON(cJSON *ego_v1_activity_specJSON);

cJSON *ego_v1_activity_spec_convertToJSON(ego_v1_activity_spec_t *ego_v1_activity_spec);

#endif /* _ego_v1_activity_spec_H_ */

