#include<random>
#include <iostream>
#include <map>
#include <string>
int main() {
 std::random_device rd;
 std::mt19937 eng(rd());
 std::uniform_int_distribution<std::mt19937::result_type> dst(1,25);
 int change = dst(eng);
 std::cout << change << "\n";
 std::map<char,char> map;
 char currCha = 'a';
 while (currCha <= 'z') {
  int charAsNum = currCha - change;
  if (charAsNum < 97) {
    charAsNum += 26;
  }
  char val = charAsNum;
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
