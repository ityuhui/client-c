#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "AppsV1API.h"


#define MAX_BUFFER_LENGTH 4096
#define intToStr(dst, src) \
    do {\
    char dst[256];\
    snprintf(dst, 256, "%ld", (long int)(src));\
}while(0)

// create a ControllerRevision
//
v1_controller_revision_t*
AppsV1API_createAppsV1NamespacedControllerRevision(apiClient_t *apiClient ,char * namespace ,v1_controller_revision_t * body ,char * pretty ,char * dryRun ,char * fieldManager)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/controllerrevisions")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/controllerrevisions");


    // Path Params
    long sizeOfPathParams_namespace = strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



    // query parameters
    char *keyQuery_pretty;
    char * valueQuery_pretty;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }

    // query parameters
    char *keyQuery_dryRun;
    char * valueQuery_dryRun;
    keyValuePair_t *keyPairQuery_dryRun = 0;
    if (dryRun)
    {
        keyQuery_dryRun = strdup("dryRun");
        valueQuery_dryRun = strdup((dryRun));
        keyPairQuery_dryRun = keyValuePair_create(keyQuery_dryRun, valueQuery_dryRun);
        list_addElement(localVarQueryParameters,keyPairQuery_dryRun);
    }

    // query parameters
    char *keyQuery_fieldManager;
    char * valueQuery_fieldManager;
    keyValuePair_t *keyPairQuery_fieldManager = 0;
    if (fieldManager)
    {
        keyQuery_fieldManager = strdup("fieldManager");
        valueQuery_fieldManager = strdup((fieldManager));
        keyPairQuery_fieldManager = keyValuePair_create(keyQuery_fieldManager, valueQuery_fieldManager);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldManager);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = v1_controller_revision_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "POST");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 201) {
        printf("%s\n","Created");
    }
    if (apiClient->response_code == 202) {
        printf("%s\n","Accepted");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not_ container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_controller_revision_t *elementToReturn = v1_controller_revision_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_namespace);
    cJSON_Delete(localVarSingleItemJSON_body);
    free(localVarBodyParameters);
    free(keyQuery_pretty);
    free(valueQuery_pretty);
    keyValuePair_free(keyPairQuery_pretty);
    free(keyQuery_dryRun);
    free(valueQuery_dryRun);
    keyValuePair_free(keyPairQuery_dryRun);
    free(keyQuery_fieldManager);
    free(valueQuery_fieldManager);
    keyValuePair_free(keyPairQuery_fieldManager);
    return elementToReturn;
end:
    return NULL;

}

// create a DaemonSet
//
v1_daemon_set_t*
AppsV1API_createAppsV1NamespacedDaemonSet(apiClient_t *apiClient ,char * namespace ,v1_daemon_set_t * body ,char * pretty ,char * dryRun ,char * fieldManager)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/daemonsets")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/daemonsets");


    // Path Params
    long sizeOfPathParams_namespace = strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



    // query parameters
    char *keyQuery_pretty;
    char * valueQuery_pretty;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }

    // query parameters
    char *keyQuery_dryRun;
    char * valueQuery_dryRun;
    keyValuePair_t *keyPairQuery_dryRun = 0;
    if (dryRun)
    {
        keyQuery_dryRun = strdup("dryRun");
        valueQuery_dryRun = strdup((dryRun));
        keyPairQuery_dryRun = keyValuePair_create(keyQuery_dryRun, valueQuery_dryRun);
        list_addElement(localVarQueryParameters,keyPairQuery_dryRun);
    }

    // query parameters
    char *keyQuery_fieldManager;
    char * valueQuery_fieldManager;
    keyValuePair_t *keyPairQuery_fieldManager = 0;
    if (fieldManager)
    {
        keyQuery_fieldManager = strdup("fieldManager");
        valueQuery_fieldManager = strdup((fieldManager));
        keyPairQuery_fieldManager = keyValuePair_create(keyQuery_fieldManager, valueQuery_fieldManager);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldManager);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = v1_daemon_set_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "POST");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 201) {
        printf("%s\n","Created");
    }
    if (apiClient->response_code == 202) {
        printf("%s\n","Accepted");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not_ container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_daemon_set_t *elementToReturn = v1_daemon_set_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_namespace);
    cJSON_Delete(localVarSingleItemJSON_body);
    free(localVarBodyParameters);
    free(keyQuery_pretty);
    free(valueQuery_pretty);
    keyValuePair_free(keyPairQuery_pretty);
    free(keyQuery_dryRun);
    free(valueQuery_dryRun);
    keyValuePair_free(keyPairQuery_dryRun);
    free(keyQuery_fieldManager);
    free(valueQuery_fieldManager);
    keyValuePair_free(keyPairQuery_fieldManager);
    return elementToReturn;
end:
    return NULL;

}

// create a Deployment
//
v1_deployment_t*
AppsV1API_createAppsV1NamespacedDeployment(apiClient_t *apiClient ,char * namespace ,v1_deployment_t * body ,char * pretty ,char * dryRun ,char * fieldManager)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/deployments")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/deployments");


    // Path Params
    long sizeOfPathParams_namespace = strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



    // query parameters
    char *keyQuery_pretty;
    char * valueQuery_pretty;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }

    // query parameters
    char *keyQuery_dryRun;
    char * valueQuery_dryRun;
    keyValuePair_t *keyPairQuery_dryRun = 0;
    if (dryRun)
    {
        keyQuery_dryRun = strdup("dryRun");
        valueQuery_dryRun = strdup((dryRun));
        keyPairQuery_dryRun = keyValuePair_create(keyQuery_dryRun, valueQuery_dryRun);
        list_addElement(localVarQueryParameters,keyPairQuery_dryRun);
    }

    // query parameters
    char *keyQuery_fieldManager;
    char * valueQuery_fieldManager;
    keyValuePair_t *keyPairQuery_fieldManager = 0;
    if (fieldManager)
    {
        keyQuery_fieldManager = strdup("fieldManager");
        valueQuery_fieldManager = strdup((fieldManager));
        keyPairQuery_fieldManager = keyValuePair_create(keyQuery_fieldManager, valueQuery_fieldManager);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldManager);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = v1_deployment_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "POST");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 201) {
        printf("%s\n","Created");
    }
    if (apiClient->response_code == 202) {
        printf("%s\n","Accepted");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not_ container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_deployment_t *elementToReturn = v1_deployment_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_namespace);
    cJSON_Delete(localVarSingleItemJSON_body);
    free(localVarBodyParameters);
    free(keyQuery_pretty);
    free(valueQuery_pretty);
    keyValuePair_free(keyPairQuery_pretty);
    free(keyQuery_dryRun);
    free(valueQuery_dryRun);
    keyValuePair_free(keyPairQuery_dryRun);
    free(keyQuery_fieldManager);
    free(valueQuery_fieldManager);
    keyValuePair_free(keyPairQuery_fieldManager);
    return elementToReturn;
end:
    return NULL;

}

// create a ReplicaSet
//
v1_replica_set_t*
AppsV1API_createAppsV1NamespacedReplicaSet(apiClient_t *apiClient ,char * namespace ,v1_replica_set_t * body ,char * pretty ,char * dryRun ,char * fieldManager)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/replicasets")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/replicasets");


    // Path Params
    long sizeOfPathParams_namespace = strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



    // query parameters
    char *keyQuery_pretty;
    char * valueQuery_pretty;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }

    // query parameters
    char *keyQuery_dryRun;
    char * valueQuery_dryRun;
    keyValuePair_t *keyPairQuery_dryRun = 0;
    if (dryRun)
    {
        keyQuery_dryRun = strdup("dryRun");
        valueQuery_dryRun = strdup((dryRun));
        keyPairQuery_dryRun = keyValuePair_create(keyQuery_dryRun, valueQuery_dryRun);
        list_addElement(localVarQueryParameters,keyPairQuery_dryRun);
    }

    // query parameters
    char *keyQuery_fieldManager;
    char * valueQuery_fieldManager;
    keyValuePair_t *keyPairQuery_fieldManager = 0;
    if (fieldManager)
    {
        keyQuery_fieldManager = strdup("fieldManager");
        valueQuery_fieldManager = strdup((fieldManager));
        keyPairQuery_fieldManager = keyValuePair_create(keyQuery_fieldManager, valueQuery_fieldManager);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldManager);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = v1_replica_set_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "POST");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 201) {
        printf("%s\n","Created");
    }
    if (apiClient->response_code == 202) {
        printf("%s\n","Accepted");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not_ container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_replica_set_t *elementToReturn = v1_replica_set_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_namespace);
    cJSON_Delete(localVarSingleItemJSON_body);
    free(localVarBodyParameters);
    free(keyQuery_pretty);
    free(valueQuery_pretty);
    keyValuePair_free(keyPairQuery_pretty);
    free(keyQuery_dryRun);
    free(valueQuery_dryRun);
    keyValuePair_free(keyPairQuery_dryRun);
    free(keyQuery_fieldManager);
    free(valueQuery_fieldManager);
    keyValuePair_free(keyPairQuery_fieldManager);
    return elementToReturn;
end:
    return NULL;

}

// create a StatefulSet
//
v1_stateful_set_t*
AppsV1API_createAppsV1NamespacedStatefulSet(apiClient_t *apiClient ,char * namespace ,v1_stateful_set_t * body ,char * pretty ,char * dryRun ,char * fieldManager)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/statefulsets")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/statefulsets");


    // Path Params
    long sizeOfPathParams_namespace = strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



    // query parameters
    char *keyQuery_pretty;
    char * valueQuery_pretty;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }

    // query parameters
    char *keyQuery_dryRun;
    char * valueQuery_dryRun;
    keyValuePair_t *keyPairQuery_dryRun = 0;
    if (dryRun)
    {
        keyQuery_dryRun = strdup("dryRun");
        valueQuery_dryRun = strdup((dryRun));
        keyPairQuery_dryRun = keyValuePair_create(keyQuery_dryRun, valueQuery_dryRun);
        list_addElement(localVarQueryParameters,keyPairQuery_dryRun);
    }

    // query parameters
    char *keyQuery_fieldManager;
    char * valueQuery_fieldManager;
    keyValuePair_t *keyPairQuery_fieldManager = 0;
    if (fieldManager)
    {
        keyQuery_fieldManager = strdup("fieldManager");
        valueQuery_fieldManager = strdup((fieldManager));
        keyPairQuery_fieldManager = keyValuePair_create(keyQuery_fieldManager, valueQuery_fieldManager);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldManager);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = v1_stateful_set_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "POST");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 201) {
        printf("%s\n","Created");
    }
    if (apiClient->response_code == 202) {
        printf("%s\n","Accepted");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not_ container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_stateful_set_t *elementToReturn = v1_stateful_set_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_namespace);
    cJSON_Delete(localVarSingleItemJSON_body);
    free(localVarBodyParameters);
    free(keyQuery_pretty);
    free(valueQuery_pretty);
    keyValuePair_free(keyPairQuery_pretty);
    free(keyQuery_dryRun);
    free(valueQuery_dryRun);
    keyValuePair_free(keyPairQuery_dryRun);
    free(keyQuery_fieldManager);
    free(valueQuery_fieldManager);
    keyValuePair_free(keyPairQuery_fieldManager);
    return elementToReturn;
end:
    return NULL;

}

// delete collection of ControllerRevision
//
v1_status_t*
AppsV1API_deleteAppsV1CollectionNamespacedControllerRevision(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/controllerrevisions")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/controllerrevisions");


    // Path Params
    long sizeOfPathParams_namespace = strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



    // query parameters
    char *keyQuery_pretty;
    char * valueQuery_pretty;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }

    // query parameters
    char *keyQuery_allowWatchBookmarks;
    int valueQuery_allowWatchBookmarks;
    keyValuePair_t *keyPairQuery_allowWatchBookmarks = 0;
    if (allowWatchBookmarks)
    {
        keyQuery_allowWatchBookmarks = strdup("allowWatchBookmarks");
        valueQuery_allowWatchBookmarks = (allowWatchBookmarks);
        keyPairQuery_allowWatchBookmarks = keyValuePair_create(keyQuery_allowWatchBookmarks, &valueQuery_allowWatchBookmarks);
        list_addElement(localVarQueryParameters,keyPairQuery_allowWatchBookmarks);
    }

    // query parameters
    char *keyQuery_continue;
    char * valueQuery_continue;
    keyValuePair_t *keyPairQuery_continue = 0;
    if (continue_)
    {
        keyQuery_continue = strdup("continue_");
        valueQuery_continue = strdup((continue_));
        keyPairQuery_continue = keyValuePair_create(keyQuery_continue, valueQuery_continue);
        list_addElement(localVarQueryParameters,keyPairQuery_continue);
    }

    // query parameters
    char *keyQuery_dryRun;
    char * valueQuery_dryRun;
    keyValuePair_t *keyPairQuery_dryRun = 0;
    if (dryRun)
    {
        keyQuery_dryRun = strdup("dryRun");
        valueQuery_dryRun = strdup((dryRun));
        keyPairQuery_dryRun = keyValuePair_create(keyQuery_dryRun, valueQuery_dryRun);
        list_addElement(localVarQueryParameters,keyPairQuery_dryRun);
    }

    // query parameters
    char *keyQuery_fieldSelector;
    char * valueQuery_fieldSelector;
    keyValuePair_t *keyPairQuery_fieldSelector = 0;
    if (fieldSelector)
    {
        keyQuery_fieldSelector = strdup("fieldSelector");
        valueQuery_fieldSelector = strdup((fieldSelector));
        keyPairQuery_fieldSelector = keyValuePair_create(keyQuery_fieldSelector, valueQuery_fieldSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldSelector);
    }

    // query parameters
    char *keyQuery_gracePeriodSeconds;
    int valueQuery_gracePeriodSeconds;
    keyValuePair_t *keyPairQuery_gracePeriodSeconds = 0;
    if (gracePeriodSeconds)
    {
        keyQuery_gracePeriodSeconds = strdup("gracePeriodSeconds");
        valueQuery_gracePeriodSeconds = (gracePeriodSeconds);
        keyPairQuery_gracePeriodSeconds = keyValuePair_create(keyQuery_gracePeriodSeconds, &valueQuery_gracePeriodSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_gracePeriodSeconds);
    }

    // query parameters
    char *keyQuery_labelSelector;
    char * valueQuery_labelSelector;
    keyValuePair_t *keyPairQuery_labelSelector = 0;
    if (labelSelector)
    {
        keyQuery_labelSelector = strdup("labelSelector");
        valueQuery_labelSelector = strdup((labelSelector));
        keyPairQuery_labelSelector = keyValuePair_create(keyQuery_labelSelector, valueQuery_labelSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_labelSelector);
    }

    // query parameters
    char *keyQuery_limit;
    int valueQuery_limit;
    keyValuePair_t *keyPairQuery_limit = 0;
    if (limit)
    {
        keyQuery_limit = strdup("limit");
        valueQuery_limit = (limit);
        keyPairQuery_limit = keyValuePair_create(keyQuery_limit, &valueQuery_limit);
        list_addElement(localVarQueryParameters,keyPairQuery_limit);
    }

    // query parameters
    char *keyQuery_orphanDependents;
    int valueQuery_orphanDependents;
    keyValuePair_t *keyPairQuery_orphanDependents = 0;
    if (orphanDependents)
    {
        keyQuery_orphanDependents = strdup("orphanDependents");
        valueQuery_orphanDependents = (orphanDependents);
        keyPairQuery_orphanDependents = keyValuePair_create(keyQuery_orphanDependents, &valueQuery_orphanDependents);
        list_addElement(localVarQueryParameters,keyPairQuery_orphanDependents);
    }

    // query parameters
    char *keyQuery_propagationPolicy;
    char * valueQuery_propagationPolicy;
    keyValuePair_t *keyPairQuery_propagationPolicy = 0;
    if (propagationPolicy)
    {
        keyQuery_propagationPolicy = strdup("propagationPolicy");
        valueQuery_propagationPolicy = strdup((propagationPolicy));
        keyPairQuery_propagationPolicy = keyValuePair_create(keyQuery_propagationPolicy, valueQuery_propagationPolicy);
        list_addElement(localVarQueryParameters,keyPairQuery_propagationPolicy);
    }

    // query parameters
    char *keyQuery_resourceVersion;
    char * valueQuery_resourceVersion;
    keyValuePair_t *keyPairQuery_resourceVersion = 0;
    if (resourceVersion)
    {
        keyQuery_resourceVersion = strdup("resourceVersion");
        valueQuery_resourceVersion = strdup((resourceVersion));
        keyPairQuery_resourceVersion = keyValuePair_create(keyQuery_resourceVersion, valueQuery_resourceVersion);
        list_addElement(localVarQueryParameters,keyPairQuery_resourceVersion);
    }

    // query parameters
    char *keyQuery_timeoutSeconds;
    int valueQuery_timeoutSeconds;
    keyValuePair_t *keyPairQuery_timeoutSeconds = 0;
    if (timeoutSeconds)
    {
        keyQuery_timeoutSeconds = strdup("timeoutSeconds");
        valueQuery_timeoutSeconds = (timeoutSeconds);
        keyPairQuery_timeoutSeconds = keyValuePair_create(keyQuery_timeoutSeconds, &valueQuery_timeoutSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_timeoutSeconds);
    }

    // query parameters
    char *keyQuery_watch;
    int valueQuery_watch;
    keyValuePair_t *keyPairQuery_watch = 0;
    if (watch)
    {
        keyQuery_watch = strdup("watch");
        valueQuery_watch = (watch);
        keyPairQuery_watch = keyValuePair_create(keyQuery_watch, &valueQuery_watch);
        list_addElement(localVarQueryParameters,keyPairQuery_watch);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = v1_delete_options_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "DELETE");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not_ container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_status_t *elementToReturn = v1_status_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_namespace);
    cJSON_Delete(localVarSingleItemJSON_body);
    free(localVarBodyParameters);
    free(keyQuery_pretty);
    free(valueQuery_pretty);
    keyValuePair_free(keyPairQuery_pretty);
    free(keyQuery_allowWatchBookmarks);
    keyValuePair_free(keyPairQuery_allowWatchBookmarks);
    free(keyQuery_continue);
    free(valueQuery_continue);
    keyValuePair_free(keyPairQuery_continue);
    free(keyQuery_dryRun);
    free(valueQuery_dryRun);
    keyValuePair_free(keyPairQuery_dryRun);
    free(keyQuery_fieldSelector);
    free(valueQuery_fieldSelector);
    keyValuePair_free(keyPairQuery_fieldSelector);
    free(keyQuery_gracePeriodSeconds);
    keyValuePair_free(keyPairQuery_gracePeriodSeconds);
    free(keyQuery_labelSelector);
    free(valueQuery_labelSelector);
    keyValuePair_free(keyPairQuery_labelSelector);
    free(keyQuery_limit);
    keyValuePair_free(keyPairQuery_limit);
    free(keyQuery_orphanDependents);
    keyValuePair_free(keyPairQuery_orphanDependents);
    free(keyQuery_propagationPolicy);
    free(valueQuery_propagationPolicy);
    keyValuePair_free(keyPairQuery_propagationPolicy);
    free(keyQuery_resourceVersion);
    free(valueQuery_resourceVersion);
    keyValuePair_free(keyPairQuery_resourceVersion);
    free(keyQuery_timeoutSeconds);
    keyValuePair_free(keyPairQuery_timeoutSeconds);
    free(keyQuery_watch);
    keyValuePair_free(keyPairQuery_watch);
    return elementToReturn;
end:
    return NULL;

}

// delete collection of DaemonSet
//
v1_status_t*
AppsV1API_deleteAppsV1CollectionNamespacedDaemonSet(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/daemonsets")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/daemonsets");


    // Path Params
    long sizeOfPathParams_namespace = strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



    // query parameters
    char *keyQuery_pretty;
    char * valueQuery_pretty;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }

    // query parameters
    char *keyQuery_allowWatchBookmarks;
    int valueQuery_allowWatchBookmarks;
    keyValuePair_t *keyPairQuery_allowWatchBookmarks = 0;
    if (allowWatchBookmarks)
    {
        keyQuery_allowWatchBookmarks = strdup("allowWatchBookmarks");
        valueQuery_allowWatchBookmarks = (allowWatchBookmarks);
        keyPairQuery_allowWatchBookmarks = keyValuePair_create(keyQuery_allowWatchBookmarks, &valueQuery_allowWatchBookmarks);
        list_addElement(localVarQueryParameters,keyPairQuery_allowWatchBookmarks);
    }

    // query parameters
    char *keyQuery_continue;
    char * valueQuery_continue;
    keyValuePair_t *keyPairQuery_continue = 0;
    if (continue_)
    {
        keyQuery_continue = strdup("continue_");
        valueQuery_continue = strdup((continue_));
        keyPairQuery_continue = keyValuePair_create(keyQuery_continue, valueQuery_continue);
        list_addElement(localVarQueryParameters,keyPairQuery_continue);
    }

    // query parameters
    char *keyQuery_dryRun;
    char * valueQuery_dryRun;
    keyValuePair_t *keyPairQuery_dryRun = 0;
    if (dryRun)
    {
        keyQuery_dryRun = strdup("dryRun");
        valueQuery_dryRun = strdup((dryRun));
        keyPairQuery_dryRun = keyValuePair_create(keyQuery_dryRun, valueQuery_dryRun);
        list_addElement(localVarQueryParameters,keyPairQuery_dryRun);
    }

    // query parameters
    char *keyQuery_fieldSelector;
    char * valueQuery_fieldSelector;
    keyValuePair_t *keyPairQuery_fieldSelector = 0;
    if (fieldSelector)
    {
        keyQuery_fieldSelector = strdup("fieldSelector");
        valueQuery_fieldSelector = strdup((fieldSelector));
        keyPairQuery_fieldSelector = keyValuePair_create(keyQuery_fieldSelector, valueQuery_fieldSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldSelector);
    }

    // query parameters
    char *keyQuery_gracePeriodSeconds;
    int valueQuery_gracePeriodSeconds;
    keyValuePair_t *keyPairQuery_gracePeriodSeconds = 0;
    if (gracePeriodSeconds)
    {
        keyQuery_gracePeriodSeconds = strdup("gracePeriodSeconds");
        valueQuery_gracePeriodSeconds = (gracePeriodSeconds);
        keyPairQuery_gracePeriodSeconds = keyValuePair_create(keyQuery_gracePeriodSeconds, &valueQuery_gracePeriodSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_gracePeriodSeconds);
    }

    // query parameters
    char *keyQuery_labelSelector;
    char * valueQuery_labelSelector;
    keyValuePair_t *keyPairQuery_labelSelector = 0;
    if (labelSelector)
    {
        keyQuery_labelSelector = strdup("labelSelector");
        valueQuery_labelSelector = strdup((labelSelector));
        keyPairQuery_labelSelector = keyValuePair_create(keyQuery_labelSelector, valueQuery_labelSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_labelSelector);
    }

    // query parameters
    char *keyQuery_limit;
    int valueQuery_limit;
    keyValuePair_t *keyPairQuery_limit = 0;
    if (limit)
    {
        keyQuery_limit = strdup("limit");
        valueQuery_limit = (limit);
        keyPairQuery_limit = keyValuePair_create(keyQuery_limit, &valueQuery_limit);
        list_addElement(localVarQueryParameters,keyPairQuery_limit);
    }

    // query parameters
    char *keyQuery_orphanDependents;
    int valueQuery_orphanDependents;
    keyValuePair_t *keyPairQuery_orphanDependents = 0;
    if (orphanDependents)
    {
        keyQuery_orphanDependents = strdup("orphanDependents");
        valueQuery_orphanDependents = (orphanDependents);
        keyPairQuery_orphanDependents = keyValuePair_create(keyQuery_orphanDependents, &valueQuery_orphanDependents);
        list_addElement(localVarQueryParameters,keyPairQuery_orphanDependents);
    }

    // query parameters
    char *keyQuery_propagationPolicy;
    char * valueQuery_propagationPolicy;
    keyValuePair_t *keyPairQuery_propagationPolicy = 0;
    if (propagationPolicy)
    {
        keyQuery_propagationPolicy = strdup("propagationPolicy");
        valueQuery_propagationPolicy = strdup((propagationPolicy));
        keyPairQuery_propagationPolicy = keyValuePair_create(keyQuery_propagationPolicy, valueQuery_propagationPolicy);
        list_addElement(localVarQueryParameters,keyPairQuery_propagationPolicy);
    }

    // query parameters
    char *keyQuery_resourceVersion;
    char * valueQuery_resourceVersion;
    keyValuePair_t *keyPairQuery_resourceVersion = 0;
    if (resourceVersion)
    {
        keyQuery_resourceVersion = strdup("resourceVersion");
        valueQuery_resourceVersion = strdup((resourceVersion));
        keyPairQuery_resourceVersion = keyValuePair_create(keyQuery_resourceVersion, valueQuery_resourceVersion);
        list_addElement(localVarQueryParameters,keyPairQuery_resourceVersion);
    }

    // query parameters
    char *keyQuery_timeoutSeconds;
    int valueQuery_timeoutSeconds;
    keyValuePair_t *keyPairQuery_timeoutSeconds = 0;
    if (timeoutSeconds)
    {
        keyQuery_timeoutSeconds = strdup("timeoutSeconds");
        valueQuery_timeoutSeconds = (timeoutSeconds);
        keyPairQuery_timeoutSeconds = keyValuePair_create(keyQuery_timeoutSeconds, &valueQuery_timeoutSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_timeoutSeconds);
    }

    // query parameters
    char *keyQuery_watch;
    int valueQuery_watch;
    keyValuePair_t *keyPairQuery_watch = 0;
    if (watch)
    {
        keyQuery_watch = strdup("watch");
        valueQuery_watch = (watch);
        keyPairQuery_watch = keyValuePair_create(keyQuery_watch, &valueQuery_watch);
        list_addElement(localVarQueryParameters,keyPairQuery_watch);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = v1_delete_options_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "DELETE");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not_ container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_status_t *elementToReturn = v1_status_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_namespace);
    cJSON_Delete(localVarSingleItemJSON_body);
    free(localVarBodyParameters);
    free(keyQuery_pretty);
    free(valueQuery_pretty);
    keyValuePair_free(keyPairQuery_pretty);
    free(keyQuery_allowWatchBookmarks);
    keyValuePair_free(keyPairQuery_allowWatchBookmarks);
    free(keyQuery_continue);
    free(valueQuery_continue);
    keyValuePair_free(keyPairQuery_continue);
    free(keyQuery_dryRun);
    free(valueQuery_dryRun);
    keyValuePair_free(keyPairQuery_dryRun);
    free(keyQuery_fieldSelector);
    free(valueQuery_fieldSelector);
    keyValuePair_free(keyPairQuery_fieldSelector);
    free(keyQuery_gracePeriodSeconds);
    keyValuePair_free(keyPairQuery_gracePeriodSeconds);
    free(keyQuery_labelSelector);
    free(valueQuery_labelSelector);
    keyValuePair_free(keyPairQuery_labelSelector);
    free(keyQuery_limit);
    keyValuePair_free(keyPairQuery_limit);
    free(keyQuery_orphanDependents);
    keyValuePair_free(keyPairQuery_orphanDependents);
    free(keyQuery_propagationPolicy);
    free(valueQuery_propagationPolicy);
    keyValuePair_free(keyPairQuery_propagationPolicy);
    free(keyQuery_resourceVersion);
    free(valueQuery_resourceVersion);
    keyValuePair_free(keyPairQuery_resourceVersion);
    free(keyQuery_timeoutSeconds);
    keyValuePair_free(keyPairQuery_timeoutSeconds);
    free(keyQuery_watch);
    keyValuePair_free(keyPairQuery_watch);
    return elementToReturn;
