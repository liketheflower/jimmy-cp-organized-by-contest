#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
typedef pair<int, int> PII;

const int UNVISITED = -1, COLOR1 = 0;

class Solution {
public:
    vector<vector<int>> AL;
    vector<int> colors;
    bool isBipartition(int node, int color) {
        if (colors[node] == color)return true;
	if (colors[node] == 1 - color)return false;
        colors[node] = color;
	cout <<"node --" <<node<< " "<<colors[node] << endl;
	for (auto &neighbor : AL[node]) {
	    cout <<"nei"<<neighbor<<endl;
	    if (!isBipartition(neighbor, 1 - color))return false;
        }
        return true;
    }
    bool possibleBipartition(int N, vector<PII>& dislikes) {
        // set colors, and the default one is UNVISITED
        vector<int> colors(N+1, UNVISITED);
        // build the graph
        vector<vector<int>> AL(N+1);
        for (auto [u, v]: dislikes) {
            AL[u].push_back(v);
            AL[v].push_back(u);
        }
        this->colors = colors;
        this->AL = AL;
        // check whehter each subgraph is bipartition
        for (int i = 0; i <= N; ++i) {
	    cout <<"iiiii "<< i <<" color" << colors[i] <<endl;
            if (this->colors[i] == UNVISITED) {
		cout << i << " " << (isBipartition(i, COLOR1)) << endl;
                if (!isBipartition(i, COLOR1)) return false;
            }
        }
        return true;


    }
};

int main(){

   ios_base::sync_with_stdio(false);                                                   
    cout.tie(NULL);                                                                     
    cin.tie(NULL);     
    int n, m;
 cin >> n >>m;
 vector<int>a(m, 0);
 
 vector<int>b(m, 0);
 for (int i = 0; i < m; ++i)cin >> a[i];
 for (int i = 0; i < m; ++i)cin >> b[i];
 vector<PII> dislikes;
 dislikes.reserve(n);
 int max_n = 0;
 for (int i = 0; i < m ; ++i){
     max_n = max(max_n, a[i]);
     max_n = max(max_n, b[i]);
     dislikes.emplace_back(a[i], b[i]);
 }
 Solution s;
 bool good = s.possibleBipartition(max_n, dislikes);
if (good)cout << "Yes"<<endl;
else cout << "No"<<endl;
return 0;
}
