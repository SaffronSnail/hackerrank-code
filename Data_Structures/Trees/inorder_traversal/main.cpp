#include <iostream>

void inOrder(node *root) {
  if (root->left != nullptr) {
    inOrder(root->left);
    std::cout << " ";
  }

  std::cout << root->data;

  if (root->right != nullptr) {
    std::cout << " ";
    inOrder(root->right);
  }
}
