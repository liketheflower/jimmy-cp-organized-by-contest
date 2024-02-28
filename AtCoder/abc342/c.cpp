#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    string s;
    cin >> n >> s;
    vector<int>ch(26, 0);
    for (int i =0; i < 26;++i){
     ch[i] = i;
    }
    int m;
    cin >> m;
    char a, b;
    int ai, bi;
    for (int i =0; i < m;++i){
        cin >> a >> b;
	ai = a-'a';
	bi = b - 'a';
	for (int j = 0; j < 26;++j){
	    if (ch[j] == ai){
	    ch[j] = bi;
	    }
	}
    }
    for (int i = 0; i <n;++i){
	s[i] = ch[s[i]-'a'] + 'a';
    }
    cout << s<<endl;
    return 0;
}

