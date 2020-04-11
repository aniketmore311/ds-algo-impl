//singly linked list
//author: aniket more
//date: 11/04/2020

#include<iostream>
using namespace std;
class List{
    private: 
    
    class Node{ //node subclass
        public:
        int data;
        Node *next;
    };
    
    Node *head = nullptr;
    Node *tail = nullptr;
    int size = 0;
    
    public:
    
    List(){};

    void printList(){ //function to print the list //works nicely
        if(isEmpty())
        {
           throw(std::underflow_error("can't display empty list!"));
        }
        Node *temp = head;
        while(temp!=nullptr){
            cout<<temp->data<<" ";
             temp = temp->next;
        
        }

        cout<<"\n";
        
    }

    bool isEmpty(){ 
        return(size==0);
    }
    
    void push(int n){ //push in front //works good
        if(isEmpty()){
            Node *temp = new Node;
            temp->data = n;
            temp->next = nullptr;

            head = temp;
            tail = temp;

            size++; 
        }
        else{
            Node *temp = new Node;
            temp->data = n;
            temp->next = head;
            head = temp;
            
            size++;
        }
    }

    int pop(){
        if(isEmpty()){ 
            throw(std::underflow_error("can not pop from an empty list!!!"));
        }else{
            int element = head->data;
            Node *temp = head;
            head = head->next;
            delete temp;
            size--;
            return element;

        }
        
    }

    void addLast(int n){ //add at the last end //works nice
        if(isEmpty()){
            Node *temp = new Node;
            temp->data = n;
            temp->next = nullptr;

            head = temp;
            tail = temp;

            size++; 
        }
        else{
            Node *temp = new Node;
            temp->data = n;
            temp->next = nullptr;

            tail->next=temp;//linking
            tail = temp; //changing tail
            
            size++;
        }
    }

    void removeNode(int key){ //removes node of the given key //works
        Node *temp = head;
        Node *prev = nullptr;
        if(temp!=nullptr && temp->data==key){ //if head is to be removed
            head = temp->next;
            delete temp;
            size--;
            return;
        }
        while(temp!=nullptr && temp->data!=key){ //iterating
            prev = temp;
            temp = temp->next;
        }
        if(temp==nullptr){ //reached end of the list
            cout<<key<<" does not exist"<<endl;
            return;
        }
        if(temp==tail) //if tail is to be removed
            tail = prev;
        prev->next = temp->next;
        delete temp;
        size--;
    }

    int search(int key){ //works
        Node *temp = head;
        int index = 0;
        while(temp!=nullptr && temp->data!=key){
            temp=temp->next;
            index++;
        }
        if(temp==nullptr)
            return -1;
        else 
            return index;

    }


    void clear(){ //clears the list 
        Node *current = head;
        Node *next = nullptr;
        while(current!=nullptr){
            next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        tail = nullptr;
        size = 0; 
    }

    ~List(){
        clear();
    }

};

int main(){
    List ls;
    ls.addLast(10);
    ls.addLast(20);
    ls.addLast(30);

    ls.printList(); //10 20 30

    ls.push(9);
    ls.push(8);

    ls.printList(); //8 9 10 20 30

    ls.removeNode(8);
    ls.removeNode(30);

    ls.printList(); // 9 10 20

    ls.addLast(40);
    ls.addLast(50);

    ls.printList(); // 9 10 20 40 50
    
    ls.pop();
    
    ls.printList(); // 10 20 40 50

    cout<<"20 at: "<<ls.search(20)<<endl;// 1
    cout<<"50 at: "<<ls.search(50)<<endl; // 3 
    cout<<"100 at: "<<ls.search(100)<<endl; //-1

    ls.clear();
    return 0;


    
}
