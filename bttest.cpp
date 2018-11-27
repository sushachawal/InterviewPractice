#include "BinaryTree.h"

int main(int argc, char** argv[]){
  int array[] = {1};
  int size = sizeof(array)/sizeof(*array);
  BTNode* q = sorted_array_to_BST(array, size);
  inOrderTraversal(q);
}
