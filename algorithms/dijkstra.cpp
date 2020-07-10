//dijkstra's algorithm for single source shortest path
// author: aniket
// date: 06-07-2020
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << ": " << x << endl
#define INF 1000000000

int main()
{
  freopen("builds/input.txt", "r", stdin);
  freopen("builds/output.txt", "w", stdout);

  int n, e, i;
  int u, v, w;

  // input for n and e
  cin >> n >> e;
  vector<vector<pair<int, int>>> adj(n); // {v,w}
  vector<tuple<int, int, int>> edges(e); // {w, u, v}
  vector<int> distance(n, INF);
  vector<bool> visited(n, false);

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // pq for {weight, end} these are the pairs inside the adj which are used to model our edges

  // taking the input of edges
  for (i = 0; i < e; i++)
  {
    cin >> u >> v >> w;
    adj.at(u).push_back({v, w});
    adj.at(v).push_back({u, w});
    edges.push_back({w, u, v});
  }

  int x; // the source
  cin >> x;

  distance[x] = 0; // making the distance of the source =0 from itself
  pq.push({0, x}); // inserting it into the queue

  while (!pq.empty()) // while the queue is not empty
  {
    int u = pq.top().second; // finding the closest vertex from the source outside the tree
    pq.pop();                // taking that vertex of the queue
    if (visited[u])          // if visited return
      continue;
    visited[u] = true; // else mark visited

    for (pair<int, int> p : adj[u]) // for every surrounding edge of u ie the closest point
    {
      int v = p.first;
      int w = p.second;                  // find the end point v and the weight of the edge
      if (distance[u] + w < distance[v]) // if the path throught u to v is smaller than the current path
      {
        distance[v] = distance[u] + w; // update the distance and
        pq.push({distance[v], v});     // add the point to the queue
      }
    }
  }

  // printing the distances
  i = 0;
  for (auto dist : distance)
  {
    cout << i++ << ": " << dist << endl;
  }
}