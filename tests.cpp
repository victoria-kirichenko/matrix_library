#include <gtest/gtest.h>

#include "s21_matrix_oop.h"

TEST(constructor, constructor_default) {
  S21Matrix A;
  EXPECT_TRUE(A.GetRows() == 1);
  EXPECT_TRUE(A.GetColumns() == 1);
  EXPECT_EQ(A(0, 0), 0.0);
}

TEST(constructor, constructor_parametr) {
  EXPECT_THROW(S21Matrix A(1, 0), std::logic_error);
  S21Matrix B(4, 3);
  EXPECT_TRUE(B.GetRows() == 4);
  EXPECT_TRUE(B.GetColumns() == 3);
  for (int i = 0; i < B.GetRows(); i++) {
    for (int j = 0; j < B.GetColumns(); j++) {
      EXPECT_EQ(B(i, j), 0.0);
    }
  }
}

TEST(constructor, constructor_copy) {
  S21Matrix A(2, 2);
  A.SetMatrix("text_files/test.txt");
  S21Matrix B(A);
  EXPECT_TRUE(B.GetRows() == 2);
  EXPECT_TRUE(B.GetColumns() == 2);
  for (int i = 0; i < B.GetRows(); i++) {
    for (int j = 0; j < B.GetColumns(); j++) {
      EXPECT_EQ(B(i, j), A(i, j));
    }
  }
}

TEST(constructor, constructor_move) {
  S21Matrix A(2, 2);
  A.SetMatrix("text_files/test.txt");
  S21Matrix B(A);
  EXPECT_TRUE(B.GetRows() == 2);
  EXPECT_TRUE(B.GetColumns() == 2);
  for (int i = 0; i < B.GetRows(); i++) {
    for (int j = 0; j < B.GetColumns(); j++) {
      EXPECT_EQ(B(i, j), A(i, j));
    }
  }
}

TEST(getters, get_rows) {
  S21Matrix A(10, 2);
  EXPECT_TRUE(A.GetRows() == 10);
}

TEST(getters, get_columns) {
  S21Matrix A(10, 31);
  EXPECT_TRUE(A.GetColumns() == 31);
}

TEST(getters, get_matrix) {
  S21Matrix A(2, 2);
  A.SetMatrix("text_files/test.txt");
  double** matrix = A.GetMatrix();
  EXPECT_TRUE(matrix[0][0] == 1.0);
  EXPECT_TRUE(matrix[0][1] == 2.0);
  EXPECT_TRUE(matrix[1][0] == 3.0);
  EXPECT_TRUE(matrix[1][1] == 4.0);
}

TEST(setters, set_rows_1) {
  S21Matrix A(3, 3);
  A.SetMatrix("text_files/test1.txt");
  A.SetRows(2);
  EXPECT_TRUE(A.GetRows() == 2);
  EXPECT_TRUE(A.GetColumns() == 3);
  EXPECT_TRUE(A(0, 0) == 1.0);
  EXPECT_TRUE(A(0, 1) == 2.0);
  EXPECT_TRUE(A(0, 2) == 3.0);
  EXPECT_TRUE(A(1, 0) == 4.0);
  EXPECT_TRUE(A(1, 1) == 5.0);
  EXPECT_TRUE(A(1, 2) == 6.0);
}

TEST(setters, set_rows_2) {
  S21Matrix A(3, 3);
  A.SetMatrix("text_files/test1.txt");
  A.SetRows(4);
  EXPECT_TRUE(A.GetRows() == 4);
  EXPECT_TRUE(A.GetColumns() == 3);
  EXPECT_TRUE(A(0, 0) == 1.0);
  EXPECT_TRUE(A(0, 1) == 2.0);
  EXPECT_TRUE(A(0, 2) == 3.0);
  EXPECT_TRUE(A(1, 0) == 4.0);
  EXPECT_TRUE(A(1, 1) == 5.0);
  EXPECT_TRUE(A(1, 2) == 6.0);
  EXPECT_TRUE(A(2, 0) == 7.0);
  EXPECT_TRUE(A(2, 1) == 8.0);
  EXPECT_TRUE(A(2, 2) == 9.0);
  EXPECT_TRUE(A(3, 0) == 0.0);
  EXPECT_TRUE(A(3, 1) == 0.0);
  EXPECT_TRUE(A(3, 2) == 0.0);
}

TEST(setters, set_rows_3) {
  S21Matrix A(3, 3);
  A.SetMatrix("text_files/test1.txt");
  EXPECT_THROW(A.SetRows(0), std::logic_error);
}

