#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<pair<int,int> > > g,vector<bool>& visited,int s,int d,int e,int ec,int &mw,int cw)
{
    if(ec == e)
    {
        if(s == d)
        {
            mw = min(mw,cw);
        }
        return;
    }
    for(auto edge : g[s])
    {
        int c = edge.first;
        int w = edge.second;
        if(!visited[c])
        {
            visited[c] = true;
            dfs(g,visited,c,d,e,ec+1,mw,cw+w);
            visited[c] = false;
        }
    }
}
int main()
{
    int v,mw = INT_MAX,s,d,e;
    cin >> v;
    vector<vector<pair<int,int> > > g(v);
    int a[v][v];
    for(int i = 0;i<v;i++)
    {
        for(int j = 0; j < v; j++)
        {
            cin >> a[i][j];
            if(a[i][j] != 0)
            {
                g[i].push_back({j,a[i][j]});
            }
        }
    }
    cin >> s>>d;
    cin >> e;
    vector<bool> visited(v,false);
    visited[s] = true;
    dfs(g,visited,s,d,e,0,mw,0);
    if(mw != INT_MAX)
    {
        cout << "Minimum weight = "<< mw;
    }
    else
        cout << "Not exsists";
    return 0;
}