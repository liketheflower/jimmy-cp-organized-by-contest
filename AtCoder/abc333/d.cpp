/*
import collections
def solve():
    n = int(input())
    graph = collections.defaultdict(list)
    for i in range(n-1):
        u, v = [int(c) for c in input().split()]
        graph[u].append(v)
        graph[v].append(u)
    if len(graph[1]) == 0:
        return 0
    if len(graph[1]) == 1:
        return 1
    def cnt_nei(i, curr=1):
        seen = [False]*(n+1)
        seen[curr] = True
        seen[i] = True
        cnt = 1
        stack = [i]
        while stack:
            node = stack.pop()
            seen[node] = True
            for j in graph[node]:
                if not seen[j]:
                    seen[j] = True
                    cnt += 1
                    stack.append(j)
        return cnt
    neighbors = [cnt_nei(v) for v in graph[1]]
    #print(neighbors)
    #print(graph[1])
    return sum(neighbors) - max(neighbors) + 1

print(solve())
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void find_nei(vector<vector<int>> &graph, int i, int p, int & cnt){
    for (auto &j: graph[i]){
	if (j == p)continue;
	cnt ++;
    find_nei(graph, j, i, cnt);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    int u, v;
    vector<vector<int>>graph(n + 10);
    for (int i = 0 ; i < n-1; ++i){
     cin >> u >> v;
     graph[u].push_back(v);
     graph[v].push_back(u);
    }
    int fin_ret = 0;
    vector<int>ret;
    if (graph[1].size() == 0){
	fin_ret = 0;
	cout << fin_ret<<endl;
	return 0;
    }
    if (graph[1].size() == 0){
	fin_ret = n;
	cout << fin_ret<<endl;
	return 0;
    }
    
    for (auto node: graph[1]){
       int this_ret = 0;
       find_nei(graph, node, 1, this_ret);
       //cout << node <<" "<< this_ret << endl;
       ret.push_back(this_ret+1);
    }
    fin_ret = n - (*max_element(ret.begin(), ret.end()));
    cout << fin_ret << endl;
    return 0;
}
