# v2beta2_metric_spec_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**container_resource** | [**v2beta2_container_resource_metric_source_t**](v2beta2_container_resource_metric_source.md) \* |  | [optional] 
**external** | [**v2beta2_external_metric_source_t**](v2beta2_external_metric_source.md) \* |  | [optional] 
**object** | [**v2beta2_object_metric_source_t**](v2beta2_object_metric_source.md) \* |  | [optional] 
**pods** | [**v2beta2_pods_metric_source_t**](v2beta2_pods_metric_source.md) \* |  | [optional] 
**resource** | [**v2beta2_resource_metric_source_t**](v2beta2_resource_metric_source.md) \* |  | [optional] 
**type** | **char \*** | type is the type of metric source.  It should be one of \&quot;ContainerResource\&quot;, \&quot;External\&quot;, \&quot;Object\&quot;, \&quot;Pods\&quot; or \&quot;Resource\&quot;, each mapping to a matching field in the object. Note: \&quot;ContainerResource\&quot; type is available on when the feature-gate HPAContainerMetrics is enabled | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


