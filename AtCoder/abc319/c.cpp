#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include <algorithm>
#include <iomanip>
using namespace std;
typedef pair<int, int> PII;
int make_pair_(int i, int j){
return i*3 + j;
}
bool bad(vector<PII>&a, vector<vector<int>>&grid){
    vector<int>m(9, 0);
    for (int i = 0; i < 9; ++i){
	auto [k, j] = a[i];
	m[make_pair_(k, j)] = i;
    }
    for (int i = 0 ; i < 3; ++i){
	if (grid[i][0] == grid[i][1]){
	    auto ii0=make_pair_(i, 0);
	    auto ii1=make_pair_(i, 1);
	    auto ii2=make_pair_(i, 2);
	    if (m[ii2] > m[ii1] && m[ii2] > m[ii0])return true;
	}
	if (grid[i][2] == grid[i][1]){
	    auto ii0=make_pair_(i, 0);
	    auto ii1=make_pair_(i, 1);
	    auto ii2=make_pair_(i, 2);
	    if (m[ii0] > m[ii1] && m[ii0] > m[ii2])return true;
	}
	if (grid[i][2] == grid[i][0]){
	    auto ii0=make_pair_(i, 0);
	    auto ii1=make_pair_(i, 1);
	    auto ii2=make_pair_(i, 2);
	    if (m[ii1] > m[ii0] && m[ii1] > m[ii2])return true;
	}
    }
    for (int j = 0 ; j < 3; ++j){
	if (grid[0][j] == grid[1][j]){
	    auto ii0=make_pair_(0, j);
	    auto ii1=make_pair_(1, j);
	    auto ii2=make_pair_(2, j);
	    if (m[ii2] > m[ii1] && m[ii2] > m[ii0])return true;
	}
	if (grid[1][j] == grid[2][j]){
	    auto ii0=make_pair_(0, j);
	    auto ii1=make_pair_(1, j);
	    auto ii2=make_pair_(2, j);
	    if (m[ii0] > m[ii1] && m[ii0] > m[ii2])return true;
	}
	if (grid[0][j] == grid[2][j]){
	    auto ii0=make_pair_(0, j);
	    auto ii1=make_pair_(1, j);
	    auto ii2=make_pair_(2, j);
	    if (m[ii1] > m[ii0] && m[ii1] > m[ii2])return true;
	}
    }
    if (grid[0][0] == grid[1][1]){
	    auto ii0=make_pair_(0, 0);
	    auto ii1=make_pair_(1, 1);
	    auto ii2=make_pair_(2, 2);
	    if (m[ii2] > m[ii1] && m[ii2] > m[ii0])return true;
    }
    if (grid[2][2] == grid[1][1]){
	    auto ii0=make_pair_(0, 0);
	    auto ii1=make_pair_(1, 1);
	    auto ii2=make_pair_(2, 2);
	    if (m[ii0] > m[ii1] && m[ii0] > m[ii2])return true;
    }
    if (grid[2][2] == grid[0][0]){
	    auto ii0=make_pair_(0, 0);
	    auto ii1=make_pair_(1, 1);
	    auto ii2=make_pair_(2, 2);
	    if (m[ii1] > m[ii0] && m[ii1] > m[ii2])return true;
    }

    if (grid[0][2] == grid[1][1]){
	    auto ii0=make_pair_(0, 2);
	    auto ii1=make_pair_(1, 1);
	    auto ii2=make_pair_(2, 0);
	    if (m[ii2] > m[ii1] && m[ii2] > m[ii0])return true;
    }
    if (grid[2][0] == grid[1][1]){
	    auto ii0=make_pair_(0, 2);
	    auto ii1=make_pair_(1, 1);
	    auto ii2=make_pair_(2, 0);
	    if (m[ii0] > m[ii1] && m[ii0] > m[ii2])return true;
    }
    if (grid[2][0] == grid[0][2]){
	    auto ii0=make_pair_(0, 2);
	    auto ii1=make_pair_(1, 1);
	    auto ii2=make_pair_(2, 0);
	    if (m[ii1] > m[ii0] && m[ii1] > m[ii2])return true;
    }

    return false;
}




int main(){
    vector<PII> a;
    vector<vector<int>> grid(3, vector<int>(3, 0));
    for (int i = 0; i < 3; ++i){
	for (int j = 0; j < 3; ++j){
	    int this_num; cin >> this_num;
	    grid[i][j] = this_num;
	    a.emplace_back(i, j);
	}
    }
    int ret = 0;
    int tot = 362880;
    do {
	ret += bad(a, grid);
    } while (next_permutation(a.begin(), a.end()));
     long double fin_ret =(long double)(tot - ret) / (long double)(tot);
    cout << setprecision (25) <<fin_ret <<endl;
 
return 0;
  }
