#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

void printDivisors(int n)
{
    // Note that this loop runs till square root
    for (int i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
           cout << " "<< i << " " << n/i;
        }
    }
}
void helper(int n){
    unordered_set<int> square;
    for (int i = 1; i < n; ++i){
	int this_one = i*i;
	if (this_one > n)break;
	square.insert(this_one);
    }
    cout << square.size() << endl;
    for (auto c: square)cout << c<<" ";
    cout << endl;
}
int main(){
    helper(10000);
    return 0;
}
