#include<iostream>
#include<vector>
#include<cstring>
#include<set>
#include<map>
using namespace std;
typedef pair<int, int> PII;

int distinctPrimeFactors(int N)
{
    if (N < 2) {
        return 0;
    }

    int c = 2;
    set<int> visited;

    while (N > 1) {
        if (N % c == 0) {
            visited.insert(c);
            N /= c;
        }
        else
            c++;
    }
    return visited.size();
}
int main(){
    map<int, int>cnt;
    int N = 100000;
    for (int i = 1; i <=N; ++i){
	auto ret = distinctPrimeFactors(i);
        cnt[ret] ++;
	//cout << i <<" " << distinctPrimeFactors(i)<< endl;
    }
    for (auto [k, v]:cnt){
	cout << k <<" "<<v<<endl;
    }
return 0;
  }
