//binary search tree
//author: aniket more
//date: 02/05/2020
#include <iostream>
using namespace std;
template <typename T>
class BST
{
private:
    class Node
    {
    public:
        T key;
        Node *left;
        Node *right;
        Node(T key)
        {
            this->key = key;
            this->left = nullptr;
            this->right = nullptr;
        }
    };

    int size;
    Node *root;

public:
    BST()
    {
        this->root = nullptr;
        this->size = 0;
    }

    bool isempty()
    {
        return (size == 0);
    }

    int getsize()
    {
        return size;
    }

    Node *inorderPrint(Node *node)
    {
        if (node != nullptr)
        {
            inorderPrint(node->left);
            std::cout << node->key << " ";
            inorderPrint(node->right);
        }
    }
    void inorderPrint()
    {
        inorderPrint(root);
    }

    Node *minimum(Node *node)
    {
        while (node->left != nullptr)
        {
            node = node->left;
        }
        return node;
    }
    T minimum()
    {
        Node *temp = minimum(root);
        return (temp->key);
    }

    Node *maximum(Node *node)
    {
        while (node->right != nullptr)
        {
            node = node->right;
        }
        return node;
    }
    T maximum()
    {
        Node *temp = maximum(root);
        return (temp->key);
    }

    Node *search(T key)
    {
        Node *temp = root;
        while (temp != nullptr)
        {
            if (key == temp->key)
            {
                return temp;
            }
            else if (key < temp->key)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }
        return nullptr;
    }

    Node *insert(Node *node, T key) //recurcise method returns links backwards
    {
        if (node == nullptr)
        {
            node = new Node(key); //attaching the new node onto the first null link
            size++;
        }
        else if (key <= node->key) //propogation
        {
            node->left = insert(node->left, key);
        }
        else if (key > node->key) //propogation
        {
            node->right = insert(node->right, key);
        }
        return node; //returning the backlinks
    }
    void insert(T key)
    {
        if (search(key) == nullptr)
        {
            root = insert(root, key);
        }
    }

    Node *remove(Node *node, T key) //recursive function that returns links in the upward direction
    //to upadate links if any changes have happened
    {
        if (node == nullptr) //key not present
            return node;
        if (key < node->key) //propogation call
        {
            node->left = remove(node->left, key);
        }
        else if (key > node->key)
        {
            node->right = remove(node->right, key);
        }
        else //this is the node to be removed
        {
            if (node->left == nullptr) //only right child
            {
                Node *temp = node->right;
                delete node;
                size--;
                return temp;
            }
            else if (node->right == nullptr) //only left child
            {
                Node *temp = node->left;
                delete node;
                size--;
                return temp;
            }
            else //both children are present
            {
                Node *temp = minimum(node->right);            //finding succesor to be placed at node
                node->key = temp->key;                        //putting succesor at node by copying the value
                node->right = remove(node->right, temp->key); //deleting succesor copy
            }
        }
        return node; //to be returned by function calls which do not make changes in any Node* (propogation calls)
    }

    void remove(T key)
    {
        root = remove(root, key);
    }

    void clear(Node *current_node)
    {
        if (current_node == nullptr)
            return;
        clear(current_node->left);
        clear(current_node->right);

        // cout << " deleting: " << current_node->key << endl;
        delete current_node;
    }

    void clear()
    {
        clear(root);
        root = nullptr;
        size = 0;
    }

    ~BST()
    {
        clear();
    }
};
int main()
{
    freopen("output.txt", "w", stdout);
    BST<int> b;
    b.insert(10);
    b.insert(30);
    b.insert(20);
    b.insert(40);

    b.remove(10);

    b.inorderPrint(); // 20 30 40

    cout << endl;

    b.clear();

    b.insert(30);
    b.insert(20);
    b.insert(40);

    b.remove(20);

    b.inorderPrint(); // 30 40

    cout << endl;
}
