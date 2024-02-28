#include<iostream>
#include<vector>
using namespace std;
void lis(vector<int>&nums){
    const int n = nums.size();
    int ret = 0;
    for (int i = 0; i < n; ++i)
    {
	bool good = true;
	for (int j = i + 1; j < n; ++j)
	{
	    if (nums[j] < nums[i]){
		good = false;
		break;
	    }
	}
	ret += good;
    }
    cout << ret <<endl;
   
}
void solve(){
    int N;
    cin >> N;
    vector<int> nums(N, 0);
    for (int i = 0; i < N; ++i)
    {
	cin >> nums[i];
    }
    lis(nums);
}
int main(){
    int T;
    cin >> T;
    while (T--){
	solve();
    }
    return 0;
}
