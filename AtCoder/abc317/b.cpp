#include<iostream>
#include<vector>
#include<set>
#include<unordered_set>
#include <algorithm>
using namespace std;
int main(){
   int n;cin>>n;
   vector<int>nums(n);
   for (int i = 0; i < n; ++i){
       cin >> nums[i];
   }
   sort(nums.begin(), nums.end());
   for (int i = 1; i < n; ++i){
       if (nums[i] != nums[i-1] + 1){
	   cout << nums[i-1] + 1 <<endl;
	   return 0;
       }
   }
return 0;
  }
