#include <gtest/gtest.h>

#include "s21_matrix_oop.h"

//
// Created by Karlene Gyles
//

class MatrixTest : public testing::Test {
 protected:
  S21Matrix *matrix_1x1;
  S21Matrix *matrix_3x3;
  S21Matrix *matrix_5x5;
  S21Matrix *s_21_matrix_3x4;
  S21Matrix *s_21_matrix_3x3;
  S21Matrix *s_21_matrix_0x0;
  S21Matrix *s_21_matrix_result;

  void SetUp() {
    int temp_value = 0;

    matrix_1x1 = new S21Matrix(1, 1);
    matrix_1x1->operator()(0, 0) = temp_value;

    matrix_3x3 = new S21Matrix();
    for (int i = 0; i < matrix_3x3->getRows(); i++) {
      for (int j = 0; j < matrix_3x3->getCols(); j++) {
        matrix_3x3->operator()(i, j) = temp_value;
        temp_value++;
      }
    }

    temp_value = 0;
    matrix_5x5 = new S21Matrix(5, 5);
    for (int i = 0; i < matrix_5x5->getRows(); i++) {
      for (int j = 0; j < matrix_5x5->getCols(); j++) {
        matrix_5x5->operator()(i, j) = temp_value;
        temp_value++;
      }
    }
    s_21_matrix_3x4 = new S21Matrix(3, 4);
    s_21_matrix_3x4->operator()(0, 0) = 1;
    s_21_matrix_3x4->operator()(0, 1) = 2;
    s_21_matrix_3x4->operator()(0, 2) = 3;
    s_21_matrix_3x4->operator()(0, 3) = 4;
    s_21_matrix_3x4->operator()(1, 0) = 5;
    s_21_matrix_3x4->operator()(1, 1) = 6;
    s_21_matrix_3x4->operator()(1, 2) = 7;
    s_21_matrix_3x4->operator()(1, 3) = 8;
    s_21_matrix_3x4->operator()(2, 0) = 9;
    s_21_matrix_3x4->operator()(2, 1) = 10;
    s_21_matrix_3x4->operator()(2, 2) = 11;
    s_21_matrix_3x4->operator()(2, 3) = 12;

    s_21_matrix_3x3 = new S21Matrix();
    s_21_matrix_3x3->operator()(0, 0) = 8;
    s_21_matrix_3x3->operator()(0, 1) = 2;
    s_21_matrix_3x3->operator()(0, 2) = 4;
    s_21_matrix_3x3->operator()(1, 0) = 4;
    s_21_matrix_3x3->operator()(1, 1) = 6;
    s_21_matrix_3x3->operator()(1, 2) = 6;
    s_21_matrix_3x3->operator()(2, 0) = 4;
    s_21_matrix_3x3->operator()(2, 1) = 8;
    s_21_matrix_3x3->operator()(2, 2) = 8;
  }

  void TearDown() {
    delete matrix_1x1;
    delete matrix_3x3;
    delete matrix_5x5;
    delete s_21_matrix_3x4;
    delete s_21_matrix_3x3;
  }
};

// TEST CONSTRUCTOR ERROR
TEST_F(MatrixTest, fail_constructor_1) {
  EXPECT_THROW(S21Matrix matrix(-1, -1), std::range_error);
}

TEST_F(MatrixTest, fail_constructor_2) {
  EXPECT_THROW(S21Matrix matrix(0, 0), std::range_error);
}

TEST_F(MatrixTest, fail_constructor_3) {
  EXPECT_THROW(S21Matrix matrix(-1, 1), std::range_error);
}

TEST_F(MatrixTest, fail_constructor_4) {
  EXPECT_THROW(S21Matrix matrix(1, -1), std::range_error);
}

////TEST SUM MATRIX ERROR
TEST_F(MatrixTest, sum_error_0) {
  EXPECT_THROW(matrix_1x1->sumMatrix(*matrix_3x3), std::length_error);
}

////TEST SUB MATRIX ERROR
TEST_F(MatrixTest, sub_error_0) {
  EXPECT_THROW(matrix_1x1->subMatrix(*matrix_3x3), std::length_error);
}

////TEST MUL MATRIX ERROR
TEST_F(MatrixTest, mul_error_0) {
  EXPECT_THROW(matrix_1x1->mulMatrix(*matrix_3x3), std::length_error);
}

////TEST determinant ERROR
TEST_F(MatrixTest, determinant_error_0) {
  S21Matrix matrix_error(2, 3);
  EXPECT_THROW(matrix_error.determinant(), std::range_error);
}

////TEST INVERSE MATRIX ERROR
////TEST OPERATOR + ERROR
TEST_F(MatrixTest, opeator_sum_error_0) {
  EXPECT_THROW(*matrix_1x1 + *matrix_3x3, std::length_error);
}

////TEST OPERATOR - ERROR
TEST_F(MatrixTest, operator_sub_error_0) {
  EXPECT_THROW(*matrix_1x1 - *matrix_3x3, std::length_error);
}

////TEST OPERATOR * ERROR
TEST_F(MatrixTest, operator_mult_error_0) {
  EXPECT_THROW(*matrix_1x1 * *matrix_3x3, std::length_error);
}

////TEST OPERATOR += ERROR
TEST_F(MatrixTest, operator_sum_ass_error_0) {
  EXPECT_THROW(*matrix_1x1 += *matrix_3x3, std::length_error);
}

////TEST OPERATOR -= ERROR
TEST_F(MatrixTest, operator_sub_ass_error_0) {
  EXPECT_THROW(*matrix_1x1 -= *matrix_3x3, std::length_error);
}

////TEST OPERATOR () ERROR
TEST_F(MatrixTest, operator_bracket_error_0) {
  EXPECT_THROW(matrix_1x1->operator()(0, -1), std::range_error);
}

TEST_F(MatrixTest, operator_bracket_error_1) {
  EXPECT_THROW(matrix_1x1->operator()(-1, 0), std::range_error);
}

TEST_F(MatrixTest, operator_bracket_error_2) {
  EXPECT_THROW(matrix_1x1->operator()(-1, -1), std::range_error);
}

