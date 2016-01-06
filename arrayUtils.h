#include <stdio.h>
typedef struct{
	void *base;
	int typeSize;
	int length;
}ARRAY_UTILS;
ARRAY_UTILS create(int typeSize,int length);
int areEqual(ARRAY_UTILS array1,ARRAY_UTILS array2);
ARRAY_UTILS resize(ARRAY_UTILS sampleUtils,int length);
void dispose(ARRAY_UTILS utils);
int findIndex(ARRAY_UTILS utils,void* element);
typedef int(MatchFunc) (void *,void *);  
void* findFirst(ARRAY_UTILS util, MatchFunc* match, void* hint);
int count(ARRAY_UTILS util, MatchFunc* match, void* hint);
void* findLast(ARRAY_UTILS util, MatchFunc* match, void* hint);
