#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
int main(){
  int n;cin >> n ;
  unordered_set<string> ss;
  for (int i = 0; i < n; ++i){
      string s;
      cin  >> s;
      auto s2 = s;
      reverse(s2.begin(), s2.end());
      if (s <= s2){
	  ss.insert(s);
      } else{
	  ss.insert(s2);
      }
  }
  cout << ss.size()<<endl;

return 0;
  }
