#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayUtils.h"
ARRAY_UTILS create(int typeSize,int length){
	ARRAY_UTILS array;
	array.base = (void *)calloc(typeSize,length);
	array.typeSize = typeSize;
	array.length = length;
	return array;
}

int areEqual(ARRAY_UTILS array1,ARRAY_UTILS array2){
	if((array1.length == array2.length) && (array1.typeSize == array2.typeSize)){
		if(memcmp(array1.base,array2.base,array1.length) == 0){
			return 1;
		}
	}
	return 0;
}

ARRAY_UTILS resize(ARRAY_UTILS sampleUtils,int length){
	sampleUtils.base = realloc(sampleUtils.base,length*sampleUtils.typeSize);
	sampleUtils.length = length;
	return sampleUtils;
}

void dispose(ARRAY_UTILS utils){
	free(utils.base);
}

int findIndex(ARRAY_UTILS utils,void* element){
	void * base = utils.base;
	for(int i=0;i<utils.length;i++){
		if(memcmp(base,element,utils.typeSize)==0){
			return i;
		}
		base = base + utils.typeSize;
	}
	return -1;
}

















