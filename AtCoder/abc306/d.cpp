#include<iostream>
#include<vector>
using namespace std;
int main(){
  int n;
  cin >> n;
   long long INF = ( long long)1<<60;
  const int H = 0,  U =  1;
  vector< long long>status(3, INF);
  status[0] = 0;
  for (int i = 0; i < n; ++i)
  {
      int x, num;
      cin >> x >> num;
      vector< long long> new_status(3, INF);
	  if (x == 0){
	      vector< long long >candidates;
	      if (status[H] != INF){
		  // skip
		  candidates.push_back(status[H]);
		  // take
		  candidates.push_back(status[H] + ( long long)num);
	      }
	      if (status[U] != INF){
		  // take
		  candidates.push_back(status[U] + ( long long)num);
	          // skip
		  new_status[U] = status[U];
	      }
	       long long this_ret = INF; 
	      if (!candidates.empty()){
		  this_ret = *max_element(candidates.begin(), candidates.end());
	      }
	      new_status[H] = this_ret;

	  } else {
              if (status[H] != INF){
		  // skip
		  new_status[H] = status[H];
		  // take
		  new_status[U] = status[H] + ( long long)num;
              }
              if (status[U] != INF){
                  // skip
		  if (new_status[U] == INF){
		      new_status[U] = status[U];
		  } else {
		      new_status[U] = max(new_status[U], status[U]);
		  }
              }
	  }
          status = new_status;
//	  cout << i << " "<<status[0] <<" "<<status[1]<<endl;
  }
  vector< long long> rets;
//  cout <<  "||| "<<status[0] <<" "<<status[1]<<endl;
  if (status[H]!= INF)rets.push_back(status[H]);
  if (status[U]!= INF)rets.push_back(status[U]);
  if (rets.empty())cout << 0 <<endl;
  else if ((int)rets.size()  == 1) cout << rets[0];
  else {
      if (rets[0] > rets[1]){
	  cout << rets[0];
      } else {
	  cout << rets[1];
      }
  }
  return 0;
}
