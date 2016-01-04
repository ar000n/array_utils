#include <stdio.h>
typedef struct arrayUtils
{
	void *base;
	int typeSize;
	int length;
}ARRAY_UTILS;
ARRAY_UTILS create(int typeSize,int length);