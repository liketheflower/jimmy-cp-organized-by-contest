#include<iostream>
#include<vector>
using namespace std;
int main(){
   int n, m;cin>>n>>m;
   vector<int> inde(n + 1, 0);
   for (int i =0; i <m;++i){
       int u, v; cin >> u >>v;
       inde[v]++;
   }
   int ret = 0;
   int cnt = 0;
   for (int i = 1; i <=n;++i){
       cnt += inde[i] == 0;
       if (inde[i] ==0){
	   ret = i;
       }
   }
   if (cnt > 1){
        ret = -1;
   }
   cout << ret << endl;
return 0;
  }
