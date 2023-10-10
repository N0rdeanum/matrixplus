#ifndef S21MATRIX_OOP_H_
#define S21MATRIX_OOP_H_

#include <algorithm>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <utility>

#define DEFAULT_ROWS 3
#define DEFAULT_COLS 3
#define EPS 1e-6

class S21Matrix {
 private:
  // attributes
  int rows_, cols_;  // rows and columns attributes
  double **matrix_;  // pointer to the memory where the matrix will be allocated

 public:
  S21Matrix();                            // default constructor
  S21Matrix(int rows, int cols);          // parameterized constructor
  S21Matrix(const S21Matrix &other);      // copy cnstructor
  S21Matrix(S21Matrix &&other) noexcept;  // move cnstructor
  ~S21Matrix();                           // destructor

  // some operators overloads
  S21Matrix &operator=(const S21Matrix &other);  // assignment operator overload
  S21Matrix &operator=(S21Matrix &&other) noexcept;
  bool operator==(const S21Matrix &other);
  double &operator()(const int rows,
                     const int cols);  // index operator overload
  const double &operator()(const int rows, const int cols) const;
  S21Matrix &operator+=(const S21Matrix &other);
  S21Matrix operator+(const S21Matrix &other);
  S21Matrix &operator-=(const S21Matrix &oother);
  S21Matrix operator-(const S21Matrix &oother);
  S21Matrix &operator*=(const S21Matrix &other);
  S21Matrix &operator*=(double num);
  S21Matrix operator*(const S21Matrix &other);
  S21Matrix operator*(const double num) const;

  // some public methods
  bool EqMatrix(const S21Matrix &other) const;
  void SumMatrix(const S21Matrix &other);
  void SubMatrix(const S21Matrix &other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix &other);
  double Determinant();
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  S21Matrix InverseMatrix();
  S21Matrix MinorMatrix(int rows, int cols) const;

  int getCols() const noexcept;
  int getRows() const noexcept;

  void setCols(int cols);
  void setRows(int rows);
};

#endif  // S21MATRIX_OOP_H_
