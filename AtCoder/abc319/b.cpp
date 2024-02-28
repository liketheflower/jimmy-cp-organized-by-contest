#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int good(int i, int n){
    int ret = -1;
    for (int k = 1; k <= 9; ++k){
	if (n % k == 0 && i % ( n / k) == 0)return k;
    }
    return ret;

}
int main(){
   int n;cin>>n;
   string ret = "";
   for (int i = 0; i < n + 1; ++i){
       auto this_ret = good(i, n);
       if (this_ret > 0){
	   ret.push_back('0' + this_ret);
       }else{
	   ret.push_back('-');
       }
   }
   cout << ret << endl;
return 0;
  }
