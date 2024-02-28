#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
typedef long long LL;
const int N = 1e6+10;



LL a[N],b[N];
LL solve(vector<int>& nums, int n, int d)
{
    LL ret = 0;
    const int m = nums.size();
    for (int i = 0; i < n; ++i)
    {
	int l = nums[i]-d, r = nums[i] + d;
        b[l]=b[l]+diff;
        b[r+1]=b[r+1]-diff;
    }
    LL sum=0;
    LL fin_ret = 0x3ff3f3f3f3f3f3f;
  //  cout <<"RET" << ret << endl;
    for (int i = 1; i <= n; i ++ )
    {
        sum=sum+(LL)b[i];
//	cout << i <<" "<<sum<<endl;
	fin_ret = min(fin_ret, ret + sum);
    }

    return fin_ret;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(a, 0, sizeof a);
    memset(b, 0, sizeof b);
    int n, d; cin >> n>> d;
    vector<int> nums(m, 0);
    for (int i = 0; i < m; ++i)cin >> nums[i];
    auto ret = solve(nums, n, d);
    cout << ret << endl;
    return 0;
}
