/*
 * v1_security_context.h
 *
 * SecurityContext holds security configuration that will be applied to a container. Some fields are present in both SecurityContext and PodSecurityContext.  When both are set, the values in SecurityContext take precedence.
 */

#ifndef _v1_security_context_H_
#define _v1_security_context_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_capabilities.h"
#include "v1_se_linux_options.h"
#include "v1_windows_security_context_options.h"



typedef struct v1_security_context_t {
    int allowPrivilegeEscalation; //boolean
    v1_capabilities_t *capabilities; //model
    int privileged; //boolean
    char *procMount; // string
    int readOnlyRootFilesystem; //boolean
    long runAsGroup; //numeric
    int runAsNonRoot; //boolean
    long runAsUser; //numeric
    v1_se_linux_options_t *seLinuxOptions; //model
    v1_windows_security_context_options_t *windowsOptions; //model

} v1_security_context_t;

v1_security_context_t *v1_security_context_create(
    int allowPrivilegeEscalation,
    v1_capabilities_t *capabilities,
    int privileged,
    char *procMount,
    int readOnlyRootFilesystem,
    long runAsGroup,
    int runAsNonRoot,
    long runAsUser,
    v1_se_linux_options_t *seLinuxOptions,
    v1_windows_security_context_options_t *windowsOptions
);

void v1_security_context_free(v1_security_context_t *v1_security_context);

v1_security_context_t *v1_security_context_parseFromJSON(cJSON *v1_security_contextJSON);

cJSON *v1_security_context_convertToJSON(v1_security_context_t *v1_security_context);

#endif /* _v1_security_context_H_ */

