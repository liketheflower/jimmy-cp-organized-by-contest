#include<iostream>
#include<vector>
using namespace std;

int main()
{
  int n, a, x, y;
  cin >> n >> a >> x >> y;
  long long ret = (long long)n*x;
  if(n > a) ret -= (long long)(x - y)*(n - a);
  cout << ret << endl;
  return 0;
}
