#include <cmath>
#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    string a;
    cin >> a;
    int ret = -1;
    for (int i = 0; i < n - 2; ++i){
	if (a.substr(i, 3) == "ABC"){
	    ret = i + 1;
	    break;
	}
    }
    cout << ret <<endl;
return 0;
  }
