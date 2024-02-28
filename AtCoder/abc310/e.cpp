#include<iostream>
#include<vector>
#include<queue>
#include<set>
const int INF = INT_MAX;
using namespace std;
typedef pair<int, int> PII;
void dfs(vector<vector<int>> &graph, vector<int>& valid_val, int u,  vector<int>&visited){
    if (valid_val[u] <=0)return;
    visited[u] = 1;
    for (auto v: graph[u]){
	//cout << u <<" u v "<< v<<endl;
	valid_val[v] = max(valid_val[v], valid_val[u] - 1);
	dfs(graph, valid_val, v, visited);
    }
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    vector<int> parents(n, -1);
    vector<int> degree(n, 0);
    for (int i = 1;  i< n;++i){
	cin >> parents[i];
    }
    // build graph
    for (int i = 1; i < n; ++i){
	int p = parents[i];
	p--;
	degree[i]++;
	graph[p].push_back(i);
    }
    vector<int> raw_vals(n, -1);
    vector<int> valid_val(n, -1);
    int u, v;
   for (int i = 0; i < m; ++i)
   {
      cin >> u >> v;
      u--;
      raw_vals[u] = max(raw_vals[u], v);
      valid_val[u] = raw_vals[u];
   }
   vector<int>visited(n, 0);
   for (int i = 0; i < n; ++i){
       if (degree[i] == 0){
	   dfs(graph, valid_val, i, visited);
       }
   }
   for (int i = 0; i < n; ++i){
       if (visited[i] == 0){
	   dfs(graph, valid_val, i, visited);
       }
   }
   int ret = 0;
   for (int i = 0; i < n; ++i){
       ret += valid_val[i] >= 0;
       //cout <<i << " "<<valid_val[i] <<endl;
   }
    
   cout << ret <<endl;
  return 0;
   
}


