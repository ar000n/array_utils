#include <stdio.h>
#include "arrayUtils.h"
ARRAY_UTILS create(int typeSize,int length){
	ARRAY_UTILS array;
	array.base = calloc(typeSize,length);
	array.typeSize = typeSize;
	array.length = length;
	return array;

}