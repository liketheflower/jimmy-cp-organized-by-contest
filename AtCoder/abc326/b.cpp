#include<iostream>
using namespace std;
int main(){
    int a;
    cin>>a;
    for (int i = a; i <=999;++i){
	int hun = i/100;
	int ten = (i/10)%10;
	int one = i%10;
	if (one == hun*ten){
	    cout << i <<endl;
	    break;
	}
    }

return 0;
  }
