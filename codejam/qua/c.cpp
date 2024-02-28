#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void solve(vector<int>&a){
   int ret = 0;
   sort(a.begin(), a.end());
   int expect = 1;
   for (int i = 0; i < (int)a.size(); ++i){
       if (a[i] >= expect){
          ret++;
          expect++;
       }
   }
   cout << ret << endl;
   return;
}
int main(){
   int T; cin >> T;
   for (int i = 1; i <= T; ++i){
      cout<<"Case #" << i << ": ";
      int n; cin >> n;
      vector<int>a;
      for (int i = 0; i < n; ++i){
        int num; cin >> num; 
        a.push_back(num);
      }
      solve(a);
   }
   return 0;
}
