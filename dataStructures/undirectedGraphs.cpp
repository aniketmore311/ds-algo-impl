#include <bits/stdc++.h>
using namespace std;

//function prototypes
void addEdge(vector<int> adj[], int u, int v);

void edgeInput(vector<int> adj[]);

void printGraph(vector<int> adj[], int n);

void dfs(vector<int> adj[], vector<bool> &visited, int s);

void bfs(vector<int> adj[], vector<bool> &visited, vector<int> &distances, int s);

void printDistances(vector<int> distances);

void printVisited(vector<bool> visited);

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n; //n is number of nodes 0 to n-1
    cin >> n;
    vector<int> adj[n];

    edgeInput(adj);     // input of edges
    printGraph(adj, n); //printing the graph

    vector<bool> visited(n, false);
    vector<int> distances(n, -1);

    bfs(adj, visited, distances, 1);
    // dfs(adj, visited, 0);

    printVisited(visited);
    printDistances(distances);
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

void printDistances(vector<int> distances)
{
    int i;
    int n = distances.size();
    cout << "distances: " << endl;
    for (i = 0; i < n; i++) // prints distances
    {
        cout << i << "-> " << distances[i] << endl;
    }
    cout << endl;
}

void printVisited(vector<bool> visited)
{
    int i;
    int n = visited.size();
    cout << "visited: " << endl;
    for (i = 0; i < n; i++) // prints distances
    {
        cout << i << "-> " << visited[i] << endl;
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

void bfs(vector<int> adj[], vector<bool> &visited, vector<int> &distances, int s)
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
