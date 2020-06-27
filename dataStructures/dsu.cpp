//implementation of the disjoint set union data structure
//autor: aniket more
//source : the competitive programmer's handbook
//date: 27-06-2020
#include <bits/stdc++.h>
using namespace std;

int parent[100];
int size[100];

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
  // now a is the big set's parent and b is the small set's parent
  size[a] += size[b];
  // the size of set a is increased to accomodate b
  parent[b] = a;
  // b is linkded to a
}

int main()
{
  freopen("builds/input.txt", "r", stdin);
  freopen("builds/output.txt", "w", stdout);

  // int i;
  // for (i = 0; i < 100; i++)
  // {
  //   parent[i] = i;
  //   size[i] = 1;
  // }

  // int e = 5;
  // for (i = 0; i < e; i++)
  // {
  //   int a, b;
  //   cin >> a >> b;
  //   unite(a, b);
  // }

  // for (i = 1; i < 6; i++)
  // {
  //   cout << findRecursive(i) << endl;
  // }

  // for (i = 1; i < 6; i++)
  // {
  //   cout << parent[i] << endl;
  // }
}