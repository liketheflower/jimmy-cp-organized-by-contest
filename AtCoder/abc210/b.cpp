#include<iostream>
using namespace std;
int main()
{
  int n;
  string s;
  cin >> n;
  cin >> s;
  for (int i = 0; i < n; ++i){
    if (s[i] == '1'){
        if (i%2==0){
            cout << "Takahashi" << endl;
        } else 
            cout << "Aoki" << endl;
        break;
    }
  }
  return 0;
}
