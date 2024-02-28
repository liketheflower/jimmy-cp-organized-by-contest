#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
#include<set>
#include<cstring>
using namespace std;
typedef long long LL;
const int N = 100000010;
LL min_val[N];
LL max_val[N];
void update(LL a, LL b, LL a1, LL b1, LL& a2, LL &b2){
    // a/b + a1/b1 
    a2 = a*b1 + a1*b;
    b2 = b*b1;
}
int main(){
    int n, x;
    cin >> n >> x;
    vector<int>nums(n,0 );
    for (int i = 0; i < n; ++i){
	cin >> nums[i];
    }
    memset(min_val, 0, sizeof min_val);
    memset(max_val, 0, sizeof max_val);
    for (auto num: nums){
    LL curr = 0;
    while (curr < x + nums[0]){
	if (min_val[curr]==0){
	    min_val[curr] = 1;
	    max_val[curr] = n;
	} else {
	    LL curr_min =  min_val[curr];
	    LL curr_max = max_val[curr];
	    LL new_val = curr + num;
	    LL new_min = curr_min;
	    LL new_max = curr_max *n;
	    curr = new_val;
	    if (min_val[new_val] ==0){
		min_val[new_val] = new_min;
		max_val[new_val] = new_max;
	    } else {
		LL updated_new_min, updated_new_max;
		update(new_min, new_max, min_val[new_val],  max_val[new_val], updated_new_min, updated_new_max);
		min_val[new_val] = updated_new_min;
		max_val[new_val] = updated_new_max;
	    }
	}
    }	
    }
    LL a=0, b=0;
    for (int num = x; num < x + nums[0]; ++num){
	LL a_, b_;
	if (min_val[num] == 0)continue;
	    update(1, n, min_val[num], max_val[num], a_, b_);
	    if (a==0){
		a = a_;
		b =  b_;
	    }else {
		update(a_, b_, a, b, a, b);
	    }
    }
    cout << a<<" "<<b<<endl;
return 0;
  }
