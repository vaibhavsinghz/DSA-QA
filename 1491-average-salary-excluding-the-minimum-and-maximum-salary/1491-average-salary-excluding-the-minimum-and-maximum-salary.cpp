class Solution {
public:
    double average(vector<int>& salary) {
        int n = salary.size();
        double sum = 0.0;
        int maxm = 0, minm = INT_MAX;
        for(auto i: salary){
            maxm = max(i, maxm);
            minm = min(i, minm);
            sum += (double) i;
        }
        sum -= (double) (maxm + minm);
        n = n - 2;
        return sum / n;
    }
};