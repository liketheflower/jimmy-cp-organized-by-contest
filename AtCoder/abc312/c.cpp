#include<iostream>
#include<vector>
using namespace std;
#include<unordered_map>
bool good(vector<int> &buy, vector<int>& sell, int a){
	int nu_buy = buy.end() - lower_bound(buy.begin(), buy.end(), a) ;
	int nu_sell = upper_bound(sell.begin(), sell.end(), a) - sell.begin();
 //       cout <<a <<" "<< nu_sell <<" " <<nu_buy<<endl;
	return nu_sell >= nu_buy;
}
int main(){
    int n, m; cin  >> n >> m;
    vector<int> sell(n);
    vector<int> buy(m);

    for (int i = 0; i <n;++i){
	cin >> sell[i];
    }
    for (int i = 0; i <m;++i){
	cin >> buy[i];
    }
    sort(sell.begin(), sell.end());
    sort(buy.begin(), buy.end());
    int lo = 1, hi = 1000000001;
    while (lo < hi){
	int mid = (lo + hi) / 2;
	if (good(buy, sell, mid)){
	    hi = mid;
	}else{
	    lo = mid + 1;
	}
    }
    cout << lo<<endl;
    /*
    for (int i = 0; i < n; ++i){
	int nu_sell = i + 1;
	int nu_buy = upper_bound(buy.begin(), buy.end(), sell[i]) - buy.begin();
	nu_buy = m - nu_buy;
	if (nu_sell >= nu_buy){
	    ret =min(ret, sell[i]);
	    if (nu_buy ==0){
		ret = min(sell[i], buy.back() + 1);
	    }
	    break;
	}
    }
    for (int i = 0; i < m; ++i){
	int nu_buy = m -i + 1;
	int nu_sell = upper_bound(sell.begin(), sell.end(), buy[i]) - sell.begin();
	if (nu_sell >= nu_buy){
	    ret =min(ret, buy[i]);
	    break;
	}
    }
    cout << ret <<endl;
    */
return 0;
  }
