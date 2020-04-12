#include<iostream>
using namespace std;

void displayArray(int *arr, int *end){
    int n = end -arr;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

void swap(int &a, int &b){
    int temp = a;
    a=b;
    b=temp;
}



void shellSort(int *arr, int *end){
    //it does the first step of insertion sort for all subarrays at the same time
    //then when it passes the point when it has more than 2 elements in subarray it does next step
    //it sorts multiple subarrays samultaneously rather than sorting those subarrays individually   
    int i,j;
    int n = end - arr;
    int h=1;
    while(h<n/3){
        h=h*3+1;
    }
    while(h>=1){
        for(i=h;i<n;i++){
            for(j=i;j>=h && arr[j-h]>arr[j];j-=h){
                swap(arr[j],arr[j-h]);
            }

        }
        h=h/3;
    }

}

void insertionSort(int *start, int *end){
    int n = end - start;
    int i,j;
    for(i=0;i<n;i++){
        for(j=i;j>0;j--){
            if(start[j-1]>start[j]){
                swap(start[j],start[j-1]);
            }else{
                break;
            }
        }
    }


}

void selectionSort(int *start, int* end){
    int n = end - start;
    int i,j,imin;
    for(i=0;i<n-1;i++){
        imin = i;
        for(j=i;j<n;j++){
            if(start[j]<start[imin]){
                imin =j;
            }
        }
        swap(start[i],start[imin]);
    }
    
}



int main(){
    int n=10;
    int arr[n]= {1,3,2,5,4,8,9,6,7,10};
    //selectionSort(arr,arr+n);
    //insertionSort(arr,arr+n);
    shellSort(arr,arr+n);
    displayArray(arr,arr+n);
    
    return 0;

}
