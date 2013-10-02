#include "gtest/gtest.h"
#include "CodingStudy.h"
#include <CodingStudy.h>
using namespace study;
TEST(RegularExpressionMatchTest, isMatch) {
  EXPECT_FALSE(isMatch("acaabbaccbbacaabbbb", "a*.*b*.*a*aa*a*"));
}
