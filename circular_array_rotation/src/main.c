#include <stdio.h>

#include "shared.h"

int main()
 {
  unsigned num_elems, num_rots, num_queries;
  scanf("%d %d %d", &num_elems, &num_rots, &num_queries);
  
  Array array = make_array(num_elems);
  for (unsigned i = 0; i < num_elems; ++i)
    scanf("%d", array.data + i);
  
  rotate_array(array, num_rots);
  
  int query;
  for (unsigned i = 0; i < num_queries; ++i)
  {
    scanf("%d", &query);
    printf("%d\n", array.data[query]);
  }
  
  return 0;
}

