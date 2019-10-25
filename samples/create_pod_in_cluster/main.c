#include <apiClient.h>
#include <CoreV1API.h>
#include <malloc.h>
#include <stdio.h>
#include <errno.h>

//#define K8S_APISERVER_BASEPATH "https://kubernetes"
#define K8S_APISERVER_BASEPATH "https://9.111.254.254:6443"
#define K8S_TOKEN_FILE_IN_CLUSTER "/var/run/secrets/kubernetes.io/serviceaccount/token"
#define K8S_TOKEN_BUF_SIZE 1024
#define K8S_AUTH_KEY "Authorization"
#define K8S_AUTH_VALUE_TEMPLATE "Bearer %s"

apiClient_t *g_k8sAPIConnector;

void create_a_pod(apiClient_t *apiClient)
{
    char *namesapce = "default";

    v1_pod_t * podinfo = calloc(1, sizeof(v1_pod_t));
    podinfo->apiVersion = strdup("v1");
    podinfo->kind = strdup("Pod");
    podinfo->spec = calloc(1, sizeof(v1_pod_spec_t));

    podinfo->metadata = calloc(1, sizeof(v1_object_meta_t));
    podinfo->metadata->name = strdup("test-p3");

    list_t *containerlist = list_create();
    v1_container_t *con = calloc(1, sizeof(v1_container_t));
    con->name = strdup("my-container");
    con->image = strdup("ubuntu:16.04");
    con->imagePullPolicy = strdup("IfNotPresent");

    list_t *commandlist = list_create();
    char *cmd = strdup("sleep");
    list_addElement(commandlist, cmd);
    con->command = commandlist;

    list_t *arglist = list_create();
    char *arg1 = strdup("3600");
    list_addElement(arglist, arg1);
    con->args = arglist;

    list_addElement(containerlist, con);
    podinfo->spec->containers = containerlist;

    v1_pod_t* apod = CoreV1API_createCoreV1NamespacedPod(apiClient, namesapce, podinfo, NULL, NULL, NULL);
    printf("code=%ld\n", apiClient->response_code);

    //v1_pod_free(apod);
}

int
loadK8sConfigInCluster(char *token, int token_buf_size)
{
    static char fname[] = "loadK8sConfigInCluster()";

    FILE *fp;
    fp = fopen(K8S_TOKEN_FILE_IN_CLUSTER, "r");

    if (fp == NULL) {
        if (errno == ENOENT) {
            printf("\
%s: The file %s does not exist.",
fname, K8S_TOKEN_FILE_IN_CLUSTER);
            return (-1);
        } else {
            printf("\
%s: Failed to open file %s (%m).",
fname, K8S_TOKEN_FILE_IN_CLUSTER);
            return (-1);
        }
    }

    while (fgets(token, token_buf_size, fp) != NULL) {
        ;
    }

    fclose(fp);

    return 0;
}

int
init_k8s_connector()
{
    list_t *apiKeys;
    apiKeys = list_create();

    char *keyToken = strdup(K8S_AUTH_KEY);
    char token[K8S_TOKEN_BUF_SIZE];
    memset(token, 0, sizeof(token));

    loadK8sConfigInCluster(token, K8S_TOKEN_BUF_SIZE);

    char valueToken[K8S_TOKEN_BUF_SIZE];
    memset(valueToken, 0, sizeof(valueToken));
    sprintf(valueToken, K8S_AUTH_VALUE_TEMPLATE, token);

    keyValuePair_t *keyPairToken = keyValuePair_create(keyToken, valueToken);
    list_addElement(apiKeys, keyPairToken);

    g_k8sAPIConnector = apiClient_create(K8S_APISERVER_BASEPATH, apiKeys, NULL);
}

int main(int argc, char *argv[])
{

    init_k8s_connector();

    create_a_pod(g_k8sAPIConnector);

    apiClient_free(g_k8sAPIConnector);
}

