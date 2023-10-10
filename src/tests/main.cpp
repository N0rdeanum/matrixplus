#include "../s21_matrix_oop.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <iostream>

TEST(create_test_1, create) {
  try {
    S21Matrix arr = S21Matrix(-1, 1);
  } catch (const std::out_of_range &err) {
    EXPECT_EQ(err.what(), std::string("Index out of range"));
  }
}

TEST(test_1, test) {
  S21Matrix A;
  S21Matrix B;
  A = B;

  EXPECT_TRUE(A.EqMatrix(B));
}

TEST(create_test_2, create) {

  S21Matrix A = S21Matrix(2, 3);

  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 2;
  A(1, 0) = 3;
  A(1, 1) = 1;
  A(1, 2) = 2;

  S21Matrix copy = A;
  EXPECT_TRUE(A.EqMatrix(copy));
}

TEST(create_test_3, create) {
  S21Matrix tmp(2, 3);
  S21Matrix tmp_check(2, 3);

  tmp(0, 0) = 1;
  tmp(0, 1) = 2;
  tmp(0, 2) = 2;
  tmp(1, 0) = 3;
  tmp(1, 1) = 1;
  tmp(1, 2) = 2;

  tmp_check(0, 0) = 1;
  tmp_check(0, 1) = 2;
  tmp_check(0, 2) = 2;
  tmp_check(1, 0) = 3;
  tmp_check(1, 1) = 1;
  tmp_check(1, 2) = 2;

  S21Matrix move(std::move(tmp));
  EXPECT_FALSE(move == tmp);
  EXPECT_TRUE(move.EqMatrix(tmp_check));
}

TEST(create_test_4, create) {
  S21Matrix tmp(2, 3), move;
  S21Matrix tmp_check(2, 3);

  tmp(0, 0) = 1;
  tmp(0, 1) = 2;
  tmp(0, 2) = 2;
  tmp(1, 0) = 3;
  tmp(1, 1) = 1;
  tmp(1, 2) = 2;

  tmp_check(0, 0) = 1;
  tmp_check(0, 1) = 2;
  tmp_check(0, 2) = 2;
  tmp_check(1, 0) = 3;
  tmp_check(1, 1) = 1;
  tmp_check(1, 2) = 2;

  move = std::move(tmp);
  EXPECT_FALSE(move.EqMatrix(tmp));
  EXPECT_TRUE(move.EqMatrix(tmp_check));
}

TEST(create_test_5, create) {
  S21Matrix tmp(2, 3), copy;

  tmp(0, 0) = 1;
  tmp(0, 1) = 2;
  tmp(0, 2) = 2;
  tmp(1, 0) = 3;
  tmp(1, 1) = 1;
  tmp(1, 2) = 2;

  copy = tmp;
  EXPECT_TRUE(copy.EqMatrix(tmp));
}

TEST(create_test_6, create) {
  S21Matrix tmp(2, 3), move;
  S21Matrix tmp_check(2, 3);

  tmp(0, 0) = 1;
  tmp(0, 1) = 2;
  tmp(0, 2) = 2;
  tmp(1, 0) = 3;
  tmp(1, 1) = 1;
  tmp(1, 2) = 2;

  tmp_check(0, 0) = 1;
  tmp_check(0, 1) = 2;
  tmp_check(0, 2) = 2;
  tmp_check(1, 0) = 3;
  tmp_check(1, 1) = 1;
  tmp_check(1, 2) = 2;

  move = std::move(tmp_check);
  EXPECT_TRUE(tmp.EqMatrix(move));
}

