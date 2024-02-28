#include<iostream>
#include<map>
#include<unordered_map>
#include<vector>
#include<set>
using namespace std;
int main(){
    int n, m;
    cin>>n >> m;
    vector<int> vote(m, 0);
    unordered_map<int, int>cnt;
    map<int, set<int>> vot_id;
    vector<int>ret(m, 0);
    for (int i = 0; i < m; ++i){
	cin >> vote[i];
	int old_vote = cnt[vote[i]];
	int new_vote = old_vote + 1;
	cnt[vote[i]] = new_vote;
        if (old_vote!=0){
	    vot_id[old_vote].erase(vote[i]);
	}
	vot_id[new_vote].insert(vote[i]);
	ret[i] = *(vot_id.rbegin() -> second).begin();
    }
   for (auto c: ret){
    cout << c << endl;
   } 
return 0;
  }
