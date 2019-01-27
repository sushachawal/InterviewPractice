#include <iostream>

template <class T>
class LinkedListNode{
public:
  LinkedListNode* next;
  T val;
public:
  LinkedListNode(T cur) : next(NULL), val(cur){}
};

template <class T>
class Node{
public:
  Node* next;
  T val;
  Node(T cur) : next(NULL), val(cur){}
  Node(): next(NULL){};
};
