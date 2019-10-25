#include <apiClient.h>
#include <CoreV1API.h>
#include <malloc.h>



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

    v1_pod_free(apod);
}

void list_pod(apiClient_t *apiClient)
{
    char *namesapce = "default";

    CoreV1API_listCoreV1NamespacedPod(apiClient, namesapce, NULL, 0, 0, NULL, NULL, 5, NULL, 30, 0);
}

void print_usage()
{
    printf("Usage: main baseurl(mandotory) token(mandotory) cafile(optional)\n\
e.g. main https://kubernetes:6443 mtpZCI6IjJZT3k1bDNK\n");
}

int main(int argc, char *argv[])
{
    if (argc < 3) {
        print_usage();
        return 1;
    }

    list_t *apiKeys;
    apiKeys = list_create();
    
    char *keyToken = strdup("Authorization");
    char valueToken[1024];
    memset(valueToken, 0, sizeof(valueToken));
    sprintf(valueToken, "Bearer %s", argv[2]);

    keyValuePair_t *keyPairToken = keyValuePair_create(keyToken, valueToken);
    list_addElement(apiKeys, keyPairToken);

    //apiClient_t *app = apiClient_create("https://kubernetes:6443", apiKeys);

    //For hypervisor
    apiClient_t *apiClient = apiClient_create("https://9.111.254.254:6443", apiKeys, NULL);

    //For kubectl proxy
    //apiClient_t *apiClient = apiClient_create("http://localhost:8001", NULL, NULL);

    create_a_pod(apiClient);

    apiClient_free(apiClient);
}

