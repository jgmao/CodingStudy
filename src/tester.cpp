#include "gtest/gtest.h"
#include "CodingStudy.h"
#include <CodingStudy.h>
using namespace study;
TEST(RegularExpressionMatchTest, isMatch) {
    EXPECT_FALSE(isMatch("", "."));
    EXPECT_TRUE(isMatch("a","ab*"));
    EXPECT_FALSE(isMatch("aa","a"));
    EXPECT_TRUE(isMatch("aa","aa"));
    EXPECT_FALSE(isMatch("aaa","aa"));
    EXPECT_TRUE(isMatch("aa", "a*"));
    EXPECT_TRUE(isMatch("aa", ".*"));
    EXPECT_TRUE(isMatch("ab", ".*"));
    EXPECT_TRUE(isMatch("aab", "c*a*b"));
    EXPECT_FALSE(isMatch("acaabbaccbbacaabbbb", "a*.*b*.*a*aa*a*"));
}
