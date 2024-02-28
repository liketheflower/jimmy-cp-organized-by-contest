#include<iostream>
#include<vector>
using namespace std;
int main(){
  int n, p, q;
  cin >> n >> p >> q;
  int min_ = 1e6;
  for(int i = 0; i < n; ++i){
      int this_num;
      cin >> this_num;
      min_ = min(min_, this_num);
  }
  int ret = min(p, q+min_);
  cout << ret<<endl;

return 0;
  }
