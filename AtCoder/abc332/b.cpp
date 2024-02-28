#include<iostream>
typedef long long LL;
using namespace std;
int main(){
    int N, G, M;
    cin >> N >> G >> M;
    int g = 0;
    int m = 0;
    for (int i = 0; i < N; ++i){
        if (g==G){
	    g = 0;
	} else if (m == 0) {
	    m = M;
	}else{
	    int old_m = m;
	    m = (m <= (G-g))?0: (m - (G-g));
	    g += old_m;
	    g = min(g, G);
	}

    } 
    cout << g <<" " << m << endl;
return 0;
  }
