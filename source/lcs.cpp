#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * 1. n+1, m+1 vector 만들고 1줄 0으로 초기화
 * 2. i in (1, n), j in (1,m) 순회하면서
 * 3. 마지막 글자가 같다면 (i-1, j-1) + 1 다르다면 max((i-1, j), (i, j-1))
 */
int lcs(string a, string b) {
    int n = a.length();
    int m = b.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    /**
     * Shortest Common Supersequence
     * return (m + n - lcs);
     *
     * Edit distance(교체 비용 없을 시)
     * return (m + n - 2 * lcs);
     */

    return dp[n][m];
}

int main() {
    string a = "ABCBDAB";
    string b = "BDCABC";
    cout << "LCS 길이: " << lcs(a, b) << endl;
    return 0;
}
