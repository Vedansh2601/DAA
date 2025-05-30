#include<bits/stdc++.h>
using namespace std;

int findi(int i,int j,string s,string t,vector<vector<int> >& dp)
{
    if(i<0 || j<0)
        return 0;
        
    if(dp[i][j]!= -1)
        return dp[i][j];
        
    if(s[i] == t[j])
        return dp[i][j] = (1 + findi(i-1,j-1,s,t,dp));
        
    return dp[i][j] = max(findi(i-1,j,s,t,dp), findi(i,j-1,s,t,dp));
}

int main()
{
    string s;
    string t;
    getline(cin,s);
    //getchar();
    getline(cin,t);
    vector<vector<int> > dp(s.size(),vector<int>(t.size(),-1));
    cout << findi(s.size()-1,t.size()-1,s,t,dp);
}