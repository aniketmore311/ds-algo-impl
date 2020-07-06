#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << ": " << x << endl

class EdgeWeightedGraph
{
public:
  // the edge subclass
  class Edge
  {
  public:
    int u;
    int v;
    double weight;

    Edge(int u, int v, double weight)
    {
      this->u = u;
      this->v = v;
      this->weight = weight;
    }

    bool operator<(const Edge &other) const
    {
      return this->weight < other.weight;
    }
  };
  vector<vector<pair<int, double>>> adj; // a vector(adj) of vectors(adjecency list) of pairs(weighted edge) of int(end vertex) and doubles(edge weight)
  int vertices;
  int edges;
  vector<Edge> edgeList;
  vector<bool> visited;

  // the constructor
  EdgeWeightedGraph(int vertices)
  {
    adj.resize(vertices);
    visited.resize(vertices, false);
    this->vertices = vertices;
  }

  // method to add an edge u -> v
  void addEdge(int u, int v, double weight)
  {
    adj.at(u).push_back({v, weight});
  }

  // method for undirected input
  void undirectedInput(int edges)
  {
    this->edges = edges;
    int u, v;
    double inputWeight;
    for (int i = 0; i < edges; i++)
    {
      std::cin >> u >> v >> inputWeight;

      addEdge(u, v, inputWeight);
      addEdge(v, u, inputWeight);

      // addding edge to the edgelist
      edgeList.push_back({u, v, inputWeight});
    }
  }

  // method to print the graph
  void printGraph()
  {
    int i = 0;
    for (auto list : adj)
    {
      std::cout << i++ << " -> ";
      for (auto elementPair : list)
      {
        cout << " (" << elementPair.first << ", " << elementPair.second << "), ";
      }
      std::cout << std::endl;
    }
  }

  void printEdgeList()
  {
    for (auto edge : edgeList)
    {
      cout << "(" << edge.u << ", " << edge.v << ", " << edge.weight << ")" << endl;
    }
  }
};

int main()
{
  freopen("builds/input.txt", "r", stdin);
  freopen("builds/output.txt", "w", stdout);

  EdgeWeightedGraph g(6);
  g.undirectedInput(9);
  g.printGraph();

  g.printEdgeList();
  sort(g.edgeList.begin(), g.edgeList.end());
  cout << endl;
  g.printEdgeList();
}