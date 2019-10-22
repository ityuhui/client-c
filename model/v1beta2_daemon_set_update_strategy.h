/*
 * v1beta2_daemon_set_update_strategy.h
 *
 * DaemonSetUpdateStrategy is a struct used to control the update strategy for a DaemonSet.
 */

#ifndef _v1beta2_daemon_set_update_strategy_H_
#define _v1beta2_daemon_set_update_strategy_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1beta2_rolling_update_daemon_set.h"



typedef struct v1beta2_daemon_set_update_strategy_t {
    v1beta2_rolling_update_daemon_set_t *rollingUpdate; //model
    char *type; // string

} v1beta2_daemon_set_update_strategy_t;

v1beta2_daemon_set_update_strategy_t *v1beta2_daemon_set_update_strategy_create(
    v1beta2_rolling_update_daemon_set_t *rollingUpdate,
    char *type
);

void v1beta2_daemon_set_update_strategy_free(v1beta2_daemon_set_update_strategy_t *v1beta2_daemon_set_update_strategy);

v1beta2_daemon_set_update_strategy_t *v1beta2_daemon_set_update_strategy_parseFromJSON(cJSON *v1beta2_daemon_set_update_strategyJSON);

cJSON *v1beta2_daemon_set_update_strategy_convertToJSON(v1beta2_daemon_set_update_strategy_t *v1beta2_daemon_set_update_strategy);

#endif /* _v1beta2_daemon_set_update_strategy_H_ */

