/*
 * v1_stateful_set_update_strategy.h
 *
 * StatefulSetUpdateStrategy indicates the strategy that the StatefulSet controller will use to perform updates. It includes any additional parameters necessary to perform the update for the indicated strategy.
 */

#ifndef _v1_stateful_set_update_strategy_H_
#define _v1_stateful_set_update_strategy_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_rolling_update_stateful_set_strategy.h"



typedef struct v1_stateful_set_update_strategy_t {
    v1_rolling_update_stateful_set_strategy_t *rollingUpdate; //model
    char *type; // string

} v1_stateful_set_update_strategy_t;

v1_stateful_set_update_strategy_t *v1_stateful_set_update_strategy_create(
    v1_rolling_update_stateful_set_strategy_t *rollingUpdate,
    char *type
);

void v1_stateful_set_update_strategy_free(v1_stateful_set_update_strategy_t *v1_stateful_set_update_strategy);

v1_stateful_set_update_strategy_t *v1_stateful_set_update_strategy_parseFromJSON(cJSON *v1_stateful_set_update_strategyJSON);

cJSON *v1_stateful_set_update_strategy_convertToJSON(v1_stateful_set_update_strategy_t *v1_stateful_set_update_strategy);

#endif /* _v1_stateful_set_update_strategy_H_ */

