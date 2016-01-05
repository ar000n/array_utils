#include <stdio.h>
#include "arrayUtils.h"
#include <assert.h>

void test_for_create_array_utils(){
	ARRAY_UTILS array1 = create(4,2);
	ARRAY_UTILS array2 = create(4,3);
	assert(array1.typeSize == 4);
	assert(array2.typeSize == 4);
	assert(array1.length == 2);
	assert(array2.length == 3);
}

void test_for_areEqual_array_utils_if_notEqual(){
	ARRAY_UTILS array1 = create(4,2);
	ARRAY_UTILS array2 = create(4,3);
	assert(areEqual(array1,array2) ==0);
}
void test_for_areEqual_array_utils_if_Equal(){
	ARRAY_UTILS array1 = create(4,10);
	ARRAY_UTILS array2 = create(4,10);
	assert(areEqual(array1,array2) ==1);
}
void test_for_resize_array(){
	ARRAY_UTILS array1 = create(8,2);
	assert(array1.length ==2);
	ARRAY_UTILS array2 = resize(array1,10);
	assert(array2.length ==10);
}
void test_for_findIndex(){
	ARRAY_UTILS array1 = create(4,6);
	int *num = (int*)array1.base;
	num[0] = 1;
	num[1] = 7;
	num[2] = 5;
	num[3] = 2;
	int element1 =5;
	int element2 =3;
	assert(findIndex(array1,&element1) == 2);
	assert(findIndex(array1,&element2) == -1);
}
int main(){
	test_for_create_array_utils();
	test_for_areEqual_array_utils_if_notEqual();
	test_for_areEqual_array_utils_if_Equal();
	test_for_resize_array();
	test_for_findIndex();

	return 0;

}
