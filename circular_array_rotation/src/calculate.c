#include <stdio.h>
#include <stdlib.h>

#include "shared.h"

void rotate_array_starting_at(Array array, unsigned rots, unsigned start)
{
  unsigned index = start;
  int forgotten_number = array.data[start];

# ifdef PRINTF_TRACE
  printf("Calculating starting at entry %d\n", start);
# endif

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

void rotate_array(Array array, unsigned rots)
{
  unsigned remainder = rots % array.size;

# ifdef PRINTF_TRACE
  printf("Caclualting with an array size of %d, %d rotations, and a remainder of %d\n", array.size, rots, remainder);
# endif

  if (rots > array.size && remainder != 0)
    for (unsigned u = 0; u < remainder; ++u)
      rotate_array_starting_at(array, rots, u);
  else
    rotate_array_starting_at(array, rots, 0);
}

