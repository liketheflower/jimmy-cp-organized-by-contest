#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s;
    cin >> s;
    bool found = false;
    for (int i = 0; i < n-1; ++i){
	if (s[i] == 'a' && s[i+1] == 'b'){
	    found = true;
	    break;
	}
	if (s[i] == 'b' && s[i+1] == 'a'){
	    found = true;
	    break;
	}
    }
	if (found)cout<<"Yes"<<endl;
	else cout << "No" << endl;

return 0;
  }
