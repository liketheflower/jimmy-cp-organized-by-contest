#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n, x;
    cin >> n >> x;
    vector<int>a(n-1,0);
    int sum = 0;
    for(int i = 0; i < n-1;++i){
	cin >> a[i];
	sum += a[i];
    }
    sort(a.begin(), a.end());
    int ret = 200;
    // last one is the min val?
    int this_sum = sum - a.back();
    if (this_sum >= x){
	ret = min(ret, 0);
    }
    // last one is the max val?
    this_sum = sum - a[0];
    if (this_sum >= x){
	ret = min(ret, a.back());
    }
    // last one is not min and not max?
    this_sum = sum - a[0] - a.back();
    int remain = x - this_sum;
    if (remain >= 0 && remain >= a[0] && remain <= a.back()){
	ret = min(ret, remain);
    }
    if (remain < 0){
	ret = min(ret, a[0]);
    }
   ret = ret == 200? -1: ret;
   cout << ret << endl;

return 0;
  }
