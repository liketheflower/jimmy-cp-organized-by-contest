#include<iostream>
#include <vector>

using namespace std;

// Function to count the number of complete subsets from 1 to n
int countCompleteSubsets(int n) {
    vector<int> primes(n + 1, 0);
    
    // Calculate the prime factorization for each number from 1 to n
    for (int i = 2; i <= n; i++) {
        int num = i;
        for (int j = 2; j * j <= num; j++) {
            while (num % j == 0) {
                num /= j;
                primes[i] ^= (1 << j);
            }
        }
        if (num > 1) {
            primes[i] ^= (1 << num);
        }
    }
    
    int count = 0;
    
    // Calculate the number of complete subsets
    for (int i = 1; i <= n; i++) {
        int divisors = 1; // Number of divisors for the current number
        for (int j = 2; j <= n; j++) {
            if (primes[i] & primes[j]) {
                divisors *= 2;
            }
        }
        // If the number of divisors is even, it's part of a complete subset
        if (divisors % 2 == 0) {
            count++;
        }
    }
    
    return count;
}

int main() {
    int n; // You can change this value as needed
    cin>>n;
    int result = countCompleteSubsets(n);
    cout << "Number of complete subsets from 1 to " << n << ": " << result << endl;
    return 0;
}

