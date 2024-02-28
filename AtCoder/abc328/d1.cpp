#include<iostream>
#include<vector>
using namespace std;

static auto speedup = []() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    return NULL;
}();
class Solution {
public:
     
    vector<vector<int>>v;
    vector<int>vis;
    bool dfs(int cur,int f)
    {
        if(vis[cur]==f) return 1;
        if(vis[cur]==(f^1)) return 0;
        // int x=1;
        vis[cur]=f;
        for(auto it:v[cur])
        {
            if(!dfs(it,f^1)) return 0;
        }
        return 1;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dis) {
        // v.clear();
        v.resize(n+2);
        vis.clear();
        vis.assign(n+1,-1);
        for(int i=0;i<dis.size();i++)
        {
            v[dis[i][0]].push_back(dis[i][1]);
            v[dis[i][1]].push_back(dis[i][0]);
        }
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==-1)
            {
                if(!dfs(i,1)) return 0; 
            }
        }
        return 1;

    }
};


int main(){
 int n, m;
 cin >> n >>m;
 vector<int>a(m, 0);
 
 vector<int>b(m, 0);
 for (int i = 0; i < m; ++i)cin >> a[i];
 for (int i = 0; i < m; ++i)cin >> b[i];
 vector<vector<int>> dislikes;
 int max_n = 0;
 for (int i = 0; i < m ; ++i){
     max_n = max(max_n, a[i]);
     max_n = max(max_n, b[i]);
     dislikes.push_back({a[i], b[i]});
 }
 Solution s;
 bool good = s.possibleBipartition(max_n, dislikes);
if (good)cout << "Yes"<<endl;
else cout << "No"<<endl;
return 0;
}
