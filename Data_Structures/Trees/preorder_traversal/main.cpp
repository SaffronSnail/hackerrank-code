#include <iostream>

void preOrder(node *root) {
  std::cout << root->data;

  if (root->left != nullptr) {
    std::cout << " ";
    preOrder(root->left);
  }

  if (root->right != nullptr) {
    std::cout << " ";
    preOrder(root->right);
  }
}
