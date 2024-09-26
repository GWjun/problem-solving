#include <bits/stdc++.h>
using namespace std;

int v, e;
int parent[100001];

vector<pair<int, pair<int, int>>> edges;
int result = 0;


int findParent(int x) {
    if (x == parent[x]) return x;
    return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    if (a < b) parent[b] = a;
    else parent[a] = b;
}

int main(void) {
    cin >> v >> e;

    for (int i = 1; i <= v; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < e; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        edges.push_back({ cost, {a, b} });
    }

    /**
     * 1. 비용에 따라 간선을 정렬
     * 2. 비용이 적은 간선을 추가 하면서 사이클 확인 (union-find)
     */

     // 간선을 비용순으로 정렬
    sort(edges.begin(), edges.end());

    for (int i = 0; i < edges.size(); i++) {
        int cost = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;

        // 같은 집합 아닌 경우
        if (findParent(a) != findParent(b)) {
            unionParent(a, b);
            result += cost;
        }
    }

    cout << result << '\n';
}