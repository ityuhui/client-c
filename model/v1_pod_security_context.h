/*
 * v1_pod_security_context.h
 *
 * PodSecurityContext holds pod-level security attributes and common container settings. Some fields are also present in container.securityContext.  Field values of container.securityContext take precedence over field values of PodSecurityContext.
 */

#ifndef _v1_pod_security_context_H_
#define _v1_pod_security_context_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_se_linux_options.h"
#include "v1_sysctl.h"
#include "v1_windows_security_context_options.h"



typedef struct v1_pod_security_context_t {
    long fsGroup; //numeric
    long runAsGroup; //numeric
    int runAsNonRoot; //boolean
    long runAsUser; //numeric
    v1_se_linux_options_t *seLinuxOptions; //model
    list_t *supplementalGroups; //primitive container
    list_t *sysctls; //nonprimitive container
    v1_windows_security_context_options_t *windowsOptions; //model

} v1_pod_security_context_t;

v1_pod_security_context_t *v1_pod_security_context_create(
    long fsGroup,
    long runAsGroup,
    int runAsNonRoot,
    long runAsUser,
    v1_se_linux_options_t *seLinuxOptions,
    list_t *supplementalGroups,
    list_t *sysctls,
    v1_windows_security_context_options_t *windowsOptions
);

void v1_pod_security_context_free(v1_pod_security_context_t *v1_pod_security_context);

v1_pod_security_context_t *v1_pod_security_context_parseFromJSON(cJSON *v1_pod_security_contextJSON);

cJSON *v1_pod_security_context_convertToJSON(v1_pod_security_context_t *v1_pod_security_context);

#endif /* _v1_pod_security_context_H_ */

