#include <kube_config.h>
#include <apiClient.h>
#include <CoreV1API.h>
#include <malloc.h>
#include <stdio.h>
#include <errno.h>

void list_secret(apiClient_t * apiClient)
{
    v1_secret_list_t *secret_list = CoreV1API_listNamespacedSecret(apiClient,
                                                        "default",  // char *namespace
                                                        "true",   // char *pretty
                                                        0,   // int allowWatchBookmarks
                                                        NULL,  // char * _continue
                                                        NULL,  // char * fieldSelector
                                                        NULL,   // char * labelSelector
                                                        0,    // int limit
                                                        NULL, // char * resourceVersion
                                                        0, // int timeoutSeconds
                                                        0 //int watch
        );

    printf("The return code of HTTP request=%ld\n", apiClient->response_code);

    if (200 == apiClient->response_code) {
        printf("The pod is deleted successfully.\n");
    } else {
        printf("Failed to list the secret.\n");
        return ;
    }

    if (secret_list && secret_list->items) {
        listEntry_t *secret_list_entry = NULL;
        v1_secret_t *secret = NULL;
        list_ForEach(secret_list_entry, secret_list->items) {
            secret = secret_list_entry->data;
            printf("\tThe secret name: %s\n", secret->metadata->name);

            listEntry_t *data_entry = NULL;
            char *data = NULL;
            list_ForEach(data_entry, secret->data) {
                data = data_entry->data;
                printf("\tThe data: %s\n", data);
            }
        }
        v1_secret_list_free(secret_list);
        secret_list = NULL;
    } else {
        printf("The list is invalid.\n");
    }
}

int main(int argc, char *argv[])
{
    char *basePath = NULL;
    sslConfig_t *sslConfig = NULL;
    list_t *apiKeys = NULL;
    int rc = load_kube_config(&basePath, &sslConfig, &apiKeys, NULL);   /* NULL means loading configuration from $HOME/.kube/config */
    if (rc != 0) {
        printf("Cannot load kubernetes configuration.\n");
        return -1;
    }
    apiClient_t *apiClient = apiClient_create_with_base_path(basePath, sslConfig, apiKeys);
    if (!apiClient) {
        printf("Cannot create a kubernetes client.\n");
        return -1;
    }

    list_secret(apiClient);

    apiClient_free(apiClient);
    apiClient = NULL;
    free_client_config(basePath, sslConfig, apiKeys);
    basePath = NULL;
    sslConfig = NULL;
    apiKeys = NULL;
    apiClient_unsetupGlobalEnv();

    return 0;
}
