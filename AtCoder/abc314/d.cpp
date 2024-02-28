#include<iostream>
#include<vector>
#include<set>
#include<unordered_set>
#include <cctype>
#include <algorithm>
using namespace std;
int KEEP = 1, TO_L = 2, TO_U = 3;
int main(){
   int n;cin>>n;
   string s; cin >> s;
   int Q; cin >> Q;
   vector<int>updates(n, 0);
   vector<int> patterns(Q + 1, 0);
   int a, b;
   char c;
   for (int i = 0; i < Q; ++i ){
       cin >> a >> b;
       cin >> c;
       patterns[i] = a;
       if (a == 1){
	   updates[b-1] = i;
	   s[b-1] = c;
       } 
   }
   int BE_U = 0, BE_L = 1;
   int U_LOC = 0, L_LOC = 1;
   vector<vector<int>> dp(Q + 1, vector<int>(2, 0));
   for (int i = 0; i <=Q;++i){
       dp[i][U_LOC] = BE_U;
       dp[i][L_LOC] = BE_L;

   }
   for (int i = Q -1; i >= 0; --i){
       if (patterns[i] == KEEP){
	   dp[i] = dp[i+1];
       } else if (patterns[i] == TO_L){
	   dp[i][L_LOC] = dp[i+1][L_LOC];
	   dp[i][U_LOC] = dp[i+1][L_LOC];
       } else /*TO_U*/{
	   dp[i][U_LOC] = dp[i+1][U_LOC];
	   dp[i][L_LOC] = dp[i+1][U_LOC];
       }
   }
   for (int i = 0; i < n; ++i){
       int idx = updates[i];
       if (s[i] >= 'a' && s[i] <= 'z'){
	   if (dp[idx][L_LOC] == BE_U){
	       s[i] = toupper(s[i]); 
	   }
       } else {
	   if (dp[idx][U_LOC] == BE_L){
	       s[i] = tolower(s[i]); 
	   }
       }
   }
   cout << s << endl;

return 0;
  }
