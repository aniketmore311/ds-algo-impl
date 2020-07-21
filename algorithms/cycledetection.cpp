#include <bits/stdc++.h>
#define rep(i, n) for (i = 0; i < (n); ++i)
#define REP(i, k, n) for (i = (k); i <= (n); ++i)
#define REPR(i, k, n) for (i = (k); i >= (n); --i
#define ll long long
#define debug(x) cout << #x << ": " << x << endl
#define D(x)                 \
  cout << "[" << #x << ": "; \
  for (auto it : x)          \
    cout << it << " ";       \
  cout << "]" << endl;
using namespace std;

/*
the cycle is detected when we come across such a node during dfs that 
has been visired before and isn't the parent of the source such an edge is called a backedge
this algorithm check for a backedge in the current node and if it not present 
in the current node then it checks all the children if still the answer is no then only it returns false
*/

bool cycledfs(vector<int> adj[], vector<bool> &visited, int s, int p)
{
  visited[s] = true;
  for (auto child : adj[s])
  {
    if (!visited[child])
    {
      // if there is a backedge in the this child and any of its children
      if (cycledfs(adj, visited, child, s) == true)
        return true;
    }
    // if child is already visited
    else
    {
      // if there is backedge between the source and the current child
      if (child != p)
        return true;
    }
  }
  // if no child returns true means there is no cycle
  return false;
}

void solve()
{
  int n, m;
  int x, y;
  cin >> n >> m;
  vector<int> adj[n];             // the adjecency list
  vector<bool> visited(n, false); // the visited array

  // forming the adj
  for (int i = 0; i < m; i++)
  {
    cin >> x >> y;
    x--;
    y--;
    // undirected input
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  bool result = cycledfs(adj, visited, 0, -1);
  cout << result << endl;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
  freopen("builds/input.txt", "r", stdin);
  freopen("builds/output.txt", "w", stdout);
#endif
  ll t;
  // cin >> t;
  t = 1;
  while (t--)
  {
    solve();
  }

  return 0;
}

// test input: undirected contains a cycle
/*
5 5
1 2
2 3
2 4
3 4
4 5
*/