TEST_F(MatrixTest, operator_bracket_error_6) {
  EXPECT_THROW(matrix_1x1->operator()(1, 0), std::range_error);
}

TEST_F(MatrixTest, operator_bracket_error_4) {
  EXPECT_THROW(matrix_1x1->operator()(0, 1), std::range_error);
}

TEST_F(MatrixTest, operator_bracket_error_5) {
  EXPECT_THROW(matrix_1x1->operator()(1, 1), std::range_error);
}

TEST_F(MatrixTest, operator_bracket_error_3) {
  S21Matrix matrix(2, 2);
  EXPECT_THROW(matrix(2, 2) = 1, std::range_error);
  EXPECT_THROW(matrix(1, 2) = 1, std::range_error);
  EXPECT_THROW(matrix(2, 1) = 1, std::range_error);
  EXPECT_THROW(matrix(2, 3) = 1, std::range_error);
  EXPECT_THROW(matrix(3, 2) = 1, std::range_error);
  EXPECT_THROW(matrix(3, 3) = 1, std::range_error);
}

TEST_F(MatrixTest, operator_const_bracket_error_0) {
  S21Matrix const temp;
  EXPECT_THROW(temp.operator()(0, -1), std::range_error);
}

TEST_F(MatrixTest, operator_const_bracket_error_1) {
  S21Matrix const temp;
  EXPECT_THROW(temp.operator()(-1, 0), std::range_error);
}

TEST_F(MatrixTest, operator_const_bracket_error_2) {
  S21Matrix const temp;
  EXPECT_THROW(temp.operator()(-1, -1), std::range_error);
}

TEST_F(MatrixTest, operator_const_bracket_error_3) {
  S21Matrix const matrix(2, 2);
  EXPECT_THROW(matrix(2, 2), std::range_error);
  EXPECT_THROW(matrix(2, 3), std::range_error);
  EXPECT_THROW(matrix(3, 2), std::range_error);
  EXPECT_THROW(matrix(3, 3), std::range_error);
  EXPECT_THROW(matrix(0, -1), std::range_error);
  EXPECT_THROW(matrix(-1, 0), std::range_error);
}

TEST_F(MatrixTest, sub_matrix_6) {
  EXPECT_THROW(matrix_1x1->subMatrix(*matrix_3x3), std::length_error);
}

TEST_F(MatrixTest, sum_matrix_1) {
  EXPECT_THROW(matrix_1x1->sumMatrix(*matrix_3x3), std::length_error);
}

TEST_F(MatrixTest, mul_matrix_error_0) {
  EXPECT_THROW(matrix_1x1->mulMatrix(*matrix_5x5), std::length_error);
}

TEST_F(MatrixTest, calc_complement_0) {
  S21Matrix temp(4, 3);
  EXPECT_THROW(temp.calcComplements(), std::range_error);
}

TEST_F(MatrixTest, determinant_0) {
  S21Matrix temp(4, 3);
  EXPECT_THROW(temp.determinant(), std::range_error);
}

TEST_F(MatrixTest, inverse_0) {
  S21Matrix temp(4, 3);
  EXPECT_THROW(temp.inverseMatrix(), std::range_error);
}

TEST_F(MatrixTest, S21MatrixSize_0x0Throw) {
  EXPECT_THROW(S21Matrix s_21_matrix_0x0(0, 0), std::range_error);
}

TEST_F(MatrixTest, MatrixTestSetRowsThrow) {
  EXPECT_THROW(s_21_matrix_3x3->setRows(0), std::range_error);
}

TEST_F(MatrixTest, MatrixTestSetColsThrow) {
  EXPECT_THROW(s_21_matrix_3x3->setCols(0), std::range_error);
}

TEST_F(MatrixTest, MatrixTestOperatorPlusThrow) {
  EXPECT_THROW(*s_21_matrix_3x4 + *s_21_matrix_3x3, std::length_error);
}

TEST_F(MatrixTest, MatrixTestOperatorMinusThrow) {
  EXPECT_THROW(*s_21_matrix_3x4 - *s_21_matrix_3x3, std::length_error);
}

TEST_F(MatrixTest, MatrixTestOperatormulMatrixThrow) {
  EXPECT_THROW(*s_21_matrix_3x4 * *s_21_matrix_3x3, std::length_error);
}

TEST_F(MatrixTest, MatrixTestOperatorFuncThrow) {
  EXPECT_THROW(s_21_matrix_3x3->operator()(-1, 0), std::range_error);
  EXPECT_THROW(s_21_matrix_3x3->operator()(0, -1), std::range_error);
  EXPECT_THROW(s_21_matrix_3x3->operator()(4, 0), std::range_error);
  EXPECT_THROW(s_21_matrix_3x3->operator()(0, 4), std::range_error);
}

TEST_F(MatrixTest, MatrixTestOperatorFuncConstThrow) {
  S21Matrix const result;
  EXPECT_THROW(result(-1, 0), std::range_error);
  EXPECT_THROW(result(0, -1), std::range_error);
  EXPECT_THROW(result(4, 0), std::range_error);
  EXPECT_THROW(result(0, 4), std::range_error);
}

TEST_F(MatrixTest, S21MatrixdeterminantThrow) {
  EXPECT_THROW(s_21_matrix_3x4->determinant(), std::range_error);
}

TEST_F(MatrixTest, S21MatrixcalcComplementsThrow) {
  EXPECT_THROW(s_21_matrix_3x4->calcComplements(), std::range_error);
}

////TEST CONSTRUCTOR
TEST_F(MatrixTest, constructor_0) {
  auto *test = new S21Matrix(1, 1);
  EXPECT_EQ(test->getRows(), matrix_1x1->getRows());
  EXPECT_EQ(test->getCols(), matrix_1x1->getCols());
  delete test;
}

TEST_F(MatrixTest, constructor_1) {
  auto *test = new S21Matrix();
  EXPECT_EQ(test->getRows(), matrix_3x3->getRows());
  EXPECT_EQ(test->getCols(), matrix_3x3->getCols());
  delete test;
}

