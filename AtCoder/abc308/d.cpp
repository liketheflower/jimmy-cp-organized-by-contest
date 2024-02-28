#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
typedef pair<int, int> PII;
void solve()
{   int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i){
	cin >> nums[i] ;
    }
    string s;
    cin >> s;
    vector<vector<int>> M(3), E(3), X(3);
    for (int i = 0; i < n;++i){
	if (s[i] == 'M'){
	    M[nums[i]].push_back(i);
	} else if(s[i] == 'E'){
	   E[nums[i]].push_back(i);
	}else{
	   X[nums[i]].push_back(i);
	}
    }
    int ret = 0;
    for (int i = 0; i < 3; ++i){
    vector<int>curr(4, 0);
	curr[i] = 1;
	for (auto x: M[i])
	{
	    for (int j = 0; j < 3; ++j)
	    {
                vector<int>new_curr;
		new_curr = curr;
		new_curr[j] = 1;
		auto it =upper_bound(E[j].begin(), E[j].end(), x) - E[j].begin();
		for (auto itt = it; itt != int(E[j].size()); itt++)
		{
	            for (int k = 0; k < 3; ++k)
		    {
			vector<int>new_new_curr;
			new_new_curr = new_curr;
			new_new_curr[k] = 1;
		       int new_new_curr_val = 0;
		       auto it2 = upper_bound(X[k].begin(), X[k].end(), E[j][itt]);
		       for (int iii = 0; iii <4; ++iii){
			   if (!new_new_curr[iii]){
			       new_new_curr_val = iii;
			       break;
			   }
		       }
		      // cout << new_new_curr_val << "----"<<endl;
		       ret += (X[k].end() - it2)*new_new_curr_val;
		      // cout << ret << "-++-" << i <<" " << j <<" " << k <<endl;
		      // cout <<endl;
		    }
		}
	    }
	}
    }
    cout << ret << endl;
}

int main(){
  solve();
  return 0;
}
