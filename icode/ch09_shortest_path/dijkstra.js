console.time();

const [n, m] = [6, 11];
const start = 1;
const arr = [
  [1, 2, 2],
  [1, 3, 5],
  [1, 4, 1],
  [2, 3, 3],
  [2, 4, 2],
  [3, 2, 3],
  [3, 6, 5],
  [4, 3, 3],
  [4, 5, 1],
  [5, 3, 1],
  [5, 6, 2],
];

const visited = Array(n + 1).fill(false);
const dist = Array(n + 1).fill(Infinity);
const graph = Array.from(Array(n + 1), () => []);

for (const [a, b, c] of arr) {
  graph[a].push([b, c]);
}

// 방문하지 않은 노드 중, 최단 거리가 가장 짧은 노드의 인덱스 반환
function getSmallNode() {
  let min = Infinity;
  let idx = 0;

  for (let i = 1; i < n + 1; i++) {
    if (dist[i] < min && !visited[i]) {
      min = dist[i];
      idx = i;
    }
  }
  return idx;
}

// 시작 노드 초기화
dist[start] = 0;
visited[start] = true;
for (const [idx, cost] of graph[start]) {
  dist[idx] = cost;
}

// 제외한 n - 1개의 노드에 대해 반복
for (let i = 0; i < n - 1; i++) {
  const now = getSmallNode();
  visited[now] = true;

  for (const [idx, cost] of graph[now]) {
    const newCost = dist[now] + cost;
    if (newCost < dist[idx]) {
      dist[idx] = newCost;
    }
  }
}

for (let i = 1; i <= n; i++) {
  if (dist[i] === Infinity) {
    console.log("INFINITY");
  } else {
    console.log(dist[i]);
  }
}

console.timeEnd();
