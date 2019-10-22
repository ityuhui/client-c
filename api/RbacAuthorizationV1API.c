#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "RbacAuthorizationV1API.h"


#define MAX_BUFFER_LENGTH 4096
#define intToStr(dst, src) \
    do {\
    char dst[256];\
    snprintf(dst, 256, "%ld", (long int)(src));\
}while(0)

// create a ClusterRole
//
v1_cluster_role_t*
RbacAuthorizationV1API_createRbacAuthorizationV1ClusterRole(apiClient_t *apiClient ,v1_cluster_role_t * body ,char * pretty ,char * dryRun ,char * fieldManager)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/rbac.authorization.k8s.io/v1/clusterroles")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/rbac.authorization.k8s.io/v1/clusterroles");




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
        localVarSingleItemJSON_body = v1_cluster_role_convertToJSON(body);
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
    //nonprimitive not container
    cJSON *RbacAuthorizationV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_cluster_role_t *elementToReturn = v1_cluster_role_parseFromJSON(RbacAuthorizationV1APIlocalVarJSON);
    cJSON_Delete(RbacAuthorizationV1APIlocalVarJSON);
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

// create a ClusterRoleBinding
//
v1_cluster_role_binding_t*
RbacAuthorizationV1API_createRbacAuthorizationV1ClusterRoleBinding(apiClient_t *apiClient ,v1_cluster_role_binding_t * body ,char * pretty ,char * dryRun ,char * fieldManager)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/rbac.authorization.k8s.io/v1/clusterrolebindings")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/rbac.authorization.k8s.io/v1/clusterrolebindings");




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
        localVarSingleItemJSON_body = v1_cluster_role_binding_convertToJSON(body);
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
    //nonprimitive not container
    cJSON *RbacAuthorizationV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_cluster_role_binding_t *elementToReturn = v1_cluster_role_binding_parseFromJSON(RbacAuthorizationV1APIlocalVarJSON);
    cJSON_Delete(RbacAuthorizationV1APIlocalVarJSON);
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

// create a Role
//
v1_role_t*
RbacAuthorizationV1API_createRbacAuthorizationV1NamespacedRole(apiClient_t *apiClient ,char * namespace ,v1_role_t * body ,char * pretty ,char * dryRun ,char * fieldManager)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/rbac.authorization.k8s.io/v1/namespaces/{namespace}/roles")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/rbac.authorization.k8s.io/v1/namespaces/{namespace}/roles");


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
        localVarSingleItemJSON_body = v1_role_convertToJSON(body);
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
    //nonprimitive not container
    cJSON *RbacAuthorizationV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_role_t *elementToReturn = v1_role_parseFromJSON(RbacAuthorizationV1APIlocalVarJSON);
    cJSON_Delete(RbacAuthorizationV1APIlocalVarJSON);
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

// create a RoleBinding
//
v1_role_binding_t*
RbacAuthorizationV1API_createRbacAuthorizationV1NamespacedRoleBinding(apiClient_t *apiClient ,char * namespace ,v1_role_binding_t * body ,char * pretty ,char * dryRun ,char * fieldManager)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/rbac.authorization.k8s.io/v1/namespaces/{namespace}/rolebindings")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/rbac.authorization.k8s.io/v1/namespaces/{namespace}/rolebindings");


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
        localVarSingleItemJSON_body = v1_role_binding_convertToJSON(body);
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
    //nonprimitive not container
    cJSON *RbacAuthorizationV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_role_binding_t *elementToReturn = v1_role_binding_parseFromJSON(RbacAuthorizationV1APIlocalVarJSON);
    cJSON_Delete(RbacAuthorizationV1APIlocalVarJSON);
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

// delete a ClusterRole
//
v1_status_t*
RbacAuthorizationV1API_deleteRbacAuthorizationV1ClusterRole(apiClient_t *apiClient ,char * name ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/rbac.authorization.k8s.io/v1/clusterroles/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/rbac.authorization.k8s.io/v1/clusterroles/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);



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
    //nonprimitive not container
    cJSON *RbacAuthorizationV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_status_t *elementToReturn = v1_status_parseFromJSON(RbacAuthorizationV1APIlocalVarJSON);
    cJSON_Delete(RbacAuthorizationV1APIlocalVarJSON);
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

