#include<iostream>

using namespace std;

void swap(int in[], int id1, int id2){
  int temp = in[id1];
  in[id1] = in[id2];
  in[id2] = temp;
}

<<<<<<< HEAD
int* newfilledarray(int l){
  int* array = new int[l];
  for(int i=0; i<l; i++)
    array[i] = i;
  return array;
}

=======
>>>>>>> 860feace2a77e4aee57af9214a6a72faa138da5f
void rotate(int in[], int l, int k){
  int cur = k%l;
  while(cur != 0){
    swap(in, 0, cur);
    cur = (cur+k)%l;
  }
<<<<<<< HEAD
=======
  return;
>>>>>>> 860feace2a77e4aee57af9214a6a72faa138da5f
}

int main(int argc, const char* argv[]){
  int size = atoi(argv[1]);
<<<<<<< HEAD
  int* ar = newfilledarray(size);
=======
  int ar[size];
>>>>>>> 860feace2a77e4aee57af9214a6a72faa138da5f
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
