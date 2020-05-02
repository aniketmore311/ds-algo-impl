//binary search(iterative)
//author: aniket more
//date: 12/04/2020
#include <iostream>
using namespace std;

int bsearch(int arr[], int lo, int hi, int key)
{

    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] == key)
            return mid;
        else if (key < arr[mid])
            hi = mid - 1;
        else if (arr[mid] < key)
            lo = mid + 1;
    }
    return -1;
}

int main()
{

    int arr[5] = {1, 2, 3, 4, 5};
    cout << bsearch(arr, 0, 4, 1) << endl; //0
    cout << bsearch(arr, 0, 4, 5) << endl; //4
    cout << bsearch(arr, 0, 4, 3) << endl; //2
    cout << bsearch(arr, 0, 4, 6) << endl; //-1
}
