#include<iostream>
#include<vector>
using namespace std;
bool good(string s, string t){
    const int m = s.size(), n = t.size();
    if (m == n){
	int diff = 0;
	for (int i = 0; i < n; ++i){
	    diff += (s[i] != t[i]);
	    if (diff > 1)return false;
	}
	return true;
    } else if (m == n +1){
	int i = 0, j = 0;
	bool insert = false;
	while (i < n){
	    if (s[i] != t[j]){
		if (insert) return false;
		insert = true;
		i += 1;
	    } else {
		i += 1;
		j += 1;
	    }
	    
	}
	if (insert){
	    return s[n] == t[n-1];
	}
	return true;

    } else if (m == n -1){
	 int i = 0, j = 0;                                                               
        bool insert = false;                                                            
        while (i < m){                                                                  
            if (s[i] != t[j]){                                                          
                if (insert) return false;                                               
                insert = true;                                                          
                j += 1;                                                                 
            } else {                                                                    
                i += 1;                                                                 
                j += 1;                                                                 
            }                                                                           
                                                                                        
        }                                                                               
        return true;   
	
    } else{
	return false;
    }
    return false;
}
int main(){

    int n;
    string t;
    cin >> n;
    cin >> t;
    vector<int>ret;
    for (int i = 1; i <=n; ++i){
	string s;
	cin >> s;
	if (good(s, t)){
	    ret.push_back( i);
	}
    }
    
    cout << ret.size() <<endl;
    for (auto x:ret)cout << x <<endl;
    return 0;
  }
