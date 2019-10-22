/*
 * v1_daemon_set_spec.h
 *
 * DaemonSetSpec is the specification of a daemon set.
 */

#ifndef _v1_daemon_set_spec_H_
#define _v1_daemon_set_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_daemon_set_update_strategy.h"
#include "v1_label_selector.h"
#include "v1_pod_template_spec.h"



typedef struct v1_daemon_set_spec_t {
    int minReadySeconds; //numeric
    int revisionHistoryLimit; //numeric
    v1_label_selector_t *selector; //model
    v1_pod_template_spec_t *template; //model
    v1_daemon_set_update_strategy_t *updateStrategy; //model

} v1_daemon_set_spec_t;

v1_daemon_set_spec_t *v1_daemon_set_spec_create(
    int minReadySeconds,
    int revisionHistoryLimit,
    v1_label_selector_t *selector,
    v1_pod_template_spec_t *template,
    v1_daemon_set_update_strategy_t *updateStrategy
);

void v1_daemon_set_spec_free(v1_daemon_set_spec_t *v1_daemon_set_spec);

v1_daemon_set_spec_t *v1_daemon_set_spec_parseFromJSON(cJSON *v1_daemon_set_specJSON);

cJSON *v1_daemon_set_spec_convertToJSON(v1_daemon_set_spec_t *v1_daemon_set_spec);

#endif /* _v1_daemon_set_spec_H_ */

