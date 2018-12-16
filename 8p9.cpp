#include<iostream>
#include<string>
#include<vector>

using namespace std;

void printparens(int n);
void printparensrecursive(int n, int l, int r, string& final);

int main(int argc, char* argv[]){
  printparens(atoi(argv[1]));
}

void printparens(int n){
  string empty = "";
  printparensrecursive(n, 0, 0, empty);
}

void printparensrecursive(int n, int l, int r, string& final){
  vector<char> posparens;
  if(l == r){
    posparens.push_back('(');
  }
  if(l > r && l<n){
    posparens.push_back('(');
    posparens.push_back(')');
  }
  if(l > r && l == n){
    posparens.push_back(')');
  }
  for(int i = 0; i < posparens.size(); i++){
    final+=posparens[i];
    if(final.length() == 2*n){
      cout << final << endl;
    }
    else{
      if(posparens[i] == '(')
        printparensrecursive(n, l+1, r, final);
      else
        printparensrecursive(n, l, r+1, final);
    }
    final = final.substr(0,final.length() - 1);
  }
}
