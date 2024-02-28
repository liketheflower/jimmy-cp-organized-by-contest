#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void update(int i, int n, int m, string &s, string &t, queue<int>&Q, vector<int>& seen){
    if (i < 0 || i + m > n || seen[i])return;
    for (int j = 0; j < m ; ++j){
	if (s[i + j]  == '#' || s[i + j] == t[j])continue;
	else return;
    }
    seen[i] = true;
    Q.emplace(i);
    return;
}
int main(){
    int n, m;
    string s, t;
    cin>>n >> m >> s >> t;
    vector<int> seen(n, 0);
    queue<int> Q;
    for (int i =  0; i < n; ++i){
	update(i, n, m, s, t, Q, seen);
    }
    while(!Q.empty()){
	auto i = Q.front();Q.pop();
	for (int j = 0; j < m ; ++j){s[i + j ] = '#';
	}
	for (int j = -m + 1; j < m; ++j)
	{
	    update(i + j, n, m, s, t, Q, seen);
	}
    }
    if (s == string(n, '#'))cout << "Yes"<<endl;
    else cout << "No" << endl;
    return 0;
}
