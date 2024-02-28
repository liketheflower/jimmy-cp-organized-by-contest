#include<iostream>
#include <algorithm>  
#include<vector>
using namespace std;
int main(){
   int n, m;
    cin >> n >>m;
    vector<int> nums(m, 0);
    for (int i = 0; i < m; ++i)cin>>nums[i];
    vector<int> ret(n+1, 0);
    int i =0, j = 0;
    sort(nums.begin(),nums.end());
    for (int k = 1; k <= n; ++k){
	if (nums[j]>=k){
	    ret[k] = nums[j] - k;
	} else {
	    while (nums[j] < k)j++;
	    ret[k] = nums[j] - k;
	}
    }
    for (int i = 1; i <= n;++i)cout <<ret[i]<<endl;
return 0;
  }
