#include<iostream>
using namespace std;
int main(){
  int n;
  cin >> n;
  int cnt = 0;
  for (int i = 1; i <= n*7; ++i){
      int this_num;
      cin  >> this_num;
      cnt += this_num;
      if (i > 1 && (i % 7 == 0)){
	  cout << cnt <<" ";
	  cnt = 0;
      }
  }
      cout << endl;
  return 0;
}