end:
    return NULL;

}

// delete collection of Deployment
//
v1_status_t*
AppsV1API_deleteAppsV1CollectionNamespacedDeployment(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/deployments")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/deployments");


    // Path Params
    long sizeOfPathParams_namespace = strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



    // query parameters
    char *keyQuery_pretty;
    char * valueQuery_pretty;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }

    // query parameters
    char *keyQuery_allowWatchBookmarks;
    int valueQuery_allowWatchBookmarks;
    keyValuePair_t *keyPairQuery_allowWatchBookmarks = 0;
    if (allowWatchBookmarks)
    {
        keyQuery_allowWatchBookmarks = strdup("allowWatchBookmarks");
        valueQuery_allowWatchBookmarks = (allowWatchBookmarks);
        keyPairQuery_allowWatchBookmarks = keyValuePair_create(keyQuery_allowWatchBookmarks, &valueQuery_allowWatchBookmarks);
        list_addElement(localVarQueryParameters,keyPairQuery_allowWatchBookmarks);
    }

    // query parameters
    char *keyQuery_continue;
    char * valueQuery_continue;
    keyValuePair_t *keyPairQuery_continue = 0;
    if (continue_)
    {
        keyQuery_continue = strdup("continue_");
        valueQuery_continue = strdup((continue_));
        keyPairQuery_continue = keyValuePair_create(keyQuery_continue, valueQuery_continue);
        list_addElement(localVarQueryParameters,keyPairQuery_continue);
    }

    // query parameters
    char *keyQuery_dryRun;
    char * valueQuery_dryRun;
    keyValuePair_t *keyPairQuery_dryRun = 0;
    if (dryRun)
    {
        keyQuery_dryRun = strdup("dryRun");
        valueQuery_dryRun = strdup((dryRun));
        keyPairQuery_dryRun = keyValuePair_create(keyQuery_dryRun, valueQuery_dryRun);
        list_addElement(localVarQueryParameters,keyPairQuery_dryRun);
    }

    // query parameters
    char *keyQuery_fieldSelector;
    char * valueQuery_fieldSelector;
    keyValuePair_t *keyPairQuery_fieldSelector = 0;
    if (fieldSelector)
    {
        keyQuery_fieldSelector = strdup("fieldSelector");
        valueQuery_fieldSelector = strdup((fieldSelector));
        keyPairQuery_fieldSelector = keyValuePair_create(keyQuery_fieldSelector, valueQuery_fieldSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldSelector);
    }

    // query parameters
    char *keyQuery_gracePeriodSeconds;
    int valueQuery_gracePeriodSeconds;
    keyValuePair_t *keyPairQuery_gracePeriodSeconds = 0;
    if (gracePeriodSeconds)
    {
        keyQuery_gracePeriodSeconds = strdup("gracePeriodSeconds");
        valueQuery_gracePeriodSeconds = (gracePeriodSeconds);
        keyPairQuery_gracePeriodSeconds = keyValuePair_create(keyQuery_gracePeriodSeconds, &valueQuery_gracePeriodSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_gracePeriodSeconds);
    }

    // query parameters
    char *keyQuery_labelSelector;
    char * valueQuery_labelSelector;
    keyValuePair_t *keyPairQuery_labelSelector = 0;
    if (labelSelector)
    {
        keyQuery_labelSelector = strdup("labelSelector");
        valueQuery_labelSelector = strdup((labelSelector));
        keyPairQuery_labelSelector = keyValuePair_create(keyQuery_labelSelector, valueQuery_labelSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_labelSelector);
    }

    // query parameters
    char *keyQuery_limit;
    int valueQuery_limit;
    keyValuePair_t *keyPairQuery_limit = 0;
    if (limit)
    {
        keyQuery_limit = strdup("limit");
        valueQuery_limit = (limit);
        keyPairQuery_limit = keyValuePair_create(keyQuery_limit, &valueQuery_limit);
        list_addElement(localVarQueryParameters,keyPairQuery_limit);
    }

    // query parameters
    char *keyQuery_orphanDependents;
    int valueQuery_orphanDependents;
    keyValuePair_t *keyPairQuery_orphanDependents = 0;
    if (orphanDependents)
    {
        keyQuery_orphanDependents = strdup("orphanDependents");
        valueQuery_orphanDependents = (orphanDependents);
        keyPairQuery_orphanDependents = keyValuePair_create(keyQuery_orphanDependents, &valueQuery_orphanDependents);
        list_addElement(localVarQueryParameters,keyPairQuery_orphanDependents);
    }

    // query parameters
    char *keyQuery_propagationPolicy;
    char * valueQuery_propagationPolicy;
    keyValuePair_t *keyPairQuery_propagationPolicy = 0;
    if (propagationPolicy)
    {
        keyQuery_propagationPolicy = strdup("propagationPolicy");
        valueQuery_propagationPolicy = strdup((propagationPolicy));
        keyPairQuery_propagationPolicy = keyValuePair_create(keyQuery_propagationPolicy, valueQuery_propagationPolicy);
        list_addElement(localVarQueryParameters,keyPairQuery_propagationPolicy);
    }

    // query parameters
    char *keyQuery_resourceVersion;
    char * valueQuery_resourceVersion;
    keyValuePair_t *keyPairQuery_resourceVersion = 0;
    if (resourceVersion)
    {
        keyQuery_resourceVersion = strdup("resourceVersion");
        valueQuery_resourceVersion = strdup((resourceVersion));
        keyPairQuery_resourceVersion = keyValuePair_create(keyQuery_resourceVersion, valueQuery_resourceVersion);
        list_addElement(localVarQueryParameters,keyPairQuery_resourceVersion);
    }

    // query parameters
    char *keyQuery_timeoutSeconds;
    int valueQuery_timeoutSeconds;
    keyValuePair_t *keyPairQuery_timeoutSeconds = 0;
    if (timeoutSeconds)
    {
        keyQuery_timeoutSeconds = strdup("timeoutSeconds");
        valueQuery_timeoutSeconds = (timeoutSeconds);
        keyPairQuery_timeoutSeconds = keyValuePair_create(keyQuery_timeoutSeconds, &valueQuery_timeoutSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_timeoutSeconds);
    }

    // query parameters
    char *keyQuery_watch;
    int valueQuery_watch;
    keyValuePair_t *keyPairQuery_watch = 0;
    if (watch)
    {
        keyQuery_watch = strdup("watch");
        valueQuery_watch = (watch);
        keyPairQuery_watch = keyValuePair_create(keyQuery_watch, &valueQuery_watch);
        list_addElement(localVarQueryParameters,keyPairQuery_watch);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = v1_delete_options_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "DELETE");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not_ container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_status_t *elementToReturn = v1_status_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_namespace);
    cJSON_Delete(localVarSingleItemJSON_body);
    free(localVarBodyParameters);
    free(keyQuery_pretty);
    free(valueQuery_pretty);
    keyValuePair_free(keyPairQuery_pretty);
    free(keyQuery_allowWatchBookmarks);
    keyValuePair_free(keyPairQuery_allowWatchBookmarks);
    free(keyQuery_continue);
    free(valueQuery_continue);
    keyValuePair_free(keyPairQuery_continue);
    free(keyQuery_dryRun);
    free(valueQuery_dryRun);
    keyValuePair_free(keyPairQuery_dryRun);
    free(keyQuery_fieldSelector);
    free(valueQuery_fieldSelector);
    keyValuePair_free(keyPairQuery_fieldSelector);
    free(keyQuery_gracePeriodSeconds);
    keyValuePair_free(keyPairQuery_gracePeriodSeconds);
    free(keyQuery_labelSelector);
    free(valueQuery_labelSelector);
    keyValuePair_free(keyPairQuery_labelSelector);
    free(keyQuery_limit);
    keyValuePair_free(keyPairQuery_limit);
    free(keyQuery_orphanDependents);
    keyValuePair_free(keyPairQuery_orphanDependents);
    free(keyQuery_propagationPolicy);
    free(valueQuery_propagationPolicy);
    keyValuePair_free(keyPairQuery_propagationPolicy);
    free(keyQuery_resourceVersion);
    free(valueQuery_resourceVersion);
    keyValuePair_free(keyPairQuery_resourceVersion);
    free(keyQuery_timeoutSeconds);
    keyValuePair_free(keyPairQuery_timeoutSeconds);
    free(keyQuery_watch);
    keyValuePair_free(keyPairQuery_watch);
    return elementToReturn;
end:
    return NULL;

}

// delete collection of ReplicaSet
//
v1_status_t*
AppsV1API_deleteAppsV1CollectionNamespacedReplicaSet(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/replicasets")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/replicasets");


    // Path Params
    long sizeOfPathParams_namespace = strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



    // query parameters
    char *keyQuery_pretty;
    char * valueQuery_pretty;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }

    // query parameters
    char *keyQuery_allowWatchBookmarks;
    int valueQuery_allowWatchBookmarks;
    keyValuePair_t *keyPairQuery_allowWatchBookmarks = 0;
    if (allowWatchBookmarks)
    {
        keyQuery_allowWatchBookmarks = strdup("allowWatchBookmarks");
        valueQuery_allowWatchBookmarks = (allowWatchBookmarks);
        keyPairQuery_allowWatchBookmarks = keyValuePair_create(keyQuery_allowWatchBookmarks, &valueQuery_allowWatchBookmarks);
        list_addElement(localVarQueryParameters,keyPairQuery_allowWatchBookmarks);
    }

    // query parameters
    char *keyQuery_continue;
    char * valueQuery_continue;
    keyValuePair_t *keyPairQuery_continue = 0;
    if (continue_)
    {
        keyQuery_continue = strdup("continue_");
        valueQuery_continue = strdup((continue_));
        keyPairQuery_continue = keyValuePair_create(keyQuery_continue, valueQuery_continue);
        list_addElement(localVarQueryParameters,keyPairQuery_continue);
    }

    // query parameters
    char *keyQuery_dryRun;
    char * valueQuery_dryRun;
    keyValuePair_t *keyPairQuery_dryRun = 0;
    if (dryRun)
    {
        keyQuery_dryRun = strdup("dryRun");
        valueQuery_dryRun = strdup((dryRun));
        keyPairQuery_dryRun = keyValuePair_create(keyQuery_dryRun, valueQuery_dryRun);
        list_addElement(localVarQueryParameters,keyPairQuery_dryRun);
    }

    // query parameters
    char *keyQuery_fieldSelector;
    char * valueQuery_fieldSelector;
    keyValuePair_t *keyPairQuery_fieldSelector = 0;
    if (fieldSelector)
    {
        keyQuery_fieldSelector = strdup("fieldSelector");
        valueQuery_fieldSelector = strdup((fieldSelector));
        keyPairQuery_fieldSelector = keyValuePair_create(keyQuery_fieldSelector, valueQuery_fieldSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldSelector);
    }

    // query parameters
    char *keyQuery_gracePeriodSeconds;
    int valueQuery_gracePeriodSeconds;
    keyValuePair_t *keyPairQuery_gracePeriodSeconds = 0;
    if (gracePeriodSeconds)
    {
        keyQuery_gracePeriodSeconds = strdup("gracePeriodSeconds");
        valueQuery_gracePeriodSeconds = (gracePeriodSeconds);
        keyPairQuery_gracePeriodSeconds = keyValuePair_create(keyQuery_gracePeriodSeconds, &valueQuery_gracePeriodSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_gracePeriodSeconds);
    }

    // query parameters
    char *keyQuery_labelSelector;
    char * valueQuery_labelSelector;
    keyValuePair_t *keyPairQuery_labelSelector = 0;
    if (labelSelector)
    {
        keyQuery_labelSelector = strdup("labelSelector");
        valueQuery_labelSelector = strdup((labelSelector));
        keyPairQuery_labelSelector = keyValuePair_create(keyQuery_labelSelector, valueQuery_labelSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_labelSelector);
    }

    // query parameters
    char *keyQuery_limit;
    int valueQuery_limit;
    keyValuePair_t *keyPairQuery_limit = 0;
    if (limit)
    {
        keyQuery_limit = strdup("limit");
        valueQuery_limit = (limit);
        keyPairQuery_limit = keyValuePair_create(keyQuery_limit, &valueQuery_limit);
        list_addElement(localVarQueryParameters,keyPairQuery_limit);
    }

    // query parameters
    char *keyQuery_orphanDependents;
    int valueQuery_orphanDependents;
    keyValuePair_t *keyPairQuery_orphanDependents = 0;
    if (orphanDependents)
    {
        keyQuery_orphanDependents = strdup("orphanDependents");
        valueQuery_orphanDependents = (orphanDependents);
        keyPairQuery_orphanDependents = keyValuePair_create(keyQuery_orphanDependents, &valueQuery_orphanDependents);
        list_addElement(localVarQueryParameters,keyPairQuery_orphanDependents);
    }

    // query parameters
    char *keyQuery_propagationPolicy;
    char * valueQuery_propagationPolicy;
    keyValuePair_t *keyPairQuery_propagationPolicy = 0;
    if (propagationPolicy)
    {
        keyQuery_propagationPolicy = strdup("propagationPolicy");
        valueQuery_propagationPolicy = strdup((propagationPolicy));
        keyPairQuery_propagationPolicy = keyValuePair_create(keyQuery_propagationPolicy, valueQuery_propagationPolicy);
        list_addElement(localVarQueryParameters,keyPairQuery_propagationPolicy);
    }

    // query parameters
    char *keyQuery_resourceVersion;
    char * valueQuery_resourceVersion;
    keyValuePair_t *keyPairQuery_resourceVersion = 0;
    if (resourceVersion)
    {
        keyQuery_resourceVersion = strdup("resourceVersion");
        valueQuery_resourceVersion = strdup((resourceVersion));
        keyPairQuery_resourceVersion = keyValuePair_create(keyQuery_resourceVersion, valueQuery_resourceVersion);
        list_addElement(localVarQueryParameters,keyPairQuery_resourceVersion);
    }

    // query parameters
    char *keyQuery_timeoutSeconds;
    int valueQuery_timeoutSeconds;
    keyValuePair_t *keyPairQuery_timeoutSeconds = 0;
    if (timeoutSeconds)
    {
        keyQuery_timeoutSeconds = strdup("timeoutSeconds");
        valueQuery_timeoutSeconds = (timeoutSeconds);
        keyPairQuery_timeoutSeconds = keyValuePair_create(keyQuery_timeoutSeconds, &valueQuery_timeoutSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_timeoutSeconds);
    }

    // query parameters
    char *keyQuery_watch;
    int valueQuery_watch;
    keyValuePair_t *keyPairQuery_watch = 0;
    if (watch)
    {
        keyQuery_watch = strdup("watch");
        valueQuery_watch = (watch);
        keyPairQuery_watch = keyValuePair_create(keyQuery_watch, &valueQuery_watch);
        list_addElement(localVarQueryParameters,keyPairQuery_watch);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = v1_delete_options_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "DELETE");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not_ container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_status_t *elementToReturn = v1_status_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_namespace);
    cJSON_Delete(localVarSingleItemJSON_body);
    free(localVarBodyParameters);
    free(keyQuery_pretty);
    free(valueQuery_pretty);
    keyValuePair_free(keyPairQuery_pretty);
    free(keyQuery_allowWatchBookmarks);
    keyValuePair_free(keyPairQuery_allowWatchBookmarks);
    free(keyQuery_continue);
    free(valueQuery_continue);
    keyValuePair_free(keyPairQuery_continue);
    free(keyQuery_dryRun);
    free(valueQuery_dryRun);
    keyValuePair_free(keyPairQuery_dryRun);
    free(keyQuery_fieldSelector);
    free(valueQuery_fieldSelector);
    keyValuePair_free(keyPairQuery_fieldSelector);
    free(keyQuery_gracePeriodSeconds);
    keyValuePair_free(keyPairQuery_gracePeriodSeconds);
    free(keyQuery_labelSelector);
    free(valueQuery_labelSelector);
    keyValuePair_free(keyPairQuery_labelSelector);
    free(keyQuery_limit);
    keyValuePair_free(keyPairQuery_limit);
    free(keyQuery_orphanDependents);
    keyValuePair_free(keyPairQuery_orphanDependents);
    free(keyQuery_propagationPolicy);
    free(valueQuery_propagationPolicy);
    keyValuePair_free(keyPairQuery_propagationPolicy);
    free(keyQuery_resourceVersion);
    free(valueQuery_resourceVersion);
    keyValuePair_free(keyPairQuery_resourceVersion);
    free(keyQuery_timeoutSeconds);
    keyValuePair_free(keyPairQuery_timeoutSeconds);
    free(keyQuery_watch);
    keyValuePair_free(keyPairQuery_watch);
    return elementToReturn;
end:
    return NULL;

}

// delete collection of StatefulSet
//
v1_status_t*
AppsV1API_deleteAppsV1CollectionNamespacedStatefulSet(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/statefulsets")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/statefulsets");


    // Path Params
    long sizeOfPathParams_namespace = strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



    // query parameters
    char *keyQuery_pretty;
    char * valueQuery_pretty;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }

    // query parameters
    char *keyQuery_allowWatchBookmarks;
    int valueQuery_allowWatchBookmarks;
    keyValuePair_t *keyPairQuery_allowWatchBookmarks = 0;
    if (allowWatchBookmarks)
    {
        keyQuery_allowWatchBookmarks = strdup("allowWatchBookmarks");
        valueQuery_allowWatchBookmarks = (allowWatchBookmarks);
        keyPairQuery_allowWatchBookmarks = keyValuePair_create(keyQuery_allowWatchBookmarks, &valueQuery_allowWatchBookmarks);
        list_addElement(localVarQueryParameters,keyPairQuery_allowWatchBookmarks);
    }

    // query parameters
    char *keyQuery_continue;
    char * valueQuery_continue;
    keyValuePair_t *keyPairQuery_continue = 0;
    if (continue_)
    {
        keyQuery_continue = strdup("continue_");
        valueQuery_continue = strdup((continue_));
        keyPairQuery_continue = keyValuePair_create(keyQuery_continue, valueQuery_continue);
        list_addElement(localVarQueryParameters,keyPairQuery_continue);
    }

    // query parameters
    char *keyQuery_dryRun;
    char * valueQuery_dryRun;
    keyValuePair_t *keyPairQuery_dryRun = 0;
    if (dryRun)
    {
        keyQuery_dryRun = strdup("dryRun");
        valueQuery_dryRun = strdup((dryRun));
        keyPairQuery_dryRun = keyValuePair_create(keyQuery_dryRun, valueQuery_dryRun);
        list_addElement(localVarQueryParameters,keyPairQuery_dryRun);
    }

    // query parameters
    char *keyQuery_fieldSelector;
    char * valueQuery_fieldSelector;
    keyValuePair_t *keyPairQuery_fieldSelector = 0;
    if (fieldSelector)
    {
        keyQuery_fieldSelector = strdup("fieldSelector");
        valueQuery_fieldSelector = strdup((fieldSelector));
        keyPairQuery_fieldSelector = keyValuePair_create(keyQuery_fieldSelector, valueQuery_fieldSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldSelector);
    }

    // query parameters
    char *keyQuery_gracePeriodSeconds;
    int valueQuery_gracePeriodSeconds;
    keyValuePair_t *keyPairQuery_gracePeriodSeconds = 0;
    if (gracePeriodSeconds)
    {
        keyQuery_gracePeriodSeconds = strdup("gracePeriodSeconds");
        valueQuery_gracePeriodSeconds = (gracePeriodSeconds);
        keyPairQuery_gracePeriodSeconds = keyValuePair_create(keyQuery_gracePeriodSeconds, &valueQuery_gracePeriodSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_gracePeriodSeconds);
    }

    // query parameters
    char *keyQuery_labelSelector;
    char * valueQuery_labelSelector;
    keyValuePair_t *keyPairQuery_labelSelector = 0;
    if (labelSelector)
    {
        keyQuery_labelSelector = strdup("labelSelector");
        valueQuery_labelSelector = strdup((labelSelector));
        keyPairQuery_labelSelector = keyValuePair_create(keyQuery_labelSelector, valueQuery_labelSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_labelSelector);
    }

    // query parameters
    char *keyQuery_limit;
    int valueQuery_limit;
    keyValuePair_t *keyPairQuery_limit = 0;
    if (limit)
    {
        keyQuery_limit = strdup("limit");
        valueQuery_limit = (limit);
        keyPairQuery_limit = keyValuePair_create(keyQuery_limit, &valueQuery_limit);
        list_addElement(localVarQueryParameters,keyPairQuery_limit);
    }

    // query parameters
    char *keyQuery_orphanDependents;
    int valueQuery_orphanDependents;
    keyValuePair_t *keyPairQuery_orphanDependents = 0;
    if (orphanDependents)
    {
        keyQuery_orphanDependents = strdup("orphanDependents");
        valueQuery_orphanDependents = (orphanDependents);
        keyPairQuery_orphanDependents = keyValuePair_create(keyQuery_orphanDependents, &valueQuery_orphanDependents);
        list_addElement(localVarQueryParameters,keyPairQuery_orphanDependents);
    }

    // query parameters
    char *keyQuery_propagationPolicy;
    char * valueQuery_propagationPolicy;
    keyValuePair_t *keyPairQuery_propagationPolicy = 0;
    if (propagationPolicy)
    {
        keyQuery_propagationPolicy = strdup("propagationPolicy");
        valueQuery_propagationPolicy = strdup((propagationPolicy));
        keyPairQuery_propagationPolicy = keyValuePair_create(keyQuery_propagationPolicy, valueQuery_propagationPolicy);
        list_addElement(localVarQueryParameters,keyPairQuery_propagationPolicy);
    }

    // query parameters
    char *keyQuery_resourceVersion;
    char * valueQuery_resourceVersion;
    keyValuePair_t *keyPairQuery_resourceVersion = 0;
    if (resourceVersion)
    {
        keyQuery_resourceVersion = strdup("resourceVersion");
        valueQuery_resourceVersion = strdup((resourceVersion));
        keyPairQuery_resourceVersion = keyValuePair_create(keyQuery_resourceVersion, valueQuery_resourceVersion);
        list_addElement(localVarQueryParameters,keyPairQuery_resourceVersion);
    }

    // query parameters
    char *keyQuery_timeoutSeconds;
    int valueQuery_timeoutSeconds;
    keyValuePair_t *keyPairQuery_timeoutSeconds = 0;
    if (timeoutSeconds)
    {
        keyQuery_timeoutSeconds = strdup("timeoutSeconds");
        valueQuery_timeoutSeconds = (timeoutSeconds);
        keyPairQuery_timeoutSeconds = keyValuePair_create(keyQuery_timeoutSeconds, &valueQuery_timeoutSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_timeoutSeconds);
    }

    // query parameters
    char *keyQuery_watch;
    int valueQuery_watch;
    keyValuePair_t *keyPairQuery_watch = 0;
    if (watch)
    {
        keyQuery_watch = strdup("watch");
        valueQuery_watch = (watch);
        keyPairQuery_watch = keyValuePair_create(keyQuery_watch, &valueQuery_watch);
        list_addElement(localVarQueryParameters,keyPairQuery_watch);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = v1_delete_options_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "DELETE");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not_ container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_status_t *elementToReturn = v1_status_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_namespace);
    cJSON_Delete(localVarSingleItemJSON_body);
    free(localVarBodyParameters);
    free(keyQuery_pretty);
    free(valueQuery_pretty);
    keyValuePair_free(keyPairQuery_pretty);
    free(keyQuery_allowWatchBookmarks);
    keyValuePair_free(keyPairQuery_allowWatchBookmarks);
    free(keyQuery_continue);
    free(valueQuery_continue);
    keyValuePair_free(keyPairQuery_continue);
    free(keyQuery_dryRun);
    free(valueQuery_dryRun);
    keyValuePair_free(keyPairQuery_dryRun);
    free(keyQuery_fieldSelector);
    free(valueQuery_fieldSelector);
    keyValuePair_free(keyPairQuery_fieldSelector);
    free(keyQuery_gracePeriodSeconds);
    keyValuePair_free(keyPairQuery_gracePeriodSeconds);
    free(keyQuery_labelSelector);
    free(valueQuery_labelSelector);
    keyValuePair_free(keyPairQuery_labelSelector);
    free(keyQuery_limit);
    keyValuePair_free(keyPairQuery_limit);
    free(keyQuery_orphanDependents);
    keyValuePair_free(keyPairQuery_orphanDependents);
    free(keyQuery_propagationPolicy);
    free(valueQuery_propagationPolicy);
    keyValuePair_free(keyPairQuery_propagationPolicy);
    free(keyQuery_resourceVersion);
    free(valueQuery_resourceVersion);
    keyValuePair_free(keyPairQuery_resourceVersion);
    free(keyQuery_timeoutSeconds);
    keyValuePair_free(keyPairQuery_timeoutSeconds);
    free(keyQuery_watch);
    keyValuePair_free(keyPairQuery_watch);
    return elementToReturn;
