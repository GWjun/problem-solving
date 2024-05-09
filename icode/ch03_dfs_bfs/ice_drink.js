let [n, m] = [4, 5];

let arr = [
  [0, 0, 1, 1, 0],
  [0, 0, 0, 1, 1],
  [1, 1, 1, 1, 1],
  [0, 0, 0, 0, 0],
];

let dx = [1, -1, 0, 0];
let dy = [0, 0, 1, -1];
let visited = Array.from({ length: n }, () => Array(m).fill(0));

function dfs(x, y) {
  visited[x][y] = 1;
  arr[x][y] = 1;

  for (let i = 0; i < 4; i++) {
    let nx = x + dx[i];
    let ny = y + dy[i];
    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
    if (arr[nx][ny] === 0 && !visited[nx][ny]) {
      dfs(nx, ny);
    }
  }
}

let cnt = 0;
for (let i = 0; i < n; i++) {
  for (let j = 0; j < m; j++) {
    if (arr[i][j] === 0) {
      dfs(i, j);
      cnt++;
    }
  }
}

console.log(cnt);
