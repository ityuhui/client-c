/*
 * ego_v1_activity_spec.h
 *
 */

#ifndef _ego_v1_activity_spec_H_
#define _ego_v1_activity_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"


typedef struct ego_v1_activity_spec {
    char *host; 
    char *command;      /**< argc and argv to execute           */
    char *execuser;     /**< execution user name                */
    char *execcwd;      /**< execution working directory        */
    list_t *envs;       /**< environment variables              */
} ego_v1_activity_spec_t;

ego_v1_activity_spec_t *ego_v1_activity_spec_create(
    char *host, // string
    char *command,// string
    char *execuser,
    char *execcwd,
    list_t *envs
);

void ego_v1_activity_spec_free(ego_v1_activity_spec_t *ego_v1_activity_spec);

ego_v1_activity_spec_t *ego_v1_activity_spec_parseFromJSON(cJSON *ego_v1_activity_specJSON);

cJSON *ego_v1_activity_spec_convertToJSON(ego_v1_activity_spec_t *ego_v1_activity_spec);

#endif /* _ego_v1_activity_spec_H_ */

