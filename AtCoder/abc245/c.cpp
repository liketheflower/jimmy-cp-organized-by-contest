#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
int main()
{

    int  N, K; cin >> N >> K;
    vector<int> A, B;
    for (int i = 0; i < N; ++i){
        int num;cin>> num;
        A.push_back(num);
    }
    for (int i = 0; i < N; ++i){
        int num;cin>>num;
        B.push_back(num);
    }
    bool zero = true, one = true;
    if (N==1)cout<<"Yes"<<endl;
    for (int i = 1; i < N; ++i){
       //  cout << i <<" "<<A[i] <<" "<< B[i] << endl;
         bool new_zero  =false, new_one = false;
        if ((zero && abs(A[i] - A[i-1]) <= K) || (one && abs(A[i] - B[i-1]) <= K))new_zero=true;
        if ((zero && abs(B[i] - A[i-1]) <= K) || (one && abs(B[i] - B[i-1]) <= K))new_one=true;
        zero = new_zero;
        one = new_one;
        if (zero || one)continue;
        else {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
