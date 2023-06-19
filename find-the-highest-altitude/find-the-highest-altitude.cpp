class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        for(int i = 1; i < gain.size(); ++i){
            gain[i] += gain[i-1];
        }
        gain.push_back(0);
        return *max_element(gain.begin(), gain.end());
    }
};