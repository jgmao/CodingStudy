#include "gtest/gtest.h"
#include "CodingStudy.h"
using namespace study;
//TEST(CyclicSortedList, insert)
//{
//    CyclicSortedList csl;
//    csl.insert(csl.head, 1);
//    csl.insert(csl.head, 5);
//    csl.insert(csl.head, 3);
//    csl.insert(csl.head->next->next, 4);
//    ListNode* nd = csl.head;
//    int rst[] = {1,3,4,5};
//    int p = 0;
//    while (nd!=nullptr) {
//        EXPECT_EQ(nd->value, *(rst+p));
//        p++;
//        nd=nd->next;
//    }
//}

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

TEST(StringProblem, removeDuplicate) {
    std::string str = "abccbda";
    removeDuplicateBitMap(str);
    EXPECT_EQ("abcd", str);
    str = "sfdfafs";
    removeDuplicateHashMap(str);
    EXPECT_EQ("sfda", str);
}

TEST(StringProblem, isAnagram){
    std::string str1 = "williamshakespeare";
    std::string str2 = "iamaweakishspeller";
    std::string str3 = "iamaweakishapeller";
    EXPECT_TRUE(isAnagram(str1, str2));
    EXPECT_FALSE(isAnagram(str1, str3));
}

TEST(MatrixProblem, rotate90){
    uint32_t im1[] = {1,2,3,4,5,6,7,8,9};
    uint32_t im2[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    rotate90(im1,3);
    EXPECT_EQ(3,im1[0]);
    EXPECT_EQ(9,im1[2]);
    EXPECT_EQ(8,im1[5]);
    EXPECT_EQ(5,im1[4]);
    rotate90(im2,4);
    EXPECT_EQ(4,im2[0]);
    EXPECT_EQ(12,im2[2]);
    EXPECT_EQ(9,im2[10]);
    EXPECT_EQ(7,im2[5]);
}

TEST(ShortestPath, ShortestWordDistance){
    int rst = ShortestWordDistance("../../../res/three.txt");
    EXPECT_EQ(0,rst);
}