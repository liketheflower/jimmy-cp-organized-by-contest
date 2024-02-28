#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
typedef long long LL;
const int N = 1e6+10;
LL a[N],b[N];
LL solve(vector<int>& nums, int n)
{
    LL ret = 0;
    const int m = nums.size();
    for (int i = 0; i < m - 1; ++i)
    {
	int u = nums[i], v = nums[i+1];
	int l = u, r = v - 1;
	if (u > v){
	    l = v; r = u - 1;
	}
	int ret1 = r - l + 1;
	int ret2 = n - ret1;
//	cout << i <<" i r "<<min(ret1, ret2) <<" "<<ret1<<ret2<<endl;
	ret += (LL)(min(ret1, ret2));
	int diff = abs(ret1-ret2);
	if (diff ==0)continue;
        if (ret1 > ret2){
	    // l, r
	    //  [2, 5]
	    //  [6, n], [1, 1]
	    // r n, 1 to l
            int l1 = 1, r1 = l-1;
	    int l2 = r+1, r2 = n;
            if (l1 <= r1){
            b[l1]=b[l1]+diff;
            b[r1+1]=b[r1+1]-diff;
	    }
            if (l2 <= r2){
            b[l2]=b[l2]+diff;
            b[r2+1]=b[r2+1]-diff;
	    }

	} else {
            b[l]=b[l]+diff;
            b[r+1]=b[r+1]-diff;
	}
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
    int n, m; cin >> n>> m;
    vector<int> nums(m, 0);
    for (int i = 0; i < m; ++i)cin >> nums[i];
    auto ret = solve(nums, n);
    cout << ret << endl;
    return 0;
}
