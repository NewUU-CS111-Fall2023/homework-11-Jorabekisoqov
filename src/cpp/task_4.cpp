#include <iostream>
#include <vector>

using namespace std;

class Problem4 {
public:
    int superPow(int a, vector<int>& b) {
        const int base = 1337;
        int result = 1;

        for (int digit : b) {
            result = (powMod(result, 10, base) * powMod(a, digit, base)) % base;
        }

        return result;
    }

private:
    int powMod(int base, int exponent, int modulus) {
        int result = 1;
        base = base % modulus;

        while (exponent > 0) {
            if (exponent % 2 == 1) {
                result = (result * base) % modulus;
            }

            exponent = exponent >> 1;
            base = (base * base) % modulus;
        }

        return result;
    }
};