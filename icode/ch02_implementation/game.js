// input
let [N, M] = [4, 4];
let [x, y, direction] = [1, 1, 0];
let arr = [
  [1, 1, 1, 1],
  [1, 0, 0, 1],
  [1, 1, 0, 1],
  [1, 1, 1, 1],
];
//

let dx = [-1, 0, 1, 0];
let dy = [0, 1, 0, -1];

function turn_left() {
  direction--;
  if (direction < 0) direction = 3;
}

let visitted = Array.from({ length: N }, () => Array(M).fill(0));
visitted[x][y] = 1;
let cnt = 1;
let is_continue = false;

while (true) {
  is_continue = false;
  visitted[x][y] = 1;

  for (let i = 0; i < 4; i++) {
    turn_left();
    let nx = x + dx[direction];
    let ny = y + dy[direction];

    if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
    if (arr[nx][ny] === 0 && !visitted[nx][ny]) {
      x = nx;
      y = ny;
      is_continue = true;
      cnt++;
      break;
    }
  }

  if (is_continue) continue;

  let nx = x - dx[direction];
  let ny = y - dy[direction];
  if (arr[nx][ny] === 0) {
    x = nx;
    y = ny;
  } else break;
}

console.log(cnt);
