#include <bits/stdc++.h>
using namespace std;

int maxsum(int i,vector<int>& arr,vector<int>& dp)
{
    if(i == 0)
        return arr[i];
    if(i < 0)
        return 0;
    if(dp[i]!=-1)
        return dp[i];
    int pick = arr[i] + maxsum(i-2,arr,dp);
    int notpick = maxsum(i-1,arr,dp);
    return dp[i] = max(pick,notpick);
}

int main()
{
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i =0;i<n;i++)
    {
        cin >> arr[i];
    }
    vector<int> dp(n,-1);
    cout << maxsum(n-1,arr,dp);
}