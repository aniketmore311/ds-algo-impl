//counting sort
//author: aniket more
//date: 11/04/2020
#include<iostream>
using namespace std;

void displayArray(int arr[], int *end){
    int n = end -arr;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

void countingSort(int arr[],int n, int final[], int counting[], int k){
    int i;
    for(i=0;i<k;i++){
        counting[i] = 0;
    }

    for(i=0;i<n;i++){
        counting[arr[i]]++;
    }
    //now the number of times n occurs = counting[n]
    for(i=1;i<k;i++){
        counting[i] = counting[i]+counting[i-1];
    }
    //now the number of times any number occurs less than or equal to n is counting[n]
    //so the index of any number n in final from arr will be one less than the value at the index n in counting.
    //we reduce counting elements at counting to keep track of duplicate items 
    for(i=n-1;i>=0;i--){
        final[counting[arr[i]]-1] = arr[i];
        counting[arr[i]]--;
    }

}
int main(){

    int n=10;
    int k=6;
    int arr[n] ={1,3,4,5,0,4,3,2,0,1};
    int final[n];
    int counting[k];
    countingSort(arr,n,final,counting,k);
    displayArray(final,final+n);

    return 0;
}