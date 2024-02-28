#include <iostream>
#include <vector>
using namespace std;
using PII = pair<int, int>;
vector<vector<PII>> rets= {{{6,8},{8,2}},{{7,9},{9,2}},{{8,10},{10,2}},{{9,11},{11,2}},{{10,12},{12,2}},{{11,13},{13,2}},{{12,14},{14,2}},{{13,15},{15,2}},{{14,16},{16,2}},{{15,17},{17,2}},{{16,18},{18,2}},{{17,19},{19,2}},{{18,20},{20,2}},{{19,21},{21,2}},{{20,22},{22,2}},{{21,23},{23,2}},{{22,24},{24,2}},{{23,25},{25,2}},{{24,26},{26,2}},{{25,27},{27,2}},{{26,28},{28,2}},{{27,29},{29,2}},{{28,30},{30,2}},{{29,31},{31,2}},{{30,32},{32,2}},{{31,33},{33,2}},{{32,34},{34,2}},{{33,35},{35,2}},{{34,36},{36,2}},{{35,37},{37,2}},{{36,38},{38,2}},{{37,39},{39,2}},{{38,40},{40,2}},{{39,41},{41,2}},{{40,42},{42,2}},{{41,43},{43,2}},{{42,44},{44,2}},{{43,45},{45,2}},{{44,46},{46,2}},{{45,47},{47,2}},{{46,48},{48,2}},{{47,49},{49,2}},{{48,50},{50,2}},{{49,51},{51,2}},{{50,52},{52,2}},{{51,53},{53,2}},{{52,54},{54,2}},{{53,55},{55,2}},{{54,56},{56,2}},{{55,57},{57,2}},{{56,58},{58,2}},{{57,59},{59,2}},{{58,60},{60,2}},{{59,61},{61,2}},{{60,62},{62,2}},{{61,63},{63,2}},{{62,64},{64,2}},{{63,65},{65,2}},{{64,66},{66,2}},{{65,67},{67,2}},{{66,68},{68,2}},{{67,69},{69,2}},{{68,70},{70,2}},{{69,71},{71,2}},{{70,72},{72,2}},{{71,73},{73,2}},{{72,74},{74,2}},{{73,75},{75,2}},{{74,76},{76,2}},{{75,77},{77,2}},{{76,78},{78,2}},{{77,79},{79,2}},{{78,80},{80,2}},{{79,81},{81,2}},{{80,82},{82,2}},{{81,83},{83,2}},{{82,84},{84,2}},{{83,85},{85,2}},{{84,86},{86,2}},{{85,87},{87,2}},{{86,88},{88,2}},{{87,89},{89,2}},{{88,90},{90,2}},{{89,91},{91,2}},{{90,92},{92,2}},{{91,93},{93,2}},{{92,94},{94,2}},{{93,95},{95,2}},{{94,96},{96,2}},{{95,97},{97,2}},{{96,98},{98,2}}};



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
void solve3(int n){
    string s;
    for (int j = 0; j < n; ++j)s.push_back('.');
    vector<string>grid(n, s);
    for (int i = 0; i < n- 4; ++i){
	grid[i][0] = 'Q';}
    for (auto [i, j]: rets[n - 10]){
	//cout << i <<" " << j <endl;
	grid[i][j] = 'Q';
    }
    for (auto g: grid) cout << g << endl; 
    return;

}
int main() {
    int T; cin >> T;
    while (T--){
	int n; cin >>  n;
	if(n<5)solve1(n);
	else if (n < 10 )solve2(n);
	else solve3(n);
    }	
    return 0;

}

