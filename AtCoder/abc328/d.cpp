#include<iostream>
using namespace std;
int main(){
    string s;
    cin >> s;
    string ret= "";
    for (auto& c:s){
	if (c == 'C'){
	    if (ret.size() >= 2){
		int n = ret.size();
		if (ret[n-2] =='A' && ret[n-1] == 'B'){
		    ret.pop_back();
		    ret.pop_back();
		} else {ret.push_back(c);}
	    }else {
		ret.push_back(c);
	    }
	}else {
	    ret.push_back(c);
	}
    
   }
    cout << ret<<endl;
    return 0;
}
