#include<iostream>
#include<vector>
using namespace std;
void solve(vector<int>a, vector<int>b, vector<int>c){
   int curr = 0;
   const int target = 1e6;
   vector<int>ret(4, 0);
   for (int i = 0; i < 4; ++i){
      int this_min = min({a[i], b[i], c[i]});
      this_min = min(target-curr, this_min);
      curr += this_min;
      ret[i] = this_min;
   }
   if (curr == target){
    for (int i = 0; i < 3; ++i)cout<<ret[i]<<" ";
    cout<<ret[3]<<endl;
   } else cout <<"IMPOSSIBLE"<<endl;
}
int main(){
   int T; cin >> T;
   for (int i = 1; i <= T; ++i){
      cout<<"Case #" << i << ": ";
      vector<int> a(4, 0), b(4,0), c(4,0);
      for (int i = 0; i < 3; ++i){
      for (int j = 0; j < 4; ++j){
        if (i == 0) cin >> a[j];
        if (i == 1) cin >> b[j];
        if (i == 2) cin >> c[j];
      }
      }
      solve(a, b, c);
   }
   return 0;
}
