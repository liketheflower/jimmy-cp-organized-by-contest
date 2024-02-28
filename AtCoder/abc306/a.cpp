#include<iostream>
using namespace std;
int main(){
  int n;
  string s;
  cin >> n;
  cin >> s;
  string ret = "";
  for (auto c:s){ret += c; ret+=c;}
  cout<< ret;
  return 0;
}
