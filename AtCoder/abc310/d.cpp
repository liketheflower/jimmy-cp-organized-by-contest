#include<iostream>
#include<vector>
#include<set>
using namespace std;
void dfs(int mask, int curr_mask,int idx, int T,int N, vector<vector<int>> &not_match,set<vector<int>>& ss, vector<int>group){
    int new_mask = mask | curr_mask;
    cout << idx << endl;
    if (idx == T - 1 && curr_mask && (__builtin_popcount(new_mask) == N)){
	group.push_back(curr_mask);
//cout << group.size() << endl;
	sort(group.begin(), group.end());
	ss.insert(group);
	return;
    }
    if (N == __builtin_popcount(new_mask) ){return;
    }
    // have a new group
    if (curr_mask){
	int new_curr_mask = 0;
	vector<int>new_group;
	new_group = group;
	new_group.push_back(curr_mask);
	dfs(new_mask, new_curr_mask, idx + 1, T, N,not_match, ss, new_group); 
    }
    // do not have a new group
    for (int i = 0; i < N; ++i){
	if ((1 << i) & new_mask)continue;
       bool match = true;
	for (auto j : not_match[i]){
	    if ((1<<j) & curr_mask){
		match = false;
		break;
	    }
	}
	if (!match)continue;
	int new_curr_mask = curr_mask;
	new_curr_mask |= (1 << i);
	dfs(mask, new_curr_mask, idx, T, N,not_match, ss, group);
    }
}
int main(){
  int N, T, M;cin >> N >> T >> M;
  set<vector<int>> ss;
  vector<vector<int>> not_match(20);
  for (int i = 0; i < M; ++i){
      int a, b;cin >> a >> b;
      not_match[a].push_back(b);
      not_match[b].push_back(a);
  }
  int mask = 0, curr_mask = 0;
  int i = 0;
  vector<int> group;
  dfs(mask, curr_mask, i, T, N,not_match, ss, group);
  cout << ss.size() << endl;

return 0;
  }
