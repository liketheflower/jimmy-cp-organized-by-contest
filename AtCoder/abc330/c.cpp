#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
typedef long long LL;
using namespace std;
int main(){
    LL n;
    cin>>n;
    int x = sqrt(double(n));
    int jjjj = sqrt(-1);
    cout << "jjjj"<<jjjj <<endl;
    vector<LL> candidates;
    for (int i = 0; i <=x + 20; ++i){
	LL remain = n - LL(i)*LL(i);
        if (remain <= 0){
	    candidates.push_back(-remain);
	    continue;
	}
        int y = sqrt(double(remain));
	for (int d = -3; d <=3;++d){
	    int j = y + d;
	    j = max(0, j);
	    LL this_ret = abs(remain- LL(j)*LL(j));
	    candidates.push_back(this_ret);
	}
    }
    auto ret = *min_element(candidates.begin(), candidates.end());
    cout << ret << endl;
return 0;
  }
