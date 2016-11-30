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
static HeapNodePtr head;

#define HEAP_LENGTH_DEF 100 * 1000
static HeapNode heap[HEAP_LENGTH_DEF];

// CONSTANTS
static const unsigned HEAP_LENGTH = HEAP_LENGTH_DEF;
#undef HEAP_LENGTH_DEF

static const HeapNodePtr NULL_NODE = (unsigned)-1;

// HEAP INTERFACE DECLARATIONS
static inline HeapNodePtr new_node();
static inline void        delete(Data data);
static inline Data        get_min();
static inline void        init();
static inline void        insert(Data data);

// HEAPNODE INTERFACE DELCARATIONS
static inline void delete_node(HeapNodePtr this);
static HeapNodePtr find_node(Data data);
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
static inline void decrement_height(HeapNodePtr position);

// HELPER FUNCTION DECLARATIONS
static inline bool is_odd(int arg);

static void insert_aux(Data data, HeapNodePtr this, HeapNodePtr parent);
static void insert_node(Data data, HeapNodePtr this);
static void replace_node(HeapNodePtr target, HeapNodePtr source);

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
  HeapNodePtr target = find_node(data);
  HeapNodePtr lesser;

  if (get_data(get_left(target)) < get_data(get_right(target)))
  {
    lesser = get_left(target);
    set_left(target, NULL_NODE);
  }
  else
  {
    lesser = get_right(target);
    set_right(target, NULL_NODE);
  }

  replace_node(target, lesser);
  delete_node(target);
}

Data get_min()
{
  return heap[head].data;
}

void init()
{
  head = NULL_NODE;
}

void insert(Data data)
{
  insert_aux(data, head, NULL_NODE);
}

HeapNodePtr new_node()
{
  for (unsigned index = 0; index < HEAP_LENGTH; ++index)
    if(!node_exists(index))
      return index;

  fprintf(stderr, "Cannot allocate a new node! All are in use!");
  return NULL_NODE;
}

// HEAPNODE INTERFACE DEFINITIONS
void decrement_height(HeapNodePtr this)
{
  heap[this].height -= 1;
}

void delete_node(HeapNodePtr this)
{
  (void)this;
}

void increment_height(HeapNodePtr this)
{
  heap[this].height += 1;
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
  return node != NULL_NODE;
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
void add_child(HeapNodePtr target, HeapNodePtr new_child)
{
  HeapNodePtr left, right;
  while (get_data(target) > get_data(new_child) &&
         node_exists(left) && node_exists(right)
        )
  {
    left = get_left(target), right = get_right(target);
    target = (get_height(left) < get_height(right)) ? left : right;
  }

  if (!node_exists(left))
    set_left(target, new_child);
  else if (!node_exists(right))
    set_right(target, new_child);
  else
    replace_node(target, new_child);
}

HeapNodePtr find_node(Data data)
{
  for (HeapNodePtr index = 0; index < HEAP_LENGTH; ++index)
    if (heap[index].data == data)
      return index;
  fprintf(stderr, "Node value %d not found!", data);
  return NULL_NODE;
}

void insert_aux(Data data, HeapNodePtr node, HeapNodePtr parent)
{
  if(!node_exists(node))
  {
    set_data(node, data);
    set_height(node, 0);
    set_left(node, NULL_NODE);
    set_parent(node, parent);
    set_right(node, NULL_NODE);
  }
  else if (heap[node].data > data)
    insert_node(data, node);
  else
  {
    increment_height(node);

    HeapNodePtr left_node = get_left(node);
    HeapNodePtr right_node = get_right(node);

    if (get_height(left_node) < get_height(right_node))
      insert_aux(data, left_node, node);
    else
      insert_aux(data, right_node, node);
  }
}

void insert_node(Data data, HeapNodePtr position)
{
  HeapNodePtr parent = heap[position].parent;

  //set up the new node
  HeapNodePtr node = new_node();
  set_data(node, data);
  set_height(node, get_height(node) + 1);
  set_left(node, position);
  set_parent(node, parent);
  set_right(node, NULL_NODE);

  // update the replaced node
  set_parent(position, node);

  // update the replaced node's parent
  if (heap[parent].left == node)
    heap[parent].left = node;
  else
    heap[parent].right = node;
}

bool is_odd(int arg)
{
  return arg & 1;
}

void replace_node(HeapNodePtr target, HeapNodePtr source)
{
  HeapNodePtr parent = get_parent(target);

  // update the target node's parent
  if (get_left(parent) == target)
    set_left(parent, source);
  else
    set_right(parent, source);

  // update the source node
  set_parent(source, parent);
  if (node_exists(get_left(target)))
    add_child(source, get_left(target));
  if (node_exists(get_right(target)))
    add_child(source, get_right(target));
}

