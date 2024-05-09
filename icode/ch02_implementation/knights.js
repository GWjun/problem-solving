const arr = Array.from({ length: 8 }, () => Array(8).fill(0));

const alp = ["a", "b", "c", "d", "e", " f", " g", "h"];

const dx = [-2, -2, 1, -1, 1, -1, 2, 2];
const dy = [1, -1, 2, 2, -2, -2, 1, -1];

const input = "c2";

let x = alp.indexOf(input[0]);
let y = input[1] - 1;

let cnt = 0;
for (let i = 0; i < 8; i++) {
  let nx = x + dx[i];
  let ny = y + dy[i];

  if (nx >= 8 || nx < 0 || ny >= 8 || ny < 0) continue;
  cnt++;
}

console.log(cnt);
