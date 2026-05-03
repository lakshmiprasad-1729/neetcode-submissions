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
    int minMeetingRooms(vector<Interval>& v) {
         int n = v.size();
         if(n==0) return 0;
        priority_queue<int,vector<int>,greater<int>> pq;
        sort(v.begin(),v.end(),[](Interval& a,Interval& b){
            if(a.start == b.start) return a.end < b.end;
            return a.start < b.start;
        });
        int ans = 1;
       pq.push(v[0].end);
        for(int i = 1 ; i < n ; i++){
            int a = v[i].start, b = v[i].end;
            if(pq.top() <= a) pq.pop() , pq.push(b);
            else pq.push(b);
           ans = max(ans,(int)pq.size());
        }
        return ans;
    }
};
