#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
  string s;
  cin >> s;
  string ret = "";
  reverse(s.begin(), s.end());
  for (auto c: s) 
  {
      if (c == '6')  {ret += "9";continue;}
      if (c == '9')  {ret += "6";continue;}
      ret += c;
  }
  cout << ret << endl;
  return 0;
}
