/*
 * v1_container.h
 *
 * A single application container that you want to run within a pod.
 */

#ifndef _v1_container_H_
#define _v1_container_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_container_port.h"
#include "v1_env_from_source.h"
#include "v1_env_var.h"
#include "v1_lifecycle.h"
#include "v1_probe.h"
#include "v1_resource_requirements.h"
#include "v1_security_context.h"
#include "v1_volume_device.h"
#include "v1_volume_mount.h"



typedef struct v1_container_t {
    list_t *args; //primitive container
    list_t *command; //primitive container
    list_t *env; //nonprimitive container
    list_t *envFrom; //nonprimitive container
    char *image; // string
    char *imagePullPolicy; // string
    v1_lifecycle_t *lifecycle; //model
    v1_probe_t *livenessProbe; //model
    char *name; // string
    list_t *ports; //nonprimitive container
    v1_probe_t *readinessProbe; //model
    v1_resource_requirements_t *resources; //model
    v1_security_context_t *securityContext; //model
    v1_probe_t *startupProbe; //model
    int stdin; //boolean
    int stdinOnce; //boolean
    char *terminationMessagePath; // string
    char *terminationMessagePolicy; // string
    int tty; //boolean
    list_t *volumeDevices; //nonprimitive container
    list_t *volumeMounts; //nonprimitive container
    char *workingDir; // string

} v1_container_t;

v1_container_t *v1_container_create(
    list_t *args,
    list_t *command,
    list_t *env,
    list_t *envFrom,
    char *image,
    char *imagePullPolicy,
    v1_lifecycle_t *lifecycle,
    v1_probe_t *livenessProbe,
    char *name,
    list_t *ports,
    v1_probe_t *readinessProbe,
    v1_resource_requirements_t *resources,
    v1_security_context_t *securityContext,
    v1_probe_t *startupProbe,
    int stdin,
    int stdinOnce,
    char *terminationMessagePath,
    char *terminationMessagePolicy,
    int tty,
    list_t *volumeDevices,
    list_t *volumeMounts,
    char *workingDir
);

void v1_container_free(v1_container_t *v1_container);

v1_container_t *v1_container_parseFromJSON(cJSON *v1_containerJSON);

cJSON *v1_container_convertToJSON(v1_container_t *v1_container);

#endif /* _v1_container_H_ */

