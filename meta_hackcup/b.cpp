#include<vector>
#include<unordered_set>
#include<set>
#include<iostream>

using namespace std;
typedef pair<int, int> PII;

vector<PII>dirs = {{1, 0},{-1, 0},{0, 1},{0, -1}};

PII get_i_j(int idx, int R, int C){
 int i = idx / C;
 int j = idx % C;
 return make_pair(i, j);
}
int f(int i, int j, int C){
return i*C +j;
}
class UF{
    vector<int> root;
    vector<int> tot;
    vector<unordered_set<int>> nei;
    public:
    UF(int n, vector<string>&grid, int R, int C): root(n), tot(n), nei(n)
    {
        for (int i=0;i<n;++i)root[i] = i;
        for (int i=0;i<n;++i)tot[i] = 1;
        for (int i=0;i<n;++i){
	    auto [ii, jj] = get_i_j(i, R,C);
	    for (auto [di, dj]: dirs){
	    int r = ii + di, c = jj + dj;
	    if (r >= 0 && r < R && c >= 0 && c<C && grid[r][c] == '.')nei[i].insert(f(r, c, C));
	    //cout << i <<"---"<< nei[i].size()<<endl;
	    }
	}
    }
    unordered_set<int> get_nei(int x){return nei[x];}
    void _union(int x, int y)
    {
	int a = find(x);
	int b = find(y);
	//cout << x<<"&&&&"<<a<<endl;
	//cout << y<<b<<endl;
	if (a == b)return;
	tot[a] += tot[b];
	//cout << a <<"^^^^"<<b<<endl;
	for (auto c: nei[b]){
	  //  cout <<"??"<< c <<endl;
	    nei[a].insert(c);
	}
         //root[find(y)] = root[find(x)];
	 root[b] = a;
    }
    int find(int x)
    {
        if (root[x]!=x)root[x] = find(root[x]);
        return root[x];
    }
    int good(int x){
	return nei[x].size();
    }
    int sum(int x){
	return tot[x];
    }
};


void solve(int id){
int R, C;
cin >> R >> C;
vector<string>grid(R);
for (int i = 0; i < R; ++i){
    cin >> grid[i];
}
    int ret = 0;
    UF uf(R*C, grid, R, C);
    for (int i = 0; i < R; ++i){
	for (int j = 0; j < C; ++j){
	    if (grid[i][j] == 'W'){
		// check left
		//cout << "***ij"<<i <<"***"<<j<<endl;
		int r = i -1, c = j;
		if (r >= 0 && grid[r][c] == 'W'){
		  //  cout << "***rc--"<<r <<"***"<<c<<endl;
		    uf._union(f(i, j, C), f(r, c, C));
		}
		// check top
		r = i, c = j - 1;
		if (c >= 0 && grid[r][c] == 'W'){
	          //	cout << "***rc---"<<r <<"***"<<c<<endl;
		    uf._union(f(i, j, C), f(r, c, C));
		}
		//cout << i <<"+++" << j <<"+++" << uf.good(f(i, j, C))<<endl;
	    }
	}
    }
    vector<set<PII>>nums(R*C);
    vector<int>harvest(R*C, 0);
    for (int i = 0; i < R; ++i){
	for (int j = 0; j < C; ++j){
	if (grid[i][j]!='W')continue;
	    auto root = uf.find(f(i, j, C));
	//cout << i <<" "<<j <<" "<< uf.good(root) <<" " <<uf.sum(root)<<endl;
	//for (auto x: uf.get_nei(root))cout <<x<<endl;
	if (uf.good(root) == 0){
            harvest[root] = uf.sum(root);
	}
	if (uf.good(root) == 1){
	    auto neis = uf.get_nei(root);
	    int nei_ = *neis.begin();
	    nums[nei_].insert(make_pair(root, uf.sum(root)));
	    int this_ret = 0;
	    for (auto [x, y]: nums[nei_]){
	    this_ret += y;
	    }
	    ret = max(ret, this_ret);
	}
	}}
for (auto x: harvest)ret += x;
    cout << "Case #"<<id<<": " <<ret<<endl;
}

int main(){
    int T;
    cin >> T;
   for (int i = 1; i <= T; ++i){
	solve(i);
    }
return 0;
  }
