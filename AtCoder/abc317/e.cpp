#include<iostream>
#include<vector>
#include<set>
#include<cstring>
#include<unordered_set>
#include <algorithm>
using namespace std;
typedef pair<int, int> PII;
vector<PII>dirs = {{0, 1},{0, -1},{1, 0},{-1, 0}};
void update_up(vector<string>&a, int i, int j){
    a[i][j] = '#';
    for (int ii = i - 1; ii >= 0; --ii){
	if (a[ii][j] == '.')a[ii][j] = '#';
	else if (a[ii][j] == '!') continue;
	else break;
    }
}
void update_down(vector<string>&a, int i, int j, int n){
    a[i][j] = '#';
    for (int ii = i + 1; ii < n; ++ii){
	if (a[ii][j] == '.')a[ii][j] = '!';
	else if (a[ii][j] == '!') continue;
	else break;
    }
}
void update_left(vector<string>&a, int i, int j){
    a[i][j] = '#';
    for (int jj = j - 1; jj >= 0; --jj){
	if (a[i][jj] == '.')a[i][jj] = '#';
	else if (a[i][jj] == '!') continue;
	else break;
    }
}
void update_right(vector<string>&a, int i, int j, int m){
    a[i][j] = '#';
    for (int jj = j + 1; jj < m; ++jj){
	if (a[i][jj] == '.')a[i][jj] = '#';
	else if (a[i][jj] == '!') continue;
	else break;
    }
}
int main(){
   int n, m;cin>>n>>m;
   vector<string>grid(n);
   for (int i = 0; i <n; ++i){
       cin >> grid[i];
   }
   int s_i, s_j, g_i, g_j;
   for (int i = 0; i < n; ++i){
       for (int j = 0; j <m;++j){
	   if (grid[i][j] == '^')update_up(grid, i, j);
	   if (grid[i][j] == 'v')update_down(grid, i, j, n);
	   if (grid[i][j] == '<')update_left(grid, i, j);
	   if (grid[i][j] == '>')update_right(grid, i, j, m);
	   if (grid[i][j] == 'S')s_i = i, s_j = j;
	   if (grid[i][j] == 'G')g_i = i, g_j = j;
       }
   }
   for (int i = 0; i < n; ++i){
       for (int j = 0; j <m;++j){
	   if (grid[i][j] == '!')grid[i][j] = '#';
       }
   }
vector<PII>Q;
Q.emplace_back(s_i, s_j);
int level = 0;
while (!Q.empty()){
vector<PII>this_Q;
for (auto [i, j]: Q){
for (auto [di, dj]: dirs){
    int r = i + di, c = j + dj;
    if  (r < 0 || r >= n || c <0 || c >= m || grid[r][c] == '#')continue;
    if (r == g_i && c == g_j){
	cout << level + 1<<endl;
	return 0;
    }
    grid[r][c] = '#';
    this_Q.emplace_back(r, c);
}
}
Q = this_Q;
level++;
}

cout << -1 <<endl;
return 0;
  }
