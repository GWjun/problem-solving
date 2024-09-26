#include <bits/stdc++.h>
using namespace std;

int v, e;

int indegree[100001];
vector<int> graph[100001];

/**
 * 1. Indegree가 0 인 노드를 큐에 삽입
 * 2. 큐를 pop하여 해당 노드의 outgoing 간선 제거, 1번 반복
 */
void topologySort() {
    vector<int> result;
    queue<int> q;

    // 처음 진입차수가 0인 노드를 큐에 삽입
    for (int i = 1; i <= v; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int now = q.front();
        q.pop();
        result.push_back(now);

        for (int i = 0; i < graph[now].size(); i++) {
            // outgoing edge 제거
            indegree[graph[now][i]] -= 1;

            if (indegree[graph[now][i]] == 0) {
                q.push(graph[now][i]);
            }
        }
    }

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << ' ';
    }
}

int main(void) {
    cin >> v >> e;

    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);

        // outgoing edge 기록
        indegree[b] += 1;
    }

    topologySort();
}