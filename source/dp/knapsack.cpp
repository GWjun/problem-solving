#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n = 4; // 아이템 개수
    int maxW = 7; // 배낭의 최대 무게

    vector<int> values = { 0, 16, 19, 23, 28 }; // 아이템 가치
    vector<int> weights = { 0, 2, 3, 4, 5 };   // 아이템 무게

    vector<vector<int>> dp(n + 1, vector<int>(maxW + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= maxW; w++) {
            if (weights[i] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i]] + values[i]);
            }
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << "최대 가치: " << dp[n][maxW] << endl;

    return 0;
}
