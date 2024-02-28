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
    //for (auto x: col)cout <<x << " ";
    cout << endl;
    for (int i = 0; i < n; ++i){
	vector<int> candidates;
	for (int j =0 ; j < n; ++j){
	    if (a[i][j] == 'o')candidates.push_back(j);
	}
	int m = candidates.size();
	//cout << i <<" "<<m<<endl;
	if (m <= 1)continue;
	LL curr_ret = ret;
	for (int kk = 0; kk < m -1; ++kk){
           for (int ll = kk + 1; ll < m; ++ll){
              int k = candidates[kk];
	      int l = candidates[ll];
	       //cout << k <<" "<< l<< "" << col[k] - 1 << "" << col[l] - 1<<endl;
	       ret += LL(col[l] + col[k] - 2);
	   }
	}
	//cout << (ret - curr_ret) << endl;
    }
    cout << ret << endl;

return 0;
  }
