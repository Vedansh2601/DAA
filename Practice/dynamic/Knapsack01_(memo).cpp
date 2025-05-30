#include<bits/stdc++.h>
using namespace std;

int knapsack01(int i,int w,vector<int> val,vector<int> wei, vector<vector<int> >& dp)
{
    if(i==0)
    {
        if(wei[0] <= w)
            return val[0];
        return 0;
    }
        
    if(dp[i][w]!=-1)
        return dp[i][w];
    
    int nottake = knapsack01(i-1,w,val,wei,dp);
    int take = INT_MIN;
    if(wei[i] <= w)
        take = val[i] + knapsack01(i-1,w - wei[i],val,wei,dp);
        
    return dp[i][w] = max(take,nottake);
}

int main()
{
    int n,w;
    cin >> n >> w;
    vector<int> val(n);
    vector<int> wei(n);
    for(int i = 0;i<n;i++)
    {
        cin >> val[i] >> wei[i];
    }
    vector<vector<int> > dp(n,vector<int>(w+1,-1));
    cout << knapsack01(n-1,w,val,wei,dp);
}