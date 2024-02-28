#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
int dp[3001][3001];
const int MOD = 998244353;
void dfs(string &s, int i, int n){
    if (i == n +1)return;
    for (int j = 0; j <= n; ++j){
	if (s[i] == '('){
	    dp[j+1][i] += dp[j][i-1];
	     dp[j+1][i] %= MOD;
	} else if (s[i] == ')'){
	    if (j>=1){
		dp[j-1][i] +=  dp[j][i-1];   
		dp[j-1][i] %= MOD;
	    }
	} else {
	    dp[j+1][i] += dp[j][i-1];
	     dp[j+1][i] %= MOD;
	    if (j>=1){
                dp[j-1][i] +=  dp[j][i-1];
		dp[j-1][i] %= MOD;
            }
	}

    }
    dfs(s, i+1, n);
}

int main(){
    string s;
    cin >> s;
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    const int n = s.size();
    dfs(s, 1, n);
    int ret = 0;
    cout << dp[0][n]<<endl;
return 0;
  }
