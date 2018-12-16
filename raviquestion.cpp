#include<unordered_map>
#include<vector>
#include<iostream>

using namespace std;

unordered_map<char, vector<char> > keypad;

void initialiseMap(void);
void perm(string num, const int totlength, string& curstring);

int main(){
  initialiseMap();
  string init = "";
  string numbers = "23";
  perm(numbers, numbers.length(), init);
}

void perm(string num, const int totlength, string& curstring){
    if(num == "")
      return;
    for(char& c : keypad[num[0]]){
      curstring+= c;
      perm(num.substr(1), totlength, curstring);
      if(curstring.length()  == totlength){
          cout << curstring << endl;
      }
      curstring = curstring.substr(0, curstring.length()-1);
    }
}

void initialiseMap(void){
  keypad['0'] = {};
  keypad['1'] = {};
  keypad['2'] = {'a','b','c'};
  keypad['3'] = {'d','e','f'};
  keypad['4'] = {'g','h','i'};
  keypad['5'] = {'j', 'k', 'l'};
  keypad['6'] = {'m', 'n', 'o'};
  keypad['7'] = {'p','q', 'r', 's'};
  keypad['8'] = {'t', 'u', 'v'};
  keypad['9'] = {'w', 'x', 'y', 'z'};
}
