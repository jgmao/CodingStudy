
#include "gtest/gtest.h"
#include <stdio.h>
#include <CodingStudy.h>
GTEST_API_ int main(int argc, char **argv) {
 // study::isMatch("acaabbaccbbacaabbbb", "a*.*b*.*a*aa*a*");
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}