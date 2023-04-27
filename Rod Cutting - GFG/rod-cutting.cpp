//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int dp[1001][1001];
    int solve(int i, int n, int price[], int length[]){//len as val
        if(i <= 0 || n == 0) return 0;
        if(dp[i][n] != -1) return dp[i][n];
        int cut = 0, noCut = 0;
        noCut = solve(i - 1, n, price, length);
        if(length[i - 1] <= n){
            cut = solve(i, n - length[i - 1], price, length) + price[i - 1];
        }
        return dp[i][n] = max(cut, noCut);
        
        
    }
    int cutRod(int price[], int n) {
        int length[n];
        for(int i = 1; i <= n; i++) length[i - 1] = i;
        memset(dp, -1, sizeof dp);
        return solve(n, n, price, length);
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends