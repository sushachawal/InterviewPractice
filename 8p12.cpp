#include<iostream>
#include<vector>
#include<array>
#include<string>

using namespace std;

// We shall represent the position by an array of integers
// column[r] = c means there is a queen at position (r,c)
// Recursively look through all of the row positions and column positions
// Append to the vector whenever all eight queens have been placed

void QueenPerms(array<int, 8> curpos, int r, vector<array<int, 8> > &results);
bool checkvalid(array<int, 8> curpos, int r, int c);
string chessboardtostring(array<int, 8> ip);

int main(){
  vector<array<int, 8> > results;
  array<int, 8> curpos = {{100, 100, 100, 100, 100, 100, 100, 100}};
  QueenPerms(curpos, 0, results);
  for(auto &array : results)
    cout << chessboardtostring(array) << endl << endl;
}

void QueenPerms(array<int, 8> curpos, int r, vector<array<int, 8> > &results){
  if(r == 8){
    results.push_back(curpos);
    return;
  }
  for(int i = 0; i < 8; i++){
    if(checkvalid(curpos, r, i)){
      curpos[r] = i;
      QueenPerms(curpos, r+1, results);
    }
    curpos[r] = 100;
  }
}

bool checkvalid(array<int, 8> curpos, int r, int c){
  for(int i = 0; i < 8; i++){
    int diff = abs(r - i);
    if(curpos[i] == c || curpos[i] == c + diff || curpos[i] == c - diff)
      return false;
  }
  return true;
}

string chessboardtostring(array<int, 8> ip){
  string op = "";
  for(int i = 0; i<8; i++){
    for(int j = 0; j < ip[i]; j++)
      op += 'X';
    op += 'Q';
    for(int j = ip[i]+1; j<8; j++)
      op += 'X';
    op.append("\n");
  }
  return op;
}
