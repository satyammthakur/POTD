/*
Convert Integer to the Sum of Two No-Zero Integers  LC-1317 , LC-easy   
Link: https://leetcode.com/submissions/detail/1763554144/
Prerequisties- nothing

Question- No-Zero integer is a positive integer that does not contain any 0 in its decimal representation.
Given an integer n, return a list of two integers [a, b] where:
a and b are No-Zero integers.
a + b = n
The test cases are generated so that there is at least one valid solution. 
If there are many valid solutions, you can return any of them. 

Approach- easy peasy. check code self explanatory
solution-
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool nonzero(int n){
        while(n>=1){
            int rem = n%10;
            if(rem==0){
                return false;
            }
            n/=10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        vector<int>a(2);
        for(int i=1;i<=n;i++){
            int temp1 = i;
            int temp2 = n-i;
            if(nonzero(temp1) && nonzero(temp2)){
                a[0]=i;
                a[1]=n-i;
                break;
            
            }

        }
        return a;
    }
};
