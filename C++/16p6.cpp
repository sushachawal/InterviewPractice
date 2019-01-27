#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int smallestdifference(vector<int> vecl, vector<int> vecr){
  if(vecl.size() == 0 || vecr.size() == 0) return -1;
  sort(vecl.begin(), vecl.end());
  sort(vecr.begin(), vecr.end());
  int pl = 0, pr = 0;
  int min = abs(vecl[pl] - vecr[pr]);
  if(min == 0) return 0;
  while(pl < vecl.size() && pr<vecr.size()){
    if(vecl[pl] < vecr[pr])
      pl++;
    else
      pr++;
    int curdiff = abs(vecl[pl] - vecr[pr]);
    if(curdiff >= min) break;
    else min = curdiff;
  }
  return min;
}

int main(){
  vector<int> vec1 = {1, 5, 89, 23, 42};
  vector<int> vec2 = {23, 234, 5};
  cout << smallestdifference(vec1, vec2) << endl;
  cout << "Should be the same as " << endl;
  cout << smallestdifference(vec1, vec2) << endl;
}
