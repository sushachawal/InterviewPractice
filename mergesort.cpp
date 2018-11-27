#include<iostream>
using namespace std;

int * merge(int l[], int r[], int sl, int sr){
    cout << "Sizes of l and r are: " << sl << " " << sr << endl;
    cout << "Left array is ";
    for(int i = 0; i < sl; i++){
      cout << l[i] << " ";
    }
    cout << endl << "Right array is ";
    for(int i =0; i < sr; i++){
      cout << r[i] << " ";
    }
    cout << endl;
    int countl = 0;
    int countr = 0;
    int* out = new int[sl+sr];
    for (int i = 0; i < sl+sr; i++) {
      if(countl >= sl)
        out[i] = r[countr++];
      else if (countr >= sr)
        out[i] = l[countl++];
      else
        out[i] = l[countl] < r[countr] ? l[countl++] : r[countr++];
    }
    return out;
}

int* mergesort(int ar[], int s, int e){
  cout << "Start index is " << s << endl;
  cout << "End index is " << e << endl;
  if(s==e){
    int* temp = new int[1];
    temp[0] = ar[s];
    return temp;
  }
  int mid = (s+e)/2;
  return merge(mergesort(ar, s, mid), mergesort(ar, mid+1, e), mid-s+1, e-mid);
}

int main(int argc, const char* argv[]){
  int size = 8;
  int myarray[] = {3, 2, 1, 4, 5, 6, 8, 7};
  int * sorted = mergesort(myarray, 0, size-1);
  for (size_t i = 0; i < size; i++) {
    cout << myarray[i] << " ";
  }
  cout << endl;
  for (size_t i = 0; i < size; i++) {
    cout << sorted[i] << " ";
  }
  cout << endl;
}
