//priority queue with stacks as heaps
//author: aniket more
//date: 11/04/2020
#include<iostream>
using namespace std;

class Pqueue{
private:
    int size;
    int capacity;
    int hindex; //next available index
    int *heap = nullptr;
public:
    Pqueue(int capacity){
        heap = new int[capacity];
        this->capacity = capacity;
        hindex=0;
        size=0;
    }

    ~Pqueue(){
        delete[] heap;
        heap =nullptr;
    }

    int getSize(){
        return size;
    }

    int parentIndex(int i){
        return ((i-1)/2);
    }

    int leftIndex(int i){
        return (2*i+1);
    }

    int rightIndex(int i){
        return (i*2+2);
    }

    void swap(int &a, int &b){
        int temp = a;
        a = b;
        b = temp;
    }

    // void printHeap(){
    //     int i=1;
    //     int k =0;
    //     cout<<"\n";
    //     while(true){
    //         for(int j=0;j<i;j++){
    //             if(k==hindex)
    //                 return;
    //             cout<<heap[k++]<<" ";
    //         }
    //         i*=2;
    //         cout<<"\n";
    //     }
        
    // }
    void printHeapLinear(){
        for(int i=0;i<size;i++)
            cout<<heap[i]<<" ";
        cout<<"\n";
    }

    void bubbleUp(int i){
        while(i!=0 && heap[parentIndex(i)]>heap[i]){
            swap(heap[parentIndex(i)],heap[i]);
            i = parentIndex(i);
        }
    }

    void bubbleDown(int i){
        while(true){
            int minimum = i;
            if(leftIndex(i)<size && heap[leftIndex(i)]<heap[i]) 
                minimum = leftIndex(i);
            if(rightIndex(i)<size && heap[rightIndex(i)]<heap[minimum]) 
                minimum = rightIndex(i);
            if(minimum==i)
                return;
            else{
                swap(heap[i], heap[minimum]);
                i = minimum; 
            }
        }  
    }

    void insert(int n){
        if(hindex==capacity)
            throw(std::overflow_error("overflow error"));
        heap[hindex++] = n;
        size++;
        bubbleUp(hindex-1);

    }

    int poll(){
        int temp = heap[0];
        if(size==0)
            throw(std::underflow_error("underflow error"));
        else if(size==1){
            hindex = 0;
            size--;
            return temp;
        }
        heap[0] = heap[--hindex];
        size--;
        bubbleDown(0);
        return temp;
    }

    int peek(){
        return heap[0];
    }

    

    
};

int main(){
    Pqueue p (10);
    p.insert(5);
    p.insert(6);
    p.insert(4);
    p.insert(10);
    p.insert(21);
    p.insert(0);
    p.insert(7);

    p.printHeapLinear();

    cout<<p.poll()<<"\n";
    cout<<p.poll()<<"\n";
    cout<<p.poll()<<"\n";

    p.printHeapLinear();
    return 0;
}