#include<iostream>
using namespace std;
int main(){
int N, X;
cin >> N >> X;
int num;
int cnt = 0;
int good = true;
for (int i = 0; i < N; ++i){
   cin >> num;
   cnt += num - (i%2);
   if (cnt > X) {good = false; break;}
}
if (good) cout << "Yes" << endl;
else cout << "No" << endl;
return 0;
}
