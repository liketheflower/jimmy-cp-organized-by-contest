#include <iostream>
#include<cmath>
float EPS = 1e-9;
using namespace std;
int main(){
  long long N;
  cin >> N;
  // (1 + n) * n /2 >= N
  // (1 + n) * n >= 2N
  // n^2 + n - 2N  >= 0
  // a = 1, b =1, c = -2N
  //(-b + sqrt(b*b - 4a*c))/2a
  // (-1 + sqrt(1 + 8N))/2
  float n = N*8;
  float ret = sqrtf(n + 1) - 1.0;
  ret = ret / 2.0;
  long long finret = (long long) (ret) - 1;
  for (long long check = finret; ; ++check){
  long long sum = (1 + check)*check / 2;
  if (sum >= N) {
      cout << check << endl;
      break;
  }
  }
  return 0;
}
