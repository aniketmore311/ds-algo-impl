#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout << #x << " :" << x << endl;

class HashTable
{
private:
  list<pair<string, int>> table[91]; // an array of lists of pairs of string and integers size is 91 indexed from 0 to 90
  int R = 31;                        // a prime number needed for hashing
  int n = 91;                        // the size
public:
  int hashString(std::string inputString) // a function to hash a string it returns the hash index
  {
    int hashIndex = 0;
    for (int i = 0; i < inputString.length(); i++)
    {
      hashIndex = (hashIndex * R + ((int)inputString[i])) % n; // % n to convert the hash into the hash index
      // debug(hash);
    }
    return hashIndex;
  }

  void insert(string key, int value)
  {
    int hashIndex = hashString(key);
    table[hashIndex].push_back(make_pair(key, value));
  }

  int search(string key)
  {
    int hashIndex = hashString(key);
    for (auto listItemPair : table[hashIndex])
    {
      if (listItemPair.first == key)
      {
        return listItemPair.second;
        break;
      }
    }
  }

  void printTable()
  {
    for (int i = 0; i < 91; i++)
    {
      if (table[i].empty())
        continue;
      else
      {
        std::cout << i << ": ";
        for (auto listElementPair : table[i])
        {
          std::cout << "(" << listElementPair.first << " -> " << listElementPair.second << "), ";
        }
        std::cout << endl;
      }
    }
  }
};

int main()
{
  freopen("builds/input.txt", "r", stdin);
  freopen("builds/output.txt", "w", stdout);

  HashTable t;
  string s1, s2;
  cin >> s1 >> s2;

  t.insert(s1, 9);
  t.insert(s2, 7);

  list<int> li;
  cout << t.search(s1) << endl;
  cout << t.search(s2) << endl;

  t.printTable();
}
