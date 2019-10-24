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
    podinfo->metadata->name = strdup("test-p1");

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
}

void list_pod(apiClient_t *apiClient)
{
    char *namesapce = "default";

    CoreV1API_listCoreV1NamespacedPod(apiClient, namesapce, NULL, 0, 0, NULL, NULL, 5, NULL, 30, 0);
}

int main()
{
    list_t *apiKeys;
    apiKeys = list_create();
    
    //char *keyToken = strdup("Authorization");
    //char *valueToken = strdup("Bearer eyJhbGciOiJSUzI1NiIsImtpZCI6IjJZT3k1bDNKTVc3Nk9qWXlqTVlYcXFRZWQwb2tGWnNFNWI0eVY1cnBQNzgifQ.eyJpc3MiOiJrdWJlcm5ldGVzL3NlcnZpY2VhY2NvdW50Iiwia3ViZXJuZXRlcy5pby9zZXJ2aWNlYWNjb3VudC9uYW1lc3BhY2UiOiJkZWZhdWx0Iiwia3ViZXJuZXRlcy5pby9zZXJ2aWNlYWNjb3VudC9zZWNyZXQubmFtZSI6ImRlZmF1bHQtdG9rZW4tOHA0aDQiLCJrdWJlcm5ldGVzLmlvL3NlcnZpY2VhY2NvdW50L3NlcnZpY2UtYWNjb3VudC5uYW1lIjoiZGVmYXVsdCIsImt1YmVybmV0ZXMuaW8vc2VydmljZWFjY291bnQvc2VydmljZS1hY2NvdW50LnVpZCI6ImMxNjhmM2NjLTFhODQtNGNjNC04ZmUxLWJjZDNhYTE5MTllOCIsInN1YiI6InN5c3RlbTpzZXJ2aWNlYWNjb3VudDpkZWZhdWx0OmRlZmF1bHQifQ.IwgMXmMmTG_bmARroB2S_Fc-7tvrQ4WpyadzXVNVlzLeSuMgABSisBmUfTURwIstOZ_yojJIC6UXYl2Cq2IELl9cJZ6Z1knktvtgfCjqUNUCFqNRkAbt4TB8b22yZEi_ZngvxDknRkJv79XcDm6Nab9MutWMN6b45iH1aL-1W93fqqXburakkpDeMm5fN0TcYxT_zLV7LWjVwWRsvcIEr1dNfVjmZiKdTs9Oepbm__t9q-kvk-t2ItzwPFuNkpygNWsQSH_lDeIutNucBh7oRPUtkvBGDlyOajYcV-Xy1ufSicdw_Mm-oDKgPB72WEYyc87H5Z8SGn6VaCqlTwiDFw");
    //keyValuePair_t *keyPairToken = keyValuePair_create(keyToken, valueToken);
    //list_addElement(apiKeys, keyPairToken);

    //apiClient_t *app = apiClient_create("https://kubernetes:6443", apiKeys);

    //apiClient_t *apiClient = apiClient_create("https://9.111.254.254:6443", apiKeys, NULL);

    apiClient_t *apiClient = apiClient_create("http://localhost:8001", NULL, NULL);

    create_a_pod(apiClient);

    apiClient_free(apiClient);
}

