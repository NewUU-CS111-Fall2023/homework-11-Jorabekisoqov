#include <iostream>

class Problem7 {
public:
    int eulerTotientFunction(int a, int b) {
        return (a - 1) * (b - 1);
    }

    void solve() {
        int a, b;
        std::cout << "Enter two prime numbers (a and b): ";
        std::cin >> a >> b;

        if (a <= 1 || b <= 1) {
            std::cout << "Both numbers should be greater than 1." << std::endl;
            return;
        }

        int result = eulerTotientFunction(a, b);

        std::cout << "Euler's totient function for " << a << " * " << b << " is: " << result << std::endl;
    }
};

