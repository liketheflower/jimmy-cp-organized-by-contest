#include<iostream>
using namespace std;

void get1(int a, int b, int& h, int & m, int & s){
    h  = a;
    m  = b;
    s = 0;
}
void get2(int a, int b, int& h, int & m, int & s){                                      
    h  = a;                                                                             
    m  = b;                                                                             
    s = 1;
}     
void solve(int A, int B, int C, int D){
    int h, m, s, h1, m1, s1;
    get1(A, B, h, m, s);
    get2(C, D, h1, m1, s1);
    if (h > h1 ||(h == h1 && m > m1) || ( h== h1 && m == m1 && s > s1)){
        cout <<"Aoki"  << endl;
    } else {
        cout <<"Takahashi"  << endl;
    }
    return;
}
int main()
{
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    solve (A, B, C, D);
    return 0;
}
