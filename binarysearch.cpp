#include <iostream>

using namespace std;

int binarysearch(int ar[], int q, int l){
  int s = 0;
  int e = l-1;
  if(q > ar[e] || q < ar[s]) return -1;
  if(q == ar[e]) return e;
  while (s!=e){
    int mid = (s+e)/2;
    if(q == ar[mid]) return mid;
    if(q > ar[mid]) s = mid+1;
    else e = mid;
  }
  return -1;
}

int main(int argc, const char* argv[]){
  int size = 6;
  int arr[] = {1, 5, 7, 9, 12, 14};
  int pos = binarysearch(arr, atoi(argv[1]), size);
  if(pos == -1) {
    cout << "Item Not found" << endl;
    return 0;
  }
  cout << "Item found at position: " << pos << endl;
}
