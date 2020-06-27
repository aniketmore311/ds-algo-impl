# disjoint set union

- it is used to keep track of connected components.
- methods of the data structure
  - `find(x)`
    - finds the parent of the given node. the parent of nodes form the same connected components will be the same
  - `unite(a,b)`
    - unites the connected components containing the elements a and b
  - `same(a,b)`
    - compares a and b returns true if they are the part of the same connected component
  - complexity
    - because of the specific implementation of dsu given in the repository the complexities are as follows
      - `find() = O(log(n))` , n is the total number of nodes
      - `unite() = O(log(n))` 
      - `same() = O(log(n))` 