/*
 * Problem Statement: Calculate x raised to the power n (pow(x, n)).
 * Algorithm: Binary Exponentiation (Logarithmic Time)
 * Pseudocode:
 * 1. Convert n to long long N to handle overflow (when n = INT_MIN).
 * 2. If N is negative, set x = 1/x and N = -N.
 * 3. Initialize result to 1.0.
 * 4. While N > 0:
 *    a. If N is odd, multiply result by x.
 *    b. Square x (x = x * x) and divide N by 2.
 * 5. Return result.
 */
#include <iostream>
using namespace std;

class PowXN {
public:
    double myPow(double x, int n) {
        long long N = n;
        
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        
        double result = 1.0;
        
        while (N > 0) {
            if (N % 2 == 1) {
                result *= x;
            }
            x *= x;
            N /= 2;
        }
        
        return result;
    }
};


int main(){
    PowXN powXN;
    double x = 2.0;
    int n = 10;
    cout << powXN.myPow(x, n) << endl;
    return 0;
}