TEST(sum_test_1, sum) {
  S21Matrix arr_1 = S21Matrix(2, 3);
  S21Matrix arr_2 = S21Matrix(2, 3);

  S21Matrix res = S21Matrix(2, 3);

  arr_1(0, 0) = 1;
  arr_1(0, 1) = 2;
  arr_1(0, 2) = 2;
  arr_1(1, 0) = 3;
  arr_1(1, 1) = 1;
  arr_1(1, 2) = 2;

  arr_2(0, 0) = 1;
  arr_2(0, 1) = 2;
  arr_2(0, 2) = 2;
  arr_2(1, 0) = 3;
  arr_2(1, 1) = 1;
  arr_2(1, 2) = 2;

  res(0, 0) = 2;
  res(0, 1) = 4;
  res(0, 2) = 4;
  res(1, 0) = 6;
  res(1, 1) = 2;
  res(1, 2) = 4;

  arr_1.SumMatrix(arr_2);

  EXPECT_TRUE(arr_1.EqMatrix(res));
}

TEST(sum_test_2, sum) {
  S21Matrix arr_1 = S21Matrix(2, 3);
  S21Matrix arr_2 = S21Matrix(3, 3);

  arr_1(0, 0) = 1;
  arr_1(0, 1) = 2;
  arr_1(0, 2) = 2;
  arr_1(1, 0) = 3;
  arr_1(1, 1) = 1;
  arr_1(1, 2) = 2;

  arr_2(0, 0) = 1;
  arr_2(0, 1) = 2;
  arr_2(0, 2) = 2;
  arr_2(1, 0) = 3;
  arr_2(1, 1) = 1;
  arr_2(1, 2) = 2;
  arr_2(2, 0) = 3;
  arr_2(2, 1) = 4;
  arr_2(2, 2) = 5;

  try {
    arr_1.SumMatrix(arr_2);
  } catch (const std::logic_error &err) {
    EXPECT_EQ(
        err.what(),
        std::string("Incorrect input, matrices should have the same size"));
  }
}

TEST(sum_test_3, sum) {
  S21Matrix arr_1 = S21Matrix(2, 3);
  S21Matrix arr_2 = S21Matrix(2, 3);

  S21Matrix res = S21Matrix(2, 3);

  arr_1(0, 0) = 1;
  arr_1(0, 1) = 2;
  arr_1(0, 2) = 2;
  arr_1(1, 0) = 3;
  arr_1(1, 1) = 1;
  arr_1(1, 2) = 2;

  arr_2(0, 0) = 1;
  arr_2(0, 1) = 2;
  arr_2(0, 2) = 2;
  arr_2(1, 0) = 3;
  arr_2(1, 1) = 1;
  arr_2(1, 2) = 2;

  res(0, 0) = 2;
  res(0, 1) = 4;
  res(0, 2) = 4;
  res(1, 0) = 6;
  res(1, 1) = 2;
  res(1, 2) = 4;

  arr_1 += arr_2;

  EXPECT_TRUE(arr_1.EqMatrix(res));
}

TEST(sum_test_4, sum) {
  S21Matrix arr_1 = S21Matrix(2, 3);
  S21Matrix arr_2 = S21Matrix(2, 3);

  S21Matrix res = S21Matrix(2, 3);

  arr_1(0, 0) = 1;
  arr_1(0, 1) = 2;
  arr_1(0, 2) = 2;
  arr_1(1, 0) = 3;
  arr_1(1, 1) = 1;
  arr_1(1, 2) = 2;

  arr_2(0, 0) = 1;
  arr_2(0, 1) = 2;
  arr_2(0, 2) = 2;
  arr_2(1, 0) = 3;
  arr_2(1, 1) = 1;
  arr_2(1, 2) = 2;

  res(0, 0) = 2;
  res(0, 1) = 4;
  res(0, 2) = 4;
  res(1, 0) = 6;
  res(1, 1) = 2;
  res(1, 2) = 4;

  arr_1 = arr_1 + arr_2;

  EXPECT_EQ(arr_1.EqMatrix(res), true);
}

