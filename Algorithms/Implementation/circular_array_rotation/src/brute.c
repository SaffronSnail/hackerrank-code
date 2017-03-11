#include "shared.h"

#include <stdio.h>

void rotate_array(Array array, int rots)
{
	for (int curr_rot = 0; curr_rot < rots; ++curr_rot)
	{
		int last_value = array.data[array.size - 1];
		for (int i = array.size - 1; i > -1; --i)
		{
			array.data[i + 1] = array.data[i];
		}
		array.data[0] = last_value;
	}
}
