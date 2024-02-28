#include<iostream>
#include<cmath>
using namespace std;
typedef long long LL;
int main(){
    LL a ;
    cin>>a;
    LL ret = -1;
    if (a > 437893890380859375){
    cout << ret << endl;
    return 0;
    }
    for (LL i = 1; pow(i, i) <= a; ++i){
	if (pow(i, i) == a){
	    ret = i;break;
	}
    }
    cout << ret << endl;

return 0;
  }
