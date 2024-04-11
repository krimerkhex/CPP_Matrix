#ifndef S21_MATRIX_OOP_H
#define S21_MATRIX_OOP_H

//
// Created by Karlene Gyles
//

#include <cmath>
#include <cstring>
#include <iostream>

class S21Matrix {
 public:
  S21Matrix();
  ~S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix &other);
  S21Matrix(S21Matrix &&other) noexcept;

  int getRows() const;
  int getCols() const;
  void setRows(int row);
  void setCols(int col);

  bool eqMatrix(const S21Matrix &other) const;
  bool operator==(const S21Matrix &other) const;

  void sumMatrix(const S21Matrix &other);
  S21Matrix &operator+=(const S21Matrix &o);
  S21Matrix operator+(const S21Matrix &o) const;

  void subMatrix(const S21Matrix &other);
  S21Matrix &operator-=(const S21Matrix &o);
  S21Matrix operator-(const S21Matrix &other) const;

  void mulMatrix(const S21Matrix &other);
  S21Matrix operator*(const S21Matrix &other) const;
  S21Matrix &operator*=(const S21Matrix &other);

  void mulNumber(double num);
  S21Matrix operator*(double num) const;
  S21Matrix &operator*=(double num);

  S21Matrix transpose();
  S21Matrix calcComplements();
  S21Matrix inverseMatrix();
  double determinant();

  S21Matrix &operator=(S21Matrix const &other);
  S21Matrix &operator=(S21Matrix &&other);
  double &operator()(int row, int col);
  double operator()(int row, int col) const;

 private:
  S21Matrix minor(int row, int col);
  int rows_ = 0, cols_ = 0;
  double **matrix_ = nullptr;
  void matrixCreate();
  void matrixCopy(S21Matrix const &other);
  void matrixMove(S21Matrix &other);
  void matrixDelete();
  void checkValid(const S21Matrix &other) const;
  void checkValidMult(const S21Matrix &other) const;
  void checkIndex(int row, int col) const;
  void isSquare() const;
  void resizeMatrix(int row, int col);
  void copyData(const S21Matrix &other);
};

#endif  // S21_MATRIX_OOP_H
