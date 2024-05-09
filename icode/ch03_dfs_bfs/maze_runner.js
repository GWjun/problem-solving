let [n, m] = [5, 6];

let arr = [
  [1, 0, 1, 0, 1, 0],
  [1, 1, 1, 1, 1, 1],
  [0, 0, 0, 0, 0, 1],
  [1, 1, 1, 1, 1, 1],
  [1, 1, 1, 1, 1, 1],
];

let dx = [1, -1, 0, 0];
let dy = [0, 0, 1, -1];
let visited = Array.from({ length: n }, () => Array(m).fill(0));
let que = [[0, 0]];

while (que.length) {
  let [x, y] = que.shift();
  visited[x][y] = 1;

  if (x === n - 1 && y === m - 1) break;

  for (let i = 0; i < 4; i++) {
    let nx = x + dx[i];
    let ny = y + dy[i];
    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
    if (arr[nx][ny] === 1 && !visited[nx][ny]) {
      arr[nx][ny] = arr[x][y] + 1;
      que.push([nx, ny]);
    }
  }
}

console.log(arr[n - 1][m - 1]);
