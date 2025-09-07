/*
Find N Unique Integers Sum up to Zero  LC-1304 , LC-easy   
Link: https://leetcode.com/submissions/detail/1762305018
Prerequisties- nothing

Question- Given an integer n, return any array containing n unique integers such that they add up to 0.
Example 1:

Input: n = 5
Output: [-7,-1,1,3,4]
Explanation: These arrays also are accepted [-5,-1,1,2,3] , [-3,-1,2,-2,4].

Concept - check comments 

Approach- easy peasy.
solution-
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;

        // If n is even, we don't include 0
        // Example: n = 4 → [-1, -2, 1, 2]
        if (n % 2 == 0) {
            for (int i = 1; i <= n / 2; i++) {
                ans.push_back(-i); // add negative number
                ans.push_back(i);  // add its positive counterpart
            }
        } 
        // If n is odd, we include 0 in the middle
        // Example: n = 5 → [-1, -2, 0, 1, 2]
        else {
            ans.push_back(0); // place 0 in the middle
            for (int i = 1; i <= n / 2; i++) {
                ans.push_back(-i); // add negative number
                ans.push_back(i);  // add its positive counterpart
            }
        }

        return ans;
    }
};
