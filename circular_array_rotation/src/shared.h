#ifndef SHARED_H
#define SHARED_H

typedef struct
{
	int *data;
	unsigned size;
} Array;

int circular_add(int op1, unsigned op2, int max);

#endif

