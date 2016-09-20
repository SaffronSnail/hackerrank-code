#include <stdio.h>
#include <stdlib.h>

#include "shared.h"

void rotate_array_nonfactor(Array array, unsigned rots, unsigned start)
{
	unsigned index = start;
	int forgotten_number = array.data[start];

	do
	{
		//rotate_index(array, index, rots, &index, &forgotten_number);
		int new_index = circular_add(index, rots, array.size);
		int new_forgotten_number = array.data[new_index];
		array.data[new_index] = forgotten_number;
		forgotten_number = new_forgotten_number;
		index = new_index;
	} while (index != start);
}

void rotate_array_factor(Array array, unsigned rots)
{
	for (unsigned u = 0; u < rots; ++u)
		rotate_array_nonfactor(array, rots, u);
}

void rotate_array(Array array, unsigned rots)
{
	// simplify calculation by never 'wrapping around'
	while (rots > array.size)
		rots -= array.size;

	if (rots == 1 || array.size % rots != 0)
		rotate_array_nonfactor(array, rots, 0);
	else
		rotate_array_factor(array, rots);
}

