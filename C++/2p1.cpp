#include "LinkedListNode.h"
#include <unordered_set>

using namespace std;

void RemoveDups(LinkedListNode<int>* n){
  LinkedListNode<int>* prev = NULL;
  unordered_set<int> table;
  while(n != NULL){
    if(table.find(n->val) != table.end()){
      prev -> next = n -> next;
      delete(n);
    }
    else{
      table.insert(n->val);
      prev = n;
    }
    n = n->next;
  }
}

int main(int argc, char* argv[]) {
  LinkedListNode<int>* head = new LinkedListNode<int>(atoi(argv[1]));
  LinkedListNode<int>* n = head;
  for(int i = 2; i <= argc - 1; i++){
    n->next = new LinkedListNode<int>(atoi(argv[i]));
    n = n->next;
  }
  RemoveDups(head);
  n = head;
  while (n != NULL){
    cout << n->val << " ";
    n = n->next;
  }
  cout << endl;
}
