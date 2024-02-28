#include<iostream>
using namespace std;
int main(){
    string s;
    cin >> s;
    string ret = "";
    for (auto c:s){
	ret.push_back(c);
	ret.push_back(' ');
    }
    ret.pop_back();
    cout << ret << endl;
return 0;
  }
