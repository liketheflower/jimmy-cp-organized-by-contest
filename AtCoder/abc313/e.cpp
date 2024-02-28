#include<iostream>
#include<vector>
#include<cstring>

using namespace std;
typedef pair<int, int> PII;
int nums[3010][3010];
int presum[3010][3010];
int main(){
    int n, m, K; cin  >> n >> m >> K;
    memset(nums, 0, sizeof nums);
    memset(presum, 0, sizeof presum);
    for (int i = 0; i < K; ++i){
	int a, b; cin >> a >> b;
	a--; b--;
	nums[a][b] = 1;
    }
    for (int i = 1; i <=n;++i){
	for (int j = 1; j <= m; ++j){
	presum[i][j] = presum[i-1][j] + presum[i][j-1] - presum[i-1][j-1] + nums[i-1][j-1];
	}
    }
    int ret = 0;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
	    for (int k = i; k < n; ++k){
		for (int l = j; l < m; ++l)
		    if (presum[k+1][l+1] - presum[k+1][j] - presum[i][l+1] + presum[i][j] == 0){
			ret++;
		    } else {
			break;
		    }
	    }
	}
    }
    cout << ret << endl;
return 0;
  }
