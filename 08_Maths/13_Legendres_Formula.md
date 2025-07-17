# Legendre's Formula

Legendre's formula helps compute the **power of a prime number `p` in the prime factorization of `n!`** (n factorial). It is especially useful in problems involving divisibility of factorials.

---

## 🔹 Formula

Given a positive integer `n` and a prime `p`, the exponent of `p` in `n!` is:

    exponent_p(n!) = n/p + n/p^2 + n/p^3 + ... (until n/p^k < 1)

Only the integer parts (floors) are taken at each division.

---

## 🔹 C++ Implementation

```cpp
int legendreFormula(int n, int p) {
    int count = 0;
    while (n > 0) {
        n /= p;
        count += n;
    }
    return count;
}
