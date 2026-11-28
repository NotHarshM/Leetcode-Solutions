class Solution {
public:
    int countPrimes(int n) {
        // Edge case: no primes less than 2
        if (n <= 2) {
            return 0;
        }
        // Initialize a boolean array to track prime numbers
        // Initially assume all numbers are prime (true)
        vector<bool> isPrime(n, true);
        // 0 and 1 are not prime numbers
        isPrime[0] = false;
        isPrime[1] = false;
        // Count of prime numbers found
        int primeCount = 0;
        // Sieve of Eratosthenes algorithm
        for (int i = 2; i < n; ++i) {
            // If current number is prime
            if (isPrime[i]) {
                // Increment prime counter
                ++primeCount;
                for (long long j = (long long)i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        return primeCount;
    }
};
