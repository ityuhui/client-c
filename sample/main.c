#include <apiClient.h>

int main()
{
    list_t *apiKeys;
    apiKeys = list_create();
    
    char *keyToken = strdup("Authorization");
    char *valueToken = strdup("Bearer eyJhbGciOiJSUzI1NiIsImtpZCI6IjJZT3k1bDNKTVc3Nk9qWXlqTVlYcXFRZWQwb2tGWnNFNWI0eVY1cnBQNzgifQ.eyJpc3MiOiJrdWJlcm5ldGVzL3NlcnZpY2VhY2NvdW50Iiwia3ViZXJuZXRlcy5pby9zZXJ2aWNlYWNjb3VudC9uYW1lc3BhY2UiOiJkZWZhdWx0Iiwia3ViZXJuZXRlcy5pby9zZXJ2aWNlYWNjb3VudC9zZWNyZXQubmFtZSI6ImRlZmF1bHQtdG9rZW4tOHA0aDQiLCJrdWJlcm5ldGVzLmlvL3NlcnZpY2VhY2NvdW50L3NlcnZpY2UtYWNjb3VudC5uYW1lIjoiZGVmYXVsdCIsImt1YmVybmV0ZXMuaW8vc2VydmljZWFjY291bnQvc2VydmljZS1hY2NvdW50LnVpZCI6ImMxNjhmM2NjLTFhODQtNGNjNC04ZmUxLWJjZDNhYTE5MTllOCIsInN1YiI6InN5c3RlbTpzZXJ2aWNlYWNjb3VudDpkZWZhdWx0OmRlZmF1bHQifQ.IwgMXmMmTG_bmARroB2S_Fc-7tvrQ4WpyadzXVNVlzLeSuMgABSisBmUfTURwIstOZ_yojJIC6UXYl2Cq2IELl9cJZ6Z1knktvtgfCjqUNUCFqNRkAbt4TB8b22yZEi_ZngvxDknRkJv79XcDm6Nab9MutWMN6b45iH1aL-1W93fqqXburakkpDeMm5fN0TcYxT_zLV7LWjVwWRsvcIEr1dNfVjmZiKdTs9Oepbm__t9q-kvk-t2ItzwPFuNkpygNWsQSH_lDeIutNucBh7oRPUtkvBGDlyOajYcV-Xy1ufSicdw_Mm-oDKgPB72WEYyc87H5Z8SGn6VaCqlTwiDFw");
    keyValuePair_t *keyPairToken = keyValuePair_create(keyToken, valueToken);
    list_addElement(apiKeys, keyPairToken);

    //apiClient_t *app = apiClient_create("https://kubernetes:6443", apiKeys);

    apiClient_t *apiClient = apiClient_create("https://9.111.254.254:6443", apiKeys);
    
    CoreAPI_getCoreAPIVersions(apiClient);


    apiClient_free(apiClient);
}