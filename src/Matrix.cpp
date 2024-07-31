// Matrix.cpp
#include <stdexcept>
#include <vector>

class Matrix {
public:
  Matrix(int rows, int cols)
      : rows_(rows), cols_(cols), data_(rows, std::vector<int>(cols, 0)) {}

  int &at(int row, int col) {
    if (row < 0 || row >= rows_ || col < 0 || col >= cols_) {
      throw std::out_of_range("Matrix index out of range");
    }
    return data_[row][col];
  }

  Matrix operator+(const Matrix &other) const {
    if (rows_ != other.rows_ || cols_ != other.cols_) {
      throw std::invalid_argument(
          "Matrices dimensions do not match for addition");
    }
    Matrix result(rows_, cols_);
    for (int i = 0; i < rows_; ++i) {
      for (int j = 0; j < cols_; ++j) {
        result.data_[i][j] = data_[i][j] + other.data_[i][j];
      }
    }
    return result;
  }

  Matrix operator-(const Matrix &other) const {
    if (rows_ != other.rows_ || cols_ != other.cols_) {
      throw std::invalid_argument(
          "Matrices dimensions do not match for subtraction");
    }
    Matrix result(rows_, cols_);
    for (int i = 0; i < rows_; ++i) {
      for (int j = 0; j < cols_; ++j) {
        result.data_[i][j] = data_[i][j] - other.data_[i][j];
      }
    }
    return result;
  }

  Matrix operator*(const Matrix &other) const {
    if (cols_ != other.rows_) {
      throw std::invalid_argument(
          "Matrices dimensions do not match for multiplication");
    }
    Matrix result(rows_, other.cols_);
    for (int i = 0; i < rows_; ++i) {
      for (int j = 0; j < other.cols_; ++j) {
        for (int k = 0; k < cols_; ++k) {
          result.data_[i][j] += data_[i][k] * other.data_[k][j];
        }
      }
    }
    return result;
  }

private:
  int rows_, cols_;
  std::vector<std::vector<int>> data_;
};