end:
    return NULL;

}

// delete a ControllerRevision
//
v1_status_t*
AppsV1API_deleteAppsV1NamespacedControllerRevision(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/controllerrevisions/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/controllerrevisions/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams_namespace = strlen(name)+3 + strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



    // query parameters
    char *keyQuery_pretty;
    char * valueQuery_pretty;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }

    // query parameters
    char *keyQuery_dryRun;
    char * valueQuery_dryRun;
    keyValuePair_t *keyPairQuery_dryRun = 0;
    if (dryRun)
    {
        keyQuery_dryRun = strdup("dryRun");
        valueQuery_dryRun = strdup((dryRun));
        keyPairQuery_dryRun = keyValuePair_create(keyQuery_dryRun, valueQuery_dryRun);
        list_addElement(localVarQueryParameters,keyPairQuery_dryRun);
    }

    // query parameters
    char *keyQuery_gracePeriodSeconds;
    int valueQuery_gracePeriodSeconds;
    keyValuePair_t *keyPairQuery_gracePeriodSeconds = 0;
    if (gracePeriodSeconds)
    {
        keyQuery_gracePeriodSeconds = strdup("gracePeriodSeconds");
        valueQuery_gracePeriodSeconds = (gracePeriodSeconds);
        keyPairQuery_gracePeriodSeconds = keyValuePair_create(keyQuery_gracePeriodSeconds, &valueQuery_gracePeriodSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_gracePeriodSeconds);
    }

    // query parameters
    char *keyQuery_orphanDependents;
    int valueQuery_orphanDependents;
    keyValuePair_t *keyPairQuery_orphanDependents = 0;
    if (orphanDependents)
    {
        keyQuery_orphanDependents = strdup("orphanDependents");
        valueQuery_orphanDependents = (orphanDependents);
        keyPairQuery_orphanDependents = keyValuePair_create(keyQuery_orphanDependents, &valueQuery_orphanDependents);
        list_addElement(localVarQueryParameters,keyPairQuery_orphanDependents);
    }

    // query parameters
    char *keyQuery_propagationPolicy;
    char * valueQuery_propagationPolicy;
    keyValuePair_t *keyPairQuery_propagationPolicy = 0;
    if (propagationPolicy)
    {
        keyQuery_propagationPolicy = strdup("propagationPolicy");
        valueQuery_propagationPolicy = strdup((propagationPolicy));
        keyPairQuery_propagationPolicy = keyValuePair_create(keyQuery_propagationPolicy, valueQuery_propagationPolicy);
        list_addElement(localVarQueryParameters,keyPairQuery_propagationPolicy);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = v1_delete_options_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "DELETE");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 202) {
        printf("%s\n","Accepted");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not_ container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_status_t *elementToReturn = v1_status_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_name);
    free(localVarToReplace_namespace);
    cJSON_Delete(localVarSingleItemJSON_body);
    free(localVarBodyParameters);
    free(keyQuery_pretty);
    free(valueQuery_pretty);
    keyValuePair_free(keyPairQuery_pretty);
    free(keyQuery_dryRun);
    free(valueQuery_dryRun);
    keyValuePair_free(keyPairQuery_dryRun);
    free(keyQuery_gracePeriodSeconds);
    keyValuePair_free(keyPairQuery_gracePeriodSeconds);
    free(keyQuery_orphanDependents);
    keyValuePair_free(keyPairQuery_orphanDependents);
    free(keyQuery_propagationPolicy);
    free(valueQuery_propagationPolicy);
    keyValuePair_free(keyPairQuery_propagationPolicy);
    return elementToReturn;
end:
    return NULL;

}

// delete a DaemonSet
//
v1_status_t*
AppsV1API_deleteAppsV1NamespacedDaemonSet(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/daemonsets/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/daemonsets/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams_namespace = strlen(name)+3 + strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



    // query parameters
    char *keyQuery_pretty;
    char * valueQuery_pretty;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }

    // query parameters
    char *keyQuery_dryRun;
    char * valueQuery_dryRun;
    keyValuePair_t *keyPairQuery_dryRun = 0;
    if (dryRun)
    {
        keyQuery_dryRun = strdup("dryRun");
        valueQuery_dryRun = strdup((dryRun));
        keyPairQuery_dryRun = keyValuePair_create(keyQuery_dryRun, valueQuery_dryRun);
        list_addElement(localVarQueryParameters,keyPairQuery_dryRun);
    }

    // query parameters
    char *keyQuery_gracePeriodSeconds;
    int valueQuery_gracePeriodSeconds;
    keyValuePair_t *keyPairQuery_gracePeriodSeconds = 0;
    if (gracePeriodSeconds)
    {
        keyQuery_gracePeriodSeconds = strdup("gracePeriodSeconds");
        valueQuery_gracePeriodSeconds = (gracePeriodSeconds);
        keyPairQuery_gracePeriodSeconds = keyValuePair_create(keyQuery_gracePeriodSeconds, &valueQuery_gracePeriodSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_gracePeriodSeconds);
    }

    // query parameters
    char *keyQuery_orphanDependents;
    int valueQuery_orphanDependents;
    keyValuePair_t *keyPairQuery_orphanDependents = 0;
    if (orphanDependents)
    {
        keyQuery_orphanDependents = strdup("orphanDependents");
        valueQuery_orphanDependents = (orphanDependents);
        keyPairQuery_orphanDependents = keyValuePair_create(keyQuery_orphanDependents, &valueQuery_orphanDependents);
        list_addElement(localVarQueryParameters,keyPairQuery_orphanDependents);
    }

    // query parameters
    char *keyQuery_propagationPolicy;
    char * valueQuery_propagationPolicy;
    keyValuePair_t *keyPairQuery_propagationPolicy = 0;
    if (propagationPolicy)
    {
        keyQuery_propagationPolicy = strdup("propagationPolicy");
        valueQuery_propagationPolicy = strdup((propagationPolicy));
        keyPairQuery_propagationPolicy = keyValuePair_create(keyQuery_propagationPolicy, valueQuery_propagationPolicy);
        list_addElement(localVarQueryParameters,keyPairQuery_propagationPolicy);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = v1_delete_options_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "DELETE");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 202) {
        printf("%s\n","Accepted");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not_ container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_status_t *elementToReturn = v1_status_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_name);
    free(localVarToReplace_namespace);
    cJSON_Delete(localVarSingleItemJSON_body);
    free(localVarBodyParameters);
    free(keyQuery_pretty);
    free(valueQuery_pretty);
    keyValuePair_free(keyPairQuery_pretty);
    free(keyQuery_dryRun);
    free(valueQuery_dryRun);
    keyValuePair_free(keyPairQuery_dryRun);
    free(keyQuery_gracePeriodSeconds);
    keyValuePair_free(keyPairQuery_gracePeriodSeconds);
    free(keyQuery_orphanDependents);
    keyValuePair_free(keyPairQuery_orphanDependents);
    free(keyQuery_propagationPolicy);
    free(valueQuery_propagationPolicy);
    keyValuePair_free(keyPairQuery_propagationPolicy);
    return elementToReturn;
end:
    return NULL;

}

// delete a Deployment
//
v1_status_t*
AppsV1API_deleteAppsV1NamespacedDeployment(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/deployments/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/deployments/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams_namespace = strlen(name)+3 + strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



    // query parameters
    char *keyQuery_pretty;
    char * valueQuery_pretty;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }

    // query parameters
    char *keyQuery_dryRun;
    char * valueQuery_dryRun;
    keyValuePair_t *keyPairQuery_dryRun = 0;
    if (dryRun)
    {
        keyQuery_dryRun = strdup("dryRun");
        valueQuery_dryRun = strdup((dryRun));
        keyPairQuery_dryRun = keyValuePair_create(keyQuery_dryRun, valueQuery_dryRun);
        list_addElement(localVarQueryParameters,keyPairQuery_dryRun);
    }

    // query parameters
    char *keyQuery_gracePeriodSeconds;
    int valueQuery_gracePeriodSeconds;
    keyValuePair_t *keyPairQuery_gracePeriodSeconds = 0;
    if (gracePeriodSeconds)
    {
        keyQuery_gracePeriodSeconds = strdup("gracePeriodSeconds");
        valueQuery_gracePeriodSeconds = (gracePeriodSeconds);
        keyPairQuery_gracePeriodSeconds = keyValuePair_create(keyQuery_gracePeriodSeconds, &valueQuery_gracePeriodSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_gracePeriodSeconds);
    }

    // query parameters
    char *keyQuery_orphanDependents;
    int valueQuery_orphanDependents;
    keyValuePair_t *keyPairQuery_orphanDependents = 0;
    if (orphanDependents)
    {
        keyQuery_orphanDependents = strdup("orphanDependents");
        valueQuery_orphanDependents = (orphanDependents);
        keyPairQuery_orphanDependents = keyValuePair_create(keyQuery_orphanDependents, &valueQuery_orphanDependents);
        list_addElement(localVarQueryParameters,keyPairQuery_orphanDependents);
    }

    // query parameters
    char *keyQuery_propagationPolicy;
    char * valueQuery_propagationPolicy;
    keyValuePair_t *keyPairQuery_propagationPolicy = 0;
    if (propagationPolicy)
    {
        keyQuery_propagationPolicy = strdup("propagationPolicy");
        valueQuery_propagationPolicy = strdup((propagationPolicy));
        keyPairQuery_propagationPolicy = keyValuePair_create(keyQuery_propagationPolicy, valueQuery_propagationPolicy);
        list_addElement(localVarQueryParameters,keyPairQuery_propagationPolicy);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = v1_delete_options_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "DELETE");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 202) {
        printf("%s\n","Accepted");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not_ container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_status_t *elementToReturn = v1_status_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_name);
    free(localVarToReplace_namespace);
    cJSON_Delete(localVarSingleItemJSON_body);
    free(localVarBodyParameters);
    free(keyQuery_pretty);
    free(valueQuery_pretty);
    keyValuePair_free(keyPairQuery_pretty);
    free(keyQuery_dryRun);
    free(valueQuery_dryRun);
    keyValuePair_free(keyPairQuery_dryRun);
    free(keyQuery_gracePeriodSeconds);
    keyValuePair_free(keyPairQuery_gracePeriodSeconds);
    free(keyQuery_orphanDependents);
    keyValuePair_free(keyPairQuery_orphanDependents);
    free(keyQuery_propagationPolicy);
    free(valueQuery_propagationPolicy);
    keyValuePair_free(keyPairQuery_propagationPolicy);
    return elementToReturn;
end:
    return NULL;

}

// delete a ReplicaSet
//
v1_status_t*
AppsV1API_deleteAppsV1NamespacedReplicaSet(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/replicasets/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/replicasets/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams_namespace = strlen(name)+3 + strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



    // query parameters
    char *keyQuery_pretty;
    char * valueQuery_pretty;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }

    // query parameters
    char *keyQuery_dryRun;
    char * valueQuery_dryRun;
    keyValuePair_t *keyPairQuery_dryRun = 0;
    if (dryRun)
    {
        keyQuery_dryRun = strdup("dryRun");
        valueQuery_dryRun = strdup((dryRun));
        keyPairQuery_dryRun = keyValuePair_create(keyQuery_dryRun, valueQuery_dryRun);
        list_addElement(localVarQueryParameters,keyPairQuery_dryRun);
    }

    // query parameters
    char *keyQuery_gracePeriodSeconds;
    int valueQuery_gracePeriodSeconds;
    keyValuePair_t *keyPairQuery_gracePeriodSeconds = 0;
    if (gracePeriodSeconds)
    {
        keyQuery_gracePeriodSeconds = strdup("gracePeriodSeconds");
        valueQuery_gracePeriodSeconds = (gracePeriodSeconds);
        keyPairQuery_gracePeriodSeconds = keyValuePair_create(keyQuery_gracePeriodSeconds, &valueQuery_gracePeriodSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_gracePeriodSeconds);
    }

    // query parameters
    char *keyQuery_orphanDependents;
    int valueQuery_orphanDependents;
    keyValuePair_t *keyPairQuery_orphanDependents = 0;
    if (orphanDependents)
    {
        keyQuery_orphanDependents = strdup("orphanDependents");
        valueQuery_orphanDependents = (orphanDependents);
        keyPairQuery_orphanDependents = keyValuePair_create(keyQuery_orphanDependents, &valueQuery_orphanDependents);
        list_addElement(localVarQueryParameters,keyPairQuery_orphanDependents);
    }

    // query parameters
    char *keyQuery_propagationPolicy;
    char * valueQuery_propagationPolicy;
    keyValuePair_t *keyPairQuery_propagationPolicy = 0;
    if (propagationPolicy)
    {
        keyQuery_propagationPolicy = strdup("propagationPolicy");
        valueQuery_propagationPolicy = strdup((propagationPolicy));
        keyPairQuery_propagationPolicy = keyValuePair_create(keyQuery_propagationPolicy, valueQuery_propagationPolicy);
        list_addElement(localVarQueryParameters,keyPairQuery_propagationPolicy);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = v1_delete_options_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "DELETE");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 202) {
        printf("%s\n","Accepted");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not_ container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_status_t *elementToReturn = v1_status_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_name);
    free(localVarToReplace_namespace);
    cJSON_Delete(localVarSingleItemJSON_body);
    free(localVarBodyParameters);
    free(keyQuery_pretty);
    free(valueQuery_pretty);
    keyValuePair_free(keyPairQuery_pretty);
    free(keyQuery_dryRun);
    free(valueQuery_dryRun);
    keyValuePair_free(keyPairQuery_dryRun);
    free(keyQuery_gracePeriodSeconds);
    keyValuePair_free(keyPairQuery_gracePeriodSeconds);
    free(keyQuery_orphanDependents);
    keyValuePair_free(keyPairQuery_orphanDependents);
    free(keyQuery_propagationPolicy);
    free(valueQuery_propagationPolicy);
    keyValuePair_free(keyPairQuery_propagationPolicy);
    return elementToReturn;
end:
    return NULL;

}

// delete a StatefulSet
//
v1_status_t*
AppsV1API_deleteAppsV1NamespacedStatefulSet(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/statefulsets/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/statefulsets/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams_namespace = strlen(name)+3 + strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



    // query parameters
    char *keyQuery_pretty;
    char * valueQuery_pretty;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }

    // query parameters
    char *keyQuery_dryRun;
    char * valueQuery_dryRun;
    keyValuePair_t *keyPairQuery_dryRun = 0;
    if (dryRun)
    {
        keyQuery_dryRun = strdup("dryRun");
        valueQuery_dryRun = strdup((dryRun));
        keyPairQuery_dryRun = keyValuePair_create(keyQuery_dryRun, valueQuery_dryRun);
        list_addElement(localVarQueryParameters,keyPairQuery_dryRun);
    }

    // query parameters
    char *keyQuery_gracePeriodSeconds;
    int valueQuery_gracePeriodSeconds;
    keyValuePair_t *keyPairQuery_gracePeriodSeconds = 0;
    if (gracePeriodSeconds)
    {
        keyQuery_gracePeriodSeconds = strdup("gracePeriodSeconds");
        valueQuery_gracePeriodSeconds = (gracePeriodSeconds);
        keyPairQuery_gracePeriodSeconds = keyValuePair_create(keyQuery_gracePeriodSeconds, &valueQuery_gracePeriodSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_gracePeriodSeconds);
    }

    // query parameters
    char *keyQuery_orphanDependents;
    int valueQuery_orphanDependents;
    keyValuePair_t *keyPairQuery_orphanDependents = 0;
    if (orphanDependents)
    {
        keyQuery_orphanDependents = strdup("orphanDependents");
        valueQuery_orphanDependents = (orphanDependents);
        keyPairQuery_orphanDependents = keyValuePair_create(keyQuery_orphanDependents, &valueQuery_orphanDependents);
        list_addElement(localVarQueryParameters,keyPairQuery_orphanDependents);
    }

    // query parameters
    char *keyQuery_propagationPolicy;
    char * valueQuery_propagationPolicy;
    keyValuePair_t *keyPairQuery_propagationPolicy = 0;
    if (propagationPolicy)
    {
        keyQuery_propagationPolicy = strdup("propagationPolicy");
        valueQuery_propagationPolicy = strdup((propagationPolicy));
        keyPairQuery_propagationPolicy = keyValuePair_create(keyQuery_propagationPolicy, valueQuery_propagationPolicy);
        list_addElement(localVarQueryParameters,keyPairQuery_propagationPolicy);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = v1_delete_options_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "DELETE");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 202) {
        printf("%s\n","Accepted");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not_ container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_status_t *elementToReturn = v1_status_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_name);
    free(localVarToReplace_namespace);
    cJSON_Delete(localVarSingleItemJSON_body);
    free(localVarBodyParameters);
    free(keyQuery_pretty);
    free(valueQuery_pretty);
    keyValuePair_free(keyPairQuery_pretty);
    free(keyQuery_dryRun);
    free(valueQuery_dryRun);
    keyValuePair_free(keyPairQuery_dryRun);
    free(keyQuery_gracePeriodSeconds);
    keyValuePair_free(keyPairQuery_gracePeriodSeconds);
    free(keyQuery_orphanDependents);
    keyValuePair_free(keyPairQuery_orphanDependents);
    free(keyQuery_propagationPolicy);
    free(valueQuery_propagationPolicy);
    keyValuePair_free(keyPairQuery_propagationPolicy);
    return elementToReturn;
end:
    return NULL;

}

// get available resources
//
v1_api_resource_list_t*
AppsV1API_getAppsV1APIResources(apiClient_t *apiClient)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/");



    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not_ container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_api_resource_list_t *elementToReturn = v1_api_resource_list_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    return elementToReturn;
end:
    return NULL;

}

