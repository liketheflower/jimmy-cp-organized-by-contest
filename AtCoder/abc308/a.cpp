#include<iostream>
#include<vector>
using namespace std;
void check(vector<int>nums){
    for (auto x: nums){
	if (x < 100 || x > 675){
	    cout << "No" <<endl;
	    return;
	}
	if (x%25!=0){
	    cout << "No" <<endl;
	    return;
	}
    }
    for (int i = 1; i < 8; ++i){
	if (nums[i] < nums[i-1]){
	    cout << "No" <<endl;
	    return;
	}
    }
	    cout << "yes" <<endl;
	    return;
}
int main(){
  vector<int> nums;
  for (int i = 1; i <= 8; ++i){
      int this_num;
      cin  >> this_num;
      nums.push_back(this_num);
  }
  check(nums);
  return 0;
}
