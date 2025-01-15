#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 1e9

int n, m, start;
vector<pair<int, int>> graph[100001];
int d[100001];

void dijkstra(int start) {
    priority_queue<pair<int, int> > pq;

    d[start] = 0;
    pq.push({ 0, start });

    while (!pq.empty()) {
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (d[now] < dist) continue;

        for (auto& node : graph[now]) {
            int cost = dist + node.second;
            if (cost < d[node.first]) {
                d[node.first] = cost;
                pq.push({ -cost, node.first });
            }
        };
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
