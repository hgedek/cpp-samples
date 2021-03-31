#include <iostream>
#include <vector>
#include <climits>


struct Node{
    int value;
    Node* left;;
    Node* right;
};

void min_BST(Node* root, int& min_dist) {
    if (!root or ( !root->left and !root->right )) return;

    if (root->left and root->right) {
        auto m = std::min(root->value-root->left->value,
                root->right->value - root->value);
        min_dist = std::min(m, min_dist);
        
        min_BST(root->left, min_dist);
        min_BST(root->right, min_dist);

    } else if (root->left){
        min_dist = std::min(min_dist, 
                root->value - root->left->value);
        min_BST(root->left, min_dist);

    } else if (root->right) {
        min_dist = std::min(min_dist,
                root->right->value - root->value);
        
        min_BST(root->right, min_dist);
    }
}
void collect(Node* root, std::vector<int>& values) {
    if (!root) return;

    collect(root->left, values);
    values.push_back(root->value);
    collect(root->right, values);
}

int minBST(Node* root){
    int min_dist = INT_MAX;
    std::vector<int> values;
    collect(root, values);

    for(auto i = 1; i < values.size(); ++i) {
        min_dist = std::min(min_dist, 
                values[i] - values[i-1]);
    }

    return min_dist;
}

int main() {
    Node root = {5};
    Node three = {3};
    root.left = &three;
    Node two = {2};
    root.left->left = &two;
    Node four = {4};
    root.left->left = &four;

    Node seven = {7};
    root.right = &seven;
    Node six = {6};
    root.right->left = &six;

    std::cout << std::abs(minBST(&root)) << std::endl;

    auto min_dist = INT_MAX;
    min_BST(&root, min_dist);

    std::cout << min_dist << std::endl;

    return 0;
}
