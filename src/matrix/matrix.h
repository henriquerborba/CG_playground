/*
 * matrix.h
 */

#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <iostream>
#include "../vector2.h"
#include <math.h>
#define M_PI 3.14159265358979323846 /* pi */

class Matrix
{
public:
    Matrix(int, int);
    Matrix(float **, int, int);
    Matrix();
    ~Matrix();
    Matrix(const Matrix &);
    Matrix &operator=(const Matrix &);

    inline float &operator()(int x, int y) { return p[x][y]; }

    Matrix &operator+=(const Matrix &);
    Matrix &operator-=(const Matrix &);
    Matrix &operator*=(const Matrix &);
    Matrix &operator*=(float);
    Matrix &operator/=(float);
    Matrix operator^(int);
    Vector2 operator*(Vector2 v);

    void swapRows(int, int);
    Matrix transpose();

    static Matrix createIdentity(int);

    // transformations
    static Matrix scale(float sx, float sy);
    static Matrix rotate(float angle);
    static Matrix translate(float positionX, float positionY);

    // functions on vectors
    static float dotProduct(Matrix, Matrix);

    // functions on augmented matrices
    Matrix inverse();

    void print();

private:
    int rows_, cols_;
    float **p;

    void allocSpace();
    Matrix expHelper(const Matrix &, int);
};

Matrix operator+(const Matrix &, const Matrix &);
Matrix operator-(const Matrix &, const Matrix &);
Matrix operator*(const Matrix &, const Matrix &);
Matrix operator*(const Matrix &, float);
Matrix operator*(float, const Matrix &);
Matrix operator/(const Matrix &, float);

#endif
