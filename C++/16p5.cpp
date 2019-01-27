#include<iostream>

using namespace std;

int factorialzeros(int x){
  int count = 0;
  for(int i = 5; i <= x; i *= 5)
    count+= x/i;
  return count;
}

long factorial(int n){
  int op = 1;
  for(int i = n; i>0; i--){
    op *= i;
  }
  return op;
}

int main(int argc, char* argv[]){
  cout << factorial(atoi(argv[1])) << endl;
  cout << factorialzeros(atoi(argv[1])) << endl;
}
