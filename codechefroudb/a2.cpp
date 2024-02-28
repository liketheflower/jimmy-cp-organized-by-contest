#include <iostream>
#include <vector>
using namespace std;
bool reachable(vector<int>& row, vector<int>& col,vector<int>& diag,vector<int>& antidiag){
   const int n = row.size();
   for (int i = 0; i < n; ++i)for(int j =0; j< n;++j){
     if (row[i] || col[j] || diag[i+j] || antidiag[i-j + 2*n])continue;
     else return false;
   }
   return true;
}

bool dfs(int i, vector<string>& grid, vector<int>&row,vector<int>& col, vector<int>&diag,vector<int>& antidiag, int q){
    const int n = row.size();
    //cout << i << " "<< j << " " << q << endl;
    if (q == n - 2){                                                                    
        auto reach= reachable(row, col, diag, antidiag);                                
        //cout << "reach: "<<reach <<endl;                                                
         if(reach){                                                                     
        for (auto g: grid) cout << g << endl;                                           
        return true;                                                                    
        }                                                                               
        return false;                                                                   
    }       
    if (i >= n) return false;                                                                            
    // put in this row
    for (int j = 0; j < n; ++j){
        //if (row[i] || col[j] || diag[i+j] || antidiag[i - j + 2*n]) continue;
        if(grid[i][j] == 'Q')continue;
        /*int old_row = row[i];
        int olc_col = col[j];
        int old_d1 = diag[i+j];
        int old_d2 = antidiag[i-j+2*n];
        */
        row[i] += 1;
        col[j] += 1;
        diag[i+j] += 1;
        antidiag[i-j+2*n] += 1;
        grid[i][j] = 'Q';
        if (dfs(i+1, grid, row, col, diag, antidiag, q+1)){
            return true;
        }
        row[i] -= 1;
        col[j] -= 1;
        diag[i+j] -= 1;
        antidiag[i-j+2*n] -= 1;
        grid[i][j] = '.';
    }
    // not put in this row
    
    return dfs(i+1, grid, row, col, diag, antidiag, q);
}

void solve1(int n){
    string s;
    for (int j = 0; j < n; ++j)s.push_back('.');
    vector<string>grid(n, s);
    vector<int> row(n, 0), col(n, 0), diag(2*n, 0), antidiag(4*n, 0);
    dfs(0, grid, row, col, diag, antidiag, 0);
}
void solve2(int n){
    string s;
    for (int j = 0; j < n; ++j)s.push_back('.');
    vector<string>grid(n, s);
    vector<int> row(n, 0), col(n, 0), diag(2*n, 0), antidiag(4*n, 0);
    for (int i = 0; i < n- 4; ++i){
        grid[i][0] = 'Q';
        row[i] += 1;
        col[0] += 1;
        diag[i] += 1;
        antidiag[i+2*n] += 1;
    }
    dfs(n-4, grid, row, col, diag, antidiag, n-4);
}
int main() {
        int T; cin >> T;
        while (T--){
            int n; cin >>  n;
            if(n<5)solve1(n);
            else solve2(n);
        }	
	return 0;
        
}

