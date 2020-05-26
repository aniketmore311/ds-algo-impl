// connected components in an undirected graph
// author: aniket more
// date: 26-05-2020
#include <bits/stdc++.h>
using namespace std;

bool queryConnections(int a, int b, vector<int> connections);

void processConnections(vector<int> adj[], vector<int> &connections);

// an implementation of dfs for this application
void dfsc(vector<int> adj[], vector<int> &connections, int count, int s);

template <typename T>
void printVector(vector<T> vec);

void printGraph(vector<int> adj[], int n);

void edgeInput(vector<int> adj[]);

void addEdge(vector<int> adj[], int u, int v);

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n; //n is number of nodes 0 to n-1
    cin >> n;
    vector<int> adj[n];

    edgeInput(adj);     // input of edges
    printGraph(adj, n); //printing the graph

    vector<int> connections(n); //
    processConnections(adj, connections);
    cout << queryConnections(0, 1, connections) << endl;
    cout << queryConnections(2, 3, connections) << endl;
}

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void edgeInput(vector<int> adj[])
{
    // in the input first line must be number of edges to be inserted
    // followed by pairs of integers representing edges
    int i, u, v, n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> u >> v;
        addEdge(adj, u, v);
    }
}

void printGraph(vector<int> adj[], int n)
{
    cout << "Graph: " << endl;
    int i;
    for (i = 0; i < n; i++)
    {
        cout << i << " -> ";
        for (auto num : adj[i])
        {
            cout << num << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

template <typename T>
void printVector(vector<T> vec)
{
    int i;
    int n = vec.size();
    for (i = 0; i < n; i++) // prints vec
    {
        cout << i << "-> " << vec[i] << endl;
    }
    cout << endl;
}

void dfsc(vector<int> adj[], vector<int> &connections, int count, int s)
{
    if (connections[s] != -1) // if already counted return
        return;
    connections[s] = count; // mark
    for (auto num : adj[s]) // process the children of the current node
    {
        dfsc(adj, connections, count, num);
    }
}

void processConnections(vector<int> adj[], vector<int> &connections)
{
    for (auto &num : connections) // intialising connections to all -1
    {
        num = -1;
    }
    int count = 0; // the count of connected components
    int i;
    int n = connections.size();
    for (i = 0; i < n; i++) //for every node in the graph
    {
        if (connections[i] == -1) // if it is not connected
        {
            dfsc(adj, connections, count, i); // run a dfs with that node as source
            // and mark all the nodes connected to that node as the current vlaue of count
            // now we have marked one connected component
            count++; // increment the count
        }
    }
    // printing the connection vector
    cout << "connections: \n";
    printVector<int>(connections);

    // printing the count of connected components
    cout << "there are " << count << " connected components" << endl;
}

bool queryConnections(int a, int b, vector<int> connections)
{
    return (connections[a] == connections[b]);
}