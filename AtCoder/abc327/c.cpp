#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool check_row(vector<vector<int>>&a){
    for (int i = 0 ; i <9;++i){
	vector<int>seen(10, 0);
	for (int j = 0; j < 9; ++j){
	    if (a[i][j] > 9 || a[i][j] < 1)return false;
	    if (seen[a[i][j]])return false;
	    seen[a[i][j]] = 1;
	}
    }
    return true;
}
bool check_col(vector<vector<int>>&a){
    for (int j = 0 ; j <9;++j){
	vector<int>seen(10, 0);
	for (int i = 0; i < 9; ++i){
	    if (a[i][j] > 9 || a[i][j] < 1)return false;
	    if (seen[a[i][j]])return false;
	    seen[a[i][j]] = 1;
	}
    }
    return true;
}
bool check_block(vector<vector<int>>&a){
    for (int i = 0 ; i <9; i+= 3){
	for (int j = 0; j < 9; j += 3){
	    vector<int>seen(10, 0);
	    for (int ii = 0; ii < 3; ++ii){
		for (int jj = 0; jj < 3; ++jj){
		    int r = i + ii;
		    int c = j + jj;
	    if (seen[a[r][c]])return false;
	    seen[a[r][c]] = 1;

		}
	    }
	}
    }
    return true;
}
int main(){
    int n=9;
    vector<vector<int>>a(n,vector<int>(n, 0));
    for (int i = 0; i <n;++i){
	for (int j = 0; j < n; ++j){
	    cin >> a[i][j];
	}
    }

    if (!check_row(a)){
	cout << "No"<<endl;
	return 0;
    }
    if (!check_col(a)){
	cout << "No"<<endl;
	return 0;
    }
    if (!check_block(a)){
	cout << "No"<<endl;
	return 0;
    }

    cout << "Yes" <<endl;

return 0;
  }
