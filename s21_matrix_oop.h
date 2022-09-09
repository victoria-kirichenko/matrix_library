#ifndef SRC_S21_MATRIX_OOP_H_
#define SRC_S21_MATRIX_OOP_H_

#include <cmath>
#include <exception>
#include <fstream>
#include <iostream>
#include <string>

class S21Matrix {
 public:
  S21Matrix();
  S21Matrix(int _rows, int _columns);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other);
  ~S21Matrix();

  int GetRows();
  int GetColumns();
  double** GetMatrix();
  void SetRows(int _rows);
  void SetColumns(int _columns);
  void SetMatrix(std::string path);

  bool eq_matrix(const S21Matrix& other);
  void sum_matrix(const S21Matrix& other);
  void sub_matrix(const S21Matrix& other);
  void mul_number(const double num);
  void mul_matrix(const S21Matrix& other);
  S21Matrix transpose();
  S21Matrix calc_complements();
  double determinant();
  S21Matrix inverse_matrix();

  S21Matrix operator+(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other);
  S21Matrix operator*(const S21Matrix& other);
  S21Matrix operator*(double num);
  friend S21Matrix operator*(double num, const S21Matrix& other);
  bool operator==(const S21Matrix& other);
  void operator+=(const S21Matrix& other);
  void operator-=(const S21Matrix& other);
  void operator*=(const S21Matrix& other);
  void operator*=(double num);
  void operator=(S21Matrix&& other);
  double& operator()(int row, int col);

  S21Matrix get_matrix_for_minor(const S21Matrix& other, int rows, int columns);

 private:
  int rows, columns;
  double** matrix;
  void init_matrix(int _rows, int _columns);
  void null_obj();
  void free_matr();
};

#endif  //  SRC_S21_MATRIX_OOP_H_