// list or watch objects of kind ControllerRevision
//
v1_controller_revision_list_t*
AppsV1API_listAppsV1ControllerRevisionForAllNamespaces(apiClient_t *apiClient ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * pretty ,char * resourceVersion ,int timeoutSeconds ,int watch)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/controllerrevisions")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/controllerrevisions");




    // query parameters
    char *keyQuery_allowWatchBookmarks;
    int valueQuery_allowWatchBookmarks;
    keyValuePair_t *keyPairQuery_allowWatchBookmarks = 0;
    if (allowWatchBookmarks)
    {
        keyQuery_allowWatchBookmarks = strdup("allowWatchBookmarks");
        valueQuery_allowWatchBookmarks = (allowWatchBookmarks);
        keyPairQuery_allowWatchBookmarks = keyValuePair_create(keyQuery_allowWatchBookmarks, &valueQuery_allowWatchBookmarks);
        list_addElement(localVarQueryParameters,keyPairQuery_allowWatchBookmarks);
    }

    // query parameters
    char *keyQuery_continue;
    char * valueQuery_continue;
    keyValuePair_t *keyPairQuery_continue = 0;
    if (continue_)
    {
        keyQuery_continue = strdup("continue_");
        valueQuery_continue = strdup((continue_));
        keyPairQuery_continue = keyValuePair_create(keyQuery_continue, valueQuery_continue);
        list_addElement(localVarQueryParameters,keyPairQuery_continue);
    }

    // query parameters
    char *keyQuery_fieldSelector;
    char * valueQuery_fieldSelector;
    keyValuePair_t *keyPairQuery_fieldSelector = 0;
    if (fieldSelector)
    {
        keyQuery_fieldSelector = strdup("fieldSelector");
        valueQuery_fieldSelector = strdup((fieldSelector));
        keyPairQuery_fieldSelector = keyValuePair_create(keyQuery_fieldSelector, valueQuery_fieldSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldSelector);
    }

    // query parameters
    char *keyQuery_labelSelector;
    char * valueQuery_labelSelector;
    keyValuePair_t *keyPairQuery_labelSelector = 0;
    if (labelSelector)
    {
        keyQuery_labelSelector = strdup("labelSelector");
        valueQuery_labelSelector = strdup((labelSelector));
        keyPairQuery_labelSelector = keyValuePair_create(keyQuery_labelSelector, valueQuery_labelSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_labelSelector);
    }

    // query parameters
    char *keyQuery_limit;
    int valueQuery_limit;
    keyValuePair_t *keyPairQuery_limit = 0;
    if (limit)
    {
        keyQuery_limit = strdup("limit");
        valueQuery_limit = (limit);
        keyPairQuery_limit = keyValuePair_create(keyQuery_limit, &valueQuery_limit);
        list_addElement(localVarQueryParameters,keyPairQuery_limit);
    }

    // query parameters
    char *keyQuery_pretty;
    char * valueQuery_pretty;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }

    // query parameters
    char *keyQuery_resourceVersion;
    char * valueQuery_resourceVersion;
    keyValuePair_t *keyPairQuery_resourceVersion = 0;
    if (resourceVersion)
    {
        keyQuery_resourceVersion = strdup("resourceVersion");
        valueQuery_resourceVersion = strdup((resourceVersion));
        keyPairQuery_resourceVersion = keyValuePair_create(keyQuery_resourceVersion, valueQuery_resourceVersion);
        list_addElement(localVarQueryParameters,keyPairQuery_resourceVersion);
    }

    // query parameters
    char *keyQuery_timeoutSeconds;
    int valueQuery_timeoutSeconds;
    keyValuePair_t *keyPairQuery_timeoutSeconds = 0;
    if (timeoutSeconds)
    {
        keyQuery_timeoutSeconds = strdup("timeoutSeconds");
        valueQuery_timeoutSeconds = (timeoutSeconds);
        keyPairQuery_timeoutSeconds = keyValuePair_create(keyQuery_timeoutSeconds, &valueQuery_timeoutSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_timeoutSeconds);
    }

    // query parameters
    char *keyQuery_watch;
    int valueQuery_watch;
    keyValuePair_t *keyPairQuery_watch = 0;
    if (watch)
    {
        keyQuery_watch = strdup("watch");
        valueQuery_watch = (watch);
        keyPairQuery_watch = keyValuePair_create(keyQuery_watch, &valueQuery_watch);
        list_addElement(localVarQueryParameters,keyPairQuery_watch);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    list_addElement(localVarHeaderType,"application/json;stream=watch"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf;stream=watch"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not_ container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_controller_revision_list_t *elementToReturn = v1_controller_revision_list_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(keyQuery_allowWatchBookmarks);
    keyValuePair_free(keyPairQuery_allowWatchBookmarks);
    free(keyQuery_continue);
    free(valueQuery_continue);
    keyValuePair_free(keyPairQuery_continue);
    free(keyQuery_fieldSelector);
    free(valueQuery_fieldSelector);
    keyValuePair_free(keyPairQuery_fieldSelector);
    free(keyQuery_labelSelector);
    free(valueQuery_labelSelector);
    keyValuePair_free(keyPairQuery_labelSelector);
    free(keyQuery_limit);
    keyValuePair_free(keyPairQuery_limit);
    free(keyQuery_pretty);
    free(valueQuery_pretty);
    keyValuePair_free(keyPairQuery_pretty);
    free(keyQuery_resourceVersion);
    free(valueQuery_resourceVersion);
    keyValuePair_free(keyPairQuery_resourceVersion);
    free(keyQuery_timeoutSeconds);
    keyValuePair_free(keyPairQuery_timeoutSeconds);
    free(keyQuery_watch);
    keyValuePair_free(keyPairQuery_watch);
    return elementToReturn;
end:
    return NULL;

}

// list or watch objects of kind DaemonSet
//
v1_daemon_set_list_t*
AppsV1API_listAppsV1DaemonSetForAllNamespaces(apiClient_t *apiClient ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * pretty ,char * resourceVersion ,int timeoutSeconds ,int watch)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/daemonsets")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/daemonsets");




    // query parameters
    char *keyQuery_allowWatchBookmarks;
    int valueQuery_allowWatchBookmarks;
    keyValuePair_t *keyPairQuery_allowWatchBookmarks = 0;
    if (allowWatchBookmarks)
    {
        keyQuery_allowWatchBookmarks = strdup("allowWatchBookmarks");
        valueQuery_allowWatchBookmarks = (allowWatchBookmarks);
        keyPairQuery_allowWatchBookmarks = keyValuePair_create(keyQuery_allowWatchBookmarks, &valueQuery_allowWatchBookmarks);
        list_addElement(localVarQueryParameters,keyPairQuery_allowWatchBookmarks);
    }

    // query parameters
    char *keyQuery_continue;
    char * valueQuery_continue;
    keyValuePair_t *keyPairQuery_continue = 0;
    if (continue_)
    {
        keyQuery_continue = strdup("continue_");
        valueQuery_continue = strdup((continue_));
        keyPairQuery_continue = keyValuePair_create(keyQuery_continue, valueQuery_continue);
        list_addElement(localVarQueryParameters,keyPairQuery_continue);
    }

    // query parameters
    char *keyQuery_fieldSelector;
    char * valueQuery_fieldSelector;
    keyValuePair_t *keyPairQuery_fieldSelector = 0;
    if (fieldSelector)
    {
        keyQuery_fieldSelector = strdup("fieldSelector");
        valueQuery_fieldSelector = strdup((fieldSelector));
        keyPairQuery_fieldSelector = keyValuePair_create(keyQuery_fieldSelector, valueQuery_fieldSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldSelector);
    }

    // query parameters
    char *keyQuery_labelSelector;
    char * valueQuery_labelSelector;
    keyValuePair_t *keyPairQuery_labelSelector = 0;
    if (labelSelector)
    {
        keyQuery_labelSelector = strdup("labelSelector");
        valueQuery_labelSelector = strdup((labelSelector));
        keyPairQuery_labelSelector = keyValuePair_create(keyQuery_labelSelector, valueQuery_labelSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_labelSelector);
    }

    // query parameters
    char *keyQuery_limit;
    int valueQuery_limit;
    keyValuePair_t *keyPairQuery_limit = 0;
    if (limit)
    {
        keyQuery_limit = strdup("limit");
        valueQuery_limit = (limit);
        keyPairQuery_limit = keyValuePair_create(keyQuery_limit, &valueQuery_limit);
        list_addElement(localVarQueryParameters,keyPairQuery_limit);
    }

    // query parameters
    char *keyQuery_pretty;
    char * valueQuery_pretty;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }

    // query parameters
    char *keyQuery_resourceVersion;
    char * valueQuery_resourceVersion;
    keyValuePair_t *keyPairQuery_resourceVersion = 0;
    if (resourceVersion)
    {
        keyQuery_resourceVersion = strdup("resourceVersion");
        valueQuery_resourceVersion = strdup((resourceVersion));
        keyPairQuery_resourceVersion = keyValuePair_create(keyQuery_resourceVersion, valueQuery_resourceVersion);
        list_addElement(localVarQueryParameters,keyPairQuery_resourceVersion);
    }

    // query parameters
    char *keyQuery_timeoutSeconds;
    int valueQuery_timeoutSeconds;
    keyValuePair_t *keyPairQuery_timeoutSeconds = 0;
    if (timeoutSeconds)
    {
        keyQuery_timeoutSeconds = strdup("timeoutSeconds");
        valueQuery_timeoutSeconds = (timeoutSeconds);
        keyPairQuery_timeoutSeconds = keyValuePair_create(keyQuery_timeoutSeconds, &valueQuery_timeoutSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_timeoutSeconds);
    }

    // query parameters
    char *keyQuery_watch;
    int valueQuery_watch;
    keyValuePair_t *keyPairQuery_watch = 0;
    if (watch)
    {
        keyQuery_watch = strdup("watch");
        valueQuery_watch = (watch);
        keyPairQuery_watch = keyValuePair_create(keyQuery_watch, &valueQuery_watch);
        list_addElement(localVarQueryParameters,keyPairQuery_watch);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    list_addElement(localVarHeaderType,"application/json;stream=watch"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf;stream=watch"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not_ container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_daemon_set_list_t *elementToReturn = v1_daemon_set_list_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(keyQuery_allowWatchBookmarks);
    keyValuePair_free(keyPairQuery_allowWatchBookmarks);
    free(keyQuery_continue);
    free(valueQuery_continue);
    keyValuePair_free(keyPairQuery_continue);
    free(keyQuery_fieldSelector);
    free(valueQuery_fieldSelector);
    keyValuePair_free(keyPairQuery_fieldSelector);
    free(keyQuery_labelSelector);
    free(valueQuery_labelSelector);
    keyValuePair_free(keyPairQuery_labelSelector);
    free(keyQuery_limit);
    keyValuePair_free(keyPairQuery_limit);
    free(keyQuery_pretty);
    free(valueQuery_pretty);
    keyValuePair_free(keyPairQuery_pretty);
    free(keyQuery_resourceVersion);
    free(valueQuery_resourceVersion);
    keyValuePair_free(keyPairQuery_resourceVersion);
    free(keyQuery_timeoutSeconds);
    keyValuePair_free(keyPairQuery_timeoutSeconds);
    free(keyQuery_watch);
    keyValuePair_free(keyPairQuery_watch);
    return elementToReturn;
end:
    return NULL;

}

// list or watch objects of kind Deployment
//
v1_deployment_list_t*
AppsV1API_listAppsV1DeploymentForAllNamespaces(apiClient_t *apiClient ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * pretty ,char * resourceVersion ,int timeoutSeconds ,int watch)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/deployments")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/deployments");




    // query parameters
    char *keyQuery_allowWatchBookmarks;
    int valueQuery_allowWatchBookmarks;
    keyValuePair_t *keyPairQuery_allowWatchBookmarks = 0;
    if (allowWatchBookmarks)
    {
        keyQuery_allowWatchBookmarks = strdup("allowWatchBookmarks");
        valueQuery_allowWatchBookmarks = (allowWatchBookmarks);
        keyPairQuery_allowWatchBookmarks = keyValuePair_create(keyQuery_allowWatchBookmarks, &valueQuery_allowWatchBookmarks);
        list_addElement(localVarQueryParameters,keyPairQuery_allowWatchBookmarks);
    }

    // query parameters
    char *keyQuery_continue;
    char * valueQuery_continue;
    keyValuePair_t *keyPairQuery_continue = 0;
    if (continue_)
    {
        keyQuery_continue = strdup("continue_");
        valueQuery_continue = strdup((continue_));
        keyPairQuery_continue = keyValuePair_create(keyQuery_continue, valueQuery_continue);
        list_addElement(localVarQueryParameters,keyPairQuery_continue);
    }

    // query parameters
    char *keyQuery_fieldSelector;
    char * valueQuery_fieldSelector;
    keyValuePair_t *keyPairQuery_fieldSelector = 0;
    if (fieldSelector)
    {
        keyQuery_fieldSelector = strdup("fieldSelector");
        valueQuery_fieldSelector = strdup((fieldSelector));
        keyPairQuery_fieldSelector = keyValuePair_create(keyQuery_fieldSelector, valueQuery_fieldSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldSelector);
    }

    // query parameters
    char *keyQuery_labelSelector;
    char * valueQuery_labelSelector;
    keyValuePair_t *keyPairQuery_labelSelector = 0;
    if (labelSelector)
    {
        keyQuery_labelSelector = strdup("labelSelector");
        valueQuery_labelSelector = strdup((labelSelector));
        keyPairQuery_labelSelector = keyValuePair_create(keyQuery_labelSelector, valueQuery_labelSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_labelSelector);
    }

    // query parameters
    char *keyQuery_limit;
    int valueQuery_limit;
    keyValuePair_t *keyPairQuery_limit = 0;
    if (limit)
    {
        keyQuery_limit = strdup("limit");
        valueQuery_limit = (limit);
        keyPairQuery_limit = keyValuePair_create(keyQuery_limit, &valueQuery_limit);
        list_addElement(localVarQueryParameters,keyPairQuery_limit);
    }

    // query parameters
    char *keyQuery_pretty;
    char * valueQuery_pretty;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }

    // query parameters
    char *keyQuery_resourceVersion;
    char * valueQuery_resourceVersion;
    keyValuePair_t *keyPairQuery_resourceVersion = 0;
    if (resourceVersion)
    {
        keyQuery_resourceVersion = strdup("resourceVersion");
        valueQuery_resourceVersion = strdup((resourceVersion));
        keyPairQuery_resourceVersion = keyValuePair_create(keyQuery_resourceVersion, valueQuery_resourceVersion);
        list_addElement(localVarQueryParameters,keyPairQuery_resourceVersion);
    }

    // query parameters
    char *keyQuery_timeoutSeconds;
    int valueQuery_timeoutSeconds;
    keyValuePair_t *keyPairQuery_timeoutSeconds = 0;
    if (timeoutSeconds)
    {
        keyQuery_timeoutSeconds = strdup("timeoutSeconds");
        valueQuery_timeoutSeconds = (timeoutSeconds);
        keyPairQuery_timeoutSeconds = keyValuePair_create(keyQuery_timeoutSeconds, &valueQuery_timeoutSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_timeoutSeconds);
    }

    // query parameters
    char *keyQuery_watch;
    int valueQuery_watch;
    keyValuePair_t *keyPairQuery_watch = 0;
    if (watch)
    {
        keyQuery_watch = strdup("watch");
        valueQuery_watch = (watch);
        keyPairQuery_watch = keyValuePair_create(keyQuery_watch, &valueQuery_watch);
        list_addElement(localVarQueryParameters,keyPairQuery_watch);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    list_addElement(localVarHeaderType,"application/json;stream=watch"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf;stream=watch"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not_ container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_deployment_list_t *elementToReturn = v1_deployment_list_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(keyQuery_allowWatchBookmarks);
    keyValuePair_free(keyPairQuery_allowWatchBookmarks);
    free(keyQuery_continue);
    free(valueQuery_continue);
    keyValuePair_free(keyPairQuery_continue);
    free(keyQuery_fieldSelector);
    free(valueQuery_fieldSelector);
    keyValuePair_free(keyPairQuery_fieldSelector);
    free(keyQuery_labelSelector);
    free(valueQuery_labelSelector);
    keyValuePair_free(keyPairQuery_labelSelector);
    free(keyQuery_limit);
    keyValuePair_free(keyPairQuery_limit);
    free(keyQuery_pretty);
    free(valueQuery_pretty);
    keyValuePair_free(keyPairQuery_pretty);
    free(keyQuery_resourceVersion);
    free(valueQuery_resourceVersion);
    keyValuePair_free(keyPairQuery_resourceVersion);
    free(keyQuery_timeoutSeconds);
    keyValuePair_free(keyPairQuery_timeoutSeconds);
    free(keyQuery_watch);
    keyValuePair_free(keyPairQuery_watch);
    return elementToReturn;
end:
    return NULL;

}

// list or watch objects of kind ControllerRevision
//
v1_controller_revision_list_t*
AppsV1API_listAppsV1NamespacedControllerRevision(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/controllerrevisions")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/controllerrevisions");


    // Path Params
    long sizeOfPathParams_namespace = strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



    // query parameters
    char *keyQuery_pretty;
    char * valueQuery_pretty;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }

    // query parameters
    char *keyQuery_allowWatchBookmarks;
    int valueQuery_allowWatchBookmarks;
    keyValuePair_t *keyPairQuery_allowWatchBookmarks = 0;
    if (allowWatchBookmarks)
    {
        keyQuery_allowWatchBookmarks = strdup("allowWatchBookmarks");
        valueQuery_allowWatchBookmarks = (allowWatchBookmarks);
        keyPairQuery_allowWatchBookmarks = keyValuePair_create(keyQuery_allowWatchBookmarks, &valueQuery_allowWatchBookmarks);
        list_addElement(localVarQueryParameters,keyPairQuery_allowWatchBookmarks);
    }

    // query parameters
    char *keyQuery_continue;
    char * valueQuery_continue;
    keyValuePair_t *keyPairQuery_continue = 0;
    if (continue_)
    {
        keyQuery_continue = strdup("continue_");
        valueQuery_continue = strdup((continue_));
        keyPairQuery_continue = keyValuePair_create(keyQuery_continue, valueQuery_continue);
        list_addElement(localVarQueryParameters,keyPairQuery_continue);
    }

    // query parameters
    char *keyQuery_fieldSelector;
    char * valueQuery_fieldSelector;
    keyValuePair_t *keyPairQuery_fieldSelector = 0;
    if (fieldSelector)
    {
        keyQuery_fieldSelector = strdup("fieldSelector");
        valueQuery_fieldSelector = strdup((fieldSelector));
        keyPairQuery_fieldSelector = keyValuePair_create(keyQuery_fieldSelector, valueQuery_fieldSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldSelector);
    }

    // query parameters
    char *keyQuery_labelSelector;
    char * valueQuery_labelSelector;
    keyValuePair_t *keyPairQuery_labelSelector = 0;
    if (labelSelector)
    {
        keyQuery_labelSelector = strdup("labelSelector");
        valueQuery_labelSelector = strdup((labelSelector));
        keyPairQuery_labelSelector = keyValuePair_create(keyQuery_labelSelector, valueQuery_labelSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_labelSelector);
    }

    // query parameters
    char *keyQuery_limit;
    int valueQuery_limit;
    keyValuePair_t *keyPairQuery_limit = 0;
    if (limit)
    {
        keyQuery_limit = strdup("limit");
        valueQuery_limit = (limit);
        keyPairQuery_limit = keyValuePair_create(keyQuery_limit, &valueQuery_limit);
        list_addElement(localVarQueryParameters,keyPairQuery_limit);
    }

    // query parameters
    char *keyQuery_resourceVersion;
    char * valueQuery_resourceVersion;
    keyValuePair_t *keyPairQuery_resourceVersion = 0;
    if (resourceVersion)
    {
        keyQuery_resourceVersion = strdup("resourceVersion");
        valueQuery_resourceVersion = strdup((resourceVersion));
        keyPairQuery_resourceVersion = keyValuePair_create(keyQuery_resourceVersion, valueQuery_resourceVersion);
        list_addElement(localVarQueryParameters,keyPairQuery_resourceVersion);
    }

    // query parameters
    char *keyQuery_timeoutSeconds;
    int valueQuery_timeoutSeconds;
    keyValuePair_t *keyPairQuery_timeoutSeconds = 0;
    if (timeoutSeconds)
    {
        keyQuery_timeoutSeconds = strdup("timeoutSeconds");
        valueQuery_timeoutSeconds = (timeoutSeconds);
        keyPairQuery_timeoutSeconds = keyValuePair_create(keyQuery_timeoutSeconds, &valueQuery_timeoutSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_timeoutSeconds);
    }

    // query parameters
    char *keyQuery_watch;
    int valueQuery_watch;
    keyValuePair_t *keyPairQuery_watch = 0;
    if (watch)
    {
        keyQuery_watch = strdup("watch");
        valueQuery_watch = (watch);
        keyPairQuery_watch = keyValuePair_create(keyQuery_watch, &valueQuery_watch);
        list_addElement(localVarQueryParameters,keyPairQuery_watch);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    list_addElement(localVarHeaderType,"application/json;stream=watch"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf;stream=watch"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not_ container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_controller_revision_list_t *elementToReturn = v1_controller_revision_list_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_namespace);
    free(keyQuery_pretty);
    free(valueQuery_pretty);
    keyValuePair_free(keyPairQuery_pretty);
    free(keyQuery_allowWatchBookmarks);
    keyValuePair_free(keyPairQuery_allowWatchBookmarks);
    free(keyQuery_continue);
    free(valueQuery_continue);
    keyValuePair_free(keyPairQuery_continue);
    free(keyQuery_fieldSelector);
    free(valueQuery_fieldSelector);
    keyValuePair_free(keyPairQuery_fieldSelector);
    free(keyQuery_labelSelector);
    free(valueQuery_labelSelector);
    keyValuePair_free(keyPairQuery_labelSelector);
    free(keyQuery_limit);
    keyValuePair_free(keyPairQuery_limit);
    free(keyQuery_resourceVersion);
    free(valueQuery_resourceVersion);
    keyValuePair_free(keyPairQuery_resourceVersion);
    free(keyQuery_timeoutSeconds);
    keyValuePair_free(keyPairQuery_timeoutSeconds);
    free(keyQuery_watch);
    keyValuePair_free(keyPairQuery_watch);
    return elementToReturn;
end:
    return NULL;

}

// list or watch objects of kind DaemonSet
//
v1_daemon_set_list_t*
AppsV1API_listAppsV1NamespacedDaemonSet(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/daemonsets")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/daemonsets");


    // Path Params
    long sizeOfPathParams_namespace = strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



    // query parameters
    char *keyQuery_pretty;
    char * valueQuery_pretty;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }

    // query parameters
    char *keyQuery_allowWatchBookmarks;
    int valueQuery_allowWatchBookmarks;
    keyValuePair_t *keyPairQuery_allowWatchBookmarks = 0;
    if (allowWatchBookmarks)
    {
        keyQuery_allowWatchBookmarks = strdup("allowWatchBookmarks");
        valueQuery_allowWatchBookmarks = (allowWatchBookmarks);
        keyPairQuery_allowWatchBookmarks = keyValuePair_create(keyQuery_allowWatchBookmarks, &valueQuery_allowWatchBookmarks);
        list_addElement(localVarQueryParameters,keyPairQuery_allowWatchBookmarks);
    }

    // query parameters
    char *keyQuery_continue;
    char * valueQuery_continue;
    keyValuePair_t *keyPairQuery_continue = 0;
    if (continue_)
    {
        keyQuery_continue = strdup("continue_");
        valueQuery_continue = strdup((continue_));
        keyPairQuery_continue = keyValuePair_create(keyQuery_continue, valueQuery_continue);
        list_addElement(localVarQueryParameters,keyPairQuery_continue);
    }

    // query parameters
    char *keyQuery_fieldSelector;
    char * valueQuery_fieldSelector;
    keyValuePair_t *keyPairQuery_fieldSelector = 0;
    if (fieldSelector)
    {
        keyQuery_fieldSelector = strdup("fieldSelector");
        valueQuery_fieldSelector = strdup((fieldSelector));
        keyPairQuery_fieldSelector = keyValuePair_create(keyQuery_fieldSelector, valueQuery_fieldSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldSelector);
    }

    // query parameters
    char *keyQuery_labelSelector;
    char * valueQuery_labelSelector;
    keyValuePair_t *keyPairQuery_labelSelector = 0;
    if (labelSelector)
    {
        keyQuery_labelSelector = strdup("labelSelector");
        valueQuery_labelSelector = strdup((labelSelector));
        keyPairQuery_labelSelector = keyValuePair_create(keyQuery_labelSelector, valueQuery_labelSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_labelSelector);
    }

    // query parameters
    char *keyQuery_limit;
    int valueQuery_limit;
    keyValuePair_t *keyPairQuery_limit = 0;
    if (limit)
    {
        keyQuery_limit = strdup("limit");
        valueQuery_limit = (limit);
        keyPairQuery_limit = keyValuePair_create(keyQuery_limit, &valueQuery_limit);
        list_addElement(localVarQueryParameters,keyPairQuery_limit);
    }

    // query parameters
    char *keyQuery_resourceVersion;
    char * valueQuery_resourceVersion;
    keyValuePair_t *keyPairQuery_resourceVersion = 0;
    if (resourceVersion)
    {
        keyQuery_resourceVersion = strdup("resourceVersion");
        valueQuery_resourceVersion = strdup((resourceVersion));
        keyPairQuery_resourceVersion = keyValuePair_create(keyQuery_resourceVersion, valueQuery_resourceVersion);
        list_addElement(localVarQueryParameters,keyPairQuery_resourceVersion);
    }

    // query parameters
    char *keyQuery_timeoutSeconds;
    int valueQuery_timeoutSeconds;
    keyValuePair_t *keyPairQuery_timeoutSeconds = 0;
    if (timeoutSeconds)
    {
        keyQuery_timeoutSeconds = strdup("timeoutSeconds");
        valueQuery_timeoutSeconds = (timeoutSeconds);
        keyPairQuery_timeoutSeconds = keyValuePair_create(keyQuery_timeoutSeconds, &valueQuery_timeoutSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_timeoutSeconds);
    }

    // query parameters
    char *keyQuery_watch;
    int valueQuery_watch;
    keyValuePair_t *keyPairQuery_watch = 0;
    if (watch)
    {
        keyQuery_watch = strdup("watch");
        valueQuery_watch = (watch);
        keyPairQuery_watch = keyValuePair_create(keyQuery_watch, &valueQuery_watch);
        list_addElement(localVarQueryParameters,keyPairQuery_watch);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    list_addElement(localVarHeaderType,"application/json;stream=watch"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf;stream=watch"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not_ container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_daemon_set_list_t *elementToReturn = v1_daemon_set_list_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_namespace);
    free(keyQuery_pretty);
    free(valueQuery_pretty);
    keyValuePair_free(keyPairQuery_pretty);
    free(keyQuery_allowWatchBookmarks);
    keyValuePair_free(keyPairQuery_allowWatchBookmarks);
    free(keyQuery_continue);
    free(valueQuery_continue);
    keyValuePair_free(keyPairQuery_continue);
    free(keyQuery_fieldSelector);
    free(valueQuery_fieldSelector);
    keyValuePair_free(keyPairQuery_fieldSelector);
    free(keyQuery_labelSelector);
    free(valueQuery_labelSelector);
    keyValuePair_free(keyPairQuery_labelSelector);
    free(keyQuery_limit);
    keyValuePair_free(keyPairQuery_limit);
    free(keyQuery_resourceVersion);
    free(valueQuery_resourceVersion);
    keyValuePair_free(keyPairQuery_resourceVersion);
    free(keyQuery_timeoutSeconds);
    keyValuePair_free(keyPairQuery_timeoutSeconds);
    free(keyQuery_watch);
    keyValuePair_free(keyPairQuery_watch);
    return elementToReturn;
end:
    return NULL;

}

// list or watch objects of kind Deployment
//
v1_deployment_list_t*
AppsV1API_listAppsV1NamespacedDeployment(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/deployments")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/deployments");


    // Path Params
    long sizeOfPathParams_namespace = strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



    // query parameters
    char *keyQuery_pretty;
    char * valueQuery_pretty;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }

    // query parameters
    char *keyQuery_allowWatchBookmarks;
    int valueQuery_allowWatchBookmarks;
    keyValuePair_t *keyPairQuery_allowWatchBookmarks = 0;
    if (allowWatchBookmarks)
    {
        keyQuery_allowWatchBookmarks = strdup("allowWatchBookmarks");
        valueQuery_allowWatchBookmarks = (allowWatchBookmarks);
        keyPairQuery_allowWatchBookmarks = keyValuePair_create(keyQuery_allowWatchBookmarks, &valueQuery_allowWatchBookmarks);
        list_addElement(localVarQueryParameters,keyPairQuery_allowWatchBookmarks);
    }

    // query parameters
    char *keyQuery_continue;
    char * valueQuery_continue;
    keyValuePair_t *keyPairQuery_continue = 0;
    if (continue_)
    {
        keyQuery_continue = strdup("continue_");
        valueQuery_continue = strdup((continue_));
        keyPairQuery_continue = keyValuePair_create(keyQuery_continue, valueQuery_continue);
        list_addElement(localVarQueryParameters,keyPairQuery_continue);
    }

    // query parameters
    char *keyQuery_fieldSelector;
    char * valueQuery_fieldSelector;
    keyValuePair_t *keyPairQuery_fieldSelector = 0;
    if (fieldSelector)
    {
        keyQuery_fieldSelector = strdup("fieldSelector");
        valueQuery_fieldSelector = strdup((fieldSelector));
        keyPairQuery_fieldSelector = keyValuePair_create(keyQuery_fieldSelector, valueQuery_fieldSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldSelector);
    }

    // query parameters
    char *keyQuery_labelSelector;
    char * valueQuery_labelSelector;
    keyValuePair_t *keyPairQuery_labelSelector = 0;
    if (labelSelector)
    {
        keyQuery_labelSelector = strdup("labelSelector");
        valueQuery_labelSelector = strdup((labelSelector));
        keyPairQuery_labelSelector = keyValuePair_create(keyQuery_labelSelector, valueQuery_labelSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_labelSelector);
    }

    // query parameters
    char *keyQuery_limit;
    int valueQuery_limit;
    keyValuePair_t *keyPairQuery_limit = 0;
    if (limit)
    {
        keyQuery_limit = strdup("limit");
        valueQuery_limit = (limit);
        keyPairQuery_limit = keyValuePair_create(keyQuery_limit, &valueQuery_limit);
        list_addElement(localVarQueryParameters,keyPairQuery_limit);
    }

    // query parameters
    char *keyQuery_resourceVersion;
    char * valueQuery_resourceVersion;
    keyValuePair_t *keyPairQuery_resourceVersion = 0;
    if (resourceVersion)
    {
        keyQuery_resourceVersion = strdup("resourceVersion");
        valueQuery_resourceVersion = strdup((resourceVersion));
        keyPairQuery_resourceVersion = keyValuePair_create(keyQuery_resourceVersion, valueQuery_resourceVersion);
        list_addElement(localVarQueryParameters,keyPairQuery_resourceVersion);
    }

    // query parameters
    char *keyQuery_timeoutSeconds;
    int valueQuery_timeoutSeconds;
    keyValuePair_t *keyPairQuery_timeoutSeconds = 0;
    if (timeoutSeconds)
    {
        keyQuery_timeoutSeconds = strdup("timeoutSeconds");
        valueQuery_timeoutSeconds = (timeoutSeconds);
        keyPairQuery_timeoutSeconds = keyValuePair_create(keyQuery_timeoutSeconds, &valueQuery_timeoutSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_timeoutSeconds);
    }

    // query parameters
    char *keyQuery_watch;
    int valueQuery_watch;
    keyValuePair_t *keyPairQuery_watch = 0;
    if (watch)
    {
        keyQuery_watch = strdup("watch");
        valueQuery_watch = (watch);
        keyPairQuery_watch = keyValuePair_create(keyQuery_watch, &valueQuery_watch);
        list_addElement(localVarQueryParameters,keyPairQuery_watch);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    list_addElement(localVarHeaderType,"application/json;stream=watch"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf;stream=watch"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not_ container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_deployment_list_t *elementToReturn = v1_deployment_list_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_namespace);
    free(keyQuery_pretty);
    free(valueQuery_pretty);
    keyValuePair_free(keyPairQuery_pretty);
    free(keyQuery_allowWatchBookmarks);
    keyValuePair_free(keyPairQuery_allowWatchBookmarks);
    free(keyQuery_continue);
    free(valueQuery_continue);
    keyValuePair_free(keyPairQuery_continue);
    free(keyQuery_fieldSelector);
    free(valueQuery_fieldSelector);
    keyValuePair_free(keyPairQuery_fieldSelector);
    free(keyQuery_labelSelector);
    free(valueQuery_labelSelector);
    keyValuePair_free(keyPairQuery_labelSelector);
    free(keyQuery_limit);
    keyValuePair_free(keyPairQuery_limit);
    free(keyQuery_resourceVersion);
    free(valueQuery_resourceVersion);
    keyValuePair_free(keyPairQuery_resourceVersion);
    free(keyQuery_timeoutSeconds);
    keyValuePair_free(keyPairQuery_timeoutSeconds);
    free(keyQuery_watch);
    keyValuePair_free(keyPairQuery_watch);
    return elementToReturn;
end:
    return NULL;

}

// list or watch objects of kind ReplicaSet
//
v1_replica_set_list_t*
AppsV1API_listAppsV1NamespacedReplicaSet(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/replicasets")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/replicasets");


    // Path Params
    long sizeOfPathParams_namespace = strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



    // query parameters
    char *keyQuery_pretty;
    char * valueQuery_pretty;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }

    // query parameters
    char *keyQuery_allowWatchBookmarks;
    int valueQuery_allowWatchBookmarks;
    keyValuePair_t *keyPairQuery_allowWatchBookmarks = 0;
    if (allowWatchBookmarks)
    {
        keyQuery_allowWatchBookmarks = strdup("allowWatchBookmarks");
        valueQuery_allowWatchBookmarks = (allowWatchBookmarks);
        keyPairQuery_allowWatchBookmarks = keyValuePair_create(keyQuery_allowWatchBookmarks, &valueQuery_allowWatchBookmarks);
        list_addElement(localVarQueryParameters,keyPairQuery_allowWatchBookmarks);
    }

    // query parameters
    char *keyQuery_continue;
    char * valueQuery_continue;
    keyValuePair_t *keyPairQuery_continue = 0;
    if (continue_)
    {
        keyQuery_continue = strdup("continue_");
        valueQuery_continue = strdup((continue_));
        keyPairQuery_continue = keyValuePair_create(keyQuery_continue, valueQuery_continue);
        list_addElement(localVarQueryParameters,keyPairQuery_continue);
    }

    // query parameters
    char *keyQuery_fieldSelector;
    char * valueQuery_fieldSelector;
    keyValuePair_t *keyPairQuery_fieldSelector = 0;
    if (fieldSelector)
    {
        keyQuery_fieldSelector = strdup("fieldSelector");
        valueQuery_fieldSelector = strdup((fieldSelector));
        keyPairQuery_fieldSelector = keyValuePair_create(keyQuery_fieldSelector, valueQuery_fieldSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldSelector);
    }

    // query parameters
    char *keyQuery_labelSelector;
    char * valueQuery_labelSelector;
    keyValuePair_t *keyPairQuery_labelSelector = 0;
    if (labelSelector)
    {
        keyQuery_labelSelector = strdup("labelSelector");
        valueQuery_labelSelector = strdup((labelSelector));
        keyPairQuery_labelSelector = keyValuePair_create(keyQuery_labelSelector, valueQuery_labelSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_labelSelector);
    }

    // query parameters
    char *keyQuery_limit;
    int valueQuery_limit;
    keyValuePair_t *keyPairQuery_limit = 0;
    if (limit)
    {
        keyQuery_limit = strdup("limit");
        valueQuery_limit = (limit);
        keyPairQuery_limit = keyValuePair_create(keyQuery_limit, &valueQuery_limit);
        list_addElement(localVarQueryParameters,keyPairQuery_limit);
    }

    // query parameters
    char *keyQuery_resourceVersion;
    char * valueQuery_resourceVersion;
    keyValuePair_t *keyPairQuery_resourceVersion = 0;
    if (resourceVersion)
    {
        keyQuery_resourceVersion = strdup("resourceVersion");
        valueQuery_resourceVersion = strdup((resourceVersion));
        keyPairQuery_resourceVersion = keyValuePair_create(keyQuery_resourceVersion, valueQuery_resourceVersion);
        list_addElement(localVarQueryParameters,keyPairQuery_resourceVersion);
    }

    // query parameters
    char *keyQuery_timeoutSeconds;
    int valueQuery_timeoutSeconds;
    keyValuePair_t *keyPairQuery_timeoutSeconds = 0;
    if (timeoutSeconds)
    {
        keyQuery_timeoutSeconds = strdup("timeoutSeconds");
        valueQuery_timeoutSeconds = (timeoutSeconds);
        keyPairQuery_timeoutSeconds = keyValuePair_create(keyQuery_timeoutSeconds, &valueQuery_timeoutSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_timeoutSeconds);
    }

    // query parameters
    char *keyQuery_watch;
    int valueQuery_watch;
    keyValuePair_t *keyPairQuery_watch = 0;
    if (watch)
    {
        keyQuery_watch = strdup("watch");
        valueQuery_watch = (watch);
        keyPairQuery_watch = keyValuePair_create(keyQuery_watch, &valueQuery_watch);
        list_addElement(localVarQueryParameters,keyPairQuery_watch);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    list_addElement(localVarHeaderType,"application/json;stream=watch"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf;stream=watch"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not_ container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_replica_set_list_t *elementToReturn = v1_replica_set_list_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_namespace);
    free(keyQuery_pretty);
    free(valueQuery_pretty);
    keyValuePair_free(keyPairQuery_pretty);
    free(keyQuery_allowWatchBookmarks);
    keyValuePair_free(keyPairQuery_allowWatchBookmarks);
    free(keyQuery_continue);
    free(valueQuery_continue);
    keyValuePair_free(keyPairQuery_continue);
    free(keyQuery_fieldSelector);
    free(valueQuery_fieldSelector);
    keyValuePair_free(keyPairQuery_fieldSelector);
    free(keyQuery_labelSelector);
    free(valueQuery_labelSelector);
    keyValuePair_free(keyPairQuery_labelSelector);
    free(keyQuery_limit);
    keyValuePair_free(keyPairQuery_limit);
    free(keyQuery_resourceVersion);
    free(valueQuery_resourceVersion);
    keyValuePair_free(keyPairQuery_resourceVersion);
    free(keyQuery_timeoutSeconds);
    keyValuePair_free(keyPairQuery_timeoutSeconds);
    free(keyQuery_watch);
    keyValuePair_free(keyPairQuery_watch);
    return elementToReturn;
end:
    return NULL;

}

// list or watch objects of kind StatefulSet
//
v1_stateful_set_list_t*
AppsV1API_listAppsV1NamespacedStatefulSet(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/statefulsets")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/statefulsets");


    // Path Params
    long sizeOfPathParams_namespace = strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



    // query parameters
    char *keyQuery_pretty;
    char * valueQuery_pretty;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }

    // query parameters
    char *keyQuery_allowWatchBookmarks;
    int valueQuery_allowWatchBookmarks;
    keyValuePair_t *keyPairQuery_allowWatchBookmarks = 0;
    if (allowWatchBookmarks)
    {
        keyQuery_allowWatchBookmarks = strdup("allowWatchBookmarks");
        valueQuery_allowWatchBookmarks = (allowWatchBookmarks);
        keyPairQuery_allowWatchBookmarks = keyValuePair_create(keyQuery_allowWatchBookmarks, &valueQuery_allowWatchBookmarks);
        list_addElement(localVarQueryParameters,keyPairQuery_allowWatchBookmarks);
    }

    // query parameters
    char *keyQuery_continue;
    char * valueQuery_continue;
    keyValuePair_t *keyPairQuery_continue = 0;
    if (continue_)
    {
        keyQuery_continue = strdup("continue_");
        valueQuery_continue = strdup((continue_));
        keyPairQuery_continue = keyValuePair_create(keyQuery_continue, valueQuery_continue);
        list_addElement(localVarQueryParameters,keyPairQuery_continue);
    }

    // query parameters
    char *keyQuery_fieldSelector;
    char * valueQuery_fieldSelector;
    keyValuePair_t *keyPairQuery_fieldSelector = 0;
    if (fieldSelector)
    {
        keyQuery_fieldSelector = strdup("fieldSelector");
        valueQuery_fieldSelector = strdup((fieldSelector));
        keyPairQuery_fieldSelector = keyValuePair_create(keyQuery_fieldSelector, valueQuery_fieldSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldSelector);
    }

    // query parameters
    char *keyQuery_labelSelector;
    char * valueQuery_labelSelector;
    keyValuePair_t *keyPairQuery_labelSelector = 0;
    if (labelSelector)
    {
        keyQuery_labelSelector = strdup("labelSelector");
        valueQuery_labelSelector = strdup((labelSelector));
        keyPairQuery_labelSelector = keyValuePair_create(keyQuery_labelSelector, valueQuery_labelSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_labelSelector);
    }

    // query parameters
    char *keyQuery_limit;
    int valueQuery_limit;
    keyValuePair_t *keyPairQuery_limit = 0;
    if (limit)
    {
        keyQuery_limit = strdup("limit");
        valueQuery_limit = (limit);
        keyPairQuery_limit = keyValuePair_create(keyQuery_limit, &valueQuery_limit);
        list_addElement(localVarQueryParameters,keyPairQuery_limit);
    }

    // query parameters
    char *keyQuery_resourceVersion;
    char * valueQuery_resourceVersion;
    keyValuePair_t *keyPairQuery_resourceVersion = 0;
    if (resourceVersion)
    {
        keyQuery_resourceVersion = strdup("resourceVersion");
        valueQuery_resourceVersion = strdup((resourceVersion));
        keyPairQuery_resourceVersion = keyValuePair_create(keyQuery_resourceVersion, valueQuery_resourceVersion);
        list_addElement(localVarQueryParameters,keyPairQuery_resourceVersion);
    }

    // query parameters
    char *keyQuery_timeoutSeconds;
    int valueQuery_timeoutSeconds;
    keyValuePair_t *keyPairQuery_timeoutSeconds = 0;
    if (timeoutSeconds)
    {
        keyQuery_timeoutSeconds = strdup("timeoutSeconds");
        valueQuery_timeoutSeconds = (timeoutSeconds);
        keyPairQuery_timeoutSeconds = keyValuePair_create(keyQuery_timeoutSeconds, &valueQuery_timeoutSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_timeoutSeconds);
    }

    // query parameters
    char *keyQuery_watch;
    int valueQuery_watch;
    keyValuePair_t *keyPairQuery_watch = 0;
    if (watch)
    {
        keyQuery_watch = strdup("watch");
        valueQuery_watch = (watch);
        keyPairQuery_watch = keyValuePair_create(keyQuery_watch, &valueQuery_watch);
        list_addElement(localVarQueryParameters,keyPairQuery_watch);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    list_addElement(localVarHeaderType,"application/json;stream=watch"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf;stream=watch"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not_ container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_stateful_set_list_t *elementToReturn = v1_stateful_set_list_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_namespace);
    free(keyQuery_pretty);
    free(valueQuery_pretty);
    keyValuePair_free(keyPairQuery_pretty);
    free(keyQuery_allowWatchBookmarks);
    keyValuePair_free(keyPairQuery_allowWatchBookmarks);
    free(keyQuery_continue);
    free(valueQuery_continue);
    keyValuePair_free(keyPairQuery_continue);
    free(keyQuery_fieldSelector);
    free(valueQuery_fieldSelector);
    keyValuePair_free(keyPairQuery_fieldSelector);
    free(keyQuery_labelSelector);
    free(valueQuery_labelSelector);
    keyValuePair_free(keyPairQuery_labelSelector);
    free(keyQuery_limit);
    keyValuePair_free(keyPairQuery_limit);
    free(keyQuery_resourceVersion);
    free(valueQuery_resourceVersion);
    keyValuePair_free(keyPairQuery_resourceVersion);
    free(keyQuery_timeoutSeconds);
    keyValuePair_free(keyPairQuery_timeoutSeconds);
    free(keyQuery_watch);
    keyValuePair_free(keyPairQuery_watch);
    return elementToReturn;
end:
    return NULL;

}

// list or watch objects of kind ReplicaSet
//
v1_replica_set_list_t*
AppsV1API_listAppsV1ReplicaSetForAllNamespaces(apiClient_t *apiClient ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * pretty ,char * resourceVersion ,int timeoutSeconds ,int watch)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/replicasets")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/replicasets");




    // query parameters
    char *keyQuery_allowWatchBookmarks;
    int valueQuery_allowWatchBookmarks;
    keyValuePair_t *keyPairQuery_allowWatchBookmarks = 0;
    if (allowWatchBookmarks)
    {
        keyQuery_allowWatchBookmarks = strdup("allowWatchBookmarks");
        valueQuery_allowWatchBookmarks = (allowWatchBookmarks);
        keyPairQuery_allowWatchBookmarks = keyValuePair_create(keyQuery_allowWatchBookmarks, &valueQuery_allowWatchBookmarks);
        list_addElement(localVarQueryParameters,keyPairQuery_allowWatchBookmarks);
    }

    // query parameters
    char *keyQuery_continue;
    char * valueQuery_continue;
    keyValuePair_t *keyPairQuery_continue = 0;
    if (continue_)
    {
        keyQuery_continue = strdup("continue_");
        valueQuery_continue = strdup((continue_));
        keyPairQuery_continue = keyValuePair_create(keyQuery_continue, valueQuery_continue);
        list_addElement(localVarQueryParameters,keyPairQuery_continue);
    }

    // query parameters
    char *keyQuery_fieldSelector;
    char * valueQuery_fieldSelector;
    keyValuePair_t *keyPairQuery_fieldSelector = 0;
    if (fieldSelector)
    {
        keyQuery_fieldSelector = strdup("fieldSelector");
        valueQuery_fieldSelector = strdup((fieldSelector));
        keyPairQuery_fieldSelector = keyValuePair_create(keyQuery_fieldSelector, valueQuery_fieldSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldSelector);
    }

    // query parameters
    char *keyQuery_labelSelector;
    char * valueQuery_labelSelector;
    keyValuePair_t *keyPairQuery_labelSelector = 0;
    if (labelSelector)
    {
        keyQuery_labelSelector = strdup("labelSelector");
        valueQuery_labelSelector = strdup((labelSelector));
        keyPairQuery_labelSelector = keyValuePair_create(keyQuery_labelSelector, valueQuery_labelSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_labelSelector);
    }

    // query parameters
    char *keyQuery_limit;
    int valueQuery_limit;
    keyValuePair_t *keyPairQuery_limit = 0;
    if (limit)
    {
        keyQuery_limit = strdup("limit");
        valueQuery_limit = (limit);
        keyPairQuery_limit = keyValuePair_create(keyQuery_limit, &valueQuery_limit);
        list_addElement(localVarQueryParameters,keyPairQuery_limit);
    }

    // query parameters
    char *keyQuery_pretty;
    char * valueQuery_pretty;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }

    // query parameters
    char *keyQuery_resourceVersion;
    char * valueQuery_resourceVersion;
    keyValuePair_t *keyPairQuery_resourceVersion = 0;
    if (resourceVersion)
    {
        keyQuery_resourceVersion = strdup("resourceVersion");
        valueQuery_resourceVersion = strdup((resourceVersion));
        keyPairQuery_resourceVersion = keyValuePair_create(keyQuery_resourceVersion, valueQuery_resourceVersion);
        list_addElement(localVarQueryParameters,keyPairQuery_resourceVersion);
    }

    // query parameters
    char *keyQuery_timeoutSeconds;
    int valueQuery_timeoutSeconds;
    keyValuePair_t *keyPairQuery_timeoutSeconds = 0;
    if (timeoutSeconds)
    {
        keyQuery_timeoutSeconds = strdup("timeoutSeconds");
        valueQuery_timeoutSeconds = (timeoutSeconds);
        keyPairQuery_timeoutSeconds = keyValuePair_create(keyQuery_timeoutSeconds, &valueQuery_timeoutSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_timeoutSeconds);
    }

    // query parameters
    char *keyQuery_watch;
    int valueQuery_watch;
    keyValuePair_t *keyPairQuery_watch = 0;
    if (watch)
    {
        keyQuery_watch = strdup("watch");
        valueQuery_watch = (watch);
        keyPairQuery_watch = keyValuePair_create(keyQuery_watch, &valueQuery_watch);
        list_addElement(localVarQueryParameters,keyPairQuery_watch);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    list_addElement(localVarHeaderType,"application/json;stream=watch"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf;stream=watch"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not_ container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_replica_set_list_t *elementToReturn = v1_replica_set_list_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(keyQuery_allowWatchBookmarks);
    keyValuePair_free(keyPairQuery_allowWatchBookmarks);
    free(keyQuery_continue);
    free(valueQuery_continue);
    keyValuePair_free(keyPairQuery_continue);
    free(keyQuery_fieldSelector);
    free(valueQuery_fieldSelector);
    keyValuePair_free(keyPairQuery_fieldSelector);
    free(keyQuery_labelSelector);
    free(valueQuery_labelSelector);
    keyValuePair_free(keyPairQuery_labelSelector);
    free(keyQuery_limit);
    keyValuePair_free(keyPairQuery_limit);
    free(keyQuery_pretty);
    free(valueQuery_pretty);
    keyValuePair_free(keyPairQuery_pretty);
    free(keyQuery_resourceVersion);
    free(valueQuery_resourceVersion);
    keyValuePair_free(keyPairQuery_resourceVersion);
    free(keyQuery_timeoutSeconds);
    keyValuePair_free(keyPairQuery_timeoutSeconds);
    free(keyQuery_watch);
    keyValuePair_free(keyPairQuery_watch);
    return elementToReturn;
end:
    return NULL;

}

// list or watch objects of kind StatefulSet
//
v1_stateful_set_list_t*
AppsV1API_listAppsV1StatefulSetForAllNamespaces(apiClient_t *apiClient ,int allowWatchBookmarks ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * pretty ,char * resourceVersion ,int timeoutSeconds ,int watch)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/statefulsets")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/statefulsets");




    // query parameters
    char *keyQuery_allowWatchBookmarks;
    int valueQuery_allowWatchBookmarks;
    keyValuePair_t *keyPairQuery_allowWatchBookmarks = 0;
    if (allowWatchBookmarks)
    {
        keyQuery_allowWatchBookmarks = strdup("allowWatchBookmarks");
        valueQuery_allowWatchBookmarks = (allowWatchBookmarks);
        keyPairQuery_allowWatchBookmarks = keyValuePair_create(keyQuery_allowWatchBookmarks, &valueQuery_allowWatchBookmarks);
        list_addElement(localVarQueryParameters,keyPairQuery_allowWatchBookmarks);
    }

    // query parameters
    char *keyQuery_continue;
    char * valueQuery_continue;
    keyValuePair_t *keyPairQuery_continue = 0;
    if (continue_)
    {
        keyQuery_continue = strdup("continue_");
        valueQuery_continue = strdup((continue_));
        keyPairQuery_continue = keyValuePair_create(keyQuery_continue, valueQuery_continue);
        list_addElement(localVarQueryParameters,keyPairQuery_continue);
    }

    // query parameters
    char *keyQuery_fieldSelector;
    char * valueQuery_fieldSelector;
    keyValuePair_t *keyPairQuery_fieldSelector = 0;
    if (fieldSelector)
    {
        keyQuery_fieldSelector = strdup("fieldSelector");
        valueQuery_fieldSelector = strdup((fieldSelector));
        keyPairQuery_fieldSelector = keyValuePair_create(keyQuery_fieldSelector, valueQuery_fieldSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldSelector);
    }

    // query parameters
    char *keyQuery_labelSelector;
    char * valueQuery_labelSelector;
    keyValuePair_t *keyPairQuery_labelSelector = 0;
    if (labelSelector)
    {
        keyQuery_labelSelector = strdup("labelSelector");
        valueQuery_labelSelector = strdup((labelSelector));
        keyPairQuery_labelSelector = keyValuePair_create(keyQuery_labelSelector, valueQuery_labelSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_labelSelector);
    }

    // query parameters
    char *keyQuery_limit;
    int valueQuery_limit;
    keyValuePair_t *keyPairQuery_limit = 0;
    if (limit)
    {
        keyQuery_limit = strdup("limit");
        valueQuery_limit = (limit);
        keyPairQuery_limit = keyValuePair_create(keyQuery_limit, &valueQuery_limit);
        list_addElement(localVarQueryParameters,keyPairQuery_limit);
    }

    // query parameters
    char *keyQuery_pretty;
    char * valueQuery_pretty;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }

    // query parameters
    char *keyQuery_resourceVersion;
    char * valueQuery_resourceVersion;
    keyValuePair_t *keyPairQuery_resourceVersion = 0;
    if (resourceVersion)
    {
        keyQuery_resourceVersion = strdup("resourceVersion");
        valueQuery_resourceVersion = strdup((resourceVersion));
        keyPairQuery_resourceVersion = keyValuePair_create(keyQuery_resourceVersion, valueQuery_resourceVersion);
        list_addElement(localVarQueryParameters,keyPairQuery_resourceVersion);
    }

    // query parameters
    char *keyQuery_timeoutSeconds;
    int valueQuery_timeoutSeconds;
    keyValuePair_t *keyPairQuery_timeoutSeconds = 0;
    if (timeoutSeconds)
    {
        keyQuery_timeoutSeconds = strdup("timeoutSeconds");
        valueQuery_timeoutSeconds = (timeoutSeconds);
        keyPairQuery_timeoutSeconds = keyValuePair_create(keyQuery_timeoutSeconds, &valueQuery_timeoutSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_timeoutSeconds);
    }

    // query parameters
    char *keyQuery_watch;
    int valueQuery_watch;
    keyValuePair_t *keyPairQuery_watch = 0;
    if (watch)
    {
        keyQuery_watch = strdup("watch");
        valueQuery_watch = (watch);
        keyPairQuery_watch = keyValuePair_create(keyQuery_watch, &valueQuery_watch);
        list_addElement(localVarQueryParameters,keyPairQuery_watch);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    list_addElement(localVarHeaderType,"application/json;stream=watch"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf;stream=watch"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not_ container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_stateful_set_list_t *elementToReturn = v1_stateful_set_list_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(keyQuery_allowWatchBookmarks);
    keyValuePair_free(keyPairQuery_allowWatchBookmarks);
    free(keyQuery_continue);
    free(valueQuery_continue);
    keyValuePair_free(keyPairQuery_continue);
    free(keyQuery_fieldSelector);
    free(valueQuery_fieldSelector);
    keyValuePair_free(keyPairQuery_fieldSelector);
    free(keyQuery_labelSelector);
    free(valueQuery_labelSelector);
    keyValuePair_free(keyPairQuery_labelSelector);
    free(keyQuery_limit);
    keyValuePair_free(keyPairQuery_limit);
    free(keyQuery_pretty);
    free(valueQuery_pretty);
    keyValuePair_free(keyPairQuery_pretty);
    free(keyQuery_resourceVersion);
    free(valueQuery_resourceVersion);
    keyValuePair_free(keyPairQuery_resourceVersion);
    free(keyQuery_timeoutSeconds);
    keyValuePair_free(keyPairQuery_timeoutSeconds);
    free(keyQuery_watch);
    keyValuePair_free(keyPairQuery_watch);
    return elementToReturn;
end:
    return NULL;

}

// partially update the specified ControllerRevision
//
v1_controller_revision_t*
AppsV1API_patchAppsV1NamespacedControllerRevision(apiClient_t *apiClient ,char * name ,char * namespace , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = list_create();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/controllerrevisions/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/controllerrevisions/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams_namespace = strlen(name)+3 + strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



    // query parameters
    char *keyQuery_pretty;
    char * valueQuery_pretty;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }

    // query parameters
    char *keyQuery_dryRun;
    char * valueQuery_dryRun;
    keyValuePair_t *keyPairQuery_dryRun = 0;
    if (dryRun)
    {
        keyQuery_dryRun = strdup("dryRun");
        valueQuery_dryRun = strdup((dryRun));
        keyPairQuery_dryRun = keyValuePair_create(keyQuery_dryRun, valueQuery_dryRun);
        list_addElement(localVarQueryParameters,keyPairQuery_dryRun);
    }

    // query parameters
    char *keyQuery_fieldManager;
    char * valueQuery_fieldManager;
    keyValuePair_t *keyPairQuery_fieldManager = 0;
    if (fieldManager)
    {
        keyQuery_fieldManager = strdup("fieldManager");
        valueQuery_fieldManager = strdup((fieldManager));
        keyPairQuery_fieldManager = keyValuePair_create(keyQuery_fieldManager, valueQuery_fieldManager);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldManager);
    }

    // query parameters
    char *keyQuery_force;
    int valueQuery_force;
    keyValuePair_t *keyPairQuery_force = 0;
    if (force)
    {
        keyQuery_force = strdup("force");
        valueQuery_force = (force);
        keyPairQuery_force = keyValuePair_create(keyQuery_force, &valueQuery_force);
        list_addElement(localVarQueryParameters,keyPairQuery_force);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = object_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    list_addElement(localVarContentType,"application/json-patch+json"); //consumes
    list_addElement(localVarContentType,"application/merge-patch+json"); //consumes
    list_addElement(localVarContentType,"application/strategic-merge-patch+json"); //consumes
    list_addElement(localVarContentType,"application/apply-patch+yaml"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "PATCH");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not_ container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_controller_revision_t *elementToReturn = v1_controller_revision_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    list_free(localVarContentType);
    free(localVarPath);
    free(localVarToReplace_name);
    free(localVarToReplace_namespace);
    cJSON_Delete(localVarSingleItemJSON_body);
    free(localVarBodyParameters);
    free(keyQuery_pretty);
    free(valueQuery_pretty);
    keyValuePair_free(keyPairQuery_pretty);
    free(keyQuery_dryRun);
    free(valueQuery_dryRun);
    keyValuePair_free(keyPairQuery_dryRun);
    free(keyQuery_fieldManager);
    free(valueQuery_fieldManager);
    keyValuePair_free(keyPairQuery_fieldManager);
    free(keyQuery_force);
    keyValuePair_free(keyPairQuery_force);
    return elementToReturn;
end:
    return NULL;

}

