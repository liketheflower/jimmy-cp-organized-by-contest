#include<iostream>
#include<vector>
#include<cstring>
#include <algorithm>
int memo[110][110];
using namespace std;
int main(){
   int n;cin>>n;
   memset(memo, 0, sizeof memo);
   for (int i = 0; i <n; ++i){
       int a, b ,c, d;
       cin >> a >>b>>c>>d;
       for (int x = a; x<b;++x){
	   for (int y = c; y<d; ++y){
	       memo[x][y] = 1;
	   }
       }
   }
   int ret = 0;
       for (int x = 0; x<=101;++x){
	   for (int y = 0; y<=101; ++y){
	       ret+=memo[x][y];
	   }
       } 
   
   
   cout << ret << endl;

return 0;
  }
