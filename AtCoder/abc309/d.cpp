#include<iostream>
#include<vector>
#include<queue>
#include<set>
const int INF = INT_MAX;
using namespace std;
typedef pair<int, int> PII;
int dijkstra(int n, vector<vector<PII>> &graph, int src)
{  // init distance from src to a node
   vector<int> dis(n, INF); dis[src] = 0;
   // python syntex: dis = [float("inf")]*n
   priority_queue<PII, vector<PII>, greater<PII>> pq;
   // init the unexplored nodes
   for (int i = 0; i < n; ++i) 
   {
      if (i == src) pq.emplace(0, i);
      else pq.emplace(INF, i);
   }
   while (!pq.empty())
   {
     // pick up the shorted node from unexplored nodes
     auto [cost, u] = pq.top(); pq.pop();
     // soft delection here
     if (cost > dis[u]) continue;
     // explore neighbors
     for (auto &[v, weight]: graph[u])
     {
        int new_cost = cost + weight;
        // find a shorter path:
        if (new_cost < dis[v])
        {
           // update
           // can not the old one now
           // pq.erase(pq.find({dis[v], v}));
           // update the dis[v] to the new one
           dis[v] = new_cost;
           // put the new one into the priority queue
           pq.emplace(dis[v], v);
        }
     }
   }
   int max_dis = 0;
   for (int i = 0; i < n; ++i)
   {
       max_dis = max(max_dis, dis[i]);
   }
   return max_dis;
}


int main(){
    int n1, n2, m;
    cin >> n1 >> n2 >> m;
    int u, v, weight;
    weight = 1;
    vector<vector<PII>> graph1(n1), graph2(n2);
   for (int i = 0; i < m; ++i)
   {
      cin >> u >> v;
      if (max(u, v) <= n1){
      graph1[u-1].emplace_back(v-1, weight);
      graph1[v-1].emplace_back(u-1, weight);
      } else {
      graph2[u-n1-1].emplace_back(v-n1-1, weight);
      graph2[v-n1-1].emplace_back(u-n1-1, weight);
      }
   }
   int d1 = dijkstra(n1, graph1, 0);
   int d2 = dijkstra(n2, graph2, n2-1);
   cout << d1 + d2 + 1<<endl;
  return 0;
   
}


