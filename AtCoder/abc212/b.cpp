#include <iostream>
#include <unordered_set>
using namespace std;
bool good(string s){
    unordered_set<char> ss(s.begin(), s.end());
    if (ss.size() == 1) return false;
    for (int i = 0; i < 3; ++i){
	if (s[i]!='9' && int(s[i+1] - s[i]) != 1 || (s[i]=='9' && s[i+1]!='0')) return true;
    }
    return false;
}
int main(){
    string s;
    cin >> s;
    if (good(s)) cout << "Strong" << endl;
    else cout << "Weak" << endl;
    return 0;
}
