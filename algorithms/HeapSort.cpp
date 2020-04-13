//heap sort
//author: aniket more
//date: 13/04/2020
#include<iostream>
using namespace std;

int leftIndex(int i){ return (i*2+1);}
int rightIndex(int i){ return (i*2+2);}
int parentIndex(int i){ return (i-1)/2;}

void displayArray(int arr[], int *end){ //function to display array
    int n = end -arr;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

void swap(int &a, int &b){
    int temp =a;
    a=b;
    b=temp;
}

void bubbleDown(int arr[],int n,int i){ //function to bubble down an element
    int max =i;
    int hindex=n-1;//last element
    if(leftIndex(i)<=hindex && arr[i]<arr[leftIndex(i)])
        max = leftIndex(i);
    if (rightIndex(i)<=hindex && arr[max]<arr[rightIndex(i)])
        max = rightIndex(i);
    if(max==i)
        return;
    else{
        swap(arr[i],arr[max]);
        i=max;
        bubbleDown(arr,n,max); //recursion
    }

}

void maxHeapify(int arr[],int n){ //function to maxheapify an array
    int hindex = n-1;
    int i;
    int start = (hindex-1)/2;
    for(i=start;i>=0;i--){
        bubbleDown(arr,n,i);
    }

}

void heapSort(int arr[], int n){ //heapsort function
    int hindex =n-1;
    while(hindex>0){
        swap(arr[0],arr[hindex--]);
        bubbleDown(arr,hindex+1,0);
    }
}

int main(){
    int n=10;
    int arr[n] = {5,10,4,3,6,8,9,2,1,7};
    maxHeapify(arr,10);
    displayArray(arr,arr+n);
    heapSort(arr,n);
    displayArray(arr,arr+n);

    return 0;
}
