//implementing stack with a linked list
//author: aniket more
//date: 11/04/2020
#include <iostream>
using namespace std;

template <typename T>
class Lstack
{
private:
    class Node
    {
    public:
        T data;
        Node *next;
    };

    Node *head = nullptr;
    int size = 0;

public:
    Lstack() {}

    bool isempty()
    {
        return (size == 0);
    }

    int getSize()
    {
        return size;
    }

    void push(T n)
    {
        if (isempty())
        {
            Node *temp = new Node;
            temp->data = n;
            temp->next = nullptr;

            head = temp;
            size++;
        }
        else
        {
            Node *temp = new Node;
            temp->data = n;
            temp->next = head;

            head = temp;
            size++;
        }
    }

    T pop()
    {
        if (isempty())
        {
            throw(std::underflow_error("underflow error !!"));
        }
        Node *temp = head;

        T element = head->data;
        head = head->next;
        delete temp;
        size--;
        return element;
    }

    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }

    void clear()
    {
        Node *trav = head;
        Node *travNext = nullptr;

        while (trav != nullptr)
        {
            travNext = trav->next;
            delete trav;
            trav = travNext;
        }

        size = 0;
        head = nullptr;
    }

    ~Lstack()
    {
        clear();
    }
};
int main()
{
    Lstack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);

    s.display();

    cout << s.pop() << " " << s.pop() << endl;

    s.display();

    cout << s.pop() << endl;
}