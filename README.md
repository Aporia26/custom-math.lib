# Custom Math & Equation Solver Library

A lightweight, and data-oriented custom mathematical library built from scratch in C and C++. This repository features a purely functional vector and matrix.

## 🚀 Features

- **Vector Mathematics (`Vector.h` / `Vector.cpp`)**: 3D vector operations using passing-by-const-reference to completely eliminate unnecessary memory copies.
- **Matrix Engineering (`Matrices.h`)**: Flat 1D array row/column architecture for linear transformations.
- **Defensive Algorithm Design (`Quadratic_Eqn.c`)**: A zero-dependency C-style quadratic equation solver containing validation barriers to dynamically mitigate domain errors (like square roots of negative values) and division-by-zero exceptions.

---

## 📁 Repository Structure

```text
custom-math.lib/
└── source/
    ├── Vector.h          # 3D Vector structure declarations and functional interfaces
    ├── Vector.cpp        # Optimized math implementations for vector mechanics
    ├── Matrices.h        # 3x3 and 4x4 matrix storage blueprints & linear math
    └── Quadratic_Eqn.c   # Self-contained standalone CLI quadratic equation solver
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

// Initialize an identity tracking pipeline
mat4 pipeline = mat4_identity();

// Combine geometric translations via matrix multiplication
mat4 transformation = mat4_multiply(pipeline, another_matrix);
```

### 3. Quadratic Solver CLI
A protected command-line algorithm ensuring stable coefficient validation before processing the core quadratic equations.

```bash
# Compilation
gcc source/Quadratic_Eqn.c -o quad_solver -lm

# Execution
./quad_solver
```

---

## ⚡ Architecture Philosophy: Data-Oriented Design

Unlike traditional object-oriented structures that couple heavy class behaviors directly inside structures, this library strictly implements a **Data-Oriented Approach**. 

<!--1. **Pure Data Layouts**: Vectors and matrices act strictly as raw numeric data containers (`structs`), preventing implicit compiler-generated hidden pointers (`vtables`).
2. **Deterministic Processing**: Algorithms exist cleanly as decoupled mathematical free-functions. This approach keeps functions predictable, heavily side-effect-free, and highly compliant with modern compiler inlining pipelines.
-->
---

## ⚙️ Compilation & Integration

To bring these modules directly into a standard C++ compilation pipeline, invoke your favorite toolchain including the source definitions directly:

```bash
# Example manual GCC linkage
g++ -std=c++17 main.cpp source/Vector.cpp -o main_executable
```
