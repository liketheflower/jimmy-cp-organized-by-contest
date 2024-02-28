#include<iostream>
#include<vector>
#include<cstring>

using namespace std;
typedef pair<int, int> PII;
int dp[201][201][4];
vector<PII> dirs = {{0, 1},{0, -1},{1, 0},{-1, 0}};
void dfs( vector<string>& grid, int i, int j, vector<vector<int>>& touch, int n, int m){
    for (int k = 0; k < 4; ++k){
	if (dp[i][j][k])continue;
	int ii = i, jj = j;
	auto [di, dj] = dirs[k];
	while (grid[ii][jj] != '#'){
	    touch[ii][jj] = 1;
	    dp[ii][jj][k] = 1;
	    ii += di;
	    jj += dj;
	  //  cout << ii << " " <<  jj <<endl;
	}
	    ii -= di;
	    jj -= dj;
	dfs(grid, ii,jj, touch, n, m);
    }
}
int main(){
    int n, m; cin  >> n >> m;
    vector<string> grid(n);
    vector<vector<int>> touch(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i)cin >> grid[i];
    memset(dp, 0, sizeof dp);
    dfs(grid, 1, 1, touch, n, m);
    int ret = 0;
    for (int i = 0; i < n; ++i){
	for (int j = 0;  j< m; ++j){
	    ret += touch[i][j];
	    //cout << touch[i][j] <<" ";
	}
	//cout << endl;
    }
    cout << ret << endl;
return 0;
  }
