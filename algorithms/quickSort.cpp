//quick sort
//author: aniket more
//date: 11/04/2020
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
{ //partitions the array and returns the pivot index
    int i, j;
    int piv = arr[lo]; //setting the pivot , this algorithm comes from nptel noc mergesort
    i = lo + 1;        //the boundary of lower zone
    for (j = lo + 1; j <= hi; j++)
    { //
        if (arr[j] <= piv)
        {
            swap(arr[j], arr[i]);
            i++;
        }
    }
    swap(arr[lo], arr[i - 1]); //putting pivot in the right place,
    //i-1 because we replace at i so at i will be an element greater than pivot as it is the next available position for the lower part.
    return (i - 1);
}
void quickSort(int arr[], int start, int end)
{                     //here index is the last elemnt included its n-1 not n
    if (start >= end) //base case of 1 element array
        return;
    int pi = partition(arr, start, end); //partitioning
    quickSort(arr, start, pi - 1);       //recursion
    quickSort(arr, pi + 1, end);         //recursion
}

int main()
{
    int n = 10;
    int arr[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    quickSort(arr, 0, 9);
    displayArray(arr, arr + n);

    return 0;
}