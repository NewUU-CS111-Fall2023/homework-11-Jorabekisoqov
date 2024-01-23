#include <iostream>
#include <cmath>

class Problem8 {
public:
    // Function to calculate Euler's totient function
    int eulerTotientFunction(int p, int q) {
        return (p - 1) * (q - 1);
    }

    // Function to check if two numbers are coprime
    bool areCoprime(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a == 1;
    }

    // Function to find modular multiplicative inverse using extended Euclidean algorithm
    int modInverse(int a, int m) {
        int m0 = m, t, q;
        int x0 = 0, x1 = 1;

        if (m == 1) return 0;

        while (a > 1) {
            q = a / m;
            t = m;

            m = a % m, a = t;
            t = x0;

            x0 = x1 - q * x0;
            x1 = t;
        }

        if (x1 < 0) x1 += m0;

        return x1;
    }

    // Function to generate RSA keys
    void generateRSAKeys(int p, int q) {
        int n = p * q;
        int phiN = eulerTotientFunction(p, q);

        int e = 2; // starting with a common choice for e
        while (e < phiN) {
            if (areCoprime(e, phiN)) {
                break;
            }
            e++;
        }

        int d = modInverse(e, phiN);

        std::cout << "Public Key (e, n): (" << e << ", " << n << ")" << std::endl;
        std::cout << "Private Key (d, n): (" << d << ", " << n << ")" << std::endl;
    }
};