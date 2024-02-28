#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
int main(){
  int n,m; cin>>n>>m;
  vector<int>price(n);
  vector<unordered_set<int>>F(n);
  for (int i  =0; i < n; ++i){
      cin >> price[i];
      int c;
      cin >> c;
      for (int j = 0; j < c; ++j){
	  int this_num;
	  cin >> this_num;
	  F[i].insert(this_num);
      }
  }
  bool found = false;
  for (int i = 0; i < n ; ++i){
      for (int j = 0; j < n; ++j){
	  bool this_found = true;
	  if (i == j)continue;
	  if (price[i] < price[j])continue;
	  for(auto k: F[i]){
	      if (F[j].find(k) == F[j].end()){
		  this_found = false;
	      }
	  }
	  if (!this_found )continue;
	  if (price[i] > price[j] ||  F[j].size() > F[i].size()){
	      found = true;
//cout << i << "" << j << endl;
	      cout << "Yes"<<endl;
	      return 0;
	  }

      }
  }
  cout << "No" <<endl;
  return 0;
}
