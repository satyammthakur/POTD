/*
Find the Number of Ways to Place People I  LC-3025 , LC-Medium
Link: https://leetcode.com/submissions/detail/1755461723/
Prerequisties- nothing as such

Question- You are given a 2D array points of size n x 2 representing integer coordinates of some points on a 
2D plane, where points[i] = [xi, yi]. Count the number of pairs of points (A, B), where
A is on the upper left side of B, and
there are no other points in the rectangle (or line) they make (including the border).
Return the count.

Concept - brute as constraints were too low

already solved , it's potd of 15 dec 2024.
Approach- solved by my own , brute wrote 

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
};