TEST(sub_test_1, sub) {
  S21Matrix arr_1 = S21Matrix(2, 3);
  S21Matrix arr_2 = S21Matrix(2, 3);

  S21Matrix res = S21Matrix(2, 3);

  arr_1(0, 0) = 1;
  arr_1(0, 1) = 2;
  arr_1(0, 2) = 2;
  arr_1(1, 0) = 3;
  arr_1(1, 1) = 1;
  arr_1(1, 2) = 2;

  arr_2(0, 0) = 1;
  arr_2(0, 1) = 2;
  arr_2(0, 2) = 2;
  arr_2(1, 0) = 3;
  arr_2(1, 1) = 1;
  arr_2(1, 2) = 2;

  res(0, 0) = 0;
  res(0, 1) = 0;
  res(0, 2) = 0;
  res(1, 0) = 0;
  res(1, 1) = 0;
  res(1, 2) = 0;

  arr_1.SubMatrix(arr_2);

  EXPECT_TRUE(arr_1.EqMatrix(res));
}

TEST(sub_test_2, sub) {
  S21Matrix arr_1 = S21Matrix(2, 3);
  S21Matrix arr_2 = S21Matrix(3, 3);

  arr_1(0, 0) = 1;
  arr_1(0, 1) = 2;
  arr_1(0, 2) = 2;
  arr_1(1, 0) = 3;
  arr_1(1, 1) = 1;
  arr_1(1, 2) = 2;

  arr_2(0, 0) = 1;
  arr_2(0, 1) = 2;
  arr_2(0, 2) = 2;
  arr_2(1, 0) = 3;
  arr_2(1, 1) = 1;
  arr_2(1, 2) = 2;
  arr_2(2, 0) = 3;
  arr_2(2, 1) = 4;
  arr_2(2, 2) = 5;

  try {
    arr_1.SubMatrix(arr_2);
  } catch (const std::logic_error &err) {
    EXPECT_EQ(
        err.what(),
        std::string("Incorrect input, matrices should have the same size"));
  }
}

TEST(sub_test_3, sub) {
  S21Matrix arr_1 = S21Matrix(2, 3);
  S21Matrix arr_2 = S21Matrix(2, 3);

  S21Matrix res = S21Matrix(2, 3);

  arr_1(0, 0) = 1;
  arr_1(0, 1) = 2;
  arr_1(0, 2) = 2;
  arr_1(1, 0) = 3;
  arr_1(1, 1) = 1;
  arr_1(1, 2) = 2;

  arr_2(0, 0) = 1;
  arr_2(0, 1) = 2;
  arr_2(0, 2) = 2;
  arr_2(1, 0) = 3;
  arr_2(1, 1) = 1;
  arr_2(1, 2) = 2;

  res(0, 0) = 0;
  res(0, 1) = 0;
  res(0, 2) = 0;
  res(1, 0) = 0;
  res(1, 1) = 0;
  res(1, 2) = 0;

  arr_1 -= arr_2;

  EXPECT_TRUE(arr_1.EqMatrix(res));
}

TEST(sub_test_4, sub) {
  S21Matrix arr_1 = S21Matrix(2, 3);
  S21Matrix arr_2 = S21Matrix(2, 3);

  S21Matrix res = S21Matrix(2, 3);

  arr_1(0, 0) = 1;
  arr_1(0, 1) = 2;
  arr_1(0, 2) = 2;
  arr_1(1, 0) = 3;
  arr_1(1, 1) = 1;
  arr_1(1, 2) = 2;

  arr_2(0, 0) = 1;
  arr_2(0, 1) = 2;
  arr_2(0, 2) = 2;
  arr_2(1, 0) = 3;
  arr_2(1, 1) = 1;
  arr_2(1, 2) = 2;

  res(0, 0) = 0;
  res(0, 1) = 0;
  res(0, 2) = 0;
  res(1, 0) = 0;
  res(1, 1) = 0;
  res(1, 2) = 0;

  arr_1 = arr_1 - arr_2;

  EXPECT_TRUE(arr_1.EqMatrix(res));
}

