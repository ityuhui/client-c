/*
 * v1beta2_daemon_set.h
 *
 * DEPRECATED - This group version of DaemonSet is deprecated by apps/v1/DaemonSet. See the release notes for more information. DaemonSet represents the configuration of a daemon set.
 */

#ifndef _v1beta2_daemon_set_H_
#define _v1beta2_daemon_set_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_object_meta.h"
#include "v1beta2_daemon_set_spec.h"
#include "v1beta2_daemon_set_status.h"



typedef struct v1beta2_daemon_set_t {
    char *apiVersion; // string
    char *kind; // string
    v1_object_meta_t *metadata; //model
    v1beta2_daemon_set_spec_t *spec; //model
    v1beta2_daemon_set_status_t *status; //model

} v1beta2_daemon_set_t;

v1beta2_daemon_set_t *v1beta2_daemon_set_create(
    char *apiVersion,
    char *kind,
    v1_object_meta_t *metadata,
    v1beta2_daemon_set_spec_t *spec,
    v1beta2_daemon_set_status_t *status
);

void v1beta2_daemon_set_free(v1beta2_daemon_set_t *v1beta2_daemon_set);

v1beta2_daemon_set_t *v1beta2_daemon_set_parseFromJSON(cJSON *v1beta2_daemon_setJSON);

cJSON *v1beta2_daemon_set_convertToJSON(v1beta2_daemon_set_t *v1beta2_daemon_set);

#endif /* _v1beta2_daemon_set_H_ */