TEST(setters, set_columns_1) {
  S21Matrix A(3, 3);
  A.SetMatrix("text_files/test1.txt");
  A.SetColumns(2);
  EXPECT_TRUE(A.GetRows() == 3);
  EXPECT_TRUE(A.GetColumns() == 2);
  EXPECT_TRUE(A(0, 0) == 1.0);
  EXPECT_TRUE(A(0, 1) == 2.0);
  EXPECT_TRUE(A(1, 0) == 4.0);
  EXPECT_TRUE(A(1, 1) == 5.0);
  EXPECT_TRUE(A(2, 0) == 7.0);
  EXPECT_TRUE(A(2, 1) == 8.0);
}

TEST(setters, set_columns_2) {
  S21Matrix A(3, 3);
  A.SetMatrix("text_files/test1.txt");
  A.SetColumns(4);
  EXPECT_TRUE(A.GetRows() == 3);
  EXPECT_TRUE(A.GetColumns() == 4);
  EXPECT_TRUE(A(0, 0) == 1.0);
  EXPECT_TRUE(A(0, 1) == 2.0);
  EXPECT_TRUE(A(0, 2) == 3.0);
  EXPECT_TRUE(A(0, 3) == 0.0);
  EXPECT_TRUE(A(1, 0) == 4.0);
  EXPECT_TRUE(A(1, 1) == 5.0);
  EXPECT_TRUE(A(1, 2) == 6.0);
  EXPECT_TRUE(A(1, 3) == 0.0);
  EXPECT_TRUE(A(2, 0) == 7.0);
  EXPECT_TRUE(A(2, 1) == 8.0);
  EXPECT_TRUE(A(2, 2) == 9.0);
  EXPECT_TRUE(A(2, 3) == 0.0);
}

TEST(setters, set_columns_3) {
  S21Matrix A(3, 3);
  A.SetMatrix("text_files/test1.txt");
  EXPECT_THROW(A.SetColumns(0), std::logic_error);
}

TEST(setters, set_matrix_1) {
  S21Matrix A(3, 3);
  EXPECT_THROW(A.SetMatrix("lala.txt"), std::invalid_argument);
}

TEST(setters, set_matrix_2) {
  S21Matrix A(3, 3);
  EXPECT_THROW(A.SetMatrix("text_files/test.txt"), std::logic_error);
}

TEST(eq_matrix, test_1) {
  S21Matrix A(2, 2);
  S21Matrix B(2, 2);
  A.SetMatrix("text_files/test.txt");
  B.SetMatrix("text_files/test.txt");
  EXPECT_TRUE(A.eq_matrix(B));
}

TEST(eq_matrix, test_2) {
  S21Matrix A(2, 2);
  S21Matrix B(3, 3);
  A.SetMatrix("text_files/test.txt");
  B.SetMatrix("text_files/test1.txt");
  EXPECT_FALSE(A.eq_matrix(B));
}

TEST(sum_matrix, test_1) {
  S21Matrix A(2, 2);
  S21Matrix B(2, 2);
  A.SetMatrix("text_files/test.txt");
  B.SetMatrix("text_files/test.txt");
  A.sum_matrix(B);
  EXPECT_TRUE(A(0, 0) == 2.0);
  EXPECT_TRUE(A(0, 1) == 4.0);
  EXPECT_TRUE(A(1, 0) == 6.0);
  EXPECT_TRUE(A(1, 1) == 8.0);
}

TEST(sum_matrix, test_2) {
  S21Matrix A(2, 2);
  S21Matrix B(3, 3);
  A.SetMatrix("text_files/test.txt");
  B.SetMatrix("text_files/test1.txt");
  EXPECT_THROW(A.sum_matrix(B), std::logic_error);
}

TEST(sub_matrix, test_1) {
  S21Matrix A(2, 2);
  S21Matrix B(2, 2);
  A.SetMatrix("text_files/test.txt");
  B.SetMatrix("text_files/test.txt");
  A.sub_matrix(B);
  EXPECT_TRUE(A(0, 0) == 0.0);
  EXPECT_TRUE(A(0, 1) == 0.0);
  EXPECT_TRUE(A(1, 0) == 0.0);
  EXPECT_TRUE(A(1, 1) == 0.0);
}

TEST(sub_matrix, test_2) {
  S21Matrix A(2, 2);
  S21Matrix B(3, 2);
  A.SetMatrix("text_files/test.txt");
  B.SetMatrix("text_files/test2.txt");
  EXPECT_THROW(A.sub_matrix(B), std::logic_error);
}

