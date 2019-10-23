#include <apiClient.h>

int main()
{
    apiClient_t *app = apiClient_create();

    apiClient_free(app);
}