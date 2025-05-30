#include <bits/stdc++.h>
using namespace std;

int fin(int ind,vector<int> arr,vector<int>& dp)
{
    if(ind == 0)    return 0;
    
    if(dp[ind] != -1)   return dp[ind];
    
    int left = fin(ind-1,arr,dp) + abs(arr[ind] - arr[ind-1]);
    
    int right = INT_MAX;
    
    if(ind > 1)
        right = fin(ind - 2,arr,dp) + abs(arr[ind]-arr[ind-2]);
        
    return dp[ind] = min(left,right);
}

int main()
{
    int n;
    cin >> n;
    vector<int>arr(n);
    vector<int>dp(n,-1);
    for(int i = 0;i<n;i++)
    {
        cin >> arr[i];
    }
    int bestwt = fin(n-1,arr,dp);
    cout << bestwt;
}