#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s;
    cin >> s;
    vector<int> cnt(26, 0);
    s.push_back('0');
    int this_cnt = 1;
    char curr = s[0];
    for (int i = 1; i <= n; ++i){
	if (curr!=s[i]){
	    cnt[curr-'a'] = max(cnt[curr-'a'], this_cnt);
	    curr = s[i];
	    this_cnt = 1;
	} else {
	    this_cnt++;
	}
    }
   long long ret = 0;
   for (auto c: cnt){
       if (c == 0)continue;
       ret += c;
   } 
    cout << ret << endl;
return 0;
  }