// partially update the specified DaemonSet
//
v1_daemon_set_t*
AppsV1API_patchAppsV1NamespacedDaemonSet(apiClient_t *apiClient ,char * name ,char * namespace , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = list_create();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/daemonsets/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/daemonsets/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams_namespace = strlen(name)+3 + strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



    // query parameters
    char *keyQuery_pretty;
    char * valueQuery_pretty;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }

    // query parameters
    char *keyQuery_dryRun;
    char * valueQuery_dryRun;
    keyValuePair_t *keyPairQuery_dryRun = 0;
    if (dryRun)
    {
        keyQuery_dryRun = strdup("dryRun");
        valueQuery_dryRun = strdup((dryRun));
        keyPairQuery_dryRun = keyValuePair_create(keyQuery_dryRun, valueQuery_dryRun);
        list_addElement(localVarQueryParameters,keyPairQuery_dryRun);
    }

    // query parameters
    char *keyQuery_fieldManager;
    char * valueQuery_fieldManager;
    keyValuePair_t *keyPairQuery_fieldManager = 0;
    if (fieldManager)
    {
        keyQuery_fieldManager = strdup("fieldManager");
        valueQuery_fieldManager = strdup((fieldManager));
        keyPairQuery_fieldManager = keyValuePair_create(keyQuery_fieldManager, valueQuery_fieldManager);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldManager);
    }

    // query parameters
    char *keyQuery_force;
    int valueQuery_force;
    keyValuePair_t *keyPairQuery_force = 0;
    if (force)
    {
        keyQuery_force = strdup("force");
        valueQuery_force = (force);
        keyPairQuery_force = keyValuePair_create(keyQuery_force, &valueQuery_force);
        list_addElement(localVarQueryParameters,keyPairQuery_force);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = object_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    list_addElement(localVarContentType,"application/json-patch+json"); //consumes
    list_addElement(localVarContentType,"application/merge-patch+json"); //consumes
    list_addElement(localVarContentType,"application/strategic-merge-patch+json"); //consumes
    list_addElement(localVarContentType,"application/apply-patch+yaml"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "PATCH");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not_ container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_daemon_set_t *elementToReturn = v1_daemon_set_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    list_free(localVarContentType);
    free(localVarPath);
    free(localVarToReplace_name);
    free(localVarToReplace_namespace);
    cJSON_Delete(localVarSingleItemJSON_body);
    free(localVarBodyParameters);
    free(keyQuery_pretty);
    free(valueQuery_pretty);
    keyValuePair_free(keyPairQuery_pretty);
    free(keyQuery_dryRun);
    free(valueQuery_dryRun);
    keyValuePair_free(keyPairQuery_dryRun);
    free(keyQuery_fieldManager);
    free(valueQuery_fieldManager);
    keyValuePair_free(keyPairQuery_fieldManager);
    free(keyQuery_force);
    keyValuePair_free(keyPairQuery_force);
    return elementToReturn;
end:
    return NULL;

}

