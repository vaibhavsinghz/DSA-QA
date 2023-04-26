//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int dp[101][10001];
    int solve(int target, int i, vector<int> &arr){
        if(target == 0) return 1;
        if(i < 0 || target < 0) return 0;
        if(dp[i][target] != -1) return dp[i][target];
        int takeIt = solve(target - arr[i], i - 1, arr);
        int discardIt = solve(target, i - 1, arr);
        return dp[i][target] = takeIt || discardIt;   
        
    }
    bool isSubsetSum(vector<int>arr, int sum){
        if(sum > 10000) return false;
        // code here 
        memset(dp, -1, sizeof dp);
        int n = arr.size();
        return solve(sum, n - 1, arr);
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends