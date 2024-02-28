#include<iostream>
using namespace std;
typedef long long LL;
int main(){
    int N, S, M , L;
    cin >> N >> S >> M >> L;
    LL ret = 0x3f3f3f3f3f3f3f3f;
    for (int a = 0; a * 6 - 13 <=N; ++a){
    for(int b = 0; b*8  - 13<= N; ++b){
	for (int c = 0 ; c * 12  - 13 <= N; ++ c){
	    int amount = a*6 + b * 8 + c*12;
	    if (amount >= N){
		LL this_ret = (LL)a*S +(LL) b*M + (LL)c*L;
		//cout << this_ret << endl;
		ret = min(ret, this_ret);
	    }
	}
    }
    }
    cout  << ret << endl;
return 0;
  }
