#include<iostream>
#include<vector>
using namespace std;
int count_( vector<int>&prefix_sum_even,vector<int>&prefix_sum_odd, int l, int r){
    int ret = 0;
    if (l >= r) return 0;
    if (l  % 2 == 0){
	ret += prefix_sum_even[r+1] - prefix_sum_even[l];
	ret += prefix_sum_odd[r+1] - prefix_sum_odd[l+1];
     } else {
	ret += prefix_sum_odd[r+1] - prefix_sum_odd[l];
	ret += prefix_sum_even[r+1] - prefix_sum_even[l+1];
     }
    return ret;
}
int main(){
    int n, q;
    cin>>n>>q;
    string s;
    cin >> s;
    vector<int>prefix_sum_even(n + 1);
    vector<int>prefix_sum_odd(n + 1);
    /*
     * sssss
     *  
     */
    for (int i = 1; i < n; ++i){
	prefix_sum_even[i+1] = prefix_sum_even[i];
	prefix_sum_odd[i+1] = prefix_sum_odd[i];
	if (s[i] == s[i-1]){
	    if ((i - 1) % 2 == 0) {
		prefix_sum_even[i+1] ++;
	    }else{
		prefix_sum_odd[i+1] ++;
	    }
	}
    } 
    int l, r;
    /*
    for (auto x: prefix_sum_even)cout << x<< " ";
    cout << endl;
    for (auto x: prefix_sum_odd)cout << x<< " ";
    cout << endl;
    */
    for (int i = 0; i < q; ++ i){
	cin  >> l >> r;
	//cout << s.substr(l -1, r - l + 1) << endl;
	auto ret = count_(prefix_sum_even, prefix_sum_odd, l-1, r-1);
	cout << ret << endl;
    }
    return 0;
}