TEST_F(MatrixTest, constructor_2) {
  auto *test = new S21Matrix(5, 5);
  EXPECT_EQ(test->getRows(), matrix_5x5->getRows());
  EXPECT_EQ(test->getCols(), matrix_5x5->getCols());
  delete test;
}

TEST_F(MatrixTest, constructor_3) {
  auto *test_1 = new S21Matrix(50, 50);
  auto *test_2 = new S21Matrix(50, 50);
  EXPECT_EQ(test_1->getRows(), test_2->getRows());
  EXPECT_EQ(test_1->getCols(), test_2->getCols());
  delete test_1;
  delete test_2;
}

TEST_F(MatrixTest, constructor_4) {
  auto *test_1 = new S21Matrix(1000, 1000);
  auto *test_2 = new S21Matrix(1000, 1000);
  EXPECT_EQ(test_1->getRows(), test_2->getRows());
  EXPECT_EQ(test_1->getCols(), test_2->getCols());
  delete test_1;
  delete test_2;
}

// ////TEST COPY CONSTRUCTOR
TEST_F(MatrixTest, copy_0) {
  S21Matrix *copy_matrix(matrix_1x1);
  EXPECT_EQ(copy_matrix->getRows(), matrix_1x1->getRows());
  EXPECT_EQ(copy_matrix->getCols(), matrix_1x1->getCols());
  EXPECT_TRUE(*copy_matrix == *matrix_1x1);
}

TEST_F(MatrixTest, copy_1) {
  S21Matrix *copy_matrix(matrix_3x3);
  EXPECT_EQ(copy_matrix->getRows(), matrix_3x3->getRows());
  EXPECT_EQ(copy_matrix->getCols(), matrix_3x3->getCols());
  EXPECT_TRUE(*copy_matrix == *matrix_3x3);
}

TEST_F(MatrixTest, copy_2) {
  S21Matrix *copy_matrix(matrix_5x5);
  EXPECT_EQ(copy_matrix->getRows(), matrix_5x5->getRows());
  EXPECT_EQ(copy_matrix->getCols(), matrix_5x5->getCols());
  EXPECT_TRUE(*copy_matrix == *matrix_5x5);
}

TEST_F(MatrixTest, copy_3) {
  auto *temp_matrix = new S21Matrix(50, 50);
  S21Matrix *copy_matrix(temp_matrix);
  EXPECT_EQ(copy_matrix->getRows(), temp_matrix->getRows());
  EXPECT_EQ(copy_matrix->getCols(), temp_matrix->getCols());
  EXPECT_TRUE(*copy_matrix == *temp_matrix);
  delete temp_matrix;
}

TEST_F(MatrixTest, copy_4) {
  auto *temp_matrix = new S21Matrix(1000, 1000);
  S21Matrix *copy_matrix(temp_matrix);
  EXPECT_EQ(copy_matrix->getRows(), temp_matrix->getRows());
  EXPECT_EQ(copy_matrix->getCols(), temp_matrix->getCols());
  EXPECT_TRUE(*copy_matrix == *temp_matrix);
  delete temp_matrix;
}

// ////TEST MOVE CONSTRUCTOR
TEST_F(MatrixTest, move_0) {
  S21Matrix copy_matrix(*matrix_1x1);
  S21Matrix matrix(std::move(*matrix_1x1));
  EXPECT_EQ(1, copy_matrix == matrix);
  EXPECT_EQ(0, matrix_1x1->getRows());
  EXPECT_EQ(0, matrix_1x1->getCols());
  EXPECT_EQ(copy_matrix.getRows(), matrix.getRows());
  EXPECT_EQ(copy_matrix.getCols(), matrix.getCols());
}

TEST_F(MatrixTest, move_1) {
  S21Matrix copy_matrix(*matrix_3x3);
  S21Matrix matrix(std::move(*matrix_3x3));
  EXPECT_EQ(1, copy_matrix == matrix);
  EXPECT_EQ(0, matrix_3x3->getRows());
  EXPECT_EQ(0, matrix_3x3->getCols());
  EXPECT_EQ(copy_matrix.getRows(), matrix.getRows());
  EXPECT_EQ(copy_matrix.getCols(), matrix.getCols());
}

TEST_F(MatrixTest, move_2) {
  S21Matrix copy_matrix(*matrix_5x5);
  S21Matrix matrix(std::move(*matrix_5x5));
  EXPECT_EQ(1, copy_matrix == matrix);
  EXPECT_EQ(0, matrix_5x5->getRows());
  EXPECT_EQ(0, matrix_5x5->getCols());
  EXPECT_EQ(copy_matrix.getRows(), matrix.getRows());
  EXPECT_EQ(copy_matrix.getCols(), matrix.getCols());
}

TEST_F(MatrixTest, move_3) {
  S21Matrix *temp_matrix = new S21Matrix(50, 50);
  S21Matrix copy_matrix(*temp_matrix);
  S21Matrix matrix(std::move(*temp_matrix));
  EXPECT_EQ(1, copy_matrix == matrix);
  EXPECT_EQ(0, temp_matrix->getRows());
  EXPECT_EQ(0, temp_matrix->getCols());
  EXPECT_EQ(copy_matrix.getRows(), matrix.getRows());
  EXPECT_EQ(copy_matrix.getCols(), matrix.getCols());
  delete temp_matrix;
}

TEST_F(MatrixTest, move_4) {
  S21Matrix *temp_matrix = new S21Matrix(1000, 1000);
  S21Matrix copy_matrix(*temp_matrix);
  S21Matrix matrix(std::move(*temp_matrix));
  EXPECT_EQ(1, copy_matrix == matrix);
  EXPECT_EQ(0, temp_matrix->getRows());
  EXPECT_EQ(0, temp_matrix->getCols());
  EXPECT_EQ(copy_matrix.getRows(), matrix.getRows());
  EXPECT_EQ(copy_matrix.getCols(), matrix.getCols());
  delete temp_matrix;
}

// ////TEST GETERS
TEST_F(MatrixTest, geters_0) {
  EXPECT_EQ(1, matrix_1x1->getRows());
  EXPECT_EQ(1, matrix_1x1->getCols());
}

