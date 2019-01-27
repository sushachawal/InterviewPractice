#include<iostream>
#include<vector>

template<typename T>class pQ{
  typedef std::pair<int,T> pqNode;
  std::vector<pqNode> harr;
public:
  
  void swap(pqNode* l, pqNode* r){
    pqNode* temp = r;
    r = l;
    l = r;
  }

  int left(int i){return 2*i + 1;}

  int right(int i){return 2*i + 2;}

  int parent(int i){return (i-1)/2;}

  void heapify(int i){
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if(l < harr.size() && harr[l].first < harr[i].first) smallest = l;
    if(r < harr.size() && harr[r].first < harr[i].first) smallest = r;
    if(smallest != i){
      swap(&harr[i], &harr[smallest]);
      heapify(smallest);
    }
  }

  pqNode extractmin(){
    if(harr.size() == 0) return INT_MAX;
    if(harr.size() == 1){
      pQ<T>::pqNode root = harr[0];
      harr.pop_back();
      return root;
    }
    pQ<T>::pqNode root = harr[0];
    harr[0] = harr.back();
    harr.pop_back();
    heapify(0);
  }

  pqNode getmin(){ return harr[0]; }

  void insert(pqNode n){
      harr.push_back(n);
      int i = harr.size() - 1;
      while(i != 0 && harr[parent(i)] > harr[i]){
        swap(&harr[parent(i)], &harr[i]);
        i = parent(i);
      }
  }
};
