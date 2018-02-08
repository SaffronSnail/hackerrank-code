#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::endl;

typedef int Vertex;
typedef std::unordered_map<Vertex, std::unordered_set<Vertex> > AdjacencyList;
typedef std::unordered_set<Vertex> Graph;
typedef std::vector<Graph> GraphSet;

void extract_graph_aux(AdjacencyList &list, const AdjacencyList::iterator &current, Graph &result) {
  for (auto neighbor : current->second)
    if (result.insert(neighbor).second)
      extract_graph_aux(list, list.find(neighbor), result);
}

Graph extract_graph(AdjacencyList &list) {
  Graph ret;

  auto origin = list.begin();
  ret.insert(origin->first);
  extract_graph_aux(list, origin, ret);

  for (Vertex v : ret)
    list.erase(v);
  return ret;
}

std::istream &operator>>(std::istream &in, GraphSet &gs) {
  size_t n;
  in >> n;

  AdjacencyList edges;
  edges.reserve(n * 2);

  for (size_t i = 0; i < n; ++i)
  {
    Vertex v1, v2;
    in >> v1 >> v2;
    edges[v1].insert(v2);
    edges[v2].insert(v1);
  }

  while (!edges.empty())
    gs.push_back(extract_graph(edges));

  return in;
}

std::ostream &operator<<(std::ostream &os, Graph &set) {
  for (Vertex v : set)
    os << v << " ";
  return os;
}

std::ostream &operator<<(std::ostream &os, GraphSet &set) {
  for (Graph g : set)
    os << g << endl;
  return os;
}

int main(void)
{
  GraphSet data;
  std::cin >> data;

  size_t min = SIZE_MAX, max = 0;

  for (const auto &graph : data)
  {
    size_t length = graph.size();
    min = std::min(length, min);
    max = std::max(length, max);
  }

  std::cout << min << " " << max << endl;
}
