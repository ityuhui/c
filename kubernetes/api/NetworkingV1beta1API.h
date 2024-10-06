#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/object.h"
#include "../model/v1_api_resource_list.h"
#include "../model/v1_delete_options.h"
#include "../model/v1_status.h"
#include "../model/v1beta1_ip_address.h"
#include "../model/v1beta1_ip_address_list.h"
#include "../model/v1beta1_service_cidr.h"
#include "../model/v1beta1_service_cidr_list.h"


// create an IPAddress
//
v1beta1_ip_address_t*
NetworkingV1beta1API_createIPAddress(apiClient_t *apiClient, v1beta1_ip_address_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


// create a ServiceCIDR
//
v1beta1_service_cidr_t*
NetworkingV1beta1API_createServiceCIDR(apiClient_t *apiClient, v1beta1_service_cidr_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


// delete collection of IPAddress
//
v1_status_t*
NetworkingV1beta1API_deleteCollectionIPAddress(apiClient_t *apiClient, char *pretty, char *_continue, char *dryRun, char *fieldSelector, int *gracePeriodSeconds, char *labelSelector, int *limit, int *orphanDependents, char *propagationPolicy, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, v1_delete_options_t *body);


// delete collection of ServiceCIDR
//
v1_status_t*
NetworkingV1beta1API_deleteCollectionServiceCIDR(apiClient_t *apiClient, char *pretty, char *_continue, char *dryRun, char *fieldSelector, int *gracePeriodSeconds, char *labelSelector, int *limit, int *orphanDependents, char *propagationPolicy, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, v1_delete_options_t *body);


// delete an IPAddress
//
v1_status_t*
NetworkingV1beta1API_deleteIPAddress(apiClient_t *apiClient, char *name, char *pretty, char *dryRun, int *gracePeriodSeconds, int *orphanDependents, char *propagationPolicy, v1_delete_options_t *body);


// delete a ServiceCIDR
//
v1_status_t*
NetworkingV1beta1API_deleteServiceCIDR(apiClient_t *apiClient, char *name, char *pretty, char *dryRun, int *gracePeriodSeconds, int *orphanDependents, char *propagationPolicy, v1_delete_options_t *body);


// get available resources
//
v1_api_resource_list_t*
NetworkingV1beta1API_getAPIResources(apiClient_t *apiClient);


// list or watch objects of kind IPAddress
//
v1beta1_ip_address_list_t*
NetworkingV1beta1API_listIPAddress(apiClient_t *apiClient, char *pretty, int *allowWatchBookmarks, char *_continue, char *fieldSelector, char *labelSelector, int *limit, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, int *watch);


// list or watch objects of kind ServiceCIDR
//
v1beta1_service_cidr_list_t*
NetworkingV1beta1API_listServiceCIDR(apiClient_t *apiClient, char *pretty, int *allowWatchBookmarks, char *_continue, char *fieldSelector, char *labelSelector, int *limit, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, int *watch);


// partially update the specified IPAddress
//
v1beta1_ip_address_t*
NetworkingV1beta1API_patchIPAddress(apiClient_t *apiClient, char *name, object_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation, int *force);


// partially update the specified ServiceCIDR
//
v1beta1_service_cidr_t*
NetworkingV1beta1API_patchServiceCIDR(apiClient_t *apiClient, char *name, object_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation, int *force);


// partially update status of the specified ServiceCIDR
//
v1beta1_service_cidr_t*
NetworkingV1beta1API_patchServiceCIDRStatus(apiClient_t *apiClient, char *name, object_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation, int *force);


// read the specified IPAddress
//
v1beta1_ip_address_t*
NetworkingV1beta1API_readIPAddress(apiClient_t *apiClient, char *name, char *pretty);


// read the specified ServiceCIDR
//
v1beta1_service_cidr_t*
NetworkingV1beta1API_readServiceCIDR(apiClient_t *apiClient, char *name, char *pretty);


// read status of the specified ServiceCIDR
//
v1beta1_service_cidr_t*
NetworkingV1beta1API_readServiceCIDRStatus(apiClient_t *apiClient, char *name, char *pretty);


// replace the specified IPAddress
//
v1beta1_ip_address_t*
NetworkingV1beta1API_replaceIPAddress(apiClient_t *apiClient, char *name, v1beta1_ip_address_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


// replace the specified ServiceCIDR
//
v1beta1_service_cidr_t*
NetworkingV1beta1API_replaceServiceCIDR(apiClient_t *apiClient, char *name, v1beta1_service_cidr_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


// replace status of the specified ServiceCIDR
//
v1beta1_service_cidr_t*
NetworkingV1beta1API_replaceServiceCIDRStatus(apiClient_t *apiClient, char *name, v1beta1_service_cidr_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


