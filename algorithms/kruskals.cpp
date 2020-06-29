//kruskal's algorithm to find mst of an undirected weighted graph
//author: aniket more
//date: 29-06-2020
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << ": " << x << endl
// we need 2 data structures for this algorithm the weighted graph and the union find

// the edge class needed for the edgeweighted graph
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

// the weighted graph class
class EdgeWeightedGraph
{
public:
  vector<vector<pair<int, double>>> adj; // a vector(adj) of vectors(adjecency list) of pairs(weighted edge) of int(end vertex) and doubles(edge weight)
  int vertices;
  int edges;
  vector<Edge> edgeList;

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

  void printEdgeList()
  {
    for (auto edge : edgeList)
    {
      cout << "(" << edge.u << ", " << edge.v << ", " << edge.weight << ")" << endl;
    }
  }
};
// the union find class
class dsu
{
public:
  vector<int> parent;
  vector<int> size;
  int vertices;

  dsu(int n)
  {
    this->vertices = n;
    // making all the elements parent of themselves
    for (int i = 0; i < n; i++)
    {
      parent.push_back(i);
    }

    // making all the sizes 1
    size.resize(n, 1);
  }

  // iterative find function
  int find(int x)
  {
    // follow the links upwards until you find a self linked node
    // that node is the parent
    while (parent[x] != x)
      x = parent[x];
    return x;
  }

  // a recursive find function that uses path compression
  int findRecursive(int x)
  {
    if (parent[x] == x)
      return x;

    int result = findRecursive(parent[x]);
    parent[x] = result; // applying path compression
    return result;
  }

  // a method to see wether given inputs are in the same component or not
  bool same(int x, int y)
  {
    return (find(x) == find(y));
  }

  // the union method
  void unite(int a, int b)
  {
    a = find(a);
    b = find(b);
    // now a and b are the parents of the original arguments

    if (a == b)
      return; // return if already in the same group

    if (size[a] < size[b])
      swap(a, b);
    // now a is the bigger set's parent and b is the smaller set's parent
    size[a] += size[b];
    // the size of set a is increased to accomodate b
    parent[b] = a;
    // b is linkded to a
  }
};

// method to print the mst
void printEdgeVector(vector<Edge> edgeList)
{
  for (auto edgeItem : edgeList)
  {
    cout << "(" << edgeItem.u << ", " << edgeItem.v << ", " << edgeItem.weight << ")" << endl;
  }
}

int main()
{
  freopen("builds/input.txt", "r", stdin);
  freopen("builds/output.txt", "w", stdout);

  /*
  kruskal's algorithm
  create an edgeList
  sort the edgelist by ascending order of edgeweights
  iterate though the edgelist
    if the points of any given edge are in different connected components then
    add that edge to the mst and unite those two components
    else continue
  */

  EdgeWeightedGraph graph(6);
  graph.undirectedInput(9);
  // graph.printGraph();

  // dsu which is needed
  dsu dsu(6);

  // the final mst
  vector<Edge> mst;

  // sorting the edgeList
  sort(graph.edgeList.begin(), graph.edgeList.end());
  // no comp function is needed because of the operator overloading in the Edge class

  // graph.printEdgeList();

  // for all edges in the edgeList
  for (auto edgeItem : graph.edgeList)
  {
    if (!dsu.same(edgeItem.u, edgeItem.v)) // if vertices not in the same component
    {
      mst.push_back(edgeItem);           // add the edge to the mst
      dsu.unite(edgeItem.u, edgeItem.v); // unite the 2 components
    }
  }

  printEdgeVector(mst); // print the answer
}

// sample input
/*
0 1 1
1 3 15
3 4 6
4 5 9
5 0 14
2 0 9
2 1 10
2 3 11
2 5 2
*/

// the processed output
/*
(0, 1, 1)
(2, 5, 2)
(3, 4, 6)
(4, 5, 9)
(2, 0, 9)
*/
