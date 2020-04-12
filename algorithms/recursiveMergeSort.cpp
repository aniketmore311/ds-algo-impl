//merge sort
//author: aniket more
//date: 11/04/2020
#include<iostream>
using namespace std;

void merge(int arr[],int lo,int mid,int hi){
    int n = hi-lo+1;//total size
    int s1 = mid-lo+1;//size1
    int s2 = n-s1;//size2
    int i,j,k=lo;
    int temp1[s1];//temp array
    int temp2[s2];//temp array
    for(i=0;i<s1;i++){ //filling temp arrays
        temp1[i]=arr[k++];
    }
    for(j=0;j<s2;j++){ //filling temp arrays
        temp2[j]=arr[k++];
    }
    
    i=0;
    j=0;
    
    for(k=lo;k<=hi;k++){ //the merge
        if(i>=s1)
            arr[k]=temp2[j++];
        else if(j>=s2)
            arr[k]=temp1[i++];
        else if(temp2[j]<temp1[i]){
            arr[k]=temp2[j++]; 
        }else{
            arr[k]=temp1[i++];
        }
    }
}

void mergeSort(int arr[],int lo,int hi){
    if(lo<hi){
        int mid = (lo+hi)/2;
        mergeSort(arr,lo,mid);
        mergeSort(arr,mid+1,hi);

        merge(arr,lo,mid,hi);

    }
         
}

void displayArray(int arr[], int *end){
    int n = end -arr;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

int main(){
    int n=10;
    int arr[10] = {10,9,8,7,6,5,4,3,2,1};
    mergeSort(arr,0,9);
    displayArray(arr,arr+n);

    
    return 0;
}