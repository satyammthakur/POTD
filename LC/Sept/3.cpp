/*
Find the Number of Ways to Place People II  LC-3027 , LC-Hard
Link: https://leetcode.com/submissions/detail/1758631606/
Prerequisties- 3025 

Question- You are given a 2D array points of size n x 2 representing integer coordinates of some points on a 
2D plane, where points[i] = [xi, yi]. Count the number of pairs of points (A, B), where
A is on the upper left side of B, and
there are no other points in the rectangle (or line) they make (including the border).
Return the count. 
[same as before ques, just used some story to conclude the question]

Concept - can't use brute here as constraints are enough.

Approach- used the yesterday's brute approach to optimise it, using sorting we will further reduce the solution

first pick one point and then find the point which is in upper left of that point, when u get the point we will
check for all the point except for i and j, whether any point lie on that rectangular region made by these two 
points or not if we couldn't find anything then we will just increase our cnt else we will just move away

TC - o(n cube) at worst case 
Solution- 
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(int x1, int y1, int x2, int y2) { return x1 >= x2 && y1 <= y2; }
    bool check1(int x1, int y1, int x2, int y2, int x3, int y3) {
        return (min(x1, x2) <= x3 && x3 <= max(x1, x2) && min(y1, y2) <= y3 && y3 <= max(y1, y2));
    }
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j = 0; j < n ; j++) {
                if(i==j) continue;
                int x2 = points[j][0];
                int y2 = points[j][1];
                if (check(x1, y1, x2, y2)) {
                    int tempcnt = 0;
                    for (int k = 0; k < n; k++) {
                        if (k == i || k == j)
                            continue;
                        int x3 = points[k][0];
                        int y3 = points[k][1];
                        if (check1(x1, y1, x2, y2, x3, y3)) {
                            tempcnt++;
                        }
                    }
                    if(tempcnt==0) cnt++;
                }
            }
        }
        return cnt;
    }

    // approach 2(used in this ques)
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();

        // Sort: x ascending, if x same then sort as y descending
        auto lambda = [](vector<int>& point1, vector<int>& point2) {
            if (point1[0] == point2[0]) {
                return point1[1] > point2[1];
            }
            return point1[0] < point2[0];
        };

        sort(points.begin(), points.end(), lambda); // O(nlogn)

        int result = 0;

        for (int i = 0; i < n; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];   // upper left

            int bestY = INT_MIN;

            for (int j = i + 1; j < n; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];   // lower right

                // Condition: (x2, y2) must be above (x1, y1)
                if (y2 > y1) { //not lower right
                    continue;
                }

                if (y2 > bestY) {
                    result++;
                    bestY = y2;
                }
            }
        }

        return result;
    }
};