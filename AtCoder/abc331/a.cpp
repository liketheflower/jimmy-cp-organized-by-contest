#include<iostream>
using namespace std;
int main(){
    int M, D, y, m , d;
    cin >> M >> D >> y >> m >> d;
    if (d == D){
	d = 1;
	if (m == M){
	    m = 1;
	   y += 1;
	}else{
	    m++;
	}
    }else {
	d ++;
    }
    cout << y <<" "<< m <<" "<<d <<endl;
return 0;
  }
