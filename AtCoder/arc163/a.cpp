#include<iostream>
using namespace std;
bool check(string s, int i){
    int l = 0, r = i + 1;
    while (true){
	if (s[l] < s[r])return true;
	else if (s[l] > s[r])return false;
	l ++;
	r ++;
	if (l==i+1 && r == (int)s.size())return false;
	if (l == i +1)return true;
	if (r == (int)s.size())return false;
    }
    return false;

}
void solve(){
    int n;
    string s;
    cin >> n;
    cin >> s;
    bool good=false;
    for (int i =0; i < n-1; ++i ){
	if (check(s, i)){
	    good = true;
	    break;
	}
    }
    if (good){cout <<"Yes"<<endl;}
    else{cout <<"No"<<endl;}

}
int main(){
  int T;
  cin >> T;
  while (T--){
      solve();
  }
  return 0;
}
