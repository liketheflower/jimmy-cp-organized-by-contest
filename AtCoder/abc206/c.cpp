#include<iostream>
#include<vector>
#include<map>
using namespace std;

void solve(vector<int>& nums){
    map<int, int> m;
    const int n = nums.size();
    m[nums[0]]++;
    long long ret = 0;
    for (int i = 1; i < n; ++i)
    {
        ret += i - m[nums[i]];
        m[nums[i]]++;
    }
    cout << ret << endl;
    return;
}


int main(){
    int T;
    cin >> T;
    vector<int> nums(T);
    for (int i = 0; i < T; ++i)
    {
        cin >> nums[i];
    }
    solve(nums);
    return 0;
}
