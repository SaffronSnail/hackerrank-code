#include <iostream>

void postOrder(node *root) {
  if (root->left != nullptr) {
    postOrder(root->left);
    std::cout << " ";
  }

  if (root->right != nullptr) {
    postOrder(root->right);
    std::cout << " ";
  }

  std::cout << root->data;
}
