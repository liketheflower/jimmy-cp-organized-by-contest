#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3f;
void backtrack( vector<vector<int>> graph, int i, vector<vector<LL>>&cost, LL& ret, LL curr_ret, vector<int>&seen,int cnt,  int n, LL k){
    cout << i <<" " << cnt<<endl;
    if (cnt == n - 1){
	cout << "curr ret" << curr_ret << endl;
	cout << "curr ret %k" << curr_ret % k << endl;

	ret = min(ret, curr_ret % k);
	return;
    }
    seen[i] = 1;
    for (auto v: graph[i]){
	if (seen[v])continue;
        seen[v] = 1;
	curr_ret += cost[i][v];
	cnt ++;
	backtrack(graph, v, cost, ret, curr_ret, seen,cnt,  n, k);
	curr_ret -= cost[i][v];
	cnt --;
	seen[v] = 0;
    }
}
int main(){
    int n, m;
    LL  k;
    cin>>n >> m;
    cin >> k;
    vector<vector<LL>>cost( n + 10, vector<LL>( n + 10, -1));
    int u, v;
    LL c;
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; ++i){
     cin  >> u >> v;
     cin >> c;
     //cout <<u  << v << c<<endl;
     cost[u][v] = c;
     cost[v][u] = c;
     cout <<u  << v << c<<endl;
     graph[u].push_back(v);
     graph[v].push_back(u);
    }
    LL ret = INF;
    for (int i =1; i<=n;++i){
	vector<int>seen(n+1, 0);
	seen[i] = 1;
	int cnt = 0;
	LL curr_ret = 0;
        backtrack(graph, i, cost, ret, curr_ret, seen,cnt,  n, k);
    }
    cout << ret << endl;
return 0;
  }
