/*
Maximum Average Pass Ratio LC-1792 , LC-Medium
Link: https://leetcode.com/submissions/detail/1755461723/
Prerequisties- nothing as such

Question- You have several classes, each with a certain number of students passing and total students. 
You need to distribute extraStudents (who will definitely pass) among classes to maximize the average 
pass ratio across all classes.

Concept - greedy,priortiy_queue

already solved , it's potd of 15 dec 2024.
Approach- 

-- Pass ratio = (pass count / total) |||| avg pass = (sum(pass ration)/total).

1st- first we will calculate the pass ratio of given classes, and then later we will find updated pass ratio
which will include the extra student , we will only assign the extra student to those classes whose updated
pass ratio and original pass ratio has the biggest diff (ofc as we have to maximise the avg pass ratio) 
[reason for using delta is cause we coudln't decide which class to assign extrastudent if we just
go by min PR value or max PR value]
till extrastudent==0 we will repeat the above process of assiging extra students. now we will just find result
by using updated PR and then return our answer.

problem with this approach is- it will throw time limit exceeded. reason- O(n square)

2nd- to find the max delta we will use priority queue that's it . elese the core logic is same

TC - o(extrastudents*log(n)) at worst case 
Solution- 
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //Approach 1
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();

        vector<double> PR(n);
        for(int i = 0; i < n; i++) {
            double ratio = (double)classes[i][0]/classes[i][1];
            PR[i] = ratio;
        }

        while(extraStudents--) { //O(n)
            //student 0

            vector<double> updatedPR(n);
            for(int i = 0; i < n; i++) {
                double newRatio = (double)(classes[i][0]+1)/(classes[i][1]+1);
                updatedPR[i] = newRatio;
            }

            int bestClassIdx = 0;
            double bestDelta = 0;

            for(int i = 0; i < n; i++) { //O(n)
                double delta = updatedPR[i] - PR[i];
                if(delta > bestDelta) {
                    bestDelta = delta;
                    bestClassIdx = i;
                }
            }

            PR[bestClassIdx] = updatedPR[bestClassIdx];
            classes[bestClassIdx][0]++;
            classes[bestClassIdx][1]++;
        }

        double result = 0.0; //AR
        for(int i = 0; i < n; i++) {
            result += PR[i];
        }

        return result/n;
    }
    //Approach 2 
    #define P pair<double, int>
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();

        priority_queue<P> pq; //max-heap  -  //{max-delta, idx}

        for(int i = 0; i < n; i++) {
            double current_PR = (double)classes[i][0]/classes[i][1];
            double new_PR = (double)(classes[i][0]+1)/(classes[i][1]+1);
            double delta = new_PR - current_PR;
            pq.push({delta, i});
        }
        
        //O(extraStudents * log(n))
        while(extraStudents--) { //O(k)
            auto curr = pq.top(); //log(n)
            pq.pop();

            double delta = curr.first;
            int idx = curr.second;

            classes[idx][0]++; //incremeent total passing students in the class
            classes[idx][1]++; //increment total students in the class


            // after assigning extra student to one of the class we are updating our pass ratio
            double current_PR = (double)classes[idx][0]/classes[idx][1]; // after assiging one student current ratio
            double new_PR = (double)(classes[idx][0]+1)/(classes[idx][1]+1); // for delta we are checking if we 
            // we assign one more to the same class what would happen
            delta = new_PR - current_PR;
            pq.push({delta, idx}); //log(n)
        }

        double result = 0.0;
        for(int i = 0; i < n; i++) {
            result += (double)classes[i][0]/classes[i][1];
        }

        return result/n;
    }
};