/*
 * v1beta1_runtime_class.h
 *
 * RuntimeClass defines a class of container runtime supported in the cluster. The RuntimeClass is used to determine which container runtime is used to run all containers in a pod. RuntimeClasses are (currently) manually defined by a user or cluster provisioner, and referenced in the PodSpec. The Kubelet is responsible for resolving the RuntimeClassName reference before running the pod.  For more details, see https://git.k8s.io/enhancements/keps/sig-node/runtime-class.md
 */

#ifndef _v1beta1_runtime_class_H_
#define _v1beta1_runtime_class_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_object_meta.h"
#include "v1beta1_overhead.h"
#include "v1beta1_scheduling.h"



typedef struct v1beta1_runtime_class_t {
    char *apiVersion; // string
    char *handler; // string
    char *kind; // string
    v1_object_meta_t *metadata; //model
    v1beta1_overhead_t *overhead; //model
    v1beta1_scheduling_t *scheduling; //model

} v1beta1_runtime_class_t;

v1beta1_runtime_class_t *v1beta1_runtime_class_create(
    char *apiVersion,
    char *handler,
    char *kind,
    v1_object_meta_t *metadata,
    v1beta1_overhead_t *overhead,
    v1beta1_scheduling_t *scheduling
);

void v1beta1_runtime_class_free(v1beta1_runtime_class_t *v1beta1_runtime_class);

v1beta1_runtime_class_t *v1beta1_runtime_class_parseFromJSON(cJSON *v1beta1_runtime_classJSON);

cJSON *v1beta1_runtime_class_convertToJSON(v1beta1_runtime_class_t *v1beta1_runtime_class);

#endif /* _v1beta1_runtime_class_H_ */

