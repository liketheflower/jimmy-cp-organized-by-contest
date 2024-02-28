#include<iostream>
using namespace std;
int main(){
    int n, x;
    cin>>n >> x;
    int ret = 0;
    for (int i = 0; i < n; ++i){
    int this_num;
    cin >> this_num;
    if (this_num <= x)ret += this_num;
    }
    
    cout << ret << endl;
return 0;
  }
