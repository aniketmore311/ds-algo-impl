//implementation of the disjoint set union data structure
//autor: aniket more
//source : the competitive programmer's handbook
//date: 27-06-2020
#include <bits/stdc++.h>
using namespace std;

int link[100];
int size[100];

int find(int x)
{
  // follow the links upwards until you find a self linked node
  // that node is the parent
  while (link[x] != x)
    x = link[x];
  return x;
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
  if (size[a] < size[b])
    swap(a, b);
  // now a is the big set parent and b is the small set parent
  size[a] += size[b];
  // the size of set of a is increased to accomodate b
  link[b] = a;
  // b is linked to a
}

int main()
{
  freopen("builds/input.txt", "r", stdin);
  freopen("builds/output.txt", "w", stdout);

  int i;
  for (i = 0; i < 100; i++)
  {
    link[i] = i;
    size[i] = 1;
  }

  unite(1, 2);
  unite(2, 3);
  unite(4, 5);
  unite(5, 3);

  cout << find(1) << endl;
  cout << find(2) << endl;
  cout << find(3) << endl;
  cout << find(4) << endl;
  cout << find(5) << endl;
}