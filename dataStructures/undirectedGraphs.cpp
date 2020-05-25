// undirected graphs, bfs, dfs
// author: aniket more
// date: 23-05-2020
#include <bits/stdc++.h>
using namespace std;

//function prototypes
void addEdge(vector<int> adj[], int u, int v);

void edgeInput(vector<int> adj[]);

void printGraph(vector<int> adj[], int n);

void dfs(vector<int> adj[], vector<bool> &visited, int s); // the recursive implementation

void dfs(vector<int> adj[], int n, int s); // the api

void bfs(vector<int> adj[], vector<bool> &visited, vector<int> &distances, int s);

void bfs(vector<int> adj[], int n, int s); //api

template <typename T>
void printVector(vector<T> vec);

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n; //n is number of nodes 0 to n-1
    cin >> n;
    vector<int> adj[n];

    edgeInput(adj);     // input of edges
    printGraph(adj, n); //printing the graph

    dfs(adj, n, 0);
    bfs(adj, n, 0);
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

void dfs(vector<int> adj[], vector<bool> &visited, int s)
{
    if (visited[s]) // if visites return
        return;
    visited[s] = true;      // else mark as visited
    for (auto num : adj[s]) // and go through the children
    {
        dfs(adj, visited, num);
    }
}
void dfs(vector<int> adj[], int n, int s) //api
{

    vector<bool> visited(n, false);
    dfs(adj, visited, s);

    cout << "visited" << endl; // print the visited vector
    printVector<bool>(visited);
}

void bfs(vector<int> adj[], vector<bool> &visited, vector<int> &distances, int s) //true function
{
    queue<int> q;

    visited[s] = true; // processing s
    distances[s] = 0;
    q.push(s);         // push s into queue
    while (!q.empty()) // while queue is not empty
    {
        int parent = q.front(); // get the queue front
        q.pop();
        for (auto child : adj[parent]) // for all its childs
        {
            if (visited[child]) // if visited skip
                continue;
            visited[child] = true;                    // else mark visited
            distances[child] = distances[parent] + 1; // note distance from s
            q.push(child);                            // push each child into the queue so that their children could be processed
        }
    }
}
void bfs(vector<int> adj[], int n, int s) //api
{
    vector<bool> visited(n, false);
    vector<int> distances(n, -1);
    bfs(adj, visited, distances, s);

    cout << "visited" << endl;
    printVector<bool>(visited);
    cout << "distances" << endl;
    printVector<int>(distances);
}
