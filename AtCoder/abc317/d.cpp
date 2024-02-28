#include<iostream>
#include<vector>
#include<set>
#include<cstring>
#include<unordered_set>
#include <algorithm>
typedef long long LL;
LL memo[102][100010];
const LL INF = 0x3f3f3f3f3f3f3f3f;
using namespace std;
void dp(vector<int>&a, vector<int>&seats,int tot, int n){
    for (int i = 0; i < n; ++i){
	int this_vote = a[i];
	for (int j = 0; j <= tot;++j){
	    if (memo[i][j]==INF)continue;
            int this_seat = seats[i];
	    // take this
	    memo[i+1][j + this_seat] = min(memo[i+1][j + this_seat],  memo[i][j] + this_vote);
	    // not take this
	   if(this_vote != 0) memo[i+1][j] = min(memo[i+1][j],  memo[i][j]);

	}
    }
}
int main(){
   int n;cin>>n;
   memset(memo, 0x3f, sizeof memo);
   memo[0][0] = 0;
   vector<int>votes(n, 0);
   vector<int>seats(n, 0);
   int tot = 0;
   for (int i = 0; i <n; ++i){
       int a, b, c;
       cin >> a >>b>>c;
       tot += c;
       seats[i] = c;
       int needs = 1 + (a+ b) / 2;
       if (a < needs){
	   votes[i] = needs - a;
       }
   }
   LL ret = INF;
    dp(votes, seats, tot, n);
   int needed_seats = (tot / 2) + 1;
   for (int s = needed_seats; s <= tot; ++s){
       ret = min(ret, memo[n][s]);
   }
   cout << ret << endl;

return 0;
  }
