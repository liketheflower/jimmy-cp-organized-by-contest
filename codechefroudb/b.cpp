#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using LL = long long;
using namespace std;
void solve(int m){
    if (m == 0) {
    int c;
    cin >> c;
    cout << "YES"<<endl;return;}
    int n = 1 << m; 
    vector<LL> nums(n, 0ll);
    for (int j = 0; j < n; ++j)cin >> nums[j];
    //sort(nums.begin(), nums.end());
    while (true){
        unordered_map<LL, int> m;
        for (auto x: nums)m[x]++;
        vector<LL> newnums;
        sort(nums.begin(), nums.end());
        for (auto num: nums){
            if (m[num] > 0){
                if (m[num+1] >0){
                    m[num + 1]--;
                    m[num]--;
                    newnums.push_back(2*num + 1);
                } else if (m[num] >= 2){
                    newnums.push_back(2*num);
                    m[num] -= 2;
                } else {
                    cout << "NO" << endl;
                   return;
                }
            }
        }
        nums = newnums;
        if (nums.size() == 1){
          if (nums[0] > 0){
          cout << "YES" << endl;
          } else {
           cout <<"NO"<<endl;
          }
          return;
        }
    }
   return;
}
int main() {
        int T; cin >> T;
        while (T--){
            int m; cin >> m;
            solve(m);
        }	
	return 0;
        
}

