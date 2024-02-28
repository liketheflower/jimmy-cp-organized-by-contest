#include<iostream>
#include<vector>
typedef long long LL;
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0 ; i < n; ++i)cin >> a[i];
    LL ret=0ll;
    vector<int>col(n, 0);
    for (int j = 0; j < n; ++j){
	for(int i = 0; i <n; ++i){
	col[j] += a[i][j] == 'o';
	}
    }
    for (int i = 0; i < n; ++i){
	for (int i1 = i + 1; i1 < n; ++i1){
	    
	}
    }
    cout << ret << endl;

return 0;
  }
