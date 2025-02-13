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
#include "../model/v1beta1_device_class.h"
#include "../model/v1beta1_device_class_list.h"
#include "../model/v1beta1_resource_claim.h"
#include "../model/v1beta1_resource_claim_list.h"
#include "../model/v1beta1_resource_claim_template.h"
#include "../model/v1beta1_resource_claim_template_list.h"
#include "../model/v1beta1_resource_slice.h"
#include "../model/v1beta1_resource_slice_list.h"


// create a DeviceClass
//
v1beta1_device_class_t*
ResourceV1beta1API_createDeviceClass(apiClient_t *apiClient, v1beta1_device_class_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


// create a ResourceClaim
//
v1beta1_resource_claim_t*
ResourceV1beta1API_createNamespacedResourceClaim(apiClient_t *apiClient, char *_namespace, v1beta1_resource_claim_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


// create a ResourceClaimTemplate
//
v1beta1_resource_claim_template_t*
ResourceV1beta1API_createNamespacedResourceClaimTemplate(apiClient_t *apiClient, char *_namespace, v1beta1_resource_claim_template_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


// create a ResourceSlice
//
v1beta1_resource_slice_t*
ResourceV1beta1API_createResourceSlice(apiClient_t *apiClient, v1beta1_resource_slice_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


// delete collection of DeviceClass
//
v1_status_t*
ResourceV1beta1API_deleteCollectionDeviceClass(apiClient_t *apiClient, char *pretty, char *_continue, char *dryRun, char *fieldSelector, int *gracePeriodSeconds, int *ignoreStoreReadErrorWithClusterBreakingPotential, char *labelSelector, int *limit, int *orphanDependents, char *propagationPolicy, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, v1_delete_options_t *body);


// delete collection of ResourceClaim
//
v1_status_t*
ResourceV1beta1API_deleteCollectionNamespacedResourceClaim(apiClient_t *apiClient, char *_namespace, char *pretty, char *_continue, char *dryRun, char *fieldSelector, int *gracePeriodSeconds, int *ignoreStoreReadErrorWithClusterBreakingPotential, char *labelSelector, int *limit, int *orphanDependents, char *propagationPolicy, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, v1_delete_options_t *body);


// delete collection of ResourceClaimTemplate
//
v1_status_t*
ResourceV1beta1API_deleteCollectionNamespacedResourceClaimTemplate(apiClient_t *apiClient, char *_namespace, char *pretty, char *_continue, char *dryRun, char *fieldSelector, int *gracePeriodSeconds, int *ignoreStoreReadErrorWithClusterBreakingPotential, char *labelSelector, int *limit, int *orphanDependents, char *propagationPolicy, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, v1_delete_options_t *body);


// delete collection of ResourceSlice
//
v1_status_t*
ResourceV1beta1API_deleteCollectionResourceSlice(apiClient_t *apiClient, char *pretty, char *_continue, char *dryRun, char *fieldSelector, int *gracePeriodSeconds, int *ignoreStoreReadErrorWithClusterBreakingPotential, char *labelSelector, int *limit, int *orphanDependents, char *propagationPolicy, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, v1_delete_options_t *body);


// delete a DeviceClass
//
v1beta1_device_class_t*
ResourceV1beta1API_deleteDeviceClass(apiClient_t *apiClient, char *name, char *pretty, char *dryRun, int *gracePeriodSeconds, int *ignoreStoreReadErrorWithClusterBreakingPotential, int *orphanDependents, char *propagationPolicy, v1_delete_options_t *body);


// delete a ResourceClaim
//
v1beta1_resource_claim_t*
ResourceV1beta1API_deleteNamespacedResourceClaim(apiClient_t *apiClient, char *name, char *_namespace, char *pretty, char *dryRun, int *gracePeriodSeconds, int *ignoreStoreReadErrorWithClusterBreakingPotential, int *orphanDependents, char *propagationPolicy, v1_delete_options_t *body);


// delete a ResourceClaimTemplate
//
v1beta1_resource_claim_template_t*
ResourceV1beta1API_deleteNamespacedResourceClaimTemplate(apiClient_t *apiClient, char *name, char *_namespace, char *pretty, char *dryRun, int *gracePeriodSeconds, int *ignoreStoreReadErrorWithClusterBreakingPotential, int *orphanDependents, char *propagationPolicy, v1_delete_options_t *body);


// delete a ResourceSlice
//
v1beta1_resource_slice_t*
ResourceV1beta1API_deleteResourceSlice(apiClient_t *apiClient, char *name, char *pretty, char *dryRun, int *gracePeriodSeconds, int *ignoreStoreReadErrorWithClusterBreakingPotential, int *orphanDependents, char *propagationPolicy, v1_delete_options_t *body);


// get available resources
//
v1_api_resource_list_t*
ResourceV1beta1API_getAPIResources(apiClient_t *apiClient);


// list or watch objects of kind DeviceClass
//
v1beta1_device_class_list_t*
ResourceV1beta1API_listDeviceClass(apiClient_t *apiClient, char *pretty, int *allowWatchBookmarks, char *_continue, char *fieldSelector, char *labelSelector, int *limit, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, int *watch);


// list or watch objects of kind ResourceClaim
//
v1beta1_resource_claim_list_t*
ResourceV1beta1API_listNamespacedResourceClaim(apiClient_t *apiClient, char *_namespace, char *pretty, int *allowWatchBookmarks, char *_continue, char *fieldSelector, char *labelSelector, int *limit, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, int *watch);


// list or watch objects of kind ResourceClaimTemplate
//
v1beta1_resource_claim_template_list_t*
ResourceV1beta1API_listNamespacedResourceClaimTemplate(apiClient_t *apiClient, char *_namespace, char *pretty, int *allowWatchBookmarks, char *_continue, char *fieldSelector, char *labelSelector, int *limit, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, int *watch);


// list or watch objects of kind ResourceClaim
//
v1beta1_resource_claim_list_t*
ResourceV1beta1API_listResourceClaimForAllNamespaces(apiClient_t *apiClient, int *allowWatchBookmarks, char *_continue, char *fieldSelector, char *labelSelector, int *limit, char *pretty, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, int *watch);


// list or watch objects of kind ResourceClaimTemplate
//
v1beta1_resource_claim_template_list_t*
ResourceV1beta1API_listResourceClaimTemplateForAllNamespaces(apiClient_t *apiClient, int *allowWatchBookmarks, char *_continue, char *fieldSelector, char *labelSelector, int *limit, char *pretty, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, int *watch);


// list or watch objects of kind ResourceSlice
//
v1beta1_resource_slice_list_t*
ResourceV1beta1API_listResourceSlice(apiClient_t *apiClient, char *pretty, int *allowWatchBookmarks, char *_continue, char *fieldSelector, char *labelSelector, int *limit, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, int *watch);


// partially update the specified DeviceClass
//
v1beta1_device_class_t*
ResourceV1beta1API_patchDeviceClass(apiClient_t *apiClient, char *name, object_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation, int *force);


// partially update the specified ResourceClaim
//
v1beta1_resource_claim_t*
ResourceV1beta1API_patchNamespacedResourceClaim(apiClient_t *apiClient, char *name, char *_namespace, object_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation, int *force);


// partially update status of the specified ResourceClaim
//
v1beta1_resource_claim_t*
ResourceV1beta1API_patchNamespacedResourceClaimStatus(apiClient_t *apiClient, char *name, char *_namespace, object_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation, int *force);


// partially update the specified ResourceClaimTemplate
//
v1beta1_resource_claim_template_t*
ResourceV1beta1API_patchNamespacedResourceClaimTemplate(apiClient_t *apiClient, char *name, char *_namespace, object_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation, int *force);


// partially update the specified ResourceSlice
//
v1beta1_resource_slice_t*
ResourceV1beta1API_patchResourceSlice(apiClient_t *apiClient, char *name, object_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation, int *force);


// read the specified DeviceClass
//
v1beta1_device_class_t*
ResourceV1beta1API_readDeviceClass(apiClient_t *apiClient, char *name, char *pretty);


// read the specified ResourceClaim
//
v1beta1_resource_claim_t*
ResourceV1beta1API_readNamespacedResourceClaim(apiClient_t *apiClient, char *name, char *_namespace, char *pretty);


// read status of the specified ResourceClaim
//
v1beta1_resource_claim_t*
ResourceV1beta1API_readNamespacedResourceClaimStatus(apiClient_t *apiClient, char *name, char *_namespace, char *pretty);


// read the specified ResourceClaimTemplate
//
v1beta1_resource_claim_template_t*
ResourceV1beta1API_readNamespacedResourceClaimTemplate(apiClient_t *apiClient, char *name, char *_namespace, char *pretty);


// read the specified ResourceSlice
//
v1beta1_resource_slice_t*
ResourceV1beta1API_readResourceSlice(apiClient_t *apiClient, char *name, char *pretty);


// replace the specified DeviceClass
//
v1beta1_device_class_t*
ResourceV1beta1API_replaceDeviceClass(apiClient_t *apiClient, char *name, v1beta1_device_class_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


// replace the specified ResourceClaim
//
v1beta1_resource_claim_t*
ResourceV1beta1API_replaceNamespacedResourceClaim(apiClient_t *apiClient, char *name, char *_namespace, v1beta1_resource_claim_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


// replace status of the specified ResourceClaim
//
v1beta1_resource_claim_t*
ResourceV1beta1API_replaceNamespacedResourceClaimStatus(apiClient_t *apiClient, char *name, char *_namespace, v1beta1_resource_claim_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


// replace the specified ResourceClaimTemplate
//
v1beta1_resource_claim_template_t*
ResourceV1beta1API_replaceNamespacedResourceClaimTemplate(apiClient_t *apiClient, char *name, char *_namespace, v1beta1_resource_claim_template_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


// replace the specified ResourceSlice
//
v1beta1_resource_slice_t*
ResourceV1beta1API_replaceResourceSlice(apiClient_t *apiClient, char *name, v1beta1_resource_slice_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


