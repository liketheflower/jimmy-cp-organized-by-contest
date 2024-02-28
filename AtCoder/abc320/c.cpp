#include<iostream>
#include <algorithm>  
#include<vector>
using namespace std;
const int INF = 0x3f3f3f3f;
int get_ret(vector<int>a, int m, int begin_t){
    int ret = INF;
    for (auto x:a){
    for (int t =begin_t; t <= begin_t + 2*m;++t){
	if ((t%m)+ 1 == x){
	    ret = min(ret, t);
	    break;
	}
    }
    }
    //cout << "ret :  "<<ret<<endl;
    return ret;
}
int main(){
    int m;
    cin >> m;
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    vector<vector<int>> a1(10);
    vector<vector<int>> a2(10);
    vector<vector<int>> a3(10);
    int ret = INF;
    for (int i = 0; i < 10; ++i){
	for (int j = 0; j < m; ++j){
	    if (s1[j] == '0' + i){a1[i].push_back(j + 1);}
	    if (s2[j] == '0' + i){a2[i].push_back(j + 1);}
	    if (s3[j] == '0' + i){a3[i].push_back(j + 1);}
	}
    }
    vector<int>idx={0, 1, 2};
    for (int i = 0; i < 10; ++i){
	if (a1[i].size() == 0 || a2[i].size() == 0 || a3[i].size()==0)continue;
    vector<vector<int>> aa;
    aa.push_back(a1[i]);
    aa.push_back(a2[i]);
    aa.push_back(a3[i]);
        do {
	    int k0 = idx[0], k1= idx[1], k2 = idx[2];
	int this_ret = -1;
	    this_ret = get_ret(aa[k0], m, this_ret + 1);
	    this_ret = get_ret(aa[k1], m, this_ret + 1);
	    this_ret = get_ret(aa[k2], m, this_ret + 1) ;
	ret = min(ret, this_ret);
       // cout << i << endl;
	//cout << this_ret << endl;
  } while (next_permutation(idx.begin(),idx.end()));

    }
    ret = ret == INF? -1 :  ret;
    cout << ret <<endl;
return 0;
  }
