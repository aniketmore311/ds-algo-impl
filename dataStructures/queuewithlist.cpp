//queue implementaion with a linked list
//author: aniket more
//date: 16/04/2020
#include<iostream>
using namespace std;
class Queue{
private:
class Node{
    public:
        int value;
        Node* next;
    };
    
    Node* head =nullptr;
    Node *tail = nullptr;
    int size=0;

public:
    
    Queue(){}//constructor

    void Enqueue(int n){
        Node* temp = new Node;
        if(size==0){
            temp->value=n;
            temp->next =nullptr;
            head = tail = temp;
            size++;
        }else{
            temp->value=n;
            temp->next=nullptr;
            tail->next=temp;
            tail=temp;
            size++;
        }
    }

    int dequeue(){
        if(size==0){
            throw(std::underflow_error("empty list"));
        }else{
            Node* temp =head;
            int ret = head->value;
            head=head->next;
            delete temp;
            size--;
            return ret;
        }
    }

    void display(){
        Node *temp =head;
        while(temp!=nullptr){
            cout<<temp->value<<" ";
            temp = temp->next;
        }
        cout<<"\n";
    }

};
int main(){
    Queue q;
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Enqueue(40);

    q.display();

    q.dequeue();
    q.dequeue();

    q.display();

    return 0;
}
