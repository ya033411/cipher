#include <iostream>
#include <map>
#include <string>
int main() {
 std::map<char,char> map;
 char currCha = 'a';
 while (currCha <= 'z') {
  char val = currCha + 3;
  if (val > 'z') {
    val -= 26;
  }
  map[currCha] = val;
  currCha++;
 }
 std::string str = "helloworld";
 std::string str2 = "";
 int strLen = str.length();
 for (int i = 0; i < strLen; i++) {
   str2 += map[str[i]];
 }
 std::cout << str << "\n" << str2 << "\n"; 
 return -1;
}
