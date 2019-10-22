/*
 * v1beta1_stateful_set_spec.h
 *
 * A StatefulSetSpec is the specification of a StatefulSet.
 */

#ifndef _v1beta1_stateful_set_spec_H_
#define _v1beta1_stateful_set_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_label_selector.h"
#include "v1_persistent_volume_claim.h"
#include "v1_pod_template_spec.h"
#include "v1beta1_stateful_set_update_strategy.h"



typedef struct v1beta1_stateful_set_spec_t {
    char *podManagementPolicy; // string
    int replicas; //numeric
    int revisionHistoryLimit; //numeric
    v1_label_selector_t *selector; //model
    char *serviceName; // string
    v1_pod_template_spec_t *template; //model
    v1beta1_stateful_set_update_strategy_t *updateStrategy; //model
    list_t *volumeClaimTemplates; //nonprimitive container

} v1beta1_stateful_set_spec_t;

v1beta1_stateful_set_spec_t *v1beta1_stateful_set_spec_create(
    char *podManagementPolicy,
    int replicas,
    int revisionHistoryLimit,
    v1_label_selector_t *selector,
    char *serviceName,
    v1_pod_template_spec_t *template,
    v1beta1_stateful_set_update_strategy_t *updateStrategy,
    list_t *volumeClaimTemplates
);

void v1beta1_stateful_set_spec_free(v1beta1_stateful_set_spec_t *v1beta1_stateful_set_spec);

v1beta1_stateful_set_spec_t *v1beta1_stateful_set_spec_parseFromJSON(cJSON *v1beta1_stateful_set_specJSON);

cJSON *v1beta1_stateful_set_spec_convertToJSON(v1beta1_stateful_set_spec_t *v1beta1_stateful_set_spec);

#endif /* _v1beta1_stateful_set_spec_H_ */

