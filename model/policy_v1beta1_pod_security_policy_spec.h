/*
 * policy_v1beta1_pod_security_policy_spec.h
 *
 * PodSecurityPolicySpec defines the policy enforced.
 */

#ifndef _policy_v1beta1_pod_security_policy_spec_H_
#define _policy_v1beta1_pod_security_policy_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "policy_v1beta1_allowed_csi_driver.h"
#include "policy_v1beta1_allowed_flex_volume.h"
#include "policy_v1beta1_allowed_host_path.h"
#include "policy_v1beta1_fs_group_strategy_options.h"
#include "policy_v1beta1_host_port_range.h"
#include "policy_v1beta1_run_as_group_strategy_options.h"
#include "policy_v1beta1_run_as_user_strategy_options.h"
#include "policy_v1beta1_runtime_class_strategy_options.h"
#include "policy_v1beta1_se_linux_strategy_options.h"
#include "policy_v1beta1_supplemental_groups_strategy_options.h"



typedef struct policy_v1beta1_pod_security_policy_spec_t {
    int allowPrivilegeEscalation; //boolean
    list_t *allowedCSIDrivers; //nonprimitive container
    list_t *allowedCapabilities; //primitive container
    list_t *allowedFlexVolumes; //nonprimitive container
    list_t *allowedHostPaths; //nonprimitive container
    list_t *allowedProcMountTypes; //primitive container
    list_t *allowedUnsafeSysctls; //primitive container
    list_t *defaultAddCapabilities; //primitive container
    int defaultAllowPrivilegeEscalation; //boolean
    list_t *forbiddenSysctls; //primitive container
    policy_v1beta1_fs_group_strategy_options_t *fsGroup; //model
    int hostIPC; //boolean
    int hostNetwork; //boolean
    int hostPID; //boolean
    list_t *hostPorts; //nonprimitive container
    int privileged; //boolean
    int readOnlyRootFilesystem; //boolean
    list_t *requiredDropCapabilities; //primitive container
    policy_v1beta1_run_as_group_strategy_options_t *runAsGroup; //model
    policy_v1beta1_run_as_user_strategy_options_t *runAsUser; //model
    policy_v1beta1_runtime_class_strategy_options_t *runtimeClass; //model
    policy_v1beta1_se_linux_strategy_options_t *seLinux; //model
    policy_v1beta1_supplemental_groups_strategy_options_t *supplementalGroups; //model
    list_t *volumes; //primitive container

} policy_v1beta1_pod_security_policy_spec_t;

policy_v1beta1_pod_security_policy_spec_t *policy_v1beta1_pod_security_policy_spec_create(
    int allowPrivilegeEscalation,
    list_t *allowedCSIDrivers,
    list_t *allowedCapabilities,
    list_t *allowedFlexVolumes,
    list_t *allowedHostPaths,
    list_t *allowedProcMountTypes,
    list_t *allowedUnsafeSysctls,
    list_t *defaultAddCapabilities,
    int defaultAllowPrivilegeEscalation,
    list_t *forbiddenSysctls,
    policy_v1beta1_fs_group_strategy_options_t *fsGroup,
    int hostIPC,
    int hostNetwork,
    int hostPID,
    list_t *hostPorts,
    int privileged,
    int readOnlyRootFilesystem,
    list_t *requiredDropCapabilities,
    policy_v1beta1_run_as_group_strategy_options_t *runAsGroup,
    policy_v1beta1_run_as_user_strategy_options_t *runAsUser,
    policy_v1beta1_runtime_class_strategy_options_t *runtimeClass,
    policy_v1beta1_se_linux_strategy_options_t *seLinux,
    policy_v1beta1_supplemental_groups_strategy_options_t *supplementalGroups,
    list_t *volumes
);

void policy_v1beta1_pod_security_policy_spec_free(policy_v1beta1_pod_security_policy_spec_t *policy_v1beta1_pod_security_policy_spec);

policy_v1beta1_pod_security_policy_spec_t *policy_v1beta1_pod_security_policy_spec_parseFromJSON(cJSON *policy_v1beta1_pod_security_policy_specJSON);

cJSON *policy_v1beta1_pod_security_policy_spec_convertToJSON(policy_v1beta1_pod_security_policy_spec_t *policy_v1beta1_pod_security_policy_spec);

#endif /* _policy_v1beta1_pod_security_policy_spec_H_ */

