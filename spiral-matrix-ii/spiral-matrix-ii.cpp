class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n , vector<int> (n)); 
        int top = 0, left = 0, right = n - 1, bottom = n - 1, val = 1;
        while(top <= bottom and left <= right){
        for(int i = left; i <= right; ++i, val++){
            mat[top][i] = val;
        }
        top++;
        for(int i = top; i<= bottom; ++i, val++){
            mat[i][right] = val;
        }
        right--;
        // if(left <= right){
            for(int i = right; i >= left; --i, val++){
                mat[bottom][i] = val;
            }
            bottom --;
        // }
        // if(top <= bottom){
            for(int i = bottom; i >= top; --i, val++){
                mat[i][left] = val;
            }
            left++;
        // }
        }
        return mat;
    }
};