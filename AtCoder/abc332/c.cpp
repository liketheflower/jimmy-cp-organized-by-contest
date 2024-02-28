#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> PII;
typedef long long LL;
bool good(string& s, int mid, int M){
    int plain = M;
    int logo =	mid;
    
    for (auto c:s){
	if (c == '0'){
	    plain = M;
	    logo = mid;
	} else if (c == '1'){
	    if (plain == 0 && logo == 0)return false;
	    if (plain)plain--;
	    else {
		logo --;
	    }
	} else {
	    logo --;
	    if (logo < 0)return false;
	}
    }
    return plain >=0 && logo >= 0;
}
int main(){
    int N, M;
    string s;
    cin>> N >> M >> s;
    int lo = 0;
    int hi = N;
    while (lo < hi){
        int mid = (lo + hi) / 2;
	if (good(s, mid, M)){
	    hi = mid;
	} else {
	    lo = mid + 1;
	}
    }
    cout << lo << endl;
return 0;
  }
