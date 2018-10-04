#include "LinkedListNode.h"

template <class Key, class value_type>
class SushHashMap{

public:
  typedef std::pair<const Key,value_type> stored;
  typedef LinkedListNode<stored>* array_type;
  array_type array[100] = {};
  void insert(Key key, value_type value){
    stored data = {key, value};
    array_type array_val = array[HashingFunction(key)];
    if(array_val == 0)
      array[HashingFunction(key)] = new LinkedListNode<stored>(data);
    else {
      if(array_val->val == data.second)return;
      while(array_val->next != NULL)
        
    }

  }
private:
  int HashingFunction(Key key){
    std::hash<Key> KeyHash;
    return KeyHash(key)%100;
  }

};
