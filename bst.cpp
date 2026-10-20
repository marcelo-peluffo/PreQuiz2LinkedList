// rename to main.cpp
#include <iostream>

struct Node {
    int data;
    Node *left, *right;
    Node (int data) : data(data), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node *root;

    Node* insert(Node *node, int data) {
        if (node == nullptr) {
            return new Node(data);
        } else if (data < node -> data) {
            node -> left = insert(node -> left, data);
        } else {
            node -> right = insert(node -> right, data);
        }
        return node;
    }

    void preOrderTraversal(Node *node) {
        if (node == nullptr) {
            return;
        } else {
            std::cout << node -> data << " ";
            preOrderTraversal(node -> left);
            preOrderTraversal(node -> right);
        }
    }

    void inOrderTraversal(Node *node) {
        if (node == nullptr) {
            return;
        } else {
            inOrderTraversal(node -> left);
            std::cout << node -> data << " ";
            inOrderTraversal(node -> right);
        }
    }

    void postOrderTraversal(Node *node) {
        if (node == nullptr) {
            return;
        } else {
            postOrderTraversal(node -> left);
            postOrderTraversal(node -> right);
            std::cout << node -> data << " ";
        }
    }

    void destroyTree(Node *node) {
        if (node != nullptr) {
            destroyTree(node -> left);
            destroyTree(node -> right);
            delete node;
        }
    }

public:
    BST() : root(nullptr) {}
    
    ~BST() {
        destroyTree(root);
    }

    void insert(int data) {
        root = insert(root, data);
    }
    
    void preOrderTraversal() {
        preOrderTraversal(root);
        std::cout << std::endl;
    }
    
    void inOrderTraversal() {
        inOrderTraversal(root);
        std::cout << std::endl;
    }
    
    void postOrderTraversal() {
        postOrderTraversal(root);
        std::cout << std::endl;
    }
};

int main() {
    BST tree;
    
    tree.insert(30);
    tree.insert(45);
    tree.insert(15);
    
    tree.preOrderTraversal();
    tree.inOrderTraversal();
    tree.postOrderTraversal();
    
    return 0;
}
