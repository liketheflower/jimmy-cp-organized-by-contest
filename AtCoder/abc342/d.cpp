#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<map>
using namespace std;
typedef long long LL;
vector<int> get_primes(int n){
// Print the number of 2s that divide n 
vector<int>ret;
    while (n % 2 == 0) 
    { 
        ret.push_back(2); 
        n = n/2; 
    } 
 
    // n must be odd at this point. So we can skip 
    // one element (Note i = i +2) 
    for (int i = 3; i <= sqrt(n); i = i + 2) 
    { 
        // While i divides n, print i and divide n 
        while (n % i == 0) 
        { 
            ret.push_back(i); 
            n = n/i; 
        } 
    } 
 
    // This condition is to handle the case when n 
    // is a prime number greater than 2 
    if (n > 2) 
        ret.push_back(n);
    return ret;

}
vector<int> get_odd_prime(int num, unordered_map<int, vector<int>>& memo){
    if (memo.find(num) != memo.end()){
    return memo[num];
    }
    vector<int> primes = get_primes(num);
    unordered_map<int, int> cnt;
    for (auto p: primes)cnt[p]++;
    vector<int>ret;
    for (auto p: primes){
        if (cnt[p] % 2 == 1){
	    if (!ret.empty() && ret.back()==p)continue;
	    ret.push_back(p);
	}
    }
    return memo[num] = ret;
}
LL solve(vector<int>& nums, int n)
{
    LL ret = 0;
    map<vector<int>, int> hist;
    unordered_map<int, vector<int>> memo;
    int zero = 0;
    for (auto num: nums){
	if (num ==0){
	    zero++;
	    continue;
	}
	//cout << num <<  " -- "<<endl;
	auto prime_factors = get_odd_prime(num, memo);
	//for (auto pp: prime_factors)cout << pp <<" ";
	//cout << endl;
	//cout << ret<<endl;
        ret += (LL)hist[prime_factors];
	hist[prime_factors] ++;
    }
    if (zero){
	ret += LL(zero)*LL(n - zero) + LL(zero)*((LL)zero-1ll)/2ll;
    }
    return ret;

}


int main(){
    int n; cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; ++i)cin >> nums[i];
    auto ret = solve(nums, n);
    cout << ret << endl;
    return 0;
}
