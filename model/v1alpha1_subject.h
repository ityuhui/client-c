/*
 * v1alpha1_subject.h
 *
 * Subject contains a reference to the object or user identities a role binding applies to.  This can either hold a direct API object reference, or a value for non-objects such as user and group names.
 */

#ifndef _v1alpha1_subject_H_
#define _v1alpha1_subject_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v1alpha1_subject_t {
    char *apiVersion; // string
    char *kind; // string
    char *name; // string
    char *namespace; // string

} v1alpha1_subject_t;

v1alpha1_subject_t *v1alpha1_subject_create(
    char *apiVersion,
    char *kind,
    char *name,
    char *namespace
);

void v1alpha1_subject_free(v1alpha1_subject_t *v1alpha1_subject);

v1alpha1_subject_t *v1alpha1_subject_parseFromJSON(cJSON *v1alpha1_subjectJSON);

cJSON *v1alpha1_subject_convertToJSON(v1alpha1_subject_t *v1alpha1_subject);

#endif /* _v1alpha1_subject_H_ */

