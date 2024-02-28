#include<vector>
#include<iostream>
using namespace std;

bool dfs(vector<string>&grid, int i, int j, int R, int C, vector<vector<bool>>&seen, vector<vector<bool>>&new_seen){
 if (i < 0 || i >= R || j<0 || j >=C)return true;
 if (grid[i][j] == '.')return false;
 if (new_seen[i][j] || grid[i][j] == 'B')return true;
 if (seen[i][j])return false;
 if (new_seen[i][j])return true;
 new_seen[i][j] = true;
 return dfs(grid, i+1, j, R, C, seen, new_seen)  && dfs(grid, i-1, j, R, C, seen, new_seen) && dfs(grid, i, j+1, R, C, seen, new_seen)  && dfs(grid, i, j-1, R, C, seen, new_seen);
}
bool ok(vector<string>grid, int R, int C){
    vector<vector<bool>>seen(R, vector<bool>(C, false));
    for (int i = 0; i < R; ++i){
	for (int j = 0; j < C; ++j){
	    if (grid[i][j] == 'W' && !seen[i][j]){
                vector<vector<bool>>new_seen(R, vector<bool>(C, false));
		//grid[i][j] = 'B';
		if (dfs(grid, i, j,  R, C, seen, new_seen)){
		    return true;
		}else {
		     for (int i = 0; i < R; ++i){                                                        
        for (int j = 0; j < C; ++j){ 
	    seen[i][j] = seen[i][j] || new_seen[i][j];
	    }}
		}
	    }
	}
    }
    return false;
}
bool good(vector<string>&grid, int R, int C){
    for (int i = 0; i < R; ++i){
	for (int j = 0; j < C; ++j){
	    if (grid[i][j] == '.'){
		grid[i][j] = 'B';
		auto ret = ok(grid, R, C);
		//cout << i << " " << j << " "<< ret<<endl;
		if (ret){
		    return true;
		}else{
		    grid[i][j] = '.';
		}
	    }
	}
    }
    return false;
}
void solve(int id){
int R, C;
cin >> R >> C;
vector<string>grid(R);
for (int i = 0; i < R; ++i){
    cin >> grid[i];
}
if (good(grid, R, C)){
    cout << "Case #"<<id<<": " <<"YES"<<endl;
} else {
    cout << "Case #"<<id<<": " <<"NO"<<endl;
}
}


int main(){
    int T;
    cin >> T;
   for (int i = 1; i <= T; ++i){
	solve(i);
    }
return 0;
  }
