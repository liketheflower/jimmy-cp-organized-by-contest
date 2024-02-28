#include <iostream>
#include <vector>
using namespace std;
const int N = 101;
int row[N], col[N], diag[2*N], antidiag[4*N];
bool reachable(int n){
   for (int i = 0; i < n; ++i)for(int j =0; j< n;++j){
     if (row[i] || col[j] || diag[i+j] || antidiag[i-j + 2*n])continue;
     else return false;
   }
   return true;
}

bool dfs(int i, vector<string>& grid, int q, int n ){
    //cout << i << " "<< j << " " << q << endl;
    if (q == n - 2){                                                                    
        auto reach= reachable(n);                                
        //cout << "reach: "<<reach <<endl;                                                
         if(reach){                                                                  
        //for (auto g: grid) cout << g << endl;                                           
        //return true;
        string outputs = "";
        outputs.push_back('{');
        for (int i = n - 4; i < n; ++i)for (int j = 0; j < n; ++j){
           if (grid[i][j] == 'Q') {outputs.push_back('{'); 
            outputs += to_string(i);
            outputs.push_back(',');
            outputs += to_string(j);
            outputs.push_back('}');
            outputs.push_back(',');
            }
        }
        outputs.pop_back();
        outputs.push_back('}');
        outputs.push_back(',');
        cout << outputs;                                                                    
        return true;                                                                   
        }
        return false;                                                                               
    }       
    if (i >= n) return false;                                                                            
    // put in this row
    for (int j = 0; j < n; ++j){
        //if (row[i] || col[j] || diag[i+j] || antidiag[i - j + 2*n]) continue;
        if(grid[i][j] == 'Q' || diag[i+j])continue;
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
        if (dfs(i+1, grid, q+1, n)){
            return true;
        }
        row[i] -= 1;
        col[j] -= 1;
        diag[i+j] -= 1;
        antidiag[i-j+2*n] -= 1;
        grid[i][j] = '.';
    }
    // not put in this row
    
    return dfs(i+1, grid, q, n);
}

void solve1(int n){
    string s;
    for (int j = 0; j < n; ++j)s.push_back('.');
    vector<string>grid(n, s);
    //vector<int> row(n, 0), col(n, 0), diag(2*n, 0), antidiag(4*n, 0);
    dfs(0, grid, 0, n);
}
void solve2(int n){
    string s;
    for (int j = 0; j < n; ++j)s.push_back('.');
    vector<string>grid(n, s);
   // vector<int> row(n, 0), col(n, 0), diag(2*n, 0), antidiag(4*n, 0);
   for (int i = 0; i < n- 4; ++i){
        grid[i][0] = 'Q';
        row[i] += 1;
        col[0] += 1;
        diag[i] += 1;
        antidiag[i+2*n] += 1;
    }
    dfs(n-4, grid, n-4, n);
}
int main() {
        //int T; cin >> T;
            cout <<"{";
       for (int n = 10; n <= 100; ++n){
           // int n; cin >>  n;
           //cout << n;
   memset(row, 0, sizeof row); 
   memset(col, 0, sizeof col); 
   memset(diag, 0, sizeof diag); 
   memset(antidiag, 0, sizeof antidiag); 
            if(n<5)solve1(n);
            else solve2(n);
        }	
            cout <<"};";
	return 0;
        
}

