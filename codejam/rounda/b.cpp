#include<iostream>                                                                      
#include<vector>
#include<unordered_map>
#include<algorithm>                                                                     
using LL = long long;
using namespace std;                                                                    
int main(){                                                                             
   int T; cin >> T;                                                                     
   for (int i = 1; i <= T; ++i){                                                        
      //cout<<"Case #" << i << ": ";
      unordered_map<LL, vector<int>> ca;
      ca[0ll] = {};  
      int N;
      cin >> N;
      LL sum = 0ll;
      vector<int> nums;
      int num; 
      for (int j = 0 ; j < 2*N; ++j){
         cin >> num; nums.push_back(num); sum+=(LL)num;
      }
      LL half = sum / 2;
      LL this_sum = 0ll;
     /*
     sort(nums.rbegin(), nums.rend());
     //for (auto x: nums)cout << x << endl;
    // cout << half<< endl;
      for (int j = 0 ; j < 2*N; ++j){
         num = nums[j];
         unordered_map<LL, vector<int>> new_ca;
         new_ca[0ll] = {};
         for (auto [k, v]: ca){
            if (new_ca.find(k) == new_ca.end())new_ca[k] = v;
            if (k + num <= half && new_ca.find(k + num) == new_ca.end()){
              new_ca[k + num] = v;
              new_ca[k + num].push_back(num);
            }
         }
         ca = new_ca;
         if (ca.find(half) != ca.end()) {
           for (auto x: ca[half]) cout << x << " ";
           cout << endl;
           break;
          }
         
      }                                                       
   }   
*/                                                                                 
   return 0;                                                                            
}      
