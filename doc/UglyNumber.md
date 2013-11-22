# Combination Ugly Number Problem

## Description

Given a string representation of number , eg. "12345", find how many combinations are ugly. 

A combination is any string of "+", "-", or "" (connection), at any possible location in the string , eg. "1+23-4+5". There are 3^(n-1) combinations , assuming there are n digits. 

## Solution 

1. start from last digit , called 'tail' and increasing the length of 'tail'
2. Markov assumption: at 'tail' length m, only the result computed in last tail (ie. tail with length m-1) is reused.
3. for a tail with length m, use a trinary code with length (m-1) to represent the combination 

		trinary mapping: "" ==> 0 , "+" ==> 1 and "-" ==> 2
        for example "1+23-4+5" is represented by trinary code (1021)
				   = 1*3^3 + 0*3^2 + 2*3^1 + 1*3^0 = 34
4. use the trinary code computed above to index the combination result stored
5. use Dynamic Programming to find each combination, start from tail number = 0, 1, 2,..., n-1. 
6. run time O(3^(n-1))

## Details

### Incremental new digit
Given input "12345" tail "345" is stored in array tailTable[] as

	tailTable[9] of tail "345"
	value | 345 | 34+5 | 34-5 | 3+45 | 3+4+5 | 3+4-5 | 3-45 | 3-(4+5) | 3-(4-5) |  
	index | 00  |  01  |  02  | 10   | 11    | 12    | 20   | 21      | 22      |

Then we want to compute the tail "2345"  

	for index 000, that is the number 2345  = 2*1000+tailTable[00]  
	for index 001, that is the number 234+5 = 2*100 +tailtable[01]  
	for index 010, that is the number 23+45 = 2*10  +tailtable[10]  

We can find that, the new digit "2" in the new tail "2345" is multiplied by 1000, 100 or 10 respectively, called incremental. The incremental is depends on how many '0's in from MSB to the first nonzero in the index. For example, '000' has 3 zeros, so the incremental 1000. 

### In case the new digit is "0"

There is no need to compute again (as well as no incremental is necessary). Just copy the previous tail twice to current tail. 

### Early break in checking is a number is ugly

Since the probability of a number is divided by 2,3,5,7 is decreasing, in isUgly() function, check %2 first, then %3, then %5 and last %7. 

## Disadvantages of this algorithm

### Storage cost
The program need to maintain two tail tables, each of them requires 3^(n-1) elements. Each elements requires 2^ceil(log2(10^n-1)) bits. For example, when the input is restrict to at most 13 digits, that require 64 bit (long integer) for the tail table. And the memory cost is 2*64*3^(13-1)/8 = 8MB. 

## Future improvement

### number start with "0"
The ugly count of number start with k 0s is 

	3^k * countUgly(s.substr(k+1,n-k)); 