TEST(mulnum_test_1, mulnum) {
  S21Matrix arr = S21Matrix();
  S21Matrix res = S21Matrix();

  arr(0, 0) = 1;
  arr(0, 1) = 2;
  arr(1, 0) = 2;
  arr(1, 1) = 3;

  res(0, 0) = 3;
  res(0, 1) = 6;
  res(1, 0) = 6;
  res(1, 1) = 9;

  arr.MulNumber(3);
  EXPECT_TRUE(arr.EqMatrix(res));
}

TEST(mulnum_test_2, mulnum) {
  S21Matrix arr(2, 2);
  S21Matrix res(2, 2);

  arr(0, 0) = 1;
  arr(0, 1) = 2;
  arr(1, 0) = 2;
  arr(1, 1) = 3;

  res(0, 0) = 3;
  res(0, 1) = 6;
  res(1, 0) = 6;
  res(1, 1) = 9;

  arr.MulNumber(3.3);

  std::cout << arr(1, 1) << std::endl;
  std::cout << res(1, 1) << std::endl;
  EXPECT_FALSE(arr.EqMatrix(res));
}

TEST(mulnum_test_3, mulnum) {
  S21Matrix arr = S21Matrix();
  S21Matrix res = S21Matrix();

  arr(0, 0) = 1;
  arr(0, 1) = 2;
  arr(1, 0) = 2;
  arr(1, 1) = 3;

  res(0, 0) = 3.3;
  res(0, 1) = 6.6;
  res(1, 0) = 6.6;
  res(1, 1) = 9.9;

  arr = arr * 3.3;

  EXPECT_TRUE(arr.EqMatrix(res));
}

TEST(mulnum_test_4, mulnum) {
  S21Matrix arr = S21Matrix();
  S21Matrix res = S21Matrix();

  arr(0, 0) = 1;
  arr(0, 1) = 2;
  arr(1, 0) = 2;
  arr(1, 1) = 3;

  res(0, 0) = 3.3;
  res(0, 1) = 6.6;
  res(1, 0) = 6.6;
  res(1, 1) = 9.9;

  arr *= 3.3;
  EXPECT_TRUE(arr.EqMatrix(res));
}

TEST(mulnum_test_5, mulnum) {
  S21Matrix arr = S21Matrix();
  S21Matrix res = S21Matrix();

  arr(0, 0) = 1;
  arr(0, 1) = 2;
  arr(1, 0) = 2;
  arr(1, 1) = 3;

  res(0, 0) = 3.3;
  res(0, 1) = 6.6;
  res(1, 0) = 6.6;
  res(1, 1) = 9.9;

  arr = arr * 3.3;
  EXPECT_TRUE(arr.EqMatrix(res));
}

TEST(mulmat_test_1, mulmat) {
  S21Matrix arr_1(3, 3);
  S21Matrix arr_2(3, 3);
  S21Matrix res = S21Matrix(3, 3);

  arr_1(0, 0) = 1;
  arr_1(0, 1) = 2;
  arr_1(0, 2) = 2;
  arr_1(1, 0) = 3;
  arr_1(1, 1) = 3;
  arr_1(1, 2) = 3;
  arr_1(2, 0) = 3;
  arr_1(2, 1) = 3;
  arr_1(2, 2) = 4;

  arr_2(0, 0) = 1;
  arr_2(0, 1) = 2;
  arr_2(0, 2) = 2;
  arr_2(1, 0) = 3;
  arr_2(1, 1) = 3;
  arr_2(1, 2) = 3;
  arr_2(2, 0) = 3;
  arr_2(2, 1) = 3;
  arr_2(2, 2) = 4;

  res(0, 0) = 13;
  res(0, 1) = 14;
  res(0, 2) = 16;
  res(1, 0) = 21;
  res(1, 1) = 24;
  res(1, 2) = 27;
  res(2, 0) = 24;
  res(2, 1) = 27;
  res(2, 2) = 31;

  arr_1.MulMatrix(arr_2);

  EXPECT_TRUE(arr_1.EqMatrix(res));
}

