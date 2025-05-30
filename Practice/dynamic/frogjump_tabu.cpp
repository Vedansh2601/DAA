#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int>arr(n);
    vector<int>dp(n,0);
    for(int i = 0;i<n;i++)
    {
        cin >> arr[i];
    }
    for(int i = 1;i<n;i++)
    {
        int fs = dp[i-1] + abs(arr[i] - arr[i-1]);
        int ss = INT_MAX;
        if(i > 1)
            ss = dp[i-2] + abs(arr[i-2]-arr[i]);
        dp[i] = min(fs,ss);    
        
    }
    cout << dp[n-1];
}