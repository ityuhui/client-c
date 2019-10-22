/*
 * v1_pod_spec.h
 *
 * PodSpec is a description of a pod.
 */

#ifndef _v1_pod_spec_H_
#define _v1_pod_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_affinity.h"
#include "v1_container.h"
#include "v1_ephemeral_container.h"
#include "v1_host_alias.h"
#include "v1_local_object_reference.h"
#include "v1_pod_dns_config.h"
#include "v1_pod_readiness_gate.h"
#include "v1_pod_security_context.h"
#include "v1_toleration.h"
#include "v1_topology_spread_constraint.h"
#include "v1_volume.h"



typedef struct v1_pod_spec_t {
    long activeDeadlineSeconds; //numeric
    v1_affinity_t *affinity; //model
    int automountServiceAccountToken; //boolean
    list_t *containers; //nonprimitive container
    v1_pod_dns_config_t *dnsConfig; //model
    char *dnsPolicy; // string
    int enableServiceLinks; //boolean
    list_t *ephemeralContainers; //nonprimitive container
    list_t *hostAliases; //nonprimitive container
    int hostIPC; //boolean
    int hostNetwork; //boolean
    int hostPID; //boolean
    char *hostname; // string
    list_t *imagePullSecrets; //nonprimitive container
    list_t *initContainers; //nonprimitive container
    char *nodeName; // string
    list_t* nodeSelector; //map
    list_t* overhead; //map
    char *preemptionPolicy; // string
    int priority; //numeric
    char *priorityClassName; // string
    list_t *readinessGates; //nonprimitive container
    char *restartPolicy; // string
    char *runtimeClassName; // string
    char *schedulerName; // string
    v1_pod_security_context_t *securityContext; //model
    char *serviceAccount; // string
    char *serviceAccountName; // string
    int shareProcessNamespace; //boolean
    char *subdomain; // string
    long terminationGracePeriodSeconds; //numeric
    list_t *tolerations; //nonprimitive container
    list_t *topologySpreadConstraints; //nonprimitive container
    list_t *volumes; //nonprimitive container

} v1_pod_spec_t;

v1_pod_spec_t *v1_pod_spec_create(
    long activeDeadlineSeconds,
    v1_affinity_t *affinity,
    int automountServiceAccountToken,
    list_t *containers,
    v1_pod_dns_config_t *dnsConfig,
    char *dnsPolicy,
    int enableServiceLinks,
    list_t *ephemeralContainers,
    list_t *hostAliases,
    int hostIPC,
    int hostNetwork,
    int hostPID,
    char *hostname,
    list_t *imagePullSecrets,
    list_t *initContainers,
    char *nodeName,
    list_t* nodeSelector,
    list_t* overhead,
    char *preemptionPolicy,
    int priority,
    char *priorityClassName,
    list_t *readinessGates,
    char *restartPolicy,
    char *runtimeClassName,
    char *schedulerName,
    v1_pod_security_context_t *securityContext,
    char *serviceAccount,
    char *serviceAccountName,
    int shareProcessNamespace,
    char *subdomain,
    long terminationGracePeriodSeconds,
    list_t *tolerations,
    list_t *topologySpreadConstraints,
    list_t *volumes
);

void v1_pod_spec_free(v1_pod_spec_t *v1_pod_spec);

v1_pod_spec_t *v1_pod_spec_parseFromJSON(cJSON *v1_pod_specJSON);

cJSON *v1_pod_spec_convertToJSON(v1_pod_spec_t *v1_pod_spec);

#endif /* _v1_pod_spec_H_ */

