#include "s21_matrix_oop.h"

//
// Created by Karlene Gyles
//

S21Matrix::S21Matrix() : S21Matrix(3, 3) {}

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  if (this->cols_ < 1 || this->rows_ < 1) {
    throw std::range_error("Error");
  }
  matrixCreate();
}

void S21Matrix::matrixCreate() {
  this->matrix_ = new double *[this->rows_]();
  for (int i = 0; i < this->rows_; ++i) {
    this->matrix_[i] = new double[this->cols_]();
  }
}

S21Matrix::S21Matrix(const S21Matrix &other)
    : rows_(other.rows_), cols_(other.cols_) {
  this->matrixCopy(other);
}

void S21Matrix::matrixCopy(const S21Matrix &other) {
  this->matrixDelete();
  this->rows_ = other.rows_;
  this->cols_ = other.cols_;
  this->matrixCreate();
  if (this->matrix_ != nullptr) {
    this->copyData(other);
  }
}

void S21Matrix::matrixMove(S21Matrix &other) {
  if (this != &other) {
    this->cols_ = other.cols_;
    this->rows_ = other.rows_;
    this->matrix_ = other.matrix_;
    other.cols_ = other.rows_ = 0;
    other.matrix_ = nullptr;
  }
}

S21Matrix::S21Matrix(S21Matrix &&other) noexcept { this->matrixMove(other); }

S21Matrix::~S21Matrix() { this->matrixDelete(); }

void S21Matrix::matrixDelete() {
  if (this->matrix_ != nullptr) {
    for (int i = 0; i < this->rows_; ++i) {
      delete[] this->matrix_[i];
    }
    delete[] this->matrix_;
    this->matrix_ = nullptr;
  }
  this->rows_ = 0;
  this->cols_ = 0;
}

void S21Matrix::sumMatrix(const S21Matrix &other) {
  checkValid(other);
  for (int i = 0; i < this->rows_; ++i) {
    for (int j = 0; j < this->cols_; ++j) {
      this->matrix_[i][j] += other.matrix_[i][j];
    }
  }
}

void S21Matrix::subMatrix(const S21Matrix &other) {
  checkValid(other);
  for (int i = 0; i < this->rows_; ++i) {
    for (int j = 0; j < this->cols_; ++j) {
      this->matrix_[i][j] -= other.matrix_[i][j];
    }
  }
}

void S21Matrix::mulMatrix(const S21Matrix &other) {
  checkValidMult(other);
  S21Matrix m_mul(this->rows_, other.cols_);
  for (int i = 0; i < this->rows_; ++i) {
    for (int j = 0; j < other.cols_; ++j) {
      for (int z = 0; z < this->cols_; ++z) {
        m_mul.matrix_[i][j] += this->matrix_[i][z] * other.matrix_[z][j];
      }
    }
  }
  *this = m_mul;
}

void S21Matrix::mulNumber(const double num) {
  for (int i = 0; i < this->rows_; ++i) {
    for (int j = 0; j < this->cols_; ++j) {
      this->matrix_[i][j] *= num;
    }
  }
}

bool S21Matrix::eqMatrix(const S21Matrix &other) const {
  bool flag = (this == &other);
  if (!flag) {
    flag = (this->rows_ == other.rows_ && this->cols_ == other.cols_);
    if (flag) {
      int num = 0;
      for (int i = 0; i < this->rows_ && num == 0; ++i) {
        num = std::memcmp(other.matrix_[i], this->matrix_[i],
                          cols_ * sizeof(double));
      }
      flag = (num == 0) ? true : false;
    }
  }
  return flag;
}

S21Matrix S21Matrix::transpose() {
  S21Matrix m_trans(this->getCols(), this->getRows());
  for (int i = 0; i < this->getRows(); ++i) {
    for (int j = 0; j < this->getCols(); ++j) {
      m_trans.matrix_[j][i] = this->matrix_[i][j];
    }
  }
  return m_trans;
}

S21Matrix S21Matrix::calcComplements() {
  isSquare();
  S21Matrix complement(this->getRows(), this->getCols());
  for (int i = 0; i < this->rows_; ++i) {
    for (int j = 0; j < this->cols_; ++j) {
      complement.matrix_[i][j] =
          this->minor(i, j).determinant() * pow(-1, i + j);
    }
  }
  return complement;
}

