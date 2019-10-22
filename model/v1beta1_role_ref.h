/*
 * v1beta1_role_ref.h
 *
 * RoleRef contains information that points to the role being used
 */

#ifndef _v1beta1_role_ref_H_
#define _v1beta1_role_ref_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v1beta1_role_ref_t {
    char *apiGroup; // string
    char *kind; // string
    char *name; // string

} v1beta1_role_ref_t;

v1beta1_role_ref_t *v1beta1_role_ref_create(
    char *apiGroup,
    char *kind,
    char *name
);

void v1beta1_role_ref_free(v1beta1_role_ref_t *v1beta1_role_ref);

v1beta1_role_ref_t *v1beta1_role_ref_parseFromJSON(cJSON *v1beta1_role_refJSON);

cJSON *v1beta1_role_ref_convertToJSON(v1beta1_role_ref_t *v1beta1_role_ref);

#endif /* _v1beta1_role_ref_H_ */

