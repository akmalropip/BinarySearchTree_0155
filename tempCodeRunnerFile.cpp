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
    Node(string i, Node* l, Node* r) {
        //memberi nilai parameter ke variabel
        info = i;
        leftchild = l;
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

        //membuat conditional statement
        Node* parent = nullptr;
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

    void postorder(Node* ptr) {

        if (root == nullptr) {
            cout << "Tree is empty" << endl;
            return;
        }
        if (ptr != nullptr) {
            postorder(ptr->leftchild);
            postorder(ptr->rightchild);
            cout << ptr->info << " ";
        }
    }
};

int main()
{
    //deklarasi object x sebagai binary tree
    BinaryTree x;

    //perulangan while selama bernilai benar
    while (true)
    {
        //membuat menu program dan input pilihan
        cout << "\nMenu" << endl;
        cout << "1. Implement insert operation" << endl;
        cout << "2. Perform inorder traversal" << endl;
        cout << "3. Perform preorder traversal" << endl;
        cout << "4. Perform postorder traversal" << endl;
        cout << "5. Exit" << endl;
        cout << "\nEnter your choice (1-5) : ";

        char ch;
        cin >> ch;
        cout << endl;

        //membuat conditional statement dari input ch
        switch (ch)
        {
            case '1':
            {
                cout << "Enter a word : ";
                string word;
                cin >> word;
                x.insert(word);
                break;
            }
            case '2':
            {
                x .inorder(x.root);
                break;
            }
            case '3':
            {
                x.preorder(x.root);
                break;
            }
            case '4':
            {
                x.postorder(x.root);
                break;
            }
            case '5':
            {
                return 0;
            }
            default: {
                cout << "Invalid option" << endl;
                break;
            }
        }
    }
} 