TEST(mul_number, test_1) {
  S21Matrix A(3, 2);
  A.SetMatrix("text_files/test2.txt");
  A.mul_number(2);
  EXPECT_TRUE(A(0, 0) == 5.0);
  EXPECT_TRUE(A(0, 1) == 8.6);
  EXPECT_TRUE(A(1, 0) == 11.2);
  EXPECT_TRUE(A(1, 1) == 2.0);
  EXPECT_TRUE(A(2, 0) == 4.0);
  EXPECT_TRUE(A(2, 1) == 4.0);
}

TEST(mul_matrix, test_1) {
  S21Matrix A(3, 3);
  S21Matrix B(3, 2);
  A.SetMatrix("text_files/test1.txt");
  B.SetMatrix("text_files/test2.txt");
  A.mul_matrix(B);
  EXPECT_TRUE(A.GetRows() == 3);
  EXPECT_TRUE(A.GetColumns() == 2);
  ASSERT_LE(fabs(19.7 - A(0, 0)), 1e-7);
  ASSERT_LE(fabs(12.3 - A(0, 1)), 1e-7);
  ASSERT_LE(fabs(50 - A(1, 0)), 1e-7);
  ASSERT_LE(fabs(34.2 - A(1, 1)), 1e-7);
  ASSERT_LE(fabs(80.3 - A(2, 0)), 1e-7);
  ASSERT_LE(fabs(56.1 - A(2, 1)), 1e-7);
}

TEST(mul_matrix, test_2) {
  S21Matrix A(3, 3);
  S21Matrix B(2, 2);
  A.SetMatrix("text_files/test1.txt");
  B.SetMatrix("text_files/test.txt");
  EXPECT_THROW(A.mul_matrix(B), std::logic_error);
}

TEST(transpose, test_1) {
  S21Matrix A(2, 2);
  A.SetMatrix("text_files/test.txt");
  S21Matrix B(A.transpose());
  EXPECT_TRUE(B(0, 0) == 1.0);
  EXPECT_TRUE(B(0, 1) == 3.0);
  EXPECT_TRUE(B(1, 0) == 2.0);
  EXPECT_TRUE(B(1, 1) == 4.0);
}

TEST(determinant, test_1) {
  S21Matrix A(3, 3);
  A.SetMatrix("text_files/test1.txt");
  double det = A.determinant();
  ASSERT_EQ(det, 0);
}

TEST(determinant, test_2) {
  S21Matrix A(2, 2);
  A.SetMatrix("text_files/test.txt");
  double det = A.determinant();
  ASSERT_EQ(det, -2);
}

TEST(determinant, test_3) {
  S21Matrix A(3, 2);
  A.SetMatrix("text_files/test2.txt");
  EXPECT_THROW(A.determinant(), std::logic_error);
}

TEST(calc_complements, test_1) {
  S21Matrix A(3, 3);
  A.SetMatrix("text_files/test_calc_compl.txt");
  S21Matrix B(A.calc_complements());
  EXPECT_TRUE(B(0, 0) == 0.0);
  EXPECT_TRUE(B(0, 1) == 10.0);
  EXPECT_TRUE(B(0, 2) == -20.0);
  EXPECT_TRUE(B(1, 0) == 4.0);
  EXPECT_TRUE(B(1, 1) == -14.0);
  EXPECT_TRUE(B(1, 2) == 8.0);
  EXPECT_TRUE(B(2, 0) == -8.0);
  EXPECT_TRUE(B(2, 1) == -2.0);
  EXPECT_TRUE(B(2, 2) == 4.0);
}

TEST(calc_complements, test_2) {
  S21Matrix A(3, 2);
  A.SetMatrix("text_files/test2.txt");
  EXPECT_THROW(A.calc_complements(), std::logic_error);
}

TEST(inverse_matrix, test_1) {
  S21Matrix A(3, 3);
  A.SetMatrix("text_files/test_inverse.txt");
  S21Matrix B(A.inverse_matrix());
  EXPECT_TRUE(B(0, 0) == 1.0);
  EXPECT_TRUE(B(0, 1) == -1.0);
  EXPECT_TRUE(B(0, 2) == 1.0);
  EXPECT_TRUE(B(1, 0) == -38.0);
  EXPECT_TRUE(B(1, 1) == 41.0);
  EXPECT_TRUE(B(1, 2) == -34.0);
  EXPECT_TRUE(B(2, 0) == 27.0);
  EXPECT_TRUE(B(2, 1) == -29.0);
  EXPECT_TRUE(B(2, 2) == 24.0);
}

