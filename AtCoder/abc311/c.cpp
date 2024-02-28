#include<iostream>
#include<vector>
using namespace std;
#include<unordered_map>
int main(){
    int n; cin  >> n;
    vector<int> next(n);
    for (int i = 0; i <n;++i){
	cin >> next[i];
	next[i]--;
    }
    vector<int>seen(n, 0);
    unordered_map<int, int> parents;
    vector<int>ret;
    for (int i = 0; i <n;++i){
	if (seen[i])continue;
	seen[i] = 1;
	bool found = false;
	int curr = i;
	int node = -1;
	while (true){
	    int j = next[curr];
	    parents[j] = curr;
	    curr = j;
	    if (seen[j]){
		found = true;
		node = j;
		break;
	    }
	    seen[curr] = 1;
	}
	if (found){
	    int this_curr = node;
	    int p = -1;
	    while (p != node){
		p = parents[this_curr];
		ret.push_back(p);
		this_curr = p;
	    }
	    break;
	}
    }
    cout << ret.size() << endl;
    reverse(ret.begin(), ret.end());
    for (auto x:ret)cout << x + 1 <<" ";
    cout << endl;
return 0;
  }
