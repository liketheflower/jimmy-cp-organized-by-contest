#include<iostream>
#include<vector>
#include<set>
#include<unordered_set>
#include <algorithm>
using namespace std;
typedef pair<int, int> PII;
int main(){
   int n, m;cin>>n>>m;
   vector<string> colors(m);
   vector<int>global_idxes;
   string s; cin >> s;
   for (int i = 0; i <n; ++i){
       int idx; cin  >> idx;
       colors[idx-1].push_back(s[i]);
       global_idxes.push_back(idx - 1);
   }
   for (int i = 0; i <m;++i){
       string this_s = colors[i];
       if (this_s.size() == 1)continue;
       colors[i] = "";
       colors[i].push_back(this_s.back());
       this_s.pop_back();
       colors[i] += this_s;
   }
   vector<int> idxes(m, 0);
   string ret;
   for (int i = 0; i < n; ++i){
       int this_idx = global_idxes[i];
       ret.push_back(colors[this_idx][idxes[this_idx]]);
       idxes[this_idx]++;
   }
   cout << ret << endl;

return 0;
  }
