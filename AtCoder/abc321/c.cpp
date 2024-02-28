#include<iostream>
#include <algorithm>  
#include<vector>
#include<cstring>
using namespace std;
const int INF = 0x3f3f3f3f;
typedef int LL;
const int HIGH = 1, ON = 0, LOW = 2;
LL dfs(string& m, int i, int c, vector<vector<LL>>& dp){
    cout << i <<" -- "<< c <<endl;
    if (i >= m.size())return 0;
    if (c > m[i] - '0')return 0;
    if (m.size() == 1 && c == 0)return 0;
    if (i == m.size() - 1)return dp[i][c] = 1;
    if (dp[i][c] != -1)return dp[i][c];
    long long ret =0;
    for (int new_c = 0; new_c < c;++new_c){
       ret += dfs(m, i+1, new_c, dp);
    }
    //cout << "ret " << ret <<endl;
    return dp[i][c] = ret;
}

int good(LL m, LL k){
    auto s = to_string(m);
    LL ret = 0;
    vector<vector<LL>> dp(12, vector<LL>(12, -1));
    for (int c = '0'; c <= s[0]; ++c){
	ret += dfs(s, 0, c - '0', dp);
    }
   cout << m << "ret -- k" << ret << " " << k << endl;
   if (ret > k)return HIGH;
   else if (ret == k)return ON;
   else return LOW;
}
int main(){
    LL n;
    cin >> n;
   // LL lo = 1, hi = 9876543210;
   LL lo = 1, hi = 33;
    while (lo < hi){
        LL mid = (lo + hi) / 2;
	auto ee = good(mid, n);
        cout << mid << "+++ Hi on lo  "<< ee<< endl;
	if (good(mid, n) == HIGH){
	    hi = mid - 1;
	}else if (good(mid, n) == LOW){
	    lo = mid + 1;
	} else {
	    hi = mid;
	}
    }
    cout << lo << endl;
    /*
    vector<vector<LL>> dp(12, vector<LL>(12, -1));
    string m = "95";
    auto ret = dfs(m, 0, 9, dp);
    cout << ret <<endl;
    */
return 0;
  }