TEST(mulmat_test_2, mulmat) {
  S21Matrix arr_1(3, 3);
  S21Matrix arr_2(2, 2);

  try {
    arr_1.MulMatrix(arr_2);
  } catch (const std::logic_error &err) {
    EXPECT_EQ(
        err.what(),
        std::string("Incorrect input, matrices should have the same size"));
  }
}

TEST(mulmat_test_3, mulmat) {
  S21Matrix arr_1(3, 3);
  S21Matrix arr_2(3, 3);
  S21Matrix res = S21Matrix(3, 3);

  res(0, 0) = 13;
  res(0, 1) = 14;
  res(0, 2) = 16;
  res(1, 0) = 21;
  res(1, 1) = 24;
  res(1, 2) = 27;
  res(2, 0) = 24;
  res(2, 1) = 27;
  res(2, 2) = 31;

  arr_1(0, 0) = 1;
  arr_1(0, 1) = 2;
  arr_1(0, 2) = 2;
  arr_1(1, 0) = 3;
  arr_1(1, 1) = 3;
  arr_1(1, 2) = 3;
  arr_1(2, 0) = 3;
  arr_1(2, 1) = 3;
  arr_1(2, 2) = 4;

  arr_2(0, 0) = 1;
  arr_2(0, 1) = 2;
  arr_2(0, 2) = 2;
  arr_2(1, 0) = 3;
  arr_2(1, 1) = 3;
  arr_2(1, 2) = 3;
  arr_2(2, 0) = 3;
  arr_2(2, 1) = 3;
  arr_2(2, 2) = 4;

  arr_1 = arr_1 * arr_2;

  EXPECT_TRUE(arr_1 == res);
}

TEST(mulmat_test_4, mulmat) {
  S21Matrix arr_1(3, 3);
  S21Matrix arr_2(3, 3);
  S21Matrix res = S21Matrix(3, 3);

  res(0, 0) = 13;
  res(0, 1) = 14;
  res(0, 2) = 16;
  res(1, 0) = 21;
  res(1, 1) = 24;
  res(1, 2) = 27;
  res(2, 0) = 24;
  res(2, 1) = 27;
  res(2, 2) = 31;

  arr_1(0, 0) = 1;
  arr_1(0, 1) = 2;
  arr_1(0, 2) = 2;
  arr_1(1, 0) = 3;
  arr_1(1, 1) = 3;
  arr_1(1, 2) = 3;
  arr_1(2, 0) = 3;
  arr_1(2, 1) = 3;
  arr_1(2, 2) = 4;

  arr_2(0, 0) = 1;
  arr_2(0, 1) = 2;
  arr_2(0, 2) = 2;
  arr_2(1, 0) = 3;
  arr_2(1, 1) = 3;
  arr_2(1, 2) = 3;
  arr_2(2, 0) = 3;
  arr_2(2, 1) = 3;
  arr_2(2, 2) = 4;

  arr_1 *= arr_2;

  EXPECT_TRUE(arr_1 == res);
}

TEST(transpose_test_1, transpose) {
  S21Matrix arr = S21Matrix(3, 3);
  S21Matrix res = S21Matrix(3, 3);

  res(0, 0) = 1;
  res(0, 1) = 3;
  res(0, 2) = 3;
  res(1, 0) = 2;
  res(1, 1) = 1;
  res(1, 2) = 3;
  res(2, 0) = 2;
  res(2, 1) = 2;
  res(2, 2) = 1;

  arr(0, 0) = 1;
  arr(0, 1) = 2;
  arr(0, 2) = 2;
  arr(1, 0) = 3;
  arr(1, 1) = 1;
  arr(1, 2) = 2;
  arr(2, 0) = 3;
  arr(2, 1) = 3;
  arr(2, 2) = 1;

  arr = arr.Transpose();
  EXPECT_TRUE(arr.EqMatrix(res));
}

