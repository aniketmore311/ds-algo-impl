#include <iostream>
using namespace std;
template <typename T>
class Dll
{
private:
    class Node
    {
    public:
        T data;
        Node *next;
        Node *prev;
        Node(int n)
        {
            this->data = n;
            next = nullptr;
            prev = nullptr;
        }
    };

    int size;
    Node *head;
    Node *tail;

public:
    Dll()
    {
        size = 0;
        head = nullptr;
        tail = nullptr;
    }

    bool isempty()
    {
        return (size == 0);
    }

    int getSize()
    {
        return size;
    }

    int search(T key)
    {
        int index = 0;
        Node *temp = head;
        while (temp->data != key && temp != nullptr)
        {
            temp = temp->next;
            index++;
        }
        if (temp == nullptr)
            return -1;
        else
            return index;
    }

    void insertFirst(T key)
    {
        Node *temp = new Node(key);
        if (isempty()) //empty list
        {
            head = temp;
            tail = temp;
            head->next = nullptr;
            head->prev = nullptr;
            size++;
        }
        else
        {
            temp->next = head;
            temp->prev = nullptr;
            head->prev = temp;
            head = temp;
            size++;
        }
    }

    void insertLast(T key)
    {
        Node *temp = new Node(key);
        if (isempty()) //empty list
        {
            head = temp;
            tail = temp;
            head->next = nullptr;
            head->prev = nullptr;
            size++;
        }
        else
        {
            temp->prev = tail;
            temp->next = nullptr;
            tail->next = temp;
            tail = temp;
            size++;
        }
    }

    void insertAt(int index, T key)
    {
        if (index >= 1 && index <= size - 1)
        {
            Node *temp = new Node(key);
            Node *before = head;
            Node *after = nullptr;
            for (int i = 0; i < index - 1; i++)
            {
                before = before->next;
            }
            after = before->next;
            temp->next = after;
            after->prev = temp;
            temp->prev = before;
            before->next = temp;
            size++;
        }
        else if (index == 0)
        {
            insertFirst(key);
        }
        else if (index == size)
        {
            insertLast(key);
        }
        else
        {
            throw(std::invalid_argument("index not valid"));
        }
    }

    void insertBefore(T key, T key2)
    {
        int index = search(key);
        if (index != -1)
        {
            insertAt(index, key2);
        }
        else
        {
            throw(std::invalid_argument("invalid argument"));
        }
    }

    void removeHead()
    {
        Node *temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
        size--;
    }

    void removeTail()
    {
        Node *temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
        size--;
    }

    void removeAt(int index)
    {
        if (index >= 1 && index < size - 1)
        {
            Node *before = head;
            Node *del;
            Node *after;
            for (int i = 0; i < index - 1; i++)
            {
                before = before->next;
            }
            del = before->next;
            after = del->next;

            before->next = after;
            after->prev = before;

            delete del;
            size--;
        }
        else if (index == 0)
        {
            removeHead();
        }
        else if (index == size - 1)
        {
            removeTail();
        }
        else
        {
            throw(std::invalid_argument("index not valid"));
        }
    }

    void remove(T key)
    {
        int i = search(key);
        removeAt(i);
    }

    void print()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        printf("\n");
    }

    void clear()
    {
        Node *del = head;
        Node *after = head;

        while (del != nullptr)
        {
            after = del->next;
            delete del;
            del = after;
        }

        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    ~Dll()
    {
        clear();
    }
};

int main()
{
    Dll<int> l;
    cout << l.isempty() << endl; //true

    l.insertFirst(3);
    l.insertFirst(2);
    l.insertFirst(1);

    l.print(); //1 2 3

    l.insertLast(3);
    l.insertLast(2);
    l.insertLast(1);

    l.print(); //1 2 3 3 2 1

    l.insertAt(6, 11);
    l.insertAt(3, 10);
    l.insertAt(0, 9);

    l.print(); //9 1 2 3 10 3 2 1 11

    cout << l.search(10) << endl; //4

    l.insertBefore(9, -9);
    l.insertBefore(10, -10);
    l.insertBefore(11, -11);

    l.print(); //-9 9 1 2 3 -10 10 3 2 1 -11 11

    l.removeAt(11);
    l.removeAt(6);
    l.removeAt(5);
    l.removeAt(0);

    l.print(); //9 1 2 3 3 2 1 -11

    l.remove(9);
    l.remove(-11);
    l.remove(3);

    l.print(); // 1 2 3 2 1

    l.clear();

    l.print(); //

    l.insertFirst(3);
    l.insertFirst(2);
    l.insertFirst(1);
    l.insertLast(3);
    l.insertLast(2);
    l.insertLast(1);

    l.print();                   //1 2 3 3 2 1
    cout << l.getSize() << endl; // 6
}