// delete a ClusterRoleBinding
//
v1_status_t*
RbacAuthorizationV1API_deleteRbacAuthorizationV1ClusterRoleBinding(apiClient_t *apiClient ,char * name ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/rbac.authorization.k8s.io/v1/clusterrolebindings/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/rbac.authorization.k8s.io/v1/clusterrolebindings/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);



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
    //nonprimitive not container
    cJSON *RbacAuthorizationV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_status_t *elementToReturn = v1_status_parseFromJSON(RbacAuthorizationV1APIlocalVarJSON);
    cJSON_Delete(RbacAuthorizationV1APIlocalVarJSON);
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

// delete collection of ClusterRole
//
v1_status_t*
RbacAuthorizationV1API_deleteRbacAuthorizationV1CollectionClusterRole(apiClient_t *apiClient ,char * pretty ,int allowWatchBookmarks ,char * continue ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/rbac.authorization.k8s.io/v1/clusterroles")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/rbac.authorization.k8s.io/v1/clusterroles");




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
    if (continue)
    {
        keyQuery_continue = strdup("continue");
        valueQuery_continue = strdup((continue));
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
    //nonprimitive not container
    cJSON *RbacAuthorizationV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_status_t *elementToReturn = v1_status_parseFromJSON(RbacAuthorizationV1APIlocalVarJSON);
    cJSON_Delete(RbacAuthorizationV1APIlocalVarJSON);
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

// delete collection of ClusterRoleBinding
//
v1_status_t*
RbacAuthorizationV1API_deleteRbacAuthorizationV1CollectionClusterRoleBinding(apiClient_t *apiClient ,char * pretty ,int allowWatchBookmarks ,char * continue ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/rbac.authorization.k8s.io/v1/clusterrolebindings")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/rbac.authorization.k8s.io/v1/clusterrolebindings");




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
    if (continue)
    {
        keyQuery_continue = strdup("continue");
        valueQuery_continue = strdup((continue));
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
    //nonprimitive not container
    cJSON *RbacAuthorizationV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_status_t *elementToReturn = v1_status_parseFromJSON(RbacAuthorizationV1APIlocalVarJSON);
    cJSON_Delete(RbacAuthorizationV1APIlocalVarJSON);
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

// delete collection of Role
//
v1_status_t*
RbacAuthorizationV1API_deleteRbacAuthorizationV1CollectionNamespacedRole(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/rbac.authorization.k8s.io/v1/namespaces/{namespace}/roles")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/rbac.authorization.k8s.io/v1/namespaces/{namespace}/roles");


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
    if (continue)
    {
        keyQuery_continue = strdup("continue");
        valueQuery_continue = strdup((continue));
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
    //nonprimitive not container
    cJSON *RbacAuthorizationV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_status_t *elementToReturn = v1_status_parseFromJSON(RbacAuthorizationV1APIlocalVarJSON);
    cJSON_Delete(RbacAuthorizationV1APIlocalVarJSON);
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

// delete collection of RoleBinding
//
v1_status_t*
RbacAuthorizationV1API_deleteRbacAuthorizationV1CollectionNamespacedRoleBinding(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue ,char * dryRun ,char * fieldSelector ,int gracePeriodSeconds ,char * labelSelector ,int limit ,int orphanDependents ,char * propagationPolicy ,char * resourceVersion ,int timeoutSeconds ,int watch ,v1_delete_options_t * body)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/rbac.authorization.k8s.io/v1/namespaces/{namespace}/rolebindings")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/rbac.authorization.k8s.io/v1/namespaces/{namespace}/rolebindings");


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
    if (continue)
    {
        keyQuery_continue = strdup("continue");
        valueQuery_continue = strdup((continue));
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
    //nonprimitive not container
    cJSON *RbacAuthorizationV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_status_t *elementToReturn = v1_status_parseFromJSON(RbacAuthorizationV1APIlocalVarJSON);
    cJSON_Delete(RbacAuthorizationV1APIlocalVarJSON);
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

// delete a Role
//
v1_status_t*
RbacAuthorizationV1API_deleteRbacAuthorizationV1NamespacedRole(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/rbac.authorization.k8s.io/v1/namespaces/{namespace}/roles/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/rbac.authorization.k8s.io/v1/namespaces/{namespace}/roles/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3strlen(namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams_namespace = strlen(name)+3strlen(namespace)+3 + strlen("{ namespace }");
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
    //nonprimitive not container
    cJSON *RbacAuthorizationV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_status_t *elementToReturn = v1_status_parseFromJSON(RbacAuthorizationV1APIlocalVarJSON);
    cJSON_Delete(RbacAuthorizationV1APIlocalVarJSON);
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

// delete a RoleBinding
//
v1_status_t*
RbacAuthorizationV1API_deleteRbacAuthorizationV1NamespacedRoleBinding(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty ,char * dryRun ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy ,v1_delete_options_t * body)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/rbac.authorization.k8s.io/v1/namespaces/{namespace}/rolebindings/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/rbac.authorization.k8s.io/v1/namespaces/{namespace}/rolebindings/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3strlen(namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams_namespace = strlen(name)+3strlen(namespace)+3 + strlen("{ namespace }");
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
    //nonprimitive not container
    cJSON *RbacAuthorizationV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_status_t *elementToReturn = v1_status_parseFromJSON(RbacAuthorizationV1APIlocalVarJSON);
    cJSON_Delete(RbacAuthorizationV1APIlocalVarJSON);
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
RbacAuthorizationV1API_getRbacAuthorizationV1APIResources(apiClient_t *apiClient)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/rbac.authorization.k8s.io/v1/")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/rbac.authorization.k8s.io/v1/");



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
    //nonprimitive not container
    cJSON *RbacAuthorizationV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_api_resource_list_t *elementToReturn = v1_api_resource_list_parseFromJSON(RbacAuthorizationV1APIlocalVarJSON);
    cJSON_Delete(RbacAuthorizationV1APIlocalVarJSON);
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

// list or watch objects of kind ClusterRole
//
v1_cluster_role_list_t*
RbacAuthorizationV1API_listRbacAuthorizationV1ClusterRole(apiClient_t *apiClient ,char * pretty ,int allowWatchBookmarks ,char * continue ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/rbac.authorization.k8s.io/v1/clusterroles")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/rbac.authorization.k8s.io/v1/clusterroles");




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
    if (continue)
    {
        keyQuery_continue = strdup("continue");
        valueQuery_continue = strdup((continue));
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
    //nonprimitive not container
    cJSON *RbacAuthorizationV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_cluster_role_list_t *elementToReturn = v1_cluster_role_list_parseFromJSON(RbacAuthorizationV1APIlocalVarJSON);
    cJSON_Delete(RbacAuthorizationV1APIlocalVarJSON);
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

// list or watch objects of kind ClusterRoleBinding
//
v1_cluster_role_binding_list_t*
RbacAuthorizationV1API_listRbacAuthorizationV1ClusterRoleBinding(apiClient_t *apiClient ,char * pretty ,int allowWatchBookmarks ,char * continue ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/rbac.authorization.k8s.io/v1/clusterrolebindings")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/rbac.authorization.k8s.io/v1/clusterrolebindings");




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
    if (continue)
    {
        keyQuery_continue = strdup("continue");
        valueQuery_continue = strdup((continue));
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
    //nonprimitive not container
    cJSON *RbacAuthorizationV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_cluster_role_binding_list_t *elementToReturn = v1_cluster_role_binding_list_parseFromJSON(RbacAuthorizationV1APIlocalVarJSON);
    cJSON_Delete(RbacAuthorizationV1APIlocalVarJSON);
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

// list or watch objects of kind Role
//
v1_role_list_t*
RbacAuthorizationV1API_listRbacAuthorizationV1NamespacedRole(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/rbac.authorization.k8s.io/v1/namespaces/{namespace}/roles")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/rbac.authorization.k8s.io/v1/namespaces/{namespace}/roles");


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
    if (continue)
    {
        keyQuery_continue = strdup("continue");
        valueQuery_continue = strdup((continue));
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
    //nonprimitive not container
    cJSON *RbacAuthorizationV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_role_list_t *elementToReturn = v1_role_list_parseFromJSON(RbacAuthorizationV1APIlocalVarJSON);
    cJSON_Delete(RbacAuthorizationV1APIlocalVarJSON);
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

// list or watch objects of kind RoleBinding
//
v1_role_binding_list_t*
RbacAuthorizationV1API_listRbacAuthorizationV1NamespacedRoleBinding(apiClient_t *apiClient ,char * namespace ,char * pretty ,int allowWatchBookmarks ,char * continue ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/rbac.authorization.k8s.io/v1/namespaces/{namespace}/rolebindings")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/rbac.authorization.k8s.io/v1/namespaces/{namespace}/rolebindings");


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
    if (continue)
    {
        keyQuery_continue = strdup("continue");
        valueQuery_continue = strdup((continue));
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
    //nonprimitive not container
    cJSON *RbacAuthorizationV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_role_binding_list_t *elementToReturn = v1_role_binding_list_parseFromJSON(RbacAuthorizationV1APIlocalVarJSON);
    cJSON_Delete(RbacAuthorizationV1APIlocalVarJSON);
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

// list or watch objects of kind RoleBinding
//
v1_role_binding_list_t*
RbacAuthorizationV1API_listRbacAuthorizationV1RoleBindingForAllNamespaces(apiClient_t *apiClient ,int allowWatchBookmarks ,char * continue ,char * fieldSelector ,char * labelSelector ,int limit ,char * pretty ,char * resourceVersion ,int timeoutSeconds ,int watch)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/rbac.authorization.k8s.io/v1/rolebindings")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/rbac.authorization.k8s.io/v1/rolebindings");




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
    if (continue)
    {
        keyQuery_continue = strdup("continue");
        valueQuery_continue = strdup((continue));
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
    //nonprimitive not container
    cJSON *RbacAuthorizationV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_role_binding_list_t *elementToReturn = v1_role_binding_list_parseFromJSON(RbacAuthorizationV1APIlocalVarJSON);
    cJSON_Delete(RbacAuthorizationV1APIlocalVarJSON);
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

// list or watch objects of kind Role
//
v1_role_list_t*
RbacAuthorizationV1API_listRbacAuthorizationV1RoleForAllNamespaces(apiClient_t *apiClient ,int allowWatchBookmarks ,char * continue ,char * fieldSelector ,char * labelSelector ,int limit ,char * pretty ,char * resourceVersion ,int timeoutSeconds ,int watch)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/rbac.authorization.k8s.io/v1/roles")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/rbac.authorization.k8s.io/v1/roles");




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
    if (continue)
    {
        keyQuery_continue = strdup("continue");
        valueQuery_continue = strdup((continue));
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
    //nonprimitive not container
    cJSON *RbacAuthorizationV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_role_list_t *elementToReturn = v1_role_list_parseFromJSON(RbacAuthorizationV1APIlocalVarJSON);
    cJSON_Delete(RbacAuthorizationV1APIlocalVarJSON);
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

// partially update the specified ClusterRole
//
v1_cluster_role_t*
RbacAuthorizationV1API_patchRbacAuthorizationV1ClusterRole(apiClient_t *apiClient ,char * name , body ,char * pretty ,char * dryRun ,char * fieldManager ,int force)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = list_create();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/rbac.authorization.k8s.io/v1/clusterroles/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/rbac.authorization.k8s.io/v1/clusterroles/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);



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
    //nonprimitive not container
    cJSON *RbacAuthorizationV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_cluster_role_t *elementToReturn = v1_cluster_role_parseFromJSON(RbacAuthorizationV1APIlocalVarJSON);
    cJSON_Delete(RbacAuthorizationV1APIlocalVarJSON);
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

// partially update the specified ClusterRoleBinding
//
v1_cluster_role_binding_t*
RbacAuthorizationV1API_patchRbacAuthorizationV1ClusterRoleBinding(apiClient_t *apiClient ,char * name , body ,char * pretty ,char * dryRun ,char * fieldManager ,int force)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = list_create();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/rbac.authorization.k8s.io/v1/clusterrolebindings/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/rbac.authorization.k8s.io/v1/clusterrolebindings/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);



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
    //nonprimitive not container
    cJSON *RbacAuthorizationV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_cluster_role_binding_t *elementToReturn = v1_cluster_role_binding_parseFromJSON(RbacAuthorizationV1APIlocalVarJSON);
    cJSON_Delete(RbacAuthorizationV1APIlocalVarJSON);
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

// partially update the specified Role
//
v1_role_t*
RbacAuthorizationV1API_patchRbacAuthorizationV1NamespacedRole(apiClient_t *apiClient ,char * name ,char * namespace , body ,char * pretty ,char * dryRun ,char * fieldManager ,int force)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = list_create();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/rbac.authorization.k8s.io/v1/namespaces/{namespace}/roles/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/rbac.authorization.k8s.io/v1/namespaces/{namespace}/roles/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3strlen(namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams_namespace = strlen(name)+3strlen(namespace)+3 + strlen("{ namespace }");
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
    //nonprimitive not container
    cJSON *RbacAuthorizationV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_role_t *elementToReturn = v1_role_parseFromJSON(RbacAuthorizationV1APIlocalVarJSON);
    cJSON_Delete(RbacAuthorizationV1APIlocalVarJSON);
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

// partially update the specified RoleBinding
//
v1_role_binding_t*
RbacAuthorizationV1API_patchRbacAuthorizationV1NamespacedRoleBinding(apiClient_t *apiClient ,char * name ,char * namespace , body ,char * pretty ,char * dryRun ,char * fieldManager ,int force)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = list_create();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/rbac.authorization.k8s.io/v1/namespaces/{namespace}/rolebindings/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/rbac.authorization.k8s.io/v1/namespaces/{namespace}/rolebindings/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3strlen(namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams_namespace = strlen(name)+3strlen(namespace)+3 + strlen("{ namespace }");
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
    //nonprimitive not container
    cJSON *RbacAuthorizationV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_role_binding_t *elementToReturn = v1_role_binding_parseFromJSON(RbacAuthorizationV1APIlocalVarJSON);
    cJSON_Delete(RbacAuthorizationV1APIlocalVarJSON);
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

// read the specified ClusterRole
//
v1_cluster_role_t*
RbacAuthorizationV1API_readRbacAuthorizationV1ClusterRole(apiClient_t *apiClient ,char * name ,char * pretty)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/rbac.authorization.k8s.io/v1/clusterroles/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/rbac.authorization.k8s.io/v1/clusterroles/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);



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
    //nonprimitive not container
    cJSON *RbacAuthorizationV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_cluster_role_t *elementToReturn = v1_cluster_role_parseFromJSON(RbacAuthorizationV1APIlocalVarJSON);
    cJSON_Delete(RbacAuthorizationV1APIlocalVarJSON);
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
    free(keyQuery_pretty);
    free(valueQuery_pretty);
    keyValuePair_free(keyPairQuery_pretty);
    return elementToReturn;
end:
    return NULL;

}

// read the specified ClusterRoleBinding
//
v1_cluster_role_binding_t*
RbacAuthorizationV1API_readRbacAuthorizationV1ClusterRoleBinding(apiClient_t *apiClient ,char * name ,char * pretty)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/rbac.authorization.k8s.io/v1/clusterrolebindings/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/rbac.authorization.k8s.io/v1/clusterrolebindings/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);



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
    //nonprimitive not container
    cJSON *RbacAuthorizationV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_cluster_role_binding_t *elementToReturn = v1_cluster_role_binding_parseFromJSON(RbacAuthorizationV1APIlocalVarJSON);
    cJSON_Delete(RbacAuthorizationV1APIlocalVarJSON);
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
    free(keyQuery_pretty);
    free(valueQuery_pretty);
    keyValuePair_free(keyPairQuery_pretty);
    return elementToReturn;
end:
    return NULL;

}

// read the specified Role
//
v1_role_t*
RbacAuthorizationV1API_readRbacAuthorizationV1NamespacedRole(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/rbac.authorization.k8s.io/v1/namespaces/{namespace}/roles/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/rbac.authorization.k8s.io/v1/namespaces/{namespace}/roles/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3strlen(namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams_namespace = strlen(name)+3strlen(namespace)+3 + strlen("{ namespace }");
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
    //nonprimitive not container
    cJSON *RbacAuthorizationV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_role_t *elementToReturn = v1_role_parseFromJSON(RbacAuthorizationV1APIlocalVarJSON);
    cJSON_Delete(RbacAuthorizationV1APIlocalVarJSON);
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

// read the specified RoleBinding
//
v1_role_binding_t*
RbacAuthorizationV1API_readRbacAuthorizationV1NamespacedRoleBinding(apiClient_t *apiClient ,char * name ,char * namespace ,char * pretty)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/rbac.authorization.k8s.io/v1/namespaces/{namespace}/rolebindings/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/rbac.authorization.k8s.io/v1/namespaces/{namespace}/rolebindings/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3strlen(namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams_namespace = strlen(name)+3strlen(namespace)+3 + strlen("{ namespace }");
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
    //nonprimitive not container
    cJSON *RbacAuthorizationV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_role_binding_t *elementToReturn = v1_role_binding_parseFromJSON(RbacAuthorizationV1APIlocalVarJSON);
    cJSON_Delete(RbacAuthorizationV1APIlocalVarJSON);
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

// replace the specified ClusterRole
//
v1_cluster_role_t*
RbacAuthorizationV1API_replaceRbacAuthorizationV1ClusterRole(apiClient_t *apiClient ,char * name ,v1_cluster_role_t * body ,char * pretty ,char * dryRun ,char * fieldManager)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/rbac.authorization.k8s.io/v1/clusterroles/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/rbac.authorization.k8s.io/v1/clusterroles/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);



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
        localVarSingleItemJSON_body = v1_cluster_role_convertToJSON(body);
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
    //nonprimitive not container
    cJSON *RbacAuthorizationV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_cluster_role_t *elementToReturn = v1_cluster_role_parseFromJSON(RbacAuthorizationV1APIlocalVarJSON);
    cJSON_Delete(RbacAuthorizationV1APIlocalVarJSON);
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

// replace the specified ClusterRoleBinding
//
v1_cluster_role_binding_t*
RbacAuthorizationV1API_replaceRbacAuthorizationV1ClusterRoleBinding(apiClient_t *apiClient ,char * name ,v1_cluster_role_binding_t * body ,char * pretty ,char * dryRun ,char * fieldManager)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/rbac.authorization.k8s.io/v1/clusterrolebindings/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/rbac.authorization.k8s.io/v1/clusterrolebindings/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);



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
        localVarSingleItemJSON_body = v1_cluster_role_binding_convertToJSON(body);
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
    //nonprimitive not container
    cJSON *RbacAuthorizationV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_cluster_role_binding_t *elementToReturn = v1_cluster_role_binding_parseFromJSON(RbacAuthorizationV1APIlocalVarJSON);
    cJSON_Delete(RbacAuthorizationV1APIlocalVarJSON);
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

// replace the specified Role
//
v1_role_t*
RbacAuthorizationV1API_replaceRbacAuthorizationV1NamespacedRole(apiClient_t *apiClient ,char * name ,char * namespace ,v1_role_t * body ,char * pretty ,char * dryRun ,char * fieldManager)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/rbac.authorization.k8s.io/v1/namespaces/{namespace}/roles/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/rbac.authorization.k8s.io/v1/namespaces/{namespace}/roles/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3strlen(namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams_namespace = strlen(name)+3strlen(namespace)+3 + strlen("{ namespace }");
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
        localVarSingleItemJSON_body = v1_role_convertToJSON(body);
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
    //nonprimitive not container
    cJSON *RbacAuthorizationV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_role_t *elementToReturn = v1_role_parseFromJSON(RbacAuthorizationV1APIlocalVarJSON);
    cJSON_Delete(RbacAuthorizationV1APIlocalVarJSON);
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

// replace the specified RoleBinding
//
v1_role_binding_t*
RbacAuthorizationV1API_replaceRbacAuthorizationV1NamespacedRoleBinding(apiClient_t *apiClient ,char * name ,char * namespace ,v1_role_binding_t * body ,char * pretty ,char * dryRun ,char * fieldManager)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/rbac.authorization.k8s.io/v1/namespaces/{namespace}/rolebindings/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/rbac.authorization.k8s.io/v1/namespaces/{namespace}/rolebindings/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3strlen(namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams_namespace = strlen(name)+3strlen(namespace)+3 + strlen("{ namespace }");
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
        localVarSingleItemJSON_body = v1_role_binding_convertToJSON(body);
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
    //nonprimitive not container
    cJSON *RbacAuthorizationV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_role_binding_t *elementToReturn = v1_role_binding_parseFromJSON(RbacAuthorizationV1APIlocalVarJSON);
    cJSON_Delete(RbacAuthorizationV1APIlocalVarJSON);
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

