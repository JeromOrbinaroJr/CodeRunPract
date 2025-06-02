// Для бинарного дерева поиска, построенного на заданных числах, выведите список всех листьев (вершин, не имеющих потомков) в порядке возрастания.
// Вводится последовательность целых чисел, оканчивающаяся нулем. Сам ноль в последовательность не входит.

#include <iostream>
#include <vector>
#include <algorithm>

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

void collectLeaves(Node* root, std::vector<int>& leaves) {
    if (root == nullptr) return;
    
    if (root->left == nullptr && root->right == nullptr) {
        leaves.push_back(root->value);
        return;
    }
    
    collectLeaves(root->left, leaves);
    collectLeaves(root->right, leaves);
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
    
    std::vector<int> leaves;
    collectLeaves(root, leaves);
    
    std::sort(leaves.begin(), leaves.end());
    
    for (int leaf : leaves) {
        std::cout << leaf << std::endl;
    }
    
    deleteTree(root);
    
    return 0;
}