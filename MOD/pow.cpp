#include <iostream>
using namespace std;

const int MOD = 1e9+7;

// a^n mod を計算する
long long modpow(long long a, long long n) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}

int main() {
    cout << modpow(3, 45) << endl;
}
