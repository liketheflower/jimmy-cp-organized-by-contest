#include<iostream>
using namespace std;
int get_ret(int a, int l , int r ){
   if (a < l)return l;
   else if (a > r) return r;
   else return a;
}
    /*
     a [l, r] -> x = l
[l, a, r] -> x = a
[l , r] a -> x= r
*/
int main(){
    int n, l, r;
    cin >> n >> l >> r;
    int ret = 0;
    int x;
    for (int i = 0; i <n ;++i){
	cin >> x;
	ret = get_ret(x, l, r);
	if (i < n -1) cout << ret <<" ";
	else cout << ret <<endl;
    }
return 0;
  }
