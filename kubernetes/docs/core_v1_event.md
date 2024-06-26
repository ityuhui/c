# core_v1_event_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**action** | **char \*** | What action was taken/failed regarding to the Regarding object. | [optional] 
**api_version** | **char \*** | APIVersion defines the versioned schema of this representation of an object. Servers should convert recognized schemas to the latest internal value, and may reject unrecognized values. More info: https://git.k8s.io/community/contributors/devel/sig-architecture/api-conventions.md#resources | [optional] 
**count** | **int** | The number of times this event has occurred. | [optional] 
**event_time** | **char \*** | Time when this Event was first observed. | [optional] 
**first_timestamp** | **char \*** | The time at which the event was first recorded. (Time of server receipt is in TypeMeta.) | [optional] 
**involved_object** | [**v1_object_reference_t**](v1_object_reference.md) \* |  | 
**kind** | **char \*** | Kind is a string value representing the REST resource this object represents. Servers may infer this from the endpoint the client submits requests to. Cannot be updated. In CamelCase. More info: https://git.k8s.io/community/contributors/devel/sig-architecture/api-conventions.md#types-kinds | [optional] 
**last_timestamp** | **char \*** | The time at which the most recent occurrence of this event was recorded. | [optional] 
**message** | **char \*** | A human-readable description of the status of this operation. | [optional] 
**metadata** | [**v1_object_meta_t**](v1_object_meta.md) \* |  | 
**reason** | **char \*** | This should be a short, machine understandable string that gives the reason for the transition into the object&#39;s current status. | [optional] 
**related** | [**v1_object_reference_t**](v1_object_reference.md) \* |  | [optional] 
**reporting_component** | **char \*** | Name of the controller that emitted this Event, e.g. &#x60;kubernetes.io/kubelet&#x60;. | [optional] 
**reporting_instance** | **char \*** | ID of the controller instance, e.g. &#x60;kubelet-xyzf&#x60;. | [optional] 
**series** | [**core_v1_event_series_t**](core_v1_event_series.md) \* |  | [optional] 
**source** | [**v1_event_source_t**](v1_event_source.md) \* |  | [optional] 
**type** | **char \*** | Type of this event (Normal, Warning), new types could be added in the future | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


