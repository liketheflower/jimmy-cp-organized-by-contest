#include<iostream>
using namespace std;
int main(){
    int n1, n2;
    cin >> n1 >> n2;
    string s1, s2;
    cin >> s1 >> s2;
    bool left = false, right = false;
    if (n1 <= n2){
	left = s2.substr(0, n1) == s1;
	right = s2.substr(n2 - n1, n1) == s1;  
    }
    if (left && right)cout << 0 << endl;
    else if (left) cout<<1<<endl;
    else if(right)cout <<2<<endl;
    else cout << 3<<endl;
return 0;
  }
