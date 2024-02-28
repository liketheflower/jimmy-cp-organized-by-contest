#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL MOD = 998244353;

LL gcd(LL a, LL b) {
   if (b == 0)return a;
   return gcd(b, a % b);
}

int main(){
    int n;
    cin >> n;
    vector<int>A(n, 0);
    for (int i = 0; i <n;++i){
	cin >> A[i];
    }
    reverse(A.begin(), A.end());
    LL a = 0, b = 1ll;
    // (x + a/b)/n
    // x/n +a/(b*n)
    // (bx + a) / (bn)
    for (auto x:A){
	//this_ret = (1/n)*(x + this_ret); 
        LL new_a = b*x + a;
	LL new_b = b*n;
	a = new_a;
	b = new_b;
	/*
	auto gcd_ = gcd(a, b);
	a /= gcd_;
	b /= gcd_;
	*/
    }
    LL ret = (a/b) % MOD;
    cout <<ret <<endl;

return 0;
  }
