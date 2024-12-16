#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void setPrime(vector<bool>& isPrime, int n) {
    isPrime[0] = isPrime[1] = false;

    // 부동 소주점 오류 있을 수도
    int limit = sqrt(n);
    for (int i = 2; i <= limit; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<bool> isPrime(n + 1, true);
    setPrime(isPrime, n);

    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) cout << i << " ";
    }
    cout << endl;

    return 0;
}
