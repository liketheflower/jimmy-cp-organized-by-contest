#include<iostream>
#include <utility>
#include<vector>
using namespace std;
typedef pair<int, int> PII;
vector<vector<int>> get_input(int &sum)
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>>a(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i){
	string s;
	cin >> s;
	for (int j = 0 ; j < m; ++j)
	{
	    if(s[j] == '#')
	    {
		a[i][j] = 1;
		sum += 1;
	    }
	}
    }
    return a;
}



bool check(vector<vector<int>> aa,vector<vector<int>>& b,vector<vector<int>>& x, int ii, int jj, int sum_a, int sum_b,int sum_x){
    const int n = aa.size(),nb= b.size(), mb = b[0].size(), nx = x.size(), mx = x[0].size();
    int sum_ab = 0, found_x = 0;
    for (int i = ii;  i < ii + nb; ++i)
    {  
    for (int j = jj; j < jj + mb; ++j)
	{
           aa[i][j] += b[i-ii][j-jj];
        }
    }
    bool ok = true;
    for (int i = 0; i + nx < n; ++i)
    {
	for (int j = 0; j + mx < n;++j){
	    sum_ab = 0;
	    found_x = 0;
	    ok = true;
	    for (int i_ = i; i_ < i + nx; ++i_)
	    {
		for (int j_ = j; j_ < j + mx; ++j_)
		{
		    if (aa[i_][j_] == 0 && x[i_ - i][j_ - j] ==0)continue;
		    else if (aa[i_][j_] == 0 || x[i_ - i][j_ - j] ==0){
			ok = false;
			break;
		    } else {
			sum_ab += aa[i_][j_];
			found_x ++;
		    }
		}
		if (!ok)break;
	    }
	    if (!ok)continue;
	    if (sum_ab == sum_a + sum_b &&found_x ==sum_x){
                return true;
	    }
	}
    }
    return false;
}
void solve( vector<vector<int>>&a, vector<vector<int>>& b,  vector<vector<int>>&x,int sum_a, int sum_b,int sum_x){
if (sum_a > sum_x || sum_b > sum_x)
{
    cout << "No";
    return;
}
int na = a.size(), ma = a[0].size(), nb = b.size(), mb = b[0].size(), nx = x.size(), mx = x[0].size();
int n = max({na, ma, nb, mb, nx, mx});
vector<vector<int>> aa(3*n, vector<int>(3*n, 0));
// put a in the center and traverse b;
for (int i = n; i < n + na;i++)
{
    for (int j = n; j < n + ma; ++j){
	aa[i][j] = a[i-n][j-n];
    }
}
for (int i = 0; i + nb <= 3*n; ++i)
{
    for (int j = 0; j + mb <= 3*n; ++j)
	if (check(aa, b, x, i, j, sum_a, sum_b, sum_x)){
	    cout << "Yes"<<endl;
	    return;
	}
}
cout << "No"<<endl;
    return;

}
int main(){
    int sum_a = 0, sum_b= 0, sum_x=0;
  auto a = get_input(sum_a);
  auto b = get_input(sum_b);
  auto x = get_input(sum_x);
  solve(a, b, x, sum_a, sum_b, sum_x);
  return 0;
}
