#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TYPE DEFINTIIONS
typedef int Data;
typedef unsigned Height;
typedef unsigned HeapNodePtr;

typedef struct HeapNode
{
  Data data;
  Height height;
  HeapNodePtr left;
  HeapNodePtr right;
  HeapNodePtr parent;
} HeapNode;

// HEAP DEFNITION
#define HEAP_LENGTH_DEF 100000
static HeapNode heap[HEAP_LENGTH_DEF];
static HeapNodePtr head;

// CONSTANTS
static const int HEAP_LENGTH = HEAP_LENGTH_DEF;
#undef HEAP_LENGTH_DEF

static const Data  EMPTY_NODE_VALUE = INT_MIN;
static const HeapNodePtr NULL_NODE = (unsigned)-1;

// HEAP INTERFACE DECLARATIONS
static inline void delete(Data data);
static inline Data get_min();
static inline void init();
static inline void insert(Data data);

// HEAPNODE INTERFACE DELCARATIONS
static inline void init_node(HeapNodePtr this, Data data);
static inline void delete_heap_node(HeapNodePtr this);
static inline bool node_exists(HeapNodePtr this);

static inline Data        get_data(HeapNodePtr this);
static inline Height      get_height(HeapNodePtr this);
static inline HeapNodePtr get_left(HeapNodePtr this);
static inline HeapNodePtr get_parent(HeapNodePtr this);
static inline HeapNodePtr get_right(HeapNodePtr this);

static inline void set_data(HeapNodePtr this, Data data);
static inline void set_height(HeapNodePtr this, Height height);
static inline void set_left(HeapNodePtr this, HeapNodePtr new_left);
static inline void set_parent(HeapNodePtr this, HeapNodePtr new_parent);
static inline void set_right(HeapNodePtr this, HeapNodePtr new_right);

static inline void increment_height(HeapNodePtr this);
static inline void decrement_height(HeapNodePtr this);

// HELPER FUNCTION DECLARATIONS
static inline bool is_odd(int arg);

static void insert_aux(Data data, HeapNodePtr this, HeapNodePtr parent);
static void replace_node(Data data, HeapNodePtr this);

// MAIN
int main(void) {
  init();
  unsigned num_queries;
  scanf("%d", &num_queries);
  for (unsigned curr_query = 0; curr_query < num_queries; ++curr_query)
  {
    unsigned query;
    scanf("%d", &query);

    if (query == 3)
      printf("%d\n", get_min());
    else
    {
      Data arg;
      scanf("%d", &arg);
      
      if (query == 1)
        insert(arg);
      else
        delete(arg);
    }
  }
  return 0;
}

// HEAP INTERFACE DEFINITIONS
void delete(Data data)
{
#error TODO: implement delete funciton
}

Data get_min()
{
  return heap[head].data;
}

void init()
{
  head = 0;
  for (HeapNodePtr i = 0; heap[i].data < HEAP_LENGTH; ++i)
    heap[i].data = EMPTY_NODE_VALUE;
}

void insert(Data data)
{
  insert_aux(data, head, NULL_NODE);
}

// HEAPNODE INTERFACE DEFINITIONS
void decrement_height(HeapNodePtr this)
{
  heap[this].height -= 1;
}

void delete_heap_node(HeapNodePtr this)
{
  set_data(this, EMPTY_NODE_VALUE);
}

void increment_height(HeapNodePtr this)
{
  heap[this].height += 1;
}

void init_node(HeapNodePtr this, Data data)
{
  set_data(this, data);
  set_height(this, 0);
  set_left(this, NULL_NODE);
  set_right(this, NULL_NODE);
  set_parent(this, NULL_NODE);
}

Data get_data(HeapNodePtr this)
{
  return heap[this].data;
}

Height get_height(HeapNodePtr this)
{
  return heap[this].height;
}

HeapNodePtr get_left(HeapNodePtr this)
{
  return heap[this].left;
}

HeapNodePtr get_parent(HeapNodePtr node)
{
  return heap[node].parent;
}

HeapNodePtr get_right(HeapNodePtr node)
{
  return heap[node].right;
}

bool node_exists(HeapNodePtr node)
{
  return heap[node].data == EMPTY_NODE_VALUE;
}

void set_data(HeapNodePtr this, Data data)
{
  heap[this].data = data;
}

void set_height(HeapNodePtr this, Height height)
{
  heap[this].height = height;
}

void set_left(HeapNodePtr this, HeapNodePtr left)
{
  heap[this].left = left;
}

void set_parent(HeapNodePtr this, HeapNodePtr parent)
{
  heap[this].parent = parent;
}

void set_right(HeapNodePtr this, HeapNodePtr right)
{
  heap[this].right = right;
}

// HELPER FUNCTION DEFINITIONS
void insert_aux(Data data, HeapNodePtr node, HeapNodePtr parent)
{
  if(!node_exists(node))
    init_node(node, data);
  else if (heap[node].data > data)
    replace_node(data, node);
  else
  {
    increment_height(node);

    HeapNodePtr left_node = left(node);
    HeapNodePtr right_node = right(node);

    if (height_of(left_node) < height_of(right_node))
      insert_aux(data, left_node, node);
    else
      insert_aux(data, right_node, node);
  }
}

bool is_odd(int arg)
{
  return arg & 1;
}

void replace_node(Data data, HeapNodePtr target)
{
  HeapNodePtr parent = heap[target].parent;

  HeapNodePtr new_node = new_heap_node();
  init_heap_node(new_node, data, parent);

  if (heap[parent].left == new_node)
    heap[parent].left = new_node;
  else
    heap[parent].right = new_node;

# error TODO: finish implementing replace_node
}

