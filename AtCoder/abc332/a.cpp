#include<iostream>
typedef long long LL;
using namespace std;
int main(){
    int N, S, K;
    cin >> N >> S >> K;
    LL ret = 0;
    LL a, b;
    for (int i = 0; i < N; ++i){
      cin >> a >> b;
      ret += a*b;
    }
    ret += ret >=S? 0 : K;
    cout << ret << endl;
return 0;
  }
