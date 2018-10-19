#include<iostream>
#include<assert.h>

template <class t> class myStack{
private:
  template<class u> class StackNode{
  public:
    u data;
    StackNode<u> * next;
    StackNode<u> * min;
  public:
    StackNode(u d) : data(d) {}
  };
  void EmptyStackCheck(){
    if(top == NULL){
      std::cout << "Warning Stack is empty!" << std::endl;
      assert(top);
    }
  }
  StackNode<t>* top;
public:
  t pop(){
    EmptyStackCheck();
    t item = top->data;
    StackNode<t>* temp = top;
    top = top->next;
    delete(temp);
    return item;
  }

  void push(t val){
    StackNode<t>* newN = new StackNode<t>(val);
    if(top == NULL || newN->data <= top->min->data)
      newN->min = newN;
    else
      newN->min = top->min;
    newN->next = top;
    top = newN;
  }

  t peek(){
    EmptyStackCheck();
    return top-> data;
  }

  bool isEmpty() {
    return (top == NULL);
  }

  StackNode<t>* min(){
    EmptyStackCheck();
    return top->min;
  }
};
