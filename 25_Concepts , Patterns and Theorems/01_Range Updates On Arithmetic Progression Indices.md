# Range Updates on Arithmetic Progression Indices: Strategy & Concepts

This document explains the advanced techniques used to solve range update problems where indices follow an arithmetic progression (AP), specifically using **Square Root Decomposition** and **Modular Arithmetic**.

---

## 1. Square Root Decomposition (The "Sqrt Split")

In competitive programming, when a query can be either "dense" (many updates) or "sparse" (few updates), we split the work based on a threshold $B$ (usually $\sqrt{n}$).

* **Large $k$ ($k > \sqrt{n}$):** The number of elements to update is small ($n/k < \sqrt{n}$). For $n=10^5$, if $k=400$, there are only 250 updates. We can afford to update these directly in $O(n/k)$ time.
* **Small $k$ ($k \leq \sqrt{n}$):** There are too many indices to update directly (e.g., $k=1$ or $2$). We **batch** these queries and process them later in $O(n)$ for each distinct $k$.

This ensures every query is handled in roughly $O(\sqrt{n})$ time, leading to an overall complexity of **$O((n + q)\sqrt{n})$**.

---

## 2. Remainder Grouping & Compressed Index Space

For a fixed jump size $k$, any index $i$ belonging to an arithmetic progression starting at $l$ must satisfy the remainder condition:
$$i \equiv l \pmod k$$

The array is logically partitioned into $k$ virtual groups based on these remainders.
* **Example ($k=3$):**
    * Remainder 0: $\{0, 3, 6, 9, \dots\}$
    * Remainder 1: $\{1, 4, 7, 10, \dots\}$
    * Remainder 2: $\{2, 5, 8, 11, \dots\}$

To use standard algorithms, we map these "jumpy" indices to a **Compressed Index Space**:
$$\text{Compressed Index} = \frac{\text{Real Index} - \text{Remainder}}{k}$$
This transforms the set $\{1, 4, 7\}$ into $\{0, 1, 2\}$, creating a continuous range.



---

## 3. Multiplicative Difference Array

A standard **Difference Array** allows $O(1)$ range additions by marking the start and end. Since this problem involves **multiplication**, we adapt the logic:
* **At `start`:** Multiply the current prefix product by $v$.
* **After `end`:** To "undo" the multiplication, multiply by the **Modular Multiplicative Inverse** of $v$.

By calculating the prefix product of this difference array, we apply the multiplication to every element within the range in a single $O(n)$ pass per remainder group.

---

## 4. Fermat’s Little Theorem & Modular Inverse

Division is not defined in modular arithmetic. To "divide" by $v$, we must find an integer $x$ such that:
$$v \cdot x \equiv 1 \pmod{MOD}$$

**Fermat's Little Theorem** states that if $MOD$ is a prime number:
$$a^{MOD-1} \equiv 1 \pmod{MOD}$$
This implies:
$$a^{MOD-2} \equiv a^{-1} \pmod{MOD}$$

The code calculates $v^{MOD-2} \pmod{MOD}$ to effectively "divide" by $v$ during the difference array sweep.



---

## 5. Binary Exponentiation (`modExp`)

Calculating $v^{MOD-2}$ requires raising a number to a power near $10^9$. A linear loop is too slow. **Binary Exponentiation** reduces this to **$O(\log MOD)$** complexity:
* If $b$ is even: $a^b = (a^2)^{b/2}$
* If $b$ is odd: $a^b = a \cdot (a^2)^{(b-1)/2}$



---

## 6. Summary of Algorithm Flow

1.  **Categorize:** Large $k$ queries are simulated immediately. Small $k$ queries are grouped by $k$ and remainder.
2.  **Batch Process:** For each $k \leq \sqrt{n}$, iterate through remainder groups.
3.  **Sweep-line:** In each group, apply "start" and "end" events and calculate the prefix product to update the `nums` array.
4.  **Finalize:** Calculate the XOR sum of the updated array.