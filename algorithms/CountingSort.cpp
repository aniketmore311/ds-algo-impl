//counting sort
//author: aniket more
//date: 11/04/2020
#include <iostream>
using namespace std;

void displayArray(int arr[], int *end)
{
    int n = end - arr;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void countingSort(int arr[], int n, int final[], int counting[], int k) // here n is the length of array and
// k is (last element +1) so that the last index of counting is counting[last element]
{
    int i;
    for (i = 0; i < k; i++)
    {
        counting[i] = 0;
    }

    for (i = 0; i < n; i++) // recording frequencies in counting[]
    {
        counting[arr[i]]++;
    }
    //at his point because of last step the number of times n occurs = counting[n]
    for (i = 1; i < k; i++)
    {
        counting[i] = counting[i] + counting[i - 1];
    }
    //now the number of times any number which is less than or equal to n appears in arr[] is counting[n]
    //so the index of any number n in final[] from arr[] will be one less than the value at the index n in counting,
    // one less than counting[n] because final is zero based
    //if the final[] was one based then the index in final[] at which any element n from arr[] appears will be counting[n]
    //we reduce counting[element] by 1 as we place them in final[] from arr[] to keep track of duplicate items
    
    //in the following step we start picking up elements from arr[] and start placing them in final[] basedn on their index 
    //the job of the counting[n] is to provide us with the index where to place n which is present in arr[]  
    for (i = n - 1; i >= 0; i--)
    {
        final[counting[arr[i]] - 1] = arr[i];
        counting[arr[i]]--;
    }
}
int main()
{

    int n = 10;
    int k = 6;
    int arr[n] = {1, 3, 4, 5, 0, 4, 3, 3, 0, 1};
    int final[n];
    int counting[k];
    countingSort(arr, n, final, counting, k);
    displayArray(final, final + n);

    return 0;
}