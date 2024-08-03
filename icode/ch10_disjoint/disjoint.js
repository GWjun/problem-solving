const [n, m] = [6, 4];
const edges = [
  [1, 4],
  [2, 3],
  [2, 4],
  [5, 6],
];

function findParent(parent, x) {
  if (parent[x] !== x) parent[x] = findParent(parent, parent[x]);
  return parent[x];
}

function unionParent(parent, a, b) {
  a = findParent(parent, a);
  b = findParent(parent, b);
  if (a < b) parent[b] = a;
  else parent[a] = b;
}

const parent = Array.from({ length: n + 1 }, (_, idx) => idx);

for (const edge of edges) {
  const [a, b] = edge;
  unionParent(parent, a, b);
}

console.log(`부모 테이블(전): ${parent.slice(1, n).join(" ")}`);

for (let i = 1; i <= n; i++) {
  findParent(parent, i);
}

console.log(`부모 테이블(후): ${parent.slice(1, n).join(" ")}`);
