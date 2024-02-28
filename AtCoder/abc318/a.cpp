#include<iostream>
#include<vector>
using namespace std;
int main(){
   int n, m, p;cin>>n >> m >>p;
   int ret = 0;
   for (int i = 1; i <= n; ++i){
       if (i >= m && ((i - m) % p ==0))ret++;
   }
   cout << ret <<endl;
return 0;
  }
