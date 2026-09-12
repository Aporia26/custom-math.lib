# Custom Math & Equation Solver Library

A lightweight, and data-oriented custom mathematical library built from scratch in C and C++. This repository features a purely functional vector and matrix.

## Features

### 1. Vector Operations (`Vector.h` / `Vector.cpp`)
* 2D and 3D floating-point vector implementations.
* Basic arithmetic operations (Vector addition, subtraction, scalar multiplication).
* Geometric calculations including Magnitude, Normalization, Dot Product, and Cross Product.

### 2. Matrix Operations (`Matrices.h` / `Matrices.cpp`)
* Custom structural layout optimized for 3x3 matrices using 0-based, row-major indexing arrays.
* Core algebraic evaluations including:
  * Determinant evaluation via standard cofactor expansion.
  * Matrix multiplication using row-by-column dot product sequences.
  * Structural maps built for transform matrices.

### 3. Algebraic Utilities (`Quadratic_Eqn.c`)
* Pure C function modules for determining real and complex roots using the quadratic formula.

---

## Repository Structure

The core library files are located within the `/source` directory:

```text
source/
├── Matrices.h        # Struct definitions and declarations for matrix operations (e.g., mat3x3)
├── Matrices.cpp      # Implementation of matrix determinants, multiplication, and transformations
├── Vector.h          # Struct definitions for 2D/3D vectors
├── Vector.cpp        # Implementation of vector arithmetic, dot products, and cross products
└── Quadratic_Eqn.c   # Pure C utility implementation for parsing and solving quadratic equations
```

---

## 🛠️ API Reference & Usage

### 1. Vector Operations
<!--The library exposes lightweight, memory-safe functions using explicit read-only constraints (`const &`) allowing seamlessly passing temporary stack values.-->

```cpp
#include "source/Vector.h"
#include <iostream>

int main() {
    vec3 A = {2.0f, 3.0f, 4.0f};
    vec3 B = {5.0f, 0.0f, 11.0f};

    vec3 sum       = add(A, B);
    float dot_prod = dot(A, B);
    vec3 cross_prd = cross(A, B);
    vec3 unit_dir  = unit_vector(A);
    float mag      = magnitude(A);

    std::cout << "Magnitude: " << mag << "\n";
    return 0;
}
```

### 2. Matrix Mechanics
Matrices leverage continuous 1D block allocation (`float m[16]`) ensuring absolute CPU cache locality and native alignment compatibility with graphics APIs like OpenGL/DirectX.

<!-- **`mat3`**: Formatted for tight 3D rotational mechanics without translation padding.
- **`mat4`**: Formatted for standard 3D spatial scaling, rotation, translation, and projection pipelines.-->

```cpp
#include "source/Matrices.h"
#include <iostream>

int main() {
    // Initialize a 3x3 Matrix in row-major configuration
    mat3x3 A;
    A.element[0] = 1.0f; A.element[1] = 0.0f; A.element[2] = 2.0f;
    A.element[3] = 0.0f; A.element[4] = 3.0f; A.element[5] = 0.0f;
    A.element[6] = 4.0f; A.element[7] = 0.0f; A.element[8] = 5.0f;

    // Compute determinant
    float determinant = det(A);
    std::cout << "Matrix Determinant: " << determinant << std::endl;

    return 0;
}
```

### 3. Quadratic Solver CLI
A protected command-line algorithm ensuring stable coefficient validation before processing the core quadratic equations.


---

## ⚡ Architecture Philosophy: Data-Oriented Design

Unlike traditional object-oriented structures that couple heavy class behaviors directly inside structures, this library strictly implements a **Data-Oriented Approach**. 

<!--1. **Pure Data Layouts**: Vectors and matrices act strictly as raw numeric data containers (`structs`), preventing implicit compiler-generated hidden pointers (`vtables`).
2. **Deterministic Processing**: Algorithms exist cleanly as decoupled mathematical free-functions. This approach keeps functions predictable, heavily side-effect-free, and highly compliant with modern compiler inlining pipelines.
-->
---

### C++ Compilation Example
Ensure you compile both the header configurations and implementation source configurations together using your compiler toolset (e.g., MSVC, GCC, or Clang):

```bash
g++ -O3 main.cpp source/Vector.cpp source/Matrices.cpp source/Quadratic_Eqn.c -o MyGameMathApp
```
