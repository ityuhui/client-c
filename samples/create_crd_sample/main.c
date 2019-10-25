#include <apiClient.h>
#include <malloc.h>
#include <ActivitiesV1API.h>



void create_one_activity(apiClient_t *apiClient)
{
    char *namesapce = "default";

    ego_v1_activity_t * activityinfo = calloc(1, sizeof(ego_v1_activity_t));
    activityinfo->apiVersion = strdup("ego.symphony.spectrumcomputing.ibm.com/v1");
    activityinfo->kind = strdup("Activity");

    activityinfo->metadata = calloc(1, sizeof(v1_object_meta_t));
    activityinfo->metadata->name = strdup("activity-sample-ego-4");

    activityinfo->spec = calloc(1, sizeof(ego_v1_activity_spec_t));
    activityinfo->spec->host = strdup("workload-pod-2");
    activityinfo->spec->command = strdup("sleep 3601");

    ego_v1_activity_t* activ = ActivitiesV1API_createNamespacedActivity(
        apiClient, 
        namesapce, 
        activityinfo, 
        NULL);

    printf("code=%ld\n", apiClient->response_code);

    ego_v1_activity_free(activityinfo);
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

    create_one_activity(apiClient);

    apiClient_free(apiClient);
}

