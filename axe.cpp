#include <iostream>
#include <vector>

using namespace std;

// Define the Node structure
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Root -> Left -> Right
void preorder(Node* node) {
    if (node == nullptr) return;

    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

// Left -> Root -> Right
void inorder(Node* node) {
    if (node == nullptr) return;

    inorder(node->left); // Fixed: was calling preorder
    cout << node->data << " ";
    inorder(node->right); // Fixed: was calling preorder
}

// Left -> Right -> Root
void postorder(Node* node) {
    if (node == nullptr) return;

    postorder(node->left); // Fixed: was calling preorder
    postorder(node->right); // Fixed: was calling preorder
    cout << node->data << " ";
}

int main() {
    // Speed up I/O
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    /* Tree Structure:
             1
            / \
           2   3
            \
             5
    */
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);

    cout << "Preorder Traversal:  ";
    preorder(root);
    cout << "\nInorder Traversal:   ";
    inorder(root);
    cout << "\nPostorder Traversal: ";
    postorder(root);
    cout << endl;

    return 0;
}