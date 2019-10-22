/*
 * v1_storage_class.h
 *
 * StorageClass describes the parameters for a class of storage for which PersistentVolumes can be dynamically provisioned.  StorageClasses are non-namespaced; the name of the storage class according to etcd is in ObjectMeta.Name.
 */

#ifndef _v1_storage_class_H_
#define _v1_storage_class_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_object_meta.h"
#include "v1_topology_selector_term.h"



typedef struct v1_storage_class_t {
    int allowVolumeExpansion; //boolean
    list_t *allowedTopologies; //nonprimitive container
    char *apiVersion; // string
    char *kind; // string
    v1_object_meta_t *metadata; //model
    list_t *mountOptions; //primitive container
    list_t* parameters; //map
    char *provisioner; // string
    char *reclaimPolicy; // string
    char *volumeBindingMode; // string

} v1_storage_class_t;

v1_storage_class_t *v1_storage_class_create(
    int allowVolumeExpansion,
    list_t *allowedTopologies,
    char *apiVersion,
    char *kind,
    v1_object_meta_t *metadata,
    list_t *mountOptions,
    list_t* parameters,
    char *provisioner,
    char *reclaimPolicy,
    char *volumeBindingMode
);

void v1_storage_class_free(v1_storage_class_t *v1_storage_class);

v1_storage_class_t *v1_storage_class_parseFromJSON(cJSON *v1_storage_classJSON);

cJSON *v1_storage_class_convertToJSON(v1_storage_class_t *v1_storage_class);

#endif /* _v1_storage_class_H_ */

