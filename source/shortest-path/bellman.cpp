#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

const int INF = 1e9;

/**
 * edge를 반복적으로 탐색하여 갱신
 * 1. 시작노드 0, 이외는 INF로 distance 초기화
 * 2. d[u] != INF && d[u] + cost < d[v]
 * 3. n-1 반복, 1번 판별
 */
int main(void) {
    int n, m, start;
    cin >> n >> m >> start;

    vector<tuple<int, int, int>> edges;  // 간선 정보를 저장할 벡터
    vector<int> d(n + 1, INF);           // 최단 거리 배열, 처음엔 모두 무한대
    d[start] = 0;                        // 시작 노드의 최단 거리는 0

    // 간선 정보 입력
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({ a, b, c });  // (출발, 도착, 비용)
    }

    // n-1번 반복
    for (int i = 0; i < n - 1; i++) {
        for (auto& edge : edges) {
            int u, v, cost;
            tie(u, v, cost) = edge;

            // 현재 간선을 통해서 더 짧은 경로를 찾으면 갱신
            if (d[u] != INF && d[u] + cost < d[v]) {
                d[v] = d[u] + cost;
            }
        }
    }

    // 음수 사이클 확인
    bool hasNegativeCycle = false;
    for (auto& edge : edges) {
        int u, v, cost;
        tie(u, v, cost) = edge;

        if (d[u] != INF && d[u] + cost < d[v]) {
            hasNegativeCycle = true;
            break;
        }
    }

    if (hasNegativeCycle) {
        cout << "Negative cycle detected." << '\n';
    }
    else {
        // 결과 출력
        for (int i = 1; i <= n; i++) {
            if (d[i] == INF) cout << "INFINITY" << '\n';
            else cout << d[i] << '\n';
        }
    }

    return 0;
}
