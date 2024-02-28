#include<iostream>
#include<vector>
using namespace std;
int main(){
   int n;cin>>n;
   vector<int>a(n);
   for (int i =0; i <n;++i)cin>>a[i];
   int first = a[0];
   int m = *max_element(a.begin() + 1, a.end());
   int ret = max(0, m - first +1);
   cout << ret <<endl;
return 0;
  }
