#include <bits/stdc++.h>
using namespace std;

int v, e;
int parent[100001];


/**
 * 배열에서 재귀적으로 부로를 찾는 함수
 */
int findParent(int x) {
    if (x == parent[x]) return x;
    return parent[x] = findParent(parent[x]);
}

/**
 * 작은 값이 부모가 되게 업데이트
 */
void unionParent(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    if (a < b) parent[b] = a;
    else parent[a] = b;
}

int main(void) {
    cin >> v >> e;

    // 자기 자신을 부모로 가지게 초기화
    for (int i = 1; i <= v; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        unionParent(a, b);
    }

    // 한 번 업데이트 하기
    for (int i = 1; i <= v; i++) {
        cout << findParent(i) << ' ';
    }
    cout << '\n';

    for (int i = 1; i <= v; i++) {
        cout << parent[i] << ' ';
    }

    cout << '\n';
}

/**
 * 모든 간선에 대해 두 노드의 루트 노드가 같다면 사이클이 존재
 */
int isCycle() {
    bool cycle = false;

    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;

        if (findParent(a) == findParent(b)) {
            cycle = true;
            break;
        }
        else {
            // 같은 그룹으로 설정
            unionParent(a, b);
        }
    }
}