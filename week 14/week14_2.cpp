#include <bits/stdc++.h>
using namespace std;

int bfs(vector<vector<int> > g,int v)
{
    for(int i = 0;i<v;i++)
    {
        int c = 1;
        vector<bool> visited(v,false);
        queue<int> q;
        visited[i] = true;
        q.push(i);
        while(!q.empty())
        {
            int current = q.front();
            q.pop();
            for(int x : g[current])
            {
                if(!visited[x])
                {
                    visited[x] = true;
                    c++;
                    q.push(x);
                    if(c == v)
                        return i;
                }
            }
        }
        
    }
    return -1;
}

int main()
{
    int v,e;
    cin >> v>>e;
    vector<vector<int> > g(v);
    for(int i =0;i<e;i++)
    {
        int s,d;
        cin >>s>>d;
        g[s].push_back(d);
    }
    int mn = bfs(g,v);
    if(mn!= -1)
    {
        cout << mn;
    }
    else
        cout << "No mother node";
    return 0;
}