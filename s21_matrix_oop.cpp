#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() {
  this->rows = 1;
  this->columns = 1;
  this->init_matrix(1, 1);
}

S21Matrix::S21Matrix(int _rows, int _columns) {
  if (_rows < 1 || _columns < 1) {
    throw std::logic_error(
        "\nThe number of rows and columns of a matrix cannot be less than 1\n");
  }
  this->rows = _rows;
  this->columns = _columns;
  this->init_matrix(_rows, _columns);
}

S21Matrix::S21Matrix(const S21Matrix& other) {
  this->rows = other.rows;
  this->columns = other.columns;
  this->init_matrix(other.rows, other.columns);
  for (int i = 0; i < other.rows; i++) {
    for (int j = 0; j < other.columns; j++) {
      this->matrix[i][j] = other.matrix[i][j];
    }
  }
}

S21Matrix::S21Matrix(S21Matrix&& other) {
  this->rows = other.rows;
  this->columns = other.columns;
  this->matrix = other.matrix;
  other.rows = other.columns = 0;
  other.matrix = nullptr;
}

S21Matrix::~S21Matrix() { this->free_matr(); }

void S21Matrix::init_matrix(int _rows, int _columns) {
  this->matrix = new double*[_rows];
  for (int i = 0; i < _rows; i++) {
    this->matrix[i] = new double[_columns]{};
  }
}

void S21Matrix::null_obj() {
  this->rows = this->columns = 0;
  this->matrix = nullptr;
}

void S21Matrix::free_matr() {
  for (int i = 0; i < rows; i++) {
    delete[] this->matrix[i];
  }
  delete[] this->matrix;
}

int S21Matrix::GetRows() { return this->rows; }

int S21Matrix::GetColumns() { return this->columns; }

void S21Matrix::SetRows(int _rows) {
  if (_rows < 1) {
    throw std::logic_error(
        "\nThe number of rows of a matrix cannot be less than 1\n");
  }
  S21Matrix B(_rows, this->columns);
  for (int i = 0; i < _rows; i++) {
    for (int j = 0; j < this->columns; j++) {
      if (i >= this->rows) {
        B.matrix[i][j] = 0.0;
      } else {
        B.matrix[i][j] = this->matrix[i][j];
      }
    }
  }
  this->free_matr();
  this->matrix = B.matrix;
  B.null_obj();
  this->rows = _rows;
}

void S21Matrix::SetColumns(int _columns) {
  if (_columns < 1) {
    throw std::logic_error(
        "\nThe number of columns of a matrix cannot be less than 1\n");
  }
  S21Matrix B(this->rows, _columns);
  for (int i = 0; i < this->rows; i++) {
    for (int j = 0; j < _columns; j++) {
      if (j >= this->columns) {
        B.matrix[i][j] = 0.0;
      } else {
        B.matrix[i][j] = this->matrix[i][j];
      }
    }
  }
  this->free_matr();
  this->matrix = B.matrix;
  B.null_obj();
  this->columns = _columns;
}

double** S21Matrix::GetMatrix() { return this->matrix; }

void S21Matrix::SetMatrix(std::string path) {
  std::fstream fp;
  fp.open(path, std::fstream::in);
  if (!fp.is_open()) {
    throw std::invalid_argument("\nCouldn't open a file\n");
  } else {
    std::string str;
    int r, c;
    fp >> r >> c;
    if (r != this->rows || c != this->columns) {
      throw std::logic_error("\nThe number of rows and columns must match\n");
    }
    getline(fp, str);
    for (int i = 0; i < this->rows; i++) {
      for (int j = 0; j < this->columns; j++) {
        fp >> this->matrix[i][j];
      }
      getline(fp, str);
    }
  }
  fp.close();
}

bool S21Matrix::eq_matrix(const S21Matrix& other) {
  bool result = 1;
  if (this->rows != other.rows || this->columns != other.columns) {
    result = 0;
  } else {
    for (int i = 0; i < this->rows; i++) {
      for (int j = 0; j < this->columns; j++) {
        if (fabs(this->matrix[i][j] - other.matrix[i][j]) >= 0.0000001) {
          result = 0;
        }
      }
    }
  }
  return result;
}

void S21Matrix::sum_matrix(const S21Matrix& other) {
  if (this->rows != other.rows || this->columns != other.columns) {
    throw std::logic_error("\nThe number of rows and columns must match\n");
  } else {
    for (int i = 0; i < this->rows; i++) {
      for (int j = 0; j < this->columns; j++) {
        this->matrix[i][j] += other.matrix[i][j];
      }
    }
  }
}

void S21Matrix::sub_matrix(const S21Matrix& other) {
  if (this->rows != other.rows || this->columns != other.columns) {
    throw std::logic_error("\nThe number of rows and columns must match\n");
  } else {
    for (int i = 0; i < this->rows; i++) {
      for (int j = 0; j < this->columns; j++) {
        this->matrix[i][j] -= other.matrix[i][j];
      }
    }
  }
}

