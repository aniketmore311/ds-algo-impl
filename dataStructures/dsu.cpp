//implementation of the disjoint set union data structure
//autor: aniket more
//source : the competitive programmer's handbook
//date: 27-06-2020
#include <bits/stdc++.h>
using namespace std;

class dsu
{
public:
  vector<int> parent;
  vector<int> size;

  dsu(int n)
  {
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

  bool same(int x, int y)
  {
    return (find(x) == find(y));
  }

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

int main()
{
  freopen("builds/input.txt", "r", stdin);
  freopen("builds/output.txt", "w", stdout);
}