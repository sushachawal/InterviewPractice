#include<queue>
#include<iostream>
#include <string>
#include "graph.h"

using namespace std;

Graph* CreateGraph0(void);
void BFS(Graph g, int startIndex);

int main(){
  Graph* myGraph = CreateGraph0();
  BFS(*myGraph, 1);
  BFS(*myGraph, 1);
}

Graph* CreateGraph0(void){
  Graph* myGraph = new Graph;
  myGraph->nodes = new Node*[6];
  myGraph->size = 6;
  for(int i = 0; i<myGraph->size; i++){
    myGraph->nodes[i] = new Node;
  }
  for(int i = 0; i<myGraph->size; i++){
    Node* curnode = myGraph->nodes[i];
    curnode->visited = false;
    curnode->name = to_string(i+1);
    switch (i) {
      case 0:
        curnode->child_size = 0;
        break;
      case 1:
        curnode->child_size = 2;
        curnode->children = new Node*[2];
        curnode->children[0] = myGraph->nodes[0];
        curnode->children[1] = myGraph->nodes[3];
        break;
      case 2:
        curnode->child_size = 1;
        curnode->children = new Node*[1];
        curnode->children[0] = myGraph->nodes[1];
        break;
      case 3:
        curnode->child_size = 1;
        curnode->children = new Node*[1];
        curnode->children[0] = myGraph->nodes[2];
        break;
      case 4:
        curnode->child_size = 1;
        curnode->children = new Node*[1];
        curnode->children[0] = myGraph->nodes[5];
        break;
      case 5:
        curnode->child_size = 0;
        break;
    }
  }
  return myGraph;
}

void BFS(Graph g, int startIndex){
  queue<Node*> q;
  q.push(g.nodes[startIndex]);
  while(!q.empty()){
    Node* curnode = q.front();
    q.pop();
    if(curnode->visited){
      continue;
    }
    cout << curnode->name << " ";
    curnode -> visited = true;
    if(curnode->child_size>0){
      for(int i = 0; i<curnode->child_size; i++)
        q.push(curnode->children[i]);
    }
  }
  cout << endl;
  for(int i = 0; i<g.size; i++)
    g.nodes[i]->visited = false;
}
