#include <iostream>
#include <unordered_set>

bool findUniqueChars(std::string s){
  std::unordered_set<char> chs;
  for(char& c : s){
    auto it = chs.find(c);
    if(it != chs.end()) return false;
    chs.insert(c);
  }
  return true;
}

int main(int argc, char* argv[]){
  std::string truefalse = findUniqueChars(argv[1]) ? "Yes!":"No!";
  std::cout << "Are the characters in the string unique?" << std::endl;
  std::cout << truefalse << std::endl;
}
