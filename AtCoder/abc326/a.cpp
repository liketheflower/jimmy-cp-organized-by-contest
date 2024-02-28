#include<iostream>
using namespace std;
int main(){
    int a, b;
    cin>>a>>b;
    bool stair = false;
    if (b >= a){
	if (b- a <= 2) stair=true;
    } else {
	if (a - b <= 3)stair=true;
    }
    cout << (stair? "Yes":"No")<<endl;

return 0;
  }
