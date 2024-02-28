#include<iostream>
#include<vector>

using namespace std;
typedef pair<int, int> PII;
void solve()
{   int n;
    cin >> n;
    vector<pair<PII, int>> num(n);
    for (int i = 0; i < n; ++i){
	int a, b;
	cin >> a >> b;
	num[i] = make_pair(make_pair(a, b), i);
    }
    sort(num.begin(), num.end(), [ ]( const auto& lhs, const auto& rhs )
{
   auto [ab, i] = lhs;
   auto [ab1, i1] = rhs;
   auto [a, b] = ab;
   auto [a1, b1] = ab1;
    /*
     a/(a+b)
     a1/(a1 + b1)
     
     
     */

   long long left = (long long)a*(a1 + b1);
   long long right = (long long)a1*(a + b);

   if (left > right)return true;
   else if (left == right)return i < i1;
   else return false;
} );
for (auto x: num){
     cout << x.second + 1<<" ";
}
cout << endl;
}
int main(){
  solve();
  return 0;
}