TEST_F(MatrixTest, geters_1) {
  EXPECT_EQ(3, matrix_3x3->getRows());
  EXPECT_EQ(3, matrix_3x3->getCols());
}

TEST_F(MatrixTest, geters_2) {
  EXPECT_EQ(5, matrix_5x5->getRows());
  EXPECT_EQ(5, matrix_5x5->getCols());
}

TEST_F(MatrixTest, geters_3) {
  auto *test = new S21Matrix(50, 50);
  EXPECT_EQ(50, test->getRows());
  EXPECT_EQ(50, test->getCols());
  test->~S21Matrix();
  delete test;
}

TEST_F(MatrixTest, geters_4) {
  auto *test = new S21Matrix(1000, 1000);
  EXPECT_EQ(1000, test->getRows());
  EXPECT_EQ(1000, test->getCols());
  test->~S21Matrix();
  delete test;
}

// ////// TEST SETTERS
TEST_F(MatrixTest, setters_0) {
  matrix_1x1->setRows(10);
  matrix_1x1->setCols(10);
  EXPECT_EQ(10, matrix_1x1->getRows());
  EXPECT_EQ(10, matrix_1x1->getCols());
}

TEST_F(MatrixTest, setters_1) {
  matrix_3x3->setRows(10);
  EXPECT_EQ(10, matrix_3x3->getRows());
  matrix_3x3->setCols(5);
  EXPECT_EQ(5, matrix_3x3->getCols());
}

TEST_F(MatrixTest, setters_2) {
  matrix_5x5->setRows(10);
  EXPECT_EQ(10, matrix_5x5->getRows());
  matrix_5x5->setCols(7);
  EXPECT_EQ(7, matrix_5x5->getCols());
}

TEST_F(MatrixTest, setters_3) {
  matrix_3x3->setRows(2);
  EXPECT_EQ(2, matrix_3x3->getRows());
  matrix_3x3->setCols(2);
  EXPECT_EQ(2, matrix_3x3->getCols());
}

TEST_F(MatrixTest, setters_4) {
  matrix_5x5->setRows(3);
  EXPECT_EQ(3, matrix_5x5->getRows());
  matrix_5x5->setCols(3);
  EXPECT_EQ(3, matrix_5x5->getCols());
}

TEST_F(MatrixTest, setters_5) {
  S21Matrix matrix;
  matrix.setRows(10);
  EXPECT_EQ(10, matrix.getRows());
  matrix.setCols(10);
  EXPECT_EQ(10, matrix.getCols());
}

// ////TEST EQ MATRIX
TEST_F(MatrixTest, eq_matrix_0) {
  S21Matrix *copy(matrix_1x1);
  EXPECT_TRUE(*copy == *matrix_1x1);
}

TEST_F(MatrixTest, eq_matrix_1) {
  S21Matrix *copy(matrix_3x3);
  EXPECT_TRUE(*copy == *matrix_3x3);
}

TEST_F(MatrixTest, eq_matrix_2) {
  S21Matrix *copy(matrix_5x5);
  EXPECT_TRUE(*copy == *matrix_5x5);
}

TEST_F(MatrixTest, eq_matrix_3) { EXPECT_FALSE(*matrix_1x1 == *matrix_3x3); }

// ////TEST SUM MATRIX
TEST_F(MatrixTest, sum_matrix_0) {
  auto *sum = new S21Matrix(1, 1);
  sum->sumMatrix(*matrix_1x1);
  EXPECT_TRUE(*matrix_1x1 == *sum);
  delete sum;
}

TEST_F(MatrixTest, sum_matrix_2) {
  S21Matrix sum(3, 3);
  sum = (*matrix_3x3 * 2);
  matrix_3x3->sumMatrix(*matrix_3x3);
  EXPECT_TRUE(sum == *matrix_3x3);
}

TEST_F(MatrixTest, sum_matrix_3) {
  S21Matrix sum(5, 5);
  sum = (*matrix_5x5 * 2);
  matrix_5x5->sumMatrix(*matrix_5x5);
  EXPECT_TRUE(sum == *matrix_5x5);
}

// ////TEST SUB MATRIX
TEST_F(MatrixTest, sub_matrix_0) {
  auto *sub = new S21Matrix(1, 1);
  (*sub)(0, 0) = 0;
  sub->subMatrix(*matrix_1x1);
  EXPECT_TRUE(*sub == *matrix_1x1);
  delete sub;
}

TEST_F(MatrixTest, sub_matrix_1) {
  S21Matrix sub(3, 3);
  matrix_3x3->subMatrix(*matrix_3x3);
  EXPECT_TRUE(sub == *matrix_3x3);
}

TEST_F(MatrixTest, sub_matrix_2) {
  S21Matrix sub(5, 5);
  matrix_5x5->subMatrix(*matrix_5x5);
  EXPECT_TRUE(sub == *matrix_5x5);
}

TEST_F(MatrixTest, sub_matrix_4) {
  auto *sub = new S21Matrix(3, 3);
  sub->subMatrix(*matrix_3x3);
  sub->mulNumber(-1);
  sub->operator()(0, 0) = 0;
  EXPECT_TRUE(*sub == *matrix_3x3);
  delete sub;
}

// ////TEST MUL NUMBER
TEST_F(MatrixTest, mul_namber_0) {
  matrix_1x1->mulNumber(1000000000);
  EXPECT_EQ(0, matrix_1x1->operator()(0, 0));
}

TEST_F(MatrixTest, mul_namber_1) {
  S21Matrix temp;
  int temp_value = 0;
  for (int i = 0; i < temp.getRows(); i++) {
    for (int j = 0; j < temp.getCols(); j++) {
      temp.operator()(i, j) = temp_value;
      temp_value++;
    }
  }
  matrix_3x3->mulNumber(1000);
  for (int i = 0; i < matrix_3x3->getRows(); i++) {
    for (int j = 0; j < matrix_3x3->getCols(); j++) {
      EXPECT_EQ(temp.operator()(i, j) * 1000, matrix_3x3->operator()(i, j));
    }
  }
}

