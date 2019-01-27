#include<iostream>

using namespace std;

int numbcombs(int n, int denom[], int l, int cur, int s_vals[]);
int numbcombs(int n);

int main(int argc, const char* argv[]){
  cout << numbcombs(atoi(argv[1])) << endl;
}

int numbcombs(int n, int denom[], int l, int cur, int s_vals[]){
  if(s_vals[n*l + cur] > 0) return s_vals[n*l + cur];
  if(cur >= l-1) return 1;
  int ways = 0;
  int valdenom = denom[cur];
  for(int i = 0; i*valdenom <= n; i++){
    ways += numbcombs(n-i*valdenom, denom, l, cur+1, s_vals);
  }
  s_vals[n*l + cur] = ways;
  return ways;
}

int numbcombs(int n){
  int denom[] = {25, 10, 5, 1};
  int* stored_vals = new int[(n+1) * 4];
  int offset = 4;
  for(int i = 0; i < n+1; i++){
    for(int j = 0; j < 4; j++) {
      stored_vals[i*offset + j] = 0;
    }
  }
  return numbcombs(n, denom, 4, 0, stored_vals);
}
