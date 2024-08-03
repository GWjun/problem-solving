const [n, m] = [4, 7];
const arr = [
  [1, 2, 4],
  [1, 4, 6],
  [2, 1, 3],
  [2, 3, 7],
  [3, 1, 5],
  [3, 4, 4],
  [4, 3, 2],
];

// 초기 테이블 생성
const dist = Array.from(Array(n + 1), () => Array(n + 1).fill(Infinity));
for (let i = 1; i <= n; i++) dist[i][i] = 0;

for (const value of arr) {
  const [a, b, cost] = value;
  dist[a][b] = cost;
}

// 3중 반복문 수행
for (let k = 1; k <= n; k++) {
  for (let a = 1; a <= n; a++) {
    for (let b = 1; b <= n; b++) {
      dist[a][b] = Math.min(dist[a][b], dist[a][k] + dist[k][b]);
    }
  }
}

console.log(dist);