TEST_F(MatrixTest, mul_namber_2) {
  S21Matrix temp(5, 5);
  int temp_value = 0;
  for (int i = 0; i < temp.getRows(); i++) {
    for (int j = 0; j < temp.getCols(); j++) {
      temp.operator()(i, j) = temp_value;
      temp_value++;
    }
  }
  matrix_5x5->mulNumber(1000);
  for (int i = 0; i < matrix_5x5->getRows(); i++) {
    for (int j = 0; j < matrix_5x5->getCols(); j++) {
      EXPECT_EQ(temp.operator()(i, j) * 1000, matrix_5x5->operator()(i, j));
    }
  }
}

TEST_F(MatrixTest, mul_namber_4) {
  auto *mul = new S21Matrix(1000, 1000);
  mul->mulNumber(0);
  for (int i = 0; i < mul->getRows(); i++) {
    for (int j = 0; j < mul->getCols(); j++) {
      EXPECT_EQ(0, mul->operator()(i, j));
    }
  }
  mul->~S21Matrix();
  delete mul;
}

// ////TEST transpose
TEST_F(MatrixTest, transpose_0) {
  S21Matrix test(1, 1);
  EXPECT_TRUE(test == matrix_1x1->transpose());
}

TEST_F(MatrixTest, transpose_1) {
  S21Matrix test(3, 3);
  test(0, 0) = 0;
  test(1, 0) = 1;
  test(2, 0) = 2;
  test(0, 1) = 3;
  test(1, 1) = 4;
  test(2, 1) = 5;
  test(0, 2) = 6;
  test(1, 2) = 7;
  test(2, 2) = 8;
  EXPECT_TRUE(test == matrix_3x3->transpose());
}

//// TEST determinant
TEST_F(MatrixTest, determinant_2) { EXPECT_EQ(0, matrix_1x1->determinant()); }

TEST_F(MatrixTest, determinant_3) { EXPECT_EQ(0, matrix_3x3->determinant()); }

TEST_F(MatrixTest, determinant_4) { EXPECT_EQ(0, matrix_5x5->determinant()); }

// TEST OPERATOR +
TEST_F(MatrixTest, operator_plus_0) {
  auto *result = new S21Matrix(1, 1);
  auto *matrix_1x1 = new S21Matrix(1, 1);
  (*matrix_1x1)(0, 0) = 1;
  (*result)(0, 0) = 2;
  EXPECT_TRUE(*result == (*matrix_1x1 + *matrix_1x1));
  delete result;
  delete matrix_1x1;
}

////TEST OPERATOR -
TEST_F(MatrixTest, operator_min_0) {
  S21Matrix *copy(matrix_1x1);
  auto *result = new S21Matrix(1, 1);
  copy->operator()(0, 0) = 1;
  (*result)(0, 0) = 0;
  EXPECT_TRUE(*result == (*copy - *copy));
  delete result;
}

TEST_F(MatrixTest, operator_min_1) {
  S21Matrix *copy(matrix_3x3);
  auto *result = new S21Matrix(3, 3);
  EXPECT_TRUE(*result == (*copy - *copy));
  result->~S21Matrix();
  delete result;
}

////TEST OPERATOR *
TEST_F(MatrixTest, operator_mult_0) {
  S21Matrix mat_1(1, 1);
  S21Matrix mat_2(1, 1);
  mat_1(0, 0) = 1;
  mat_2(0, 0) = 1;
  S21Matrix result(1, 1);
  result(0, 0) = 1;
  EXPECT_TRUE(result == (mat_1 * mat_2));
}

////TEST OPERATOR +=
TEST_F(MatrixTest, operator_plus_asgmnt_0) {
  S21Matrix copy(*matrix_3x3);
  auto *result = new S21Matrix(3, 3);
  (*result)(0, 0) = 0;
  (*result)(0, 1) = 2;
  (*result)(0, 2) = 4;
  (*result)(1, 0) = 6;
  (*result)(1, 1) = 8;
  (*result)(1, 2) = 10;
  (*result)(2, 0) = 12;
  (*result)(2, 1) = 14;
  (*result)(2, 2) = 16;
  *matrix_3x3 += copy;
  EXPECT_TRUE(*result == *matrix_3x3);
  delete result;
}

TEST_F(MatrixTest, operator_plus_asgmnt_1) {
  S21Matrix copy(*matrix_5x5);
  auto *result = new S21Matrix(5, 5);
  (*result)(0, 0) = 0;
  (*result)(0, 1) = 2;
  (*result)(0, 2) = 4;
  (*result)(0, 3) = 6;
  (*result)(0, 4) = 8;
  (*result)(1, 0) = 10;
  (*result)(1, 1) = 12;
  (*result)(1, 2) = 14;
  (*result)(1, 3) = 16;
  (*result)(1, 4) = 18;
  (*result)(2, 0) = 20;
  (*result)(2, 1) = 22;
  (*result)(2, 2) = 24;
  (*result)(2, 3) = 26;
  (*result)(2, 4) = 28;
  (*result)(3, 0) = 30;
  (*result)(3, 1) = 32;
  (*result)(3, 2) = 34;
  (*result)(3, 3) = 36;
  (*result)(3, 4) = 38;
  (*result)(4, 0) = 40;
  (*result)(4, 1) = 42;
  (*result)(4, 2) = 44;
  (*result)(4, 3) = 46;
  (*result)(4, 4) = 48;
  *matrix_5x5 += copy;
  EXPECT_TRUE(*result == *matrix_5x5);
  delete result;
}

////TEST OPERATOR -=
TEST_F(MatrixTest, operator_min_asgmnt_0) {
  S21Matrix copy(*matrix_1x1);
  auto *result = new S21Matrix(1, 1);
  (*matrix_1x1)(0, 0) = 1;
  copy(0, 0) = 1;
  (*result)(0, 0) = 0;
  *matrix_1x1 -= copy;
  EXPECT_TRUE(*result == *matrix_1x1);
  delete result;
}

