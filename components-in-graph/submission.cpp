#include <iostream>
#include <unordered_map>
#include <unordered_set>

using std::cin;
using std::cout;
using std::endl;

typedef int Vertex;
typedef std::unordered_set<Vertex> Graph;

typedef std::pair<Vertex, Vertex> Edge;
std::ostream &operator<<(std::ostream &out, const Edge &edge)
{
  out << "(" << edge.first << ", " << edge.second << ")";
  return out;
}

static std::unordered_map<Vertex, Graph *> graphs;

void add_edge(Vertex v1, Vertex v2);
void add_to_graph(Graph *graph, Vertex v);
void create_new_graph(Vertex v1, Vertex v2);
void merge_graphs(Graph *source, Graph *destination);

struct Result
{
  size_t min;
  size_t max;
};

Result find_result();

int main(void)
{
  size_t n;
  Vertex left, right;

  cin >> n;
  
  for (size_t i = 0; i < n; ++i)
  {
    cin >> left >> right;
    add_edge(left, right);
  }

  Result res = find_result();
  cout << res.min << " " << res.max << endl;
}

void add_edge(Vertex v1, Vertex v2)
{
  bool v1_exists = graphs.count(v1) == 1;
  bool v2_exists = graphs.count(v2) == 1;

  if (v1_exists && v2_exists)
    merge_graphs(graphs.at(v1), graphs.at(v2));
  else if (v1_exists)
    add_to_graph(graphs.at(v1), v2);
  else if (v2_exists)
    add_to_graph(graphs.at(v2), v1);
  else
    create_new_graph(v1, v2);
}

void add_to_graph(Graph *graph, Vertex v)
{
  graph->insert(v);
  graphs[v] = graph;
}

void create_new_graph(Vertex v1, Vertex v2)
{
  Graph *graph = new Graph();

  add_to_graph(graph, v1);
  add_to_graph(graph, v2);
}

Result find_result()
{
  Result ret;
  ret.min = SIZE_MAX;
  ret.max = 0;

  std::unordered_set<Graph *> checked;
  for (auto kvp : graphs)
  {
    if (checked.count(kvp.second) == 0)
    {
      checked.insert(kvp.second);
      size_t length = kvp.second->size();
      if (length < ret.min && length > 1)
        ret.min = length;
      if (length > ret.max)
        ret.max = length;
    }
  }

  return ret;
}

void merge_graphs(Graph *source, Graph *destination)
{
  if (source == destination)
    return;

  for (Vertex v : *source)
    add_to_graph(destination, v);

  delete source;
}

