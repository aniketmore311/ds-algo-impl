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

//strongly connected components in directed graphs
// algorithm:
/*
* to find the strongly connected components 
* we follow a similar algorithms to that of connected components
* but instead of finding connected components by running many dfs in direct(linear) order
* we run many dfs in a special order 
* that order is the reverse post order similar to topological sort but
* we run the reverse postorder on the reverse graph of the problem graph
* so we have the reverse post order on a reverse graph as the desired order
*/

// so first we need methods that will give us the reverse post order or topological sort

// implementation of dfs for reverse post order
void dfsForReversePostorder(Graph &graph, int s, deque<int> &deq)
{
  if (graph.visited[s])
  {
    return;
  }
  else
  {
    graph.visited[s] = true;
    for (auto child : graph.adj.at(s))
    {
      dfsForReversePostorder(graph, child, deq);
    }
    deq.push_front(s);
  }
}

// method that returns a reverse post order in the form of a deque<int>
deque<int> reversePostorder(Graph &graph)
{
  deque<int> resultDeque;
  graph.visited.assign(graph.v, false);

  for (int i = 0; i < graph.v; i++)
  {
    if (!graph.visited[i])
    {
      dfsForReversePostorder(graph, i, resultDeque);
    }
  }
  return resultDeque;
}

// now we have the methods that will return the reverse post order

// modified dfs for connected components
void dfsForStronglyConnectedComponents(int s, Graph &graph, int count)
{
  if (graph.visited[s]) // if visited return
    return;
  graph.visited[s] = true;
  graph.stronglyConnectedComponents[s] = count;
  //for every child of s ie every element of the vector at adj[s]
  for (auto child : graph.adj.at(s)) // do dfs on the children
  {
    dfsForStronglyConnectedComponents(child, graph, count);
  }
}

// preprocessing method for strongly connected components.
// it modifies the stronglyconnectedcomponents and visited vectors of the graph object
void processStronglyConnectedComponents(Graph &graph)
{
  graph.visited.assign(graph.v, false);
  graph.stronglyConnectedComponents.assign(graph.v, -1);

  vector<vector<int>> reversedGraphVector = graph.reverseGraph(); // getting the adecencylist of the reversed graph

  Graph reversed(graph.v); // creating the actual object called reversed from reverseGraphVector
  // we need this object to get the reverse post order as that method takes an object arguement not an adjecencty list
  reversed.adj = reversedGraphVector;
  //reversed.printGraph(); // printing the reversed graph

  deque<int> deq;                   // deq to store the reverse post order
  deq = reversePostorder(reversed); // getting the reverse postorder on the reverse graph

  int count = 0;
  for (auto num : deq)
  {
    if (!graph.visited[num])
    {
      dfsForStronglyConnectedComponents(num, graph, count);
      count++;
      // notice that the actual strongly connected components method runs on the original graph not the reversed graph
      // the reversed graph is only used to get the order that we need to run the connected  components algorithm
      // while the actual algorithm still runs on the original graph
    }
  }
}

int main()
{
  freopen("builds/input.txt", "r", stdin);
  freopen("builds/output.txt", "w", stdout);

  // Graph graph(13);
  // graph.directedInput(22);

  // graph.printGraph();
  // processStronglyConnectedComponents(graph);
  // graph.printVector(graph.stronglyConnectedComponents, "scc");

  return 0;
}
/*
sample input
0 1
0 5
2 0
2 3
3 2
3 5
4 2
4 3
5 4
6 0
6 4
6 9
7 6
7 8
8 7
8 9
9 10
9 11
10 12
11 4
11 12
12 9

correct output:
scc: 
0: 1
1: 0
2: 1
3: 1
4: 1
5: 1
6: 3
7: 4
8: 4
9: 2
10: 2
11: 2
12: 2


*/