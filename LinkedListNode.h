#include <iostream>

template <class T>
class LinkedListNode{
public:
  LinkedListNode* next;
  T val;
  LinkedListNode(T cur) : next(NULL), val(cur){}
};
