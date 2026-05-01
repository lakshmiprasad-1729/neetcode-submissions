class Solution {
public:
    int climbStairs(int n) {
        int prev , curr; prev = 0 , curr = 1;
        for(int i = 1 ; i <= n ; i++){
            int value = 0;
            if( i-1 >= 0) value +=curr;
            if(i-2 >= 0) value +=prev;
            prev = curr;
            curr = value;
        }
        return curr;
    }
};
