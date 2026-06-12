#include <iostream>
using namespace std;

//membuat class Node
class Node {

    //memberi akses modifier serta mendeklarasi variabel dan object node
    public :
    string info;
    Node* leftchild;
    Node* rightchild;

    //membuat constructor untuk class Node
    Node(string i, Node* 1, Node* r) {
        //memberi nilai parameter ke variabel
        info = i;
        leftchild = 1;
        rightchild = r;
    }

};

// membuat class BinaryTree
class BinaryTree {

    //memberi akses modifier dan deklarasi object
    public :
    Node* root;

    BinaryTree() {
        root = nullptr;
    }

    void insert(string element) {
        //memberi nilai untuk setiap object node yang dibuat
        Node* newNode = new Node(element, nullptr, nullptr);
        newNode->info = element;
        newNode->leftchild = nullptr;
        newNode->rightchild = nullptr;

        Node* parent = nullptr;
        Node* currentNode = nullptr;
        search(element, parent, currentNode);

        //membuat conditional statement
        Node* paraent = nullptr;
        Node* currentNode = nullptr;
        search(element, parent, currentNode);

        //membuat conditional statement
        if (parent == nullptr) {
            root = newNode;
            return;
        }

        if (element < parent->info)
        {
            parent->leftchild = newNode;
        }
        else if (element > parent->info) 
        {
            parent->rightchild = newNode;
        }

    }

    void search(string element, Node*& parent, Node*& currentNode) {
        currentNode = root;
        parent = nullptr;
        while ((currentNode != nullptr) && (currentNode->info != element))
        {

            parent = currentNode;
            if (element < currentNode->info) 
                currentNode = currentNode->leftchild;
                 else
                  currentNode = currentNode->rightchild;
        }
    }

    void inorder(Node* ptr) {

        if (root == nullptr) {
            cout << "Tree is empty" << endl;
            return;
        }
        if (ptr != nullptr) {
            inorder(ptr->leftchild);
            cout << ptr->info << " ";
            inorder(ptr->rightchild);
        }
    }

    void preorder(Node* ptr) {

        if (root == nullptr) {
            cout << "Tree is empty" << endl;
            return;
        }
        if (ptr != nullptr) {
            cout << ptr->info << " ";
            preorder(ptr->leftchild);
            preorder(ptr->rightchild);
        }
    }

    
}

