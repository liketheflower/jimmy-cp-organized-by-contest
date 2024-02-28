#include<vector>
#include<iostream>
using namespace std;
typedef long long LL;
bool good(int offset, int hour){
    int new_hour = (offset + hour) % 24;
    return new_hour >= 9 && new_hour < 18; 
}
int main(){
    LL ret=0;
    int n;
    cin >> n;
    vector<int> p(n, 0);
    vector<int> clock(n, 0);
    for (int i = 0; i < n; ++i){
	cin >> p[i] >> clock[i];
    }
    for (int hour = 0; hour < 24; ++hour){
	LL this_ret = 0;
	for (int j = 0; j  < n; ++j){
	    if (good(clock[j], hour)){
		this_ret += p[j];
	    }
	}
	ret = max(this_ret, ret);
//	cout << hour << " "<<this_ret <<endl;
    }
    cout << ret <<endl;
return 0;
  }
