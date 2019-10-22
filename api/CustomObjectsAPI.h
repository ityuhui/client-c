#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../model/object.h"
#include "../model/v1_delete_options.h"


// Creates a cluster scoped Custom object
//
object_t*
CustomObjectsAPI_createClusterCustomObject(apiClient_t *apiClient ,char * group ,char * version ,char * plural , body ,char * pretty);


// Creates a namespace scoped Custom object
//
object_t*
CustomObjectsAPI_createNamespacedCustomObject(apiClient_t *apiClient ,char * group ,char * version ,char * namespace ,char * plural , body ,char * pretty);


// Deletes the specified cluster scoped custom object
//
object_t*
CustomObjectsAPI_deleteClusterCustomObject(apiClient_t *apiClient ,char * group ,char * version ,char * plural ,char * name ,v1_delete_options_t * body ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy);


// Deletes the specified namespace scoped custom object
//
object_t*
CustomObjectsAPI_deleteNamespacedCustomObject(apiClient_t *apiClient ,char * group ,char * version ,char * namespace ,char * plural ,char * name ,v1_delete_options_t * body ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy);


// Returns a cluster scoped custom object
//
object_t*
CustomObjectsAPI_getClusterCustomObject(apiClient_t *apiClient ,char * group ,char * version ,char * plural ,char * name);


// read scale of the specified custom object
//
object_t*
CustomObjectsAPI_getClusterCustomObjectScale(apiClient_t *apiClient ,char * group ,char * version ,char * plural ,char * name);


// read status of the specified cluster scoped custom object
//
object_t*
CustomObjectsAPI_getClusterCustomObjectStatus(apiClient_t *apiClient ,char * group ,char * version ,char * plural ,char * name);


// Returns a namespace scoped custom object
//
object_t*
CustomObjectsAPI_getNamespacedCustomObject(apiClient_t *apiClient ,char * group ,char * version ,char * namespace ,char * plural ,char * name);


// read scale of the specified namespace scoped custom object
//
object_t*
CustomObjectsAPI_getNamespacedCustomObjectScale(apiClient_t *apiClient ,char * group ,char * version ,char * namespace ,char * plural ,char * name);


// read status of the specified namespace scoped custom object
//
object_t*
CustomObjectsAPI_getNamespacedCustomObjectStatus(apiClient_t *apiClient ,char * group ,char * version ,char * namespace ,char * plural ,char * name);


// list or watch cluster scoped custom objects
//
object_t*
CustomObjectsAPI_listClusterCustomObject(apiClient_t *apiClient ,char * group ,char * version ,char * plural ,char * pretty ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// list or watch namespace scoped custom objects
//
object_t*
CustomObjectsAPI_listNamespacedCustomObject(apiClient_t *apiClient ,char * group ,char * version ,char * namespace ,char * plural ,char * pretty ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch);


// patch the specified cluster scoped custom object
//
object_t*
CustomObjectsAPI_patchClusterCustomObject(apiClient_t *apiClient ,char * group ,char * version ,char * plural ,char * name , body);


// partially update scale of the specified cluster scoped custom object
//
object_t*
CustomObjectsAPI_patchClusterCustomObjectScale(apiClient_t *apiClient ,char * group ,char * version ,char * plural ,char * name , body);


// partially update status of the specified cluster scoped custom object
//
object_t*
CustomObjectsAPI_patchClusterCustomObjectStatus(apiClient_t *apiClient ,char * group ,char * version ,char * plural ,char * name , body);


// patch the specified namespace scoped custom object
//
object_t*
CustomObjectsAPI_patchNamespacedCustomObject(apiClient_t *apiClient ,char * group ,char * version ,char * namespace ,char * plural ,char * name , body);


// partially update scale of the specified namespace scoped custom object
//
object_t*
CustomObjectsAPI_patchNamespacedCustomObjectScale(apiClient_t *apiClient ,char * group ,char * version ,char * namespace ,char * plural ,char * name , body);


// partially update status of the specified namespace scoped custom object
//
object_t*
CustomObjectsAPI_patchNamespacedCustomObjectStatus(apiClient_t *apiClient ,char * group ,char * version ,char * namespace ,char * plural ,char * name , body);


// replace the specified cluster scoped custom object
//
object_t*
CustomObjectsAPI_replaceClusterCustomObject(apiClient_t *apiClient ,char * group ,char * version ,char * plural ,char * name , body);


// replace scale of the specified cluster scoped custom object
//
object_t*
CustomObjectsAPI_replaceClusterCustomObjectScale(apiClient_t *apiClient ,char * group ,char * version ,char * plural ,char * name , body);


// replace status of the cluster scoped specified custom object
//
object_t*
CustomObjectsAPI_replaceClusterCustomObjectStatus(apiClient_t *apiClient ,char * group ,char * version ,char * plural ,char * name , body);


// replace the specified namespace scoped custom object
//
object_t*
CustomObjectsAPI_replaceNamespacedCustomObject(apiClient_t *apiClient ,char * group ,char * version ,char * namespace ,char * plural ,char * name , body);


// replace scale of the specified namespace scoped custom object
//
object_t*
CustomObjectsAPI_replaceNamespacedCustomObjectScale(apiClient_t *apiClient ,char * group ,char * version ,char * namespace ,char * plural ,char * name , body);


// replace status of the specified namespace scoped custom object
//
object_t*
CustomObjectsAPI_replaceNamespacedCustomObjectStatus(apiClient_t *apiClient ,char * group ,char * version ,char * namespace ,char * plural ,char * name , body);


