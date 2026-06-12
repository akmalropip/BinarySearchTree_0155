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
        Node* newNode = new Node(element, nullptr, nullptr);
        newNode->info = element;
        newNode->leftchild = nullptr;
        newNode->rightchild = nullptr;

        Node* parent = nullptr;
        Node* currentNode = nullptr;
        search(element, parent, currentNode);
    }
}

