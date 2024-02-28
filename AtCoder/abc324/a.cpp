#include <cmath>
#include<unordered_set>
#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    unordered_set<int>s;
    for (int i = 1; i <=n; ++i){
	int this_val;
	cin >> this_val;
	s.insert(this_val);
    }
    string fin_ret = s.size() == 1 ?"Yes":"No";
    cout << fin_ret <<endl;
return 0;
  }
