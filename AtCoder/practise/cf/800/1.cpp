#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    if (n <=3){
	cout<<"NO"<<endl;
	return 0;
    }
    n -= 2;
    if (n&1)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    return 0;
}
