#include<iostream>

using namespace std;

void swap(int in[], int id1, int id2){
  int temp = in[id1];
  in[id1] = in[id2];
  in[id2] = temp;
}

int* newfilledarray(int l){
  int* array = new int[l];
  for(int i=0; i<l; i++)
    array[i] = i;
  return array;
}

void rotate(int in[], int l, int k){
  int cur = k%l;
  while(cur != 0){
    swap(in, 0, cur);
    cur = (cur+k)%l;
  }
}

int main(int argc, const char* argv[]){
  int size = atoi(argv[1]);
  int* ar = newfilledarray(size);
  for (int i=0; i<size; i++){
    ar[i] = i+1;
    cout << i+1 << " ";
  }
  cout << endl;
  rotate(ar, size, atoi(argv[2]));
  for (int i=0; i<size; i++){
    cout << ar[i] << " ";
  }
  cout << endl;
}
