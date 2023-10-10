#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() {
  rows_ = DEFAULT_ROWS;
  cols_ = DEFAULT_COLS;

  matrix_ = new double *[rows_];
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_];
  }
}

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  if (rows_ > 0 && cols_ > 0) {
    matrix_ = new double *[rows_];
    for (int i = 0; i < rows_; i++) {
      matrix_[i] = new double[cols_];
    }
  } else {
    throw std::out_of_range("Index out of range");
  }
}

S21Matrix::S21Matrix(const S21Matrix &other)
    : rows_(other.rows_), cols_(other.cols_) {
  if (rows_ > 0 && cols_ > 0) {
    matrix_ = new double *[other.rows_];
    for (int i = 0; i < other.rows_; i++) {
      matrix_[i] = new double[other.cols_];
      for (int j = 0; j < other.cols_; j++) {
        matrix_[i][j] = other.matrix_[i][j];
      }
    }
  }
}

S21Matrix::S21Matrix(S21Matrix &&other) noexcept
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;
}

S21Matrix::~S21Matrix() {
  for (int i = 0; i < rows_; i++) {
    delete[] matrix_[i];
  }
  delete[] matrix_;
  matrix_ = nullptr;
}

bool S21Matrix::EqMatrix(const S21Matrix &other) const {
  bool result = true;

  if (cols_ != other.cols_ || rows_ != other.rows_) {
    result = false;
    return result;
  }

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      if (fabs(other.matrix_[i][j] - matrix_[i][j]) > EPS) {
        result = false;
        break;
      }
    }
  }

  return result;
}

void S21Matrix::SubMatrix(const S21Matrix &other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::logic_error(
        "Incorrect input, matrices should have the same size");
  } else {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        matrix_[i][j] = matrix_[i][j] - other.matrix_[i][j];
      }
    }
  }
}

void S21Matrix::SumMatrix(const S21Matrix &other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::logic_error(
        "Incorrect input, matrices should have the same size");
  } else {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        matrix_[i][j] += other.matrix_[i][j];
      }
    }
  }
}

void S21Matrix::MulNumber(const double num) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] *= num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix &other) {
  if (cols_ != other.rows_) {
    throw std::logic_error(
        "Incorrect input, matrices should have the same size");
  }

  if (matrix_ != nullptr && other.matrix_ != nullptr && rows_ > 0 &&
      cols_ > 0 && other.cols_ > 0) {
    S21Matrix tmp(rows_, cols_);

    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        for (int k = 0; k < other.rows_; k++) {
          tmp(i, j) += matrix_[i][k] * other.matrix_[k][j];
        }
      }
    }
    *this = std::move(tmp);
  }
}

S21Matrix &S21Matrix::operator=(const S21Matrix &other) {
  S21Matrix cpy(other);
  *this = std::move(cpy);

  return *this;
}

S21Matrix &S21Matrix::operator=(S21Matrix &&other) noexcept {
  if (matrix_ != nullptr) {
    for (int i = 0; i < rows_; i++) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
  }

  matrix_ = other.matrix_;
  rows_ = other.rows_;
  cols_ = other.cols_;

  other.matrix_ = nullptr;
  other.rows_ = 0;
  other.cols_ = 0;

  return *this;
}

bool S21Matrix::operator==(const S21Matrix &other) { return EqMatrix(other); }

S21Matrix &S21Matrix::operator-=(const S21Matrix &other) {
  SubMatrix(other);
  return *this;
}

S21Matrix S21Matrix::operator-(const S21Matrix &other) {
  S21Matrix result(*this);
  result.SubMatrix(other);
  return result;
}

S21Matrix &S21Matrix::operator*=(const S21Matrix &other) {
  MulMatrix(other);
  return *this;
}

S21Matrix &S21Matrix::operator*=(double num) {
  MulNumber(num);
  return *this;
}

S21Matrix &S21Matrix::operator+=(const S21Matrix &other) {
  SumMatrix(other);
  return *this;
}

