//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int dp[101][10001];
    bool helper(vector<int> &arr, int sum, int i){
        if(sum == 0) return true;
        if(i < 0 || sum < 0) return false;
        if(dp[i][sum] != -1) return dp[i][sum];
        bool take = 0, noTake = 0;
        noTake = helper(arr, sum, i - 1);
        take = helper(arr, sum - arr[i], i - 1);
        return dp[i][sum] = take || noTake;
        
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        if(sum > 10000) return false;
        memset(dp, -1, sizeof dp);
        int n = arr.size();
        return helper(arr, sum, n - 1);
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