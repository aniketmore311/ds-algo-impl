#include <bits/stdc++.h>
using namespace std;
class Graph
{
public:
  vector<vector<int>> adj;
  vector<bool> visited;
  vector<int> distances;
  vector<int> fromNode; // keeps a record of parent of every element in bfs
  vector<int> connectedComponents;
  vector<int> stronglyConnectedComponents;
  int v; // no of vertices
  int e; // no of edeges

  Graph(int v) //constructor
  {
    this->v = v;
    adj.resize(v); //resize allocates and initialises the vector of vector
    // allocating and initialising other attributes
    visited.resize(v, false);
    distances.resize(v, -1);
    fromNode.resize(v, -1);
    connectedComponents.resize(v, -1);
    stronglyConnectedComponents.resize(v, -1);
  }

  // depth first search api
  void dfs(int s)
  {
    visited.assign(v, false); // preparing the visited array for dfs
    dfs(s, visited);
  }

  // depth first search implementation
  void dfs(int s, vector<bool> &visited)
  {
    // if visited return
    if (visited[s])
    {
      return;
    }
    else
    {
      visited[s] = true;
      //for every child of s ie every element of the vector at adj[s]
      for (auto child : adj.at(s)) // do dfs on the children
      {
        dfs(child, visited);
      }
    }
  }

  // breadth first search api
  void bfs(int s)
  {
    visited.assign(v, false);
    distances.assign(v, -1);
    fromNode.assign(v, -1);
    bfs(s, visited, distances, fromNode);
  }

  //breadth first search implementation
  void bfs(int s, vector<bool> &visited, vector<int> &distances, vector<int> &fromNode)
  {
    queue<int> q;
    // processing s
    visited[s] = true;
    distances[s] = 0;
    fromNode[s] = s;
    q.push(s); // push s to the queue

    while (!q.empty()) // while q is not empty
    {
      int parent = q.front(); // pop and get front element as parent
      q.pop();

      for (auto child : adj.at(parent)) // for all the children of the parent
      {
        // if child is visited continue
        if (visited[child])
        {
          continue;
        }
        else
        {
          visited[child] = true;                    // mark as visited
          distances[child] = distances[parent] + 1; // record the distance
          fromNode[child] = parent;                 // note the parent

          q.push(child); // push the child to the queue so that its children could be processed
        }
      }
    }
  }

  // a method that returns the reverse graph of the current graph
  vector<vector<int>> reverseGraph() // tested: works
  {
    vector<vector<int>> result;
    result.resize(v);
    int i = 0;

    for (i = 0; i < v; i++)
    {
      for (auto child : adj.at(i))
      {
        result.at(child).push_back(i);
      }
    }
    return result;
  }

  // input methods

  // input for directed graphs
  void directedInput(int e)
  {
    this->e = e;
    for (int i = 0; i < e; i++)
    {
      int u, v;
      std::cin >> u >> v;

      addEdge(u, v);
    }
  }

  // input for undirected graphs
  void undirectedInput(int e)
  {
    this->e = e;
    for (int i = 0; i < e; i++)
    {
      int u, v;
      std::cin >> u >> v;

      addEdge(u, v);
      addEdge(v, u);
    }
  }

  void addEdge(int u, int v)
  {
    adj.at(u).push_back(v);
  }

  // a method to print the graph
  void printGraph()
  {
    std::cout << "Graph: " << endl;
    int i = 0;
    for (auto parent : adj) // here parent is also a vector inside of adj
    {
      std::cout << i++ << " -> ";
      for (auto child : parent) // here child is an integer
      {
        std::cout << child << " ";
      }
      std::cout << endl;
    }
    std::cout << endl;
  }

  // a general method used to print all the vectors in the attributes
  template <typename T>
  void printVector(vector<T> vec, std::string vectorName)
  {
    std::cout << vectorName << ": " << std::endl;
    int i = 0;
    for (auto element : vec)
    {
      std::cout << i++ << ": " << element << endl;
    }
    std::cout << endl;
  }
};

// connected components in undirected graphs

// modified dfs for connected components
void dfsForConnectedComponents(int s, Graph &graph, int count)
{
  if (graph.visited[s]) // if visited return
    return;
  graph.visited[s] = true;
  graph.connectedComponents[s] = count;
  //for every child of s ie every element of the vector at adj[s]
  for (auto child : graph.adj.at(s)) // do dfs on the children
  {
    dfsForConnectedComponents(child, graph, count);
  }
}
// preprocessing method for connected components. it modifies the connected components and visited vectors
void processConnectedComponents(Graph &graph)
{
  graph.visited.assign(graph.v, false);
  graph.connectedComponents.assign(graph.v, -1);
  int i = 0;
  int count = 0;
  for (i = 0; i < graph.v; i++)
  {
    if (!graph.visited[i])
    {
      dfsForConnectedComponents(i, graph, count);
      count++;
    }
  }
}

int main()
{
  freopen("builds/input.txt", "r", stdin);
  freopen("builds/output.txt", "w", stdout);

  Graph udg(8);
  udg.undirectedInput(8);
  processConnectedComponents(udg);
  udg.printVector(udg.connectedComponents, "connected components: ");

  return 0;
}