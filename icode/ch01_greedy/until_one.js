let [n, k] = [1000000000000000, 12313248];

let cnt = 0;
while (true) {
  if (n < k) break;

  if (n % k === 0) {
    n /= k;
    cnt++;
  } else {
    cnt += n % k;
    n = n - (n % k);
  }
}

cnt += n - 1;

console.log(cnt);
