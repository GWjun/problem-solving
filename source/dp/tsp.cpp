#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main() {
    int n;
    cin >> n;

    /**
     * 방문을 기준으로 상태 정의
     * -1 미방문
     */
    vector<vector<int>> dp(1 << n, vector<int>(n, -1));
    vector<vector<int>> cost(n, vector<int>(n));

    // 간선 가중치 입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    function<int(int, int)> tsp = [&](int visited, int current) {
        // 모든 도시 방문 완료 (Base Case)
        if (visited == (1 << n) - 1) {
            return cost[current][0]; // 시작점(0)으로 돌아가는 비용
        }

        // 이미 계산된 값이 있다면 반환 (메모이제이션)
        if (dp[visited][current] != -1) {
            return dp[visited][current];
        }

        int minV = INF;

        // 방문하지 않은 모든 도시 탐색
        for (int next = 0; next < n; next++) {
            if (!(visited & (1 << next))) {
                minV = min(minV, tsp(visited | (1 << next), next) + cost[current][next]);
            }
        }

        return dp[visited][current] = minV;
        };

    // TSP 수행 (시작점: 0번 도시)
    int min_tour_cost = tsp(1, 0);
    cout << "최소 비용: " << min_tour_cost << endl;

    return 0;
}