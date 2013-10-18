//
//  SingleNumber.cpp
//  CodingStudy
//
//  Created by Guoxin Jin on 10/2/13.
//  Copyright (c) 2013 Guoxin Jin. All rights reserved.
//
/*
 Given an array of integers, every element appears twice except for one. Find that single one.
 
 Could you implement it without using extra memory?
*/
namespace study{
 int singleNumber(int A[], int n) {
     for (int i=1; i< n ;i++)
     {
         A[0]=A[i]^A[0];
     }
     return A[0];
     
 }
}