#include "shared.h"

int circular_add(int op1, unsigned op2, int max)
{
	int ret = op1 + op2;
	while (ret >= max)
		ret -= max;
	return ret;
}

