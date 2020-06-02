// undirected graphs, bfs, dfs
// author: aniket more
// date: 23-05-2020
#include <bits/stdc++.h>
using namespace std;
class Graph
{
private:
    vector<vector<int>> adj;
    vector<bool> visited;
    vector<int> distances;
    vector<int> fromNode; // keeps a record of parent of every element in bfs
    vector<int> connectedComponents;
    vector<int> stronglyConnectedComponents;
    int v; // no of vertices
    int e; // no of edeges

public:
    Graph(int v) //constructor
    {
        this->v = v;
        adj.resize(v); //allocates and initialises the vector of vector
        // allocating and initialising other attributes
        visited.resize(v, false);
        distances.resize(v, -1);
        fromNode.resize(v, -1);
        connectedComponents.resize(v, -1);
        stronglyConnectedComponents.resize(v, -1);
    }

    void dfs(int s) // api for dfs
    {
        visited.assign(v, false); // preparing the visited array for dfs
        dfs(s, visited);
    }

    void dfs(int s, vector<bool> &visited) // the recursive dfs implementation
    {
        if (visited[s]) // if visited return
            return;
        visited[s] = true;
        //for every child of s ie every element of the vector at adj[s]
        for (auto child : adj[s]) // do dfs on the children
        {
            dfs(child, visited);
        }
    }

    void bfs(int s) // api for bfs
    {
        visited.assign(v, false);
        distances.assign(v, -1);
        fromNode.assign(v, -1);
        bfs(s, visited, distances, fromNode);
    }

    // actual bfs function
    void bfs(int s, vector<bool> &visited, vector<int> &distances, vector<int> &fromNode)
    {
        queue<int> q;
        // processing s
        visited[s] = true;
        distances[s] = 0;
        fromNode[s] = s;
        q.push(s); // push s to the string

        while (!q.empty()) // while q is not empty
        {
            int parent = q.front(); // pop and get front element as parent
            q.pop();

            for (auto child : adj[parent]) // for all the children of the parent
            {
                if (visited[child]) // if the child is visited before then return
                    continue;

                visited[child] = true;                    // mark as visited
                distances[child] = distances[parent] + 1; // record the distance
                fromNode[child] = parent;                 // note the parent

                q.push(child); // push the child to the queqe so that its children could be processed
            }
        }
    }

    // topological sort
    // this function prints the topological sort
    void topologicalSort() //tested : works
    {
        deque<int> dq; // stack for the reverse post order (deque acts as a stack)
        // post order is the order in which the points are done
        // i.e. all the children of that node have been processed then only it is done
        // and reverse of that is the topological sort
        visited.assign(v, false); // preparing the visited vector for dfs
        // to make sure that all the connected components are covered the following for loop is implemented
        // if we make only one dfs call from the root then
        // the nodes which are nor reachable from the node will not be considered
        // hence it is important to make multiple dfs calls
        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                dfsSort(i, dq, visited);
            }
        }
        // now our deque contains the topological sort order
        // printing the stack(deque)
        cout << "Topological Sort: " << endl;
        for (auto num : dq)
        {
            cout << num << " ";
        }
        cout << "\n";
    }

    // the dfs method for topological sort
    // it pushes a node into the stack(deque.push_front) once its done processing all its children
    void dfsSort(int s, deque<int> &dq, vector<bool> &visited)
    {
        if (visited[s])
            return;

        visited[s] = true;
        for (auto child : adj[s])
        {
            dfsSort(child, dq, visited);
        }
        // the parent is pushed to the stack(deque) only after all of children have been processed
        dq.push_front(s);
    }

    // connected components in undirected graphs

    void processConnectedComponents()
    {
        visited.assign(v, false);
        connectedComponents.assign(v, -1);
        int i = 0;
        int count = 0;
        for (i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                dfsConnectedComponents(i, visited, count);
                count++;
            }
        }
    }

    void dfsConnectedComponents(int s, vector<bool> &visited, int count)
    {
        if (visited[s]) // if visited return
            return;
        visited[s] = true;
        connectedComponents[s] = count;
        //for every child of s ie every element of the vector at adj[s]
        for (auto child : adj[s]) // do dfs on the children
        {
            dfsConnectedComponents(child, visited, count);
        }
    }

    //strongly connected components in directed graphs
    // algorithm:
    /*
    * to find the strongly connected components 
    * we follow a similar algorithms to that of connected components
    * but instead of finding connected components by running many dfs in direct order
    * we run many dfs in a special order 
    * that order is the reverse post order similar to topological sort but
    * we run the algorithms on the reverse graph of the problem graph
    * so we have the reverse post order on a reverse graph
    */
    // vector<vector<int>> reverseGraph() // tested: works
    // {
    //     vector<vector<int>> result;
    //     result.resize(v);
    //     int i = 0;

    //     for (i = 0; i < v; i++)
    //     {
    //         for (auto child : adj.at(i))
    //         {
    //             result.at(child).push_back(i);
    //         }
    //     }
    //     return result;
    // }

    // // method that returns reverse post order in a deque
    // deque<int> reversePostOrder()
    // {
    //     stack<int> st;            // stack for the reverse post order
    //     visited.assign(v, false); // preparing the visited vector for dfs
    //     for (int i = 0; i < v; i++)
    //     {
    //         if (!visited[i])
    //         {
    //             dfsSort(i, st, visited);
    //         }
    //     }
    // }

    // void processStronglyConnectedComponents()
    // {
    // }

    // input methods

    // input for directed graphs
    void directedInput(int e) // input for directed graph
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
    void undirectedInput(int e) // input for undirecred graph
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
    void printVector(vector<T> vec)
    {
        int i = 0;
        for (auto element : vec)
        {
            std::cout << i++ << ": " << element << endl;
        }
        std::cout << endl;
    }

    void printVisited()
    {
        std::cout << "visited: " << endl;
        printVector<bool>(visited);
    }

    void printDistances()
    {
        std::cout << "distances: " << endl;
        printVector<int>(distances);
    }

    void printFromNode()
    {
        std::cout << "from Node: " << endl;
        printVector<int>(fromNode);
    }

    void printConnectedComponents()
    {
        std::cout << "connected components: " << endl;
        printVector<int>(connectedComponents);
    }
};

int main()
{
    freopen("builds/input.txt", "r", stdin);
    freopen("builds/output.txt", "w", stdout);

    
}
