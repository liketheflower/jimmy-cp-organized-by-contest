#include <cmath>
#include<iostream>
using namespace std;
typedef long long LL;
int main(){
    LL n;
    cin >> n;
    LL y = 1;
    while (y <= n){
      LL x = 1;
     while (x <= n){
	 if (n == x*y){
	     cout <<"Yes"<<endl;
	     return 0;
	 }
	 x <<= 1;
     }
     y *= 3;
    }
    cout << "No" <<endl;
return 0;
  }
