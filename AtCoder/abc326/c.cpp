#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n, m;
    cin>>n>>m;
    vector<int>a(n, 0);
    for (int i = 0; i <n;++i){
	cin >> a[i];
    }
    int ret = 0;
    sort(a.begin(), a.end());
    for (int i =0; i < n; ++i){
	int x = a[i];
	int y = x + m;
	int idx = lower_bound(a.begin(), a.end(), y) - a.begin();
	ret = max(ret, idx - i);
    }
    cout <<ret <<endl;

return 0;
  }
