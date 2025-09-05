/*
Minimum Operations to Make the Integer Zero  LC-2749 , LC-easy
Link: https://leetcode.com/submissions/detail/1760834320/
Prerequisties- nothing

Question- You are given two integers num1 and num2.In one operation, you can choose integer 
i in the range [0, 60] and subtract pow(2,i) + num2 from num1. Return the integer denoting the minimum 
number of operations needed to make num1 equal to 0.
If it is impossible to make num1 equal to 0, return -1.

Concept - 
1st : num1` = num1 - (2^i1 + num2)
2nd : num1`` = num1` - (2^i2 + num2) = num1 - (2^i1+num2) - (2^i2 +num2) = num1 - 2*num2 -(2^i1+2^i2);
3rd : num2``` = num2`- (2^i3 + num2) = further solving = num1 - 3*num2 - (2^i1+2^i2 +2^i3);

similary after t times = num1```t=0 
0 = num1 - t*num2 - (2^i1+2^i2 +..+ 2^it);
num1 - t*num2 = (2^i1+2^i2 +..+ 2^it);

now start t with zero , for every t we will find val = num1 - t*num2 
now the bits of val will tell us about the min operation if the number of set bits in val is <=t && t<=val
that t will be your ans else increase t++.

dry run on the example test case 1 
num1 = 3 , num2 =-2;
t=0 -> val = 3 -> set bits 2 t =0 ; setbits>t ==> t++
t=1 -> val = 7 -> set bits 3 t=1 ; setbits>t ==> t++
t=2 -> val = 9 -> set bits 2 t=2 ; setbits<=t && t<=val therefore this t will be our answer


num1=5 , num2=7;
t=0 -> val = 5 -> setbits 2 t=0 ; setbits>t ==> t++;
t=1 -> val = -2 val<0 return -1;
Approach- couldn't think of any approach so watched video from code with mik.
solution-
*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        int t=0;
        while(true){
            long long val = (long long)num1 - (long long)t*num2;
            if(val<0) return -1;
            if(__builtin_popcountll(val)<=t && t<=val){
                return t;
            }
            t++;
        }
        return -1;
    }
};
