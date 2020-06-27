#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << ": " << x << endl

class EdgeWeightedGraph
{
private:
  vector<vector<pair<int, double>>> adj; // a vector(adj) of vectors(adjecency list) of pairs(weighted edge) of int(end vertex) and doubles(edge weight)
  int vertices;
  int edges;

public:
  vector<tuple<int, int, double>> edgeList;

  EdgeWeightedGraph(int vertices)
  {
    adj.resize(vertices);
    this->vertices = vertices;
  }

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
};

int main()
{
  freopen("builds/input.txt", "r", stdin);
  freopen("builds/output.txt", "w", stdout);

  EdgeWeightedGraph g(4);
  g.undirectedInput(4);
  g.printGraph();
}