S21Matrix S21Matrix::operator+(const S21Matrix &other) {
  S21Matrix res(*this);
  res.SumMatrix(other);

  return res;
}

S21Matrix S21Matrix::operator*(const S21Matrix &other) {
  S21Matrix result(*this);
  result.MulMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator*(const double num) const {
  S21Matrix result(*this);
  result.MulNumber(num);

  return result;
}

double &S21Matrix::operator()(const int rows, const int cols) {
  if (rows > rows_ || cols > cols_ || rows < 0 || cols < 0) {
    throw std::out_of_range("index out of range");
  }
  return matrix_[rows][cols];
}

const double &S21Matrix::operator()(const int rows, const int cols) const {
  if (rows > rows_ || cols > cols_ || rows < 0 || cols < 0) {
    throw std::out_of_range("index out of range");
  }
  return matrix_[rows][cols];
}

S21Matrix S21Matrix::MinorMatrix(int rows, int cols) const {
  S21Matrix res(rows_ - 1, cols_ - 1);

  for (int i = 0, r_idx = 0; i < rows_; i++) {
    for (int j = 0, c_idx = 0; j < cols_; j++) {
      if (i != rows && j != cols) {
        res(r_idx, c_idx++) = (*this)(i, j);

        if (c_idx == cols_ - 1) {
          r_idx++;
        }
      }
    }
  }

  return res;
}

S21Matrix S21Matrix::Transpose() {
  S21Matrix res(cols_, rows_);

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      res(j, i) = (*this)(i, j);
    }
  }

  return res;
}

double S21Matrix::Determinant() {
  if (rows_ != cols_ || rows_ < 0) {
    throw std::logic_error("Incorrect input, calculation error");
  }

  double det = 0.0;

  if (rows_ == 1) {
    det = matrix_[0][0];
  } else if (rows_ == 2) {
    det = matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
  } else {
    for (int i = 0; i < rows_; i++) {
      S21Matrix tmp = MinorMatrix(0, i);

      det += matrix_[0][i] * tmp.Determinant() * pow(-1, i);
    }
  }

  return det;
}

S21Matrix S21Matrix::CalcComplements() {
  if (cols_ != rows_) {
    throw std::logic_error("Incorrect input, calculation error");
  }

  S21Matrix res(rows_, cols_);

  if (rows_ > 1) {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        res(i, j) = MinorMatrix(i, j).Determinant() * pow(-1, i + j);
      }
    }
  }

  return res;
}

S21Matrix S21Matrix::InverseMatrix() {
  double det = Determinant();

  if (fabs(det) > EPS) {
    det = 1 / det;
    S21Matrix tmp = CalcComplements().Transpose();

    tmp.MulNumber(det);

    return tmp;
  } else {
    throw std::invalid_argument("Impossible inverse matrix, determinant is 0");
  }
}

void S21Matrix::setCols(int cols) {
  if (cols > 0 && rows_ > 0) {
    S21Matrix tmp(rows_, cols);

    if (cols_ >= 0) {
      for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < std::min(cols_, cols); j++) {
          tmp(i, j) = (*this)(i, j);
        }
      }
      delete[] matrix_;
      matrix_ = nullptr;
    }

    *this = tmp;
  } else {
    throw std::invalid_argument("The value should be positive");
  }
}

void S21Matrix::setRows(int rows) {
  if (cols_ > 0 && rows > 0) {
    S21Matrix tmp(rows, cols_);

    if (rows_ > 0) {
      for (int i = 0; i < std::min(rows_, rows); i++) {
        for (int j = 0; j < cols_; j++) {
          tmp(i, j) = (*this)(i, j);
        }
      }
      delete[] matrix_;
      matrix_ = nullptr;
    }

    *this = tmp;
  } else {
    throw std::invalid_argument("The value should be positive");
  }
}

int S21Matrix::getCols() const noexcept { return cols_; }

int S21Matrix::getRows() const noexcept { return rows_; }
