/*
 * v1beta2_daemon_set_spec.h
 *
 * DaemonSetSpec is the specification of a daemon set.
 */

#ifndef _v1beta2_daemon_set_spec_H_
#define _v1beta2_daemon_set_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_label_selector.h"
#include "v1_pod_template_spec.h"
#include "v1beta2_daemon_set_update_strategy.h"



typedef struct v1beta2_daemon_set_spec_t {
    int minReadySeconds; //numeric
    int revisionHistoryLimit; //numeric
    v1_label_selector_t *selector; //model
    v1_pod_template_spec_t *template; //model
    v1beta2_daemon_set_update_strategy_t *updateStrategy; //model

} v1beta2_daemon_set_spec_t;

v1beta2_daemon_set_spec_t *v1beta2_daemon_set_spec_create(
    int minReadySeconds,
    int revisionHistoryLimit,
    v1_label_selector_t *selector,
    v1_pod_template_spec_t *template,
    v1beta2_daemon_set_update_strategy_t *updateStrategy
);

void v1beta2_daemon_set_spec_free(v1beta2_daemon_set_spec_t *v1beta2_daemon_set_spec);

v1beta2_daemon_set_spec_t *v1beta2_daemon_set_spec_parseFromJSON(cJSON *v1beta2_daemon_set_specJSON);

cJSON *v1beta2_daemon_set_spec_convertToJSON(v1beta2_daemon_set_spec_t *v1beta2_daemon_set_spec);

#endif /* _v1beta2_daemon_set_spec_H_ */

