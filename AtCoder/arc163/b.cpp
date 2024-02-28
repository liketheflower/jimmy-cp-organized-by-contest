#include<iostream>
#include<vector>
using namespace std;
bool is_p(string s){
    int l = 0, r = s.size() - 1;
    while (l < r){
	if (s[l++] != s[r--])return false;
    }
    return true;
}
void solve(vector<string>&ss)
{
    const int n = ss.size();
    for (int i = 0; i < n - 1; ++i)
    {
	for (int j = i + 1; j < n; ++j)
	{
	    if (is_p(ss[i] + ss[j]) || is_p(ss[j] + ss[i])){
		cout << "Yes" << endl;
		return;
	    }
	}
    }
    cout << "No" <<endl;
}
int main(){
  int n;
  cin >> n;
  vector<string> ss;
  for (int i = 0; i < n; ++i)
  {
      string s;
      cin >> s;
      ss.push_back(s);
  }
  solve(ss);
  return 0;
}
