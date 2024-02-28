#include<iostream>
#include<vector>
#include <bitset>
using namespace std;
const int N = 2e5+2;
int main(){
    int n, m;
    cin>>n >> m;
    int color;
    n = N;
    vector<bitset<N>> st(n + 1);
    for (int i = 1; i <=n; ++i){
        cin >> color;
	st[i].set(color, true);
    }
    int a, b;
    for (int i = 0; i < m; ++i){
	cin >> a >> b;
	st[b] |= st[a];
	st[a].reset();
	cout << st[b].count()<<endl;
    }
    return 0;
}
