/*
Find closest person  LC-3516 , LC-easy
Link: https://leetcode.com/submissions/detail/1758916546/
Prerequisties- nothing

Question- given 3 person standing in a line on x axis-
Return 1 if Person 1 arrives first.
Return 2 if Person 2 arrives first.
Return 0 if both arrive at the same time

Concept - nothing 

Approach- look at the code and get it very simple 
solution-
*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findClosest(int x, int y, int z) {
        if(abs(x-z)==abs(y-z)) return 0;
        else if(abs(x-z)>abs(y-z)) return 2;
        else return 1;
    }
};