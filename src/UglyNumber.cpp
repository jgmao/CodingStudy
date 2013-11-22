#include <vector>
#include <CodingStudy.h>
#include <string>
namespace study
{
    long* tail; //
    long* temptail;
     
    int isUgly(long g)
    {
        //ordered check, from most likely to most unlikely, which can break early and speed up
        if (g==0) return 1;
        if (g%2==0) return 1;
        if (g%3==0) return 1;
        if (g%5==0) return 1;
        if (g%7==0) return 1;
        return 0;
    }

    int processTail(std::string& left, std::string& right)
    {
        int n = left.size();//left is the head in string
        int m = right.size();//right is the tail in string
        int count=0;
        long a = atol(left.c_str());//a is the head in long
        long b = atol(right.c_str());//b is the tail in long
        long newDigit = atol(right.substr(0,1).c_str());
        if (m==0)
        {
            count = isUgly(a); //check the entire number ==> trinary all 0 case
        }
        else if (m==1)
        {
            // check when tail length 1
            count+= isUgly(a+b);
            count+= isUgly(a-b);
            tail[0] = b;
        }
        else
        {
            uint32_t nTailLast = pow(3,m-2);//number of combinations of last tail
            uint32_t nTailCurr = nTailLast*3; // number of combinations of current tail
            long increment = pow(10, m-1); //increment depends on the length of connected tail ==> number of successive 0 in the tail
            long incrementChangePosition = 1;
            for (uint32_t i=0; i< nTailLast; i++) //compute new tail table
            {
                if (newDigit == 0) //save computation
                {
                    temptail[i] = tail[i];      // symbol 0 ==> connection
                    temptail[nTailLast+i] = tail[i];      // symbol 1 ==> +
                    temptail[2*nTailLast+i] = -tail[i];  
                }
                else
                {
                    if (i==incrementChangePosition)
                    {
                        increment /= 10;
                        incrementChangePosition *=3;
                    }
                    temptail[i] = newDigit*increment+tail[i];      // symbol 0 ==> connection
                    temptail[nTailLast+i] = newDigit+tail[i];      // symbol 1 ==> +
                    temptail[2*nTailLast+i] = newDigit-tail[i];    // symbol 2 ==> -
                }
                
            }

            for (uint32_t i=0; i< nTailCurr; i++) //use new tail table to count ugly
            {
                count+= isUgly(a+temptail[i]);
                count+= isUgly(a-temptail[i]);
            }

            // update tail table
            for (uint32_t i=0; i< nTailCurr; i++) 
            {
                tail[i] = temptail[i];
            }
        }
        return count;
    }

    int countUgly(std::string& s){
        int n = s.size();
        long tableLen = 1;
        for (int i=0; i<n-1; i++)
        {
            tableLen*=3;
        }
        tail = new long[tableLen];
        temptail = new long[tableLen];
        int count=0;
        for (int i=n; i>0; i--)
            count+= processTail(s.substr(0,i),s.substr(i,n-i));
        delete[] tail;
        delete[] temptail;
        return count;
    }

}









