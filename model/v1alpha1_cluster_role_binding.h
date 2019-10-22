/*
 * v1alpha1_cluster_role_binding.h
 *
 * ClusterRoleBinding references a ClusterRole, but not_ contain it.  It can reference a ClusterRole in the global namespace, and adds who information via Subject.
 */

#ifndef _v1alpha1_cluster_role_binding_H_
#define _v1alpha1_cluster_role_binding_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_object_meta.h"
#include "v1alpha1_role_ref.h"
#include "v1alpha1_subject.h"



typedef struct v1alpha1_cluster_role_binding_t {
    char *apiVersion; // string
    char *kind; // string
    v1_object_meta_t *metadata; //model
    v1alpha1_role_ref_t *roleRef; //model
    list_t *subjects; //nonprimitive container

} v1alpha1_cluster_role_binding_t;

v1alpha1_cluster_role_binding_t *v1alpha1_cluster_role_binding_create(
    char *apiVersion,
    char *kind,
    v1_object_meta_t *metadata,
    v1alpha1_role_ref_t *roleRef,
    list_t *subjects
);

void v1alpha1_cluster_role_binding_free(v1alpha1_cluster_role_binding_t *v1alpha1_cluster_role_binding);

v1alpha1_cluster_role_binding_t *v1alpha1_cluster_role_binding_parseFromJSON(cJSON *v1alpha1_cluster_role_bindingJSON);

cJSON *v1alpha1_cluster_role_binding_convertToJSON(v1alpha1_cluster_role_binding_t *v1alpha1_cluster_role_binding);

#endif /* _v1alpha1_cluster_role_binding_H_ */

