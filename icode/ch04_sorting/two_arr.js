let [n, k] = [5, 3];
let a1 = [1, 2, 5, 4, 3];
let a2 = [5, 5, 6, 6, 5];

a1.sort();
a2.sort((a, b) => b - a);

for (let i = 0; i < k; i++) {
  a1[i] = a2[i];
}

let result = a1.reduce((acc, it) => acc + it);

console.log(result);
