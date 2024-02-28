#include<iostream>
using namespace std;
bool contains_single_ch(string s){
    for (auto c: s.substr(1)){
        if (c != s[0])return false;
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    int ret = 0;
    for (int i = 1; i <= n; ++i){
    int day;
    cin >> day;
    string month_s = to_string(i);
    string day_s = "";
    for (int d = 1; d <= day; ++ d){
	day_s = to_string(d);
	//cout << month_s + day_s <<endl;
        ret += contains_single_ch(month_s + day_s);
    }
    }
    
    cout << ret << endl;
return 0;
  }
