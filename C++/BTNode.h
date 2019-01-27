#include <iostream>

class BTNode{
public:
  int data;
  BTNode* left;
  BTNode* right;
  BTNode(int d, BTNode* l, BTNode* r): data(d), left(l), right(r){};
};
