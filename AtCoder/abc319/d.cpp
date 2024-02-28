#include<iostream>
#include<vector>
#include<set>
#include<cstring>
using namespace std;
typedef long long LL;
bool good(vector<int>a, LL mid, LL m, LL tot){
    if (tot / mid > m)return false;
    int line = 0;
    LL curr = 0;
    for (auto c: a){
	if (curr == 0){
	    curr += c;
	}else {
	 if (curr + 1 + c > mid){
		line ++;
		if (line > m)return false;
		curr = c;
	    } else {
		curr += 1 + c;
	    }
    }
}
    if (curr >0)line++;
    return line <= m;
    }
    int main(){
   int n, m;cin>>n >> m;
   vector<int>a(n, 0);
   LL lo = 1, hi = 0, tot=0;
   for (int i = 0; i <n; ++i){
       cin >> a[i];
       lo = max(lo, (LL)a[i]);
       hi += (LL)a[i];
   }
   tot = hi;
   if (m==1){cout << tot + n - 1<<endl;return 0;}
   while (lo < hi){
       LL mid = (lo + hi ) / 2;
       auto ret = good(a, mid, m, tot);
       cout << mid << " "<<ret <<endl;
       if (ret){
	   hi = mid;
       } else {
	   lo = mid + 1;
       }
   }
   cout << lo <<endl;

return 0;
  }
