#include <iostream>
#include <climits>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
void solve(vector<int>& a, vector<int> & b){
    sort(a.begin(), a.end()); 
    sort(b.begin(), b.end());
    int ret = INT_MAX;
    const int n = a.size(), m = b.size();
    int i = 0, j = 0;
    while (i < n && j < m){
	ret = min(ret, abs(a[i] - b[j]));
	if (a[i] > b[j])j++;
	else if (a[i] == b[j]) {
	    cout << "0" << endl;
	    return;
	}
	else i++;
    }
    cout << ret << endl;
    return;
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n, 0), b(m, 0);
    for (int i = 0; i < n; ++i)cin >> a[i];
    for (int i = 0; i < m; ++i)cin >> b[i];
    solve(a, b);
    return 0;
}
