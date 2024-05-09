let n = 2;
let input = [
  ["홍길동", "95"],
  ["이순신", "77"],
];

let sorted = input.sort((a, b) => a[1] - b[1]).map((it) => it[0]);

console.log(sorted.join(" "));
