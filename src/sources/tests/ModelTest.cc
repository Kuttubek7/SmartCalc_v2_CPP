#include "ModelTest.h"

#include "CalcModel.h"

namespace {

#define EXP 1e-7

TEST(ModelTest, arithmetic_test_00) {
  s21::CalcModel model;
  EXPECT_NEAR(model.Calculate("21-42+21"), 0.0, EXP);
}

TEST(ModelTest, arithmetic_test_01) {
  s21::CalcModel model;
  EXPECT_NEAR(model.Calculate("21*2/21^3.14159"), 0.0029469, EXP);
}

TEST(ModelTest, arithmetic_test_02) {
  s21::CalcModel model;
  EXPECT_NEAR(model.Calculate("8%2"), 0.0, EXP);
}

TEST(ModelTest, arithmetic_test_03) {
  s21::CalcModel model;
  EXPECT_NEAR(model.Calculate("7%2"), 1.0, EXP);
}

TEST(ModelTest, arithmetic_test_04) {
  s21::CalcModel model;
  EXPECT_NEAR(model.Calculate("sin(3)+cos(3)"), -0.8488724, EXP);
}

TEST(ModelTest, arithmetic_test_05) {
  s21::CalcModel model;
  EXPECT_NEAR(model.Calculate("asin(1)+acos(0)"), 3.1415926, EXP);
}

TEST(ModelTest, arithmetic_test_06) {
  s21::CalcModel model;
  EXPECT_NEAR(model.Calculate("tan(1)+atan(0)"), 1.5574077, EXP);
}

TEST(ModelTest, arithmetic_test_07) {
  s21::CalcModel model;
  EXPECT_NEAR(model.Calculate("log(10) + ln(10)"), 3.3025850, EXP);
}

TEST(ModelTest, arithmetic_test_08) {
  s21::CalcModel model;
  EXPECT_NEAR(model.Calculate("sqrt(2)"), 1.4142135, EXP);
}

TEST(ModelTest, arithmetic_test_09) {
  s21::CalcModel model;
  EXPECT_NEAR(model.Calculate("2+2*(2+2*(2+2*(2+2*(2+2))))"), 94.0, EXP);
}

TEST(ModelTest, arithmetic_test_10) {
  s21::CalcModel model;
  EXPECT_NEAR(model.Calculate("-1+2"), 1.0, EXP);
}

TEST(ModelTest, arithmetic_test_11) {
  s21::CalcModel model;
  EXPECT_NEAR(model.Calculate("1+(-2)"), -1.0, EXP);
}

TEST(ModelTest, arithmetic_test_12) {
  s21::CalcModel model;
  EXPECT_NEAR(model.Calculate("X^2"), 0.0, EXP);
  model.UpdateX(2);
  EXPECT_NEAR(model.Calculate("X^2"), 4.0, EXP);
}

TEST(ModelTest, exception_test_00) {
  s21::CalcModel model;
  double tmp = 0.0;
  EXPECT_THROW(tmp = model.Calculate("((1+1)"), std::exception);
  EXPECT_NEAR(tmp, 0, EXP);
}

TEST(ModelTest, exception_test_01) {
  s21::CalcModel model;
  double tmp = 0.0;
  EXPECT_THROW(tmp = model.Calculate("+-+"), std::exception);
  EXPECT_NEAR(tmp, 0, EXP);
}

TEST(ModelTest, exception_test_02) {
  s21::CalcModel model;
  double tmp = 0.0;
  EXPECT_THROW(tmp = model.Calculate("inf"), std::exception);
  EXPECT_NEAR(tmp, 0, EXP);
}

}  // namespace