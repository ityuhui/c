#ifndef v1_pod_resource_claim_TEST
#define v1_pod_resource_claim_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_pod_resource_claim_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_pod_resource_claim.h"
v1_pod_resource_claim_t* instantiate_v1_pod_resource_claim(int include_optional);

#include "test_v1_claim_source.c"


v1_pod_resource_claim_t* instantiate_v1_pod_resource_claim(int include_optional) {
  v1_pod_resource_claim_t* v1_pod_resource_claim = NULL;
  if (include_optional) {
    v1_pod_resource_claim = v1_pod_resource_claim_create(
      "0",
       // false, not to have infinite recursion
      instantiate_v1_claim_source(0)
    );
  } else {
    v1_pod_resource_claim = v1_pod_resource_claim_create(
      "0",
      NULL
    );
  }

  return v1_pod_resource_claim;
}


#ifdef v1_pod_resource_claim_MAIN

void test_v1_pod_resource_claim(int include_optional) {
    v1_pod_resource_claim_t* v1_pod_resource_claim_1 = instantiate_v1_pod_resource_claim(include_optional);

	cJSON* jsonv1_pod_resource_claim_1 = v1_pod_resource_claim_convertToJSON(v1_pod_resource_claim_1);
	printf("v1_pod_resource_claim :\n%s\n", cJSON_Print(jsonv1_pod_resource_claim_1));
	v1_pod_resource_claim_t* v1_pod_resource_claim_2 = v1_pod_resource_claim_parseFromJSON(jsonv1_pod_resource_claim_1);
	cJSON* jsonv1_pod_resource_claim_2 = v1_pod_resource_claim_convertToJSON(v1_pod_resource_claim_2);
	printf("repeating v1_pod_resource_claim:\n%s\n", cJSON_Print(jsonv1_pod_resource_claim_2));
}

int main() {
  test_v1_pod_resource_claim(1);
  test_v1_pod_resource_claim(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_pod_resource_claim_MAIN
#endif // v1_pod_resource_claim_TEST
