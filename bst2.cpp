// practiced BST again, rename to main.cpp
#include <iostream>
#include <queue>

struct Node {
    int value;
    Node* left;
    Node* right;
    Node() : value(0), left(nullptr), right(nullptr) {}
    Node(int value) : value(value), left(nullptr), right(nullptr) {}
};

class BST {
public:
    BST() {
        root = nullptr;
    }
    
    ~BST() {
        destroyTree(root);
    }
    
    Node* getRoot() {
        return root;
    }
    
    bool empty() {
        return isEmpty();
    }
    
    void breadthFirstTraversal(Node* node) {
        lvlbfs(node);
    }
    
    void preOrderTraversal(Node* node) {
        predfs(node);
    }
    
    void inOrderTraversal(Node* node) {
        inodfs(node);
    }
    
    void postOrderTraversal(Node* node) {
        posdfs(node);
    }
    
    void insert(int data) {
        root = insert(root, data);
    }
    
    bool search(int target) {
         return search(root, target);
    }
    
    int minimum() {
        return findMin();
    }
    
    int maximum() {
        return findMax();
    }
    
private:
    Node* root;
    
    void destroyTree(Node* node) {
        if (node != nullptr) {
            destroyTree(node -> left);
            destroyTree(node -> right);
            delete node;
        }
    }
    
    bool isEmpty() {
        return root == nullptr;
    }
    
    void lvlbfs(Node* node) {
        if (node == nullptr) {
            return;
        } else {
            std::queue<Node*> queue;
            queue.push(node);
            while (!queue.empty()) {
                Node* current = queue.front(); queue.pop();
                std::cout << current -> value << std::endl;
                if (current -> left != nullptr) {
                    queue.push(current -> left);
                }
                if (current -> right != nullptr) {
                    queue.push(current -> right);
                }
            }
        }
    }
    
    void predfs(Node* node) {
        if (node == nullptr) {
            return;
        } else {
            std::cout << node -> value << std::endl;
            predfs(node -> left);
            predfs(node -> right);
        }
    }
    
    void inodfs(Node* node) {
        if (node == nullptr) {
            return;
        } else {
            inodfs(node -> left);
            std::cout << node -> value << std::endl;
            inodfs(node -> right);
        }
    }
    
    void posdfs(Node* node) {
        if (node == nullptr) {
            return;
        } else {
            posdfs(node -> left);
            posdfs(node -> right);
            std::cout << node -> value << std::endl;
        }
    }
    
    Node* insert(Node* node, int data) {
        if (node == nullptr) {
            return new Node(data);
        } else {
            if (data < node -> value) {
                node -> left = insert(node -> left, data);
            } else if (data > node -> value) {
                node -> right = insert(node -> right, data);
            } else {
                return node;
            }
        }
        return node;
    }
    
    bool search(Node* node, int target) {
        if (node == nullptr) {
            return false;
        } else if (node -> value == target) {
            return true;
        } else if (target < node -> value) {
            return search(node -> left, target);
        } else if (target > node -> value) {
            return search(node -> right, target);
        } else {
            return false;
        }
    }
    
    int findMin() {
        Node* node = root;
        if (node == nullptr) {
            return -1;
        } else {
            int minimum = node -> value;
            while (node -> left != nullptr) {
                if (minimum > node -> left -> value) {
                    minimum = node -> left -> value;
                }
                node = node -> left;
            }
            return minimum;
        }
    }
    
    int findMax() {
        Node* node = root;
        if (node == nullptr) {
            return -1;
        } else {
            int maximum = node -> value;
            while (node -> right != nullptr) {
                if (maximum < node -> right -> value) {
                    maximum = node -> right -> value;
                }
                node = node -> right;
            }
            return maximum;
        }
    }
};

int main() {
    BST tree;
    
    int n;
    std::cin >> n;
    while (n-- > 0) {
        int number;
        std::cin >> number;
        tree.insert(number);
    }
    
    int q;
    std::cin >> q;
    while (q-- > 0) {
        int query;
        std::cin >> query;
        if (tree.search(query)) {
            std::cout << query << ": Found" << std::endl;
        } else {
            std::cout << query << ": Not Found" << std::endl;
        }
    }

    
    Node* root = tree.getRoot();
    
    std::cout << "BFS (LEVEL): ";
    tree.breadthFirstTraversal(root);
    
    std::cout << "DFS (PREORDER): ";
    tree.preOrderTraversal(root);
    
    std::cout << "DFS (INORDER): ";
    tree.inOrderTraversal(root);
    
    std::cout << "DFS (POSTORDER): ";
    tree.postOrderTraversal(root);
    
    if (tree.empty()) {
        std::cout << "Tree is empty" << std::endl;
    } else {
        std::cout << "Minimum: " << tree.minimum() << std::endl;
        std::cout << "Maximum: " << tree.maximum() << std::endl;
    }
    
    return 0;
}
