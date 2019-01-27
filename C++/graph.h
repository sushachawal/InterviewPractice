class Node{
  public:
     std::string name;
     bool visited;
     Node** children;
     int child_size;
};

class Graph{
  public:
    Node** nodes;
    int size;
};
