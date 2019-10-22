/*
 * v1_windows_security_context_options.h
 *
 * WindowsSecurityContextOptions contain Windows-specific options and credentials.
 */

#ifndef _v1_windows_security_context_options_H_
#define _v1_windows_security_context_options_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v1_windows_security_context_options_t {
    char *gmsaCredentialSpec; // string
    char *gmsaCredentialSpecName; // string
    char *runAsUserName; // string

} v1_windows_security_context_options_t;

v1_windows_security_context_options_t *v1_windows_security_context_options_create(
    char *gmsaCredentialSpec,
    char *gmsaCredentialSpecName,
    char *runAsUserName
);

void v1_windows_security_context_options_free(v1_windows_security_context_options_t *v1_windows_security_context_options);

v1_windows_security_context_options_t *v1_windows_security_context_options_parseFromJSON(cJSON *v1_windows_security_context_optionsJSON);

cJSON *v1_windows_security_context_options_convertToJSON(v1_windows_security_context_options_t *v1_windows_security_context_options);

#endif /* _v1_windows_security_context_options_H_ */

