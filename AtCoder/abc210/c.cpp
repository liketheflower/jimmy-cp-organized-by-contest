#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main()
{
  int n, k;
  cin >> n >> k;
  unordered_map<int, int> m;
  int ret = 0;
  int num = 0;
  vector<int> nums(n, 0);
  for (int i = 0; i < n; ++i){
    cin >> nums[i];
    m[nums[i]] ++;
    if (i >= k){
      m[nums[i-k]]--;
      if (m[nums[i-k]] == 0) m.erase(nums[i-k]);
    }
    if (i >= k-1) {
    //cout <<  i << " "<< m.size() << endl;
    ret = max(ret, (int)m.size());
    }
  }
  cout << ret << endl;
  return 0;
}
