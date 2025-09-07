/*
Minimum Operations to Make Array Elements Zero  LC-3495 , LC-hard   
Link: https://leetcode.com/submissions/detail/1761685496
Prerequisties- nothing

Question- You are given a 2D array queries, where queries[i] is of the form [l, r]. Each queries[i] 
defines an array of integers nums consisting of elements ranging from l to r, both inclusive.
In one operation, you can: Select two integers a and b from the array.
Replace them with floor(a / 4) and floor(b / 4).
Your task is to determine the minimum number of operations required to 
reduce all elements of the array to zero for each query. Return the sum of the results for all queries..

Concept - first of all [[a,b]] [a,b] represents an array starting from a ending with b a,a+1,a+2 ... b.

at a time we can pick two elements and then floor(a / 4) and floor(b / 4). 
so we ca pick the max1 and maxi2 from the array to get the answer.
what we can do is we will insert the elements in a max heap for this an do the op this is a brute way of doing
it.


we have to take floor with 4 right 
so we can draw some pattern for this which is 
 from 1 - 3 we need only 1 op 
 from 4 to 15 we need only 2 op 
 from 16 to 63 we need only 3 step 
 from 4 power (s-1)  - 4 power s -1 we need s op 

 now for l to r just have to check this following pattern to get to the answer 

 now for every elements s1+s2+s3 .. for each elements to get to zero
 therefore ans is total/2 as we can pick 2 elements 

Approach- couldn't think of any approach so watched video from code with mik.
solution-
*/

#include<bits/stdc++.h>
using namespace std;

//T.C : O(Q * log(max r)), Q =  number of queries, r = right value of ranges
//S.C : O(1)
class Solution {
public:

    long long solve(int l, int r) {
        //L, R
        //1 to 3 : 1 steps
        //4 to 15 : 2 steps
        long long L = 1; //R = 4*L-1
        long long S = 1;
        long long steps = 0;

        while(L <= r) {
            long long R = 4*L - 1;

            long long start = max(L, (long long)l);
            long long end   = min(R, (long long)r);

            if(start <= end) {
                steps += (end-start+1)*S;
            }

            S += 1;
            L = L*4;
        }

        return steps;
    }

    long long minOperations(vector<vector<int>>& queries) {
        long long result = 0;

        for(auto &query : queries) {
            int l = query[0];
            int r = query[1];

            long long steps = solve(l, r);

            result += (steps+1)/2;
        }

        return result;
    }
};