TEST(inverse_test_1, inverse) {
  S21Matrix arr = S21Matrix(3, 3);
  S21Matrix res = S21Matrix(3, 3);

  res(0, 0) = -5. / 13;
  res(0, 1) = 4. / 13;
  res(0, 2) = 2. / 13;
  res(1, 0) = 3. / 13;
  res(1, 1) = -5. / 13;
  res(1, 2) = 4. / 13;
  res(2, 0) = 6. / 13;
  res(2, 1) = 3. / 13;
  res(2, 2) = -5. / 13;

  arr(0, 0) = 1;
  arr(0, 1) = 2;
  arr(0, 2) = 2;
  arr(1, 0) = 3;
  arr(1, 1) = 1;
  arr(1, 2) = 2;
  arr(2, 0) = 3;
  arr(2, 1) = 3;
  arr(2, 2) = 1;

  arr = arr.InverseMatrix();

  EXPECT_TRUE(arr.EqMatrix(res));
}

TEST(inverse_test_2, inverse) {
  S21Matrix arr;

  arr(0, 0) = 1;
  arr(0, 1) = -1;
  arr(1, 0) = 1;
  arr(1, 1) = -1;

  try {
    arr.InverseMatrix();
  } catch (const std::invalid_argument &err) {
    EXPECT_EQ(err.what(),
              std::string("Impossible inverse matrix, determinant is 0"));
  }
}

TEST(setter_getter_test_1, setter_getter) {
  S21Matrix arr(3, 5);

  EXPECT_EQ(arr.getCols(), 5);
  EXPECT_EQ(arr.getRows(), 3);

  arr.setCols(3);
  arr.setRows(1);

  EXPECT_EQ(arr.getCols(), 3);
  EXPECT_EQ(arr.getRows(), 1);

  arr.setCols(10);
  arr.setRows(6);

  EXPECT_EQ(arr.getCols(), 10);
  EXPECT_EQ(arr.getRows(), 6);
}

TEST(setter_getter_test_2, setter_getter) {
  S21Matrix arr(2, 2);
  S21Matrix res = S21Matrix(3, 3);

  res(0, 0) = 1;
  res(0, 1) = 2;
  res(0, 2) = 0;
  res(1, 0) = 2;
  res(1, 1) = 3;
  res(1, 2) = 0;
  res(2, 0) = 0;
  res(2, 1) = 0;
  res(2, 2) = 0;

  arr(0, 0) = 1;
  arr(0, 1) = 2;
  arr(1, 0) = 2;
  arr(1, 1) = 3;

  arr.setCols(3);
  arr.setRows(3);

  EXPECT_EQ(arr.getCols(), 3);
  EXPECT_EQ(arr.getRows(), 3);

  EXPECT_EQ(arr == res, true);
}

TEST(setter_getter_test_3, setter_getter) {
  S21Matrix arr(2, 2);

  try {
    arr.setRows(-1);
  } catch (const std::invalid_argument &err) {
    EXPECT_EQ(err.what(), std::string("The value should be positive"));
  }
}

TEST(setter_getter_test_4, setter_getter) {
  S21Matrix arr(2, 2);

  try {
    arr.setCols(-1);
  } catch (const std::invalid_argument &err) {
    EXPECT_EQ(err.what(), std::string("The value should be positive"));
  }
}

