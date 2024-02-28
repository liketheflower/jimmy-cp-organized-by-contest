#include<iostream>
#include<vector>
using namespace std;
int main(){
   int n;cin>>n;
   string p = "3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";
   cout << p.substr(0, n + 2)<<endl;
return 0;
  }
