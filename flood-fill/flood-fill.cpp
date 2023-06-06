class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j, int ic, int fc){
        int n = image.size(), m = image[0].size();
        if(i < 0 or i >= n) return;
        if(j < 0 or j >= m) return;
        if(image[i][j] != ic) return;
        image[i][j] = fc;
        dfs(image, i + 1, j, ic, fc);
        dfs(image, i - 1, j, ic, fc);
        dfs(image, i, j + 1, ic, fc);
        dfs(image, i, j - 1, ic, fc);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] != color)
            dfs(image, sr, sc, image[sr][sc], color);
        return image;
    }
};