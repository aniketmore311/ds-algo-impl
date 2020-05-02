#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void displayArray(int arr[], int *end)
{
    int n = end - arr;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int partition(int arr[], int lo, int hi)
{
    int piv = arr[lo];
    int lowerNext = lo + 1;
    int it;
    for (it = lo + 1; it <= hi; it++)
    {
        if (arr[it] >= piv)
        {
            swap(arr[it], arr[lowerNext++]);
        }
    }
    swap(arr[lo], arr[--lowerNext]);
    return lowerNext;
}

int nthlargest(int arr[], int n, int lo, int hi)
{
    int target = n - 1;
    int index;
    while (lo <= hi)
    {
        index = partition(arr, lo, hi);
        if (index == target)
            return arr[index];
        else if (target < index)
        {
            hi = index - 1;
        }
        else if (index < target)
        {
            lo = index + 1;
        }
    }
}

int main()
{
    int n = 10;
    int arr[10] = {5, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    cout << nthlargest(arr, 10, 0, 9) << endl;
    displayArray(arr, arr + n);
    return 0;
}