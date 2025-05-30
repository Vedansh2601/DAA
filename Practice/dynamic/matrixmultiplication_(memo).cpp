#include<bits/stdc++.h>
using namespace std;

int matrixmul(int i,int j,vector<int> arr, vector<vector<int> >& dp)
{
    if(i==j)
        return 0;
        
    if(dp[i][j]!=-1)
        return dp[i][j];
    
    int mini = INT_MAX;
    
    for(int k = i;k<j;k++)
    {
        int step = (arr[i-1] * arr[k] * arr[j]) + matrixmul(i,k,arr,dp) + matrixmul(k+1,j,arr,dp);
        mini = min(step,mini);
    }
        
    return dp[i][j] = mini;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n+1);
    for(int i = 0;i<n;i++)
    {
        int x,y;
        cin >> x >> y;
        if(i == 0)
            arr[0] = x;
        arr[i+1] = y;
    }
    vector<vector<int> > dp(n+1,vector<int>(n+1,-1));
    cout << matrixmul(1,n,arr,dp);
}