TEST_F(MatrixTest, operator_min_asgmnt_1) {
  S21Matrix copy(*matrix_3x3);
  auto *result = new S21Matrix(3, 3);
  (*result)(0, 0) = 0;
  (*result)(0, 1) = 0;
  (*result)(0, 2) = 0;
  (*result)(1, 0) = 0;
  (*result)(1, 1) = 0;
  (*result)(1, 2) = 0;
  (*result)(2, 0) = 0;
  (*result)(2, 1) = 0;
  (*result)(2, 2) = 0;
  *matrix_3x3 -= copy;
  EXPECT_TRUE(*result == *matrix_3x3);
  delete result;
}

TEST_F(MatrixTest, operator_min_asgmnt_2) {
  S21Matrix copy(*matrix_5x5);
  auto *result = new S21Matrix(5, 5);
  (*result)(0, 0) = 0;
  (*result)(0, 1) = 0;
  (*result)(0, 2) = 0;
  (*result)(0, 3) = 0;
  (*result)(0, 4) = 0;
  (*result)(1, 0) = 0;
  (*result)(1, 1) = 0;
  (*result)(1, 2) = 0;
  (*result)(1, 3) = 0;
  (*result)(1, 4) = 0;
  (*result)(2, 0) = 0;
  (*result)(2, 1) = 0;
  (*result)(2, 2) = 0;
  (*result)(2, 3) = 0;
  (*result)(2, 4) = 0;
  (*result)(3, 0) = 0;
  (*result)(3, 1) = 0;
  (*result)(3, 2) = 0;
  (*result)(3, 3) = 0;
  (*result)(3, 4) = 0;
  (*result)(4, 0) = 0;
  (*result)(4, 1) = 0;
  (*result)(4, 2) = 0;
  (*result)(4, 3) = 0;
  (*result)(4, 4) = 0;
  *matrix_5x5 -= copy;
  EXPECT_TRUE(*result == *matrix_5x5);
  delete result;
}

////TEST OPERATOR *=
TEST_F(MatrixTest, operator_mult_asgmnt_0) {
  S21Matrix copy(*matrix_1x1);
  auto *result = new S21Matrix(1, 1);
  (*matrix_1x1)(0, 0) = 1;
  copy(0, 0) = 1;
  (*result)(0, 0) = 1;
  *matrix_1x1 *= copy;
  EXPECT_TRUE(*result == *matrix_1x1);
  delete result;
}

TEST_F(MatrixTest, operator_mult_asgmnt_1) {
  S21Matrix copy(*matrix_3x3);
  auto *result = new S21Matrix(3, 3);
  (*result)(0, 0) = 15;
  (*result)(0, 1) = 18;
  (*result)(0, 2) = 21;
  (*result)(1, 0) = 42;
  (*result)(1, 1) = 54;
  (*result)(1, 2) = 66;
  (*result)(2, 0) = 69;
  (*result)(2, 1) = 90;
  (*result)(2, 2) = 111;
  copy *= *matrix_3x3;
  EXPECT_TRUE(*result == copy);
  delete result;
}

TEST_F(MatrixTest, operator_mult_asgmnt_2) {
  S21Matrix copy(*matrix_5x5);
  auto *result = new S21Matrix(5, 5);
  (*result)(0, 0) = 150;
  (*result)(0, 1) = 160;
  (*result)(0, 2) = 170;
  (*result)(0, 3) = 180;
  (*result)(0, 4) = 190;
  (*result)(1, 0) = 400;
  (*result)(1, 1) = 435;
  (*result)(1, 2) = 470;
  (*result)(1, 3) = 505;
  (*result)(1, 4) = 540;
  (*result)(2, 0) = 650;
  (*result)(2, 1) = 710;
  (*result)(2, 2) = 770;
  (*result)(2, 3) = 830;
  (*result)(2, 4) = 890;
  (*result)(3, 0) = 900;
  (*result)(3, 1) = 985;
  (*result)(3, 2) = 1070;
  (*result)(3, 3) = 1155;
  (*result)(3, 4) = 1240;
  (*result)(4, 0) = 1150;
  (*result)(4, 1) = 1260;
  (*result)(4, 2) = 1370;
  (*result)(4, 3) = 1480;
  (*result)(4, 4) = 1590;
  *matrix_5x5 *= copy;
  EXPECT_TRUE(*result == *matrix_5x5);
  delete result;
}

// TEST OPERATOR ==
TEST_F(MatrixTest, operator_eq_0) {
  auto *result = new S21Matrix(5, 5);
  (*result)(0, 0) = 150;
  (*result)(0, 1) = 160;
  (*result)(0, 2) = 170;
  (*result)(0, 3) = 180;
  (*result)(0, 4) = 190;
  (*result)(1, 0) = 400;
  (*result)(1, 1) = 435;
  (*result)(1, 2) = 470;
  (*result)(1, 3) = 505;
  (*result)(1, 4) = 540;
  (*result)(2, 0) = 650;
  (*result)(2, 1) = 710;
  (*result)(2, 2) = 770;
  (*result)(2, 3) = 830;
  (*result)(2, 4) = 890;
  (*result)(3, 0) = 900;
  (*result)(3, 1) = 985;
  (*result)(3, 2) = 1070;
  (*result)(3, 3) = 1155;
  (*result)(3, 4) = 1240;
  (*result)(4, 0) = 1150;
  (*result)(4, 1) = 1260;
  (*result)(4, 2) = 1370;
  (*result)(4, 3) = 1480;
  (*result)(4, 4) = 1590;
  EXPECT_FALSE(*result == *matrix_5x5);
  delete result;
}

TEST_F(MatrixTest, operator_eq_1) {
  auto *result = new S21Matrix(5, 5);
  EXPECT_FALSE(*result == *matrix_5x5);
  delete result;
}

TEST_F(MatrixTest, operator_eq_2) {
  S21Matrix *result = matrix_5x5;
  EXPECT_TRUE(*result == *matrix_5x5);
}

TEST_F(MatrixTest, operator_eq_3) {
  auto *result = new S21Matrix(5, 4);
  EXPECT_FALSE(*result == *matrix_5x5);
  delete result;
}

