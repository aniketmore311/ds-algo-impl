//contains function to resize a array
//author: aniket more
//date: 11/04/2020
#include<iostream>
using namespace std;

void resize(int *arr, int size, int &capacity){
    if(size==capacity){
        int *temp = new int[2*capacity];
        capacity*=2;

        for(int i=0;i<size;i++){
            temp[i]=arr[i];
        }
        delete[] arr;
        arr=temp;
        temp=nullptr;
    }else if(size=capacity/4){
        int *temp = new int[capacity/2];
        capacity=capacity/2;

        for(int i=0;i<size;i++){
            temp[i]=arr[i];
        }
        delete[] arr;
        arr=temp;
        temp=nullptr;
    }
}

void displayArray(int *arr, int *end){
    int n = end -arr;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}
int main(){
    

    return 0;
}
