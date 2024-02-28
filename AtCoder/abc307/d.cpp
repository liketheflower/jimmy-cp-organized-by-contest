#include<iostream>
using namespace std;
int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  string ret = "";
  int left = 0;
  for (auto c:s){
      if (c == '(')left++;
      if (c == ')')
      {
	  if (left == 0){ret.push_back(c); continue;}
	  else {
	      while (ret.back() != '('){ret.pop_back();}
	      ret.pop_back();
	      left --;
	      continue;
	  }

      } 
      ret.push_back(c);

  }
  cout << ret << endl;
  return 0;
}
