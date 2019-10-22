/*
 * v1_delete_options.h
 *
 * DeleteOptions may be provided when deleting an API object.
 */

#ifndef _v1_delete_options_H_
#define _v1_delete_options_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_preconditions.h"



typedef struct v1_delete_options_t {
    char *apiVersion; // string
    list_t *dryRun; //primitive container
    long gracePeriodSeconds; //numeric
    char *kind; // string
    int orphanDependents; //boolean
    v1_preconditions_t *preconditions; //model
    char *propagationPolicy; // string

} v1_delete_options_t;

v1_delete_options_t *v1_delete_options_create(
    char *apiVersion,
    list_t *dryRun,
    long gracePeriodSeconds,
    char *kind,
    int orphanDependents,
    v1_preconditions_t *preconditions,
    char *propagationPolicy
);

void v1_delete_options_free(v1_delete_options_t *v1_delete_options);

v1_delete_options_t *v1_delete_options_parseFromJSON(cJSON *v1_delete_optionsJSON);

cJSON *v1_delete_options_convertToJSON(v1_delete_options_t *v1_delete_options);

#endif /* _v1_delete_options_H_ */

