#include "BinaryTree.h"

int main(int argc, const char* argv[]){
  int array[argc-1];
  for(int i = 1; i < argc ; i++){
    array[i-1] = atoi(argv[i]);
  }
  int size = sizeof(array)/sizeof(*array);
  BTNode* q = sorted_array_to_BST(array, size);
  inOrderTraversal(q);
}
