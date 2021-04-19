#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int n) : data(n), next(nullptr)
    {
    }

    string toString()
    {
        string s;
        s.append(to_string(this->data));
        s.append(" -> ");
        return s;
    }
};

class LinkedList
{
public:
    Node *head;

    LinkedList() : head(nullptr)
    {
    }

    LinkedList(initializer_list<int> lst) : head(nullptr)
    {

        for (int n : lst)
        {
            // cerr << n << endl;
            this->insertAtTail(n);
        }
    }

    void insertAtTail(int n)
    {
        auto temp = this->head;
        // cerr << (temp == nullptr) << endl;
        auto newNode = new Node(n);
        if (temp == nullptr)
        {
            this->head = newNode;
            return;
        }
        while (temp->next)
        {
            temp = temp->next;
        }
        // temp = last node
        temp->next = newNode;
    }

    void reverseIt()
    {
        Node *curr, *prev, *next;
        curr = this->head;
        prev = nullptr;
        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        this->head = prev;
    }

    Node *reverseRec(Node *&head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        auto newHead = reverseRec(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }

    void reverseRecCon()
    {
        auto newHead = this->reverseRec(this->head);
        this->head = newHead;
    }

    string toString()
    {
        string s;
        auto temp = this->head;
        while (temp)
        {
            s.append(temp->toString());
            temp = temp->next;
        }
        s.append("NULL");
        return s;
    }
};

void solve()
{
    LinkedList lst{1, 2, 3, 4};
    cout << lst.toString() << endl;
    lst.reverseIt();
    cout << lst.toString() << endl;
    lst.reverseRecCon();
    cout << lst.toString() << endl;
}

int main()
{
    solve();
}
