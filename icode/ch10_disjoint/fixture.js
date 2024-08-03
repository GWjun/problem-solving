export function findParent(parent, x) {
  if (parent[x] !== x) findParent(parent, parent[x]);
  return x;
}

export function getCycle() {
  let isCycle = false;
  for (const edge of edges) {
    const [a, b] = edge;
    if (findParent(parent, a) !== findParent(parent, b))
      unionParent(parent, a, b);
    else {
      isCycle = true;
      break;
    }
  }
}