// partially update status of the specified DaemonSet
//
v1_daemon_set_t*
AppsV1API_patchAppsV1NamespacedDaemonSetStatus(apiClient_t *apiClient ,char * name ,char * namespace , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = list_create();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/daemonsets/{name}/status")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/daemonsets/{name}/status");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams_namespace = strlen(name)+3 + strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



    // query parameters
    char *keyQuery_pretty;
    char * valueQuery_pretty;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }

    // query parameters
    char *keyQuery_dryRun;
    char * valueQuery_dryRun;
    keyValuePair_t *keyPairQuery_dryRun = 0;
    if (dryRun)
    {
        keyQuery_dryRun = strdup("dryRun");
        valueQuery_dryRun = strdup((dryRun));
        keyPairQuery_dryRun = keyValuePair_create(keyQuery_dryRun, valueQuery_dryRun);
        list_addElement(localVarQueryParameters,keyPairQuery_dryRun);
    }

    // query parameters
    char *keyQuery_fieldManager;
    char * valueQuery_fieldManager;
    keyValuePair_t *keyPairQuery_fieldManager = 0;
    if (fieldManager)
    {
        keyQuery_fieldManager = strdup("fieldManager");
        valueQuery_fieldManager = strdup((fieldManager));
        keyPairQuery_fieldManager = keyValuePair_create(keyQuery_fieldManager, valueQuery_fieldManager);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldManager);
    }

    // query parameters
    char *keyQuery_force;
    int valueQuery_force;
    keyValuePair_t *keyPairQuery_force = 0;
    if (force)
    {
        keyQuery_force = strdup("force");
        valueQuery_force = (force);
        keyPairQuery_force = keyValuePair_create(keyQuery_force, &valueQuery_force);
        list_addElement(localVarQueryParameters,keyPairQuery_force);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = object_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    list_addElement(localVarContentType,"application/json-patch+json"); //consumes
    list_addElement(localVarContentType,"application/merge-patch+json"); //consumes
    list_addElement(localVarContentType,"application/strategic-merge-patch+json"); //consumes
    list_addElement(localVarContentType,"application/apply-patch+yaml"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "PATCH");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not_ container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_daemon_set_t *elementToReturn = v1_daemon_set_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    list_free(localVarContentType);
    free(localVarPath);
    free(localVarToReplace_name);
    free(localVarToReplace_namespace);
    cJSON_Delete(localVarSingleItemJSON_body);
    free(localVarBodyParameters);
    free(keyQuery_pretty);
    free(valueQuery_pretty);
    keyValuePair_free(keyPairQuery_pretty);
    free(keyQuery_dryRun);
    free(valueQuery_dryRun);
    keyValuePair_free(keyPairQuery_dryRun);
    free(keyQuery_fieldManager);
    free(valueQuery_fieldManager);
    keyValuePair_free(keyPairQuery_fieldManager);
    free(keyQuery_force);
    keyValuePair_free(keyPairQuery_force);
    return elementToReturn;
end:
    return NULL;

}

// partially update the specified Deployment
//
v1_deployment_t*
AppsV1API_patchAppsV1NamespacedDeployment(apiClient_t *apiClient ,char * name ,char * namespace , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = list_create();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/deployments/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/deployments/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams_namespace = strlen(name)+3 + strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



    // query parameters
    char *keyQuery_pretty;
    char * valueQuery_pretty;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }

    // query parameters
    char *keyQuery_dryRun;
    char * valueQuery_dryRun;
    keyValuePair_t *keyPairQuery_dryRun = 0;
    if (dryRun)
    {
        keyQuery_dryRun = strdup("dryRun");
        valueQuery_dryRun = strdup((dryRun));
        keyPairQuery_dryRun = keyValuePair_create(keyQuery_dryRun, valueQuery_dryRun);
        list_addElement(localVarQueryParameters,keyPairQuery_dryRun);
    }

    // query parameters
    char *keyQuery_fieldManager;
    char * valueQuery_fieldManager;
    keyValuePair_t *keyPairQuery_fieldManager = 0;
    if (fieldManager)
    {
        keyQuery_fieldManager = strdup("fieldManager");
        valueQuery_fieldManager = strdup((fieldManager));
        keyPairQuery_fieldManager = keyValuePair_create(keyQuery_fieldManager, valueQuery_fieldManager);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldManager);
    }

    // query parameters
    char *keyQuery_force;
    int valueQuery_force;
    keyValuePair_t *keyPairQuery_force = 0;
    if (force)
    {
        keyQuery_force = strdup("force");
        valueQuery_force = (force);
        keyPairQuery_force = keyValuePair_create(keyQuery_force, &valueQuery_force);
        list_addElement(localVarQueryParameters,keyPairQuery_force);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = object_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    list_addElement(localVarContentType,"application/json-patch+json"); //consumes
    list_addElement(localVarContentType,"application/merge-patch+json"); //consumes
    list_addElement(localVarContentType,"application/strategic-merge-patch+json"); //consumes
    list_addElement(localVarContentType,"application/apply-patch+yaml"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "PATCH");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not_ container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_deployment_t *elementToReturn = v1_deployment_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    list_free(localVarContentType);
    free(localVarPath);
    free(localVarToReplace_name);
    free(localVarToReplace_namespace);
    cJSON_Delete(localVarSingleItemJSON_body);
    free(localVarBodyParameters);
    free(keyQuery_pretty);
    free(valueQuery_pretty);
    keyValuePair_free(keyPairQuery_pretty);
    free(keyQuery_dryRun);
    free(valueQuery_dryRun);
    keyValuePair_free(keyPairQuery_dryRun);
    free(keyQuery_fieldManager);
    free(valueQuery_fieldManager);
    keyValuePair_free(keyPairQuery_fieldManager);
    free(keyQuery_force);
    keyValuePair_free(keyPairQuery_force);
    return elementToReturn;
end:
    return NULL;

}

// partially update scale of the specified Deployment
//
v1_scale_t*
AppsV1API_patchAppsV1NamespacedDeploymentScale(apiClient_t *apiClient ,char * name ,char * namespace , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = list_create();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/deployments/{name}/scale")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/deployments/{name}/scale");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams_namespace = strlen(name)+3 + strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



    // query parameters
    char *keyQuery_pretty;
    char * valueQuery_pretty;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }

    // query parameters
    char *keyQuery_dryRun;
    char * valueQuery_dryRun;
    keyValuePair_t *keyPairQuery_dryRun = 0;
    if (dryRun)
    {
        keyQuery_dryRun = strdup("dryRun");
        valueQuery_dryRun = strdup((dryRun));
        keyPairQuery_dryRun = keyValuePair_create(keyQuery_dryRun, valueQuery_dryRun);
        list_addElement(localVarQueryParameters,keyPairQuery_dryRun);
    }

    // query parameters
    char *keyQuery_fieldManager;
    char * valueQuery_fieldManager;
    keyValuePair_t *keyPairQuery_fieldManager = 0;
    if (fieldManager)
    {
        keyQuery_fieldManager = strdup("fieldManager");
        valueQuery_fieldManager = strdup((fieldManager));
        keyPairQuery_fieldManager = keyValuePair_create(keyQuery_fieldManager, valueQuery_fieldManager);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldManager);
    }

    // query parameters
    char *keyQuery_force;
    int valueQuery_force;
    keyValuePair_t *keyPairQuery_force = 0;
    if (force)
    {
        keyQuery_force = strdup("force");
        valueQuery_force = (force);
        keyPairQuery_force = keyValuePair_create(keyQuery_force, &valueQuery_force);
        list_addElement(localVarQueryParameters,keyPairQuery_force);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = object_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    list_addElement(localVarContentType,"application/json-patch+json"); //consumes
    list_addElement(localVarContentType,"application/merge-patch+json"); //consumes
    list_addElement(localVarContentType,"application/strategic-merge-patch+json"); //consumes
    list_addElement(localVarContentType,"application/apply-patch+yaml"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "PATCH");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not_ container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_scale_t *elementToReturn = v1_scale_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    list_free(localVarContentType);
    free(localVarPath);
    free(localVarToReplace_name);
    free(localVarToReplace_namespace);
    cJSON_Delete(localVarSingleItemJSON_body);
    free(localVarBodyParameters);
    free(keyQuery_pretty);
    free(valueQuery_pretty);
    keyValuePair_free(keyPairQuery_pretty);
    free(keyQuery_dryRun);
    free(valueQuery_dryRun);
    keyValuePair_free(keyPairQuery_dryRun);
    free(keyQuery_fieldManager);
    free(valueQuery_fieldManager);
    keyValuePair_free(keyPairQuery_fieldManager);
    free(keyQuery_force);
    keyValuePair_free(keyPairQuery_force);
    return elementToReturn;
end:
    return NULL;

}

// partially update status of the specified Deployment
//
v1_deployment_t*
AppsV1API_patchAppsV1NamespacedDeploymentStatus(apiClient_t *apiClient ,char * name ,char * namespace , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = list_create();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/deployments/{name}/status")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/deployments/{name}/status");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams_namespace = strlen(name)+3 + strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



    // query parameters
    char *keyQuery_pretty;
    char * valueQuery_pretty;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }

    // query parameters
    char *keyQuery_dryRun;
    char * valueQuery_dryRun;
    keyValuePair_t *keyPairQuery_dryRun = 0;
    if (dryRun)
    {
        keyQuery_dryRun = strdup("dryRun");
        valueQuery_dryRun = strdup((dryRun));
        keyPairQuery_dryRun = keyValuePair_create(keyQuery_dryRun, valueQuery_dryRun);
        list_addElement(localVarQueryParameters,keyPairQuery_dryRun);
    }

    // query parameters
    char *keyQuery_fieldManager;
    char * valueQuery_fieldManager;
    keyValuePair_t *keyPairQuery_fieldManager = 0;
    if (fieldManager)
    {
        keyQuery_fieldManager = strdup("fieldManager");
        valueQuery_fieldManager = strdup((fieldManager));
        keyPairQuery_fieldManager = keyValuePair_create(keyQuery_fieldManager, valueQuery_fieldManager);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldManager);
    }

    // query parameters
    char *keyQuery_force;
    int valueQuery_force;
    keyValuePair_t *keyPairQuery_force = 0;
    if (force)
    {
        keyQuery_force = strdup("force");
        valueQuery_force = (force);
        keyPairQuery_force = keyValuePair_create(keyQuery_force, &valueQuery_force);
        list_addElement(localVarQueryParameters,keyPairQuery_force);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = object_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    list_addElement(localVarContentType,"application/json-patch+json"); //consumes
    list_addElement(localVarContentType,"application/merge-patch+json"); //consumes
    list_addElement(localVarContentType,"application/strategic-merge-patch+json"); //consumes
    list_addElement(localVarContentType,"application/apply-patch+yaml"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "PATCH");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not_ container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_deployment_t *elementToReturn = v1_deployment_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    list_free(localVarContentType);
    free(localVarPath);
    free(localVarToReplace_name);
    free(localVarToReplace_namespace);
    cJSON_Delete(localVarSingleItemJSON_body);
    free(localVarBodyParameters);
    free(keyQuery_pretty);
    free(valueQuery_pretty);
    keyValuePair_free(keyPairQuery_pretty);
    free(keyQuery_dryRun);
    free(valueQuery_dryRun);
    keyValuePair_free(keyPairQuery_dryRun);
    free(keyQuery_fieldManager);
    free(valueQuery_fieldManager);
    keyValuePair_free(keyPairQuery_fieldManager);
    free(keyQuery_force);
    keyValuePair_free(keyPairQuery_force);
    return elementToReturn;
end:
    return NULL;

}

// partially update the specified ReplicaSet
//
v1_replica_set_t*
AppsV1API_patchAppsV1NamespacedReplicaSet(apiClient_t *apiClient ,char * name ,char * namespace , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = list_create();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/replicasets/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/replicasets/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams_namespace = strlen(name)+3 + strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



    // query parameters
    char *keyQuery_pretty;
    char * valueQuery_pretty;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }

    // query parameters
    char *keyQuery_dryRun;
    char * valueQuery_dryRun;
    keyValuePair_t *keyPairQuery_dryRun = 0;
    if (dryRun)
    {
        keyQuery_dryRun = strdup("dryRun");
        valueQuery_dryRun = strdup((dryRun));
        keyPairQuery_dryRun = keyValuePair_create(keyQuery_dryRun, valueQuery_dryRun);
        list_addElement(localVarQueryParameters,keyPairQuery_dryRun);
    }

    // query parameters
    char *keyQuery_fieldManager;
    char * valueQuery_fieldManager;
    keyValuePair_t *keyPairQuery_fieldManager = 0;
    if (fieldManager)
    {
        keyQuery_fieldManager = strdup("fieldManager");
        valueQuery_fieldManager = strdup((fieldManager));
        keyPairQuery_fieldManager = keyValuePair_create(keyQuery_fieldManager, valueQuery_fieldManager);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldManager);
    }

    // query parameters
    char *keyQuery_force;
    int valueQuery_force;
    keyValuePair_t *keyPairQuery_force = 0;
    if (force)
    {
        keyQuery_force = strdup("force");
        valueQuery_force = (force);
        keyPairQuery_force = keyValuePair_create(keyQuery_force, &valueQuery_force);
        list_addElement(localVarQueryParameters,keyPairQuery_force);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = object_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    list_addElement(localVarContentType,"application/json-patch+json"); //consumes
    list_addElement(localVarContentType,"application/merge-patch+json"); //consumes
    list_addElement(localVarContentType,"application/strategic-merge-patch+json"); //consumes
    list_addElement(localVarContentType,"application/apply-patch+yaml"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "PATCH");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not_ container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_replica_set_t *elementToReturn = v1_replica_set_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    list_free(localVarContentType);
    free(localVarPath);
    free(localVarToReplace_name);
    free(localVarToReplace_namespace);
    cJSON_Delete(localVarSingleItemJSON_body);
    free(localVarBodyParameters);
    free(keyQuery_pretty);
    free(valueQuery_pretty);
    keyValuePair_free(keyPairQuery_pretty);
    free(keyQuery_dryRun);
    free(valueQuery_dryRun);
    keyValuePair_free(keyPairQuery_dryRun);
    free(keyQuery_fieldManager);
    free(valueQuery_fieldManager);
    keyValuePair_free(keyPairQuery_fieldManager);
    free(keyQuery_force);
    keyValuePair_free(keyPairQuery_force);
    return elementToReturn;
end:
    return NULL;

}

// partially update scale of the specified ReplicaSet
//
v1_scale_t*
AppsV1API_patchAppsV1NamespacedReplicaSetScale(apiClient_t *apiClient ,char * name ,char * namespace , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = list_create();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/replicasets/{name}/scale")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/replicasets/{name}/scale");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams_namespace = strlen(name)+3 + strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



    // query parameters
    char *keyQuery_pretty;
    char * valueQuery_pretty;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }

    // query parameters
    char *keyQuery_dryRun;
    char * valueQuery_dryRun;
    keyValuePair_t *keyPairQuery_dryRun = 0;
    if (dryRun)
    {
        keyQuery_dryRun = strdup("dryRun");
        valueQuery_dryRun = strdup((dryRun));
        keyPairQuery_dryRun = keyValuePair_create(keyQuery_dryRun, valueQuery_dryRun);
        list_addElement(localVarQueryParameters,keyPairQuery_dryRun);
    }

    // query parameters
    char *keyQuery_fieldManager;
    char * valueQuery_fieldManager;
    keyValuePair_t *keyPairQuery_fieldManager = 0;
    if (fieldManager)
    {
        keyQuery_fieldManager = strdup("fieldManager");
        valueQuery_fieldManager = strdup((fieldManager));
        keyPairQuery_fieldManager = keyValuePair_create(keyQuery_fieldManager, valueQuery_fieldManager);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldManager);
    }

    // query parameters
    char *keyQuery_force;
    int valueQuery_force;
    keyValuePair_t *keyPairQuery_force = 0;
    if (force)
    {
        keyQuery_force = strdup("force");
        valueQuery_force = (force);
        keyPairQuery_force = keyValuePair_create(keyQuery_force, &valueQuery_force);
        list_addElement(localVarQueryParameters,keyPairQuery_force);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = object_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    list_addElement(localVarContentType,"application/json-patch+json"); //consumes
    list_addElement(localVarContentType,"application/merge-patch+json"); //consumes
    list_addElement(localVarContentType,"application/strategic-merge-patch+json"); //consumes
    list_addElement(localVarContentType,"application/apply-patch+yaml"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "PATCH");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not_ container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_scale_t *elementToReturn = v1_scale_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    list_free(localVarContentType);
    free(localVarPath);
    free(localVarToReplace_name);
    free(localVarToReplace_namespace);
    cJSON_Delete(localVarSingleItemJSON_body);
    free(localVarBodyParameters);
    free(keyQuery_pretty);
    free(valueQuery_pretty);
    keyValuePair_free(keyPairQuery_pretty);
    free(keyQuery_dryRun);
    free(valueQuery_dryRun);
    keyValuePair_free(keyPairQuery_dryRun);
    free(keyQuery_fieldManager);
    free(valueQuery_fieldManager);
    keyValuePair_free(keyPairQuery_fieldManager);
    free(keyQuery_force);
    keyValuePair_free(keyPairQuery_force);
    return elementToReturn;
end:
    return NULL;

}

