#include<vector>
#include<iostream>
using namespace std;
vector<pair<int, int>>dirs = {{0, 1},{0, -1},{1, 0},{-1, 0},{1, 1},{1, -1},{-1, 1},{-1, -1}};
void dfs( vector<string>& p, int i, int j, int n, int m){
    if (i <0 || i>=n || j <0 || j >=m || p[i][j] != '#')return;
    p[i][j] = '.';
    for (auto [di, dj]: dirs){
    dfs(p, i + di, j + dj, n, m);
    }
}
int main(){
    int ret=0;
    int n, m;
    cin >> n>> m;
    vector<string> p(n);
    for (int i = 0; i < n; ++i){
	cin >> p[i];
    }
    for (int i = 0 ; i <n; ++i){
	for (int j = 0; j < m; ++j){
	    if (p[i][j] == '#'){
		ret ++;
		dfs(p, i, j, n, m);
	    }
	}
    }
    cout << ret <<endl;
return 0;
  }
