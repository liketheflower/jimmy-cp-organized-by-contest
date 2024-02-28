#include<iostream>
#include<vector>
#include<set>
#include<cstring>
#include<unordered_set>
#include <algorithm>
int memo[11][11];
using namespace std;
int get_res(vector<int>&p, int n){
    int ret = 0;
    int this_ret = 0;
    for (int i = 1; i < n; ++i){
	int u = p[i], v = p[i-1];
	if (memo[u][v] == -1){
	    this_ret = 0;
	}
	this_ret += memo[u][v];
	ret =max(ret, this_ret);
    }
    return ret;
}
int main(){
   int n, m;cin>>n>>m;
   memset(memo, -1, sizeof memo);
   for (int i = 0; i <m; ++i){
       int a, b ,c;
       cin >> a >>b>>c;
       memo[a][b] = c;
       memo[b][a] = c;
   }
   int ret = 0;
   vector<int> p(n);
   for (int i = 0; i < n; ++i){
       p[i] = i + 1;
   }

   do{
        //Display the current permutation
        auto this_ret = get_res(p, n);
	ret = max(this_ret, ret);
    }while(next_permutation(p.begin(), p.end())); //Generate next permutation till it is not lexicographically largest

   cout << ret << endl;

return 0;
  }
