#include<iostream>
using namespace std;
int get_len(string&s, int i, int j){
    if (i<0 || j >= s.size())return 0;
    while (i >= 0 && j < s.size() && s[i]==s[j]){
	i--; j++;
    }
    i++; j--;
    return j - i +1;
}
int main(){
    string s;
    cin >> s;
    int ret = 1;
    const int n = s.size();
    for (int i = 0; i <n; ++i){
	ret = max(ret, get_len(s, i - 1, i + 1));
	ret = max(ret, get_len(s, i , i + 1));
    }
    cout << ret <<endl;
return 0;
  }