TEST(inverse_matrix, test_2) {
  S21Matrix A(3, 2);
  A.SetMatrix("text_files/test2.txt");
  EXPECT_THROW(A.inverse_matrix(), std::logic_error);
}

TEST(operator, plus_1) {
  S21Matrix A(2, 2);
  S21Matrix B(2, 2);
  A.SetMatrix("text_files/test.txt");
  B.SetMatrix("text_files/test.txt");
  S21Matrix C = A + B;
  EXPECT_TRUE(C(0, 0) == 2.0);
  EXPECT_TRUE(C(0, 1) == 4.0);
  EXPECT_TRUE(C(1, 0) == 6.0);
  EXPECT_TRUE(C(1, 1) == 8.0);
}

TEST(operator, plus_2) {
  S21Matrix A(2, 2);
  S21Matrix B(3, 3);
  A.SetMatrix("text_files/test.txt");
  B.SetMatrix("text_files/test1.txt");
  EXPECT_THROW(A + B, std::logic_error);
}

TEST(operator, minus_1) {
  S21Matrix A(2, 2);
  S21Matrix B(2, 2);
  A.SetMatrix("text_files/test.txt");
  B.SetMatrix("text_files/test.txt");
  S21Matrix C = A - B;
  EXPECT_TRUE(C(0, 0) == 0.0);
  EXPECT_TRUE(C(0, 1) == 0.0);
  EXPECT_TRUE(C(1, 0) == 0.0);
  EXPECT_TRUE(C(1, 1) == 0.0);
}

TEST(operator, minus_2) {
  S21Matrix A(2, 2);
  S21Matrix B(3, 2);
  A.SetMatrix("text_files/test.txt");
  B.SetMatrix("text_files/test2.txt");
  EXPECT_THROW(A - B, std::logic_error);
}

TEST(operator, mul_number_1) {
  S21Matrix A(3, 2);
  A.SetMatrix("text_files/test2.txt");
  S21Matrix B = A * 2;
  EXPECT_TRUE(B(0, 0) == 5.0);
  EXPECT_TRUE(B(0, 1) == 8.6);
  EXPECT_TRUE(B(1, 0) == 11.2);
  EXPECT_TRUE(B(1, 1) == 2.0);
  EXPECT_TRUE(B(2, 0) == 4.0);
  EXPECT_TRUE(B(2, 1) == 4.0);
}

TEST(operator, mul_number_2) {
  S21Matrix A(3, 2);
  A.SetMatrix("text_files/test2.txt");
  S21Matrix B = 2 * A;
  EXPECT_TRUE(B(0, 0) == 5.0);
  EXPECT_TRUE(B(0, 1) == 8.6);
  EXPECT_TRUE(B(1, 0) == 11.2);
  EXPECT_TRUE(B(1, 1) == 2.0);
  EXPECT_TRUE(B(2, 0) == 4.0);
  EXPECT_TRUE(B(2, 1) == 4.0);
}

TEST(operator, mul_matrix_1) {
  S21Matrix A(3, 3);
  S21Matrix B(3, 2);
  A.SetMatrix("text_files/test1.txt");
  B.SetMatrix("text_files/test2.txt");
  S21Matrix C = A * B;
  EXPECT_TRUE(C.GetRows() == 3);
  EXPECT_TRUE(C.GetColumns() == 2);
  ASSERT_LE(fabs(19.7 - C(0, 0)), 1e-7);
  ASSERT_LE(fabs(12.3 - C(0, 1)), 1e-7);
  ASSERT_LE(fabs(50 - C(1, 0)), 1e-7);
  ASSERT_LE(fabs(34.2 - C(1, 1)), 1e-7);
  ASSERT_LE(fabs(80.3 - C(2, 0)), 1e-7);
  ASSERT_LE(fabs(56.1 - C(2, 1)), 1e-7);
}

TEST(operator, mul_matrix_2) {
  S21Matrix A(3, 3);
  S21Matrix B(2, 2);
  A.SetMatrix("text_files/test1.txt");
  B.SetMatrix("text_files/test.txt");
  EXPECT_THROW(A * B, std::logic_error);
}

TEST(operator, equal_1) {
  S21Matrix A(2, 2);
  S21Matrix B(2, 2);
  A.SetMatrix("text_files/test.txt");
  B.SetMatrix("text_files/test.txt");
  EXPECT_TRUE(A == B);
}

