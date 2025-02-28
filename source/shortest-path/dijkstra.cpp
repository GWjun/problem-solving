#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;

int n, m, start;
vector<pair<int, int>> graph[100001];
int d[100001];


/**
 * ### 최소의 누적거리를 선택하며 갱신
 *
 * pq
 * - param1: 해당 노드까지의 누적 거리
 * - param2: 탐색할 노드의 번호
 *
 * d
 * - 해당 노드(인덱스)까지의 최소 거리를 나타내는 일차원 배열
 */
void dijkstra(int start) {
    priority_queue<pair<int, int> > pq;

    d[start] = 0;
    pq.push({ 0, start });

    while (!pq.empty()) {
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (d[now] < dist) continue;

        for (auto& pair : graph[now]) {
            int cost = dist + pair.second;
            int next = pair.first;
            if (cost < d[next]) {
                d[next] = cost;
                pq.push({ -cost, next });
            }
        }
    }
}

int main(void) {
    cin >> n >> m >> start;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({ b, c });
    }

    fill(d, d + 100001, INF);
    dijkstra(start);

    for (int i = 1; i <= n; i++) {
        if (d[i] == INF) cout << "INFINITY" << '\n';
        else cout << d[i] << '\n';
    }
}
