#include <stdio.h>
#include "arrayUtils.h"
int main(){
	ARRAY_UTILS array = create(4,5);
	printf("type size : %d\n", array.typeSize);
}
