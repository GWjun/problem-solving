#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

vector<int> arr;

void setPrime(vector<bool>& isPrime, int n) {
    isPrime[0] = isPrime[1] = false;

    int limit = sqrt(n);
    for (int i = 2; i <= limit; i++) {
        if (isPrime[i]) {
            arr.push_back(i);
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    for (int i = limit + 1; i <= n; i++) {
        if (isPrime[i]) arr.push_back(i);
    }
}

int main() {
    int n;
    cin >> n;

    vector<bool> isPrime(n + 1, true);
    setPrime(isPrime, n);

    if (n == 1) {
        cout << 0 << '\n';
        return 0;
    }

    int p1 = 0, p2 = 0;
    long long sum = arr[0];
    long long cnt = 0;

    while (p2 < arr.size()) {
        // cout << arr[p1] << " " << arr[p2] << " " << sum << '\n';
        if (sum == n) {
            cnt++;
            sum -= arr[p1++];
        }
        else if (sum < n) {
            sum += arr[++p2];
        }
        else {
            sum -= arr[p1++];
        }
    }

    cout << cnt << '\n';

    return 0;
}
