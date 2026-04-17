# C-Programming: Mathematical & Algorithmic Problems 🧮

This repository contains a collection of solutions programmed in **C**, focusing on mathematical optimization, dynamic data structures, and symbolic computation.

All projects were originally developed for the **Programming II** course at the **Escuela Superior de Física y Matemáticas (ESFM)** of the **IPN**.

-

## 🚀 Featured Projects

### 1. The Knapsack Problem 🎒
An implementation of the 0-1 combinatorial optimization problem.
* **Method**: Dynamic Programming to maximize profit under capacity constraints.
* **Complexity**: Pseudo-polynomial $O(nc)$, optimizing both time and space.
* **Applications**: Includes documentation on its use in logistics and cryptography (Merkle-Hellman Knapsack Cryptosystem).

### 2. Search & Sort Algorithms 🔍
A comprehensive system for array manipulation with real-time visualization.
* **Sorting**: Implementation of Quicksort, Mergesort, Heapsort, Shellsort, and direct methods.
* **Searching**: Linear, Binary, and Hash-based search algorithms.
* **Interface**: Console-based graphical rendering using histograms to observe the behavior of each algorithm in real-time.

### 3. Symbolic Differentiator (Expression Trees) 📐
A calculus engine that processes mathematical functions and generates their symbolic derivative.
* **Structure**: Construction of **Binary Expression Trees** from postfix notation.
* **Logic**: Use of **dynamic Stacks** and recursion to apply differentiation rules (sum, product, power, and chain rule).
* **Functions**: Supports variables, constants, and trigonometric functions (Sine, Cosine).

---

## 📂 Documentation Structure
The repository includes complementary files detailing the theoretical basis of the projects:
* **Presentations**: Problem history (Richard Karp, 1972) and visual step-by-step examples[cite: 5, 57, 324].
* **Technical Papers**: Formal definitions, complexity analysis, and variants like the Multiple-Choice Knapsack or the Subset Sum Problem.

## 🛠️ Requirements & Installation
1. **Compiler**: Requires GCC (MinGW for Windows or standard GCC on Linux).
2. **Compilation**: 
   ```bash
   gcc file_name.c -o program
   ./program
