#include "myStack.h"
#include<assert.h>

using namespace std;

int main(){
  myStack<int> stack;
  for(int i=0; i<10; i++){
    stack.push(i);
    stack.pop();
  }
  stack.push(-7);
  int myInt = stack.pop();
  for(int i=0; i<10; i++)
    stack.push(i);
  cout << myInt << endl;
  cout << stack.min()->data << endl;
}
