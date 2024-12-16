#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int w, h;

int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dy[] = { 0, -1, -1, -1, 0, 1, 1, 1 };

void dfs(vector<vector<int>>& arr, vector<vector<bool>>& visited, int x, int y) {
    visited[x][y] = true;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;

        if (!visited[nx][ny] && arr[nx][ny] == 1) {
            dfs(arr, visited, nx, ny);
        }
    }
}

void bfs(vector<vector<int>>& arr, vector<vector<bool>>& visited, int x, int y) {
    queue<pair<int, int>> q;
    q.push({ x, y });
    visited[x][y] = true;

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;

            if (!visited[nx][ny] && arr[nx][ny] == 1) {
                visited[nx][ny] = true;
                q.push({ nx, ny });
            }
        }
    }
}

int main() {
    while (true) {
        cin >> w >> h;
        if (w == 0 && h == 0) break;

        vector<vector<int>> arr(h, vector<int>(w));
        vector<vector<bool>> visited(h, vector<bool>(w, false));
        int count = 0;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> arr[i][j];
            }
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (arr[i][j] == 1 && !visited[i][j]) {
                    dfs(arr, visited, i, j);
                    count++;
                }
            }
        }

        cout << count << endl;
    }

    return 0;
}
