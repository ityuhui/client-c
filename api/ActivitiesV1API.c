#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "ActivitiesV1API.h"


#define MAX_BUFFER_LENGTH 4096
#define intToStr(dst, src) \
    do {\
    char dst[256];\
    snprintf(dst, 256, "%ld", (long int)(src));\
}while(0)




// Creates a namespace scoped Custom object
//
ego_v1_activity_t *
ActivitiesV1API_createNamespacedActivity(apiClient_t *apiClient , char * namespace_ , ego_v1_activity_t * body , char * pretty)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    char      *group = "ego.symphony.spectrumcomputing.ibm.com";
    char      *version = "v1";
    char      *plural = "activities";

    // create the path
    long sizeOfPath = strlen("/apis/{group}/{version}/namespaces/{namespace}/{plural}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/{group}/{version}/namespaces/{namespace}/{plural}");


    // Path Params
    long sizeOfPathParams_group = strlen(group)+3 + strlen(version)+3 + strlen(namespace_)+3 + strlen(plural)+3 + strlen("{ group }");
    if(group == NULL) {
        goto end;
    }
    char* localVarToReplace_group = malloc(sizeOfPathParams_group);
    sprintf(localVarToReplace_group, "{%s}", "group");

    localVarPath = strReplace(localVarPath, localVarToReplace_group, group);

    // Path Params
    long sizeOfPathParams_version = strlen(group)+3 + strlen(version)+3 + strlen(namespace_)+3 + strlen(plural)+3 + strlen("{ version }");
    if(version == NULL) {
        goto end;
    }
    char* localVarToReplace_version = malloc(sizeOfPathParams_version);
    sprintf(localVarToReplace_version, "{%s}", "version");

    localVarPath = strReplace(localVarPath, localVarToReplace_version, version);

    // Path Params
    long sizeOfPathParams_namespace = strlen(group)+3 + strlen(version)+3 + strlen(namespace_)+3 + strlen(plural)+3 + strlen("{ namespace }");
    if(namespace_ == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace_);

    // Path Params
    long sizeOfPathParams_plural = strlen(group)+3 + strlen(version)+3 + strlen(namespace_)+3 + strlen(plural)+3 + strlen("{ plural }");
    if(plural == NULL) {
        goto end;
    }
    char* localVarToReplace_plural = malloc(sizeOfPathParams_plural);
    sprintf(localVarToReplace_plural, "{%s}", "plural");

    localVarPath = strReplace(localVarPath, localVarToReplace_plural, plural);

    printf("localVarPath=%s\n", localVarPath);

    // query parameters
    char *keyQuery_pretty = NULL;
    char *valueQuery_pretty = NULL;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = ego_v1_activity_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "POST");

    if (apiClient->response_code == 201) {
        printf("%s\n","Created");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not_ container
    cJSON *activitiesAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    ego_v1_activity_t *elementToReturn = ego_v1_activity_parseFromJSON(activitiesAPIlocalVarJSON);
    cJSON_Delete(activitiesAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    FREEUP(localVarPath);
    FREEUP(localVarToReplace_group);
    FREEUP(localVarToReplace_version);
    FREEUP(localVarToReplace_namespace);
    FREEUP(localVarToReplace_plural);
    cJSON_Delete(localVarSingleItemJSON_body);
    FREEUP(localVarBodyParameters);
    FREEUP(keyQuery_pretty);
    FREEUP(valueQuery_pretty);
    keyValuePair_free(keyPairQuery_pretty);
    return elementToReturn;
end:
    return NULL;

}

/*

// Creates a cluster scoped Custom object
//
object_t*
CustomObjectsAPI_createClusterCustomObject(apiClient_t *apiClient, char * group, char * version, char * plural, object_t * body, char * pretty)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/{group}/{version}/{plural}") + 1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/{group}/{version}/{plural}");


    // Path Params
    long sizeOfPathParams_group = strlen(group) + 3 + strlen(version) + 3 + strlen(plural) + 3 + strlen("{ group }");
    if (group == NULL) {
        goto end;
    }
    char* localVarToReplace_group = malloc(sizeOfPathParams_group);
    sprintf(localVarToReplace_group, "{%s}", "group");

    localVarPath = strReplace(localVarPath, localVarToReplace_group, group);

    // Path Params
    long sizeOfPathParams_version = strlen(group) + 3 + strlen(version) + 3 + strlen(plural) + 3 + strlen("{ version }");
    if (version == NULL) {
        goto end;
    }
    char* localVarToReplace_version = malloc(sizeOfPathParams_version);
    sprintf(localVarToReplace_version, "{%s}", "version");

    localVarPath = strReplace(localVarPath, localVarToReplace_version, version);

    // Path Params
    long sizeOfPathParams_plural = strlen(group) + 3 + strlen(version) + 3 + strlen(plural) + 3 + strlen("{ plural }");
    if (plural == NULL) {
        goto end;
    }
    char* localVarToReplace_plural = malloc(sizeOfPathParams_plural);
    sprintf(localVarToReplace_plural, "{%s}", "plural");

    localVarPath = strReplace(localVarPath, localVarToReplace_plural, plural);



    // query parameters
    char *keyQuery_pretty;
    char * valueQuery_pretty;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty) {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters, keyPairQuery_pretty);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body;
    if (body != NULL) {
        //string
        localVarSingleItemJSON_body = object_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
    }
    list_addElement(localVarHeaderType, "application/json"); //produces
    apiClient_invoke(apiClient,
        localVarPath,
        localVarQueryParameters,
        localVarHeaderParameters,
        localVarFormParameters,
        localVarHeaderType,
        localVarContentType,
        localVarBodyParameters,
        "POST");

    if (apiClient->response_code == 201) {
        printf("%s\n", "Created");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n", "Unauthorized");
    }
    //nonprimitive not_ container
    cJSON *CustomObjectsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(CustomObjectsAPIlocalVarJSON);
    cJSON_Delete(CustomObjectsAPIlocalVarJSON);
    if (elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);


    list_free(localVarHeaderType);

    free(localVarPath);
    free(localVarToReplace_group);
    free(localVarToReplace_version);
    free(localVarToReplace_plural);
    cJSON_Delete(localVarSingleItemJSON_body);
    free(localVarBodyParameters);
    free(keyQuery_pretty);
    free(valueQuery_pretty);
    keyValuePair_free(keyPairQuery_pretty);
    return elementToReturn;
end:
    return NULL;

}

// Deletes the specified cluster scoped custom object
//
object_t*
CustomObjectsAPI_deleteClusterCustomObject(apiClient_t *apiClient ,char * group ,char * version ,char * plural ,char * name ,v1_delete_options_t * body ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/{group}/{version}/{plural}/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/{group}/{version}/{plural}/{name}");


    // Path Params
    long sizeOfPathParams_group = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ group }");
    if(group == NULL) {
        goto end;
    }
    char* localVarToReplace_group = malloc(sizeOfPathParams_group);
    sprintf(localVarToReplace_group, "{%s}", "group");

    localVarPath = strReplace(localVarPath, localVarToReplace_group, group);

    // Path Params
    long sizeOfPathParams_version = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ version }");
    if(version == NULL) {
        goto end;
    }
    char* localVarToReplace_version = malloc(sizeOfPathParams_version);
    sprintf(localVarToReplace_version, "{%s}", "version");

    localVarPath = strReplace(localVarPath, localVarToReplace_version, version);

    // Path Params
    long sizeOfPathParams_plural = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ plural }");
    if(plural == NULL) {
        goto end;
    }
    char* localVarToReplace_plural = malloc(sizeOfPathParams_plural);
    sprintf(localVarToReplace_plural, "{%s}", "plural");

    localVarPath = strReplace(localVarPath, localVarToReplace_plural, plural);

    // Path Params
    long sizeOfPathParams_name = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);



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
    cJSON *CustomObjectsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(CustomObjectsAPIlocalVarJSON);
    cJSON_Delete(CustomObjectsAPIlocalVarJSON);
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
    free(localVarToReplace_group);
    free(localVarToReplace_version);
    free(localVarToReplace_plural);
    free(localVarToReplace_name);
    cJSON_Delete(localVarSingleItemJSON_body);
    free(localVarBodyParameters);
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

// Deletes the specified namespace scoped custom object
//
object_t*
CustomObjectsAPI_deleteNamespacedCustomObject(apiClient_t *apiClient ,char * group ,char * version ,char * namespace ,char * plural ,char * name ,v1_delete_options_t * body ,int gracePeriodSeconds ,int orphanDependents ,char * propagationPolicy)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/{group}/{version}/namespaces/{namespace}/{plural}/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/{group}/{version}/namespaces/{namespace}/{plural}/{name}");


    // Path Params
    long sizeOfPathParams_group = strlen(group)+3 + strlen(version)+3 + strlen(namespace)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ group }");
    if(group == NULL) {
        goto end;
    }
    char* localVarToReplace_group = malloc(sizeOfPathParams_group);
    sprintf(localVarToReplace_group, "{%s}", "group");

    localVarPath = strReplace(localVarPath, localVarToReplace_group, group);

    // Path Params
    long sizeOfPathParams_version = strlen(group)+3 + strlen(version)+3 + strlen(namespace)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ version }");
    if(version == NULL) {
        goto end;
    }
    char* localVarToReplace_version = malloc(sizeOfPathParams_version);
    sprintf(localVarToReplace_version, "{%s}", "version");

    localVarPath = strReplace(localVarPath, localVarToReplace_version, version);

    // Path Params
    long sizeOfPathParams_namespace = strlen(group)+3 + strlen(version)+3 + strlen(namespace)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);

    // Path Params
    long sizeOfPathParams_plural = strlen(group)+3 + strlen(version)+3 + strlen(namespace)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ plural }");
    if(plural == NULL) {
        goto end;
    }
    char* localVarToReplace_plural = malloc(sizeOfPathParams_plural);
    sprintf(localVarToReplace_plural, "{%s}", "plural");

    localVarPath = strReplace(localVarPath, localVarToReplace_plural, plural);

    // Path Params
    long sizeOfPathParams_name = strlen(group)+3 + strlen(version)+3 + strlen(namespace)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);



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
    cJSON *CustomObjectsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(CustomObjectsAPIlocalVarJSON);
    cJSON_Delete(CustomObjectsAPIlocalVarJSON);
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
    free(localVarToReplace_group);
    free(localVarToReplace_version);
    free(localVarToReplace_namespace);
    free(localVarToReplace_plural);
    free(localVarToReplace_name);
    cJSON_Delete(localVarSingleItemJSON_body);
    free(localVarBodyParameters);
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

// Returns a cluster scoped custom object
//
object_t*
CustomObjectsAPI_getClusterCustomObject(apiClient_t *apiClient ,char * group ,char * version ,char * plural ,char * name)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/{group}/{version}/{plural}/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/{group}/{version}/{plural}/{name}");


    // Path Params
    long sizeOfPathParams_group = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ group }");
    if(group == NULL) {
        goto end;
    }
    char* localVarToReplace_group = malloc(sizeOfPathParams_group);
    sprintf(localVarToReplace_group, "{%s}", "group");

    localVarPath = strReplace(localVarPath, localVarToReplace_group, group);

    // Path Params
    long sizeOfPathParams_version = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ version }");
    if(version == NULL) {
        goto end;
    }
    char* localVarToReplace_version = malloc(sizeOfPathParams_version);
    sprintf(localVarToReplace_version, "{%s}", "version");

    localVarPath = strReplace(localVarPath, localVarToReplace_version, version);

    // Path Params
    long sizeOfPathParams_plural = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ plural }");
    if(plural == NULL) {
        goto end;
    }
    char* localVarToReplace_plural = malloc(sizeOfPathParams_plural);
    sprintf(localVarToReplace_plural, "{%s}", "plural");

    localVarPath = strReplace(localVarPath, localVarToReplace_plural, plural);

    // Path Params
    long sizeOfPathParams_name = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);


    list_addElement(localVarHeaderType,"application/json"); //produces
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
        printf("%s\n","A single Resource");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not_ container
    cJSON *CustomObjectsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(CustomObjectsAPIlocalVarJSON);
    cJSON_Delete(CustomObjectsAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_group);
    free(localVarToReplace_version);
    free(localVarToReplace_plural);
    free(localVarToReplace_name);
    return elementToReturn;
end:
    return NULL;

}

// read scale of the specified custom object
//
object_t*
CustomObjectsAPI_getClusterCustomObjectScale(apiClient_t *apiClient ,char * group ,char * version ,char * plural ,char * name)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/{group}/{version}/{plural}/{name}/scale")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/{group}/{version}/{plural}/{name}/scale");


    // Path Params
    long sizeOfPathParams_group = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ group }");
    if(group == NULL) {
        goto end;
    }
    char* localVarToReplace_group = malloc(sizeOfPathParams_group);
    sprintf(localVarToReplace_group, "{%s}", "group");

    localVarPath = strReplace(localVarPath, localVarToReplace_group, group);

    // Path Params
    long sizeOfPathParams_version = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ version }");
    if(version == NULL) {
        goto end;
    }
    char* localVarToReplace_version = malloc(sizeOfPathParams_version);
    sprintf(localVarToReplace_version, "{%s}", "version");

    localVarPath = strReplace(localVarPath, localVarToReplace_version, version);

    // Path Params
    long sizeOfPathParams_plural = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ plural }");
    if(plural == NULL) {
        goto end;
    }
    char* localVarToReplace_plural = malloc(sizeOfPathParams_plural);
    sprintf(localVarToReplace_plural, "{%s}", "plural");

    localVarPath = strReplace(localVarPath, localVarToReplace_plural, plural);

    // Path Params
    long sizeOfPathParams_name = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);


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
    cJSON *CustomObjectsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(CustomObjectsAPIlocalVarJSON);
    cJSON_Delete(CustomObjectsAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_group);
    free(localVarToReplace_version);
    free(localVarToReplace_plural);
    free(localVarToReplace_name);
    return elementToReturn;
end:
    return NULL;

}

// read status of the specified cluster scoped custom object
//
object_t*
CustomObjectsAPI_getClusterCustomObjectStatus(apiClient_t *apiClient ,char * group ,char * version ,char * plural ,char * name)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/{group}/{version}/{plural}/{name}/status")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/{group}/{version}/{plural}/{name}/status");


    // Path Params
    long sizeOfPathParams_group = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ group }");
    if(group == NULL) {
        goto end;
    }
    char* localVarToReplace_group = malloc(sizeOfPathParams_group);
    sprintf(localVarToReplace_group, "{%s}", "group");

    localVarPath = strReplace(localVarPath, localVarToReplace_group, group);

    // Path Params
    long sizeOfPathParams_version = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ version }");
    if(version == NULL) {
        goto end;
    }
    char* localVarToReplace_version = malloc(sizeOfPathParams_version);
    sprintf(localVarToReplace_version, "{%s}", "version");

    localVarPath = strReplace(localVarPath, localVarToReplace_version, version);

    // Path Params
    long sizeOfPathParams_plural = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ plural }");
    if(plural == NULL) {
        goto end;
    }
    char* localVarToReplace_plural = malloc(sizeOfPathParams_plural);
    sprintf(localVarToReplace_plural, "{%s}", "plural");

    localVarPath = strReplace(localVarPath, localVarToReplace_plural, plural);

    // Path Params
    long sizeOfPathParams_name = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);


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
    cJSON *CustomObjectsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(CustomObjectsAPIlocalVarJSON);
    cJSON_Delete(CustomObjectsAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_group);
    free(localVarToReplace_version);
    free(localVarToReplace_plural);
    free(localVarToReplace_name);
    return elementToReturn;
end:
    return NULL;

}

// Returns a namespace scoped custom object
//
object_t*
CustomObjectsAPI_getNamespacedCustomObject(apiClient_t *apiClient ,char * group ,char * version ,char * namespace ,char * plural ,char * name)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/{group}/{version}/namespaces/{namespace}/{plural}/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/{group}/{version}/namespaces/{namespace}/{plural}/{name}");


    // Path Params
    long sizeOfPathParams_group = strlen(group)+3 + strlen(version)+3 + strlen(namespace)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ group }");
    if(group == NULL) {
        goto end;
    }
    char* localVarToReplace_group = malloc(sizeOfPathParams_group);
    sprintf(localVarToReplace_group, "{%s}", "group");

    localVarPath = strReplace(localVarPath, localVarToReplace_group, group);

    // Path Params
    long sizeOfPathParams_version = strlen(group)+3 + strlen(version)+3 + strlen(namespace)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ version }");
    if(version == NULL) {
        goto end;
    }
    char* localVarToReplace_version = malloc(sizeOfPathParams_version);
    sprintf(localVarToReplace_version, "{%s}", "version");

    localVarPath = strReplace(localVarPath, localVarToReplace_version, version);

    // Path Params
    long sizeOfPathParams_namespace = strlen(group)+3 + strlen(version)+3 + strlen(namespace)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);

    // Path Params
    long sizeOfPathParams_plural = strlen(group)+3 + strlen(version)+3 + strlen(namespace)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ plural }");
    if(plural == NULL) {
        goto end;
    }
    char* localVarToReplace_plural = malloc(sizeOfPathParams_plural);
    sprintf(localVarToReplace_plural, "{%s}", "plural");

    localVarPath = strReplace(localVarPath, localVarToReplace_plural, plural);

    // Path Params
    long sizeOfPathParams_name = strlen(group)+3 + strlen(version)+3 + strlen(namespace)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);


    list_addElement(localVarHeaderType,"application/json"); //produces
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
        printf("%s\n","A single Resource");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not_ container
    cJSON *CustomObjectsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(CustomObjectsAPIlocalVarJSON);
    cJSON_Delete(CustomObjectsAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_group);
    free(localVarToReplace_version);
    free(localVarToReplace_namespace);
    free(localVarToReplace_plural);
    free(localVarToReplace_name);
    return elementToReturn;
end:
    return NULL;

}

// read scale of the specified namespace scoped custom object
//
object_t*
CustomObjectsAPI_getNamespacedCustomObjectScale(apiClient_t *apiClient ,char * group ,char * version ,char * namespace ,char * plural ,char * name)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/{group}/{version}/namespaces/{namespace}/{plural}/{name}/scale")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/{group}/{version}/namespaces/{namespace}/{plural}/{name}/scale");


    // Path Params
    long sizeOfPathParams_group = strlen(group)+3 + strlen(version)+3 + strlen(namespace)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ group }");
    if(group == NULL) {
        goto end;
    }
    char* localVarToReplace_group = malloc(sizeOfPathParams_group);
    sprintf(localVarToReplace_group, "{%s}", "group");

    localVarPath = strReplace(localVarPath, localVarToReplace_group, group);

    // Path Params
    long sizeOfPathParams_version = strlen(group)+3 + strlen(version)+3 + strlen(namespace)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ version }");
    if(version == NULL) {
        goto end;
    }
    char* localVarToReplace_version = malloc(sizeOfPathParams_version);
    sprintf(localVarToReplace_version, "{%s}", "version");

    localVarPath = strReplace(localVarPath, localVarToReplace_version, version);

    // Path Params
    long sizeOfPathParams_namespace = strlen(group)+3 + strlen(version)+3 + strlen(namespace)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);

    // Path Params
    long sizeOfPathParams_plural = strlen(group)+3 + strlen(version)+3 + strlen(namespace)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ plural }");
    if(plural == NULL) {
        goto end;
    }
    char* localVarToReplace_plural = malloc(sizeOfPathParams_plural);
    sprintf(localVarToReplace_plural, "{%s}", "plural");

    localVarPath = strReplace(localVarPath, localVarToReplace_plural, plural);

    // Path Params
    long sizeOfPathParams_name = strlen(group)+3 + strlen(version)+3 + strlen(namespace)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);


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
    cJSON *CustomObjectsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(CustomObjectsAPIlocalVarJSON);
    cJSON_Delete(CustomObjectsAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_group);
    free(localVarToReplace_version);
    free(localVarToReplace_namespace);
    free(localVarToReplace_plural);
    free(localVarToReplace_name);
    return elementToReturn;
end:
    return NULL;

}

// read status of the specified namespace scoped custom object
//
object_t*
CustomObjectsAPI_getNamespacedCustomObjectStatus(apiClient_t *apiClient ,char * group ,char * version ,char * namespace ,char * plural ,char * name)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/{group}/{version}/namespaces/{namespace}/{plural}/{name}/status")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/{group}/{version}/namespaces/{namespace}/{plural}/{name}/status");


    // Path Params
    long sizeOfPathParams_group = strlen(group)+3 + strlen(version)+3 + strlen(namespace)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ group }");
    if(group == NULL) {
        goto end;
    }
    char* localVarToReplace_group = malloc(sizeOfPathParams_group);
    sprintf(localVarToReplace_group, "{%s}", "group");

    localVarPath = strReplace(localVarPath, localVarToReplace_group, group);

    // Path Params
    long sizeOfPathParams_version = strlen(group)+3 + strlen(version)+3 + strlen(namespace)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ version }");
    if(version == NULL) {
        goto end;
    }
    char* localVarToReplace_version = malloc(sizeOfPathParams_version);
    sprintf(localVarToReplace_version, "{%s}", "version");

    localVarPath = strReplace(localVarPath, localVarToReplace_version, version);

    // Path Params
    long sizeOfPathParams_namespace = strlen(group)+3 + strlen(version)+3 + strlen(namespace)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);

    // Path Params
    long sizeOfPathParams_plural = strlen(group)+3 + strlen(version)+3 + strlen(namespace)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ plural }");
    if(plural == NULL) {
        goto end;
    }
    char* localVarToReplace_plural = malloc(sizeOfPathParams_plural);
    sprintf(localVarToReplace_plural, "{%s}", "plural");

    localVarPath = strReplace(localVarPath, localVarToReplace_plural, plural);

    // Path Params
    long sizeOfPathParams_name = strlen(group)+3 + strlen(version)+3 + strlen(namespace)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);


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
    cJSON *CustomObjectsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(CustomObjectsAPIlocalVarJSON);
    cJSON_Delete(CustomObjectsAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_group);
    free(localVarToReplace_version);
    free(localVarToReplace_namespace);
    free(localVarToReplace_plural);
    free(localVarToReplace_name);
    return elementToReturn;
end:
    return NULL;

}

// list or watch cluster scoped custom objects
//
object_t*
CustomObjectsAPI_listClusterCustomObject(apiClient_t *apiClient ,char * group ,char * version ,char * plural ,char * pretty ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/{group}/{version}/{plural}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/{group}/{version}/{plural}");


    // Path Params
    long sizeOfPathParams_group = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen("{ group }");
    if(group == NULL) {
        goto end;
    }
    char* localVarToReplace_group = malloc(sizeOfPathParams_group);
    sprintf(localVarToReplace_group, "{%s}", "group");

    localVarPath = strReplace(localVarPath, localVarToReplace_group, group);

    // Path Params
    long sizeOfPathParams_version = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen("{ version }");
    if(version == NULL) {
        goto end;
    }
    char* localVarToReplace_version = malloc(sizeOfPathParams_version);
    sprintf(localVarToReplace_version, "{%s}", "version");

    localVarPath = strReplace(localVarPath, localVarToReplace_version, version);

    // Path Params
    long sizeOfPathParams_plural = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen("{ plural }");
    if(plural == NULL) {
        goto end;
    }
    char* localVarToReplace_plural = malloc(sizeOfPathParams_plural);
    sprintf(localVarToReplace_plural, "{%s}", "plural");

    localVarPath = strReplace(localVarPath, localVarToReplace_plural, plural);



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
    list_addElement(localVarHeaderType,"application/json;stream=watch"); //produces
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
    cJSON *CustomObjectsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(CustomObjectsAPIlocalVarJSON);
    cJSON_Delete(CustomObjectsAPIlocalVarJSON);
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
    free(localVarToReplace_group);
    free(localVarToReplace_version);
    free(localVarToReplace_plural);
    free(keyQuery_pretty);
    free(valueQuery_pretty);
    keyValuePair_free(keyPairQuery_pretty);
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

// list or watch namespace scoped custom objects
//
object_t*
CustomObjectsAPI_listNamespacedCustomObject(apiClient_t *apiClient ,char * group ,char * version ,char * namespace ,char * plural ,char * pretty ,char * continue_ ,char * fieldSelector ,char * labelSelector ,int limit ,char * resourceVersion ,int timeoutSeconds ,int watch)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/{group}/{version}/namespaces/{namespace}/{plural}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/{group}/{version}/namespaces/{namespace}/{plural}");


    // Path Params
    long sizeOfPathParams_group = strlen(group)+3 + strlen(version)+3 + strlen(namespace)+3 + strlen(plural)+3 + strlen("{ group }");
    if(group == NULL) {
        goto end;
    }
    char* localVarToReplace_group = malloc(sizeOfPathParams_group);
    sprintf(localVarToReplace_group, "{%s}", "group");

    localVarPath = strReplace(localVarPath, localVarToReplace_group, group);

    // Path Params
    long sizeOfPathParams_version = strlen(group)+3 + strlen(version)+3 + strlen(namespace)+3 + strlen(plural)+3 + strlen("{ version }");
    if(version == NULL) {
        goto end;
    }
    char* localVarToReplace_version = malloc(sizeOfPathParams_version);
    sprintf(localVarToReplace_version, "{%s}", "version");

    localVarPath = strReplace(localVarPath, localVarToReplace_version, version);

    // Path Params
    long sizeOfPathParams_namespace = strlen(group)+3 + strlen(version)+3 + strlen(namespace)+3 + strlen(plural)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);

    // Path Params
    long sizeOfPathParams_plural = strlen(group)+3 + strlen(version)+3 + strlen(namespace)+3 + strlen(plural)+3 + strlen("{ plural }");
    if(plural == NULL) {
        goto end;
    }
    char* localVarToReplace_plural = malloc(sizeOfPathParams_plural);
    sprintf(localVarToReplace_plural, "{%s}", "plural");

    localVarPath = strReplace(localVarPath, localVarToReplace_plural, plural);



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
    list_addElement(localVarHeaderType,"application/json;stream=watch"); //produces
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
    cJSON *CustomObjectsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(CustomObjectsAPIlocalVarJSON);
    cJSON_Delete(CustomObjectsAPIlocalVarJSON);
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
    free(localVarToReplace_group);
    free(localVarToReplace_version);
    free(localVarToReplace_namespace);
    free(localVarToReplace_plural);
    free(keyQuery_pretty);
    free(valueQuery_pretty);
    keyValuePair_free(keyPairQuery_pretty);
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

// patch the specified cluster scoped custom object
//
object_t*
CustomObjectsAPI_patchClusterCustomObject(apiClient_t *apiClient ,char * group ,char * version ,char * plural ,char * name , object_t * body)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = list_create();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/{group}/{version}/{plural}/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/{group}/{version}/{plural}/{name}");


    // Path Params
    long sizeOfPathParams_group = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ group }");
    if(group == NULL) {
        goto end;
    }
    char* localVarToReplace_group = malloc(sizeOfPathParams_group);
    sprintf(localVarToReplace_group, "{%s}", "group");

    localVarPath = strReplace(localVarPath, localVarToReplace_group, group);

    // Path Params
    long sizeOfPathParams_version = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ version }");
    if(version == NULL) {
        goto end;
    }
    char* localVarToReplace_version = malloc(sizeOfPathParams_version);
    sprintf(localVarToReplace_version, "{%s}", "version");

    localVarPath = strReplace(localVarPath, localVarToReplace_version, version);

    // Path Params
    long sizeOfPathParams_plural = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ plural }");
    if(plural == NULL) {
        goto end;
    }
    char* localVarToReplace_plural = malloc(sizeOfPathParams_plural);
    sprintf(localVarToReplace_plural, "{%s}", "plural");

    localVarPath = strReplace(localVarPath, localVarToReplace_plural, plural);

    // Path Params
    long sizeOfPathParams_name = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);



    // Body Param
    cJSON *localVarSingleItemJSON_body;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = object_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/json-patch+json"); //consumes
    list_addElement(localVarContentType,"application/merge-patch+json"); //consumes
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
    cJSON *CustomObjectsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(CustomObjectsAPIlocalVarJSON);
    cJSON_Delete(CustomObjectsAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    
    
    
    list_free(localVarHeaderType);
    list_free(localVarContentType);
    free(localVarPath);
    free(localVarToReplace_group);
    free(localVarToReplace_version);
    free(localVarToReplace_plural);
    free(localVarToReplace_name);
    cJSON_Delete(localVarSingleItemJSON_body);
    free(localVarBodyParameters);
    return elementToReturn;
end:
    return NULL;

}

// partially update scale of the specified cluster scoped custom object
//
object_t*
CustomObjectsAPI_patchClusterCustomObjectScale(apiClient_t *apiClient ,char * group ,char * version ,char * plural ,char * name , object_t * body)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = list_create();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/{group}/{version}/{plural}/{name}/scale")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/{group}/{version}/{plural}/{name}/scale");


    // Path Params
    long sizeOfPathParams_group = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ group }");
    if(group == NULL) {
        goto end;
    }
    char* localVarToReplace_group = malloc(sizeOfPathParams_group);
    sprintf(localVarToReplace_group, "{%s}", "group");

    localVarPath = strReplace(localVarPath, localVarToReplace_group, group);

    // Path Params
    long sizeOfPathParams_version = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ version }");
    if(version == NULL) {
        goto end;
    }
    char* localVarToReplace_version = malloc(sizeOfPathParams_version);
    sprintf(localVarToReplace_version, "{%s}", "version");

    localVarPath = strReplace(localVarPath, localVarToReplace_version, version);

    // Path Params
    long sizeOfPathParams_plural = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ plural }");
    if(plural == NULL) {
        goto end;
    }
    char* localVarToReplace_plural = malloc(sizeOfPathParams_plural);
    sprintf(localVarToReplace_plural, "{%s}", "plural");

    localVarPath = strReplace(localVarPath, localVarToReplace_plural, plural);

    // Path Params
    long sizeOfPathParams_name = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);



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
    cJSON *CustomObjectsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(CustomObjectsAPIlocalVarJSON);
    cJSON_Delete(CustomObjectsAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    
    
    
    list_free(localVarHeaderType);
    list_free(localVarContentType);
    free(localVarPath);
    free(localVarToReplace_group);
    free(localVarToReplace_version);
    free(localVarToReplace_plural);
    free(localVarToReplace_name);
    cJSON_Delete(localVarSingleItemJSON_body);
    free(localVarBodyParameters);
    return elementToReturn;
end:
    return NULL;

}

// partially update status of the specified cluster scoped custom object
//
object_t*
CustomObjectsAPI_patchClusterCustomObjectStatus(apiClient_t *apiClient ,char * group ,char * version ,char * plural ,char * name , object_t * body)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = list_create();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/{group}/{version}/{plural}/{name}/status")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/{group}/{version}/{plural}/{name}/status");


    // Path Params
    long sizeOfPathParams_group = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ group }");
    if(group == NULL) {
        goto end;
    }
    char* localVarToReplace_group = malloc(sizeOfPathParams_group);
    sprintf(localVarToReplace_group, "{%s}", "group");

    localVarPath = strReplace(localVarPath, localVarToReplace_group, group);

    // Path Params
    long sizeOfPathParams_version = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ version }");
    if(version == NULL) {
        goto end;
    }
    char* localVarToReplace_version = malloc(sizeOfPathParams_version);
    sprintf(localVarToReplace_version, "{%s}", "version");

    localVarPath = strReplace(localVarPath, localVarToReplace_version, version);

    // Path Params
    long sizeOfPathParams_plural = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ plural }");
    if(plural == NULL) {
        goto end;
    }
    char* localVarToReplace_plural = malloc(sizeOfPathParams_plural);
    sprintf(localVarToReplace_plural, "{%s}", "plural");

    localVarPath = strReplace(localVarPath, localVarToReplace_plural, plural);

    // Path Params
    long sizeOfPathParams_name = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);



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
    cJSON *CustomObjectsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(CustomObjectsAPIlocalVarJSON);
    cJSON_Delete(CustomObjectsAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    
    
    
    list_free(localVarHeaderType);
    list_free(localVarContentType);
    free(localVarPath);
    free(localVarToReplace_group);
    free(localVarToReplace_version);
    free(localVarToReplace_plural);
    free(localVarToReplace_name);
    cJSON_Delete(localVarSingleItemJSON_body);
    free(localVarBodyParameters);
    return elementToReturn;
end:
    return NULL;

}

// patch the specified namespace scoped custom object
//
object_t*
CustomObjectsAPI_patchNamespacedCustomObject(apiClient_t *apiClient ,char * group ,char * version ,char * namespace ,char * plural ,char * name , object_t * body)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = list_create();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/{group}/{version}/namespaces/{namespace}/{plural}/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/{group}/{version}/namespaces/{namespace}/{plural}/{name}");


    // Path Params
    long sizeOfPathParams_group = strlen(group)+3 + strlen(version)+3 + strlen(namespace)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ group }");
    if(group == NULL) {
        goto end;
    }
    char* localVarToReplace_group = malloc(sizeOfPathParams_group);
    sprintf(localVarToReplace_group, "{%s}", "group");

    localVarPath = strReplace(localVarPath, localVarToReplace_group, group);

    // Path Params
    long sizeOfPathParams_version = strlen(group)+3 + strlen(version)+3 + strlen(namespace)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ version }");
    if(version == NULL) {
        goto end;
    }
    char* localVarToReplace_version = malloc(sizeOfPathParams_version);
    sprintf(localVarToReplace_version, "{%s}", "version");

    localVarPath = strReplace(localVarPath, localVarToReplace_version, version);

    // Path Params
    long sizeOfPathParams_namespace = strlen(group)+3 + strlen(version)+3 + strlen(namespace)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);

    // Path Params
    long sizeOfPathParams_plural = strlen(group)+3 + strlen(version)+3 + strlen(namespace)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ plural }");
    if(plural == NULL) {
        goto end;
    }
    char* localVarToReplace_plural = malloc(sizeOfPathParams_plural);
    sprintf(localVarToReplace_plural, "{%s}", "plural");

    localVarPath = strReplace(localVarPath, localVarToReplace_plural, plural);

    // Path Params
    long sizeOfPathParams_name = strlen(group)+3 + strlen(version)+3 + strlen(namespace)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);



    // Body Param
    cJSON *localVarSingleItemJSON_body;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = object_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/json-patch+json"); //consumes
    list_addElement(localVarContentType,"application/merge-patch+json"); //consumes
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
    cJSON *CustomObjectsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(CustomObjectsAPIlocalVarJSON);
    cJSON_Delete(CustomObjectsAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    
    
    
    list_free(localVarHeaderType);
    list_free(localVarContentType);
    free(localVarPath);
    free(localVarToReplace_group);
    free(localVarToReplace_version);
    free(localVarToReplace_namespace);
    free(localVarToReplace_plural);
    free(localVarToReplace_name);
    cJSON_Delete(localVarSingleItemJSON_body);
    free(localVarBodyParameters);
    return elementToReturn;
end:
    return NULL;

}

// partially update scale of the specified namespace scoped custom object
//
object_t*
CustomObjectsAPI_patchNamespacedCustomObjectScale(apiClient_t *apiClient ,char * group ,char * version ,char * namespace ,char * plural ,char * name , object_t * body)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = list_create();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/{group}/{version}/namespaces/{namespace}/{plural}/{name}/scale")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/{group}/{version}/namespaces/{namespace}/{plural}/{name}/scale");


    // Path Params
    long sizeOfPathParams_group = strlen(group)+3 + strlen(version)+3 + strlen(namespace)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ group }");
    if(group == NULL) {
        goto end;
    }
    char* localVarToReplace_group = malloc(sizeOfPathParams_group);
    sprintf(localVarToReplace_group, "{%s}", "group");

    localVarPath = strReplace(localVarPath, localVarToReplace_group, group);

    // Path Params
    long sizeOfPathParams_version = strlen(group)+3 + strlen(version)+3 + strlen(namespace)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ version }");
    if(version == NULL) {
        goto end;
    }
    char* localVarToReplace_version = malloc(sizeOfPathParams_version);
    sprintf(localVarToReplace_version, "{%s}", "version");

    localVarPath = strReplace(localVarPath, localVarToReplace_version, version);

    // Path Params
    long sizeOfPathParams_namespace = strlen(group)+3 + strlen(version)+3 + strlen(namespace)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);

    // Path Params
    long sizeOfPathParams_plural = strlen(group)+3 + strlen(version)+3 + strlen(namespace)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ plural }");
    if(plural == NULL) {
        goto end;
    }
    char* localVarToReplace_plural = malloc(sizeOfPathParams_plural);
    sprintf(localVarToReplace_plural, "{%s}", "plural");

    localVarPath = strReplace(localVarPath, localVarToReplace_plural, plural);

    // Path Params
    long sizeOfPathParams_name = strlen(group)+3 + strlen(version)+3 + strlen(namespace)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);



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
    cJSON *CustomObjectsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(CustomObjectsAPIlocalVarJSON);
    cJSON_Delete(CustomObjectsAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    
    
    
    list_free(localVarHeaderType);
    list_free(localVarContentType);
    free(localVarPath);
    free(localVarToReplace_group);
    free(localVarToReplace_version);
    free(localVarToReplace_namespace);
    free(localVarToReplace_plural);
    free(localVarToReplace_name);
    cJSON_Delete(localVarSingleItemJSON_body);
    free(localVarBodyParameters);
    return elementToReturn;
end:
    return NULL;

}

// partially update status of the specified namespace scoped custom object
//
object_t*
CustomObjectsAPI_patchNamespacedCustomObjectStatus(apiClient_t *apiClient ,char * group ,char * version ,char * namespace ,char * plural ,char * name , object_t * body)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = list_create();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/{group}/{version}/namespaces/{namespace}/{plural}/{name}/status")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/{group}/{version}/namespaces/{namespace}/{plural}/{name}/status");


    // Path Params
    long sizeOfPathParams_group = strlen(group)+3 + strlen(version)+3 + strlen(namespace)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ group }");
    if(group == NULL) {
        goto end;
    }
    char* localVarToReplace_group = malloc(sizeOfPathParams_group);
    sprintf(localVarToReplace_group, "{%s}", "group");

    localVarPath = strReplace(localVarPath, localVarToReplace_group, group);

    // Path Params
    long sizeOfPathParams_version = strlen(group)+3 + strlen(version)+3 + strlen(namespace)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ version }");
    if(version == NULL) {
        goto end;
    }
    char* localVarToReplace_version = malloc(sizeOfPathParams_version);
    sprintf(localVarToReplace_version, "{%s}", "version");

    localVarPath = strReplace(localVarPath, localVarToReplace_version, version);

    // Path Params
    long sizeOfPathParams_namespace = strlen(group)+3 + strlen(version)+3 + strlen(namespace)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);

    // Path Params
    long sizeOfPathParams_plural = strlen(group)+3 + strlen(version)+3 + strlen(namespace)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ plural }");
    if(plural == NULL) {
        goto end;
    }
    char* localVarToReplace_plural = malloc(sizeOfPathParams_plural);
    sprintf(localVarToReplace_plural, "{%s}", "plural");

    localVarPath = strReplace(localVarPath, localVarToReplace_plural, plural);

    // Path Params
    long sizeOfPathParams_name = strlen(group)+3 + strlen(version)+3 + strlen(namespace)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);



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
    cJSON *CustomObjectsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(CustomObjectsAPIlocalVarJSON);
    cJSON_Delete(CustomObjectsAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    
    
    
    list_free(localVarHeaderType);
    list_free(localVarContentType);
    free(localVarPath);
    free(localVarToReplace_group);
    free(localVarToReplace_version);
    free(localVarToReplace_namespace);
    free(localVarToReplace_plural);
    free(localVarToReplace_name);
    cJSON_Delete(localVarSingleItemJSON_body);
    free(localVarBodyParameters);
    return elementToReturn;
end:
    return NULL;

}

// replace the specified cluster scoped custom object
//
object_t*
CustomObjectsAPI_replaceClusterCustomObject(apiClient_t *apiClient ,char * group ,char * version ,char * plural ,char * name , object_t * body)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/{group}/{version}/{plural}/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/{group}/{version}/{plural}/{name}");


    // Path Params
    long sizeOfPathParams_group = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ group }");
    if(group == NULL) {
        goto end;
    }
    char* localVarToReplace_group = malloc(sizeOfPathParams_group);
    sprintf(localVarToReplace_group, "{%s}", "group");

    localVarPath = strReplace(localVarPath, localVarToReplace_group, group);

    // Path Params
    long sizeOfPathParams_version = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ version }");
    if(version == NULL) {
        goto end;
    }
    char* localVarToReplace_version = malloc(sizeOfPathParams_version);
    sprintf(localVarToReplace_version, "{%s}", "version");

    localVarPath = strReplace(localVarPath, localVarToReplace_version, version);

    // Path Params
    long sizeOfPathParams_plural = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ plural }");
    if(plural == NULL) {
        goto end;
    }
    char* localVarToReplace_plural = malloc(sizeOfPathParams_plural);
    sprintf(localVarToReplace_plural, "{%s}", "plural");

    localVarPath = strReplace(localVarPath, localVarToReplace_plural, plural);

    // Path Params
    long sizeOfPathParams_name = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);



    // Body Param
    cJSON *localVarSingleItemJSON_body;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = object_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
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
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not_ container
    cJSON *CustomObjectsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(CustomObjectsAPIlocalVarJSON);
    cJSON_Delete(CustomObjectsAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_group);
    free(localVarToReplace_version);
    free(localVarToReplace_plural);
    free(localVarToReplace_name);
    cJSON_Delete(localVarSingleItemJSON_body);
    free(localVarBodyParameters);
    return elementToReturn;
end:
    return NULL;

}

// replace scale of the specified cluster scoped custom object
//
object_t*
CustomObjectsAPI_replaceClusterCustomObjectScale(apiClient_t *apiClient ,char * group ,char * version ,char * plural ,char * name , object_t * body)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/{group}/{version}/{plural}/{name}/scale")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/{group}/{version}/{plural}/{name}/scale");


    // Path Params
    long sizeOfPathParams_group = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ group }");
    if(group == NULL) {
        goto end;
    }
    char* localVarToReplace_group = malloc(sizeOfPathParams_group);
    sprintf(localVarToReplace_group, "{%s}", "group");

    localVarPath = strReplace(localVarPath, localVarToReplace_group, group);

    // Path Params
    long sizeOfPathParams_version = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ version }");
    if(version == NULL) {
        goto end;
    }
    char* localVarToReplace_version = malloc(sizeOfPathParams_version);
    sprintf(localVarToReplace_version, "{%s}", "version");

    localVarPath = strReplace(localVarPath, localVarToReplace_version, version);

    // Path Params
    long sizeOfPathParams_plural = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ plural }");
    if(plural == NULL) {
        goto end;
    }
    char* localVarToReplace_plural = malloc(sizeOfPathParams_plural);
    sprintf(localVarToReplace_plural, "{%s}", "plural");

    localVarPath = strReplace(localVarPath, localVarToReplace_plural, plural);

    // Path Params
    long sizeOfPathParams_name = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);



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
    cJSON *CustomObjectsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(CustomObjectsAPIlocalVarJSON);
    cJSON_Delete(CustomObjectsAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_group);
    free(localVarToReplace_version);
    free(localVarToReplace_plural);
    free(localVarToReplace_name);
    cJSON_Delete(localVarSingleItemJSON_body);
    free(localVarBodyParameters);
    return elementToReturn;
end:
    return NULL;

}

// replace status of the cluster scoped specified custom object
//
object_t*
CustomObjectsAPI_replaceClusterCustomObjectStatus(apiClient_t *apiClient ,char * group ,char * version ,char * plural ,char * name , object_t * body)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/{group}/{version}/{plural}/{name}/status")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/{group}/{version}/{plural}/{name}/status");


    // Path Params
    long sizeOfPathParams_group = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ group }");
    if(group == NULL) {
        goto end;
    }
    char* localVarToReplace_group = malloc(sizeOfPathParams_group);
    sprintf(localVarToReplace_group, "{%s}", "group");

    localVarPath = strReplace(localVarPath, localVarToReplace_group, group);

    // Path Params
    long sizeOfPathParams_version = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ version }");
    if(version == NULL) {
        goto end;
    }
    char* localVarToReplace_version = malloc(sizeOfPathParams_version);
    sprintf(localVarToReplace_version, "{%s}", "version");

    localVarPath = strReplace(localVarPath, localVarToReplace_version, version);

    // Path Params
    long sizeOfPathParams_plural = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ plural }");
    if(plural == NULL) {
        goto end;
    }
    char* localVarToReplace_plural = malloc(sizeOfPathParams_plural);
    sprintf(localVarToReplace_plural, "{%s}", "plural");

    localVarPath = strReplace(localVarPath, localVarToReplace_plural, plural);

    // Path Params
    long sizeOfPathParams_name = strlen(group)+3 + strlen(version)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);



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
    cJSON *CustomObjectsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(CustomObjectsAPIlocalVarJSON);
    cJSON_Delete(CustomObjectsAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_group);
    free(localVarToReplace_version);
    free(localVarToReplace_plural);
    free(localVarToReplace_name);
    cJSON_Delete(localVarSingleItemJSON_body);
    free(localVarBodyParameters);
    return elementToReturn;
end:
    return NULL;

}

// replace the specified namespace scoped custom object
//
object_t*
CustomObjectsAPI_replaceNamespacedCustomObject(apiClient_t *apiClient ,char * group ,char * version ,char * namespace ,char * plural ,char * name , object_t * body)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/{group}/{version}/namespaces/{namespace}/{plural}/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/{group}/{version}/namespaces/{namespace}/{plural}/{name}");


    // Path Params
    long sizeOfPathParams_group = strlen(group)+3 + strlen(version)+3 + strlen(namespace)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ group }");
    if(group == NULL) {
        goto end;
    }
    char* localVarToReplace_group = malloc(sizeOfPathParams_group);
    sprintf(localVarToReplace_group, "{%s}", "group");

    localVarPath = strReplace(localVarPath, localVarToReplace_group, group);

    // Path Params
    long sizeOfPathParams_version = strlen(group)+3 + strlen(version)+3 + strlen(namespace)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ version }");
    if(version == NULL) {
        goto end;
    }
    char* localVarToReplace_version = malloc(sizeOfPathParams_version);
    sprintf(localVarToReplace_version, "{%s}", "version");

    localVarPath = strReplace(localVarPath, localVarToReplace_version, version);

    // Path Params
    long sizeOfPathParams_namespace = strlen(group)+3 + strlen(version)+3 + strlen(namespace)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);

    // Path Params
    long sizeOfPathParams_plural = strlen(group)+3 + strlen(version)+3 + strlen(namespace)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ plural }");
    if(plural == NULL) {
        goto end;
    }
    char* localVarToReplace_plural = malloc(sizeOfPathParams_plural);
    sprintf(localVarToReplace_plural, "{%s}", "plural");

    localVarPath = strReplace(localVarPath, localVarToReplace_plural, plural);

    // Path Params
    long sizeOfPathParams_name = strlen(group)+3 + strlen(version)+3 + strlen(namespace)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);



    // Body Param
    cJSON *localVarSingleItemJSON_body;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = object_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
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
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not_ container
    cJSON *CustomObjectsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(CustomObjectsAPIlocalVarJSON);
    cJSON_Delete(CustomObjectsAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_group);
    free(localVarToReplace_version);
    free(localVarToReplace_namespace);
    free(localVarToReplace_plural);
    free(localVarToReplace_name);
    cJSON_Delete(localVarSingleItemJSON_body);
    free(localVarBodyParameters);
    return elementToReturn;
end:
    return NULL;

}

// replace scale of the specified namespace scoped custom object
//
object_t*
CustomObjectsAPI_replaceNamespacedCustomObjectScale(apiClient_t *apiClient ,char * group ,char * version ,char * namespace ,char * plural ,char * name , object_t * body)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/{group}/{version}/namespaces/{namespace}/{plural}/{name}/scale")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/{group}/{version}/namespaces/{namespace}/{plural}/{name}/scale");


    // Path Params
    long sizeOfPathParams_group = strlen(group)+3 + strlen(version)+3 + strlen(namespace)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ group }");
    if(group == NULL) {
        goto end;
    }
    char* localVarToReplace_group = malloc(sizeOfPathParams_group);
    sprintf(localVarToReplace_group, "{%s}", "group");

    localVarPath = strReplace(localVarPath, localVarToReplace_group, group);

    // Path Params
    long sizeOfPathParams_version = strlen(group)+3 + strlen(version)+3 + strlen(namespace)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ version }");
    if(version == NULL) {
        goto end;
    }
    char* localVarToReplace_version = malloc(sizeOfPathParams_version);
    sprintf(localVarToReplace_version, "{%s}", "version");

    localVarPath = strReplace(localVarPath, localVarToReplace_version, version);

    // Path Params
    long sizeOfPathParams_namespace = strlen(group)+3 + strlen(version)+3 + strlen(namespace)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);

    // Path Params
    long sizeOfPathParams_plural = strlen(group)+3 + strlen(version)+3 + strlen(namespace)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ plural }");
    if(plural == NULL) {
        goto end;
    }
    char* localVarToReplace_plural = malloc(sizeOfPathParams_plural);
    sprintf(localVarToReplace_plural, "{%s}", "plural");

    localVarPath = strReplace(localVarPath, localVarToReplace_plural, plural);

    // Path Params
    long sizeOfPathParams_name = strlen(group)+3 + strlen(version)+3 + strlen(namespace)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);



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
    cJSON *CustomObjectsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(CustomObjectsAPIlocalVarJSON);
    cJSON_Delete(CustomObjectsAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_group);
    free(localVarToReplace_version);
    free(localVarToReplace_namespace);
    free(localVarToReplace_plural);
    free(localVarToReplace_name);
    cJSON_Delete(localVarSingleItemJSON_body);
    free(localVarBodyParameters);
    return elementToReturn;
end:
    return NULL;

}

// replace status of the specified namespace scoped custom object
//
object_t*
CustomObjectsAPI_replaceNamespacedCustomObjectStatus(apiClient_t *apiClient ,char * group ,char * version ,char * namespace ,char * plural ,char * name , object_t * body)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/{group}/{version}/namespaces/{namespace}/{plural}/{name}/status")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/{group}/{version}/namespaces/{namespace}/{plural}/{name}/status");


    // Path Params
    long sizeOfPathParams_group = strlen(group)+3 + strlen(version)+3 + strlen(namespace)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ group }");
    if(group == NULL) {
        goto end;
    }
    char* localVarToReplace_group = malloc(sizeOfPathParams_group);
    sprintf(localVarToReplace_group, "{%s}", "group");

    localVarPath = strReplace(localVarPath, localVarToReplace_group, group);

    // Path Params
    long sizeOfPathParams_version = strlen(group)+3 + strlen(version)+3 + strlen(namespace)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ version }");
    if(version == NULL) {
        goto end;
    }
    char* localVarToReplace_version = malloc(sizeOfPathParams_version);
    sprintf(localVarToReplace_version, "{%s}", "version");

    localVarPath = strReplace(localVarPath, localVarToReplace_version, version);

    // Path Params
    long sizeOfPathParams_namespace = strlen(group)+3 + strlen(version)+3 + strlen(namespace)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);

    // Path Params
    long sizeOfPathParams_plural = strlen(group)+3 + strlen(version)+3 + strlen(namespace)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ plural }");
    if(plural == NULL) {
        goto end;
    }
    char* localVarToReplace_plural = malloc(sizeOfPathParams_plural);
    sprintf(localVarToReplace_plural, "{%s}", "plural");

    localVarPath = strReplace(localVarPath, localVarToReplace_plural, plural);

    // Path Params
    long sizeOfPathParams_name = strlen(group)+3 + strlen(version)+3 + strlen(namespace)+3 + strlen(plural)+3 + strlen(name)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);



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
    cJSON *CustomObjectsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(CustomObjectsAPIlocalVarJSON);
    cJSON_Delete(CustomObjectsAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_group);
    free(localVarToReplace_version);
    free(localVarToReplace_namespace);
    free(localVarToReplace_plural);
    free(localVarToReplace_name);
    cJSON_Delete(localVarSingleItemJSON_body);
    free(localVarBodyParameters);
    return elementToReturn;
end:
    return NULL;

}

*/