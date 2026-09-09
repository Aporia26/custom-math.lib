#pragma once;

struct mat4x4 {

    float mat4x4[16];
};

mat4x4 add(mat4x4 A, mat4x4 B);
mat4x4 subst(mat4x4 A, mat4x4 B);
float det(mat4x4 A);
mat4x4 scale(mat4x4 A);
mat4x4 product(mat4x4 A, mat4x4 B);