// partially update status of the specified ReplicaSet
//
v1_replica_set_t*
AppsV1API_patchAppsV1NamespacedReplicaSetStatus(apiClient_t *apiClient ,char * name ,char * namespace , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = list_create();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/replicasets/{name}/status")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/replicasets/{name}/status");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams_namespace = strlen(name)+3 + strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



    // query parameters
    char *keyQuery_pretty;
    char * valueQuery_pretty;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }

    // query parameters
    char *keyQuery_dryRun;
    char * valueQuery_dryRun;
    keyValuePair_t *keyPairQuery_dryRun = 0;
    if (dryRun)
    {
        keyQuery_dryRun = strdup("dryRun");
        valueQuery_dryRun = strdup((dryRun));
        keyPairQuery_dryRun = keyValuePair_create(keyQuery_dryRun, valueQuery_dryRun);
        list_addElement(localVarQueryParameters,keyPairQuery_dryRun);
    }

    // query parameters
    char *keyQuery_fieldManager;
    char * valueQuery_fieldManager;
    keyValuePair_t *keyPairQuery_fieldManager = 0;
    if (fieldManager)
    {
        keyQuery_fieldManager = strdup("fieldManager");
        valueQuery_fieldManager = strdup((fieldManager));
        keyPairQuery_fieldManager = keyValuePair_create(keyQuery_fieldManager, valueQuery_fieldManager);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldManager);
    }

    // query parameters
    char *keyQuery_force;
    int valueQuery_force;
    keyValuePair_t *keyPairQuery_force = 0;
    if (force)
    {
        keyQuery_force = strdup("force");
        valueQuery_force = (force);
        keyPairQuery_force = keyValuePair_create(keyQuery_force, &valueQuery_force);
        list_addElement(localVarQueryParameters,keyPairQuery_force);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = object_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    list_addElement(localVarContentType,"application/json-patch+json"); //consumes
    list_addElement(localVarContentType,"application/merge-patch+json"); //consumes
    list_addElement(localVarContentType,"application/strategic-merge-patch+json"); //consumes
    list_addElement(localVarContentType,"application/apply-patch+yaml"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "PATCH");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not_ container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_replica_set_t *elementToReturn = v1_replica_set_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    list_free(localVarContentType);
    free(localVarPath);
    free(localVarToReplace_name);
    free(localVarToReplace_namespace);
    cJSON_Delete(localVarSingleItemJSON_body);
    free(localVarBodyParameters);
    free(keyQuery_pretty);
    free(valueQuery_pretty);
    keyValuePair_free(keyPairQuery_pretty);
    free(keyQuery_dryRun);
    free(valueQuery_dryRun);
    keyValuePair_free(keyPairQuery_dryRun);
    free(keyQuery_fieldManager);
    free(valueQuery_fieldManager);
    keyValuePair_free(keyPairQuery_fieldManager);
    free(keyQuery_force);
    keyValuePair_free(keyPairQuery_force);
    return elementToReturn;
end:
    return NULL;

}

// partially update the specified StatefulSet
//
v1_stateful_set_t*
AppsV1API_patchAppsV1NamespacedStatefulSet(apiClient_t *apiClient ,char * name ,char * namespace , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = list_create();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/statefulsets/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/statefulsets/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams_namespace = strlen(name)+3 + strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



    // query parameters
    char *keyQuery_pretty;
    char * valueQuery_pretty;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }

    // query parameters
    char *keyQuery_dryRun;
    char * valueQuery_dryRun;
    keyValuePair_t *keyPairQuery_dryRun = 0;
    if (dryRun)
    {
        keyQuery_dryRun = strdup("dryRun");
        valueQuery_dryRun = strdup((dryRun));
        keyPairQuery_dryRun = keyValuePair_create(keyQuery_dryRun, valueQuery_dryRun);
        list_addElement(localVarQueryParameters,keyPairQuery_dryRun);
    }

    // query parameters
    char *keyQuery_fieldManager;
    char * valueQuery_fieldManager;
    keyValuePair_t *keyPairQuery_fieldManager = 0;
    if (fieldManager)
    {
        keyQuery_fieldManager = strdup("fieldManager");
        valueQuery_fieldManager = strdup((fieldManager));
        keyPairQuery_fieldManager = keyValuePair_create(keyQuery_fieldManager, valueQuery_fieldManager);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldManager);
    }

    // query parameters
    char *keyQuery_force;
    int valueQuery_force;
    keyValuePair_t *keyPairQuery_force = 0;
    if (force)
    {
        keyQuery_force = strdup("force");
        valueQuery_force = (force);
        keyPairQuery_force = keyValuePair_create(keyQuery_force, &valueQuery_force);
        list_addElement(localVarQueryParameters,keyPairQuery_force);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = object_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    list_addElement(localVarContentType,"application/json-patch+json"); //consumes
    list_addElement(localVarContentType,"application/merge-patch+json"); //consumes
    list_addElement(localVarContentType,"application/strategic-merge-patch+json"); //consumes
    list_addElement(localVarContentType,"application/apply-patch+yaml"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "PATCH");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not_ container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_stateful_set_t *elementToReturn = v1_stateful_set_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    list_free(localVarContentType);
    free(localVarPath);
    free(localVarToReplace_name);
    free(localVarToReplace_namespace);
    cJSON_Delete(localVarSingleItemJSON_body);
    free(localVarBodyParameters);
    free(keyQuery_pretty);
    free(valueQuery_pretty);
    keyValuePair_free(keyPairQuery_pretty);
    free(keyQuery_dryRun);
    free(valueQuery_dryRun);
    keyValuePair_free(keyPairQuery_dryRun);
    free(keyQuery_fieldManager);
    free(valueQuery_fieldManager);
    keyValuePair_free(keyPairQuery_fieldManager);
    free(keyQuery_force);
    keyValuePair_free(keyPairQuery_force);
    return elementToReturn;
end:
    return NULL;

}

// partially update scale of the specified StatefulSet
//
v1_scale_t*
AppsV1API_patchAppsV1NamespacedStatefulSetScale(apiClient_t *apiClient ,char * name ,char * namespace , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = list_create();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/statefulsets/{name}/scale")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/statefulsets/{name}/scale");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams_namespace = strlen(name)+3 + strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



    // query parameters
    char *keyQuery_pretty;
    char * valueQuery_pretty;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }

    // query parameters
    char *keyQuery_dryRun;
    char * valueQuery_dryRun;
    keyValuePair_t *keyPairQuery_dryRun = 0;
    if (dryRun)
    {
        keyQuery_dryRun = strdup("dryRun");
        valueQuery_dryRun = strdup((dryRun));
        keyPairQuery_dryRun = keyValuePair_create(keyQuery_dryRun, valueQuery_dryRun);
        list_addElement(localVarQueryParameters,keyPairQuery_dryRun);
    }

    // query parameters
    char *keyQuery_fieldManager;
    char * valueQuery_fieldManager;
    keyValuePair_t *keyPairQuery_fieldManager = 0;
    if (fieldManager)
    {
        keyQuery_fieldManager = strdup("fieldManager");
        valueQuery_fieldManager = strdup((fieldManager));
        keyPairQuery_fieldManager = keyValuePair_create(keyQuery_fieldManager, valueQuery_fieldManager);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldManager);
    }

    // query parameters
    char *keyQuery_force;
    int valueQuery_force;
    keyValuePair_t *keyPairQuery_force = 0;
    if (force)
    {
        keyQuery_force = strdup("force");
        valueQuery_force = (force);
        keyPairQuery_force = keyValuePair_create(keyQuery_force, &valueQuery_force);
        list_addElement(localVarQueryParameters,keyPairQuery_force);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = object_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    list_addElement(localVarContentType,"application/json-patch+json"); //consumes
    list_addElement(localVarContentType,"application/merge-patch+json"); //consumes
    list_addElement(localVarContentType,"application/strategic-merge-patch+json"); //consumes
    list_addElement(localVarContentType,"application/apply-patch+yaml"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "PATCH");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not_ container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_scale_t *elementToReturn = v1_scale_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    list_free(localVarContentType);
    free(localVarPath);
    free(localVarToReplace_name);
    free(localVarToReplace_namespace);
    cJSON_Delete(localVarSingleItemJSON_body);
    free(localVarBodyParameters);
    free(keyQuery_pretty);
    free(valueQuery_pretty);
    keyValuePair_free(keyPairQuery_pretty);
    free(keyQuery_dryRun);
    free(valueQuery_dryRun);
    keyValuePair_free(keyPairQuery_dryRun);
    free(keyQuery_fieldManager);
    free(valueQuery_fieldManager);
    keyValuePair_free(keyPairQuery_fieldManager);
    free(keyQuery_force);
    keyValuePair_free(keyPairQuery_force);
    return elementToReturn;
end:
    return NULL;

}

// partially update status of the specified StatefulSet
//
v1_stateful_set_t*
AppsV1API_patchAppsV1NamespacedStatefulSetStatus(apiClient_t *apiClient ,char * name ,char * namespace , object_t * body ,char * pretty ,char * dryRun ,char * fieldManager ,int force)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = list_create();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/statefulsets/{name}/status")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/statefulsets/{name}/status");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams_namespace = strlen(name)+3 + strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



    // query parameters
    char *keyQuery_pretty;
    char * valueQuery_pretty;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }

    // query parameters
    char *keyQuery_dryRun;
    char * valueQuery_dryRun;
    keyValuePair_t *keyPairQuery_dryRun = 0;
    if (dryRun)
    {
        keyQuery_dryRun = strdup("dryRun");
        valueQuery_dryRun = strdup((dryRun));
        keyPairQuery_dryRun = keyValuePair_create(keyQuery_dryRun, valueQuery_dryRun);
        list_addElement(localVarQueryParameters,keyPairQuery_dryRun);
    }

    // query parameters
    char *keyQuery_fieldManager;
    char * valueQuery_fieldManager;
    keyValuePair_t *keyPairQuery_fieldManager = 0;
    if (fieldManager)
    {
        keyQuery_fieldManager = strdup("fieldManager");
        valueQuery_fieldManager = strdup((fieldManager));
        keyPairQuery_fieldManager = keyValuePair_create(keyQuery_fieldManager, valueQuery_fieldManager);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldManager);
    }

    // query parameters
    char *keyQuery_force;
    int valueQuery_force;
    keyValuePair_t *keyPairQuery_force = 0;
    if (force)
    {
        keyQuery_force = strdup("force");
        valueQuery_force = (force);
        keyPairQuery_force = keyValuePair_create(keyQuery_force, &valueQuery_force);
        list_addElement(localVarQueryParameters,keyPairQuery_force);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = object_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    list_addElement(localVarContentType,"application/json-patch+json"); //consumes
    list_addElement(localVarContentType,"application/merge-patch+json"); //consumes
    list_addElement(localVarContentType,"application/strategic-merge-patch+json"); //consumes
    list_addElement(localVarContentType,"application/apply-patch+yaml"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "PATCH");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not_ container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_stateful_set_t *elementToReturn = v1_stateful_set_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    list_free(localVarContentType);
    free(localVarPath);
    free(localVarToReplace_name);
    free(localVarToReplace_namespace);
    cJSON_Delete(localVarSingleItemJSON_body);
    free(localVarBodyParameters);
    free(keyQuery_pretty);
    free(valueQuery_pretty);
    keyValuePair_free(keyPairQuery_pretty);
    free(keyQuery_dryRun);
    free(valueQuery_dryRun);
    keyValuePair_free(keyPairQuery_dryRun);
    free(keyQuery_fieldManager);
    free(valueQuery_fieldManager);
    keyValuePair_free(keyPairQuery_fieldManager);
    free(keyQuery_force);
    keyValuePair_free(keyPairQuery_force);
    return elementToReturn;
end:
    return NULL;

}

// read the specified ControllerRevision
//
v1_controller_revision_t*
AppsV1API_readAppsV1NamespacedControllerRevision(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,int exact ,int export)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/controllerrevisions/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/controllerrevisions/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams_namespace = strlen(name)+3 + strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



    // query parameters
    char *keyQuery_pretty;
    char * valueQuery_pretty;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }

    // query parameters
    char *keyQuery_exact;
    int valueQuery_exact;
    keyValuePair_t *keyPairQuery_exact = 0;
    if (exact)
    {
        keyQuery_exact = strdup("exact");
        valueQuery_exact = (exact);
        keyPairQuery_exact = keyValuePair_create(keyQuery_exact, &valueQuery_exact);
        list_addElement(localVarQueryParameters,keyPairQuery_exact);
    }

    // query parameters
    char *keyQuery_export;
    int valueQuery_export;
    keyValuePair_t *keyPairQuery_export = 0;
    if (export)
    {
        keyQuery_export = strdup("export");
        valueQuery_export = (export);
        keyPairQuery_export = keyValuePair_create(keyQuery_export, &valueQuery_export);
        list_addElement(localVarQueryParameters,keyPairQuery_export);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not_ container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_controller_revision_t *elementToReturn = v1_controller_revision_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_name);
    free(localVarToReplace_namespace);
    free(keyQuery_pretty);
    free(valueQuery_pretty);
    keyValuePair_free(keyPairQuery_pretty);
    free(keyQuery_exact);
    keyValuePair_free(keyPairQuery_exact);
    free(keyQuery_export);
    keyValuePair_free(keyPairQuery_export);
    return elementToReturn;
end:
    return NULL;

}

// read the specified DaemonSet
//
v1_daemon_set_t*
AppsV1API_readAppsV1NamespacedDaemonSet(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,int exact ,int export)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/daemonsets/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/daemonsets/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams_namespace = strlen(name)+3 + strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



    // query parameters
    char *keyQuery_pretty;
    char * valueQuery_pretty;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }

    // query parameters
    char *keyQuery_exact;
    int valueQuery_exact;
    keyValuePair_t *keyPairQuery_exact = 0;
    if (exact)
    {
        keyQuery_exact = strdup("exact");
        valueQuery_exact = (exact);
        keyPairQuery_exact = keyValuePair_create(keyQuery_exact, &valueQuery_exact);
        list_addElement(localVarQueryParameters,keyPairQuery_exact);
    }

    // query parameters
    char *keyQuery_export;
    int valueQuery_export;
    keyValuePair_t *keyPairQuery_export = 0;
    if (export)
    {
        keyQuery_export = strdup("export");
        valueQuery_export = (export);
        keyPairQuery_export = keyValuePair_create(keyQuery_export, &valueQuery_export);
        list_addElement(localVarQueryParameters,keyPairQuery_export);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not_ container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_daemon_set_t *elementToReturn = v1_daemon_set_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_name);
    free(localVarToReplace_namespace);
    free(keyQuery_pretty);
    free(valueQuery_pretty);
    keyValuePair_free(keyPairQuery_pretty);
    free(keyQuery_exact);
    keyValuePair_free(keyPairQuery_exact);
    free(keyQuery_export);
    keyValuePair_free(keyPairQuery_export);
    return elementToReturn;
end:
    return NULL;

}

// read status of the specified DaemonSet
//
v1_daemon_set_t*
AppsV1API_readAppsV1NamespacedDaemonSetStatus(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/daemonsets/{name}/status")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/daemonsets/{name}/status");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams_namespace = strlen(name)+3 + strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



    // query parameters
    char *keyQuery_pretty;
    char * valueQuery_pretty;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not_ container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_daemon_set_t *elementToReturn = v1_daemon_set_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_name);
    free(localVarToReplace_namespace);
    free(keyQuery_pretty);
    free(valueQuery_pretty);
    keyValuePair_free(keyPairQuery_pretty);
    return elementToReturn;
end:
    return NULL;

}

// read the specified Deployment
//
v1_deployment_t*
AppsV1API_readAppsV1NamespacedDeployment(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,int exact ,int export)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/deployments/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/deployments/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams_namespace = strlen(name)+3 + strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



    // query parameters
    char *keyQuery_pretty;
    char * valueQuery_pretty;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }

    // query parameters
    char *keyQuery_exact;
    int valueQuery_exact;
    keyValuePair_t *keyPairQuery_exact = 0;
    if (exact)
    {
        keyQuery_exact = strdup("exact");
        valueQuery_exact = (exact);
        keyPairQuery_exact = keyValuePair_create(keyQuery_exact, &valueQuery_exact);
        list_addElement(localVarQueryParameters,keyPairQuery_exact);
    }

    // query parameters
    char *keyQuery_export;
    int valueQuery_export;
    keyValuePair_t *keyPairQuery_export = 0;
    if (export)
    {
        keyQuery_export = strdup("export");
        valueQuery_export = (export);
        keyPairQuery_export = keyValuePair_create(keyQuery_export, &valueQuery_export);
        list_addElement(localVarQueryParameters,keyPairQuery_export);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not_ container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_deployment_t *elementToReturn = v1_deployment_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_name);
    free(localVarToReplace_namespace);
    free(keyQuery_pretty);
    free(valueQuery_pretty);
    keyValuePair_free(keyPairQuery_pretty);
    free(keyQuery_exact);
    keyValuePair_free(keyPairQuery_exact);
    free(keyQuery_export);
    keyValuePair_free(keyPairQuery_export);
    return elementToReturn;
end:
    return NULL;

}

// read scale of the specified Deployment
//
v1_scale_t*
AppsV1API_readAppsV1NamespacedDeploymentScale(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/deployments/{name}/scale")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/deployments/{name}/scale");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams_namespace = strlen(name)+3 + strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



    // query parameters
    char *keyQuery_pretty;
    char * valueQuery_pretty;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not_ container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_scale_t *elementToReturn = v1_scale_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_name);
    free(localVarToReplace_namespace);
    free(keyQuery_pretty);
    free(valueQuery_pretty);
    keyValuePair_free(keyPairQuery_pretty);
    return elementToReturn;
end:
    return NULL;

}

// read status of the specified Deployment
//
v1_deployment_t*
AppsV1API_readAppsV1NamespacedDeploymentStatus(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/deployments/{name}/status")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/deployments/{name}/status");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams_namespace = strlen(name)+3 + strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



    // query parameters
    char *keyQuery_pretty;
    char * valueQuery_pretty;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not_ container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_deployment_t *elementToReturn = v1_deployment_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_name);
    free(localVarToReplace_namespace);
    free(keyQuery_pretty);
    free(valueQuery_pretty);
    keyValuePair_free(keyPairQuery_pretty);
    return elementToReturn;
end:
    return NULL;

}

// read the specified ReplicaSet
//
v1_replica_set_t*
AppsV1API_readAppsV1NamespacedReplicaSet(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,int exact ,int export)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/replicasets/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/replicasets/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams_namespace = strlen(name)+3 + strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



    // query parameters
    char *keyQuery_pretty;
    char * valueQuery_pretty;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }

    // query parameters
    char *keyQuery_exact;
    int valueQuery_exact;
    keyValuePair_t *keyPairQuery_exact = 0;
    if (exact)
    {
        keyQuery_exact = strdup("exact");
        valueQuery_exact = (exact);
        keyPairQuery_exact = keyValuePair_create(keyQuery_exact, &valueQuery_exact);
        list_addElement(localVarQueryParameters,keyPairQuery_exact);
    }

    // query parameters
    char *keyQuery_export;
    int valueQuery_export;
    keyValuePair_t *keyPairQuery_export = 0;
    if (export)
    {
        keyQuery_export = strdup("export");
        valueQuery_export = (export);
        keyPairQuery_export = keyValuePair_create(keyQuery_export, &valueQuery_export);
        list_addElement(localVarQueryParameters,keyPairQuery_export);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not_ container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_replica_set_t *elementToReturn = v1_replica_set_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_name);
    free(localVarToReplace_namespace);
    free(keyQuery_pretty);
    free(valueQuery_pretty);
    keyValuePair_free(keyPairQuery_pretty);
    free(keyQuery_exact);
    keyValuePair_free(keyPairQuery_exact);
    free(keyQuery_export);
    keyValuePair_free(keyPairQuery_export);
    return elementToReturn;
end:
    return NULL;

}

// read scale of the specified ReplicaSet
//
v1_scale_t*
AppsV1API_readAppsV1NamespacedReplicaSetScale(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/replicasets/{name}/scale")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/replicasets/{name}/scale");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams_namespace = strlen(name)+3 + strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



    // query parameters
    char *keyQuery_pretty;
    char * valueQuery_pretty;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not_ container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_scale_t *elementToReturn = v1_scale_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_name);
    free(localVarToReplace_namespace);
    free(keyQuery_pretty);
    free(valueQuery_pretty);
    keyValuePair_free(keyPairQuery_pretty);
    return elementToReturn;
end:
    return NULL;

}

// read status of the specified ReplicaSet
//
v1_replica_set_t*
AppsV1API_readAppsV1NamespacedReplicaSetStatus(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/replicasets/{name}/status")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/replicasets/{name}/status");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams_namespace = strlen(name)+3 + strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



    // query parameters
    char *keyQuery_pretty;
    char * valueQuery_pretty;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not_ container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_replica_set_t *elementToReturn = v1_replica_set_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_name);
    free(localVarToReplace_namespace);
    free(keyQuery_pretty);
    free(valueQuery_pretty);
    keyValuePair_free(keyPairQuery_pretty);
    return elementToReturn;
end:
    return NULL;

}

// read the specified StatefulSet
//
v1_stateful_set_t*
AppsV1API_readAppsV1NamespacedStatefulSet(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,int exact ,int export)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/statefulsets/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/statefulsets/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams_namespace = strlen(name)+3 + strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



    // query parameters
    char *keyQuery_pretty;
    char * valueQuery_pretty;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }

    // query parameters
    char *keyQuery_exact;
    int valueQuery_exact;
    keyValuePair_t *keyPairQuery_exact = 0;
    if (exact)
    {
        keyQuery_exact = strdup("exact");
        valueQuery_exact = (exact);
        keyPairQuery_exact = keyValuePair_create(keyQuery_exact, &valueQuery_exact);
        list_addElement(localVarQueryParameters,keyPairQuery_exact);
    }

    // query parameters
    char *keyQuery_export;
    int valueQuery_export;
    keyValuePair_t *keyPairQuery_export = 0;
    if (export)
    {
        keyQuery_export = strdup("export");
        valueQuery_export = (export);
        keyPairQuery_export = keyValuePair_create(keyQuery_export, &valueQuery_export);
        list_addElement(localVarQueryParameters,keyPairQuery_export);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not_ container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_stateful_set_t *elementToReturn = v1_stateful_set_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_name);
    free(localVarToReplace_namespace);
    free(keyQuery_pretty);
    free(valueQuery_pretty);
    keyValuePair_free(keyPairQuery_pretty);
    free(keyQuery_exact);
    keyValuePair_free(keyPairQuery_exact);
    free(keyQuery_export);
    keyValuePair_free(keyPairQuery_export);
    return elementToReturn;
end:
    return NULL;

}

// read scale of the specified StatefulSet
//
v1_scale_t*
AppsV1API_readAppsV1NamespacedStatefulSetScale(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/statefulsets/{name}/scale")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/statefulsets/{name}/scale");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams_namespace = strlen(name)+3 + strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



    // query parameters
    char *keyQuery_pretty;
    char * valueQuery_pretty;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not_ container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_scale_t *elementToReturn = v1_scale_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_name);
    free(localVarToReplace_namespace);
    free(keyQuery_pretty);
    free(valueQuery_pretty);
    keyValuePair_free(keyPairQuery_pretty);
    return elementToReturn;
end:
    return NULL;

}

// read status of the specified StatefulSet
//
v1_stateful_set_t*
AppsV1API_readAppsV1NamespacedStatefulSetStatus(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/statefulsets/{name}/status")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/statefulsets/{name}/status");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams_namespace = strlen(name)+3 + strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



    // query parameters
    char *keyQuery_pretty;
    char * valueQuery_pretty;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not_ container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_stateful_set_t *elementToReturn = v1_stateful_set_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_name);
    free(localVarToReplace_namespace);
    free(keyQuery_pretty);
    free(valueQuery_pretty);
    keyValuePair_free(keyPairQuery_pretty);
    return elementToReturn;
end:
    return NULL;

}

