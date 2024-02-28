#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>a(n, 0);
    for (int i = 0; i < n; ++i){cin>>a[i];}
    sort(a.begin(), a.end());
    int max_val = a.back();
    while (!a.empty() && a.back()==max_val)a.pop_back();
    int ret = -1;
    if (!a.empty())ret=a.back();
    
    cout << ret << endl;
return 0;
  }
