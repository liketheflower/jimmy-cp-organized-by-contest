#include <cmath>
#include<iostream>
using namespace std;
int main(){
    string s;
    cin >> s;
    bool ret = true;
    for (int i = 1; i < s.size(); i+=2){
	if (s[i]!='0')ret=false;
    }
    string fin_ret = ret ?"Yes":"No";
    cout << fin_ret <<endl;
return 0;
  }
