#include <iostream>
#include <chrono>
#include <algorithm>
#include <numeric>
#include <ctime>
#include <cstdlib>

using namespace std;

//Function Prototype
int GCD_Euclid(int a, int b);
int GCD(int a, int b);
int GCD_Binary(int a, int b);
int GCD_Binary_Optimize(int a, int b);

int main() {

    clock_t start, end;
    start = clock();
    for (int i = 0; i < 1000; i++) {
        GCD_Euclid(rand() % 10000, rand() % 10000);
    }
    end = clock();
    double duration = double(end - start) / double(CLOCKS_PER_SEC);

    start = clock();
    for (int i = 0; i < 1000; i++) {
        gcd(rand() % 10000, rand() % 10000);
    }
    end = clock();
    double duration_1 = double(end - start) / double(CLOCKS_PER_SEC);

    start = clock();
    for (int i = 0; i < 1000; i++) {
        GCD(rand() % 10000, rand() % 10000);
    }
    end = clock();
    double duration_2 = double(end - start) / double(CLOCKS_PER_SEC);

    start = clock();
    for (int i = 0; i < 1000; i++) {
        GCD_Binary(rand() % 10000, rand() % 10000);
    }
    end = clock();
    double duration_3 = double(end - start) / double(CLOCKS_PER_SEC);

    start = clock();
    for (int i = 0; i < 1000; i++) {
        GCD_Binary_Optimize(rand() % 10000, rand() % 10000);
    }
    end = clock();
    double duration_4 = double(end - start) / double(CLOCKS_PER_SEC);

    cout << fixed;
    cout << "GCD_Euclid: " << duration  << " sec." << endl;
    cout << "gcd: " << duration_1 << " sec." << endl;
    cout << "GCD: " << duration_2 << " sec." << endl;
    cout << "GCD_Binary: " << duration_3 << " sec." << endl;
    cout << "GCD_Binary_Optimize: " << duration_4 << " sec." << endl;
}

/**
 * Standard Algorithm
 * */
int GCD(int a, int b) {
    while (b > 0) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

/**
 * Euclid’s Algorithm
 * */
int GCD_Euclid(int a, int b) {
    return b ? GCD_Euclid(b, a % b) : a;
}

/**
 * Binary Algorithm
 *  1. gcd(0, b) = b and gcd(a, 0) = a.
 *  2. gcd(2a, 2b) = 2 * gcd(a, b).
 *  3. gcd(2a, b) = gcd(a, b) if b is odd and gcd(a, 2b) = gcd(a, b) if a is odd.
 *  4. gcd(a, b) = gcd(|a - b|, min(a, b)) if a and b are odd.
 * */

int GCD_Binary(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    if (a == b) return a;

    if (a % 2 == 0) {
        if (b % 2 == 0) {
            return 2 * GCD_Binary(a / 2, b / 2);
        } else {
            return GCD_Binary(a / 2, b);
        }
    } else if (b % 2 == 0) {
        return GCD_Binary(a, b / 2);
    } else {
        return GCD_Binary(abs(a - b), min(a, b));
    }
}

/**
 * Using the build in function __builtin_ctz() to get the exact bits of the number to right shift
 * whenever we divided by 2 in the GCD_Binary() function.
 * */
int GCD_Binary_Optimize(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;

    int az = __builtin_ctz(a);
    int bz = __builtin_ctz(b);
    int shift = std::min(az, bz);
    b >>= bz;

    while (a != 0) {
        a >>= az;
        int diff = b - a;
        az = __builtin_ctz(diff);
        b = std::min(a, b);
        a = std::abs(diff);
    }

    return b << shift;
}