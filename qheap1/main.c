#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// TYPE DEFINTIIONS
typedef int Data;
typedef unsigned Height;
typedef unsigned Index;

struct HeapData
{
  Data data;
  Height height;
  Index left;
  Index right;
};

#define HEAP_LENGTH_DEF 100000
static struct HeapData heap[HEAP_LENGTH_DEF];

// CONSTANTS
static const int HEAP_LENGTH = HEAP_LENGTH_DEF;
#undef HEAP_LENGTH_DEF

static const Data EMPTY_NODE_VALUE = INT_MIN;

// HELPER FUNCTION DECLARATIONS
static inline bool is_odd(int arg);

static inline Index left_index(Index index);
static inline Index parent_index(Index index);
static inline Index right_index(Index index);

static inline bool node_exists(Index index);

static void insert_aux(Data data, Index index);
static inline void insert(Data data);

// MAIN
int main(void)
{
  for (Index i = 0; heap[i].data < HEAP_LENGTH; ++i)
    heap[i].data = EMPTY_NODE_VALUE;

  return 0;
}

// HELPER FUNCTION DEFINITIONS
static inline bool is_odd(int arg)
{
  return arg & 1;
}

void insert(Data data)
{
  insert_aux(data, 0);
}

void insert_aux(Data data, Index index)
{
  if(!node_exists(index))
  {
    heap[index].data = data;
    heap[index].height = 0;
  }
  else if (heap[index].data < data)
  {
    
  }
  else
  {
    heap[index].height += 1;
    Index left = left_index(index);
    Index right = right_index(index);

    if (heap[left].height < heap[right].height)
      insert_aux(data, left);
    else
      insert_aux(data, right);
  }
}

Index left_index(Index index)
{
  return right_index(index) - 1;
}

static inline bool node_exists(Index index)
{
  return heap[index].data == EMPTY_NODE_VALUE;
}

Index perent_index(Index index)
{
  return (is_odd(index) ? (index + 1) / 2 : index / 2) - 1;
}

Index right_index(Index index)
{
  return (index + 1) * 2;
}

