#include <bits/stdc++.h>
#define rep(i, n) for (i = 0; i < (n); ++i)
#define REP(i, k, n) for (i = (k); i <= (n); ++i)
#define REPR(i, k, n) for (i = (k); i >= (n); --i
#define ll long long
#define debug(x) cout << #x << ": " << x << endl
using namespace std;

//function prototypes
void solve();
void kahn(int v);
void printOrder();

// global variables
vector<int> adj[100];
int ind[100];
vector<int> result;
vector<int> pre;

/*
topological sorting is not unique
kahn's algorithm for topological sorting O(v+e)
this algorithm is similar to bfs as opposed to the reverse post order topological sort algorithm which is similar to dfs
1. keep a count of indegree of all the nodes while taking the input 
2. itertate through the indegrees[] array and if a node has indegree = 1 push it into a queue
3. while the queue is not empty
  - get the top element, push it into the result, pop it from the queue 
  - for all the children of that node 
    - reduce the indegree by one 
    - if the new indegree is one push it to the queue
*/

int main()
{
  std::ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
  freopen("builds/input.txt", "r", stdin);
  freopen("builds/output.txt", "w", stdout);
#endif
  ll t;
  cin >> t;
  // t = 1;
  while (t--)
  {
    solve();
  }

  return 0;
}

void solve()
{
  int v, e, x, y;
  cin >> e >> v;
  for (int i = 0; i < e; i++)
  {
    cin >> x >> y;
    pre.push_back(x);
    pre.push_back(y);
    adj[x].push_back(y);
    ind[y]++;
  }
  kahn(v);
  printOrder();
}

// the function which decides the sort
void kahn(int v)
{

  queue<int> q; // declaring the queue
  // finding the initial members of the queue which have an indegree of 0
  for (int i = 0; i < v; i++)
  {
    if (ind[i] == 0)
    {
      q.push(i);
    }
  }

  while (!q.empty())
  {

    int current = q.front();
    result.push_back(current);
    q.pop();

    for (auto child : adj[current])
    {
      ind[child]--;
      if (ind[child] == 0)
      {
        q.push(child);
      }
    }
  }
}

void printOrder()
{
  for (auto child : result)
  {
    cout << child << " ";
  }
  cout << endl;
}
