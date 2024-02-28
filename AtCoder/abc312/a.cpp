#include<iostream>
#include<vector>
using namespace std;
int main(){
  string s;cin >>s;
  vector<string> ss={"ACE", "BDF", "CEG", "DFA", "EGB", "FAC", "GBD"};
  bool found = false;
  for (auto x: ss){
      if (s==x)found=true;
  }
  if (found)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
return 0;
  }
