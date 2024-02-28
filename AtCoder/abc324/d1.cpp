#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
typedef pair<int, int> PII;
int mex(int i, int j, int k){
    vector<int>a(4, 0);
    int ret = 0;
    a[i] = 1;
    a[j] = 1;
    a[k] = 1;
    for (int e = 0; e < 4; ++e){
	if (!a[e])return e;
    }
    return ret;
}
int get_cnt(vector<int>&e, vector<int>&a,vector<int>& b){
    const int ne = e.size(), na =a.size(), nb = b.size();
    if (ne == 0 || na == 0 || nb ==0 )return 0;
    int ret = 0;
    int j = nb -1;
    int i = na - 1;
    for (int f = ne - 1; f >=0 ; --f){
    for (; i >=0 && a[i] > e[f]; i--){                                        
    while( j >= 0 &&b[j] > a[i]){                                                       
        --j;                                                                            
    }                                                                                   
        ret += nb - j - 1;                                                              
    }       
   
   
   
    }

    return ret;
}
void solve()
{   int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i){
	scanf("%d",&nums[i]);
    }
    string s;
    cin >> s;
    vector<vector<int>> M(3), E(3), X(3);
    for (int i = 0; i < n;++i){
	if (s[i] == 'M'){
	    M[nums[i]].push_back(i);
	} else if(s[i] == 'E'){
	   E[nums[i]].push_back(i);
	}else{
	   X[nums[i]].push_back(i);
	}
    }
    int ret = 0;
    for (int i = 0; i < 3; ++i){
	    for (int j = 0; j < 3; ++j)
	    {
		for (int k = 0; k < 3; ++k){
		    auto cnt = get_cnt(M[i], E[j], X[k]);
		    //cout << i << " "<<j<<" "<< k <<" "<<mex(i, j, k) << " "<<cnt<<endl;
		    ret += mex(i, j, k)*cnt;
		}
	    }
    }
    cout << ret << endl;
}

int main(){
  solve();
  return 0;
}
