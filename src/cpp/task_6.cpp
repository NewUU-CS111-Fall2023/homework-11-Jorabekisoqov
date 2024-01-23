#include <iostream>
#include <cmath>
class Problem6{
bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }

    int sqrtNum = sqrt(num);
    for (int i = 2; i <= sqrtNum; ++i) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

void generateTwoPrimesGreaterThanN(int n) {
    if (n <= 1) {
        std::cout << "Input should be greater than 1." << std::endl;
        return;
    }

    int firstPrime = n + 1;
    while (!isPrime(firstPrime)) {
        ++firstPrime;
    }

    int secondPrime = firstPrime + 1;
    while (!isPrime(secondPrime)) {
        ++secondPrime;
    }

    std::cout <<  firstPrime << " and " << secondPrime << std::endl;
}
};