TEST_F(MatrixTest, operator_eq_4) {
  auto *result = new S21Matrix(1, 1);
  EXPECT_FALSE(*result == *matrix_5x5);
  delete result;
}

TEST_F(MatrixTest, operator_eq_5) {
  auto *matrix_1 = new S21Matrix(6, 4);
  auto *matrix_2 = new S21Matrix(4, 6);
  EXPECT_FALSE(*matrix_1 == *matrix_2);
  delete matrix_1;
  delete matrix_2;
}

////TEST OPERATOR =
TEST_F(MatrixTest, operator_asgmnt_0) {
  S21Matrix *temp = matrix_1x1;
  EXPECT_TRUE(*temp == *matrix_1x1);
}

TEST_F(MatrixTest, operator_asgmnt_1) {
  S21Matrix *temp = matrix_3x3;
  EXPECT_TRUE(*temp == *matrix_3x3);
}

TEST_F(MatrixTest, operator_asgmnt_2) {
  S21Matrix *temp = matrix_5x5;
  EXPECT_TRUE(*temp == *matrix_5x5);
}

TEST_F(MatrixTest, S21MatrixSize_3x3) {
  EXPECT_EQ(3, s_21_matrix_3x3->getRows());
  EXPECT_EQ(3, s_21_matrix_3x3->getCols());
}

TEST_F(MatrixTest, S21MatrixSize_3x4) {
  EXPECT_EQ(3, s_21_matrix_3x4->getRows());
  EXPECT_EQ(4, s_21_matrix_3x4->getCols());
}

TEST_F(MatrixTest, MatrixTestConstructorZero) {
  S21Matrix result;
  EXPECT_EQ(3, result.getRows());
  EXPECT_EQ(3, result.getCols());
}

TEST_F(MatrixTest, MatrixTestConstructor3x4) {
  S21Matrix result(3, 4);
  EXPECT_EQ(3, result.getRows());
  EXPECT_EQ(4, result.getCols());
}

TEST_F(MatrixTest, MatrixTestConstructorFromOther) {
  S21Matrix result(*s_21_matrix_3x4);
  EXPECT_EQ(3, result.getRows());
  EXPECT_EQ(4, result.getCols());
  EXPECT_EQ(1, result == *s_21_matrix_3x4);
}

TEST_F(MatrixTest, MatrixTestConstructorFromMoveOther) {
  S21Matrix result(*s_21_matrix_3x4);
  S21Matrix move_result(std::move(*s_21_matrix_3x4));
  EXPECT_EQ(3, result.getRows());
  EXPECT_EQ(4, result.getCols());
  EXPECT_EQ(1, result == move_result);
  EXPECT_EQ(0, s_21_matrix_3x4->getRows());
  EXPECT_EQ(0, s_21_matrix_3x4->getCols());
}

TEST_F(MatrixTest, MatrixTestSetRows) {
  S21Matrix result(2, 3);
  result(0, 0) = 8;
  result(0, 1) = 2;
  result(0, 2) = 4;
  result(1, 0) = 4;
  result(1, 1) = 6;
  result(1, 2) = 6;
  s_21_matrix_3x3->setRows(2);
  EXPECT_EQ(2, s_21_matrix_3x3->getRows());
  EXPECT_EQ(3, s_21_matrix_3x3->getCols());
  EXPECT_EQ(1, *s_21_matrix_3x3 == result);
}

TEST_F(MatrixTest, MatrixTestSetCols) {
  S21Matrix result(3, 2);
  result(0, 0) = 8;
  result(0, 1) = 2;
  result(1, 0) = 4;
  result(1, 1) = 6;
  result(2, 0) = 4;
  result(2, 1) = 8;
  s_21_matrix_3x3->setCols(2);
  EXPECT_EQ(3, s_21_matrix_3x3->getRows());
  EXPECT_EQ(2, s_21_matrix_3x3->getCols());
  EXPECT_EQ(1, *s_21_matrix_3x3 == result);
}

TEST_F(MatrixTest, MatrixTestOperatorPlusAssign) {
  S21Matrix result(3, 4);
  result(0, 0) = 2;
  result(0, 1) = 4;
  result(0, 2) = 6;
  result(0, 3) = 8;
  result(1, 0) = 10;
  result(1, 1) = 12;
  result(1, 2) = 14;
  result(1, 3) = 16;
  result(2, 0) = 18;
  result(2, 1) = 20;
  result(2, 2) = 22;
  result(2, 3) = 24;
  *s_21_matrix_3x4 += *s_21_matrix_3x4;
  EXPECT_EQ(1, result == *s_21_matrix_3x4);
}

TEST_F(MatrixTest, MatrixTestOperatorMinusAssign) {
  S21Matrix result(3, 4);
  result(0, 0) = 0;
  result(0, 1) = 0;
  result(0, 2) = 0;
  result(0, 3) = 0;
  result(1, 0) = 0;
  result(1, 1) = 0;
  result(1, 2) = 0;
  result(1, 3) = 0;
  result(2, 0) = 0;
  result(2, 1) = 0;
  result(2, 2) = 0;
  result(2, 3) = 0;
  *s_21_matrix_3x4 -= *s_21_matrix_3x4;
  EXPECT_EQ(1, result == *s_21_matrix_3x4);
}

TEST_F(MatrixTest, MatrixTestOperatorMulNumAssign) {
  S21Matrix result(3, 4);
  result(0, 0) = 5;
  result(0, 1) = 10;
  result(0, 2) = 15;
  result(0, 3) = 20;
  result(1, 0) = 25;
  result(1, 1) = 30;
  result(1, 2) = 35;
  result(1, 3) = 40;
  result(2, 0) = 45;
  result(2, 1) = 50;
  result(2, 2) = 55;
  result(2, 3) = 60;
  *s_21_matrix_3x4 *= 5;
  EXPECT_EQ(1, result == *s_21_matrix_3x4);
}

