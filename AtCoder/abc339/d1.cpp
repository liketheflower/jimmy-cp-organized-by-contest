#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
const int N = 65;
int mask[N][N][N][N];
typedef pair<int, int> PII;
bool invalid(int i, int j,  vector<string>&grid, int n){
    if (i == 0 || j ==0  || i == n +1 || j == n +1 || grid[--i][--j] == '#')return true;
    return false;
}
int bfs(int i1, int j1, int i2, int j2, vector<string>& grid, int n){
    vector<pair<PII, PII>> curr_level;
    vector<PII> dirs = {{0, 1},{0, -1},{1, 0},{-1, 0}};
    curr_level.emplace_back(make_pair(i1, j1), make_pair(i2, j2));
    int level = 0;
    int r1, r2, c1, c2;
    while (!curr_level.empty()){

	vector<pair<PII, PII>> next_level;
	for (auto [ij1, ij2]: curr_level){
	    auto [i1, j1] = ij1;
	    auto [i2, j2] = ij2;
	    for (auto [di, dj]: dirs){
		r1 = i1 + di;
		c1 = j1 + dj;
		r2 = i2 + di;
		c2 = j2 + dj;
		if (invalid(r1, c1, grid, n)){
		    r1 = i1;
		    c1 = j1;
		}
		if (invalid(r2, c2, grid, n)){
		    r2 = i2;
		    c2 = j2;
		}
		if (r1 == r2 && c1 == c2)return level + 1;
		if (mask[r1][c1][r2][c2])continue;
		mask[r1][c1][r2][c2] = 1;
		next_level.emplace_back(make_pair(r1, c1), make_pair(r2, c2));
	    }
	}
	level++;
	curr_level = next_level;
    }
    return -1;
}
int main(){
    memset(mask, 0, sizeof mask);
    int n; cin >> n;
    int i1=-1, j1=-1, i2=-1, j2 =-1;
    vector<string> grid(n);
    for (int i = 0; i < n; ++i){
	cin >> grid[i];
	for (int j = 0; j < n; ++j){
	    if (grid[i][j] == 'P'){
		if (i1 == -1){
		    i1 = i + 1;
		    j1 = j + 1;
		}else{
		    i2 = i + 1;
		    j2 = j + 1;
		}
	    }
	}
    }
    mask[i1][j1][i2][j2] = 1;
    auto ret = bfs(i1, j1, i2, j2, grid, n);
    cout << ret << endl;
    return 0;
}
