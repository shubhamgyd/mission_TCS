function gcd(a, b) {
  return b ? gcd(b, a % b) : a;
}

function getQ(X, j) {
  return X / gcd(X, j);
}

function addDivisors(n, map) {
  let m = 1;

  while (m * m <= n) {
    if (n % m == 0) {
      map[m] = -~map[m];

      const l = n / m;

      if (l != m) map[l] = -~map[l];
    }

    m += 1;
  }
}

function f(A, X) {
  const Ais = {};
  let result = 0;

  for (let j = 1; j < A.length; j++) {
    if (A[j] == A[0]) result += 1;

    // Search
    if (Ais.hasOwnProperty(A[j])) {
      const q = getQ(X, j);

      result += Ais[A[j]][q] || 0;

      // Initialise this value's
      // search structure
    } else {
      Ais[A[j]] = {};
    }

    // Add divisors for j
    addDivisors(j, Ais[A[j]]);
  }

  return result;
}

function bruteForce(A, X) {
  let result = 0;

  for (let j = 1; j < A.length; j++) {
    for (let i = 0; i < j; i++) {
      if (A[i] == A[j] && (i * j) % X == 0) result += 1;
    }
  }

  return result;
}

var numTests = 1000;
var n = 100;
var m = 50;
var x = 100;

A = [2, 3, 4, 3, 3, 2, 3, 3];
const X = 2;
const _brute = bruteForce(A, X);
const _f = f(A, X);
console.log(_f);
console.log(_brute);

if (_brute != _f) {
  console.log("Mismatch!");
  console.log(X, JSON.stringify(A));
  console.log(_brute, _f);
}

console.log("Done testing.");
