#include "shared.h"

#include <stdlib.h>

int circular_add(int op1, unsigned op2, int max)
{
	int ret = op1 + op2;
	while (ret >= max)
		ret -= max;
	return ret;
}

Array make_array(int size)
{
	Array ret;
	ret.data = (int *)malloc(sizeof(int) * size);
	ret.size = size;
	return ret;
}

