#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/**
 * ABB ACBA
 * 0 1 2 3 4
 * 1 0 1 2 3
 * 2 1 1 1 2
 * 3 2 2 1 2
 */
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;

        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= m; j++) {
            dp[0][j] = j;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] }) + 1;
                }
            }
        }

        // vs lcs
        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j <= m; j++) {
        //         if (s1[i - 1] == s2[j - 1]) {
        //             dp[i][j] = dp[i - 1][j - 1] + 1;
        //         }
        //         else {
        //             dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        //         }
        //     }
        // }

        cout << dp[n][m] << '\n';

    }

    return 0;
}