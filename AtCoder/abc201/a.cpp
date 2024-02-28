#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void getInput(vector<int> & nums)
{ 
  int num;
  for (int i = 0; i < 3; ++i)
  {
    cin >> num;
    nums.push_back(num);
  }
}

void solve(vector<int>& nums) 
{
  const int n = nums.size();
  if (n <= 1) 
  {
    cout << "Yes" << endl;
    return;
  }
  sort(nums.begin(), nums.end());
  int delta = nums[1] - nums[0];
  for (int i = 1; i < n; ++i)
  {
    if (nums[i] - nums[i-1] != delta) 
    {  
      cout << "No" << endl;
      return;
    }
  }
  cout << "Yes" << endl;
  return;
}

int main()
{
  vector<int> nums;
  getInput(nums);
  solve(nums);
  return 0;
}
