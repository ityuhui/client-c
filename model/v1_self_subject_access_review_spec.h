/*
 * v1_self_subject_access_review_spec.h
 *
 * SelfSubjectAccessReviewSpec is a description of the access request.  Exactly one of ResourceAuthorizationAttributes and NonResourceAuthorizationAttributes must be set
 */

#ifndef _v1_self_subject_access_review_spec_H_
#define _v1_self_subject_access_review_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_non_resource_attributes.h"
#include "v1_resource_attributes.h"



typedef struct v1_self_subject_access_review_spec_t {
    v1_non_resource_attributes_t *nonResourceAttributes; //model
    v1_resource_attributes_t *resourceAttributes; //model

} v1_self_subject_access_review_spec_t;

v1_self_subject_access_review_spec_t *v1_self_subject_access_review_spec_create(
    v1_non_resource_attributes_t *nonResourceAttributes,
    v1_resource_attributes_t *resourceAttributes
);

void v1_self_subject_access_review_spec_free(v1_self_subject_access_review_spec_t *v1_self_subject_access_review_spec);

v1_self_subject_access_review_spec_t *v1_self_subject_access_review_spec_parseFromJSON(cJSON *v1_self_subject_access_review_specJSON);

cJSON *v1_self_subject_access_review_spec_convertToJSON(v1_self_subject_access_review_spec_t *v1_self_subject_access_review_spec);

#endif /* _v1_self_subject_access_review_spec_H_ */

