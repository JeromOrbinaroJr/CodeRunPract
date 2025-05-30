// Реализуйте бинарное дерево поиска для целых чисел.
// Программа должна последовательно обрабатывать вводимые числа. 
// Если очередное число есть в дереве, ничего делать не нужно. 
// Если числа в дереве нет, нужно добавить его в соответствующее место дерева.
// Балансировку дерева производить не нужно.
// Найдите высоту получившегося дерева.

#include <iostream>

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }
    if (root->value == value) {
        return root;
    }
    if (value < root->value) {
        root->left = insert(root->left, value);
    }
    else {
        root->right = insert(root->right, value);
    }
    return root;
}

int height(Node* root) {
    if (root == nullptr) return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return std::max(leftHeight, rightHeight) + 1;
}

void deleteTree(Node* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    Node* root = nullptr;
    int tempValue;
    
    while (std::cin >> tempValue && tempValue != 0) {
        root = insert(root, tempValue);
    }
    
    std::cout << height(root) << std::endl;
    
    deleteTree(root);
    
    return 0;
}