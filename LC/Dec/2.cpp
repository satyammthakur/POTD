/*
Count Number of Trapezoids I LC-3623     , LC-Medium
Link: https://leetcode.com/submissions/detail/1845061942
Prerequisties- nothing as such

Question- You are given a 2D integer array points, where points[i] = [xi, yi] represents the coordinates 
of the ith point on the Cartesian plane. A horizontal trapezoid is a convex quadrilateral with at least 
one pair of horizontal sides (i.e. parallel to the x-axis). Two lines are parallel if and only if they 
have the same slope. Return the number of unique horizontal trapezoids that can be formed by choosing 
any four distinct points from points.
Since the answer may be very large, return it modulo 10^9 + 7.

Concept - math , geometry , array , hashtable

already solved , it's potd of 15 dec 2024.
Approach- 

we have to make trapezoids it means two sides of the fig should be parallel 
i.e points that come under horizontal line ==> same y coordinate 

now we will first find the number of points on that horizontal 
and then we have to count no. of lines we can make using that line 
nc2.

and similarly find how many horizontal lines we can find and similary calulate counts for each one 
and multiply everything to get the answer for the curr two lines
for the next line we have to maintain the prev lines so.
TC - o(n) at worst case 
SC - o(n)
Solution- 
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int M = 1e9+7;
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int,int> mpp;
        for(auto &point : points){
            int y = point[1];
            mpp[y]++;
        }

        long long res = 0;
        long long prevHorizontalLines = 0 ; 

        for(auto &it : mpp){
            int cnt = it.second;
            long long horizontalLines = cnt*(cnt-1)/2;

            res += horizontalLines*prevHorizontalLines;
            prevHorizontalLines += horizontalLines;
        }

        return res%M;
    }
};