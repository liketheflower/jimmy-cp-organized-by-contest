#include<iostream>
using namespace std;
typedef long long LL;
int solve(){
    LL x; cin >> x;
    int n; cin >> n;
    int ret = 0;
    if (n == 1){
	ret = x;
	return ret;
    } else if (n == x){
	return 1;
    }
    int max_v = x / n;
    for (int i = max_v; i>= 1; --i){
       if (x % i ==0 && (x / i >=n))return i;
    }
    return 1;
}
int main(){
int T; cin >> T;
while (T--){
    auto ret = solve();
    cout << ret << endl;
}
    return 0;
}