TEST_F(MatrixTest, MatrixTestOperatorFunc) {
  EXPECT_EQ(8, s_21_matrix_3x3->operator()(0, 0));
  s_21_matrix_3x3->operator()(0, 0) = 5;
  EXPECT_EQ(5, s_21_matrix_3x3->operator()(0, 0));
  EXPECT_EQ(2, s_21_matrix_3x3->operator()(0, 1));
  EXPECT_EQ(4, s_21_matrix_3x3->operator()(0, 2));
  EXPECT_EQ(4, s_21_matrix_3x3->operator()(1, 0));
  EXPECT_EQ(6, s_21_matrix_3x3->operator()(1, 1));
  EXPECT_EQ(6, s_21_matrix_3x3->operator()(1, 2));
  EXPECT_EQ(4, s_21_matrix_3x3->operator()(2, 0));
  EXPECT_EQ(8, s_21_matrix_3x3->operator()(2, 1));
  EXPECT_EQ(8, s_21_matrix_3x3->operator()(2, 2));
}
TEST_F(MatrixTest, MatrixTestOperatorFuncConst0) {
  S21Matrix const result;
  EXPECT_EQ(0, result(0, 0));
}

TEST_F(MatrixTest, MatrixTestEqMatrix) {
  EXPECT_EQ(0, *s_21_matrix_3x3 == *s_21_matrix_3x4);
  EXPECT_EQ(1, *s_21_matrix_3x3 == *s_21_matrix_3x3);
  S21Matrix result;
  result(0, 0) = 0.00000002;
  EXPECT_EQ(0, *s_21_matrix_3x3 == result);
}

TEST_F(MatrixTest, S21Matrixdeterminant) {
  EXPECT_EQ(16, s_21_matrix_3x3->determinant());
  s_21_matrix_3x3->operator()(2, 0) = 0;
  s_21_matrix_3x3->operator()(2, 1) = 0;
  s_21_matrix_3x3->operator()(2, 2) = 0;
  EXPECT_EQ(0, s_21_matrix_3x3->determinant());
}

TEST_F(MatrixTest, S21Matrixtranspose) {
  EXPECT_EQ(3, s_21_matrix_3x4->getRows());
  EXPECT_EQ(4, s_21_matrix_3x4->getCols());
  *s_21_matrix_3x4 = s_21_matrix_3x4->transpose();
  EXPECT_EQ(4, s_21_matrix_3x4->getRows());
  EXPECT_EQ(3, s_21_matrix_3x4->getCols());
}

TEST_F(MatrixTest, MatrixTestOperatorMulNum) {
  S21Matrix result(3, 4);
  result(0, 0) = 5;
  result(0, 1) = 10;
  result(0, 2) = 15;
  result(0, 3) = 20;
  result(1, 0) = 25;
  result(1, 1) = 30;
  result(1, 2) = 35;
  result(1, 3) = 40;
  result(2, 0) = 45;
  result(2, 1) = 50;
  result(2, 2) = 55;
  result(2, 3) = 60;
  S21Matrix result_test(3, 4);
  result_test = *s_21_matrix_3x4 * 5;
  EXPECT_EQ(1, result == result_test);
}

TEST_F(MatrixTest, MatrixTestOperatorPlus) {
  S21Matrix result(3, 4);
  result(0, 0) = 2;
  result(0, 1) = 4;
  result(0, 2) = 6;
  result(0, 3) = 8;
  result(1, 0) = 10;
  result(1, 1) = 12;
  result(1, 2) = 14;
  result(1, 3) = 16;
  result(2, 0) = 18;
  result(2, 1) = 20;
  result(2, 2) = 22;
  result(2, 3) = 24;
  S21Matrix result_test(3, 4);
  result_test = *s_21_matrix_3x4 + *s_21_matrix_3x4;
  EXPECT_EQ(1, result == result_test);
}

TEST_F(MatrixTest, MatrixTestOperatorMinus) {
  S21Matrix result(3, 4);
  result(0, 0) = 0;
  result(0, 1) = 0;
  result(0, 2) = 0;
  result(0, 3) = 0;
  result(1, 0) = 0;
  result(1, 1) = 0;
  result(1, 2) = 0;
  result(1, 3) = 0;
  result(2, 0) = 0;
  result(2, 1) = 0;
  result(2, 2) = 0;
  result(2, 3) = 0;
  S21Matrix result_test(3, 4);
  result_test = *s_21_matrix_3x4 - *s_21_matrix_3x4;
  EXPECT_EQ(1, result == result_test);
}

TEST_F(MatrixTest, MatrixTestOperatormulMatrixAssign) {
  S21Matrix result(3, 1);
  result(0, 0) = 24;
  result(1, 0) = 34;
  result(2, 0) = 44;

  S21Matrix matrix3x1(3, 1);
  matrix3x1(0, 0) = 1;
  matrix3x1(1, 0) = 2;
  matrix3x1(2, 0) = 3;
  *s_21_matrix_3x3 *= matrix3x1;
  EXPECT_EQ(1, result == *s_21_matrix_3x3);
  EXPECT_EQ(3, s_21_matrix_3x3->getRows());
  EXPECT_EQ(1, s_21_matrix_3x3->getCols());
}

TEST_F(MatrixTest, MatrixTestOperatormulMatrix) {
  S21Matrix result(3, 1);
  result(0, 0) = 24;
  result(1, 0) = 34;
  result(2, 0) = 44;

  S21Matrix matrix3x1(3, 1);
  matrix3x1(0, 0) = 1;
  matrix3x1(1, 0) = 2;
  matrix3x1(2, 0) = 3;
  S21Matrix result_test(3, 1);
  result_test = *s_21_matrix_3x3 * matrix3x1;
  EXPECT_EQ(1, result == result_test);
}

TEST_F(MatrixTest, S21MatrixInverse) {
  S21Matrix result;
  result(0, 0) = 0;
  result(0, 1) = 1;
  result(0, 2) = -0.75;
  result(1, 0) = -0.5;
  result(1, 1) = 3;
  result(1, 2) = -2;
  result(2, 0) = 0.5;
  result(2, 1) = -3.5;
  result(2, 2) = 2.5;
  S21Matrix result_inverse;
  result_inverse = s_21_matrix_3x3->inverseMatrix();
  EXPECT_EQ(1, result == result_inverse);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
