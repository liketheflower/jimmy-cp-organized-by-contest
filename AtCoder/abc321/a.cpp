#include <cmath>
#include<iostream>
using namespace std;
int main(){
    int a;
    cin >> a;
    string s = to_string(a);
    bool ret = true;
    if (s.size()==1){
	ret = true;
    } else {
	for (int i = 1; i < s.size(); ++i){
	    if (s[i] - s[i-1]>=0){
		ret = false;
		break;
	    }
	}
    }
    if (ret)cout <<"Yes"<<endl;
    else cout <<"No"<<endl;
return 0;
  }
