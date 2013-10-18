#include "gtest/gtest.h"
#include "CodingStudy.h"
#include <CodingStudy.h>
using namespace study;
TEST(CyclicSortedList, insert)
{
    CyclicSortedList csl;
    csl.insert(csl.head, 1);
    csl.insert(csl.head, 5);
    csl.insert(csl.head, 3);
    csl.insert(csl.head->next->next, 4);
    ListNode* nd = csl.head;
    int rst[] = {1,3,4,5};
    int p = 0;
    while (nd!=nullptr) {
        EXPECT_EQ(nd->value, *(rst+p));
        p++;
        nd=nd->next;
    }
}

TEST(SingleNumber, signelNumber){
    int A[] = {2,2,1};
    EXPECT_EQ(singleNumber(A,3),1);
}

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
