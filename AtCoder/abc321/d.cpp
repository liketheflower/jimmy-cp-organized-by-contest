#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
typedef long long LL;
const LL INF = 0x3f3f3f3f;
using namespace std;
typedef pair<LL, LL> PII;
void dfs(LL i, vector<LL>&seen, vector<vector<LL>>& ret,  unordered_map<LL, vector<LL>>& graph, LL x, LL y, map<PII, PII>& offset){
    if (seen[i])return;
    seen[i] = 1;
    ret[i][0] = x;
    ret[i][1] = y;
    //cout << "i: "<<i <<" "<<ret[i][0]<<endl;
    for (auto j: graph[i]){
      //  cout << "j: "<<j <<endl;
	auto key = make_pair(i, j);
	auto [dx, dy] = offset[key];
	LL new_x = x + dx, new_y = y + dy;
	dfs(j, seen, ret, graph, new_x, new_y, offset);
    }
}
int main(){
    LL n, m;
    cin >> n >> m;
    unordered_map<LL, vector<LL>> graph;
    //set<PII> seen;
    map<PII, PII> offset;
    for (LL i = 0; i <m;++i){
	LL a, b, x, y;
	cin >> a >> b >> x >> y;
	a--; b--;
	//cout <<a<<b<<endl;
	    auto key1 = make_pair(a, b);
	    offset[key1] = make_pair(x, y);
	    auto key2 = make_pair(b, a);
	    offset[key2] = make_pair(-x, -y);
	    graph[a].push_back(b);
	    graph[b].push_back(a);
    }
    vector<vector<LL>> ret(n, vector<LL>(2, -INF)); 
    vector<LL>seen(n, 0);
    //ret[0][0] =0;
    //ret[0][1] =0;
   //seen[0] = 1;
    dfs(0, seen, ret, graph, 0, 0, offset);
    for (LL i = 0; i < n; ++i){
	  //  cout << ret[i][0] <<" "<<ret[i][1]<<endl;
	if (ret[i][0] == -INF &&  ret[i][1 == -INF]){
	    cout << "undecidable"<<endl;
	} else {
	    cout << ret[i][0] <<" "<<ret[i][1]<<endl;
	}
    }
return 0;
  }