// replace the specified ControllerRevision
//
v1_controller_revision_t*
AppsV1API_replaceAppsV1NamespacedControllerRevision(apiClient_t *apiClient ,char * name ,char * namespace ,v1_controller_revision_t * body ,char * pretty ,char * dryRun ,char * fieldManager)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/controllerrevisions/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/controllerrevisions/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams_namespace = strlen(name)+3 + strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



    // query parameters
    char *keyQuery_pretty;
    char * valueQuery_pretty;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }

    // query parameters
    char *keyQuery_dryRun;
    char * valueQuery_dryRun;
    keyValuePair_t *keyPairQuery_dryRun = 0;
    if (dryRun)
    {
        keyQuery_dryRun = strdup("dryRun");
        valueQuery_dryRun = strdup((dryRun));
        keyPairQuery_dryRun = keyValuePair_create(keyQuery_dryRun, valueQuery_dryRun);
        list_addElement(localVarQueryParameters,keyPairQuery_dryRun);
    }

    // query parameters
    char *keyQuery_fieldManager;
    char * valueQuery_fieldManager;
    keyValuePair_t *keyPairQuery_fieldManager = 0;
    if (fieldManager)
    {
        keyQuery_fieldManager = strdup("fieldManager");
        valueQuery_fieldManager = strdup((fieldManager));
        keyPairQuery_fieldManager = keyValuePair_create(keyQuery_fieldManager, valueQuery_fieldManager);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldManager);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = v1_controller_revision_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "PUT");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 201) {
        printf("%s\n","Created");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not_ container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_controller_revision_t *elementToReturn = v1_controller_revision_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_name);
    free(localVarToReplace_namespace);
    cJSON_Delete(localVarSingleItemJSON_body);
    free(localVarBodyParameters);
    free(keyQuery_pretty);
    free(valueQuery_pretty);
    keyValuePair_free(keyPairQuery_pretty);
    free(keyQuery_dryRun);
    free(valueQuery_dryRun);
    keyValuePair_free(keyPairQuery_dryRun);
    free(keyQuery_fieldManager);
    free(valueQuery_fieldManager);
    keyValuePair_free(keyPairQuery_fieldManager);
    return elementToReturn;
end:
    return NULL;

}

// replace the specified DaemonSet
//
v1_daemon_set_t*
AppsV1API_replaceAppsV1NamespacedDaemonSet(apiClient_t *apiClient ,char * name ,char * namespace ,v1_daemon_set_t * body ,char * pretty ,char * dryRun ,char * fieldManager)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/daemonsets/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/daemonsets/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams_namespace = strlen(name)+3 + strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



    // query parameters
    char *keyQuery_pretty;
    char * valueQuery_pretty;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }

    // query parameters
    char *keyQuery_dryRun;
    char * valueQuery_dryRun;
    keyValuePair_t *keyPairQuery_dryRun = 0;
    if (dryRun)
    {
        keyQuery_dryRun = strdup("dryRun");
        valueQuery_dryRun = strdup((dryRun));
        keyPairQuery_dryRun = keyValuePair_create(keyQuery_dryRun, valueQuery_dryRun);
        list_addElement(localVarQueryParameters,keyPairQuery_dryRun);
    }

    // query parameters
    char *keyQuery_fieldManager;
    char * valueQuery_fieldManager;
    keyValuePair_t *keyPairQuery_fieldManager = 0;
    if (fieldManager)
    {
        keyQuery_fieldManager = strdup("fieldManager");
        valueQuery_fieldManager = strdup((fieldManager));
        keyPairQuery_fieldManager = keyValuePair_create(keyQuery_fieldManager, valueQuery_fieldManager);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldManager);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = v1_daemon_set_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "PUT");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 201) {
        printf("%s\n","Created");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not_ container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_daemon_set_t *elementToReturn = v1_daemon_set_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_name);
    free(localVarToReplace_namespace);
    cJSON_Delete(localVarSingleItemJSON_body);
    free(localVarBodyParameters);
    free(keyQuery_pretty);
    free(valueQuery_pretty);
    keyValuePair_free(keyPairQuery_pretty);
    free(keyQuery_dryRun);
    free(valueQuery_dryRun);
    keyValuePair_free(keyPairQuery_dryRun);
    free(keyQuery_fieldManager);
    free(valueQuery_fieldManager);
    keyValuePair_free(keyPairQuery_fieldManager);
    return elementToReturn;
end:
    return NULL;

}

// replace status of the specified DaemonSet
//
v1_daemon_set_t*
AppsV1API_replaceAppsV1NamespacedDaemonSetStatus(apiClient_t *apiClient ,char * name ,char * namespace ,v1_daemon_set_t * body ,char * pretty ,char * dryRun ,char * fieldManager)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/daemonsets/{name}/status")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/daemonsets/{name}/status");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams_namespace = strlen(name)+3 + strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



    // query parameters
    char *keyQuery_pretty;
    char * valueQuery_pretty;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }

    // query parameters
    char *keyQuery_dryRun;
    char * valueQuery_dryRun;
    keyValuePair_t *keyPairQuery_dryRun = 0;
    if (dryRun)
    {
        keyQuery_dryRun = strdup("dryRun");
        valueQuery_dryRun = strdup((dryRun));
        keyPairQuery_dryRun = keyValuePair_create(keyQuery_dryRun, valueQuery_dryRun);
        list_addElement(localVarQueryParameters,keyPairQuery_dryRun);
    }

    // query parameters
    char *keyQuery_fieldManager;
    char * valueQuery_fieldManager;
    keyValuePair_t *keyPairQuery_fieldManager = 0;
    if (fieldManager)
    {
        keyQuery_fieldManager = strdup("fieldManager");
        valueQuery_fieldManager = strdup((fieldManager));
        keyPairQuery_fieldManager = keyValuePair_create(keyQuery_fieldManager, valueQuery_fieldManager);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldManager);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = v1_daemon_set_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "PUT");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 201) {
        printf("%s\n","Created");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not_ container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_daemon_set_t *elementToReturn = v1_daemon_set_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_name);
    free(localVarToReplace_namespace);
    cJSON_Delete(localVarSingleItemJSON_body);
    free(localVarBodyParameters);
    free(keyQuery_pretty);
    free(valueQuery_pretty);
    keyValuePair_free(keyPairQuery_pretty);
    free(keyQuery_dryRun);
    free(valueQuery_dryRun);
    keyValuePair_free(keyPairQuery_dryRun);
    free(keyQuery_fieldManager);
    free(valueQuery_fieldManager);
    keyValuePair_free(keyPairQuery_fieldManager);
    return elementToReturn;
end:
    return NULL;

}

// replace the specified Deployment
//
v1_deployment_t*
AppsV1API_replaceAppsV1NamespacedDeployment(apiClient_t *apiClient ,char * name ,char * namespace ,v1_deployment_t * body ,char * pretty ,char * dryRun ,char * fieldManager)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/deployments/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/deployments/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams_namespace = strlen(name)+3 + strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



    // query parameters
    char *keyQuery_pretty;
    char * valueQuery_pretty;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }

    // query parameters
    char *keyQuery_dryRun;
    char * valueQuery_dryRun;
    keyValuePair_t *keyPairQuery_dryRun = 0;
    if (dryRun)
    {
        keyQuery_dryRun = strdup("dryRun");
        valueQuery_dryRun = strdup((dryRun));
        keyPairQuery_dryRun = keyValuePair_create(keyQuery_dryRun, valueQuery_dryRun);
        list_addElement(localVarQueryParameters,keyPairQuery_dryRun);
    }

    // query parameters
    char *keyQuery_fieldManager;
    char * valueQuery_fieldManager;
    keyValuePair_t *keyPairQuery_fieldManager = 0;
    if (fieldManager)
    {
        keyQuery_fieldManager = strdup("fieldManager");
        valueQuery_fieldManager = strdup((fieldManager));
        keyPairQuery_fieldManager = keyValuePair_create(keyQuery_fieldManager, valueQuery_fieldManager);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldManager);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = v1_deployment_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "PUT");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 201) {
        printf("%s\n","Created");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not_ container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_deployment_t *elementToReturn = v1_deployment_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_name);
    free(localVarToReplace_namespace);
    cJSON_Delete(localVarSingleItemJSON_body);
    free(localVarBodyParameters);
    free(keyQuery_pretty);
    free(valueQuery_pretty);
    keyValuePair_free(keyPairQuery_pretty);
    free(keyQuery_dryRun);
    free(valueQuery_dryRun);
    keyValuePair_free(keyPairQuery_dryRun);
    free(keyQuery_fieldManager);
    free(valueQuery_fieldManager);
    keyValuePair_free(keyPairQuery_fieldManager);
    return elementToReturn;
end:
    return NULL;

}

// replace scale of the specified Deployment
//
v1_scale_t*
AppsV1API_replaceAppsV1NamespacedDeploymentScale(apiClient_t *apiClient ,char * name ,char * namespace ,v1_scale_t * body ,char * pretty ,char * dryRun ,char * fieldManager)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/deployments/{name}/scale")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/deployments/{name}/scale");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams_namespace = strlen(name)+3 + strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



    // query parameters
    char *keyQuery_pretty;
    char * valueQuery_pretty;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }

    // query parameters
    char *keyQuery_dryRun;
    char * valueQuery_dryRun;
    keyValuePair_t *keyPairQuery_dryRun = 0;
    if (dryRun)
    {
        keyQuery_dryRun = strdup("dryRun");
        valueQuery_dryRun = strdup((dryRun));
        keyPairQuery_dryRun = keyValuePair_create(keyQuery_dryRun, valueQuery_dryRun);
        list_addElement(localVarQueryParameters,keyPairQuery_dryRun);
    }

    // query parameters
    char *keyQuery_fieldManager;
    char * valueQuery_fieldManager;
    keyValuePair_t *keyPairQuery_fieldManager = 0;
    if (fieldManager)
    {
        keyQuery_fieldManager = strdup("fieldManager");
        valueQuery_fieldManager = strdup((fieldManager));
        keyPairQuery_fieldManager = keyValuePair_create(keyQuery_fieldManager, valueQuery_fieldManager);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldManager);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = v1_scale_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "PUT");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 201) {
        printf("%s\n","Created");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not_ container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_scale_t *elementToReturn = v1_scale_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_name);
    free(localVarToReplace_namespace);
    cJSON_Delete(localVarSingleItemJSON_body);
    free(localVarBodyParameters);
    free(keyQuery_pretty);
    free(valueQuery_pretty);
    keyValuePair_free(keyPairQuery_pretty);
    free(keyQuery_dryRun);
    free(valueQuery_dryRun);
    keyValuePair_free(keyPairQuery_dryRun);
    free(keyQuery_fieldManager);
    free(valueQuery_fieldManager);
    keyValuePair_free(keyPairQuery_fieldManager);
    return elementToReturn;
end:
    return NULL;

}

// replace status of the specified Deployment
//
v1_deployment_t*
AppsV1API_replaceAppsV1NamespacedDeploymentStatus(apiClient_t *apiClient ,char * name ,char * namespace ,v1_deployment_t * body ,char * pretty ,char * dryRun ,char * fieldManager)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/deployments/{name}/status")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/deployments/{name}/status");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams_namespace = strlen(name)+3 + strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



    // query parameters
    char *keyQuery_pretty;
    char * valueQuery_pretty;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }

    // query parameters
    char *keyQuery_dryRun;
    char * valueQuery_dryRun;
    keyValuePair_t *keyPairQuery_dryRun = 0;
    if (dryRun)
    {
        keyQuery_dryRun = strdup("dryRun");
        valueQuery_dryRun = strdup((dryRun));
        keyPairQuery_dryRun = keyValuePair_create(keyQuery_dryRun, valueQuery_dryRun);
        list_addElement(localVarQueryParameters,keyPairQuery_dryRun);
    }

    // query parameters
    char *keyQuery_fieldManager;
    char * valueQuery_fieldManager;
    keyValuePair_t *keyPairQuery_fieldManager = 0;
    if (fieldManager)
    {
        keyQuery_fieldManager = strdup("fieldManager");
        valueQuery_fieldManager = strdup((fieldManager));
        keyPairQuery_fieldManager = keyValuePair_create(keyQuery_fieldManager, valueQuery_fieldManager);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldManager);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = v1_deployment_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "PUT");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 201) {
        printf("%s\n","Created");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not_ container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_deployment_t *elementToReturn = v1_deployment_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_name);
    free(localVarToReplace_namespace);
    cJSON_Delete(localVarSingleItemJSON_body);
    free(localVarBodyParameters);
    free(keyQuery_pretty);
    free(valueQuery_pretty);
    keyValuePair_free(keyPairQuery_pretty);
    free(keyQuery_dryRun);
    free(valueQuery_dryRun);
    keyValuePair_free(keyPairQuery_dryRun);
    free(keyQuery_fieldManager);
    free(valueQuery_fieldManager);
    keyValuePair_free(keyPairQuery_fieldManager);
    return elementToReturn;
end:
    return NULL;

}

// replace the specified ReplicaSet
//
v1_replica_set_t*
AppsV1API_replaceAppsV1NamespacedReplicaSet(apiClient_t *apiClient ,char * name ,char * namespace ,v1_replica_set_t * body ,char * pretty ,char * dryRun ,char * fieldManager)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/replicasets/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/replicasets/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams_namespace = strlen(name)+3 + strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



    // query parameters
    char *keyQuery_pretty;
    char * valueQuery_pretty;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }

    // query parameters
    char *keyQuery_dryRun;
    char * valueQuery_dryRun;
    keyValuePair_t *keyPairQuery_dryRun = 0;
    if (dryRun)
    {
        keyQuery_dryRun = strdup("dryRun");
        valueQuery_dryRun = strdup((dryRun));
        keyPairQuery_dryRun = keyValuePair_create(keyQuery_dryRun, valueQuery_dryRun);
        list_addElement(localVarQueryParameters,keyPairQuery_dryRun);
    }

    // query parameters
    char *keyQuery_fieldManager;
    char * valueQuery_fieldManager;
    keyValuePair_t *keyPairQuery_fieldManager = 0;
    if (fieldManager)
    {
        keyQuery_fieldManager = strdup("fieldManager");
        valueQuery_fieldManager = strdup((fieldManager));
        keyPairQuery_fieldManager = keyValuePair_create(keyQuery_fieldManager, valueQuery_fieldManager);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldManager);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = v1_replica_set_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "PUT");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 201) {
        printf("%s\n","Created");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not_ container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_replica_set_t *elementToReturn = v1_replica_set_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_name);
    free(localVarToReplace_namespace);
    cJSON_Delete(localVarSingleItemJSON_body);
    free(localVarBodyParameters);
    free(keyQuery_pretty);
    free(valueQuery_pretty);
    keyValuePair_free(keyPairQuery_pretty);
    free(keyQuery_dryRun);
    free(valueQuery_dryRun);
    keyValuePair_free(keyPairQuery_dryRun);
    free(keyQuery_fieldManager);
    free(valueQuery_fieldManager);
    keyValuePair_free(keyPairQuery_fieldManager);
    return elementToReturn;
end:
    return NULL;

}

// replace scale of the specified ReplicaSet
//
v1_scale_t*
AppsV1API_replaceAppsV1NamespacedReplicaSetScale(apiClient_t *apiClient ,char * name ,char * namespace ,v1_scale_t * body ,char * pretty ,char * dryRun ,char * fieldManager)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/replicasets/{name}/scale")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/replicasets/{name}/scale");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams_namespace = strlen(name)+3 + strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



    // query parameters
    char *keyQuery_pretty;
    char * valueQuery_pretty;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }

    // query parameters
    char *keyQuery_dryRun;
    char * valueQuery_dryRun;
    keyValuePair_t *keyPairQuery_dryRun = 0;
    if (dryRun)
    {
        keyQuery_dryRun = strdup("dryRun");
        valueQuery_dryRun = strdup((dryRun));
        keyPairQuery_dryRun = keyValuePair_create(keyQuery_dryRun, valueQuery_dryRun);
        list_addElement(localVarQueryParameters,keyPairQuery_dryRun);
    }

    // query parameters
    char *keyQuery_fieldManager;
    char * valueQuery_fieldManager;
    keyValuePair_t *keyPairQuery_fieldManager = 0;
    if (fieldManager)
    {
        keyQuery_fieldManager = strdup("fieldManager");
        valueQuery_fieldManager = strdup((fieldManager));
        keyPairQuery_fieldManager = keyValuePair_create(keyQuery_fieldManager, valueQuery_fieldManager);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldManager);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = v1_scale_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "PUT");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 201) {
        printf("%s\n","Created");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not_ container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_scale_t *elementToReturn = v1_scale_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_name);
    free(localVarToReplace_namespace);
    cJSON_Delete(localVarSingleItemJSON_body);
    free(localVarBodyParameters);
    free(keyQuery_pretty);
    free(valueQuery_pretty);
    keyValuePair_free(keyPairQuery_pretty);
    free(keyQuery_dryRun);
    free(valueQuery_dryRun);
    keyValuePair_free(keyPairQuery_dryRun);
    free(keyQuery_fieldManager);
    free(valueQuery_fieldManager);
    keyValuePair_free(keyPairQuery_fieldManager);
    return elementToReturn;
end:
    return NULL;

}

// replace status of the specified ReplicaSet
//
v1_replica_set_t*
AppsV1API_replaceAppsV1NamespacedReplicaSetStatus(apiClient_t *apiClient ,char * name ,char * namespace ,v1_replica_set_t * body ,char * pretty ,char * dryRun ,char * fieldManager)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/replicasets/{name}/status")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/replicasets/{name}/status");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams_namespace = strlen(name)+3 + strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



    // query parameters
    char *keyQuery_pretty;
    char * valueQuery_pretty;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }

    // query parameters
    char *keyQuery_dryRun;
    char * valueQuery_dryRun;
    keyValuePair_t *keyPairQuery_dryRun = 0;
    if (dryRun)
    {
        keyQuery_dryRun = strdup("dryRun");
        valueQuery_dryRun = strdup((dryRun));
        keyPairQuery_dryRun = keyValuePair_create(keyQuery_dryRun, valueQuery_dryRun);
        list_addElement(localVarQueryParameters,keyPairQuery_dryRun);
    }

    // query parameters
    char *keyQuery_fieldManager;
    char * valueQuery_fieldManager;
    keyValuePair_t *keyPairQuery_fieldManager = 0;
    if (fieldManager)
    {
        keyQuery_fieldManager = strdup("fieldManager");
        valueQuery_fieldManager = strdup((fieldManager));
        keyPairQuery_fieldManager = keyValuePair_create(keyQuery_fieldManager, valueQuery_fieldManager);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldManager);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = v1_replica_set_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "PUT");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 201) {
        printf("%s\n","Created");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not_ container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_replica_set_t *elementToReturn = v1_replica_set_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_name);
    free(localVarToReplace_namespace);
    cJSON_Delete(localVarSingleItemJSON_body);
    free(localVarBodyParameters);
    free(keyQuery_pretty);
    free(valueQuery_pretty);
    keyValuePair_free(keyPairQuery_pretty);
    free(keyQuery_dryRun);
    free(valueQuery_dryRun);
    keyValuePair_free(keyPairQuery_dryRun);
    free(keyQuery_fieldManager);
    free(valueQuery_fieldManager);
    keyValuePair_free(keyPairQuery_fieldManager);
    return elementToReturn;
end:
    return NULL;

}

// replace the specified StatefulSet
//
v1_stateful_set_t*
AppsV1API_replaceAppsV1NamespacedStatefulSet(apiClient_t *apiClient ,char * name ,char * namespace ,v1_stateful_set_t * body ,char * pretty ,char * dryRun ,char * fieldManager)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/statefulsets/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/statefulsets/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams_namespace = strlen(name)+3 + strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



    // query parameters
    char *keyQuery_pretty;
    char * valueQuery_pretty;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }

    // query parameters
    char *keyQuery_dryRun;
    char * valueQuery_dryRun;
    keyValuePair_t *keyPairQuery_dryRun = 0;
    if (dryRun)
    {
        keyQuery_dryRun = strdup("dryRun");
        valueQuery_dryRun = strdup((dryRun));
        keyPairQuery_dryRun = keyValuePair_create(keyQuery_dryRun, valueQuery_dryRun);
        list_addElement(localVarQueryParameters,keyPairQuery_dryRun);
    }

    // query parameters
    char *keyQuery_fieldManager;
    char * valueQuery_fieldManager;
    keyValuePair_t *keyPairQuery_fieldManager = 0;
    if (fieldManager)
    {
        keyQuery_fieldManager = strdup("fieldManager");
        valueQuery_fieldManager = strdup((fieldManager));
        keyPairQuery_fieldManager = keyValuePair_create(keyQuery_fieldManager, valueQuery_fieldManager);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldManager);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = v1_stateful_set_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "PUT");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 201) {
        printf("%s\n","Created");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not_ container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_stateful_set_t *elementToReturn = v1_stateful_set_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_name);
    free(localVarToReplace_namespace);
    cJSON_Delete(localVarSingleItemJSON_body);
    free(localVarBodyParameters);
    free(keyQuery_pretty);
    free(valueQuery_pretty);
    keyValuePair_free(keyPairQuery_pretty);
    free(keyQuery_dryRun);
    free(valueQuery_dryRun);
    keyValuePair_free(keyPairQuery_dryRun);
    free(keyQuery_fieldManager);
    free(valueQuery_fieldManager);
    keyValuePair_free(keyPairQuery_fieldManager);
    return elementToReturn;
end:
    return NULL;

}

// replace scale of the specified StatefulSet
//
v1_scale_t*
AppsV1API_replaceAppsV1NamespacedStatefulSetScale(apiClient_t *apiClient ,char * name ,char * namespace ,v1_scale_t * body ,char * pretty ,char * dryRun ,char * fieldManager)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/statefulsets/{name}/scale")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/statefulsets/{name}/scale");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams_namespace = strlen(name)+3 + strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



    // query parameters
    char *keyQuery_pretty;
    char * valueQuery_pretty;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }

    // query parameters
    char *keyQuery_dryRun;
    char * valueQuery_dryRun;
    keyValuePair_t *keyPairQuery_dryRun = 0;
    if (dryRun)
    {
        keyQuery_dryRun = strdup("dryRun");
        valueQuery_dryRun = strdup((dryRun));
        keyPairQuery_dryRun = keyValuePair_create(keyQuery_dryRun, valueQuery_dryRun);
        list_addElement(localVarQueryParameters,keyPairQuery_dryRun);
    }

    // query parameters
    char *keyQuery_fieldManager;
    char * valueQuery_fieldManager;
    keyValuePair_t *keyPairQuery_fieldManager = 0;
    if (fieldManager)
    {
        keyQuery_fieldManager = strdup("fieldManager");
        valueQuery_fieldManager = strdup((fieldManager));
        keyPairQuery_fieldManager = keyValuePair_create(keyQuery_fieldManager, valueQuery_fieldManager);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldManager);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = v1_scale_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "PUT");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 201) {
        printf("%s\n","Created");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not_ container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_scale_t *elementToReturn = v1_scale_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_name);
    free(localVarToReplace_namespace);
    cJSON_Delete(localVarSingleItemJSON_body);
    free(localVarBodyParameters);
    free(keyQuery_pretty);
    free(valueQuery_pretty);
    keyValuePair_free(keyPairQuery_pretty);
    free(keyQuery_dryRun);
    free(valueQuery_dryRun);
    keyValuePair_free(keyPairQuery_dryRun);
    free(keyQuery_fieldManager);
    free(valueQuery_fieldManager);
    keyValuePair_free(keyPairQuery_fieldManager);
    return elementToReturn;
end:
    return NULL;

}

// replace status of the specified StatefulSet
//
v1_stateful_set_t*
AppsV1API_replaceAppsV1NamespacedStatefulSetStatus(apiClient_t *apiClient ,char * name ,char * namespace ,v1_stateful_set_t * body ,char * pretty ,char * dryRun ,char * fieldManager)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/statefulsets/{name}/status")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/statefulsets/{name}/status");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams_namespace = strlen(name)+3 + strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



    // query parameters
    char *keyQuery_pretty;
    char * valueQuery_pretty;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }

    // query parameters
    char *keyQuery_dryRun;
    char * valueQuery_dryRun;
    keyValuePair_t *keyPairQuery_dryRun = 0;
    if (dryRun)
    {
        keyQuery_dryRun = strdup("dryRun");
        valueQuery_dryRun = strdup((dryRun));
        keyPairQuery_dryRun = keyValuePair_create(keyQuery_dryRun, valueQuery_dryRun);
        list_addElement(localVarQueryParameters,keyPairQuery_dryRun);
    }

    // query parameters
    char *keyQuery_fieldManager;
    char * valueQuery_fieldManager;
    keyValuePair_t *keyPairQuery_fieldManager = 0;
    if (fieldManager)
    {
        keyQuery_fieldManager = strdup("fieldManager");
        valueQuery_fieldManager = strdup((fieldManager));
        keyPairQuery_fieldManager = keyValuePair_create(keyQuery_fieldManager, valueQuery_fieldManager);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldManager);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = v1_stateful_set_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "PUT");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 201) {
        printf("%s\n","Created");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not_ container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_stateful_set_t *elementToReturn = v1_stateful_set_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_name);
    free(localVarToReplace_namespace);
    cJSON_Delete(localVarSingleItemJSON_body);
    free(localVarBodyParameters);
    free(keyQuery_pretty);
    free(valueQuery_pretty);
    keyValuePair_free(keyPairQuery_pretty);
    free(keyQuery_dryRun);
    free(valueQuery_dryRun);
    keyValuePair_free(keyPairQuery_dryRun);
    free(keyQuery_fieldManager);
    free(valueQuery_fieldManager);
    keyValuePair_free(keyPairQuery_fieldManager);
    return elementToReturn;
end:
    return NULL;

}

