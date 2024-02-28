#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int>&values, vector<int>&weights, int W){
    const int n = values.size();
    int memo[n][1010];
    memset(memo, -1, sizeof memo);
    for (int j = 0; j <= W; ++j){
       int v = values[0]*j;
      int w = weights[0]*j;
	if (w > W)break;
	memo[0][w] = v;
    }
    for (int i = 1; i < n; ++i){
	int this_v = values[i];
	int this_w = weights[i];
	for (int j = 0; j < W; ++j){
	    for (int w = 0; w <=W; ++w){
		if (memo[i-1][w] ==-1)continue;
		int new_w = w + j*this_w;
		if (new_w > W)break;
		memo[i][new_w] = max(memo[i][new_w], memo[i-1][w] + this_v*j);
	    }
	}
    }
    int ret = 0;
    for (int w = 0; w <= W; ++w){
	 ret = max(ret, memo[n-1][w]);
    }
    /*
    for (int i = 0 ; i < n;++i){
	cout << i << "----"<<endl;
	for (int j = 0; j <= W;++j){
	    cout <<memo[i][j]<<" ";
	}
	cout <<endl;
    }
    */
    cout << ret <<endl;
}
int main(){
    int N, W;
    cin  >> N >> W;
    vector<int> values, weights;
    for (int i = 0 ; i < N; ++i){
	int this_w, this_v;
	cin >> this_w >> this_v;
	weights.push_back(this_w);
	values.push_back(this_v);
    }
    solve(values, weights, W);
    return 0;
}
