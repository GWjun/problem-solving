#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, e;
    cin >> n >> e;

    long long ans = 0;
    vector<vector<pair<int, int>>> arr(n + 1);

    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        arr[a].push_back({ b, c });
        arr[b].push_back({ a, c });
    }

    priority_queue<pair<int, int>> pq;
    vector<bool> visited(n + 1);

    for (auto pair : arr[1]) {
        pq.push({ -pair.second, pair.first });
    };
    visited[1] = true;

    while (!pq.empty()) {
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (visited[now]) continue;

        ans += dist;
        visited[now] = true;

        for (auto pair : arr[now]) {
            pq.push({ -pair.second, pair.first });
        }
    }

    cout << ans << '\n';

    return 0;
}
