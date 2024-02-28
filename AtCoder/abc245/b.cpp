#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
int main()
{

    int n; cin >> n;
    unordered_set<int> s;
    for (int i = 0; i < n; ++i){
        int num; cin >> num;
        if (num >= 0) s.insert(num);
    }
    vector<int> nums(s.begin(), s.end());
    if(nums.empty()){
        cout  << 0 << endl;
    
    }
    sort(nums.begin(), nums.end());
    for (int i = 0; i < s.size(); ++i){
        if (nums[i] != i){
        cout << i<<endl;
        break;
        }
    }    
    return 0;
}