TEST(EqMatrix_test_1, create) {
  S21Matrix tmp(2, 3);
  S21Matrix tmp_check(2, 3);

  tmp(0, 0) = 1;
  tmp(0, 1) = 2;
  tmp(0, 2) = 2;
  tmp(1, 0) = 3;
  tmp(1, 1) = 1;
  tmp(1, 2) = 2;

  tmp_check(0, 0) = 1;
  tmp_check(0, 1) = 2;
  tmp_check(0, 2) = 2;
  tmp_check(1, 0) = 3;
  tmp_check(1, 1) = 1;
  tmp_check(1, 2) = 2;

  EXPECT_TRUE(tmp.EqMatrix(tmp_check));
}
TEST(EqMatrix_test_2, create) {
  S21Matrix tmp(2, 3);
  S21Matrix tmp_check(2, 3);

  tmp(0, 0) = 1;
  tmp(0, 1) = 2;
  tmp(0, 2) = 2;
  tmp(1, 0) = 3;
  tmp(1, 1) = 1;
  tmp(1, 2) = 2;

  tmp_check(0, 0) = 1;
  tmp_check(0, 1) = 2;
  tmp_check(0, 2) = 2;
  tmp_check(1, 0) = 3;
  tmp_check(1, 1) = 4;
  tmp_check(1, 2) = 3;

  EXPECT_FALSE(tmp.EqMatrix(tmp_check));
}

TEST(determinant_test_1, determinant) {
  S21Matrix arr = S21Matrix(5, 5);

  arr(0, 0) = 1;
  arr(0, 1) = 2;
  arr(0, 2) = 3;
  arr(0, 3) = 4;
  arr(0, 4) = 1;
  arr(1, 0) = 2;
  arr(1, 1) = 3;
  arr(1, 2) = 3;
  arr(1, 3) = 3;
  arr(1, 4) = 4;
  arr(2, 0) = 10;
  arr(2, 1) = 11;
  arr(2, 2) = 4;
  arr(2, 3) = 5;
  arr(2, 4) = 9.9;
  arr(3, 0) = 4.4;
  arr(3, 1) = 333;
  arr(3, 2) = 8;
  arr(3, 3) = 1.1;
  arr(3, 4) = 1;
  arr(4, 0) = 1;
  arr(4, 1) = 0;
  arr(4, 2) = 0;
  arr(4, 3) = 0;
  arr(4, 4) = 0;

  EXPECT_NEAR(arr.Determinant(), 7949.67, 1e-7);
}

// TEST(determinant_test_2, determinant) {
//   S21Matrix arr = S21Matrix();

//   arr(0, 0) = 1;
//   arr(0, 1) = 2;
//   arr(1, 0) = 2;
//   arr(1, 1) = 3;

//   EXPECT_NEAR(arr.Determinant(), -1, 1e-7);
// }
TEST(Determinant, true) {
  S21Matrix matrix_a(1, 1);
  matrix_a(0, 0) = 1;
  ASSERT_TRUE(matrix_a.Determinant() == 1);
}

TEST(CalcComplements, False) {
  S21Matrix matrix_a(2, 3);
  EXPECT_THROW(matrix_a.CalcComplements(), std::logic_error);
}

TEST(determinant_test_2, determinant) {
  S21Matrix arr = S21Matrix(1, 1);

  EXPECT_EQ(arr.Determinant(), 0);
}

TEST(determinant_test_3, determinant) {
  S21Matrix arr = S21Matrix(2, 3);

  arr(0, 0) = 1;
  arr(0, 1) = 2;
  arr(0, 2) = 2;
  arr(1, 0) = 3;
  arr(1, 1) = 1;
  arr(1, 2) = 2;

  try {
    arr.Determinant();
  } catch (const std::logic_error &err) {
    EXPECT_EQ(err.what(), std::string("Incorrect input, calculation error"));
  }
}

TEST(idx_test_1, idx) {
  try {
    S21Matrix a(2, 2);
    a(0, -0) = -1;

  } catch (const std::out_of_range &err) {

    EXPECT_EQ(err.what(), std::string("Index out of range"));
  }
}

TEST(idx_test_2, idx) {
  S21Matrix arr = S21Matrix(2, 3);
  EXPECT_ANY_THROW(arr(-1, 0) = 1);
}

TEST(idx_test_3, idx) {
  const S21Matrix  arr = S21Matrix(2, 3);
  EXPECT_ANY_THROW( arr(-1, 0));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  ::testing::InitGoogleMock(&argc, argv);

  return RUN_ALL_TESTS();
}