void S21Matrix::mul_number(const double num) {
  for (int i = 0; i < this->rows; i++) {
    for (int j = 0; j < this->columns; j++) {
      this->matrix[i][j] *= num;
    }
  }
}

void S21Matrix::mul_matrix(const S21Matrix& other) {
  int row, col;
  if (this->columns != other.rows) {
    throw std::logic_error(
        "\nThe number of columns of the first matrix must match the number of "
        "rows of the second matrix\n");
  } else {
    row = this->rows, col = other.columns;
    S21Matrix B(this->rows, other.columns);
    for (int i = 0; i < this->rows; i++) {
      for (int j = 0; j < other.columns; j++) {
        for (int k = 0; k < this->columns; k++) {
          B.matrix[i][j] += this->matrix[i][k] * other.matrix[k][j];
        }
      }
    }
    this->free_matr();
    this->matrix = B.matrix;
    B.null_obj();
    this->rows = row;
    this->columns = col;
  }
}

S21Matrix S21Matrix::transpose() {
  S21Matrix B(this->columns, this->rows);
  for (int i = 0; i < this->rows; i++) {
    for (int j = 0; j < this->columns; j++) {
      B.matrix[j][i] = this->matrix[i][j];
    }
  }
  return B;
}

S21Matrix S21Matrix::get_matrix_for_minor(const S21Matrix& other, int rows,
                                          int columns) {
  for (int i = 0; i < other.rows; i++) {
    for (int j = 0; j < other.columns; j++) {
      if (i != rows && j != columns) {
        if (j > columns && i > rows) {
          this->matrix[i - 1][j - 1] = other.matrix[i][j];
        } else if (j < columns && i < rows) {
          this->matrix[i][j] = other.matrix[i][j];
        } else if (j > columns && i < rows) {
          this->matrix[i][j - 1] = other.matrix[i][j];
        } else if (j < columns && i > rows) {
          this->matrix[i - 1][j] = other.matrix[i][j];
        }
      }
    }
  }
  return *this;
}

double S21Matrix::determinant() {
  double res = 0.0;
  if (this->rows != this->columns) {
    throw std::logic_error("\nThe number of rows and columns must match\n");
  } else {
    for (int j = 0; j < this->columns; j++) {
      if (this->rows == 1) {
        res = this->matrix[0][0];
      } else if (this->rows == 2) {
        res = this->matrix[0][0] * this->matrix[1][1] -
              this->matrix[1][0] * this->matrix[0][1];
      } else {
        S21Matrix B(this->rows - 1, this->columns - 1);
        B.get_matrix_for_minor(*this, 0, j);
        res += this->matrix[0][j] * pow(-1, j) * B.determinant();
      }
    }
  }
  return res;
}

S21Matrix S21Matrix::calc_complements() {
  if (this->rows != this->columns) {
    throw std::logic_error("\nThe number of rows and columns must match\n");
  }
  S21Matrix B(this->rows, this->columns);
  S21Matrix C(this->rows - 1, this->columns - 1);
  for (int i = 0; i < this->rows; i++) {
    for (int j = 0; j < this->columns; j++) {
      C.get_matrix_for_minor(*this, i, j);
      B.matrix[i][j] = C.determinant() * pow(-1, i + j);
    }
  }
  return B;
}

S21Matrix S21Matrix::inverse_matrix() {
  if (this->rows != this->columns) {
    throw std::logic_error("\nThe number of rows and columns must match\n");
  } else if (this->determinant() == 0.0) {
    throw std::logic_error(
        "\nThe number of determinant cannot be equal to 0\n");
  }
  const double det = 1 / this->determinant();
  S21Matrix B(this->calc_complements());
  S21Matrix C(B.transpose());
  C.mul_number(det);
  return C;
}

S21Matrix S21Matrix::operator+(const S21Matrix& other) {
  S21Matrix res(*this);
  res.sum_matrix(other);
  return res;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) {
  S21Matrix res(*this);
  res.sub_matrix(other);
  return res;
}

S21Matrix S21Matrix::operator*(double num) {
  S21Matrix res(*this);
  res.mul_number(num);
  return res;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) {
  S21Matrix res(*this);
  res.mul_matrix(other);
  return res;
}

S21Matrix operator*(double num, const S21Matrix& other) {
  S21Matrix res(other);
  res.mul_number(num);
  return res;
}

bool S21Matrix::operator==(const S21Matrix& other) {
  return this->eq_matrix(other);
}

void S21Matrix::operator+=(const S21Matrix& other) { this->sum_matrix(other); }

void S21Matrix::operator-=(const S21Matrix& other) { this->sub_matrix(other); }

void S21Matrix::operator*=(double num) { this->mul_number(num); }

void S21Matrix::operator*=(const S21Matrix& other) { this->mul_matrix(other); }

void S21Matrix::operator=(S21Matrix&& other) { std::swap(*this, other); }

double& S21Matrix::operator()(int row, int col) {
  if (row >= this->rows || col >= this->columns) {
    throw std::out_of_range("\nIndex numbers outside the matrix\n");
  }
  return this->matrix[row][col];
}