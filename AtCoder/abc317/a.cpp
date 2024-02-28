#include<iostream>
#include<vector>
using namespace std;
int main(){
   int n, x, k;cin>>n >> x >>k;
   int ret = -1;
   for (int i = 0; i < n; ++i){
       int this_one;
       cin >> this_one;
       if (x +this_one >= k && ret == -1) ret = i + 1;
   }
   cout << ret <<endl;
return 0;
  }
