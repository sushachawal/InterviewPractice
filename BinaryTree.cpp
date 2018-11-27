#include "BinaryTree.h"

BTNode* sorted_array_to_BST(int array[], int start, int end){
  if(start > end) return NULL;
  int mid = (end+start)/2;
  return new BTNode(array[mid], sorted_array_to_BST(array, start, mid-1), sorted_array_to_BST(array, mid+1, end));
}

BTNode* sorted_array_to_BST(int a[], int size){
  return sorted_array_to_BST(a, 0, size -1);
}

void postOrderTraversal(BTNode* node){
  if(node != NULL){
    postOrderTraversal(node->left);
    postOrderTraversal(node->right);
    std::cout << node->data << " " << std::endl;
  }
}

void inOrderTraversal(BTNode* node){
  if(node != NULL){
    inOrderTraversal(node->left);
    std::cout << node->data << " " << std::endl;
    inOrderTraversal(node->right);
  }
}