S21Matrix S21Matrix::inverseMatrix() {
  isSquare();
  double det = this->determinant();
  if (fabs(det) == 1e-7) {
    throw std::invalid_argument("determ = 0");
  }
  S21Matrix calc(this->calcComplements().transpose());
  return calc * (1. / det);
}

double S21Matrix::determinant() {
  isSquare();
  double determ = 0.0;
  if (this->cols_ == 1) {
    determ = this->matrix_[0][0];
  } else if (this->cols_ == 2) {
    determ = (this->matrix_[0][0] * this->matrix_[1][1]) -
             (this->matrix_[0][1] * this->matrix_[1][0]);
  } else {
    for (int i = 0; i < this->rows_; ++i) {
      determ +=
          pow(-1, i) * this->matrix_[0][i] * this->minor(0, i).determinant();
    }
  }
  return determ;
}

S21Matrix S21Matrix::minor(const int row, const int col) {
  S21Matrix temp(this->rows_ - 1, this->cols_ - 1);
  for (int i = 0, a = 0; i < this->rows_; ++i) {
    if (i == row) continue;
    for (int j = 0, b = 0; j < this->cols_; ++j) {
      if (j == col) continue;
      temp.matrix_[a][b] = this->matrix_[i][j];
      b++;
    }
    a++;
  }
  return temp;
}

void S21Matrix::copyData(const S21Matrix &other) {
  int row = (other.rows_ < rows_) ? other.rows_ : rows_;
  int col = (other.cols_ < cols_) ? other.cols_ : cols_;
  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < col; ++j) {
      this->matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

double &S21Matrix::operator()(int row, int col) {
  checkIndex(row, col);
  return this->matrix_[row][col];
}

double S21Matrix::operator()(int row, int col) const {
  checkIndex(row, col);
  return this->matrix_[row][col];
}

S21Matrix S21Matrix::operator+(const S21Matrix &other) const {
  S21Matrix m_sum(*this);
  m_sum.sumMatrix(other);
  return m_sum;
}

S21Matrix S21Matrix::operator-(const S21Matrix &other) const {
  S21Matrix m_sub(*this);
  m_sub.subMatrix(other);
  return m_sub;
}

S21Matrix S21Matrix::operator*(const S21Matrix &other) const {
  S21Matrix m_mult(*this);
  m_mult.mulMatrix(other);
  return m_mult;
}

S21Matrix S21Matrix::operator*(double num) const {
  S21Matrix m_mult(*this);
  m_mult.mulNumber(num);
  return m_mult;
}

bool S21Matrix::operator==(const S21Matrix &other) const {
  return this->eqMatrix(other);
}

S21Matrix &S21Matrix::operator=(S21Matrix const &other) {
  if (this != &other) {
    this->matrixCopy(other);
  }
  return *this;
}

S21Matrix &S21Matrix::operator=(S21Matrix &&other) {
  if (this != &other) {
    this->matrixDelete();
    this->matrixMove(other);
  }
  return *this;
}

int S21Matrix::getRows() const { return this->rows_; }

int S21Matrix::getCols() const { return this->cols_; }

void S21Matrix::setRows(int row) { this->resizeMatrix(row, this->cols_); }

void S21Matrix::setCols(int col) { this->resizeMatrix(this->rows_, col); }

void S21Matrix::resizeMatrix(const int row, const int col) {
  S21Matrix result(row, col);
  result.copyData(*this);
  *this = result;
}

S21Matrix &S21Matrix::operator+=(const S21Matrix &other) {
  sumMatrix(other);
  return *this;
}

S21Matrix &S21Matrix::operator-=(const S21Matrix &other) {
  subMatrix(other);
  return *this;
}

S21Matrix &S21Matrix::operator*=(const S21Matrix &other) {
  this->mulMatrix(other);
  return *this;
}

S21Matrix &S21Matrix::operator*=(double num) {
  this->mulNumber(num);
  return *this;
}

void S21Matrix::checkValid(const S21Matrix &other) const {
  if ((this->cols_ != other.cols_) || (this->rows_ != other.rows_))
    throw std::length_error("range_error");
}

void S21Matrix::checkValidMult(const S21Matrix &other) const {
  if (this->cols_ != other.rows_) throw std::length_error("range_error");
}

void S21Matrix::isSquare() const {
  if (this->cols_ != this->rows_) throw std::range_error("Inverse range_error");
}

void S21Matrix::checkIndex(int row, int col) const {
  if (row >= this->rows_ || row < 0 || col >= this->cols_ || col < 0)
    throw std::range_error("operator() const range error");
}