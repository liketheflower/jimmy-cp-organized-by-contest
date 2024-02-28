#include <cmath>
#include<iostream>
using namespace std;
int main(){
    int a, b;
    cin >> a>>b;
    long long ret = pow(a, b) + pow(b, a);
    cout << ret <<endl;
return 0;
  }
