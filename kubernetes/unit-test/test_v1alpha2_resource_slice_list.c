#ifndef v1alpha2_resource_slice_list_TEST
#define v1alpha2_resource_slice_list_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1alpha2_resource_slice_list_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1alpha2_resource_slice_list.h"
v1alpha2_resource_slice_list_t* instantiate_v1alpha2_resource_slice_list(int include_optional);

#include "test_v1_list_meta.c"


v1alpha2_resource_slice_list_t* instantiate_v1alpha2_resource_slice_list(int include_optional) {
  v1alpha2_resource_slice_list_t* v1alpha2_resource_slice_list = NULL;
  if (include_optional) {
    v1alpha2_resource_slice_list = v1alpha2_resource_slice_list_create(
      "0",
      list_createList(),
      "0",
       // false, not to have infinite recursion
      instantiate_v1_list_meta(0)
    );
  } else {
    v1alpha2_resource_slice_list = v1alpha2_resource_slice_list_create(
      "0",
      list_createList(),
      "0",
      NULL
    );
  }

  return v1alpha2_resource_slice_list;
}


#ifdef v1alpha2_resource_slice_list_MAIN

void test_v1alpha2_resource_slice_list(int include_optional) {
    v1alpha2_resource_slice_list_t* v1alpha2_resource_slice_list_1 = instantiate_v1alpha2_resource_slice_list(include_optional);

	cJSON* jsonv1alpha2_resource_slice_list_1 = v1alpha2_resource_slice_list_convertToJSON(v1alpha2_resource_slice_list_1);
	printf("v1alpha2_resource_slice_list :\n%s\n", cJSON_Print(jsonv1alpha2_resource_slice_list_1));
	v1alpha2_resource_slice_list_t* v1alpha2_resource_slice_list_2 = v1alpha2_resource_slice_list_parseFromJSON(jsonv1alpha2_resource_slice_list_1);
	cJSON* jsonv1alpha2_resource_slice_list_2 = v1alpha2_resource_slice_list_convertToJSON(v1alpha2_resource_slice_list_2);
	printf("repeating v1alpha2_resource_slice_list:\n%s\n", cJSON_Print(jsonv1alpha2_resource_slice_list_2));
}

int main() {
  test_v1alpha2_resource_slice_list(1);
  test_v1alpha2_resource_slice_list(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1alpha2_resource_slice_list_MAIN
#endif // v1alpha2_resource_slice_list_TEST
