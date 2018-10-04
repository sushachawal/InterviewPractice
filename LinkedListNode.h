#include <iostream>

template <class T>
class LinkedListNode{
  LinkedListNode* next;
  T val;
  LinkedListNode(T cur) : next(NULL), val(cur){}
};
