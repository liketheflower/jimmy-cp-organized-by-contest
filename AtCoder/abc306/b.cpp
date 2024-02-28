#include<iostream>
#include<vector>
using namespace std;
int main(){
  int n = 64;
  unsigned long long ret = 0;
  
  for (int i = 0; i < 64; ++i)
  {
      int num;
      cin >> num;
      unsigned long long this_ret = (unsigned long long)num * ((unsigned long long)1 << i);
      ret += this_ret;
  }
  cout <<ret;
  return 0;
}
