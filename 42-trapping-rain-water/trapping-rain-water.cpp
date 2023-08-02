class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0, l = 0, r = n - 1;
        int lMax = height[l], rMax = height[r];
        while(l < r){
            if(lMax <= rMax){
                l++;
                lMax = max(lMax, height[l]);
                ans += lMax - height[l];
            }
            else{
                r--;
                rMax = max(rMax, height[r]);
                ans += rMax - height[r];
            }
        }
        return ans;
    }
};