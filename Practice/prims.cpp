#include <bits/stdc++.h>
using namespace std;

void prims(vector<vector<pair<int,int> > > g,int v)
{
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
    vector<int> key(v,INT_MAX);
    vector<bool> visited(v,false);
    vector<int> parent(v,-1);
    key[0] = 0;
    pq.push({0,0});
    while(!pq.empty())
    {
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();
        if(visited[u] == true)
            continue;
        visited[u] = true;
        for (auto edge : g[u])
        {
            int c = edge.first;
            int wt = edge.second;
            if(!visited[c] && wt < key[c])
            {
                key[c] = wt;
                parent[c] = u;
                pq.push({wt,c});
            }
        }
    }
    for(int i = 0;i<v;i++)
    {
        if(parent[i] != -1)
        {
            cout << parent[i] <<" - "<<i<<" weight: "<<key[i]<<endl;
        }
    }
}
int main()
{
    int v,e;
    cin >> v >> e;
    vector<vector<pair<int,int> > > g(v);
    for(int i = 0; i<e;i++)
    {
        int s,d,w;
        cin >> s >> d >> w;
        g[s].push_back({d,w});
        g[d].push_back({s,w});
    }
    prims(g,v);
}