TEST(operator, equal_2) {
  S21Matrix A(2, 2);
  S21Matrix B(3, 3);
  A.SetMatrix("text_files/test.txt");
  B.SetMatrix("text_files/test1.txt");
  EXPECT_FALSE(A == B);
}

TEST(operator, plusravno_1) {
  S21Matrix A(2, 2);
  S21Matrix B(2, 2);
  A.SetMatrix("text_files/test.txt");
  B.SetMatrix("text_files/test.txt");
  A += B;
  EXPECT_TRUE(A(0, 0) == 2.0);
  EXPECT_TRUE(A(0, 1) == 4.0);
  EXPECT_TRUE(A(1, 0) == 6.0);
  EXPECT_TRUE(A(1, 1) == 8.0);
}

TEST(operator, plusravno_2) {
  S21Matrix A(2, 2);
  S21Matrix B(3, 3);
  A.SetMatrix("text_files/test.txt");
  B.SetMatrix("text_files/test1.txt");
  EXPECT_THROW(A += B, std::logic_error);
}

TEST(operator, minusravno_1) {
  S21Matrix A(2, 2);
  S21Matrix B(2, 2);
  A.SetMatrix("text_files/test.txt");
  B.SetMatrix("text_files/test.txt");
  A -= B;
  EXPECT_TRUE(A(0, 0) == 0.0);
  EXPECT_TRUE(A(0, 1) == 0.0);
  EXPECT_TRUE(A(1, 0) == 0.0);
  EXPECT_TRUE(A(1, 1) == 0.0);
}

TEST(operator, minusravno_2) {
  S21Matrix A(2, 2);
  S21Matrix B(3, 2);
  A.SetMatrix("text_files/test.txt");
  B.SetMatrix("text_files/test2.txt");
  EXPECT_THROW(A -= B, std::logic_error);
}

TEST(operator, mulravno_number_1) {
  S21Matrix A(3, 2);
  A.SetMatrix("text_files/test2.txt");
  A *= 2;
  EXPECT_TRUE(A(0, 0) == 5.0);
  EXPECT_TRUE(A(0, 1) == 8.6);
  EXPECT_TRUE(A(1, 0) == 11.2);
  EXPECT_TRUE(A(1, 1) == 2.0);
  EXPECT_TRUE(A(2, 0) == 4.0);
  EXPECT_TRUE(A(2, 1) == 4.0);
}

TEST(operator, mulravno_matrix_1) {
  S21Matrix A(3, 3);
  S21Matrix B(3, 2);
  A.SetMatrix("text_files/test1.txt");
  B.SetMatrix("text_files/test2.txt");
  A *= B;
  EXPECT_TRUE(A.GetRows() == 3);
  EXPECT_TRUE(A.GetColumns() == 2);
  ASSERT_LE(fabs(19.7 - A(0, 0)), 1e-7);
  ASSERT_LE(fabs(12.3 - A(0, 1)), 1e-7);
  ASSERT_LE(fabs(50 - A(1, 0)), 1e-7);
  ASSERT_LE(fabs(34.2 - A(1, 1)), 1e-7);
  ASSERT_LE(fabs(80.3 - A(2, 0)), 1e-7);
  ASSERT_LE(fabs(56.1 - A(2, 1)), 1e-7);
}

TEST(operator, mulravno_matrix_2) {
  S21Matrix A(3, 3);
  S21Matrix B(2, 2);
  A.SetMatrix("text_files/test1.txt");
  B.SetMatrix("text_files/test.txt");
  EXPECT_THROW(A *= B, std::logic_error);
}

TEST(operator, ravno) {
  S21Matrix A(3, 3);
  A.SetMatrix("text_files/test1.txt");
  S21Matrix B = A;
  EXPECT_TRUE(B.GetRows() == 3);
  EXPECT_TRUE(B.GetColumns() == 3);
  ASSERT_EQ(B(0, 0), 1.0);
  ASSERT_EQ(B(0, 1), 2.0);
  ASSERT_EQ(B(0, 2), 3.0);
  ASSERT_EQ(B(1, 0), 4.0);
  ASSERT_EQ(B(1, 1), 5.0);
  ASSERT_EQ(B(1, 2), 6.0);
  ASSERT_EQ(B(2, 0), 7.0);
  ASSERT_EQ(B(2, 1), 8.0);
  ASSERT_EQ(B(2, 2), 9.0);
}

TEST(operator, index) {
  S21Matrix A(3, 3);
  A.SetMatrix("text_files/test1.txt");
  EXPECT_THROW(A(4, 1), std::logic_error);
}
