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

void* findFirst(ARRAY_UTILS util, MatchFunc* match, void* hint){
	for(int i=0;i<util.length;i++){
		if(match(hint,util.base) == 1){
			return util.base;
		}
		util.base+=util.typeSize;
	}
	return NULL;
};

void* findLast(ARRAY_UTILS util, MatchFunc* match, void* hint){
	util.base += ((util.length-1) * util.typeSize);
	for(int i=util.length-1;i>=0;i--){
		if(match(hint,util.base) == 1){
			return util.base;
		}
		util.base-=util.typeSize;
	}
	return NULL;
};

int count(ARRAY_UTILS util, MatchFunc* match, void* hint){
	int counter = 0;
	for(int i=0;i<util.length;i++){
		if(match(hint,util.base) == 1){
			counter++;
		}
		util.base+=util.typeSize;
	}
	return counter;
};

int filter(ARRAY_UTILS util, MatchFunc* match, void* hint, void** destination, int maxItems ){
	int counter = 0;
	for(int i=0;i<util.length;i++){
		if(match(hint,util.base) == 1){
			*destination = util.base;
			counter++;
			destination++;
		}
		util.base+=util.typeSize;
	}
	return counter;
};

void map(ARRAY_UTILS source, ARRAY_UTILS destination, ConvertFunc* convert, void* hint){
	for(int i=0;i<source.length;i++){
		convert(hint, source.base, destination.base);
		source.base+=source.typeSize;
		destination.base+=source.typeSize;
	}
};
















