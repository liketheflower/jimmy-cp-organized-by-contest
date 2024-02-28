#include<iostream>
using namespace std;
int main(){
    int n, l;
    cin >> n >> l;
    int ret = 0;
    int x;
    for (int i = 0; i <n ;++i){
	cin >> x;
	ret += x >= l;
    }
    cout <<  ret << endl;
return 0;
  }
