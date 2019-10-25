#include <apiClient.h>
#include <ego_v1_activity.h>
#include <malloc.h>



void create_an_activity(apiClient_t *apiClient)
{
    char *namesapce = "default";

    ego_v1_activity_t * activityinfo = calloc(1, sizeof(ego_v1_activity_t));
    activityinfo->apiVersion = strdup("v1");
    activityinfo->kind = strdup("Activity");
    activityinfo->spec = calloc(1, sizeof(ego_v1_activity_spec_t));

    activityinfo->metadata = calloc(1, sizeof(v1_object_meta_t));
    activityinfo->metadata->name = strdup("ego-activity23");

    activityinfo->spec->command = strdup("sleep 3600");
    activityinfo->spec->host = strdup("sim-workload-pod");

    ego_v1_activity_t* activitysample = ActivitiesV1API_createNamespacedActivity(
        apiClient, 
        namesapce, 
        activityinfo, 
        NULL);
    printf("code=%ld\n", apiClient->response_code);
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

    // run in cluster
    //apiClient_t *app = apiClient_create("https://kubernetes", apiKeys);

    // run in hypervisor
    apiClient_t *apiClient = apiClient_create("https://9.111.254.254:6443", apiKeys, NULL);

    // run in hypervisor with kubectl proxy
    //apiClient_t *apiClient = apiClient_create("http://localhost:8001", NULL, NULL);

    create_an_activity(apiClient);

    apiClient_free(apiClient);
}

