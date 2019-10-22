/*
 * v1_pod.h
 *
 * Pod is a collection of containers that can run on a host. This resource is created by clients and scheduled onto hosts.
 */

#ifndef _v1_pod_H_
#define _v1_pod_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_object_meta.h"
#include "v1_pod_spec.h"
#include "v1_pod_status.h"



typedef struct v1_pod_t {
    char *apiVersion; // string
    char *kind; // string
    v1_object_meta_t *metadata; //model
    v1_pod_spec_t *spec; //model
    v1_pod_status_t *status; //model

} v1_pod_t;

v1_pod_t *v1_pod_create(
    char *apiVersion,
    char *kind,
    v1_object_meta_t *metadata,
    v1_pod_spec_t *spec,
    v1_pod_status_t *status
);

void v1_pod_free(v1_pod_t *v1_pod);

v1_pod_t *v1_pod_parseFromJSON(cJSON *v1_podJSON);

cJSON *v1_pod_convertToJSON(v1_pod_t *v1_pod);

#endif /* _v1_pod_H_ */

