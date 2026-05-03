/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& v) {
         int n = v.size();
         if(n==0) return true;
        priority_queue<int,vector<int>,greater<int>> pq;
        sort(v.begin(),v.end(),[](Interval& a,Interval& b){
            if(a.start == b.start) return a.end < b.end;
            return a.start < b.start;
        });
       pq.push(v[0].end);
        for(int i = 1 ; i < n ; i++){
            int a = v[i].start, b = v[i].end;
            if(pq.top() <= a) pq.pop() , pq.push(b);
            else pq.push(b);
            if(pq.size() > 1) return false;
        }
        return true;
        
    }
};
