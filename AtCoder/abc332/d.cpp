#include<iostream>
#include<vector>
typedef long long LL;
using namespace std;

LL f(LL i, LL j, vector<vector<LL>>& prefix, LL n){
    if (i <= n && j <=n)return prefix[i][j];   
    LL ii = i % n;
    LL jj = j % n;
    LL R = i / n;
    LL C = j / n;
    LL complete =R*C*prefix[n][n];
    complete += R*f(n, jj, prefix, n);
    complete += C*f(ii, n, prefix, n);
    return complete + prefix[ii][jj];

}
int main(){
    int n, Q;
    cin >> n >> Q;
    vector<vector<int>> a(n, vector<int>(n, 0));
    string s;
    for (int i = 0; i < n; ++i)
    {
	cin  >> s;
	for (int j = 0 ; j < n ; ++j){
	    if (s[j] == 'B')a[i][j] = 1;
	}
    }

    vector<vector<LL>> prefix(n + 1, vector<LL>(n + 1, 0));
    for (int i = 1; i <= n; ++i)
	for (int j = 1 ; j <= n ; ++j){
	    prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + a[i-1][j-1];
	}

    LL i1, j1, i2, j2, ret;
    for (int i = 0 ; i < Q; ++i){
	cin >> i1 >> j1 >> i2 >> j2;
	LL this_ret = f(i2+1, j2+1, prefix, n) -f(i2+1, j1, prefix, n) - f(i1, j2+1, prefix, n) + f(i1, j1, prefix, n);
	cout << this_ret << endl;
    }
    return 0;
}
