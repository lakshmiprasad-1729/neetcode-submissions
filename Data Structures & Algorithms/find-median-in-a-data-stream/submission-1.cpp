class MedianFinder {
public:
    priority_queue<int,vector<int>,greater<int>> mini;
    priority_queue<int> maxi;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int n = mini.size(),  m = maxi.size();
         if(n == 0)  mini.push(num);
         else{
            if((int)mini.top() <= num) mini.push(num);
            else maxi.push(num);
         }
        while((int)mini.size()-(int)maxi.size() > 1){
           maxi.push(mini.top());
           mini.pop();
        }
        while((int)maxi.size()-(int)mini.size() > 1){
            mini.push(maxi.top());
            maxi.pop();
        }
    }
    
    double findMedian() {
        int n = mini.size() , m = maxi.size();
        if(n==m){
            double a = mini.top();
            return (a+maxi.top())/2;
        }
        if(m > n) return maxi.top();
        return mini.top();
    }
};
