#include<iostream>
using namespace std;


void solve(int R, int C){
   int n = 2*R + 1, m = 2*C+1;
   for (int i = 0; i < n; ++i){
       for (int j = 0; j < m; ++j){
          if (i == 0 && j <= 1 ) {
          cout << '.';continue;
          } 
          
          if (i == 1 && j == 0 ) {
          cout << '.';continue;
          } 
          if (i % 2 == 0){
              cout << (j%2==0? '+':'-') ;
          } else {
              cout << (j%2==0? '|':'.') ;
          }
       }
       cout << endl;
   }   
   return;
}
int main(){
   int T; cin >> T;
   for (int i = 1; i <= T; ++i){
      cout<<"Case #" << i << ":" << endl;
      int R, C; cin >> R >> C;
      solve(R, C);
   }
   return 0;
}
