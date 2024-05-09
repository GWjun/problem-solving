const [n, m, k] = [5, 8, 3];
const nums = [2, 4, 5, 4, 6];

nums.sort((a, b) => b - a);

let cnt = 0;
let sum = 0;
for (let i = 0; i < m; i++) {
  cnt++;
  if (cnt > k) {
    sum += nums[1];
    cnt = 0;
  } else {
    sum += nums[0];
  }
}

// O(m)
console.log(sum);

// O(1)
let q = parseInt(m / (k + 1));
let r = m % (k + 1);
console.log(q * (nums[0] * k + nums[1]) + r * nums[0]);
