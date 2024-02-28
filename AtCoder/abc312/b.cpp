#include<iostream>
#include<vector>
using namespace std;
bool good(vector<string> &s, int i, int j){
    for (int ii = 0; ii < 9;++ii){
	for (int jj = 0; jj < 9; ++jj){
	    int r = i + ii, c = j + jj;
	    if (ii <3 &&  jj< 3){
		if (s[r][c] != '#')
		{return false;}
	    }
	    if (ii >=6 && jj >= 6){
		if (s[r][c] != '#')
		{return false;}
	    }
	    if (ii == 3 && jj <= 3){
		if (s[r][c] != '.')
		{return false;}
	    }
	    if (ii <= 3 && jj == 3){
		if (s[r][c] != '.')
		{return false;}
	    }
	    if (ii == 5 && jj >= 5){
		if (s[r][c] != '.')
		{return false;}
	    }
	    if (ii >= 5  && jj == 5){
		if (s[r][c] != '.')
		{return false;}
	    }
	}
    }
    return true;
}
int main(){
  int n, m; cin >> n >> m;
  vector<string>s(n);
  for (int i = 0 ; i < n; ++i){
      cin >> s[i];
  }
  for (int i = 0; i < n-8; ++i){
      for (int j = 0; j < m-8 ; ++j)
      {
	  if (good(s, i, j)){
	      cout << i+1 <<" "<<j+1 <<endl;
	  }
      }
  }
return 0;
  }
